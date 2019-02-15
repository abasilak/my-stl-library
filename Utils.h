#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>
#include <cmath>
#include <assert.h>
#include <limits.h>

inline
bool
power_of_two(size_t x)
{
    return !(x == 0) && !(x & (x - 1));
}

template<typename T>
void
safe_delete(T*& ptr)
{
    if(ptr) { delete   ptr; ptr = nullptr; }
}

template <typename T>
void
safe_array_delete(T*& ptr)
{
    if(ptr) { delete[] ptr; ptr = nullptr; }
}

#endif