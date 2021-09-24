#ifndef GOSUB_STATEMENT_INCLUDED
#define GOSUB_STATEMENT_INCLUDED

#include "ProgramState.h"
#include "Statement.h"

class GoSubStatement : public Statement {
public:
    GoSubStatement(int line);
    virtual void execute(ProgramState* state, std::ostream& outf);

private:
    int m_line;
};

#endif