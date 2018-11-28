#pragma once

#define PREFIX uksf

#define QUOTE_NX(A) #A
#define QUOTE(A) QUOTE_NX(A)
#define DOUBLES_NX(A, B) A ## _ ## B
#define DOUBLES(A, B) DOUBLES_NX(A, B)

#define ADDON DOUBLES(PREFIX, COMPONENT)

#define GVAR(A) DOUBLES(ADDON, A)
#define QGVAR(A) QUOTE(GVAR(A))

#define LOCK client::invoker_lock lock
#define SLEEP(A) Sleep(DWORD(A * CLOCKS_PER_SEC))

#include "../common.hpp"
#include "../threaded.hpp"
