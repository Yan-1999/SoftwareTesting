#pragma once
#ifndef SALE_H
#define SALE_H

class Sale
{
public:
    class Result
    {
    public:
        double val;

        Result(double value) : val(value) {}
    };

    Result solve(int a, int b, int c);
};

#endif // !SALE_H
