#ifndef ADD_STATEMENT_INCLUDED
#define ADD_STATEMENT_INCLUDED

#include "ProgramState.h"
#include "Statement.h"

class AddStatement : public Statement {
public:
    AddStatement(std::string variableName, int value); // Constructor to add var and int
    AddStatement(std::string variableName, std::string variableName2); // Constructor to add two variables
    virtual void execute(ProgramState* state, std::ostream& outf);

private:
    std::string m_variableName;
    std::string m_variableName2;
    int m_value;
    bool varAndVal; // Differentiate between two constructors
};

#endif