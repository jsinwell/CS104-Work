#include "../lib/MultiplyStatement.h"
using namespace std;

MultiplyStatement::MultiplyStatement(string variableName, int value) {
    m_variableName = variableName;
    m_value = value;
    varAndVal = true;
}

MultiplyStatement::MultiplyStatement(string variableName, string variableName2) {
    m_variableName = variableName;
    m_variableName2 = variableName2;
    varAndVal = false;
}

void MultiplyStatement::execute(ProgramState* state, ostream& outf) {

    if (varAndVal == false) {
        m_value = state->getValue(m_variableName2);
        state->multiply(m_variableName, m_value);
        state->nextLine();
    }

    else {
        state->multiply(m_variableName, m_value);
        state->nextLine();
    }
}