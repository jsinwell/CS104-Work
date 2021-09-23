#include "../lib/GoToStatement.h"
using namespace std;

GoToStatement::GoToStatement(int line) { m_line = line; }

void GoToStatement::execute(ProgramState* state, ostream& outf) {
    if ((m_line < 1) || (m_line > state->getNumLines())) {  // If line number is out of range
        outf << "Illegal jump instruction" << endl;
        std::exit(1);  // Program terminated abnormally
    }

    else {
        state->goTo(m_line);
    }
}