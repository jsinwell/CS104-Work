#include "../lib/ReturnStatement.h"
using namespace std;

ReturnStatement::ReturnStatement() {

}

void ReturnStatement::execute(ProgramState* state, ostream& outf) {
    state->returnTo();
}