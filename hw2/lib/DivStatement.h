#ifndef DIV_STATEMENT_INCLUDED
#define DIV_STATEMENT_INCLUDED

#include "ProgramState.h"
#include "Statement.h"

class DivStatement : public Statement {
public:
    DivStatement(std::string variableName, int value);
    DivStatement(std::string variableName, std::string variableName2);
    virtual void execute(ProgramState* state, std::ostream& outf);

private:
    std::string m_variableName;
    std::string m_variableName2;
    int m_value;
    bool varAndVal;
};

#endif