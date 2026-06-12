#include "task.h"
#include <ctime>

using namespace std;

vector<Task> allTasks;

void addTask(){

    Task t;

    cout << "\n========== ADD TASK ==========\n";

    cout << "Enter Task ID: ";
    cin >> t.taskId;
    cin.ignore();

    cout << "Enter Task Name: ";
    getline(cin, t.taskName);

    cout << "Enter Description: ";
    getline(cin, t.taskDescription);

    cout << "Enter Category: ";
    getline(cin, t.taskCategory);

    cout << "Enter Priority (1-5): ";
    cin >> t.priority;

    cout << "Enter Number of Days To Complete: ";
    cin >> t.daysToComplete;

    time_t now = time(0);
    now += t.daysToComplete * 24 * 60 * 60;

    tm *deadline = localtime(&now);

    t.dueDay = deadline->tm_mday;
    t.dueMonth = deadline->tm_mon + 1;
    t.dueYear = deadline->tm_year + 1900;

    t.isCompleted = false;

    allTasks.push_back(t);

    cout << "\nTask Added Successfully!\n";
}

void displayTasks(){

    if(allTasks.empty()){

        cout << "\nNo Tasks Available!\n";
        return;
    }

    for(const auto &t : allTasks){

        cout << "\n================================";
        cout << "\nID: " << t.taskId;
        cout << "\nName: " << t.taskName;
        cout << "\nDescription: " << t.taskDescription;
        cout << "\nCategory: " << t.taskCategory;
        cout << "\nPriority: " << t.priority;
        cout << "\nDays To Complete: "
             << t.daysToComplete;

        cout << "\nDeadline: "
             << t.dueDay << "/"
             << t.dueMonth << "/"
             << t.dueYear;

        cout << "\nStatus: "
             << (t.isCompleted ? "Completed"
                               : "Pending");
        cout << "\n================================\n";
    }
}

void editTask(){

    int id;

    cout << "\nEnter Task ID: ";
    cin >> id;
    cin.ignore();

    for(auto &t : allTasks){

        if(t.taskId == id){

            int choice;

            cout << "\n1. Name";
            cout << "\n2. Description";
            cout << "\n3. Category";
            cout << "\n4. Priority";
            cout << "\n5. Days To Complete";

            cout << "\nChoice: ";
            cin >> choice;
            cin.ignore();

            switch(choice){

                case 1:
                    getline(cin, t.taskName);
                    break;

                case 2:
                    getline(cin, t.taskDescription);
                    break;

                case 3:
                    getline(cin, t.taskCategory);
                    break;

                case 4:
                    cin >> t.priority;
                    break;

                case 5:
                {
                    cin >> t.daysToComplete;

                    time_t now = time(0);
                    now += t.daysToComplete * 24 * 60 * 60;

                    tm *deadline = localtime(&now);

                    t.dueDay = deadline->tm_mday;
                    t.dueMonth = deadline->tm_mon + 1;
                    t.dueYear = deadline->tm_year + 1900;

                    break;
                }

                default:
                    cout << "\nInvalid Choice\n";
            }

            return;
        }
    }

    cout << "\nTask Not Found!\n";
}

void removeTask(){

    int id;

    cout << "\nEnter Task ID: ";
    cin >> id;

    for(size_t i=0;i<allTasks.size();i++){

        if(allTasks[i].taskId == id){

            allTasks.erase(allTasks.begin()+i);

            cout << "\nTask Removed!\n";
            return;
        }
    }

    cout << "\nTask Not Found!\n";
}

void markCompleted(){

    int id;

    cout << "\nEnter Task ID: ";
    cin >> id;

    for(auto &t : allTasks){

        if(t.taskId == id){

            t.isCompleted = true;

            cout << "\nTask Completed!\n";
            return;
        }
    }

    cout << "\nTask Not Found!\n";
}