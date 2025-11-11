#include "../inc/LibInterface.hh"

bool LibInterface::LoadPlugin() {
    handle = dlopen(libPath.c_str(), RTLD_LAZY);
    if (!handle) {
        std::cerr << "Nie moge zaladowac " << libPath << "\n";
        return false;
    }
    
    CreateCmd = (CreateCmdFunc)dlsym(handle, "CreateCmd");
    if (!CreateCmd) {
        std::cerr << "Blad: nie znalazlem CreateCmd\n";
        return false;
    }
    
    GetCmdName = (GetCmdNameFunc)dlsym(handle, "GetCmdName");
    if (!GetCmdName) {
        std::cerr << "Blad: nie znalazlem GetCmdName\n";
        return false;
    }
    
    return true;
}

void LibInterface::UnloadPlugin() {
    if (handle) {
        dlclose(handle);
        handle = nullptr;
    }
}