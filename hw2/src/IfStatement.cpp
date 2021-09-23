#include "../lib/IfStatement.h"
using namespace std;

IfStatement::IfStatement(string var, string op, int valueToCompare, int line) {
    m_var = var;
    m_operator = op;
    m_valueToCompare = valueToCompare;
    m_line = line;
}

void IfStatement::execute(ProgramState* state, ostream& outf) {
    if ((m_line < 1) || (m_line > state->getNumLines())) {
        outf << "Illegal jump instruction" << endl;  // Line out of range
        std::exit(1);                                // Terminate program
    }

    else {
        state->ifState(m_var, m_operator, m_valueToCompare, m_line);
    }
}