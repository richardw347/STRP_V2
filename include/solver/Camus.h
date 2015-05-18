/*
 * Camus.h
 *
 *  Created on: 22 Nov 2012
 *      Author: richard
 */

#ifndef CAMUS_H_
#define CAMUS_H_
/*
#include "../data_struct/DataStruct.h"
#include "../data_struct/DSNFFormula.h"
#include "../data_struct/CNF_DNF.h"
#include <iostream>
#include <boost/foreach.hpp>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <ctime>sss
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PRINT 0
#define READ 0
#define WRITE 1

namespace STRP {

class Camus {
public:
	Camus(int num_vars, int mus_val, std::string input_fname, bool keep_files,
			bool gen_stats);
	virtual ~Camus();
	bool stepResolution(const std::set<T_Clause>& universal,
			const std::set<StepClause>& step, CNFFormula& result, bool solver_flag,
			bool _deg);

	void sometimeResolution(const std::set<T_Clause>& universal,
			const std::set<StepClause>& step, SometimeProblem sp, CNFFormula h,
			CNFFormula& result, bool solver_flag, bool _deg);
	void kill();
	void close_files();
private:
	void build_step_problem(const std::set<T_Clause>& universal,
			const std::set<StepClause>& step);
	bool run_camus_step(std::set<T_Clause>& universal, bool solver_flag,
			bool _deg);
	void build_sometime_problem(const std::set<T_Clause>& universal,
			const std::set<StepClause>& step, SometimeProblem sp, CNFFormula h);
	void run_camus(CNFFormula& result, bool solver_flag, bool _deg);
	void run_camus_mtminer(CNFFormula& resul, bool solver_flag, bool _deg);
	void run_camus_shd(CNFFormula& result, bool solver_flag, bool _deg);
	void new_rand_file();
	void save_stats();
	std::vector<std::string> filenames;
	std::vector<T_Clause> lhs_lookup;
	int _num_vars;
	int _mus_val;
	std::string fname_mod;
	std::string stat;
	std::string stat_file;
	bool _keep_files;
	bool _gen_stats;

};

}*/ /* namespace STRP */
#endif /* CAMUS_H_ */
