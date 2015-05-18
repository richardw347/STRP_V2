#include "DSNFSolver.h"

namespace STRP {

DSNFSolver::DSNFSolver(DSNFFormula* formula, bool _solver_flag, bool _sat_flag,
		int mus_val, std::string input_filename, bool keep_files,
		bool gen_stats, bool deg) {
	_formula = formula;
	time_t start;
	time(&start);
	step_solver = new StepResolution(_formula->num_vars, mus_val,
			input_filename, keep_files, gen_stats, start);
	sometime_solver = new SometimeResolution(_formula->num_vars, mus_val,
				input_filename, keep_files, gen_stats, start);
	solver_flag = _solver_flag;
	sat_flag = _sat_flag;
	step_count = 0;
	som_count = 0;
	uni_count = 0;
	deg_newuni = 0;
	_deg = deg;
}

bool DSNFSolver::solve() {

	bool exit_loop = false;
	std::string group;
	std::string problem;

	while (!exit_loop) {

		exit_loop = true;

		//////////////////////////////////////////////////////////////////////
		///////////////////////STEP RESOLUTION////////////////////////////////

		if (step_solver->run_search(_formula->universal, _formula->step,
				solver_flag, _deg)) {

			if (solver_flag) {
				std::cout << "Step resolution search successful" << std::endl;
			}

			exit_loop = false;
			step_count++;

			// check for termination
			if (Minisat::can_initTerm(_formula->initial, _formula->universal,
					sat_flag)) {
				if (solver_flag) {
					std::cout << "Applying initial termination rule"
							<< std::endl;
				}
				return false;
			}

		} else if (sometime_all()) {

			//////////////////////////////////////////////////////////////////////
			///////////////////////SOMETIME RESOLUTION////////////////////////////

			exit_loop = false;

			// check for termination
			if (Minisat::can_initTerm(_formula->initial, _formula->universal,
					sat_flag)) {
				if (solver_flag) {
					std::cout << "Applying initial termination rule"
							<< std::endl;
				}
				return false;
			}
			if (sometime_termination()) {
				if (solver_flag) {
					std::cout << "Applying sometime termination rule"
							<< std::endl;
				}
				return false;
			}

		}

	}

	// check for termination
	if (Minisat::can_initTerm(_formula->initial, _formula->universal,
			sat_flag)) {
		if (solver_flag) {
			std::cout << "Applying initial termination rule" << std::endl;
		}
		return false;
	}
	if (sometime_termination()) {
		if (solver_flag) {
			std::cout << "Applying sometime termination rule" << std::endl;
		}
		return false;
	}

	return true;
}

bool DSNFSolver::sometime_all() {

	//loop through all the sometime problems
	BOOST_FOREACH(SometimeProblem sp, _formula->sometime) {

		if (solver_flag) {
			std::cout << "\nrunning loop search for: " << sp.first << std::endl;
		}
		if (sometime_solver->run_search(_formula->universal, _formula->step, sp,
				solver_flag, _deg)) {
			som_count++;
			if (solver_flag) {
				std::cout << "loop search successful" << std::endl << std::endl;
			}
			return true;
		} else {
			if (solver_flag) {
				std::cout << "loop search failed" << std::endl << std::endl;
			}
		}
	}
	return false;
}

bool DSNFSolver::sometime_termination() {

	BOOST_FOREACH(SometimeProblem sp, _formula->sometime) {
		// check for sometime termination
		if (Minisat::can_somTerm(_formula->universal, sp.first, sat_flag)) {
			return true;

		}
	}
	return false;

}

void DSNFSolver::close_files() {
	step_solver->close_files();
}

void DSNFSolver::kill_camus() {
}

DSNFSolver::~DSNFSolver() {
	delete step_solver;
}

} /* namespace STRP */
