# Interpreter - Etap 1

## Opis projektu
Interpreter poleceń z obsługą wtyczek dynamicznych (bibliotek .so).

## Struktura projektu
- `inc/` - pliki nagłówkowe
  - `LibInterface.hh` - interfejs do ładowania bibliotek dynamicznych
  - `Preprocessor.hh` - funkcja uruchamiająca preprocesor
- `src/` - pliki źródłowe
  - `LibInterface.cpp` - implementacja ładowania wtyczek
  - `Preprocessor.cpp` - implementacja preprocesora
  - `main.cpp` - program testowy

## Kompilacja
```bash
make
```

## Uruchomienie
```bash
./interpreter test_actions.txt
```

## Wymagania
- g++ z obsługą C++17
- biblioteka dl (dlopen, dlsym)
