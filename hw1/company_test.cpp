#include "company.hpp"
#include <iostream>

int main(int argc, char* argv[]) {

    CompanyTracker testCase(5);

    // Testing double merge then split
    testCase.merge(0, 1);
    testCase.merge(0, 2);
    testCase.split(0);
    testCase.inSameCompany(0, 1);
    testCase.inSameCompany(0, 2);

    // Testing a merge of students 0 and 1, if same company, splitting both students and checking again
    testCase.merge(0, 1);
    testCase.inSameCompany(0, 1);
    testCase.split(0);
    testCase.split(1);
    testCase.inSameCompany(0, 1);

    testCase.split(9);   // Should return nothing since out of range
    testCase.split(-1);  // Should return nothing since negative
    testCase.split(2);   // Should do nothing since 1-person company

    testCase.inSameCompany(3, 3);   // Should return true since same people
    testCase.inSameCompany(8, 1);   // Should return false since out of range
    testCase.inSameCompany(-1, 1);  // Should return false since out of range

    testCase.merge(2, 3);   // Test merge function with two one-person companies
    testCase.merge(1, 1);   // Test merge function if i and j are same
    testCase.merge(6, 2);   // Test merge function if i or j out of range
    testCase.merge(-1, 5);  // Should just return since negative

    return 0;
}