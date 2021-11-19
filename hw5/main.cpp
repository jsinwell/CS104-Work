#include "Hashtable.h"
#include <random>

using namespace std;

int main () {

    Hashtable<int> hashtable(true, 20);
	
    hashtable.add("word", 5);
    hashtable.add("bird", 5);
    hashtable.add("hello", 5);
    hashtable.add("trojan", 5);
    hashtable.add("jon", 5);
    hashtable.add("brendan", 5);
    hashtable.add("usc", 5);
    hashtable.add("dog", 5);
    hashtable.add("cat", 5);
    hashtable.add("monkey", 5);
     hashtable.add("abc", 5);
    hashtable.add("ge", 5);
    hashtable.add("b", 5);
    hashtable.add("m", 5);
     hashtable.add("g", 5);
    hashtable.add("f", 5);
 
    
    
    


    return 0;
}