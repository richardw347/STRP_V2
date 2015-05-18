#ifndef TRANSLATOR_H_
#define TRANSLATOR_H_
#include <boost/foreach.hpp>
#include <vector>
#include <map>
#include <iostream>
#include "CNF_DNF.h"
#include "DataStruct.h"

#define DEBUG 0

void cond_to_uncond(DSNFFormula& result, SNFFormula& input);
void premerge_rhs(DSNFFormula& input, SNFFormula& snf);
void premerge_lhs(DSNFFormula& result, SNFFormula& input);

DSNFFormula translateToDSNF(SNFFormula& input) {

	DSNFFormula result;

	// translate any conditional eventualities to unconditional ones
	cond_to_uncond(result, input);

	if (DEBUG) {
		std::cout << "translated conditional eventualities" << std::endl;
	}

//	premerge_rhs(input);

	/*if (DEBUG) {
	 std::cout << "premerged rhs's" << std::endl;
	 }*/

// add all initial clauses to result
	result.initial.insert(result.initial.end(), input.initial.begin(),
			input.initial.end());
	// add all universal clauses to result
	result.universal.insert(input.universal.begin(),
			input.universal.end());

	/*BOOST_FOREACH(StepClause s, input.step){

	 result.step.insert(s);
	 }*/

	premerge_lhs(result, input);

	if (DEBUG) {
		std::cout << "premerged lhs's" << std::endl;
	}

	premerge_rhs(result, input);

	if (DEBUG) {
		std::cout << "premerged rhs's" << std::endl;
	}

	result.num_vars = input.table.getNumVars();

	return result;
}

void cond_to_uncond(DSNFFormula& result, SNFFormula& input) {

	BOOST_FOREACH(SometimeClause so, input.sometime) {

		if (so.first.size() > 0 && so.first != getFALSE()) {

			// translation required
			// input: LHS => SOMETIME q

			// generate new literal wait_for_q
			int wait_for_q = input.table.getVar(
					"wait_for_" + boost::lexical_cast<std::string>(so.second));

			// generate new universal clause of the form
			// LHS OR q OR wait_for_q
			T_Clause newU;
			newU.insert(so.first.begin(), so.first.end()); //add all from LHS
			newU.insert(so.second); // add q
			newU.insert(wait_for_q);
			result.universal.insert(newU); //add to DSNF output

			SometimeProblem sp;

			StepClause tempStep;
			// generate a new step clause of the form
			// not wait_for_q OR NEXT q OR NEXT wait_for_q

			/*sp.second.first.insert(wait_for_q * -1);
			sp.second.second.insert(so.second);
			sp.second.second.insert(wait_for_q);*/

			tempStep.first.insert(wait_for_q * -1);
			tempStep.second.insert(so.second);
			tempStep.second.insert(wait_for_q);
			input.step.push_back(tempStep);


			// new sometime literal not wait_for_q
			sp.first = wait_for_q * -1;

			// add sometime problem to DSNF output
			result.sometime.push_back(sp);

		} else {

			// already unconditional
			SometimeProblem sp;
			sp.first = so.second;
			result.sometime.push_back(sp);
		}

	}
}

void premerge_lhs(DSNFFormula& result, SNFFormula& input) {

	typedef std::vector<StepClause> clauseVect;
	typedef std::map<T_Clause, clauseVect> mapType;

	mapType lists;
	clauseVect stepResult;
	int lit_num = 0;				// not z => NEXT RHS

	BOOST_FOREACH(StepClause scl, input.step) {

		// iterate through the list
		// constructing a map of similar elements
		lists[scl.first].push_back(scl);

	}

	BOOST_FOREACH(const mapType::value_type val, lists) {

		StepClause s;

		if (val.second.size() > 1) {
			//create a new literal x
			int x = input.table.getVar(
					"_x" + boost::lexical_cast<std::string>(lit_num));

			// generate a new step clause of the form
			// LHS => NEXT x
			StepClause newS;
			newS.first = val.first;
			T_Clause new_rhs;
			newS.second.insert(x);
			result.step.insert(newS);

			// generate a new set of universal clauses
			// such that x => RHS's
			CNFFormula cnf;
			BOOST_FOREACH(StepClause step, val.second) {
				step.second.insert(x * -1);
				cnf.insert(step.second);
			}

			BOOST_FOREACH(T_Clause cl, cnf) {
				result.universal.insert(cl);
			}

			lit_num++;

		} else {
			result.step.insert(val.second[0]);
		}

	}


}

void premerge_rhs(DSNFFormula& input, SNFFormula& snf) {

	//std::cout << "start premerge rhs" << std::endl;

	typedef std::vector<StepClause> clauseVect;
	typedef std::map<T_Clause, clauseVect> mapType;

	mapType lists;
	std::vector<T_Clause> universal_result;
	clauseVect stepResult;

	BOOST_FOREACH(StepClause scl, input.step) {

		// iterate through the list
		// constructing a map of similar elements
		lists[scl.second].push_back(scl);

	}

	int lit_num = 0;

	BOOST_FOREACH(const mapType::value_type val, lists) {

		if (val.second.size() > 1) {

			//create a new literal z
			int z = snf.table.getVar(
					"_z" + boost::lexical_cast<std::string>(lit_num));

			// generate a new step clause of the form
			// not z => NEXT RHS
			StepClause newS;
			newS.first.insert(z * -1);
			newS.second = val.first;
			stepResult.push_back(newS);

			// generate a new set of universal clauses
			// such that z => LHS's
			//CNFFormula cnf;
			BOOST_FOREACH(StepClause step, val.second) {

				//take the LHS e.g. a n b
				//create new clauses of the form
				// z => a n b == ~z u a and ~z u b
				T_Clause new_uni;
				BOOST_FOREACH(int var, step.first) {
					new_uni.insert(var);
					new_uni.insert(z);
				}
				input.universal.insert(new_uni);
				//cnf.insert(step.first);
			}

			lit_num++;
		} else {
			stepResult.push_back(val.second[0]);
		}

	}
	input.step.clear();
	BOOST_FOREACH(StepClause cl, stepResult) {
		input.step.insert(cl);
	}
	//input.step = stepResult;

}

#endif /* TRANSLATOR_H_ */
