#pragma once

#include <vector>
#include <utility>
#include <Windows.h>
std::pair<int, int> CalcMinMax(const std::vector<int>& a);
double CalcAverage(const std::vector<int>& a);
std::vector<int> ReplaceMinMax(const std::vector<int>& a, int mn, int mx, double avg);