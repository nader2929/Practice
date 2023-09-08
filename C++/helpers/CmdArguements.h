#include <string>

using namespace std;

struct CmdArguments{
    int rows;
    int cols;
    int cpus;
    bool debugMode = false;
};

CmdArguments getCmdArguements(int argc, char **argv);