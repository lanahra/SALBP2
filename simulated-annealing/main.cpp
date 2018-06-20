#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "instance.h"

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
    std::vector<std::vector<int>> A(n, std::vector<int>(n));

    while (std::getline(instanceFile, line)) {
        int u;
        int v;
        char comma;

        std::istringstream ss(line);
        ss >> u >> comma >> v;

        if (u == -1) {
            break;
        }

        A[u][v] = 1;
    }

    return Instance(m, t, A);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: INSTANCE WORKSTATIONS\n");
        exit(EXIT_FAILURE);
    }

    /* instance file path */
    const std::string instancePath(argv[1]);

    /* number of workstations */
    unsigned m;
    std::istringstream ss(argv[2]);
    ss >> m;

    Instance instance = parseInstance(instancePath, m);
}
