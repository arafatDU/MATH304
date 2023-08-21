#include<stdio.h>
#include<math.h>
#define PI 3.1415

int main()
{
	int n = 100;
	double a = 0, b = 2*PI, h, x;
	h = (b - a)/n;
	printf("\"X\",\"sin(x)\"\n");
	x = a;
	printf("%lf,%lf\n", x,sin(x));

	for(int i=0; i<n; i++) 
	{
		x += h;
		printf("%lf,%lf\n", x, sin(x));
	}	

	x = b;
	printf("%lf,%lf\n",x, sin(x));
	printf("The End\n");

	return 0;
}
