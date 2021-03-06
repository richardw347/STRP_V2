/** \file
 *  This C++ source file was generated by $ANTLR version 3.4
 *
 *     -  From the grammar source file : SNF.g
 *     -                            On : 2012-12-17 12:31:42
 *     -                 for the lexer : SNFLexerLexer
 *
 * Editing it, at least manually, is not wise.
 *
 * C++ language generator and runtime by Gokulakannan Somasundaram ( heavy lifting from C Run-time by Jim Idle )
 *
 *
*/
// [The "BSD license"]
// Copyright (c) 2005-2009 Gokulakannan Somasundaram, ElectronDB
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

/* -----------------------------------------
 * Include the ANTLR3 generated header file.
 */
#include    "SNFLexer.hpp"
/* ----------------------------------------- */



	namespace 	STRP  {


/** String literals used by SNFLexer that we must do things like MATCHS() with.
 *  C will normally just lay down 8 bit characters, and you can use L"xxx" to
 *  get wchar_t, but wchar_t is 16 bits on Windows, which is not UTF32 and so
 *  we perform this little trick of defining the literals as arrays of UINT32
 *  and passing in the address of these.
 */
static ANTLR_UCHAR	lit_1[]  = { 0x61, 0x6C, 0x77, 0x61, 0x79, 0x73,  antlr3::ANTLR_STRING_TERMINATOR};
static ANTLR_UCHAR	lit_2[]  = { 0x61, 0x6E, 0x64,  antlr3::ANTLR_STRING_TERMINATOR};
static ANTLR_UCHAR	lit_3[]  = { 0x6E, 0x65, 0x78, 0x74,  antlr3::ANTLR_STRING_TERMINATOR};
static ANTLR_UCHAR	lit_4[]  = { 0x6E, 0x6F, 0x74,  antlr3::ANTLR_STRING_TERMINATOR};
static ANTLR_UCHAR	lit_5[]  = { 0x6F, 0x72,  antlr3::ANTLR_STRING_TERMINATOR};
static ANTLR_UCHAR	lit_6[]  = { 0x73, 0x6F, 0x6D, 0x65, 0x74, 0x69, 0x6D, 0x65,  antlr3::ANTLR_STRING_TERMINATOR};

	}



/* ============================================================================= */

/* =============================================================================
 * Start of recognizer
 */

using namespace antlr3;

	namespace 	STRP  {


/* =========================================================================
 * Lexer matching rules end.
 * =========================================================================
 */



SNFLexer::~SNFLexer()
{
}

void
SNFLexer::reset()
{
    this->get_rec()->reset();
}

/** \brief Name of the grammar file that generated this code
 */
static const char fileName[] = "SNF.g";

/** \brief Return the name of the grammar file that generated this code.
 */
const char* SNFLexer::getGrammarFileName()
{
	return fileName;
}

/** \brief Create a new lexer called SNFLexer
 *
 * \param[in]    instream Pointer to an initialized input stream
 * \return
 *     - Success pSNFLexer initialized for the lex start
 *     - Fail NULL
 */
SNFLexer::SNFLexer(StreamType* instream)
:SNFLexerImplTraits::BaseLexerType(ANTLR_SIZE_HINT, instream, NULL)
{
	// See if we can create a new lexer with the standard constructor
	//
	this->init(instream );
}

/** \brief Create a new lexer called SNFLexer
 *
 * \param[in]    instream Pointer to an initialized input stream
 * \param[state] state Previously created shared recognizer stat
 * \return
 *     - Success pSNFLexer initialized for the lex start
 *     - Fail NULL
 */
SNFLexer::SNFLexer(StreamType* instream, RecognizerSharedStateType* state)
:SNFLexerImplTraits::BaseLexerType(ANTLR_SIZE_HINT, instream, state)
{
	this->init(instream );
}

void SNFLexer::init(StreamType* instream)
{
    /* -------------------------------------------------------------------
     * Memory for basic structure is allocated, now to fill in
     * in base ANTLR3 structures. We initialize the function pointers
     * for the standard ANTLR3 lexer function set, but upon return
     * from here, the programmer may set the pointers to provide custom
     * implementations of each function.
     *
     * We don't use the macros defined in SNFLexer.h here so you can get a sense
     * of what goes where.
     */

}

/* =========================================================================
 * Functions to match the lexer grammar defined tokens from the input stream
 */

//   Comes from: 18:6: ( '(' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start T__6
 *
 * Looks to match the characters the constitute the token T__6
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == true if an exception was thrown.
 */
void SNFLexer::mT__6()
{
    ANTLR_UINT32	_type;
      


    _type	    = T__6;


    // SNF.g:18:6: ( '(' )
    // SNF.g:18:8: '('
    {
         this->matchc('(');
        if  (this->hasException())
        {
            goto ruleT__6Ex;
        }


    }

	this->get_lexstate()->set_type(_type);
    // This is where rules clean up and exit
    //
    goto ruleT__6Ex; /* Prevent compiler warnings */
    ruleT__6Ex: ;

}
// $ANTLR end T__6

//   Comes from: 19:6: ( ')' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start T__7
 *
 * Looks to match the characters the constitute the token T__7
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == true if an exception was thrown.
 */
void SNFLexer::mT__7()
{
    ANTLR_UINT32	_type;
      


    _type	    = T__7;


    // SNF.g:19:6: ( ')' )
    // SNF.g:19:8: ')'
    {
         this->matchc(')');
        if  (this->hasException())
        {
            goto ruleT__7Ex;
        }


    }

	this->get_lexstate()->set_type(_type);
    // This is where rules clean up and exit
    //
    goto ruleT__7Ex; /* Prevent compiler warnings */
    ruleT__7Ex: ;

}
// $ANTLR end T__7

//   Comes from: 20:6: ( ',' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start T__8
 *
 * Looks to match the characters the constitute the token T__8
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == true if an exception was thrown.
 */
void SNFLexer::mT__8()
{
    ANTLR_UINT32	_type;
      


    _type	    = T__8;


    // SNF.g:20:6: ( ',' )
    // SNF.g:20:8: ','
    {
         this->matchc(',');
        if  (this->hasException())
        {
            goto ruleT__8Ex;
        }


    }

	this->get_lexstate()->set_type(_type);
    // This is where rules clean up and exit
    //
    goto ruleT__8Ex; /* Prevent compiler warnings */
    ruleT__8Ex: ;

}
// $ANTLR end T__8

//   Comes from: 21:6: ( '.' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start T__9
 *
 * Looks to match the characters the constitute the token T__9
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == true if an exception was thrown.
 */
void SNFLexer::mT__9()
{
    ANTLR_UINT32	_type;
      


    _type	    = T__9;


    // SNF.g:21:6: ( '.' )
    // SNF.g:21:8: '.'
    {
         this->matchc('.');
        if  (this->hasException())
        {
            goto ruleT__9Ex;
        }


    }

	this->get_lexstate()->set_type(_type);
    // This is where rules clean up and exit
    //
    goto ruleT__9Ex; /* Prevent compiler warnings */
    ruleT__9Ex: ;

}
// $ANTLR end T__9

//   Comes from: 22:7: ( '[' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start T__10
 *
 * Looks to match the characters the constitute the token T__10
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == true if an exception was thrown.
 */
void SNFLexer::mT__10()
{
    ANTLR_UINT32	_type;
      


    _type	    = T__10;


    // SNF.g:22:7: ( '[' )
    // SNF.g:22:9: '['
    {
         this->matchc('[');
        if  (this->hasException())
        {
            goto ruleT__10Ex;
        }


    }

	this->get_lexstate()->set_type(_type);
    // This is where rules clean up and exit
    //
    goto ruleT__10Ex; /* Prevent compiler warnings */
    ruleT__10Ex: ;

}
// $ANTLR end T__10

//   Comes from: 23:7: ( ']' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start T__11
 *
 * Looks to match the characters the constitute the token T__11
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == true if an exception was thrown.
 */
void SNFLexer::mT__11()
{
    ANTLR_UINT32	_type;
      


    _type	    = T__11;


    // SNF.g:23:7: ( ']' )
    // SNF.g:23:9: ']'
    {
         this->matchc(']');
        if  (this->hasException())
        {
            goto ruleT__11Ex;
        }


    }

	this->get_lexstate()->set_type(_type);
    // This is where rules clean up and exit
    //
    goto ruleT__11Ex; /* Prevent compiler warnings */
    ruleT__11Ex: ;

}
// $ANTLR end T__11

//   Comes from: 24:7: ( 'always' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start T__12
 *
 * Looks to match the characters the constitute the token T__12
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == true if an exception was thrown.
 */
void SNFLexer::mT__12()
{
    ANTLR_UINT32	_type;
      


    _type	    = T__12;


    // SNF.g:24:7: ( 'always' )
    // SNF.g:24:9: 'always'
    {
        this->matchs(lit_1);
        if  (this->hasException())
        {
            goto ruleT__12Ex;
        }




    }

	this->get_lexstate()->set_type(_type);
    // This is where rules clean up and exit
    //
    goto ruleT__12Ex; /* Prevent compiler warnings */
    ruleT__12Ex: ;

}
// $ANTLR end T__12

//   Comes from: 25:7: ( 'and' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start T__13
 *
 * Looks to match the characters the constitute the token T__13
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == true if an exception was thrown.
 */
void SNFLexer::mT__13()
{
    ANTLR_UINT32	_type;
      


    _type	    = T__13;


    // SNF.g:25:7: ( 'and' )
    // SNF.g:25:9: 'and'
    {
        this->matchs(lit_2);
        if  (this->hasException())
        {
            goto ruleT__13Ex;
        }




    }

	this->get_lexstate()->set_type(_type);
    // This is where rules clean up and exit
    //
    goto ruleT__13Ex; /* Prevent compiler warnings */
    ruleT__13Ex: ;

}
// $ANTLR end T__13

//   Comes from: 26:7: ( 'next' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start T__14
 *
 * Looks to match the characters the constitute the token T__14
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == true if an exception was thrown.
 */
void SNFLexer::mT__14()
{
    ANTLR_UINT32	_type;
      


    _type	    = T__14;


    // SNF.g:26:7: ( 'next' )
    // SNF.g:26:9: 'next'
    {
        this->matchs(lit_3);
        if  (this->hasException())
        {
            goto ruleT__14Ex;
        }




    }

	this->get_lexstate()->set_type(_type);
    // This is where rules clean up and exit
    //
    goto ruleT__14Ex; /* Prevent compiler warnings */
    ruleT__14Ex: ;

}
// $ANTLR end T__14

//   Comes from: 27:7: ( 'not' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start T__15
 *
 * Looks to match the characters the constitute the token T__15
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == true if an exception was thrown.
 */
void SNFLexer::mT__15()
{
    ANTLR_UINT32	_type;
      


    _type	    = T__15;


    // SNF.g:27:7: ( 'not' )
    // SNF.g:27:9: 'not'
    {
        this->matchs(lit_4);
        if  (this->hasException())
        {
            goto ruleT__15Ex;
        }




    }

	this->get_lexstate()->set_type(_type);
    // This is where rules clean up and exit
    //
    goto ruleT__15Ex; /* Prevent compiler warnings */
    ruleT__15Ex: ;

}
// $ANTLR end T__15

//   Comes from: 28:7: ( 'or' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start T__16
 *
 * Looks to match the characters the constitute the token T__16
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == true if an exception was thrown.
 */
void SNFLexer::mT__16()
{
    ANTLR_UINT32	_type;
      


    _type	    = T__16;


    // SNF.g:28:7: ( 'or' )
    // SNF.g:28:9: 'or'
    {
        this->matchs(lit_5);
        if  (this->hasException())
        {
            goto ruleT__16Ex;
        }




    }

	this->get_lexstate()->set_type(_type);
    // This is where rules clean up and exit
    //
    goto ruleT__16Ex; /* Prevent compiler warnings */
    ruleT__16Ex: ;

}
// $ANTLR end T__16

//   Comes from: 29:7: ( 'sometime' )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start T__17
 *
 * Looks to match the characters the constitute the token T__17
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == true if an exception was thrown.
 */
void SNFLexer::mT__17()
{
    ANTLR_UINT32	_type;
      


    _type	    = T__17;


    // SNF.g:29:7: ( 'sometime' )
    // SNF.g:29:9: 'sometime'
    {
        this->matchs(lit_6);
        if  (this->hasException())
        {
            goto ruleT__17Ex;
        }




    }

	this->get_lexstate()->set_type(_type);
    // This is where rules clean up and exit
    //
    goto ruleT__17Ex; /* Prevent compiler warnings */
    ruleT__17Ex: ;

}
// $ANTLR end T__17

//   Comes from: 137:5: ( ( 'a' .. 'z' | 'A' .. 'Z' | '0' .. '9' )* )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start ID
 *
 * Looks to match the characters the constitute the token ID
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == true if an exception was thrown.
 */
void SNFLexer::mID()
{
    ANTLR_UINT32	_type;
      


    _type	    = ID;


    // SNF.g:137:5: ( ( 'a' .. 'z' | 'A' .. 'Z' | '0' .. '9' )* )
    // SNF.g:137:7: ( 'a' .. 'z' | 'A' .. 'Z' | '0' .. '9' )*
    {
        // SNF.g:137:7: ( 'a' .. 'z' | 'A' .. 'Z' | '0' .. '9' )*

        for (;;)
        {
            int alt1=2;
            switch ( this->LA(1) )
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
            case 'I':
            case 'J':
            case 'K':
            case 'L':
            case 'M':
            case 'N':
            case 'O':
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
            case 'V':
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'h':
            case 'i':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'o':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'u':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
            	{
            		alt1=1;
            	}
                break;

            }

            switch (alt1)
            {
        	case 1:
        	    // SNF.g:
        	    {
        	        if ( ((this->LA(1) >= '0') && (this->LA(1) <= '9')) || ((this->LA(1) >= 'A') && (this->LA(1) <= 'Z')) || ((this->LA(1) >= 'a') && (this->LA(1) <= 'z')) )
        	        {
        	            this->consume();
        	        }
        	        else
        	        {
        	            new ANTLR_Exception< SNFLexerImplTraits, MISMATCHED_SET_EXCEPTION, StreamType>( this->get_rec(), "" );

        	            this->recover();
        	            goto ruleIDEx;
        	        }


        	    }
        	    break;

        	default:
        	    goto loop1;	/* break out of the loop */
        	    break;
            }
        }
        loop1: ; /* Jump out to here if this rule does not match */


    }

	this->get_lexstate()->set_type(_type);
    // This is where rules clean up and exit
    //
    goto ruleIDEx; /* Prevent compiler warnings */
    ruleIDEx: ;

}
// $ANTLR end ID

//   Comes from: 140:5: ( ( ' ' | '\\t' | '\\r' | '\\n' ) )
/** \brief Lexer rule generated by ANTLR3
 *
 * $ANTLR start WS
 *
 * Looks to match the characters the constitute the token WS
 * from the attached input stream.
 *
 *
 * \remark
 *  - lexer->error == true if an exception was thrown.
 */
void SNFLexer::mWS()
{
    ANTLR_UINT32	_type;
      


    _type	    = WS;


    // SNF.g:140:5: ( ( ' ' | '\\t' | '\\r' | '\\n' ) )
    // SNF.g:140:9: ( ' ' | '\\t' | '\\r' | '\\n' )
    {
        if ( ((this->LA(1) >= '\t') && (this->LA(1) <= '\n')) || this->LA(1) == '\r' || this->LA(1) == ' ' )
        {
            this->consume();
        }
        else
        {
            new ANTLR_Exception< SNFLexerImplTraits, MISMATCHED_SET_EXCEPTION, StreamType>( this->get_rec(), "" );

            this->recover();
            goto ruleWSEx;
        }


        {
            this->get_state()->get_channel()=HIDDEN;
        }


    }

	this->get_lexstate()->set_type(_type);
    // This is where rules clean up and exit
    //
    goto ruleWSEx; /* Prevent compiler warnings */
    ruleWSEx: ;

}
// $ANTLR end WS

/** This is the entry point in to the lexer from an object that
 *  wants to generate the next token, such as a pCOMMON_TOKEN_STREAM
 */
void
SNFLexer::mTokens()
{
    {
        //  SNF.g:1:8: ( T__6 | T__7 | T__8 | T__9 | T__10 | T__11 | T__12 | T__13 | T__14 | T__15 | T__16 | T__17 | ID | WS )

        ANTLR_UINT32 alt2;

        alt2=14;

        switch ( this->LA(1) )
        {
        case '(':
        	{
        		alt2=1;
        	}
            break;
        case ')':
        	{
        		alt2=2;
        	}
            break;
        case ',':
        	{
        		alt2=3;
        	}
            break;
        case '.':
        	{
        		alt2=4;
        	}
            break;
        case '[':
        	{
        		alt2=5;
        	}
            break;
        case ']':
        	{
        		alt2=6;
        	}
            break;
        case 'a':
        	{
        		switch ( this->LA(2) )
        		{
        		case 'l':
        			{
        				switch ( this->LA(3) )
        				{
        				case 'w':
        					{
        						switch ( this->LA(4) )
        						{
        						case 'a':
        							{
        								switch ( this->LA(5) )
        								{
        								case 'y':
        									{
        										switch ( this->LA(6) )
        										{
        										case 's':
        											{
        												switch ( this->LA(7) )
        												{
        												case '0':
        												case '1':
        												case '2':
        												case '3':
        												case '4':
        												case '5':
        												case '6':
        												case '7':
        												case '8':
        												case '9':
        												case 'A':
        												case 'B':
        												case 'C':
        												case 'D':
        												case 'E':
        												case 'F':
        												case 'G':
        												case 'H':
        												case 'I':
        												case 'J':
        												case 'K':
        												case 'L':
        												case 'M':
        												case 'N':
        												case 'O':
        												case 'P':
        												case 'Q':
        												case 'R':
        												case 'S':
        												case 'T':
        												case 'U':
        												case 'V':
        												case 'W':
        												case 'X':
        												case 'Y':
        												case 'Z':
        												case 'a':
        												case 'b':
        												case 'c':
        												case 'd':
        												case 'e':
        												case 'f':
        												case 'g':
        												case 'h':
        												case 'i':
        												case 'j':
        												case 'k':
        												case 'l':
        												case 'm':
        												case 'n':
        												case 'o':
        												case 'p':
        												case 'q':
        												case 'r':
        												case 's':
        												case 't':
        												case 'u':
        												case 'v':
        												case 'w':
        												case 'x':
        												case 'y':
        												case 'z':
        													{
        														alt2=13;
        													}
        												    break;

        												default:
        												    alt2=7;
        												}

        											}
        										    break;

        										default:
        										    alt2=13;
        										}

        									}
        								    break;

        								default:
        								    alt2=13;
        								}

        							}
        						    break;

        						default:
        						    alt2=13;
        						}

        					}
        				    break;

        				default:
        				    alt2=13;
        				}

        			}
        		    break;
        		case 'n':
        			{
        				switch ( this->LA(3) )
        				{
        				case 'd':
        					{
        						switch ( this->LA(4) )
        						{
        						case '0':
        						case '1':
        						case '2':
        						case '3':
        						case '4':
        						case '5':
        						case '6':
        						case '7':
        						case '8':
        						case '9':
        						case 'A':
        						case 'B':
        						case 'C':
        						case 'D':
        						case 'E':
        						case 'F':
        						case 'G':
        						case 'H':
        						case 'I':
        						case 'J':
        						case 'K':
        						case 'L':
        						case 'M':
        						case 'N':
        						case 'O':
        						case 'P':
        						case 'Q':
        						case 'R':
        						case 'S':
        						case 'T':
        						case 'U':
        						case 'V':
        						case 'W':
        						case 'X':
        						case 'Y':
        						case 'Z':
        						case 'a':
        						case 'b':
        						case 'c':
        						case 'd':
        						case 'e':
        						case 'f':
        						case 'g':
        						case 'h':
        						case 'i':
        						case 'j':
        						case 'k':
        						case 'l':
        						case 'm':
        						case 'n':
        						case 'o':
        						case 'p':
        						case 'q':
        						case 'r':
        						case 's':
        						case 't':
        						case 'u':
        						case 'v':
        						case 'w':
        						case 'x':
        						case 'y':
        						case 'z':
        							{
        								alt2=13;
        							}
        						    break;

        						default:
        						    alt2=8;
        						}

        					}
        				    break;

        				default:
        				    alt2=13;
        				}

        			}
        		    break;

        		default:
        		    alt2=13;
        		}

        	}
            break;
        case 'n':
        	{
        		switch ( this->LA(2) )
        		{
        		case 'e':
        			{
        				switch ( this->LA(3) )
        				{
        				case 'x':
        					{
        						switch ( this->LA(4) )
        						{
        						case 't':
        							{
        								switch ( this->LA(5) )
        								{
        								case '0':
        								case '1':
        								case '2':
        								case '3':
        								case '4':
        								case '5':
        								case '6':
        								case '7':
        								case '8':
        								case '9':
        								case 'A':
        								case 'B':
        								case 'C':
        								case 'D':
        								case 'E':
        								case 'F':
        								case 'G':
        								case 'H':
        								case 'I':
        								case 'J':
        								case 'K':
        								case 'L':
        								case 'M':
        								case 'N':
        								case 'O':
        								case 'P':
        								case 'Q':
        								case 'R':
        								case 'S':
        								case 'T':
        								case 'U':
        								case 'V':
        								case 'W':
        								case 'X':
        								case 'Y':
        								case 'Z':
        								case 'a':
        								case 'b':
        								case 'c':
        								case 'd':
        								case 'e':
        								case 'f':
        								case 'g':
        								case 'h':
        								case 'i':
        								case 'j':
        								case 'k':
        								case 'l':
        								case 'm':
        								case 'n':
        								case 'o':
        								case 'p':
        								case 'q':
        								case 'r':
        								case 's':
        								case 't':
        								case 'u':
        								case 'v':
        								case 'w':
        								case 'x':
        								case 'y':
        								case 'z':
        									{
        										alt2=13;
        									}
        								    break;

        								default:
        								    alt2=9;
        								}

        							}
        						    break;

        						default:
        						    alt2=13;
        						}

        					}
        				    break;

        				default:
        				    alt2=13;
        				}

        			}
        		    break;
        		case 'o':
        			{
        				switch ( this->LA(3) )
        				{
        				case 't':
        					{
        						switch ( this->LA(4) )
        						{
        						case '0':
        						case '1':
        						case '2':
        						case '3':
        						case '4':
        						case '5':
        						case '6':
        						case '7':
        						case '8':
        						case '9':
        						case 'A':
        						case 'B':
        						case 'C':
        						case 'D':
        						case 'E':
        						case 'F':
        						case 'G':
        						case 'H':
        						case 'I':
        						case 'J':
        						case 'K':
        						case 'L':
        						case 'M':
        						case 'N':
        						case 'O':
        						case 'P':
        						case 'Q':
        						case 'R':
        						case 'S':
        						case 'T':
        						case 'U':
        						case 'V':
        						case 'W':
        						case 'X':
        						case 'Y':
        						case 'Z':
        						case 'a':
        						case 'b':
        						case 'c':
        						case 'd':
        						case 'e':
        						case 'f':
        						case 'g':
        						case 'h':
        						case 'i':
        						case 'j':
        						case 'k':
        						case 'l':
        						case 'm':
        						case 'n':
        						case 'o':
        						case 'p':
        						case 'q':
        						case 'r':
        						case 's':
        						case 't':
        						case 'u':
        						case 'v':
        						case 'w':
        						case 'x':
        						case 'y':
        						case 'z':
        							{
        								alt2=13;
        							}
        						    break;

        						default:
        						    alt2=10;
        						}

        					}
        				    break;

        				default:
        				    alt2=13;
        				}

        			}
        		    break;

        		default:
        		    alt2=13;
        		}

        	}
            break;
        case 'o':
        	{
        		switch ( this->LA(2) )
        		{
        		case 'r':
        			{
        				switch ( this->LA(3) )
        				{
        				case '0':
        				case '1':
        				case '2':
        				case '3':
        				case '4':
        				case '5':
        				case '6':
        				case '7':
        				case '8':
        				case '9':
        				case 'A':
        				case 'B':
        				case 'C':
        				case 'D':
        				case 'E':
        				case 'F':
        				case 'G':
        				case 'H':
        				case 'I':
        				case 'J':
        				case 'K':
        				case 'L':
        				case 'M':
        				case 'N':
        				case 'O':
        				case 'P':
        				case 'Q':
        				case 'R':
        				case 'S':
        				case 'T':
        				case 'U':
        				case 'V':
        				case 'W':
        				case 'X':
        				case 'Y':
        				case 'Z':
        				case 'a':
        				case 'b':
        				case 'c':
        				case 'd':
        				case 'e':
        				case 'f':
        				case 'g':
        				case 'h':
        				case 'i':
        				case 'j':
        				case 'k':
        				case 'l':
        				case 'm':
        				case 'n':
        				case 'o':
        				case 'p':
        				case 'q':
        				case 'r':
        				case 's':
        				case 't':
        				case 'u':
        				case 'v':
        				case 'w':
        				case 'x':
        				case 'y':
        				case 'z':
        					{
        						alt2=13;
        					}
        				    break;

        				default:
        				    alt2=11;
        				}

        			}
        		    break;

        		default:
        		    alt2=13;
        		}

        	}
            break;
        case 's':
        	{
        		switch ( this->LA(2) )
        		{
        		case 'o':
        			{
        				switch ( this->LA(3) )
        				{
        				case 'm':
        					{
        						switch ( this->LA(4) )
        						{
        						case 'e':
        							{
        								switch ( this->LA(5) )
        								{
        								case 't':
        									{
        										switch ( this->LA(6) )
        										{
        										case 'i':
        											{
        												switch ( this->LA(7) )
        												{
        												case 'm':
        													{
        														switch ( this->LA(8) )
        														{
        														case 'e':
        															{
        																switch ( this->LA(9) )
        																{
        																case '0':
        																case '1':
        																case '2':
        																case '3':
        																case '4':
        																case '5':
        																case '6':
        																case '7':
        																case '8':
        																case '9':
        																case 'A':
        																case 'B':
        																case 'C':
        																case 'D':
        																case 'E':
        																case 'F':
        																case 'G':
        																case 'H':
        																case 'I':
        																case 'J':
        																case 'K':
        																case 'L':
        																case 'M':
        																case 'N':
        																case 'O':
        																case 'P':
        																case 'Q':
        																case 'R':
        																case 'S':
        																case 'T':
        																case 'U':
        																case 'V':
        																case 'W':
        																case 'X':
        																case 'Y':
        																case 'Z':
        																case 'a':
        																case 'b':
        																case 'c':
        																case 'd':
        																case 'e':
        																case 'f':
        																case 'g':
        																case 'h':
        																case 'i':
        																case 'j':
        																case 'k':
        																case 'l':
        																case 'm':
        																case 'n':
        																case 'o':
        																case 'p':
        																case 'q':
        																case 'r':
        																case 's':
        																case 't':
        																case 'u':
        																case 'v':
        																case 'w':
        																case 'x':
        																case 'y':
        																case 'z':
        																	{
        																		alt2=13;
        																	}
        																    break;

        																default:
        																    alt2=12;
        																}

        															}
        														    break;

        														default:
        														    alt2=13;
        														}

        													}
        												    break;

        												default:
        												    alt2=13;
        												}

        											}
        										    break;

        										default:
        										    alt2=13;
        										}

        									}
        								    break;

        								default:
        								    alt2=13;
        								}

        							}
        						    break;

        						default:
        						    alt2=13;
        						}

        					}
        				    break;

        				default:
        				    alt2=13;
        				}

        			}
        		    break;

        		default:
        		    alt2=13;
        		}

        	}
            break;
        case '\t':
        case '\n':
        case '\r':
        case ' ':
        	{
        		alt2=14;
        	}
            break;

        default:
            alt2=13;
        }

        switch (alt2)
        {
    	case 1:
    	    // SNF.g:1:10: T__6
    	    {
    	        /* 1:10: T__6 */
    	        mT__6();
    	        if  (this->hasException())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 2:
    	    // SNF.g:1:15: T__7
    	    {
    	        /* 1:15: T__7 */
    	        mT__7();
    	        if  (this->hasException())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 3:
    	    // SNF.g:1:20: T__8
    	    {
    	        /* 1:20: T__8 */
    	        mT__8();
    	        if  (this->hasException())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 4:
    	    // SNF.g:1:25: T__9
    	    {
    	        /* 1:25: T__9 */
    	        mT__9();
    	        if  (this->hasException())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 5:
    	    // SNF.g:1:30: T__10
    	    {
    	        /* 1:30: T__10 */
    	        mT__10();
    	        if  (this->hasException())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 6:
    	    // SNF.g:1:36: T__11
    	    {
    	        /* 1:36: T__11 */
    	        mT__11();
    	        if  (this->hasException())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 7:
    	    // SNF.g:1:42: T__12
    	    {
    	        /* 1:42: T__12 */
    	        mT__12();
    	        if  (this->hasException())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 8:
    	    // SNF.g:1:48: T__13
    	    {
    	        /* 1:48: T__13 */
    	        mT__13();
    	        if  (this->hasException())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 9:
    	    // SNF.g:1:54: T__14
    	    {
    	        /* 1:54: T__14 */
    	        mT__14();
    	        if  (this->hasException())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 10:
    	    // SNF.g:1:60: T__15
    	    {
    	        /* 1:60: T__15 */
    	        mT__15();
    	        if  (this->hasException())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 11:
    	    // SNF.g:1:66: T__16
    	    {
    	        /* 1:66: T__16 */
    	        mT__16();
    	        if  (this->hasException())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 12:
    	    // SNF.g:1:72: T__17
    	    {
    	        /* 1:72: T__17 */
    	        mT__17();
    	        if  (this->hasException())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 13:
    	    // SNF.g:1:78: ID
    	    {
    	        /* 1:78: ID */
    	        mID();
    	        if  (this->hasException())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;
    	case 14:
    	    // SNF.g:1:81: WS
    	    {
    	        /* 1:81: WS */
    	        mWS();
    	        if  (this->hasException())
    	        {
    	            goto ruleTokensEx;
    	        }



    	    }
    	    break;

        }
    }


    goto ruleTokensEx; /* Prevent compiler warnings */
ruleTokensEx: ;
}

/* =========================================================================
 * Lexer matching rules end.
 * =========================================================================
 */
/* End of Lexer code
 * ================================================
 * ================================================
 */

	}



/* End of code
 * =============================================================================
 */
