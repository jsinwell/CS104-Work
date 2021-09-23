// Interpreter.cpp
#include "../lib/AddStatement.h"
#include "../lib/DivStatement.h"
#include "../lib/EndStatement.h"
#include "../lib/GoSubStatement.h"
#include "../lib/GoToStatement.h"
#include "../lib/IfStatement.h"
#include "../lib/LetStatement.h"
#include "../lib/MultiplyStatement.h"
#include "../lib/PrintALLStatement.h"
#include "../lib/PrintStatement.h"
#include "../lib/ProgramState.h"
#include "../lib/ReturnStatement.h"
#include "../lib/Statement.h"
#include "../lib/SubStatement.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// parseProgram() takes a filename as a parameter, opens and reads the
// contents of the file, and returns an vector of pointers to Statement.
void parseProgram(istream& inf, vector<Statement*>& program);

// parseLine() takes a line from the input file and returns a Statement
// pointer of the appropriate type.  This will be a handy method to call
// within your parseProgram() method.
Statement* parseLine(string line);

// interpretProgram() reads a program from the given input stream
// and interprets it, writing any output to the given output stream.
// Note:  you are required to implement this function!
void interpretProgram(istream& inf, ostream& outf);

int main() {
    cout << "Enter BASIC program file name: ";
    string filename;
    getline(cin, filename);
    ifstream infile(filename.c_str());
    if (!infile) {
        cout << "Cannot open " << filename << "!" << endl;
        return 1;
    }
    interpretProgram(infile, cout);
}

void parseProgram(istream& inf, vector<Statement*>& program) {
    program.push_back(NULL);

    string line;
    while (!inf.eof()) {
        getline(inf, line);
        program.push_back(parseLine(line));
    }
}

Statement* parseLine(string line) {
    Statement* statement;
    stringstream ss;
    stringstream temp;  // Temp stringstream for arithmetic of two variables
    string type;
    string type2; // Used for THEN
    string var;
    string var2;
    string op; // Operator for IF statement
    int val;
    int lineToJump;

    ss << line;
    ss >> type;

    temp << line;
    temp >> type;

    if (type == "LET") {
        ss >> var;
        ss >> val;
        // Note:  Because the project spec states that we can assume the file
        //	  contains a syntactically legal program, we know that
        //	  any line that begins with "LET" will be followed by a space
        //	  and then a variable and then an integer value.
        statement = new LetStatement(var, val);
    }

    else if (type == "PRINT") {
        ss >> var;
        statement = new PrintStatement(var);  // Bugged *fixed in makefile*
    }

    else if (type == "PRINTALL") {
        ss >> var;
        statement = new PrintAllStatement();
    }

    else if (type == "END" || type == ".") {
        statement = new EndStatement();
    }

    else if (type == "GOTO") {
        ss >> val;
        statement = new GoToStatement(val);
    }

    else if (type == "GOSUB") {
        ss >> val;
        statement = new GoSubStatement(val);
    }

    else if (type == "RETURN") {
        statement = new ReturnStatement();
    }

    else if (type == "ADD") {
        ss >> var;
        ss >> val;

        if (ss.fail()) {  // If ss fails, it means we are adding two variables
            temp >> var;  // Temporary fix, try to figure out how to clear ss stream
            temp >> var2;
            statement = new AddStatement(var, var2);
        }

        else {
            statement = new AddStatement(var, val);
        }
    }

    else if (type == "SUB") {
        ss >> var;
        ss >> val;

        if (ss.fail()) {  // See ADD type
            temp >> var;
            temp >> var2;
            statement = new SubStatement(var, var2);
        }

        else {
            statement = new SubStatement(var, val);
        }
    }

    else if (type == "MULT") {
        ss >> var;
        ss >> val;

        if (ss.fail()) {
            temp >> var;
            temp >> var2;
            statement = new MultiplyStatement(var, var2);
        }

        else {
            statement = new MultiplyStatement(var, val);
        }
    }

    else if (type == "DIV") {
        ss >> var;
        ss >> val;

        if (ss.fail()) {
            temp >> var;
            temp >> var2;
            statement = new DivStatement(var, var2);
        }

        else {
            statement = new DivStatement(var, val);
        }
    }

    else if (type == "IF") {
        ss >> var;
        ss >> op;
        ss >> val;
        ss >> type2;
        ss >> lineToJump;

        statement = new IfStatement(var, op, val, lineToJump);
    }
    
    return statement;
}

void interpretProgram(istream& inf, ostream& outf) {
    vector<Statement*> program;
    parseProgram(inf, program);

    // Incomplete;  TODO:  Finish this function!
    int size = program.size() - 1;

    ProgramState* state = new ProgramState(size);

    if (size >= 1000) {
        outf << "Error: program too large" << endl;
        return;
    }

    // fix
    else {
        while ((program[state->getLine()]) != NULL) {
            program[state->getLine()]->execute(state, outf);
        }
    }
}
