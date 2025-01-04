#pragma once

#include <cmath>
#include <thread>
#include <vector>
#include <algorithm>
#include <numeric>
#include <execution>
#include <functional>

namespace map {
    void calc_ser(std::vector<double>& iv, std::vector<double>& ov, std::function<double(double)> op) {
        std::transform(iv.begin(), iv.end(), ov.begin(), [&](auto x) {
            return op(x);
        });
    }

    void calc_par(std::vector<double>& iv, std::vector<double>& ov, std::function<double(double)> op) {
        std::transform(std::execution::par, iv.begin(), iv.end(), ov.begin(), [&](auto x) {
            return op(x);
        });
    }
}