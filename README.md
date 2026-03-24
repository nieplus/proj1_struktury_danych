# Struktury danych — Dynamic Array i Linked List

Prosty projekt demonstracyjny implementujący dwie struktury danych w C++:
- DynamicArray — tablica dynamiczna z automatycznym rozszerzaniem i kurczeniem
- LinkedList — lista jednokierunkowa

## Zawartość projektu
- [Dynamic_array.h](Dynamic_array.h) — deklaracja klasy `DynamicArray`
- [Dynamic_array.cpp](Dynamic_array.cpp) — implementacja `DynamicArray`
- [Linked_list.h](Linked_list.h) — deklaracja struktury `Node` i klasy `LinkedList`
- [Linked_list.cpp](Linked_list.cpp) — implementacja `LinkedList`
- [main.cpp](main.cpp) — punkt startowy

## Kompilacja
Projekt to prosty zbiór plików źródłowych. Masz dwie wygodne opcje kompilacji:

- Ręczna (g++):

```bash
g++ -std=c++17 main.cpp Dynamic_array.cpp Linked_list.cpp -o app
```

- Przy użyciu `Makefile` (zalecane):

```bash
make        # skompiluje pliki i zbuduje plik wykonywalny `app`
make run    # zbuduje i uruchomi ./app
make clean  # usunie pliki obiektowe i wykonywalny
```