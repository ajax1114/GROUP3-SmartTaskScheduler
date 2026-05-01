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

// Global Data Structures
priority_queue<Task> priorityQueueTasks; // For High Priority
queue<Task> normalQueue;                // For Medium/Low Priority
stack<vector<Task>> undoStack;          // Stores system snapshots for Undo

// --- Helper Functions ---

// Captures the current state of both queues for the Undo stack
void saveState() {
    vector<Task> state;
    
    // Save Priority Queue
    priority_queue<Task> tempPQ = priorityQueueTasks;
    while(!tempPQ.empty()) {
        state.push_back(tempPQ.top());
        tempPQ.pop();
    }
    
    // Save Normal Queue (using a special marker or size could work, 
    // but we'll store all as a list and redistribute on undo)
    queue<Task> tempQ = normalQueue;
    while(!tempQ.empty()) {
        state.push_back(tempQ.front());
        tempQ.pop();
    }
    undoStack.push(state);
}

// Function to add task
void addTask() {
    saveState(); // Save state before modifying
    Task t;

    cout << "\n--- Add New Task ---\n";
    cout << "Enter Task Name: ";
    cin.ignore();
    getline(cin, t.name);

    cout << "Enter Deadline (YYYY-MM-DD): ";
    getline(cin, t.deadline);

    cout << "Enter Priority (1=High, 2=Medium, 3=Low): ";
    cin >> t.priority;

    if (t.priority == 1) {
        priorityQueueTasks.push(t);
    } else {
        normalQueue.push(t);
    }

    cout << "Task Added Successfully!\n";
<<<<<<< HEAD
}

// Function to delete a task by name
=======

    // Function to delete a task by name
>>>>>>> f2bcdea41b943ae97eae944382ae01eb24024269
void deleteTask() {
    if (priorityQueueTasks.empty() && normalQueue.empty()) {
        cout << "Nothing to delete.\n";
        return;
    }

    saveState();
    string target;
    cout << "Enter the exact Task Name to delete: ";
    cin.ignore();
    getline(cin, target);

<<<<<<< HEAD
    bool found = false;

    // Search and remove from Priority Queue
    priority_queue<Task> tempPQ;
    while (!priorityQueueTasks.empty()) {
        Task t = priorityQueueTasks.top();
        priorityQueueTasks.pop();
        if (t.name == target) found = true;
        else tempPQ.push(t);
    }
    priorityQueueTasks = tempPQ;

    // Search and remove from Normal Queue
    queue<Task> tempQ;
    while (!normalQueue.empty()) {
        Task t = normalQueue.front();
        normalQueue.pop();
        if (t.name == target) found = true;
        else tempQ.push(t);
    }
    normalQueue = tempQ;

    if (found) cout << "Task '" << target << "' deleted.\n";
    else cout << "Task not found.\n";
}
=======
    bool found = false;
>>>>>>> f2bcdea41b943ae97eae944382ae01eb24024269
