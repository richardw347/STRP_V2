#ifndef MINISAT_H
#define MINISAT_H
#include <boost/foreach.hpp>
#include <vector>
#include <set>
#include "Solver.h"
#include "SolverTypes.h"
#include "../data_struct/DataStruct.h"
#include "../data_struct/CNF_DNF.h"
#include <iostream>

#define PRINT 0

class Minisat {

public:
	static bool can_initTerm(const vector<STRP::T_Clause>& init,
			const std::set<STRP::T_Clause>& uni, bool sat_flag) {

		Solver solver;

		if (!addToSolver(solver, init, sat_flag)) {
			return true;
		}

		if (!addToSolver(solver, uni, sat_flag)) {
			return true;
		}

		bool result = solver.solve();
		if (sat_flag) {
			std::cout << "minisat: " << result << std::endl;
		}
		return !solver.solve();

	}
	static bool bfs_term(DNFFormula h, DNFFormula h1, bool sat_flag) {

		Solver solver;


		// convert h from dnf to cnf
		CNFFormula cnf_h = toCNF(h);


		// negate h1 (this implicitly converts it to CNF)
		CNFFormula not_h1 = negateFormula(h1);


		if (!addToSolver(solver, cnf_h, sat_flag)) {
			return true;
		}


		if (!addToSolver(solver, not_h1, sat_flag)) {
			return true;
		}

		bool result = solver.solve();
		if (sat_flag) {
			std::cout << "minisat: " << result << std::endl;
		}
		return !solver.solve();

	}

	static bool can_somTerm(const std::set<STRP::T_Clause>& uni, int som_lit, bool sat_flag) {

		Solver solver;

		if (!addToSolver(solver, uni, sat_flag)) {
			return true;
		}

		vec<Lit> new_cl;
		int abs_som_var = abs(som_lit);
		while (abs_som_var >= solver.nVars) {
			solver.newVar();
		}
		new_cl.push(Lit(abs_som_var, (som_lit > 0)));

		if (!solver.addClause(new_cl, sat_flag)) {
			return true;
		}

		bool result = solver.solve();
		if (sat_flag) {
			std::cout << "minisat: " << result << std::endl;
		}
		return !solver.solve();

	}

private:
	static bool addToSolver(Solver& solver, const vector<STRP::T_Clause>& clauses, bool sat_flag) {

		BOOST_FOREACH(STRP::T_Clause cl, clauses) {

			if (sat_flag) {
				std::cout << "minisat: " << STRP::printClause(cl) << std::endl;
			}

			vec<Lit> new_cl;

			BOOST_FOREACH(int var, cl) {
				int abs_var = abs(var);
				while (abs_var >= solver.nVars) {
					solver.newVar();
				}
				new_cl.push(Lit(abs_var, (var > 0)));
			}
			if (!solver.addClause(new_cl)) {
				return false;
			}
		}
		return true;
	}

	static bool addToSolver(Solver& solver, const CNFFormula& clauses, bool sat_flag) {

		BOOST_FOREACH(STRP::T_Clause cl, clauses) {

			if (sat_flag) {
				std::cout << "minisat: " << STRP::printClause(cl) << std::endl;
			}

			vec<Lit> new_cl;

			BOOST_FOREACH(int var, cl) {
				int abs_var = abs(var);
				while (abs_var >= solver.nVars) {
					solver.newVar();
				}
				new_cl.push(Lit(abs_var, (var > 0)));
			}
			if (!solver.addClause(new_cl)) {
				return false;
			}
		}
		return true;
	}
};

#endif // MINISAT_H
