grammar SNF;

options {
 language=Cpp;
}

@lexer::namespace {	STRP }
@parser::namespace{	STRP }

@parser::includes
{
#include "../data_struct/SNFFormula.h"
#include "SNFLexer.hpp"
}

@parser::members {
SNFFormula result;
}

@lexer::traits {

     class SNFLexer; class SNFParser;

     typedef antlr3::Traits< SNFLexer, SNFParser > SNFLexerTraits;

     typedef SNFLexerTraits SNFParserTraits;

}

@parser::traits {

     class SNFLexer; class SNFParser;

     typedef antlr3::Traits< SNFLexer, SNFParser > SNFLexerTraits;

     typedef SNFLexerTraits SNFParserTraits;

}

formula returns [SNFFormula f]
:
	'and''('
	list_of_snfclauses {f = result;}
	')''.'
;

list_of_snfclauses
: 	'['']' |
	'[' 
	snfclause 
	(',' snfclause)* 
	']'
; 

snfclause
:
	'always''('temporalclause')' |
	clause {result.initial.push_back($clause.cl);}
;

temporalclause
:
	clause {result.universal.push_back($clause.cl);}
	| stepclause {result.step.push_back($stepclause.stcl);}
	| uncond_stepclause {result.step.push_back($uncond_stepclause.stcl);}
	| sometimeclause {result.sometime.push_back($sometimeclause.socl);}
	| uncond_sometimeclause {result.sometime.push_back($uncond_sometimeclause.socl);}
;

sometimeclause returns [SometimeClause socl]
:
	'or' '(' '['
		(l1=literal {socl.first.insert($l1.var);})
		(',' l2=literal {socl.first.insert($l2.var);})*
		','?
		so1=sometimeliteral {socl.second = $so1.var;}
	']'')'
;


uncond_sometimeclause returns [SometimeClause socl]
@init {socl.first.insert(-1);}
:
	'or' '(' '['
		so1=sometimeliteral {socl.second = $so1.var;}
	']'')'
;

uncond_stepclause returns [StepClause stcl]
@init {stcl.first.insert(-1);}
:
	'or' '(' '['
		sl1=stepliteral {stcl.second.insert($sl1.var);}
		(',' sl2=stepliteral {stcl.second.insert($sl2.var);})*
	']'')'
;

stepclause returns [StepClause stcl]
:
	'or' '(' '['
		(l1=literal {stcl.first.insert($l1.var);})
		(',' l2=literal {stcl.first.insert($l2.var);})* 
		','?
		sl1=stepliteral {stcl.second.insert($sl1.var);}
		(',' sl2=stepliteral {stcl.second.insert($sl2.var);})*
	']'')'
;

clause returns [T_Clause cl]
:
	'or' '(' '['
		l1=literal {cl.insert($l1.var);}
		(',' l2=literal {cl.insert($l2.var);})*
	']'')'
;


stepliteral returns [int var]
:
	'next''('literal')' {var = $literal.var;}
;

sometimeliteral returns [int var]
:
	'sometime''('literal')' {var = $literal.var;}

;

literal returns [int var]
:	
	'not''('(ID)')'{ var = (result.table.getVar($ID.text) * -1); }
	| 'not' ID { var = (result.table.getVar($ID.text) * -1); }
	| ID { var = result.table.getVar($ID.text); }
;


ID  :	('a'..'z' | 'A'..'Z'|'0'..'9')*;


WS  :   ( ' '
        | '\t'
        | '\r'
        | '\n'
        ) {$channel=HIDDEN;}
    ;

