#ifndef DATASTRUCT_H_INCLUDED
#define DATASTRUCT_H_INCLUDED
#include <set>
#include <string>
#include <algorithm>
#include <boost/lexical_cast.hpp>
#include <boost/foreach.hpp>
#include <iostream>

namespace STRP {
typedef std::set<int> T_Clause;
typedef std::pair<T_Clause, T_Clause> StepClause;
typedef std::pair<T_Clause, int> SometimeClause;
typedef std::set<T_Clause> CNFFormula;
typedef std::set<T_Clause> DNFFormula;
typedef std::pair<int, StepClause> SometimeProblem;

inline T_Clause getTRUE() {
	T_Clause TRUE;
	if (TRUE.size() < 1) {
		TRUE.insert(1);
	}
	return TRUE;
}

inline T_Clause getFALSE() {
	T_Clause FALSE;
	if (FALSE.size() < 1) {
		FALSE.insert(-1);
	}
	return FALSE;
}

inline std::string printClause(T_Clause clause) {

	std::string out;
	out += "[";
	T_Clause::iterator it;
	for (it = clause.begin(); it != clause.end(); it++) {
		out += boost::lexical_cast<std::string>(*it);
		if (*it != *(clause.rbegin())) {
			out += ", ";
		}

	}
	out += "]";
	return out;

}

inline std::string printClause(T_Clause clause, std::string op) {

	std::string out;
	out += "[";
	T_Clause::iterator it;
	for (it = clause.begin(); it != clause.end(); it++) {
		out += boost::lexical_cast<std::string>(*it);
		if (*it != *(clause.rbegin())) {
			out += " " + op + " ";
		}

	}
	out += "]";
	return out;

}

inline std::string cl_to_camus_string(T_Clause clause) {

	std::string out;
	T_Clause::iterator it;
	for (it = clause.begin(); it != clause.end(); it++) {
		out += boost::lexical_cast<std::string>(*it);
		if (*it != *(clause.rbegin())) {
			out += " ";
		}

	}
	out += " 0";
	return out;

}

inline std::string printStep(StepClause clause) {

	std::string out;
	out += printClause(clause.first);
	out += " -> NEXT";
	out += printClause(clause.second);
	return out;

}

inline std::string printSometime(SometimeClause clause) {
	std::string out;
	out += printClause(clause.first);
	out += " -> SOMETIME ";
	out += boost::lexical_cast<std::string>(clause.second);
	return out;
}

inline std::string printSometimeP(SometimeProblem problem) {
	std::string out;
	out += "SOMETIME " + boost::lexical_cast<std::string>(problem.first);
	out += "\n " + printStep(problem.second);
	return out;
}

inline std::string printCNF(CNFFormula formula) {

	std::string out = "";

	BOOST_FOREACH(T_Clause cl, formula) {
		out += printClause(cl, "∨");
		if (cl != *(formula.rbegin())) {
			out += " ∧ ";
		}
	}

	return out;
}

inline std::string printDNF(DNFFormula formula) {

	std::string out = "";

	BOOST_FOREACH(T_Clause cl, formula) {
		out += printClause(cl, "∧");
		if (cl != *(formula.rbegin())) {
			out += " ∨ ";
		}
	}

	return out;
}

inline std::string printStepClause(StepClause step) {
	std::string out;
	out += "\n" + printClause(step.first);
	out += " => NEXT(" + printClause(step.second) + ")";
	return out;
}

inline bool isSuperSet(T_Clause a, T_Clause b) {

	if (a == b) {
		return 0;
	} else {
		return std::includes(a.begin(), a.end(), b.begin(), b.end());
	}

}

inline void simplifyCNF(CNFFormula& formula) {

	// check for empty clause i,e. FALSE
	BOOST_FOREACH(T_Clause cl, formula) {
		if (cl == getFALSE()) {
			formula.erase(cl);
		}
	}

	if (formula.size() > 1) {
		// create a new set
		CNFFormula new_set;

		T_Clause first = *formula.begin();

		// add fist element to new set
		new_set.insert(first);

		BOOST_FOREACH(T_Clause cl, formula) {

			BOOST_FOREACH(T_Clause new_cl, new_set) {

				if (!isSuperSet(cl, new_cl)) {
					new_set.insert(cl);
				}

			}
		}

		formula = new_set;
	}

}

inline void simplifyDNF(DNFFormula& formula) {

	if (formula.size() > 1) {

		// check for empty clause i,e. FALSE
		BOOST_FOREACH(T_Clause cl, formula) {
			if (cl == getFALSE()) {
				formula.erase(cl);
			}
		}

		// create a new set
		CNFFormula new_set;

		T_Clause first = *formula.begin();

		// add fist element to new set
		new_set.insert(first);

		BOOST_FOREACH(T_Clause cl, formula) {

			BOOST_FOREACH(T_Clause new_cl, new_set) {

				if (!isSuperSet(cl, new_cl)) {
					new_set.insert(cl);
				}

			}
		}

		formula = new_set;
	}

}

inline void negateCNF(CNFFormula& formula) {
	CNFFormula new_set;

	BOOST_FOREACH(T_Clause cl, formula) {

		T_Clause new_cl;

		BOOST_FOREACH(int var, cl) {

			new_cl.insert((var * -1));
		}
		new_set.insert(new_cl);
	}

	formula = new_set;
}

inline CNFFormula negateFormula(CNFFormula formula) {

	CNFFormula new_set;

	BOOST_FOREACH(T_Clause cl, formula) {

		T_Clause new_cl;

		BOOST_FOREACH(int var, cl) {

			new_cl.insert((var * -1));
		}
		new_set.insert(new_cl);
	}

	return new_set;
}

inline void negateClause(T_Clause& clause) {

	T_Clause new_cl;

	BOOST_FOREACH(int lit, clause) {

		new_cl.insert((lit * -1));
	}

	clause = new_cl;
}

}
;

#endif // DATASTRUCT_H_INCLUDED
