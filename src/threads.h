#pragma once
#include <vector>
#include <windows.h>

struct ThreadData {
    const std::vector<int>* arr = nullptr;
    int mn = 0;
    int mx = 0;
    double avg = 0.0;
};

DWORD WINAPI min_max(LPVOID p);
DWORD WINAPI average(LPVOID p);