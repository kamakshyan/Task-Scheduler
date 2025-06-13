//
// Created by Kamakshya Nanda on 6/12/25.
//

#include "Scheduler.h"
#include "Task.h"

Task createTask(int id);

void Scheduler::addTask() {
    Task task = createTask(nextId_++);
    tasks_.push_back(task);
    puts("Task added.");
}

void Scheduler::showTasks() const {
    for (const Task& task : tasks_) {
        task.printTask();
    }
}

void Scheduler::markTaskDone() {
    std::cout << "Enter task ID: ";
    int id;
    std::cin >> id;
    for (Task& task : tasks_) {
        if (task.id == id) {
            task.completed = true;
            std::cout << "Task {" << id << "} marked completed." << std::endl;
            return;
        }
    }
    puts(std::format("Task with ID {} not found!",id).c_str());
}

void Scheduler::deleteTask() {
    std::cout << "Enter task ID: ";
    int id;
    std::cin >> id;
    for (auto it = tasks_.begin(); it != tasks_.end(); it++) {
        if (it->id == id) {
            tasks_.erase(it);
            std::cout << "Task {" << id << "} deleted." << std::endl;
            return;
        }
    }
    puts(std::format("Task with ID {} not found!",id).c_str());
}


