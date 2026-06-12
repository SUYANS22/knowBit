#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <vector>
#include <string>

struct Task{

    int taskId;
    std::string taskName;
    std::string taskDescription;
    std::string taskCategory;

    int priority;
    bool isCompleted;

    int daysToComplete;

    int dueDay;
    int dueMonth;
    int dueYear;
};

extern std::vector<Task> allTasks;

void addTask();
void displayTasks();
void editTask();
void removeTask();
void markCompleted();

#endif