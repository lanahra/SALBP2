#include <vector>

class Instance {
    /* number of tasks */
    unsigned number_of_tasks;

    /* number of workstations */
    unsigned number_of_workstations;

    /* execution time of each task */
    std::vector<unsigned> execution_time;

    /* precedence graph */
    std::vector<std::pair<unsigned, unsigned>> precedence;

    public:
        Instance(
            unsigned number_of_tasks,
            unsigned number_of_workstations,
            std::vector<unsigned> execution_time,
            std::vector<std::pair<unsigned, unsigned>> precedence);
        unsigned getTasks();
        unsigned getStations();
        std::vector<unsigned> getTime();
        std::vector<std::pair<unsigned, unsigned>> getPrecedence();
};
