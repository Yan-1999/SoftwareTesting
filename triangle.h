#pragma once
#ifndef TRIANLGE_H
#define TRIANLGE_H

class Triangle {
public:
    enum class Type : char {
        NON = 0,
        SCALENE = 1,
        ISOSCELES = 2,
        EQUILATERAL = 3,
    };

    Type solve(int a, int b, int c);
};

#endif // !TRIANLGE_H
