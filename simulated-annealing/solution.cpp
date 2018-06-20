#include <iostream>
#include "solution.h"

Solution::Solution(Instance instance)
    : tasks(instance.getTasks())
    , time(instance.getStations())
{
    unsigned n = instance.getTasks();
    unsigned m = instance.getStations();

    std::fill(time.begin(), time.end(), 0);

    for (int i = 0; i < n; i++) {
        unsigned station = std::rand() % m;

        tasks[i] = station;
        time[station] += instance.getTime()[i];
    }

    cycleTime = *std::max_element(time.begin(), time.end());
}

bool Solution::isValid(Instance instance) {
    std::vector<std::pair<unsigned, unsigned>> A = instance.getPrecedence();

    for (auto pair : A) {
        unsigned u = pair.first;
        unsigned v = pair.second;

        if (tasks[u] > tasks[v]) {
            std::cout << tasks[u] << ", " << tasks[v] << "\n";
            return false;
        }
    }

    return true;
}

std::vector<unsigned> Solution::getTasks() {
    return this->tasks;
}

unsigned Solution::getCycleTime() {
    return this->cycleTime;
}
