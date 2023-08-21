#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define EPSILON 10e-6
#define F(x) ((x)*(x)*(x) + 4*(x)*(x) - 10)
#define g(X) sqrt((10 - (X)*(X)*(X))/4)
int main(){
	int n=100, i;
	double x0=1.25, x1;
	//if(F(x0)*F(x1) > 0) exit(0);
	printf("-------------------------------------------------------------------------\n");
	printf("Iter     x0          x1        g(x0)       f(x1)      \n");
	printf("-------------------------------------------------------------------------\n");
	for(i = 1; i<n; i++){
		x1 = g(x0);
		printf("%3d %10.6lf %10.6lf %10.6lf %10.6lf\n", i, x0, x1, g(x0), F(x1));
		if(fabs(F(x1))<EPSILON) {
			printf("-------------------------------------------------------------------------\n");
			printf("Root = %lf\n", x1); exit(0);
		}
		//if(F(x0)*F(x2)<0) x1 = g(x0);
		else x0 = x1;
	}
	
	return 0;
}
