#include "../lib/ProgramState.h"

#include <iostream>
using namespace std;

ProgramState::ProgramState(int numLines) {
    m_numLines = numLines;
    line = 1;
}

void ProgramState::nextLine() { line++; }

void ProgramState::setValue(string s, int val) {
    it = programMap.find(s);
    if (it == programMap.end()) {  // Make pair if does not exist
        programMap.insert(make_pair(s, val));
    }

    else {
        programMap[s] = val;
    }
}

void ProgramState::print(string s, ostream& outf) {
    it = programMap.find(s);

    if (it == programMap.end()) {
        setValue(s, 0);  // Default value of var is 0
        outf << programMap[s] << endl;
    }

    else {
        outf << programMap[s] << endl;
    }
}

void ProgramState::printAll(ostream& outf) {
    it = programMap.begin();

    // Use map iterator to print all vars in alphabetical order
    while (it != programMap.end()) {
        string s = it->first;
        int val = it->second;

        outf << s << " " << val << endl;

        it++;
    }
}

void ProgramState::endState() { 
    return;
}

int ProgramState::getLine() { return line; }

int ProgramState::getValue(string s) {
    it = programMap.find(s);
    int val = it->second;
    return val;
}

void ProgramState::add(string s, int val) {
    int sum = getValue(s) + val;
    programMap[s] = sum;
}

void ProgramState::sub(string s, int val) {
    int diff = getValue(s) - val;
    programMap[s] = diff;
}

void ProgramState::multiply(string s, int val) {
    int product = getValue(s) * val;
    programMap[s] = product;
}

void ProgramState::div(string s, int val) {
    int quotient = getValue(s) / val;
    programMap[s] = quotient;
}

int ProgramState::getNumLines() { return m_numLines; }

void ProgramState::goTo(int val) { line = val; }

void ProgramState::goSub(int val) {
    lineStack.push(line);
    goTo(val);
}

void ProgramState::returnTo() {
    if (lineStack.empty()) {
        std::exit(0);  // Exit program successfully if stack empty
    }

    else {
        int prevLine = lineStack.top();
        goTo(prevLine + 1);  // prevLine is most recent GOSUB, but we want to return to next line
        lineStack.pop();
    }
}

void ProgramState::ifState(string var, string op, int val, int line) {
    bool check = false;            // Check if comparison is true: initially set to false
    int varValue = getValue(var);  // Get the value of var being compared

    if ((op == ">") && (varValue > val)) {
        check = true;
        goTo(line);
    }

    else if ((op == "<") && (varValue < val)) {
        check = true;
        goTo(line);
    }

    else if ((op == ">=") && (varValue >= val)) {
        check = true;
        goTo(line);
    }

    else if ((op == "<=") && (varValue <= val)) {
        check = true;
        goTo(line);
    }

    else if ((op == "=") && (varValue == val)) {
        check = true;
        goTo(line);
    }

    else if ((op == "<>") && (varValue != val)) {
        check = true;
        goTo(line);
    }

    else {
        std::exit(1); // Exit program if operator is wrong
    }
}
