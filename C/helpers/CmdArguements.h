#include <string>

using namespace std;

struct CmdArguments{
    int rows;
    int cols;
    int cpus;
};

CmdArguments getCmdArguements(int argc, char **argv);