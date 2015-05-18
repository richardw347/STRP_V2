/*
 * StepResolution.cpp
 *
 *  Created on: 10 Jan 2013
 *      Author: rmw
 */

#include "StepResolution.h"

namespace STRP {

StepResolution::StepResolution(int num_vars, int mus_val,
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

void StepResolution::new_rand_file() {
	srand((unsigned) time(0));
	int random_integer = rand();
	fname_mod = boost::lexical_cast<std::string>(random_integer);
	filenames.push_back(fname_mod);
}

void StepResolution::save_stats() {

	std::ofstream myfile;
	myfile.open(stat_file.c_str(), std::ios::out | std::ios::app);
	myfile << stat;
	myfile.close();
	stat = "";
}

void StepResolution::close_files() {
	if (!_keep_files) {

		BOOST_FOREACH(std::string name_mod, filenames) {
			remove(("camus" + name_mod + ".cnf").c_str());
			remove(("camus" + name_mod + ".cnf.grp").c_str());
			remove(("camus" + name_mod + ".mcs").c_str());
			remove(("camus" + name_mod + ".mus").c_str());
		}

	}

}

/////////////////////STEP RESOLUTION////////////////////////////
///////////////////////////////////////////////////////////////

bool StepResolution::run_search(std::set<T_Clause>& universal,
		const std::set<StepClause>& step, bool solver_flag, bool _deg) {

	if (solver_flag) {
		std::cout << "Running step resolution search" << std::endl;
	}

	// build the problem string	std::map<int, MUS_INDEXES> sometime_map;
	this->build_step_problem(universal, step);

	return this->run_camus_step(universal, solver_flag, _deg);

}

void StepResolution::build_step_problem(const std::set<T_Clause>& universal,
		const std::set<StepClause>& step) {

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
		stat += boost::lexical_cast<std::string>(
				step.size() + universal.size());
		stat += ";";
	}

	problem_file.close();
	group_file.close();
}

bool StepResolution::run_camus_step(std::set<T_Clause>& universal,
		bool solver_flag, bool _deg) {

	FILE *fp;
	bool result = false;
	char path[1035];

	int num_cores = 0;
	std::string clauses_added;

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

		num_cores++;
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

			if (universal.insert(new_uni).second) {

				//uni_count++;
				deg_newuni++;

				if (solver_flag) {
					clauses_added += "step: adding universal clause: "
							+ printClause(new_uni) + "\n";
				}
				result = true;

			}
		}

	}

	if (_deg) {
		time(&current);
		double dif = difftime(current, start);
		std::cout << std::fixed << std::setprecision(4);
		std::cout  << dif << " " << deg_newuni << std::endl;
		deg_newuni = 0;
	}

	if (solver_flag) {
		std::cout << "mus count: " << num_cores << std::endl;
		std::cout << clauses_added;
	}

	if (_gen_stats) {
		stat += boost::lexical_cast<std::string>(num_cores);
		stat += "\n";
		save_stats();
	}

	pclose(fp);
	return result;
}

StepResolution::~StepResolution() {
// TODO Auto-generated destructor stub
}

} /* namespace STRP */
