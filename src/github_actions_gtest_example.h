#pragma once

#include <iostream>

#if defined(__unix__) || defined(__unix) || \
    (defined(__APPLE__) && defined(__MACH__))
#define __unix_or_mac__
#else
#define __windows__
#endif

#ifdef __unix_or_mac__ 
#define VISIBLE __attribute__((visibility("default")))
#else
/* Windows Visual C++ only */
#ifdef _EXPORTING
   #define VISIBLE __declspec(dllexport)
#else
   #define VISIBLE __declspec(dllimport)
#endif
#endif

namespace githubActionsGtestExample {

  VISIBLE std::string sayHello();
  VISIBLE int add(int _first, int _second);

} // namespace githubActionsGtestExample
