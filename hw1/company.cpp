#include "company.hpp"

#include <iostream>

// Initializes the tracker with n students and their 1-person companies.
CompanyTracker::CompanyTracker(int n) {
    numCompanies = n;
    companies = new Company*[numCompanies];
    for (int i = 0; i < numCompanies; ++i)
        companies[i] = new Company();
}

// Deallocates all dynamically allocated memory.
CompanyTracker::~CompanyTracker() {
    for (int i = 0; i < numCompanies; ++i) {
        delete companies[i];
        companies[i] = nullptr;
    }
    delete[] companies;
}

void CompanyTracker::merge(int i, int j) {

    if (i >= numCompanies || j >= numCompanies || i < 0 || j < 0) {  // Arguments out of range
        return;
    }

    else if (companies[i] == companies[j]) {  // Both people in same company
        return;
    }

    else if (i == j) {  // i and j are the same person
        return;
    }

    // Merge when i and j are both part of 1-person companies, meaning parent points to null
    else if ((companies[i]->parent == nullptr) && (companies[j]->parent == nullptr)) {

        // Merge into dynamically allocated object company C, which becomes parents of A and B
        Company* companyC1 = new Company;

        companyC1->merge1 = companies[i];
        companyC1->merge2 = companies[j];

        companies[i]->parent = companyC1;  // Parents of i and j point to company C
        companies[j]->parent = companyC1;
        companyC1->parent = nullptr;  // Company C's parent then becomes null since it is largest

        delete companyC1;
    }

    else {
        largestCompany(i);  // Find largest company of both i and j
        largestCompany(j);
        // Essentially same as merging two 1-person companies
        Company* companyC2 = new Company;

        companyC2->merge1 = companies[i];
        companyC2->merge2 = companies[j];

        companies[i]->parent = companyC2;
        companies[j]->parent = companyC2;
        companyC2->parent = nullptr;

        delete companyC2;
    }
}

void CompanyTracker::split(int i) {

    if (i >= numCompanies || i < 0) {
        return;
    }

    // Don't split if there is no parent company
    else if (companies[i]->parent == nullptr) {
        return;
    }

    else {
        largestCompany(i);  // Find largest company, then set i's parent to null since splitting
        companies[i]->parent = nullptr;
    }
}

bool CompanyTracker::inSameCompany(int i, int j) {

    if (i >= numCompanies || j >= numCompanies || i < 0 || j < 0) {  // Arguments out of range
        return false;
    }

    else if (i == j) {  // i and j are same people
        return true;
    }

    else {
        Company* largestI = largestCompany(i);
        Company* largestJ = largestCompany(j);
        return largestI == largestJ;
    }
}

Company* CompanyTracker::largestCompany(int i) {

    // Go through each level of parent company until you reach a company without one
    Company* next = companies[i];

    while (next->parent != nullptr) {
        next = next->parent;
    }
    return next;  // Return the largest company
}