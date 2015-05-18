#ifndef SNFFORMULA_H_INCLUDED
#define SNFFORMULA_H_INCLUDED
#include <vector>
#include <string>
#include "DataStruct.h"
#include "SymbolTable.h"
#include <boost/foreach.hpp>

using namespace std;

namespace STRP {
class SNFFormula;
}

class STRP::SNFFormula {

public:
	SNFFormula(){
		universal.push_back(getTRUE());
	};
	~SNFFormula(){};
	vector<T_Clause> initial;
	vector<T_Clause> universal;
	vector<StepClause> step;
	vector<SometimeClause> sometime;
	SymbolTable table;
	string toString() {

		string out = "";

		// initial clauses
		out += "\n=====Inital Clauses=====\n";
		BOOST_FOREACH(T_Clause cl, initial){
			out += "\n" + printClause(cl) + "\n";
		}

		// universal clauses
		out += "\n=====Universal Clauses=====\n";
		BOOST_FOREACH(T_Clause cl, universal){
			out += "\n" + printClause(cl) + "\n";
		}

		out += "\n=====Step Clauses=====\n";
		BOOST_FOREACH(StepClause cl, step){
			out += "\n" + printStep(cl) + "\n";
		}

		out += "\n=====Sometime Clauses=====\n";
		BOOST_FOREACH(SometimeClause cl, sometime){
			out += "\n" + printSometime(cl) + "\n";
		}

		out += "\n==========End===========\n";

		return out;

	}


};

#endif // SNFFORMULA_H_INCLUDED
