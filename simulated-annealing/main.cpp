#include <chrono>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "solution.h"

Instance parseInstance(std::string instancePath, unsigned number_of_workstations) {
    /* number of tasks */
    unsigned number_of_tasks;

    std::string line;
    std::ifstream instanceFile(instancePath);

    /* parse number of tasks */
    std::getline(instanceFile, line);
    std::istringstream ss(line);
    ss >> number_of_tasks;

    /* execution time of each task */
    std::vector<unsigned> execution_time(number_of_tasks);

    for (int i = 0; i < number_of_tasks; i++) {
        unsigned time;

        std::getline(instanceFile, line);
        std::istringstream ss(line);
        ss >> time;

        execution_time[i] = time;
    }

    /* precedence graph */
    std::vector<std::pair<unsigned, unsigned>> precedence;

    while (std::getline(instanceFile, line)) {
        int u;
        int v;
        char comma;

        std::istringstream ss(line);
        ss >> u >> comma >> v;

        if (u == -1) {
            break;
        }

        precedence.push_back(std::make_pair(u - 1, v - 1));
    }

    return Instance(number_of_tasks, number_of_workstations, execution_time, precedence);
}

Solution simulatedAnnealing(Instance instance, unsigned steps) {
    Solution current(instance);
    std::cout << current.getCycleTime() << ", ";
    Solution best = current;

    double temperature;

    for (int k = 0; k <= steps; k++) {
        temperature = 1.0 - ((double) k / steps);
        double r = (double) std::rand() / RAND_MAX;

        Solution neighbour(instance, current);

        if (neighbour.getCycleTime() < current.getCycleTime()) {
            current = neighbour;
        } else if (temperature > r) {
            current = neighbour;
        }

        if (current.getCycleTime() < best.getCycleTime()) {
            best = current;
        }
    }

    return best;
}

void printSolution(Solution solution) {
    std::cout << solution.getCycleTime() << "\n";
    std::cout << "#Task\t#Station\n";

    unsigned task = 0;
    for (unsigned station : solution.getTasks()) {
        std::cout << task << "\t" << station << "\n";
        task++;
    }
}

int main(int argc, char **argv) {
    std::istringstream ss;

    if (argc != 5) {
        fprintf(stderr, "Usage: salbp2-sa INSTANCE WORKSTATIONS SEED STEPS\n");
        fprintf(stderr, "\tINSTANCE instance file\n");
        fprintf(stderr, "\tWORKSTATIONS fixed number of workstations\n");
        fprintf(stderr, "\tSEED seed for random number generation\n");
        fprintf(stderr, "\tSTEPS number of iterations\n");
        exit(EXIT_FAILURE);
    }

    /* instance file path */
    const std::string instancePath(argv[1]);

    /* number of workstations */
    unsigned number_of_workstations;
    ss.str(argv[2]);
    ss >> number_of_workstations;
    ss.clear();

    Instance instance = parseInstance(instancePath, number_of_workstations);

    /* seed for random number generation */
    unsigned seed;
    ss.str(argv[3]);
    ss >> seed;
    ss.clear();

    std::srand(seed);

    /* number of steps */
    unsigned steps;
    ss.str(argv[4]);
    ss >> steps;
    ss.clear();

    std::cout << "initial, time, best" << std::endl;

    auto start = std::chrono::system_clock::now();

    Solution solution = simulatedAnnealing(instance, steps);

    auto end = std::chrono::system_clock::now();
    auto time = end - start;
    auto seconds = std::chrono::duration_cast<std::chrono::duration<double>>(time);

    std::cout << seconds.count() << ", ";

    printSolution(solution);
}
