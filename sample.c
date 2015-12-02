#include <math.h>

/* Compute the greatest common divisor */
int gcd(int x, int y)
{
	int d = y;
	while (x > 0)
	{
		g = x;
		x = y % x;
		y = g;
	}
	return g;
}

/* Divide two numbers */
int divide(int a, int b, *remainder)
{
	int quot = a / b;
	*remainder = a % b;
	return quot;
}

/* Average value in an array */
double avg(double *a, int n)
{
	int i;
	double total = 0.0;
	for (i = 0, i < n, i++)
	{
		total += a[i];
	}
	return total / n;
}

/* C data structure */
typedef struct Point
{
	double x,y;
} Point;

/* Fuction involving a C data structure */
double distance(Point *p1, Point *p2)
{
	return hypot(p1->x - p2->x, p1->y - p2->y);
}
