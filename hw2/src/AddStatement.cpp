#include "../lib/AddStatement.h"
using namespace std;

AddStatement::AddStatement(string variableName, int value) {
    m_variableName = variableName;
    m_value = value;
    varAndVal = true;
}

AddStatement::AddStatement(string variableName, string variableName2) {
    m_variableName = variableName;
    m_variableName2 = variableName2;
    varAndVal = false;
}

void AddStatement::execute(ProgramState* state, ostream& outf) {

    if (varAndVal == false) {
        m_value = state->getValue(m_variableName2);
        state->add(m_variableName, m_value);
        state->nextLine();
    }

    else {
        state->add(m_variableName, m_value);
        state->nextLine();
    }
}