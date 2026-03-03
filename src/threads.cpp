#include "threads.h"
#include <iostream>

DWORD WINAPI min_max(LPVOID p)
{
    auto* data = reinterpret_cast<ThreadData*>(p);

    int mn = (*data->arr)[0];
    int mx = (*data->arr)[0];

    for (std::size_t i = 1; i < data->arr->size(); ++i)
    {
      
        if ((*data->arr)[i] < mn) mn = (*data->arr)[i];
        Sleep(7);

        if ((*data->arr)[i] > mx) mx = (*data->arr)[i];
        Sleep(7);

    }

    data->mn = mn;
    data->mx = mx;

    std::cout << "min = " << data->mn << "\n";
    std::cout << "max = " << data->mx << "\n";

    return 0;
}

DWORD WINAPI average(LPVOID p)
{
    auto* data = reinterpret_cast<ThreadData*>(p);

    long long sum = 0;
    for (std::size_t i = 0; i < data->arr->size(); ++i)
    {
        sum += (*data->arr)[i];

        Sleep(12);
    }

    data->avg = static_cast<double>(sum) / static_cast<double>(data->arr->size());
    std::cout << "average = " << data->avg << "\n";

    return 0;
}