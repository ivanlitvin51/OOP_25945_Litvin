#include <vector>
#include <array>
#include <list>
#include <deque>
#include <iostream>
#include <random>
#include <iomanip>
#include <sstream>
#include <fstream>

#include "hypo.hpp"
#include "hypo_mod.hpp"


int main() {
    const int  M = 15;
    const long N = 50000;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, M);

    std::vector<long>       vec;
    std::array<long, 15>    arr{};
    std::list<long>         lst;
    std::deque<long>        deq;

    for (int i = 0; i < M; ++i) {
        long value = dist(gen);

        vec.push_back(value);
        arr[i] = value;
        lst.push_back(value);
        deq.push_back(value);
    }

    std::vector<double>     res_vec(M);
    std::array<double, 15>  res_arr{};
    std::list<double>       res_lst;
    std::deque<double>      res_deq(M);

    for (int i = 0; i < M; ++i) {
        res_vec[i] = hypo_random::hypotenuse<double>(vec[i], vec[i] + 1);
    }

    for (int i = 0; i < M; ++i) {
        res_arr[i] = hypo_random::hypotenuse<double>(arr[i], arr[i] + 1);
    }

    for (std::list<long>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << static_cast<const void*>(&*it);
        res_lst.push_back(hypo_random::hypotenuse<double>(*it, (*it) + 1));
    }

    std::size_t idx = 0;
    for (const long& value : deq) {
        res_deq[idx++] = hypo_random::hypotenuse<double>(value, value + 1);
    }


    std::list<double>   res_from_vec;
    std::deque<double>  res_from_arr(M);
    std::vector<double> res_from_lst;
    std::array<double, 15> res_from_deq{};

    for (int i = 0; i < M; i++) {
        res_from_vec.push_back(hypo_random::hypotenuse<double>(vec[i], vec[i]) + 1);
    }

    for (int i = 0; i < M; i++) {
        res_from_arr[i] = hypo_random::hypotenuse<double>(arr[i], arr[i] + 1);
    }

    for (std::list<long>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
        res_from_lst.push_back(hypo_random::hypotenuse<double>(*it, (*it) + 1));
    }

    std::size_t idx2 = 0;
    for (const long& value : deq) {
        res_from_deq[idx2++] = hypo_random::hypotenuse<double>(value, value + 1);
    }

    std::ostringstream table;
    table << "| Index | Vector | Vector -> Result | Array | Array -> Result "
        "| List | List -> Result | Deque | Deque -> Result |\n";

    std::list<long>::const_iterator   itList = lst.begin();
    std::list<double>::const_iterator itListRes = res_lst.begin();

    table << std::fixed << std::setprecision(2);
    for (int i = 0; i < M; ++i) {
        table << "| " << i
            << " | " << vec[i]
            << " | " << res_vec[i]
            << " | " << arr[i]
            << " | " << res_arr[i]
            << " | " << *itList
            << " | " << *itListRes
            << " | " << deq[i]
            << " | " << res_deq[i]
            << " |\n";

        ++itList;
        ++itListRes;
    }

    std::ofstream out("containers.md");
    out << table.str();
    out.close();

    return 0;
}