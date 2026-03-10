#include "threads.h"
#include "win_error.h"
#include "core.h"

#include <iostream>
#include <vector>
#include <stdexcept>

static std::vector<int> ReadArrayFromConsole()
{
    std::size_t n = 0;
    std::cout << "Enter array size: ";
    if (!(std::cin >> n) || n == 0U) {
        throw std::invalid_argument("Invalid array size");
    }

    std::vector<int> a;
    a.reserve(n);

    std::cout << "Enter " << n << " integers:\n";
    for (std::size_t i = 0; i < n; ++i) {
        int x = 0;
        if (!(std::cin >> x)) {
            throw std::invalid_argument("Invalid integer input");
        }
        a.push_back(x);
    }
    return a;
}

int main()
{
    try
    {
        std::vector<int> arr = ReadArrayFromConsole();

        ThreadData data;
        data.arr = &arr;

        HANDLE hMinMax = nullptr;
        HANDLE hAverage = nullptr;
        DWORD idMinMax = 0;
        DWORD idAverage = 0;

        hMinMax = CreateThread(
            nullptr,
            0,
            min_max,             
            &data,
            0,
            &idMinMax
        );
        if (hMinMax == nullptr) {
            ThrowLastError("CreateThread(min_max)");
        }

        hAverage = CreateThread(
            nullptr,
            0,
            average,             
            &data,
            0,
            &idAverage
        );
        if (hAverage == nullptr) {
            CloseHandle(hMinMax);
            ThrowLastError("CreateThread(average)");
        }

        WaitForSingleObject(hMinMax, INFINITE);
        WaitForSingleObject(hAverage, INFINITE);

        CloseHandle(hAverage);
        CloseHandle(hMinMax);

        arr = ReplaceMinMax(arr, data.mn, data.mx, data.avg);

        std::cout << "Result array:\n";
        for (const int v : arr) {
            std::cout << v << " ";
        }
        std::cout << "\n";

        return 0;
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }
}