#pragma once
#include <string>
#include <windows.h>

std::string GetLastErrorAsString(DWORD err);
[[noreturn]] void ThrowLastError(const char* where);