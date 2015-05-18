#ifndef CNF_DNF_H_INCLUDED
#define CNF_DNF_H_INCLUDED
#include <set>
#include <vector>
#include <iostream>
#include "DataStruct.h"

using namespace STRP;

struct Digits {
    std::set<int>::const_iterator begin;
    std::set<int>::const_iterator end;
    std::set<int>::const_iterator me;
};
typedef std::vector<Digits> Vd;


inline std::set<T_Clause> cart_product(std::set<T_Clause> in){
	std::set<T_Clause> out;
    Vd vd;


    for(std::set<T_Clause>::const_iterator it = in.begin();
        it != in.end();
        ++it) {
        Digits d = {(*it).begin(), (*it).end(), (*it).begin()};
        vd.push_back(d);
    }

    while(1) {

        // Construct your first product vector by pulling
        // out the element of each vector via the iterator.
        T_Clause result;
        for(Vd::const_iterator it = vd.begin(); it != vd.end(); it++) {
            result.insert(*(it->me));
        }
        out.insert(result);

        // Increment the rightmost one, and repeat.

        // When you reach the end, reset that one to the beginning and
        // increment the next-to-last one. You can get the "next-to-last"
        // iterator by pulling it out of the neighboring element in your
        // vector of iterators.
        for(Vd::iterator it = vd.begin(); ; ) {
            // okay, I started at the left instead. sue me
            ++(it->me);
            if(it->me == it->end) {
                if(it+1 == vd.end()) {
                    // I'm the last digit, and I'm about to roll
                    return out;
                } else {
                    // cascade
                    it->me = it->begin;
                    ++it;
                }
            } else {
                // normal
                break;
            }
        }
    }
}


inline DNFFormula toDNF(CNFFormula in){
    if (in.size() > 0){
    	return cart_product(in);
    } else {
    	return in;
    }

}

inline CNFFormula toCNF(DNFFormula in){
    if (in.size() > 0){
    	return cart_product(in);
    } else {
    	return in;
    }
};
#endif // CNF_DNF_H_INCLUDED
