//
// Created by Kamakshya Nanda on 6/12/25.
//

#ifndef TASK_H
#define TASK_H

#include<iostream>
#include<chrono>
#include<string>
struct Task {
     int id;
     std::string title;
     std::string description;
     int priority;
     std::chrono::system_clock::time_point deadline;
     bool completed;

     std::chrono::system_clock::duration getTimeLeft() const;
     void printTask() const;
     Task(int id, std::string title, std::string description, int priority, std::chrono::system_clock::time_point deadline, bool completed);
};



#endif //TASK_H
