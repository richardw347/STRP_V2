#ifndef DSNFFORMULA_H
#define DSNFFORMULA_H

#include "DataStruct.h"
#include <vector>
#include <string>
#include <set>

namespace STRP{
	class DSNFFormula;
}

class STRP::DSNFFormula
{
    public:
		DSNFFormula(){};
		~DSNFFormula(){};
		std::vector<T_Clause> initial;
    	std::set<T_Clause> universal;
    	std::set<StepClause> step;
    	std::vector<SometimeProblem> sometime;
    	unsigned int num_vars;
    	std::string toString(){

    		std::string out = "";

    		// initial clauses
    		out += "\n=====Inital Clauses=====";
    		BOOST_FOREACH(T_Clause cl, initial){
    			out += "\n" + printClause(cl);
    		}

    		// universal clauses
    		out += "\n=====Universal Clauses=====";
    		BOOST_FOREACH(T_Clause cl, universal){
    			out += "\n" + printClause(cl);
    		}

    		out += "\n=====Step Clauses=====";
    		BOOST_FOREACH(StepClause val, step){
    			out += printStepClause(val);
    		}

    		out += "\n=====Sometime Problems=====";
    		BOOST_FOREACH(SometimeProblem sp, sometime){
    			out += "\nSOMETIME(" + boost::lexical_cast<std::string>(sp.first) +")";
    			out += "\n" + printStep(sp.second);
    		}

    		out += "\n==========End===========";

    		return out;
    	}
    protected:
    private:
};

#endif // DSNFFORMULA_H
