#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void encrypt();
void decrypt(long d, long n);
long modulExpo(long b, long n, long m);
long gcd(long a, long b);
long extended(long e, long l);
long decryptionKey(long p, long q);

int main(int argc, char* argv[]) {

    long e = 65537;
    long p = stol(argv[1]);  // p is the first command arg, q is second
    long q = stol(argv[2]);
    long n = p * q;

    // Computing L
    long l = ((p - 1) * (q - 1)) / gcd(p - 1, q - 1);  // Euclidean algorithm to calculate LCM

    if (l <= 65537) {
        cout << "Error: L is <= e" << endl;
        exit(EXIT_FAILURE);
    }

    // Extended Euclidean algorithm
    long s = 0;
    long old_s = 1;
    long t = 1;
    long old_t = 0;
    long r = e;
    long old_r = l;

    while (r != 0) {
        long quotient = old_r / r;
        long temp = r;
        r = old_r - quotient * r;
        old_r = temp;
        temp = s;
        s = old_s - quotient * s;
        old_s = temp;
        temp = t;
        t = old_t - quotient * t;
        old_t = temp;
    }

    // Fixing our d value if it is less than 0
    if (old_t < 0) {
        old_t = old_t + (p - 1) * (q - 1);
    }

    if (old_r != 1) {
        cout << "Error: GCD is not 1" << endl;
        exit(EXIT_FAILURE);
    }

    long d = old_t;  // Our "d" value from the Euclidean algorithm

    string command;

    while (1) {
        cin >> command;

        if (command == "EXIT") {
            break;
        }

        if (command == "ENCRYPT") {
            encrypt();
        }

        if (command == "DECRYPT") {
            decrypt(d, n);
        }
    }

    return 0;
}

void encrypt() {

    string filename;
    long n;
    string message;

    getline(cin >> filename >> n >> std::ws, message);  // std::ws to remove leading whitespace (courtesy of google)
    ofstream file;
    file.open(filename);

    vector<char> data(message.begin(), message.end());  // Char vector to store our original message into indices
    long e = 65537;                                     // Our chosen E value
    int x = 1 + log(n / 27) / log(100);                 // Change of base rule
    int dummy_x = x;
    vector<int> plaintext;  // Vector to convert the message into plaintext, where a = 01, b = 02, etc.
    string temp = "";
    string temp2 = "";
    string whitespace = " ";  // Non-elegant way to add spaces between each chunk
    int iterator = 0;

    if (n < 27) {
        cout << "Error: x less than 27" << endl;
        exit(EXIT_FAILURE);
    }

    while (1) {

        for (int i = iterator; i < x; i++) {
            if (data[i] == ' ') {  // If our character is a space, it should be 00
                plaintext.push_back(data[i] - 32);
            }

            else {
                plaintext.push_back(
                        data[i] - 96);  // Since 'a' has decimal value 97, we want to subtract 96 to make it 01
            }

            temp = to_string(plaintext[i]);
            if (stoi(temp) >= 0 && stoi(temp) <= 9) {  // Add the leading 0 if required
                temp = '0' + temp;
            }
            temp2 = temp2 + temp;
        }
        long M = stol(temp2);         // convert string to long
        long C = modulExpo(M, e, n);  // Calculate C value which is encrypted message

        if (x > data.size() - 1) {
            file << C;  // Removes trailing whitespace at end of text file
            break;
        }
        file << C << whitespace;  // Output C followed by a whitespace

        temp.clear();  // Resetting all the values
        temp2.clear();

        iterator = iterator + dummy_x;  // Start for loop after last visited index
        x = x + dummy_x;                // Dummy_x preserves initial x value
    }
}

void decrypt(long d, long n) {
    int x = 1 + log(n / 27) / log(100);
    int dummy_x = x;
    string input;
    string output;
    int iterator = 0;
    string whitespace = " ";
    long C;
    vector<int> messageData;  // Vector to store our original long C
    vector<int> outputData;   // Vector used in writing to output file

    cin >> input >> output;
    ifstream ifile;
    ofstream ofile;
    ifile.open(input);
    ofile.open(output);

    while (ifile >> C) {  // Read each long integer
        // Convert back to original M value
        long M = modulExpo(C, d, n);

        for (int i = 0; i < x; i++) {
            messageData.push_back(M % 100);  // Get each set of 2 digits
            M /= 100;
        }

        // messageData is currently backwards
        reverse(messageData.begin(), messageData.end());

        for (int i = iterator; i < x; i++) {
            outputData.push_back(messageData[i]);  // outputData stores the individual integers

            if (outputData[i] == 0) {
                ofile << static_cast<char>(outputData[i] + 32);  // Deal with space characters
            } else {
                ofile << static_cast<char>(outputData[i] + 96);  // Cast to a char and add 96 to produce ASCII character
            }
        }

        iterator = iterator + dummy_x;
        x = x + dummy_x;
    }
}

// Modular Exponentiation
long modulExpo(long b, long n, long m) {

    // make n into vector of binary bits
    vector<int> binary;
    for (int i = 0; n > 0; i++) {
        binary.push_back(n % 2);
        n = n / 2;
    }
    // Reverse binary bits in case our E value is not symmetric

    // Modular exponentiation function from lecture
    long x = 1;
    long power = b % m;
    for (int i = 0; i <= binary.size() - 1; i++) {
        if (binary[i] == 1) {
            x = (x * power) % m;
        }
        power = (power * power) % m;
    }

    return x;
}

// Basic Euclidean algorithm
long gcd(long a, long b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}
