/*
 * SometimeResolution.cpp
 *
 *  Created on: 10 Jan 2013
 *      Author: rmw
 */

#include "SometimeResolution.h"

namespace STRP {

SometimeResolution::SometimeResolution(int num_vars, int mus_val,
		std::string input_fname, bool keep_files, bool gen_stats,
		time_t _start) {
	_num_vars = num_vars;
	_mus_val = mus_val;
	_keep_files = keep_files;
	_gen_stats = gen_stats;
	new_rand_file();
	stat_file = input_fname + ".strp_stat";
	remove(stat_file.c_str());
	start = _start;
	current = start;
}

void SometimeResolution::new_rand_file() {
	srand((unsigned) time(0));
	int random_integer = rand();
	fname_mod = boost::lexical_cast<std::string>(random_integer);
	filenames.push_back(fname_mod);
}

void SometimeResolution::save_stats() {

	std::ofstream myfile;
	myfile.open(stat_file.c_str(), std::ios::out | std::ios::app);
	myfile << stat;
	myfile.close();
	stat = "";
}

void SometimeResolution::close_files() {
	if (!_keep_files) {

		BOOST_FOREACH(std::string name_mod, filenames) {
			remove(("camus" + name_mod + ".cnf").c_str());
			remove(("camus" + name_mod + ".cnf.grp").c_str());
			remove(("camus" + name_mod + ".mcs").c_str());
			remove(("camus" + name_mod + ".mus").c_str());
		}

	}

}

bool SometimeResolution::run_search(std::set<T_Clause>& universal,
		const std::set<StepClause>& step, SometimeProblem sp, bool solver_flag,
		bool _deg) {
	DNFFormula h, h1;
	h.insert(getTRUE());
	bool result = false;

	while (true) {

		this->build_sometime_problem(universal, step, sp, h);
		CNFFormula som_result;
		som_result = this->run_camus(som_result);

		if (som_result.size() > 0) {
			// convert CNF clauses to DNF (by negation)
			negateCNF(som_result);
			h1 = som_result;

			if (solver_flag) {
				std::cout << "loop candidate: " << printDNF(h1) << std::endl;
			}

			if (h == h1) {

				if (solver_flag) {
					std::cout
							<< "loop search termination successful adding new universal clauses"
							<< std::endl;
				}

				negateCNF(h1);

				// add all of h1 to universal set
				BOOST_FOREACH(T_Clause cl, h1) {

					if (universal.insert(cl).second) {
						if (solver_flag) {
							std::cout << "som: adding universal clause: "
									<< printClause(cl) << std::endl;
						}
						result = true;
						deg_newuni++;

					}
				}

				//TODO redo deg
				if (_deg) {
					time(&current);
					double dif = difftime(current, start);
					std::cout << std::fixed << std::setprecision(4);
					std::cout << dif << " " << deg_newuni << std::endl;
					deg_newuni = 0;
				}

				return result;
			} else {
				if (solver_flag) {
					std::cout << "Can't term, searching again" << std::endl;
				}
				h.clear();
				h.insert(h1.begin(), h1.end());
			}

		} else {
			return false;
		}
	}
	return false;
}
void SometimeResolution::build_sometime_problem(
		const std::set<T_Clause>& universal, const std::set<StepClause>& step,
		SometimeProblem sp, DNFFormula h) {

	lhs_lookup.clear();

	new_rand_file();

	std::ofstream problem_file;
	std::ofstream group_file;

	std::string problem = "p cnf ";
	problem += boost::lexical_cast<std::string>(_num_vars);
	problem += " ";
	problem += boost::lexical_cast<std::string>(step.size() + universal.size());
	problem += "\n";

	problem_file.open(("camus" + fname_mod + ".cnf").c_str());
	group_file.open(("camus" + fname_mod + ".cnf.grp").c_str());

	problem_file << problem;
	int num_clauses = 0;

// add step clauses
	BOOST_FOREACH(StepClause val, step) {

		num_clauses++;
		lhs_lookup.push_back(val.first);
		std::string clause = cl_to_camus_string(val.second) + "\n";
		std::string group = boost::lexical_cast<std::string>(num_clauses);
		group += "\n";
		problem_file << clause;
		group_file << group;
	}

	DNFFormula h_prime;

	BOOST_FOREACH(T_Clause cl, h) {
		T_Clause nc;
		nc.insert(cl.begin(), cl.end());
		negateClause(nc);
		nc.insert(sp.first);
		h_prime.insert(nc);
	}

// add h_prime
	if (h_prime.size() > 0) {
		// add current H
		BOOST_FOREACH(T_Clause cl, h_prime) {
			num_clauses++;
			std::string clause = cl_to_camus_string(cl) + "\n";
			std::string group = boost::lexical_cast<std::string>(num_clauses);
			group += " ";
			problem_file << clause;
			group_file << group;
		}
	}

// add universal clauses
	BOOST_FOREACH(T_Clause cl, universal) {

		num_clauses++;
		std::string clause = cl_to_camus_string(cl) + "\n";
		std::string group = boost::lexical_cast<std::string>(num_clauses);
		group += " ";
		problem_file << clause;
		group_file << group;

	}

	if (_gen_stats) {
		stat += boost::lexical_cast<std::string>(_num_vars);
		stat += ";";
		stat += boost::lexical_cast<std::string>(num_clauses);
		stat += ";";
	}

	problem_file.close();
	group_file.close();

}

CNFFormula SometimeResolution::run_camus(CNFFormula& result) {

	FILE *fp;
	char path[1035];

	std::string clauses_added;
	result.clear();

	// run extern solver based on cmd line flag selection
	if (_mus_val == 0) {

		// using camus_mus & camus_mcs we can run it in one command
		fp = popen(
				("camus_mcs camus" + fname_mod + ".cnf -g camus" + fname_mod
						+ ".cnf.grp | camus_mus").c_str(), "r");

	} else if (_mus_val == 1) {
		system(
				("camus_mcs camus" + fname_mod + ".cnf -g camus" + fname_mod
						+ ".cnf.grp > camus" + fname_mod + ".mcs").c_str());

		fp = popen(("mtminer camus" + fname_mod + ".mcs 2>/dev/null").c_str(),
				"r");

	} else if (_mus_val == 2) {
		system(
				("camus_mcs camus" + fname_mod + ".cnf -g camus" + fname_mod
						+ ".cnf.grp > camus" + fname_mod + ".mcs").c_str());
		system(
				("shd 0D camus" + fname_mod + ".mcs camus" + fname_mod
						+ ".mus 1>/dev/null 2>/dev/null").c_str());

		fp = fopen(("camus" + fname_mod + ".mus").c_str(), "r");
	}

	if (fp == NULL) {
		//TODO add exceptions
		std::cout << "Failed to run command" << std::endl;
	}

	while (fgets(path, sizeof(path) - 1, fp) != NULL) {

		std::istringstream iss(path, std::istringstream::in);
		std::string val;
		std::set<int> mus;

		T_Clause new_uni;
		while (iss >> val) {

			int int_val = atoi(val.c_str());

			// convert from 1-indexing to 0-indexing
			int_val--;

			if ((int_val >= 0) && (int_val < lhs_lookup.size())) {
				new_uni.insert(lhs_lookup[int_val].begin(),
						lhs_lookup[int_val].end());
			}

		}
		if (new_uni.size() > 0) {

			result.insert(new_uni);
		}

	}

	if (_gen_stats) {
		stat += boost::lexical_cast<std::string>(result.size());
		stat += "\n";
		save_stats();
	}

	pclose(fp);
	return result;
}
SometimeResolution::~SometimeResolution() {
// TODO Auto-generated destructor stub
}

} /* namespace STRP */
