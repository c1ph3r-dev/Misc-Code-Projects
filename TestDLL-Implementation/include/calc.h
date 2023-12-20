#pragma once

#ifdef CALCULATION_EXPORTS
#define CALCULATION_API __declspec(dllexport)
#else
#define CALCULATION_API __declspec(dllimport)
#endif

extern "C" CALCULATION_API void addition(double a, double b);

extern "C" CALCULATION_API void subtraction(double a, double b);