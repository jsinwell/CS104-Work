/*
Each node has d children
Parent of node is at (i-1)/d
Children of nodes are (i*d)+1 to (i*d)+d, so (i*d)+k
*/

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

template<class T>
class MinHeap {
public:
    MinHeap(int d);
    /* Constructor that builds a d-ary Min Heap
       This should work for any d >= 2,
       but doesn't have to do anything for smaller d.*/

    ~MinHeap();

    void add(T item, int priority);
    /* adds the item to the heap, with the given priority. */

    const T& peek() const;
    /* returns the element with smallest priority.
       Break ties however you wish.
       Throws an exception if the heap is empty. */

    void remove();
    /* removes the element with smallest priority.
       Break ties however you wish.
       Throws an exception if the heap is empty. */

    bool isEmpty();
    /* returns true iff there are no elements on the heap. */

    // void update (int location, int priority);

private:
    // whatever you need to naturally store things.
    // You may also add helper functions here.
    std::vector<std::pair<T, int>> nodes;  // Vector to store nodes and priority
    int _d;                                // Max number of children for a parent node
    int size;
    int Parent(int i);
    int kthChild(int i, int k);
    int smallestChild(int pos);
    void bubbleUp(int pos);
    void trickleDown(int pos);
};

template<class T>
MinHeap<T>::MinHeap(int d) {
    _d = d;
    size = 0;
}

template<class T>
MinHeap<T>::~MinHeap() {}

template<class T>
int MinHeap<T>::Parent(int i) {
    return ((i - 1) / _d);
}

template<class T>
int MinHeap<T>::kthChild(int i, int k) {
    return ((i * _d) + k);
}

template<class T>
void MinHeap<T>::add(T item, int priority) {
    // Make a new node, increase size, and bubble up that position
    nodes.push_back(std::make_pair(item, priority));
    size++;
    bubbleUp(size - 1);
}

template<class T>
void MinHeap<T>::bubbleUp(int pos) {
    int parent = Parent(pos);  // Find the parent node to compare

    while (parent >= 0) {  // Loop until we reach the root node
        if (nodes[pos].second < nodes[parent].second) {
            iter_swap(nodes.begin() + pos, nodes.begin() + parent);
            pos = parent;             // Swap values only if child is less than the parent
            parent = (pos - 1) / _d;  // New parent is one layer above curr node
        } else {
            break;
        }
    }
}

template<class T>
const T& MinHeap<T>::peek() const {
    if (size == 0) {  // Throw exception if heap is empty
        throw std::exception();
    }
    return nodes[0].first;  // Return first element of heap
}

template<class T>
void MinHeap<T>::remove() {
    if (isEmpty()) {
        throw std::exception();
    }
    iter_swap(nodes.begin(), nodes.begin() + (size - 1));  // Swap root with node to remove
    nodes.erase(nodes.begin() + (size - 1));               // Erase the root, which is now in the last element of heap
    size--;
    trickleDown(0);  // New root is out of place now, need to trickle down
}

template<class T>
void MinHeap<T>::trickleDown(int pos) {
    while (kthChild(pos, 1) < size) {
        int child = smallestChild(pos);                 // Need to find smallest child node
        if (nodes[child].second < nodes[pos].second) {  // Swap nodes if child is less than parent
            iter_swap(nodes.begin() + pos, nodes.begin() + child);
            pos = child;  // Update our position to be the new child
        } else {
            break;  // Break out of loop if our node is no longer smaller than the children
        }
    }
}

template<class T>
int MinHeap<T>::smallestChild(int pos) {  // Break ties
    int count = 2;                        // Variable to count through the children
    int firstChild = kthChild(pos, 1);
    int nextChild = kthChild(pos, count);

    while ((count <= _d) && (nextChild < size)) {  // Loop until we reach the max # of children
        if (nodes[nextChild].second < nodes[firstChild].second) {
            firstChild = nextChild;
        }
        count++;
        nextChild = kthChild(pos, count);  // Increment count, update to next child node
    }

    return firstChild;  // We return the smallest child of parent node
}

template<class T>
bool MinHeap<T>::isEmpty() {
    if (size == 0) {
        return true;
    }
    return false;
}

/* template <class T>
void MinHeap<T>::update(int location, int priority){
  // Get old priority of node
  int node = nodes[location].second;
  if(node < priority) { // If old priority < new priority, means we need to trickleDOwn
    nodes[location].second = priority;
    trickleDown(location);
  }
  else {
    nodes[location].second = priority;
    bubbleUp(location);
  }

  } */
