// PrintStatement.cpp:
#include "../lib/PrintStatement.h"

using namespace std;

PrintStatement::PrintStatement(string variableName) : m_variableName(variableName) {}

void PrintStatement::execute(ProgramState* state, ostream& outf) {
    state->print(m_variableName, outf);
    state->nextLine();
}
