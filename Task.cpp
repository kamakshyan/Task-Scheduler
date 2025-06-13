//
// Created by Kamakshya Nanda on 6/12/25.
//

#include "Task.h"
#include<chrono>
#include <iomanip>

Task::Task(int id, std::string title, std::string description, int priority, std::chrono::system_clock::time_point deadline, bool completed ) : id(id), title(title), description(description), priority(priority), deadline(deadline), completed(completed) {}

std::chrono::system_clock::duration Task::getTimeLeft() const {
    auto now = std::chrono::system_clock::now();
    return deadline - now;
}

std::string formatTimeLeft(std::chrono::system_clock::duration timeLeft) {
    if (timeLeft < std::chrono::seconds(0)) return "Task Overdue!";
    auto hours = std::chrono::duration_cast<std::chrono::hours>(timeLeft).count();
    auto minutes = std::chrono::duration_cast<std::chrono::minutes>(timeLeft).count() % 60;
    return std::format("{}h {}m left",hours,minutes);
}

void Task::printTask() const {
    std::cout << "\nTask ID: " << id << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Description: " << description << std::endl;

    auto timeT = std::chrono::system_clock::to_time_t(deadline);
    std::tm* tm = std::localtime(&timeT);
    std::cout << "Deadline: " << std::put_time(tm, "%Y-%m-%d %H:%M") << std::endl;
    if (completed) {
        std::cout << "+++ Task completed! +++" << std::endl;
    }
    else {
        std::cout << "Time Left: " << formatTimeLeft(getTimeLeft()) << std::endl;
    }
}
