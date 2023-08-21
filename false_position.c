#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define EPSILON 10e-6
#define F(x) ((x)*(x)*(x) + 4*(x)*(x) - 10)
int main(){
	int n=100, i;
	double a=1.25, b =1.5, c;
	if(F(a)*F(b) > 0) exit(0);
	printf("-------------------------------------------------------------------------\n");
	printf("Iter     a           b          c        f(a)       f(b)      f(c)\n");
	printf("-------------------------------------------------------------------------\n");
	for(i = 1; i<n; i++){
		c = ( b*F(a) - a*F(b) )/( F(a) - F(b) );
		printf("%3d %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf\n", i, a, b, c, F(a), F(b), F(c));
		if(fabs(F(c))<EPSILON) {
			printf("-------------------------------------------------------------------------\n");
			printf("Root = %lf\n", c); exit(0);
		}
		if(F(a)*F(c)<0) b = c;
		else a = c;
	}
	
	return 0;
}















/*

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

#define f(x) (x*x - 5*x + 6)
#define EPSILON 10e-7

double a, b, c;

void __init__bounds__(double x, double y);
bool existsRoot(double x, double y);
void falseMethod();

int main(){
	
	printf("Enter two bound values:");
	scanf("%lf %lf", &a, &b);
	
	__init__bounds__(a,b);
	
	printf("a: %lf b: %lf\n", a, b);
	
	// f(3.0) = 0.0 < 0.0005 
	
	
	if(!existsRoot(a,b)){
		printf("Root doesn't exist!\n");
		exit(0);
	} 
	else{
		falseMethod();
	}
	
	
}


void __init__bounds__(double x, double y){
	a = x;
	b = y;
}

bool existsRoot(double x, double y){
	//printf("f(a): %lf f(b): %lf\n", f(x), f(y));
	return f(x) * f(y) <= 0; 
}

void falseMethod(){
	
	c = ( b*f(a) - a*f(b) )/( f(a) - f(b) ); // c = 0+3.5/2 = 1.75
	//printf("c: %lf\n", c);
	
	if(fabs(f(c)) < EPSILON){
		printf("Root: %.2lf\n", c);
		return;
	} 
	else{
		if(existsRoot(a,c)){
			b = c;
			falseMethod();
		}else{
			a = c;
			falseMethod();
		}
	} 
	
	
}
*/
