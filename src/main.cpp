#include <iostream>
#include <vector>
#include <chrono>

#include "utils.hpp"

int main() {
    const double e = 2.718281828459;

    auto x = std::vector<double>();  // 1gb double
    for (size_t idx = 0; idx < 134217728; idx++) {
        x.push_back(static_cast<double>(idx));
    }

    // serial
    std::cout << "serial calculation begin" << std::endl;
    auto x0 = std::vector(x);
    auto start0 = std::chrono::high_resolution_clock::now();
    map::calc_ser(x0, x0, [&](auto x) {
        return std::sin(std::pow(e, -x));
    });
    auto end0 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration0 = end0 - start0;
    auto sum0 = std::accumulate(x0.begin(), x0.end(), 0.0);
    std::cout << "ser time cost:\t" << std::chrono::duration_cast<std::chrono::milliseconds>(duration0).count() << "\t"
              << "result:\t" << sum0 << std::endl;

    // parallel
    std::cout << "parallel calculation begin" << std::endl;
    auto x1 = std::vector(x);
    auto start1 = std::chrono::high_resolution_clock::now();
    map::calc_par(x1, x1, [&](auto x) {
        return std::sin(std::pow(e, -x));
    });
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration1 = end1 - start1;
    auto sum1 = std::accumulate(x1.begin(), x1.end(), 0.0);
    std::cout << "par time cost:\t" << std::chrono::duration_cast<std::chrono::milliseconds>(duration1).count() << "\t"
              << "result:\t" << sum1 << std::endl;

    return 0;
}