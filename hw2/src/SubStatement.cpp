#include "SubStatement.h"
using namespace std;

SubStatement::SubStatement(string variableName, int value) {
    m_variableName = variableName;
    m_value = value;
    varAndVal = true;
}

SubStatement::SubStatement(string variableName, string variableName2) {
    m_variableName = variableName;
    m_variableName2 = variableName2;
    varAndVal = false;
}

void SubStatement::execute(ProgramState* state, ostream& outf) {
    if (varAndVal == false) {
        m_value = state->getValue(m_variableName2);
        state->sub(m_variableName, m_value);
        state->nextLine();
    }

    else {
        state->sub(m_variableName, m_value);
        state->nextLine();
    }
}