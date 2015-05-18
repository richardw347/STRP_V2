cmake_minimum_required(VERSION 2.8.3)

project(strp_v2)

find_package(Boost REQUIRED)

set(ANTLR_FILES
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3baserecognizer.hpp
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3baserecognizer.inl
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3bitset.hpp
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3bitset.inl
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3collections.hpp
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3collections.inl
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3commontoken.hpp
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3commontoken.inl
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3commontreeadaptor.hpp
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3commontreeadaptor.inl
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3commontree.hpp
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3commontree.inl
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3commontreenodestream.hpp
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3commontreenodestream.inl
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3convertutf.hpp
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3cyclicdfa.hpp
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3cyclicdfa.inl
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3debugeventlistener.hpp
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3defs.hpp
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3errors.hpp
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3exception.hpp
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3exception.inl
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3filestream.hpp
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3filestream.inl
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3.hpp
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3.inl
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3input.hpp
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3input.inl
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3interfaces.hpp
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3intstream.hpp
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3intstream.inl
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3lexer.hpp
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3lexer.inl
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3memory.hpp
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3parser.hpp
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3parser.inl
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3recognizersharedstate.hpp
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3recognizersharedstate.inl
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3rewritestreams.hpp
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3rewritestreams.inl
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3tokenstream.hpp
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3tokenstream.inl
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3traits.hpp
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3treeparser.hpp
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR/antlr3treeparser.inl
)

set(MINISAT_FILES
	${PROJECT_SOURCE_DIR}/thridparty/minisat/Constraints.C
	${PROJECT_SOURCE_DIR}/thridparty/minisat/Constraints.h
	${PROJECT_SOURCE_DIR}/thridparty/minisat/Global.h
	${PROJECT_SOURCE_DIR}/thridparty/minisat/Heap.h
	${PROJECT_SOURCE_DIR}/thridparty/minisat/Minisat.h
	${PROJECT_SOURCE_DIR}/thridparty/minisat/Queue.h
	${PROJECT_SOURCE_DIR}/thridparty/minisat/Solver.C
	${PROJECT_SOURCE_DIR}/thridparty/minisat/Solver.h
	${PROJECT_SOURCE_DIR}/thridparty/minisat/SolverTypes.h
	${PROJECT_SOURCE_DIR}/thridparty/minisat/Sort.h
	${PROJECT_SOURCE_DIR}/thridparty/minisat/VarOrder.h
)

set(HEADER_FILES
	${PROJECT_SOURCE_DIR}/include/data_struct/CNF_DNF.h
	${PROJECT_SOURCE_DIR}/include/data_struct/DataStruct.h
	${PROJECT_SOURCE_DIR}/include/data_struct/DSNFFormula.h
	${PROJECT_SOURCE_DIR}/include/data_struct/SNFFormula.h
	${PROJECT_SOURCE_DIR}/include/data_struct/SymbolTable.h
	${PROJECT_SOURCE_DIR}/include/data_struct/Translator.h
	${PROJECT_SOURCE_DIR}/include/parser/SNFLexer.hpp
	${PROJECT_SOURCE_DIR}/include/parser/SNFParser.hpp
	${PROJECT_SOURCE_DIR}/include/solver/DSNFSolver.h
	${PROJECT_SOURCE_DIR}/include/solver/SometimeResolution.h
        ${PROJECT_SOURCE_DIR}/include/solver/StepResolution.h

)
set(SOURCE_FILES
	${PROJECT_SOURCE_DIR}/src/DSNFSolver.cpp
	${PROJECT_SOURCE_DIR}/src/SNF.g
	${PROJECT_SOURCE_DIR}/src/SNFLexer.cpp
	${PROJECT_SOURCE_DIR}/src/SNFParser.cpp
	${PROJECT_SOURCE_DIR}/src/SNF.tokens
	${PROJECT_SOURCE_DIR}/src/SometimeResolution.cpp
	${PROJECT_SOURCE_DIR}/src/StepResolution.cpp
	${PROJECT_SOURCE_DIR}/src/STRP++.cpp
)

include_directories(
    ${PROJECT_SOURCE_DIR}/include/data_struct
    ${PROJECT_SOURCE_DIR}/include/parser
    ${PROJECT_SOURCE_DIR}/include/solver
    ${PROJECT_SOURCE_DIR}/thridparty/minisat
    ${PROJECT_SOURCE_DIR}/thridparty/ANTLR
)
add_executable(STRP_V2 ${ANTLR_FILES} ${MINISAT_FILES} ${HEADER_FILES} ${SOURCE_FILES})

install(TARGETS STRP_V2 DESTINATION bin)

