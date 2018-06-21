#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "solution.h"

Instance parseInstance(std::string instancePath, unsigned m) {
    /* number of tasks */
    unsigned n;

    std::string line;
    std::ifstream instanceFile(instancePath);

    /* parse number of tasks */
    std::getline(instanceFile, line);
    std::istringstream ss(line);
    ss >> n;

    /* execution time of each task */
    std::vector<unsigned> t(n);

    for (int i = 0; i < n; i++) {
        unsigned time;

        std::getline(instanceFile, line);
        std::istringstream ss(line);
        ss >> time;

        t[i] = time;
    }

    /* precedence graph */
    std::vector<std::pair<unsigned, unsigned>> A;

    while (std::getline(instanceFile, line)) {
        int u;
        int v;
        char comma;

        std::istringstream ss(line);
        ss >> u >> comma >> v;

        if (u == -1) {
            break;
        }

        A.push_back(std::make_pair(u - 1, v - 1));
    }

    return Instance(n, m, t, A);
}

Solution simulatedAnnealing(Instance instance, unsigned steps) {
    Solution current(instance);
    std::cout << "Initial solution: " << current.getCycleTime() << "\n";
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
    std::cout << "Best solution: " << solution.getCycleTime() << "\n";
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
        fprintf(stderr, "Usage: INSTANCE WORKSTATIONS SEED STEPS\n");
        exit(EXIT_FAILURE);
    }

    /* instance file path */
    const std::string instancePath(argv[1]);

    /* number of workstations */
    unsigned m;
    ss.str(argv[2]);
    ss >> m;
    ss.clear();

    Instance instance = parseInstance(instancePath, m);

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

    Solution solution = simulatedAnnealing(instance, steps);

    printSolution(solution);
}
