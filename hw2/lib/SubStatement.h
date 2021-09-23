#ifndef SUB_STATEMENT_INCLUDED
#define SUB_STATEMENT_INCLUDED

#include "ProgramState.h"
#include "Statement.h"

class SubStatement : public Statement {
public:
    SubStatement(std::string variableName, int value);                  // Constructor to sub var and int
    SubStatement(std::string variableName, std::string variableName2);  // Constructor to sub two variables
    virtual void execute(ProgramState* state, std::ostream& outf);

private:
    std::string m_variableName;
    std::string m_variableName2;
    int m_value;
    bool varAndVal;
};

#endif