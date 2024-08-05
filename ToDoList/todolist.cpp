#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Task structure
struct Task {
    string description;
    bool isCompleted;
};

// To-do list class
class ToDoList {
private:
    vector<Task> tasks;

public:
    // Add a task to the list
    void addTask(string description) {
        Task newTask;
        newTask.description = description;
        newTask.isCompleted = false;
        tasks.push_back(newTask);
    }

    // View all tasks in the list
    void viewTasks() {
        cout << "To-Do List:" << endl;
        for (int i = 0; i < tasks.size(); i++) {
            cout << (i + 1) << ". " << tasks[i].description;
            if (tasks[i].isCompleted) {
                cout << " (Completed)";
            } else {
                cout << " (Pending)";
            }
            cout << endl;
        }
    }

    // Mark a task as completed
    void markTaskAsCompleted(int taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].isCompleted = true;
            cout << "Task marked as completed." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    // Remove a task from the list
    void removeTask(int taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + (taskNumber - 1));
            cout << "Task removed." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }
};

int main() {
    ToDoList toDoList;

    while (true) {
        cout << "To-Do List Manager" << endl;
        cout << "-----------------" << endl;
        cout << "\n";
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "\n";
        cout << "\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\n";
                cout << "\n";
                cout << "Enter task description: ";
                string description;
                cin.ignore();
                getline(cin, description);
                toDoList.addTask(description);
                break;
            }
            case 2: {
                toDoList.viewTasks();
                break;
            }
            case 3: {
                cout << "\n";
                cout << "\n";
                cout << "Enter task number to mark as completed: ";
                int taskNumber;
                cin >> taskNumber;
                toDoList.markTaskAsCompleted(taskNumber);
                break;
            }
            case 4: {
                cout << "\n";
                cout << "\n";
                cout << "Enter task number to remove: ";
                int taskNumber;
                cin >> taskNumber;
                toDoList.removeTask(taskNumber);
                break;
            }
            case 5: {
                cout << "\n";
                cout << "\n";
                cout << "Exiting..." << endl;
                return 0;
            }
            default: {
                cout << "\n";
                cout << "\n";
                cout << "Invalid choice. Please try again." << endl;
            }
        }

        cout << endl;
    }

    return 0;
}