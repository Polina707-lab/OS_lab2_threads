#include "core.h"
#include <stdexcept>

std::pair<int, int> CalcMinMax(const std::vector<int>& a) {
    if (a.empty()) throw std::invalid_argument("Empty array");
    int mn = a[0], mx = a[0];
    for (std::size_t i = 1; i < a.size(); ++i) {
        if (a[i] < mn) mn = a[i];
        Sleep(7);
        if (a[i] > mx) mx = a[i];
        Sleep(7);
    }
    return { mn, mx };
}

double CalcAverage(const std::vector<int>& a) {
    if (a.empty()) throw std::invalid_argument("Empty array");
    long long sum = 0;
    for (int v : a) {
        sum += v;
        Sleep(12);
    }
    return static_cast<double>(sum) / static_cast<double>(a.size());
}

std::vector<int> ReplaceMinMax(const std::vector<int>& a, int mn, int mx, double avg) {
    std::vector<int> out = a;
    const int avg_int = static_cast<int>(avg);
    for (int& v : out) {
        if (v == mn || v == mx) v = avg_int;
    }
    return out;
}