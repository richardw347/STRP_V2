#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include <map>
#include <string>
#include <boost/foreach.hpp>

typedef std::map<std::string, int> SymTableType;

class SymbolTable
{
    public:
        SymbolTable(){
        	_valueCounter = 1;
        	_table["TRUE"] = 1;
        }
        ~SymbolTable(){}
        unsigned int getVar(std::string key){

        	int val = _table[key];

            if (val == 0){
                _table[key] = this->getNextVar();
                return _table[key];
            } else {
                return val;
            }
        }
        std::string toString(){
        	std::string out;
        	BOOST_FOREACH(const SymTableType::value_type val, _table){
    			out += "\n" + val.first + " = ";
    			out += boost::lexical_cast<std::string>(val.second);
    		}
        	return out;

        }
        unsigned int getNumVars(){
        	return _valueCounter;
        }
    protected:
    private:
        SymTableType _table;
        unsigned int _valueCounter;
        unsigned int getNextVar(){
            _valueCounter++;
            return _valueCounter;
        }
};

#endif // SYMBOLTABLE_H
