#include "triangle.h"

void tri_sort(long &a, long &b, long &c) {
    long tmp;
    if (a > b) {
        tmp = a;
        a = b;
        b = tmp;
    }

    if (a > c) {
        tmp = a;
        a = c;
        c = tmp;
    }

    if (b > c) {
        tmp = b;
        b = c;
        c = tmp;
    }
}

Triangle::Type Triangle::solve(int a, int b, int c) {
    long a0 = a, b0 = b, c0 = c;
    tri_sort(a0, b0, c0);
    if (a0 <= 0 || a0 + b0 <= c0)
        return Type::NON;
    else if (a0 == c0)
        return Type::EQUILATERAL;
    else if (a0 == b0 || b0 == c0)
        return Type::ISOSCELES;
    else
        return Type::SCALENE;
}