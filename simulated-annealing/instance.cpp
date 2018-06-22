#include "instance.h"

Instance::Instance(
    unsigned number_of_tasks,
    unsigned number_of_workstations,
    std::vector<unsigned> execution_time,
    std::vector<std::pair<unsigned, unsigned>> precedence)
    : number_of_tasks(number_of_tasks)
    , number_of_workstations(number_of_workstations)
    , execution_time(execution_time)
    , precedence(precedence)
{}

unsigned Instance::getTasks() {
    return this->number_of_tasks;
}

unsigned Instance::getStations() {
    return this->number_of_workstations;
}

std::vector<unsigned> Instance::getTime() {
    return this->execution_time;
}

std::vector<std::pair<unsigned, unsigned>> Instance::getPrecedence() {
    return this->precedence;
}
