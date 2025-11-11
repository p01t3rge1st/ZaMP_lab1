#include <iostream>
#include "../inc/Preprocessor.hh"
#include "../inc/LibInterface.hh"

void TestPreprocessor(const std::string& filename) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "TEST 1: PREPROCESOR" << std::endl;
    std::cout << "========================================" << std::endl;
    
    try {
        std::cout << "[INFO] Wczytywanie pliku: " << filename << std::endl;
        std::string result = RunPreprocessor(filename);
        
        std::cout << "[OK] Preprocesor zakończył pracę\n" << std::endl;
        std::cout << "=== Wynik po preprocessingu ===" << std::endl;
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "[BŁĄD] " << e.what() << std::endl;
    }
}

void TestPlugin(const std::string& pluginPath) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "TEST 2: ŁADOWANIE WTYCZKI" << std::endl;
    std::cout << "========================================" << std::endl;
    
    std::cout << "[INFO] Tworzenie interfejsu dla: " << pluginPath << std::endl;
    LibInterface plugin(pluginPath);
    
    std::cout << "[INFO] Próba załadowania wtyczki..." << std::endl;
    if (!plugin.LoadPlugin()) {
        std::cerr << "[BŁĄD] Nie udało się załadować wtyczki!" << std::endl;
        return;
    }
    
    std::cout << "[OK] Wtyczka załadowana pomyślnie!" << std::endl;
    std::cout << "[INFO] Adres handle: " << plugin.handle << std::endl;
    std::cout << "[INFO] Adres CreateCmd: " << (void*)plugin.CreateCmd << std::endl;
    std::cout << "[INFO] Adres GetCmdName: " << (void*)plugin.GetCmdName << std::endl;
    
    // Pobierz nazwę komendy
    std::cout << "\n[INFO] Wywołanie GetCmdName()..." << std::endl;
    const char* cmdName = plugin.GetCmdName();
    std::cout << "[OK] Nazwa komendy: '" << cmdName << "'" << std::endl;
    
    // Stwórz instancję komendy
    std::cout << "\n[INFO] Wywołanie CreateCmd()..." << std::endl;
    AbstractInterp4Command* cmd = plugin.CreateCmd();
    std::cout << "[OK] Utworzono obiekt komendy (adres: " << (void*)cmd << ")" << std::endl;
    
    // Wykonaj komendę
    std::cout << "\n[INFO] Wywołanie Execute()..." << std::endl;
    bool success = cmd->Execute();
    std::cout << "[OK] Execute() zwróciło: " << (success ? "true" : "false") << std::endl;
    
    // Posprzątaj
    delete cmd;
    std::cout << "\n[INFO] Usunięto obiekt komendy" << std::endl;
    std::cout << "[INFO] Wtyczka zostanie automatycznie wyładowana (destruktor)" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file> [plugin_path]" << std::endl;
        return 1;
    }

    // Test preprocesora
    TestPreprocessor(argv[1]);
    
    // Test wtyczki (jeśli podano ścieżkę lub użyj domyślnej)
    std::string pluginPath = (argc >= 3) ? argv[2] : "./libexample.so";
    TestPlugin(pluginPath);

    std::cout << "\n========================================" << std::endl;
    std::cout << "KONIEC TESTÓW" << std::endl;
    std::cout << "========================================\n" << std::endl;

    return 0;
}
