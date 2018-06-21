#include <algorithm>
#include <cstdlib>
#include <vector>
#include "instance.h"

class Solution {

    std::vector<unsigned> tasks;
    std::vector<unsigned> time;
    unsigned cycleTime;

    public:
        Solution(Instance instance);
        Solution(Instance instance, Solution solution);
        bool isValid(Instance instance);
        std::vector<unsigned> getTasks();
        std::vector<unsigned> getTime();
        unsigned getCycleTime();
};
