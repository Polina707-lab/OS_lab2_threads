#include "threads.h"
#include <iostream>

DWORD WINAPI min_max(LPVOID p)
{
    auto* data = reinterpret_cast<ThreadData*>(p);

    std::pair <int, int> mxmn = CalcMinMax(*data->arr);
    data->mn = mxmn.first;
    data->mx = mxmn.second;

    std::cout << "min = " << data->mn << "\n";
    std::cout << "max = " << data->mx << "\n";

    return 0;
}

DWORD WINAPI average(LPVOID p)
{
    auto* data = reinterpret_cast<ThreadData*>(p);


    data->avg = CalcAverage(*data->arr);
    std::cout << "average = " << data->avg << "\n";

    return 0;
}