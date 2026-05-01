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
}

// Function to delete a task by name
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
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> beb5eaeb2f79a6d71585b433ecf92c2d5e91f23d
>>>>>>> 6e2bd80d4cff6aea2fc69a9e7593b9628ea78134
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
<<<<<<< HEAD
=======
<<<<<<< HEAD

>>>>>>> 6e2bd80d4cff6aea2fc69a9e7593b9628ea78134
// Function to edit a task
void editTask() {
    if (priorityQueueTasks.empty() && normalQueue.empty()) {
        cout << "Nothing to edit.\n";
        return;
    }

    saveState();
    string target;
    cout << "Enter the Task Name you want to edit: ";
    cin.ignore();
    getline(cin, target);

    // To edit, we basically find, delete, and re-add
    // Simplified: we'll search both, update the first match
<<<<<<< HEAD
    bool found = false;
    vector<Task> allTasks;

    // Extract all
    while(!priorityQueueTasks.empty()){
        allTasks.push_back(priorityQueueTasks.top());
        priorityQueueTasks.pop();
    }
    while(!normalQueue.empty()){
        allTasks.push_back(normalQueue.front());
        normalQueue.pop();
    }

    for(auto &t : allTasks) {
        if(t.name == target) {
            cout << "New name: ";
            getline(cin, t.name);
            cout << "New deadline: ";
            getline(cin, t.deadline);
            cout << "New priority (1-3): ";
            cin >> t.priority;
            found = true;
            break;
        }
    }

    // Re-distribute
    for(auto &t : allTasks) {
        if(t.priority == 1) priorityQueueTasks.push(t);
        else normalQueue.push(t);
    }

    if(found) cout << "Task updated!\n";
    else cout << "Task not found.\n";
}

// Undo last action using Stack
void undoLast() {
    if (undoStack.empty()) {
        cout << "Nothing to undo!\n";
        return;
    }

    // Clear current queues
    while(!priorityQueueTasks.empty()) priorityQueueTasks.pop();
    while(!normalQueue.empty()) normalQueue.pop();

    // Restore from stack
    vector<Task> previousState = undoStack.top();
    undoStack.pop();

    for(auto &t : previousState) {
        if(t.priority == 1) priorityQueueTasks.push(t);
        else normalQueue.push(t);
    }

    cout << "Reverted to previous state!\n";
}
=======
    bool found = false;
    vector<Task> allTasks;

    // Extract all
    while(!priorityQueueTasks.empty()){
        allTasks.push_back(priorityQueueTasks.top());
        priorityQueueTasks.pop();
    }
    while(!normalQueue.empty()){
        allTasks.push_back(normalQueue.front());
        normalQueue.pop();
    }

    for(auto &t : allTasks) {
        if(t.name == target) {
            cout << "New name: ";
            getline(cin, t.name);
            cout << "New deadline: ";
            getline(cin, t.deadline);
            cout << "New priority (1-3): ";
            cin >> t.priority;
            found = true;
            break;
        }
    }

    // Re-distribute
    for(auto &t : allTasks) {
        if(t.priority == 1) priorityQueueTasks.push(t);
        else normalQueue.push(t);
    }

    if(found) cout << "Task updated!\n";
    else cout << "Task not found.\n";
}
=======
=======
    bool found = false;
>>>>>>> f2bcdea41b943ae97eae944382ae01eb24024269
>>>>>>> beb5eaeb2f79a6d71585b433ecf92c2d5e91f23d
<<<<<<< HEAD

// Undo last action using Stack
void undoLast() {
    if (undoStack.empty()) {
        cout << "Nothing to undo!\n";
        return;
    }

    // Clear current queues
    while(!priorityQueueTasks.empty()) priorityQueueTasks.pop();
    while(!normalQueue.empty()) normalQueue.pop();

    // Restore from stack
    vector<Task> previousState = undoStack.top();
    undoStack.pop();

    for(auto &t : previousState) {
        if(t.priority == 1) priorityQueueTasks.push(t);
        else normalQueue.push(t);
    }

    cout << "Reverted to previous state!\n";
}

// Function to view tasks
void viewTasks() {
    if (priorityQueueTasks.empty() && normalQueue.empty()) {
        cout << "\n[!] Your task list is currently empty.\n";
        return;
    }

    cout << "\n--- URGENT / HIGH PRIORITY (Priority Queue) ---\n";
    priority_queue<Task> tempPQ = priorityQueueTasks;
    while (!tempPQ.empty()) {
        Task t = tempPQ.top();
        tempPQ.pop();
        cout << "[" << t.priority << "] " << t.name << " | Deadline: " << t.deadline << endl;
    }

    cout << "\n--- NORMAL TASKS (Queue) ---\n";
    queue<Task> tempQ = normalQueue;
    while (!tempQ.empty()) {
        Task t = tempQ.front();
        tempQ.pop();
        cout << "[" << t.priority << "] " << t.name << " | Deadline: " << t.deadline << endl;
    }
}
=======
>>>>>>> 6e2bd80d4cff6aea2fc69a9e7593b9628ea78134
>>>>>>> bac8be5e27356e9dc8d1add4b7908c614ff61d22
