#include "GoSubStatement.h"
using namespace std;

GoSubStatement::GoSubStatement(int line) { m_line = line; }

void GoSubStatement::execute(ProgramState* state, ostream& outf) {
    if ((m_line < 1) || (m_line > state->getNumLines())) {
        outf << "Illegal jump instruction" << endl;
        std::exit(1);
    }

    else {
        state->goSub(m_line);
    }
}