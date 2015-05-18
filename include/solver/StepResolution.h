/*
 * StepResolution.h
 *
 *  Created on: 10 Jan 2013
 *      Author: rmw
 */

#ifndef STEPRESOLUTION_H_
#define STEPRESOLUTION_H_

#include "../data_struct/DataStruct.h"
#include "../data_struct/DSNFFormula.h"
#include "../data_struct/CNF_DNF.h"
#include <iostream>
#include <boost/foreach.hpp>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <ctime>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iomanip>

namespace STRP {

class StepResolution {
public:
	StepResolution(int num_vars, int mus_val, std::string input_fname,
			bool keep_files, bool gen_stats, time_t start);
	bool run_search(std::set<T_Clause>& universal,
			const std::set<StepClause>& step, bool solver_flag, bool _deg);
	void close_files();
	virtual ~StepResolution();
private:
	void build_step_problem(const std::set<T_Clause>& universal,
			const std::set<StepClause>& step);
	bool run_camus_step(std::set<T_Clause>& universal, bool solver_flag,
			bool _deg);
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
	int deg_newuni;
	time_t start,current;
};

} /* namespace STRP */
#endif /* STEPRESOLUTION_H_ */
