/*
 * DSNFSolver.h
 *
 *  Created on: 5 Nov 2012
 *      Author: richard
 */

#ifndef DSNFSOLVER_H_
#define DSNFSOLVER_H_

#include "DataStruct.h"
#include "DSNFFormula.h"
#include "Minisat.h"
#include "StepResolution.h"
#include "SometimeResolution.h"
#include <boost/foreach.hpp>
#include <time.h>

namespace STRP {

class DSNFSolver {
public:
	DSNFSolver(DSNFFormula* formula, bool solver_flag, bool sat_flag, int mus_val, std::string input_fname, bool keep_files, bool gen_stats, bool deg);
	~DSNFSolver();
	bool solve();
	void close_files();
	int step_count;
	int som_count;
	int uni_count;
	void kill_camus();
private:
	DSNFFormula* _formula;
	CNFFormula FALSE;
	StepResolution* step_solver;
	SometimeResolution* sometime_solver;
	std::set<std::set<T_Clause> > closed_set;
	bool solver_flag;
	bool sat_flag;
	bool sometime_termination();
	bool sometime_all();
	int deg_newuni;
	bool _deg;
};
}
/* namespace STRP */
#endif /* DSNFSOLVER_H_ */
