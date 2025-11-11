#include "../inc/AbstractInterp4Command.hh"
#include <iostream>

class ExampleCommand : public AbstractInterp4Command {
public:
    ExampleCommand() {
        std::cout << "    [PLUGIN] Konstruktor ExampleCommand wywołany" << std::endl;
    }
    
    ~ExampleCommand() override {
        std::cout << "    [PLUGIN] Destruktor ExampleCommand wywołany" << std::endl;
    }
    
    const char* GetCmdName() const override {
        std::cout << "    [PLUGIN] GetCmdName() wywołane" << std::endl;
        return "example";
    }
    
    bool Execute() override {
        std::cout << "    [PLUGIN] Execute() - Rozpoczynam wykonywanie..." << std::endl;
        std::cout << "    [PLUGIN] Wykonuję przykładową operację!" << std::endl;
        std::cout << "    [PLUGIN] 2 + 2 = " << (2 + 2) << std::endl;
        std::cout << "    [PLUGIN] Execute() - Zakończono pomyślnie" << std::endl;
        return true;
    }
};

extern "C" {
    AbstractInterp4Command* CreateCmd() {
        std::cout << "    [PLUGIN] CreateCmd() - tworzę nową instancję ExampleCommand" << std::endl;
        return new ExampleCommand();
    }
    
    const char* GetCmdName() {
        std::cout << "    [PLUGIN] GetCmdName() (funkcja C) wywołana" << std::endl;
        return "example";
    }
}
