#include <string>
#include <iostream>
#include <sys/stat.h>
#include "CmdArguements.h"

using namespace std;

bool file_exists(string path){
    struct stat buffer;   
    return (stat (path.c_str(), &buffer) == 0); 
}

CmdArguments getCmdArguements(int argc, char **argv){
    CmdArguments cmdArgs = CmdArguments();
    for (int i = 1; i < argc; i += 2) {
        string arg = argv[i];
        string value = (i + 1 < argc) ? argv[i + 1] : "";

        if (arg == "--cpus" || arg == "-p") {
            try{
                cmdArgs.cpus = stoi(value);
            }
            catch(const exception& e){
                cout << "\tERROR: Cannot convert given value for CPUs (processors)\n";
                exit(-1);
            }
        } else if (arg == "--rows" || arg == "-r") {
            try{
                cmdArgs.rows = stoi(value);
            }
            catch(const exception& e){
                cout << "\tERROR: Cannot convert given value for size of X axis\n";
                exit(-1);
            }
        } else if (arg == "--cols"|| arg == "-c") {
            try{
                cmdArgs.cols = stoi(value);
            }
            catch(const exception& e){
                cout << "\tERROR: Cannot convert given value for size of Y axis\n";
                exit(-1);
            }
        } else if(arg == "--help" || arg == "-h"){ 
            cout << R"(
options:
    -h, --help            show this help message and exit
    --cpus CPUS, -p CPUS  Number of processors to use to process the image.
            )" << "\n";
            exit(-1);
        } else {
            std::cout << "Invalid argument: " << arg << std::endl;
        }
    }
    string missingArgs = "";
    if(cmdArgs.cpus == 0){
        missingArgs = "cpus";
    }

    if(missingArgs != ""){
        cout << "PARSE ERROR:\n\t" << "Required argument missing: " << missingArgs << "\n";
        exit(-1);
    }
    return cmdArgs;
}