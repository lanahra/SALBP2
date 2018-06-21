#include <algorithm>
#include <cstdlib>
#include <vector>
#include "instance.h"

class Solution {

    /* station assignment for each task */
    std::vector<unsigned> tasks;

    /* cycle time for each station */
    std::vector<unsigned> time;

    /* cycle time of assembly line */
    unsigned cycleTime;

    public:
        /* create valid initial solution */
        Solution(Instance instance);

        /* create valid neighbour from another solution */
        Solution(Instance instance, Solution solution);

        /* return true if solution is valid, false otherwise */
        bool isValid(Instance instance);

        std::vector<unsigned> getTasks();
        std::vector<unsigned> getTime();
        unsigned getCycleTime();
};
