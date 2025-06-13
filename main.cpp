#include <iomanip>
#include<iostream>

#include "Scheduler.h"
#include "Task.h"

Task createTask(int id) {
    std::string title;
    std::string description;
    std::cout << "Enter title: ";
    std::getline(std::cin >> std::ws, title);
    std::cout << "Enter description: ";
    std::getline(std::cin >> std::ws, description);
    int priority;
    std::cout << "Enter priority (1 = high, 5 = low): ";
    std::cin >> priority;
    std::string deadlineInput;
    std::cout << "Enter deadline (YYYY-MM-DD HH:MM): ";
    std::getline(std::cin >> std::ws, deadlineInput);

    std::tm tm = {};
    std::istringstream ss(deadlineInput);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M");

    if (ss.fail()) {
        std::cerr << "Invalid date/time format";
    }

    std::time_t tt = std::mktime(&tm);
    auto deadline = std::chrono::system_clock::from_time_t(tt);

    return Task{id, title, description, priority, deadline, false};

}
int main() {
    puts("-- Task Scheduler -- ");
    Scheduler scheduler;
    int choice;

    while (true) {
        std::cout << "\n1. Add Task\n2. Show Tasks\n3. Mark Task Done\n4. Delete Task\n5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                scheduler.addTask(); break;
            case 2:
                scheduler.showTasks(); break;
            case 3:
                scheduler.markTaskDone(); break;
            case 4:
                scheduler.deleteTask(); break;
            case 5:
                exit(0);
            default:
                std::cout << "Invalid choice\n";
        }
    }
}