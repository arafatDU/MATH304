#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define EPSILON 10e-6
#define F(x) ((x)*(x)*(x) + 4*(x)*(x) - 5)
void bisection(double a, double b);

int main(){
	double a=-5, b =5, h;
	//if(F(a)*F(b) > 0) exit(0);
	h = (fabs(a) + fabs(b))/(3*2);
	
	for(int j=0; j<6; j++){
		b = a + h;
		printf("a = %10.6lf  b = %10.6lf\n", a, b);
		bisection(a, b);
		a = b;
	}
	
	return 0;
}




void bisection(double a, double b){
	int n = 100, i;
	double c;
	for(i = 1; i<n; i++){
		c = (a+b)/2;
		//printf("%3d %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf\n", i, a, b, c, F(a), F(b), F(c));
		if(fabs(F(c))<EPSILON) {
			printf("Root = %lf\n", c); break;
		}
		if(F(a)*F(c)<0) b = c;
		else a = c;
	}
}
