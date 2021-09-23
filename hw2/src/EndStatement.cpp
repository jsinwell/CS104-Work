#include "../lib/EndStatement.h"

using namespace std;

EndStatement::EndStatement() {

}

void EndStatement::execute(ProgramState* state, std::ostream& outf) {
    state->endState();
}
