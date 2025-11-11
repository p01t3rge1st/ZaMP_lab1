#include <iostream>
#include "inc/Preprocessor.hh"
#include "inc/LibInterface.hh"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    try {
        std::string result = RunPreprocessor(argv[1]);
        std::cout << "=== Preprocessed output ===" << std::endl;
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
