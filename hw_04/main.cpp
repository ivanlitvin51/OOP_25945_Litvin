#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <iterator>

std::vector<int> load(std::string filename) {
    std::ifstream file(filename);
    std::vector<int> result;
    int number;

    while (file >> number) {
        result.push_back(number);
        if (file.peek() == ',') {
            file.ignore();
        }
    }
    return result;
}

int main() {
    std::vector<int> file1 = load("s04_v1_45_1.txt");
    std::vector<int> file2 = load("s04_v1_45_2.txt");

    std::vector<int> v1;
    std::vector<int> v2;
    if (file1.size() >= file2.size()) {
        v1 = file1;
        v2 = file2;
    } else {
        v1 = file2;
        v2 = file1;
    }

    std::cout << "Количество в первом: " << v1.size() << std::endl;
    std::cout << "Количество во втором: " << v2.size() << std::endl;

    // способ 1 через обычный цикл for
    std::map<int, int> count_v1;
    for (int i = 0; i < v1.size(); i++) {
        int x = v1[i];
        count_v1[x]++;
    }

    // способ 2 через функцию std::count из <algorithm>
    std::map<int, int> count_v2;
    for (int i = 0; i < v2.size(); i++) {
        int x = v2[i];
        count_v2[x] = std::count(v2.begin(), v2.end(), x);
    }
    
    int cnt = std::count(std::next(v2.begin(), 23), v2.end(), 33);
    std::cout << "Количество 33 в 2 векторе: " << cnt << "\n";

    // сумма всех значений (2 варианта)
    // вариант 1 std::accumulate
    long long sum1 = std::accumulate(v1.begin(), v1.end(), 0LL);

    // вариант 2 std::for_each с лямбдой
    long long sum2 = 0;
    std::for_each(v1.begin(), v1.end(), [&sum2, sum1](int x) {
        sum2 += x;
    });

    std::cout << "Сумма v1 (accumulate): " << sum1 << std::endl;
    std::cout << "Сумма v1 (for_each): " << sum2 << std::endl;

    // сумма первых 10 элементов без циклов
    int first10_v1 = std::accumulate(v1.begin(), std::next(v1.begin(), 10), 0);
    int first10_v2 = std::accumulate(v2.begin(), std::next(v2.begin(), 10), 0);
    std::cout << "Сумма первых 10 v1: " << first10_v1 << std::endl;
    std::cout << "Сумма первых 10 v2: " << first10_v2 << std::endl;
    

    // бинарная операция через std::accumulate (пример: сложение по модулю 2, XOR)
    int bin_res = std::accumulate(v1.begin(), v1.end(), 0, [](int acc, int x) {
        return acc ^ x;
    });
    std::cout << "Бинарная операция: " << bin_res << std::endl;

    // числа, которые во 2-м векторе >= 2 раз, а в 1-м векторе > 3 раз
    std::cout << "\nРезультаты сравнения дубликатов:\n";

    // способ 1 через цикл for (по словарю count_v2)
    std::cout << "-- Способ 1 (через for):" << std::endl;
    for (std::map<int, int>::iterator it = count_v2.begin(); it != count_v2.end(); ++it) {
        int num = it->first;
        int in_v2 = it->second;
        int in_v1 = count_v1[num];

        if (in_v2 >= 2 && in_v1 > 3) {
            std::cout << "Число " << num << " -> в v1: " << in_v1 << ", в v2: " << in_v2 << std::endl;
        }
    }

    // способ 2: через std::for_each из <algorithm> с лямбдой
    std::cout << "\n-- Способ 2 (через std::for_each):" << std::endl;
    std::for_each(count_v2.begin(), count_v2.end(), [&count_v1](std::pair<int, int> p) {
        int num = p.first;
        int in_v2 = p.second;
        int in_v1 = count_v1[num];

        if (in_v2 >= 2 && in_v1 > 3) {
            std::cout << "Число " << num << " -> в v1: " << in_v1 << ", в v2: " << in_v2 << std::endl;
        }
    });

    return 0;
}