#include <iostream>
#include "solution.h"

Solution::Solution(Instance instance)
    : tasks(instance.getTasks())
    , time(instance.getStations())
{
    unsigned n = instance.getTasks();
    unsigned m = instance.getStations();

    do {
        std::fill(time.begin(), time.end(), 0);

        for (int i = 0; i < n; i++) {
            unsigned station = 0;

            tasks[i] = station;
            time[station] += instance.getTime()[i];
        }

        cycleTime = *std::max_element(time.begin(), time.end());
    } while (!isValid(instance));
}

Solution::Solution(Instance instance, Solution solution) {
    do {
        tasks = solution.getTasks();
        time = solution.getTime();

        unsigned task = std::rand() % instance.getTasks();
        unsigned station = std::rand() % instance.getStations();

        std::vector<unsigned> times = instance.getTime();

        time[tasks[task]] -= times[task];
        tasks[task] = station;
        time[station] += times[task];

        cycleTime = *std::max_element(time.begin(), time.end());
    } while (!isValid(instance));
}

bool Solution::isValid(Instance instance) {
    std::vector<std::pair<unsigned, unsigned>> A = instance.getPrecedence();

    for (auto pair : A) {
        unsigned u = pair.first;
        unsigned v = pair.second;

        if (tasks[u] > tasks[v]) {
            return false;
        }
    }

    return true;
}

std::vector<unsigned> Solution::getTasks() {
    return this->tasks;
}

std::vector<unsigned> Solution::getTime() {
    return this->time;
}

unsigned Solution::getCycleTime() {
    return this->cycleTime;
}
