// ProgramState.h
//
// CS 104 / Fall 2021
//
// The ProgramState class encapsulates the state of an executing Facile
// program.  The state of a BASIC program consists of three parts:
//
//    * The program counter, which specifies the line number of the
//      statement that will execute next.
//    * A map, as explained by the problem writeup.
//    * A stack of integers, which is used to hold return lines for GOSUB
//      statements.
//
// We've provided you a start on this class, but you'll need to add methods
// to it as you go along.  In particular, you'll need methods to access and
// modify the state; these methods will be called primarily by the various
// execute() methods in the Statement subclasses, to allow the execution of
// a statement to change the state of a program.  For example, executing a
// GOTO statement will cause the program counter to be changed.

#ifndef PROGRAM_STATE_INCLUDED
#define PROGRAM_STATE_INCLUDED
#include <map>
#include <stack>

class ProgramState
{
public:
	ProgramState(int numLines);

	// You'll need to add a variety of methods here.  Rather than trying to
	// think of what you'll need to add ahead of time, add them as you find
	// that you need them.

    void nextLine();

    void setValue(std::string s, int val); // Sets value for LET

    void print(std::string s, std::ostream& outf); // Print out a variable

    void printAll(std::ostream& outf); // Prints out all variables in format, VAR VAL

    int getLine();

    int getNumLines();

    int getValue(std::string s); // Get value of variable

    ProgramState* endState(); // End the program

    void add(std::string s, int val);

    void sub(std::string s, int val);

    void multiply(std::string s, int val);

    void div(std::string s, int val);

    void goTo(int val);

    void goSub(int val);

    void returnTo();

    void ifState(std::string var, std::string op, int val, int line);


private:
    int m_numLines;
    int line;
    std::map<std::string, int> programMap; // Map to store variables and their values
    std::map<std::string, int>::iterator it; // Map iterator
    std::stack<int> lineStack; // Stack for GOSUB and RETURN
};

#endif
