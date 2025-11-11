#include "../inc/Preprocessor.hh"
#include <cstdlib>
#include <sstream>
#include <array>
#include <memory>
#include <stdexcept>
#include <iostream>

std::string RunPreprocessor(const std::string& inputFile) {
    std::string cmd = "g++ -E -P -x c++ " + inputFile + " 2>&1";
    
    std::array<char, 128> buffer;
    std::string result;

    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    
    return result;
}
