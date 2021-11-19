#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <ostream>
#include <fstream>
#include <cmath>
#include <vector>

template<class T>
class Hashtable {
    public:
    Hashtable(bool debug = false, unsigned int size = 11);
    ~Hashtable();
    int add(std::string k, const T& val);
    const T& lookup(std::string k);
    void reportAll(std::ostream &) const;
    private:
    int hash(std::string k) const;
    void resize();
    double loadFactor; 
    bool debugger;
    unsigned int m;
    int numKeys;
    int r1, r2, r3, r4, r5; 
    int t1, t2, t3, t4, t5; // Debug integers
    int resizeArray[17]; // Array to store our prime # resize
    int resizeIndex;
    std::pair<std::string, T> *lookUpTable;
    int probeRate = 0;

};

template<class T>
Hashtable<T>::Hashtable(bool debug, unsigned int size) {
    debugger = debug;
    m = size;
    loadFactor = 0;
    numKeys = 0;
    resizeIndex = 0;

    lookUpTable = new std::pair<std::string, T>[11];
    resizeArray[0] = 11, resizeArray[1] = 23, resizeArray[2] = 47, resizeArray[3] = 97, resizeArray[4] = 197, resizeArray[5] = 397, resizeArray[6] = 797, resizeArray[7] = 1597, resizeArray[8] = 3203, resizeArray[9] = 6421, resizeArray[10] = 12853, resizeArray[11] = 25717, resizeArray[12] = 51437, resizeArray[13] = 102877, resizeArray[14] = 205759, resizeArray[15] = 411527, resizeArray[16] = 823117;

        srand(time(NULL)); // Seed random number generator

        r1 = rand() % (m-1); // Generate random numbers
        r2 = rand() % (m-1);
        r3 = rand() % (m-1);
        r4 = rand() % (m-1);
        r5 = rand() % (m-1);
   

        t1 = 983132572; // Our debug mode numbers
        t2 = 1468777056;
        t3 = 552714139;
        t4 = 984953261;
        t5 = 261934300;        

}

template<class T>
Hashtable<T>::~Hashtable() {
    delete[] lookUpTable;
}

template<class T>
int Hashtable<T>::add(std::string k, const T& val) {

    int hashVal = hash(k);

    for(unsigned int i = 1; i <= m; i++) {
        loadFactor = (double)numKeys/(double)m;

        if(loadFactor > 0.5) {
            resize(); // Quadratic probing won't work if load factor > 0.5
        }

        
        if(lookUpTable[i].first == k) { // If key already in table, do nothing
            return 0;
        }
      
        // Empty index we can place our pair into
        if(lookUpTable[hashVal].first == "" && lookUpTable[hashVal].second == 0) {
            lookUpTable[hashVal] = std::make_pair(k, val);
            numKeys++;
            break; // Break out of loop once we can insert a pair
        }

        // Continue quadratic probing until we find a spot
        hashVal = (hashVal + (int)pow(i, 2)) % m;
        probeRate++;
        std::cout << probeRate << std::endl;
    }

    return -1;

}

template<class T>
const T& Hashtable<T>::lookup(std::string k) {
    for(unsigned int i = 0; i <= m; i++) {
        if(lookUpTable[i].first == k) { // If we find string in hash table, return it's second value
            return lookUpTable[i].second;
        }
    }
}

template<class T>
void Hashtable<T>::reportAll(std::ostream &) const {
    std::ofstream ofile;
    ofile.open("output.txt"); 

    for(int i = 0; i < m; i++) { // Write all indices to output file
        ofile << lookUpTable[i].first << " " << lookUpTable[i].second << std::endl;
    }

    ofile.close();
}

template<class T>
int Hashtable<T>::hash(std::string k) const {
    // Maximum of 5 integers 

    std::vector<long long int> vec;
    int total = 0;
    int exponent = 0;
    int size = k.size() - 1;
    long long hashVal;
    
    if(k.size() == 6) { // 3 scenarios: string is exactly 6 letters, below 6, or above 6 letters
        for(int i = size; i >= 0; i--) {
            total += pow(27, exponent) * (k[i] - 96);
            exponent++;
        }

        vec.push_back(total);
        for(int i = 1; i < 5; i++) {
            vec.push_back(0);
        } 
    }
    
    else if(k.size() < 6) {
        for(int i = size; i >= 0; i--) {
            total += pow(27, exponent) * (k[i] - 96);
            exponent++;
        }

        vec.push_back(total);
        for(int i = 1; i < 5; i++) {
            vec.push_back(0);
        } 
    }

    else if(k.size() > 6) {
        while(size >= 0) {
        for(int i = size; i > size - 6 && i >= 0; i--) {
            total += pow(27, exponent) * (k[i] - 96);
            exponent++;
        }

            vec.push_back(total);
            exponent = 0;
            total = 0;
            size -= 6;
        }

        for(int i = 1; i < 5; i++) { // Ensures no buggy vector values
            vec.push_back(0);
        }
 
    }

    if(debugger == false) { // Running non-debug mode
        hashVal = ((vec[0]*r5) + (vec[1]*r4) + (vec[2]*r3) + (vec[3]*r2) +(vec[4]*r1)) % m;
    }

    else if(debugger == true) { // Running debug mode
        hashVal = ((vec[0]*t5) + (vec[1]*t4) + (vec[2]*t3) + (vec[3]*t2) +(vec[4]*t1)) % m;
    }

    return hashVal;

}

template<class T>
void Hashtable<T>::resize() {

    // Randomize our r values again
    r1 = rand() % (m-1);
    r2 = rand() % (m-1);
    r3 = rand() % (m-1);
    r4 = rand() % (m-1);
    r5 = rand() % (m-1);

    resizeIndex++;
    m = resizeArray[resizeIndex];
    std::pair<std::string, T>* temp = new std::pair<std::string, T>[m];

    for(int i = 0; i < resizeArray[resizeIndex]; i++) {
        temp[i] = std::make_pair("", 0); // Make new empty pairs in our temp table
    }

    for(int i = 0; i < resizeArray[resizeIndex-1]; i++) {
        if(lookUpTable[i].first != "" && lookUpTable[i].second != 0) {
            int hashVal = hash(lookUpTable[i].first); // Rehash our values
            for(int j = 1; j <= m; j++) { // Re-insert our old values into the temp table
                if(temp[i].first == "" && temp[i].second == 0) {
                    temp[hashVal] = std::make_pair(lookUpTable[i].first, lookUpTable[i].second);
                    break; 
                }

                hashVal = (hashVal + (int)pow(i, 2)) % m; // Quadratic probing
            }
        }
    }

    delete[] lookUpTable;
    lookUpTable = temp;

}
