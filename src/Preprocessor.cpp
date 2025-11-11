#include "../inc/Preprocessor.hh"
#include <cstdlib>
#include <sstream>
#include <array>
#include <memory>
#include <stdexcept>
#include <iostream>

std::string RunPreprocessor(const std::string& inputFile) {
    std::string cmd = "g++ -E -P -x c++ " + inputFile + " 2>&1";
    
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) {
        return "";
    }
    
    char buffer[128];
    std::string result = "";
    
    while (fgets(buffer, 128, pipe) != NULL) {
        result += buffer;
    }
    
    pclose(pipe);
    return result;
}
