#include <vector>

class Instance {
    /* number of tasks */
    unsigned n;

    /* number of workstations */
    unsigned m;

    /* execution time of each task */
    std::vector<unsigned> t;

    /* precedence graph */
    std::vector<std::pair<unsigned, unsigned>> A;

    public:
        Instance(
            unsigned n,
            unsigned m,
            std::vector<unsigned> t,
            std::vector<std::pair<unsigned, unsigned>> A);
        unsigned getTasks();
        unsigned getStations();
        std::vector<unsigned> getTime();
        std::vector<std::pair<unsigned, unsigned>> getPrecedence();
};
