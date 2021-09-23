#ifndef GOTO_STATEMENT_INCLUDED
#define GOTO_STATEMENT_INCLUDED

#include "ProgramState.h"
#include "Statement.h"

class GoToStatement : public Statement {
public:
    GoToStatement(int line);
    virtual void execute(ProgramState* state, std::ostream& outf);

private:
    int m_line;
};

#endif