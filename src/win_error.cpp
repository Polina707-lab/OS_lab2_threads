#include "win_error.h"
#include <stdexcept>

std::string GetLastErrorAsString(DWORD err) {
    LPSTR buf = nullptr;

    const DWORD flags = FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS;

    const DWORD len = FormatMessageA(
        flags,
        nullptr,
        err,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        reinterpret_cast<LPSTR>(&buf),
        0,
        nullptr
    );

    std::string msg;
    if (len != 0U && buf != nullptr) {
        msg.assign(buf, buf + len);
    }
    else {
        msg = "Unknown error";
    }

    if (buf != nullptr) {
        LocalFree(buf);
    }
    return msg;
}

void ThrowLastError(const char* where) {
    const DWORD err = GetLastError();
    throw std::runtime_error(
        std::string(where) + ": (" + std::to_string(err) + ") " + GetLastErrorAsString(err)
    );
}