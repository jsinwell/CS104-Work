#include "minHeap.h"
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <locale>

using namespace std;

/* Notes:
f-value = g+h, where g = # of moves made from start state
h = our heuristic value => DATA -> SALT: h = 3
    1) Always make move with smallest f
    2) Break f value ties by choosing smallest h value (priority = f*(n+1)+h)
    3) If multiple words have smallest f and h-value, choose smaller string

*/

/* struct Node {
    string word;
    int heuristic;
    Node(string s, int h) : word(s), hueristic(h) {}

} */

int HeuristicValue(const string& start, const string& end) { // Calculating our hueristic value
    int h = 0;
    int size = start.size();
    for(int i = 0; i < size; i++) {
        if(start[i] != end[i]) {
            h++;
        }
    }
    return h;
}

// p = f*(n+1)+h, where f = g+h
int pValue(string start, string end, int g) {
    int h = HeuristicValue(start, end);
    int f = g + h;
    int priority = f * (start.size() + 1) + h;
    return priority;

}

// Function to make all words in file uppercase
void ToUpper(string& word) {
    int size = word.size();
    for(int i = 0; i < size; i++) {
        if(islower(word[i])) {
            word[i] = toupper(word[i]);
        }
    }
}

void GraphSearch(set<string> words, string start, string end) {
    MinHeap<string> heap(2); // Instantiate a binary string heap
    // g value and priority for calculations
    int g = 0;
    int priority = pValue(start, end, g); 

    bool exit = false; // Exit condition
    int expansions = 0; // Number of expansions recorded

    map<string, int> distance; // Store our steps
      
    set<string>::iterator it = words.find(start);
    string curr = *it; // Store the iterator's dereferenced string values
    string temp;

    distance[curr] = g; 
    heap.add(curr, priority);
 

 try
 {   
    while(heap.isEmpty() == false) {
        curr = heap.peek(); // Peek the current word and explore
        heap.remove();
        // H = 0 meaning we found answer
        if(HeuristicValue(curr, end) == 0) {
            exit = true;
            cout << distance[curr] << endl << expansions << endl;
            break;
        }
        else {
            for(unsigned int i = 0; i < curr.size(); i++) {
                for (char j = 0; j < 26; j++) {
                 string temp = curr;
                 temp[i] = (char)(j+65);

                if((distance.find(temp) == distance.end() || distance[temp] > distance[curr] + HeuristicValue(curr, temp)) && words.find(temp) != words.end())
                {
                    distance[temp] = distance[curr] + 1;
                    int temph = HeuristicValue(curr, temp);

                    if(temph == 1) {
                        priority = pValue(temp, end, g);
                        heap.add(temp, priority);
                    }
                }
            }
        }
    }
    expansions++;
}

        // If we reach here it means exit condition was not met and there is no transformations possible
        if(exit == false) {
            cout << "No transformation" << endl << expansions << endl;
        }

}


catch(exception& e) { // Catch other extraneous errors
    cout << "No transformations" << endl << expansions << endl << e.what() << endl;
    return;
}

}


int main (int argc, char *argv[]) {
    string start = argv[1]; // Store start string as the first word, end string as second word
    string end = argv[2];
    set<string> words; // Set used to insert words into search algorithm
    string word = "";

    if(start.size() != end.size()) {
        cout << "No transformation" << endl << 0 << endl;
        return 0;
    }

    ToUpper(start); // Make sure start and end are uppercase to avoid errors
    ToUpper(end);

    ifstream file;
    file.open(argv[3]);
    if(file.fail()) {
        cout << "Cannot open file" << endl;
        throw std::exception();
    }

    int numWords = 0;
    file >> numWords;
    for(int i = 0; i < numWords; i++) {
        file >> word;
        if(word.size() != start.size()) // Insert all the words of correct length into our string set
        {
            continue;
        }
        ToUpper(word); // Make sure all our words are uppercase
        words.insert(word);
    }
    

    GraphSearch(words,start,end);

    return 0;

}