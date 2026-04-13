#include <iostream>
#include <chrono>
#include <iomanip>
#include <string>
#include "Dynamic_array.h"
#include "Linked_list.h"

using namespace std;
using namespace std::chrono;

// Funkcja pomocnicza do wypisywania wyników
void printResult(string op, double arrayTime, double listTime) {
    cout << left << setw(25) << op
        << fixed << setprecision(6) << setw(15) << arrayTime << "s | "
        << setw(15) << listTime << "s" << endl;
}

int main() {
    const int N = 100000;

    cout << "Rozpoczynam testy porownawcze dla N = " << N << " elementow\n";
    cout << "--------------------------------------------------------------------------\n";
    cout << left << setw(25) << "Operacja" << setw(18) << "Tablica dyn." << "Lista wiazana" << endl;
    cout << "--------------------------------------------------------------------------\n";

    DynamicArray arr(10);
    LinkedList list;

    auto start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) arr.addEnd(i);
    auto end = high_resolution_clock::now();
    double t_arr_end = duration<double>(end - start).count();

    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) list.addEnd(i);
    end = high_resolution_clock::now();
    double t_list_end = duration<double>(end - start).count();
    printResult("Dodawanie na koniec", t_arr_end, t_list_end);

    start = high_resolution_clock::now();
    arr.find(N - 1);
    end = high_resolution_clock::now();
    double t_arr_find = duration<double>(end - start).count();

    start = high_resolution_clock::now();
    list.find(N - 1);
    end = high_resolution_clock::now();
    double t_list_find = duration<double>(end - start).count();
    printResult("Wyszukiwanie (koniec)", t_arr_find, t_list_find);

    start = high_resolution_clock::now();
    arr.addAtIndex(N / 2, 999);
    end = high_resolution_clock::now();
    double t_arr_idx = duration<double>(end - start).count();

    start = high_resolution_clock::now();
    list.addAtIndex(N / 2, 999);
    end = high_resolution_clock::now();
    double t_list_idx = duration<double>(end - start).count();
    printResult("Dodawanie w srodek", t_arr_idx, t_list_idx);

    start = high_resolution_clock::now();
    arr.removeAtIndex(N / 2);
    end = high_resolution_clock::now();
    double t_arr_rem_idx = duration<double>(end - start).count();

    start = high_resolution_clock::now();
    list.removeAtIndex(N / 2);
    end = high_resolution_clock::now();
    double t_list_rem_idx = duration<double>(end - start).count();
    printResult("Usuwanie ze srodka", t_arr_rem_idx, t_list_rem_idx);

    start = high_resolution_clock::now();
    for (int i = 0; i < N / 10; i++) arr.removeFront();
    end = high_resolution_clock::now();
    double t_arr_rem_front = duration<double>(end - start).count();

    start = high_resolution_clock::now();
    for (int i = 0; i < N / 10; i++) list.removeFront();
    end = high_resolution_clock::now();
    double t_list_rem_front = duration<double>(end - start).count();
    printResult("Usuwanie z poczatku (x" + to_string(N / 10) + ")", t_arr_rem_front, t_list_rem_front);

    DynamicArray arr2(10);
    LinkedList list2;

    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) arr2.addFront(i);
    end = high_resolution_clock::now();
    double t_arr_front = duration<double>(end - start).count();

    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) list2.addFront(i);
    end = high_resolution_clock::now();
    double t_list_front = duration<double>(end - start).count();
    printResult("Dodawanie na poczatek", t_arr_front, t_list_front);

    start = high_resolution_clock::now();
    for (int i = 0; i < N / 10; i++) arr2.removeEnd();
    end = high_resolution_clock::now();
    double t_arr_rem_end = duration<double>(end - start).count();

    start = high_resolution_clock::now();
    for (int i = 0; i < N / 10; i++) list2.removeEnd();
    end = high_resolution_clock::now();
    double t_list_rem_end = duration<double>(end - start).count();
    printResult("Usuwanie z konca (x" + to_string(N / 10) + ")", t_arr_rem_end, t_list_rem_end);

    cout << "--------------------------------------------------------------------------\n";
    return 0;
}