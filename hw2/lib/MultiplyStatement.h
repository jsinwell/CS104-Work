#ifndef MULTIPLY_STATEMENT_INCLUDED
#define MULTIPLY_STATEMENT_INCLUDED

#include "ProgramState.h"
#include "Statement.h"

class MultiplyStatement : public Statement {
public:
    MultiplyStatement(std::string variableName, int value);
    MultiplyStatement(std::string variableName, std::string variableName2);
    virtual void execute(ProgramState* state, std::ostream& outf);

private:
    std::string m_variableName;
    std::string m_variableName2;
    int m_value;
    bool varAndVal;
};

#endif