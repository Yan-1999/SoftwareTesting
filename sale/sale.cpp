#include "sale.h"

Sale::Result Sale::solve(int a, int b, int c)
{
	if (a > 70 || b > 80 || c > 90 || a < 1 || b < 1 || c < 1)
		return -1;
	int sum = a * 25 + b * 30 + 45 * c;
	if (sum <= 1000)
		return sum * 0.1;
	else if (sum <= 1800)
		return sum * 0.15;
	else
		return sum * 0.2;
}