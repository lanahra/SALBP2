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
        void change(Instance instance);
        bool isValid(Instance instance);
        std::vector<unsigned> getTasks();
        unsigned getCycleTime();
};
