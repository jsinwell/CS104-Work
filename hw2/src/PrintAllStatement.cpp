#include "../lib/PrintAllStatement.h"

using namespace std;

PrintAllStatement::PrintAllStatement() {}

void PrintAllStatement::execute(ProgramState* state, std::ostream& outf) {
    state->printAll(outf);
    state->nextLine();
}