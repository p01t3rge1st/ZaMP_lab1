#include "../inc/AbstractInterp4Command.hh"
#include <iostream>

class ExampleCommand : public AbstractInterp4Command {
public:
    const char* GetCmdName() const override {
        return "example";
    }
    
    bool Execute() override {
        std::cout << "Executing example command" << std::endl;
        return true;
    }
};

extern "C" {
    AbstractInterp4Command* CreateCmd() {
        return new ExampleCommand();
    }
    
    const char* GetCmdName() {
        return "example";
    }
}
