#ifndef IF_STATEMENT_INCLUDED
#define IF_STATEMENT_INCLUDED

#include "ProgramState.h"
#include "Statement.h"

class IfStatement : public Statement {
public:
    IfStatement(std::string var, std::string op, int valueToCompare, int line);
    virtual void execute(ProgramState* state, std::ostream& outf);

private:
    std::string m_var;
    std::string m_operator;
    int m_valueToCompare;
    int m_line;
};

#endif