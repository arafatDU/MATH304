#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define EPSILON 10e-6
#define F(x) ((x)*(x)*(x) + 4*(x)*(x) - 10)
int main(){
	int n=100, i;
	double x0=1.25, x1 =1.5, x2;
	if(F(x0)*F(x1) > 0) exit(0);
	printf("-------------------------------------------------------------------------\n");
	printf("Iter     x0          x1        x2       f(x0)      f(x1)     f(x2)\n");
	printf("-------------------------------------------------------------------------\n");
	for(i = 1; i<n; i++){
		x2 = ( x1*F(x0) - x0*F(x1) )/( F(x0) - F(x1) );
		printf("%3d %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf\n", i, x0, x1, x2, F(x0), F(x1), F(x2));
		if(fabs(F(x2))<EPSILON) {
			printf("-------------------------------------------------------------------------\n");
			printf("Root = %lf\n", x2); exit(0);
		}
		if(F(x0)*F(x2)<0) x1 = x2;
		else x0 = x2;
	}
	
	return 0;
}
