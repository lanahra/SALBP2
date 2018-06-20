#include <vector>

class Instance {
    /* number of workstations */
    unsigned m;

    /* execution time of each task */
    std::vector<unsigned> t;

    /* precedence graph */
    std::vector<std::vector<int>> A;

    public:
        Instance(
            unsigned m,
            std::vector<unsigned> t,
            std::vector<std::vector<int>> A);
};
