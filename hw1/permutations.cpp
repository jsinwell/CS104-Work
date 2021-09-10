#include <iostream>

// Swap function using temp variable and pass by reference
void permuteSwap(char& a, char& b) {
    char temp;
    temp = a;
    a = b;
    b = temp;
}

void permuteHelper(std::string& in, int l, int r) {

    // Base case, when first and last indices are the same
    if (l == r) {
        std::cout << in << std::endl;
    }

    else {
        // Loop from the first index to last index
        for (int i = l; i <= r; i++) {

            permuteSwap(in[l], in[i]);  // Initial swap

            permuteHelper(in, l + 1, r);  // Recursive call, increment L to eventually reach base case

            permuteSwap(in[l], in[i]);  // Move up tree using backtracking for other permutations
        }
    }
}

void permutations(std::string in) {

    int l = 0;              // First index of string
    int r = in.size() - 1;  // Last index of string

    permuteHelper(in, l, r);
}