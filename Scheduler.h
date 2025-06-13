//
// Created by Kamakshya Nanda on 6/12/25.
//

#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <vector>

#include "Task.h"


class Scheduler {
public:
    void addTask();
    void showTasks() const;
    void markTaskDone();
    void deleteTask();
private:
    std::vector<Task> tasks_;
    int nextId_ = 1;
};



#endif //SCHEDULER_H
