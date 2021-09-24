#ifndef PRINT_STATEMENT_INCLUDED
#define PRINT_STATEMENT_INCLUDED

#include "ProgramState.h"
#include "Statement.h"

class PrintStatement : public Statement {
private:
    std::string m_variableName;

public:
    PrintStatement(std::string variableName);

    virtual void execute(ProgramState* state, std::ostream& outf);
};

#endif
