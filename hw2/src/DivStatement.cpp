#include "../lib/DivStatement.h"
using namespace std;

DivStatement::DivStatement(string variableName, int value) {
    m_variableName = variableName;
    m_value = value;
    varAndVal = true;
}

DivStatement::DivStatement(string variableName, string variableName2) {
    m_variableName = variableName;
    m_variableName2 = variableName2;
    varAndVal = false;
}

void DivStatement::execute(ProgramState* state, ostream& outf) {
    if (varAndVal == false) {
        m_value = state->getValue(m_variableName2);
    }

    // Check if you are dividing by zero
    if (m_value == 0) {
        outf << "Divide by zero exception" << endl;
        return;
    }

    state->div(m_variableName, m_value);
    state->nextLine();
}