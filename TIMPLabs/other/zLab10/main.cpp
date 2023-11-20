/*
Написать программу поиска в заданной последовательности неотрицательных чисел минимальное среднее
арифметическое двух ее элементов, номера которых различаются не менее, чем на 6 Известно, что значение
каждого элемента последовательности не превышает 1000 Количество элементов последовательности не
превышает 10000

Программа считается эффективной по времени, если время работы программы пропорционально количеству
элементов последовательности N , т.е. при увеличении N в k раз время работы программы должно
увеличиваться не более чем в k раз. Программа считается эффективной по памяти, если размер памяти,
использованной в программе для хранения данных, не зависит от числа N и не превышает 1 килобайта.

Программа считается эффективной по памяти, если размер памяти, использованной в программе для хранения
данных, не зависит от числа N и не превышает 1 килобайта. Входные данные представлены следующим
образом. В первой строке задаётся число N — общее количество элементов последовательности.
Гарантируется, что N > 6 . В каждой из следующих N строк задаётся одно неотрицательное целое число —
очередной элемент последовательности.

Для решения поставленной задачи используйте массивы для хранения входных данных, после чего будут
проверены все возможные пары элементов.
Оптимизируйте написанную программу так, чтобы она стала эффективной как по времени, так и по памяти (или
хотя бы по одной из этих характеристик).
Пример входных данных:
10
100
45
55
10
35
25
10
10
10
26
Ответ - 18
*/



// Оптимизированная
// #include <iostream>
// #include <chrono>
// #include <time.h>
// using namespace std;

// static void test_proc(){
//     short n; cin >> n;
//     short arr[10000];
//     for (short i = 0; i < n; ++i) {
//         // cin >> arr[i];
//         arr[i] = rand() % 1000;
//     }

//     auto start = chrono::steady_clock::now();
    
//     float avg = 1001.0;
//     short index = 6;
//     short num;
//     while(index < n){
//         for(short i = 0; i < n-index; i++){
//             num = (arr[i]+arr[i+index]) * 0.5;
//             if (num < avg){ avg = num; }
//         }
//         ++index;
//     }
//     cout << avg << endl;
//     auto dur = chrono::steady_clock::now() - start;
//     cout << "Time: " << chrono::duration_cast<chrono::microseconds>(dur).count() << " mcrsec" << endl;
// }

// static void size_proc(){}

// static size_t test_proc_size(){
//     return (uintptr_t)((uintptr_t)(void*)size_proc - (uintptr_t)(void*)test_proc);
// }

// int main() {
//     srand(time(nullptr));
//     test_proc(); // Функция с тз
//     size_proc(); // Функция пустышка, записана после тз
//     cout << "Memory: " << test_proc_size() << " bit" << endl; // вычислялка на 107 строке
//     return 0;
// }

#include <iostream>
#include <unordered_map>
#include <chrono>

using namespace std;

int main() {
    short n;
    cin >> n;

    short arr[10000];
    for (short i = 0; i < n; ++i) {
        // cin >> arr[i];
        arr[i] = rand() % 1000;
    }

    auto start = chrono::steady_clock::now();

    unordered_map<short, short> sumCountMap;
    short index = 6;
    short sum = 0;

    for (short i = 0; i < index; ++i) {
        sum += arr[i];
    }

    for (short i = 0; i < n - index; ++i) {
        sum += arr[i + index];
        short avg = sum / index;
        sumCountMap[avg]++;
        sum -= arr[i];
    }

    float minAvg = 1001.0;
    for (const auto& entry : sumCountMap) {
        if (entry.first < minAvg) {
            minAvg = entry.first;
        }
    }

    auto dur = chrono::steady_clock::now() - start;
    cout << "Min Avg: " << minAvg << endl;
    cout << "time: " << chrono::duration_cast<chrono::microseconds>(dur).count() << " mcrsec";
    cin.ignore();
    cin.get();
    return 0;
}

// #include <chrono>
// auto start = chrono::steady_clock::now(); // Запоминаем время начала работы программы
// auto dur = chrono::steady_clock::now() - start; // Вычисляем время выполнения
// cout << "Время выполнения программы: " << chrono::duration_cast<chrono::microseconds>(dur).count() << " микросекунд";
// start = chrono::steady_clock::now(); // Снова запоминаем время начала работы программы
