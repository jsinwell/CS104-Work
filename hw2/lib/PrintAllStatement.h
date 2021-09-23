#ifndef PRINT_ALL_STATEMENT_INCLUDED
#define PRINT_ALL_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class PrintAllStatement : public Statement {
public:
    PrintAllStatement();
    virtual void execute(ProgramState* state, std::ostream& outf);
};

#endif