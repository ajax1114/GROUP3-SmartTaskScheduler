#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Task structure
struct Task {
    string name;
    string deadline;
    int priority; // 1 = High, 2 = Medium, 3 = Low

    // Overloading < operator for Priority Queue
    // (Higher priority value (1) should be at the top)
    bool operator<(const Task& other) const {
        return priority > other.priority; 
    }
};

