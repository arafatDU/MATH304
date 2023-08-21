#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

#define f(x) (x*x - 5*x + 6)
#define EPSILON 10e-6

double a, b, c;

void initBounds(double x, double y);
bool existsRoot(double x, double y);
void bisectionMethod();

int main(){
	
	printf("Enter two bound values:");
	scanf("%lf %lf", &a, &b);
	
	initBounds(a,b);
	
	printf("a: %lf b: %lf\n", a, b);
	
	// f(3.0) = 0.0 < 0.0005 
	
	/*if( f(b) == 0.00){
		printf("f(b): %lf\tRoot: %lf\n",f(b), b);
		exit(0);
	}*/
	
	if(!existsRoot(a,b)){
		printf("Root doesn't exist!\n");
		exit(0);
	} 
	else{
		bisectionMethod();
	}
	
	
}


void initBounds(double x, double y){ 
	a = x;
	b = y;
	
	//*(&a) = x;
	//*(&b) = y; 
}

bool existsRoot(double x, double y){
	//printf("f(a): %lf f(b): %lf\n", f(x), f(y));
	return f(x) * f(y) <= 0; 
}

void bisectionMethod(){
	
	c = (a+b)/2; // c = 0+3.5/2 = 1.75
	//printf("c: %lf\n", c);
	
	if(fabs(f(c))<= EPSILON){
		printf("Root: %lf\n", c);
		return;
	} 
	else{
		if(existsRoot(a,c)){
			b = c;
			bisectionMethod();
		}else{
			a = c;
			bisectionMethod();
		}
	} 
	
	
}







/*
#define F(x) ((x)*(x)*(x) + 4*(x)*(x) - 10)
int main(){
	int n=100, i;
	double a=1.25, b =1.5, c;
	if(F(a)*F(b) > 0) exit(0);
	printf("---------------------------------------------------------\n");
	printf("Iter  a    b   c   f(a)   f(b)     f(c)\n");
	printf("---------------------------------------------------------\n");
	for(i = 1; i<n; i++){
		c = (a+b)/2;
		printf("%3d %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf\n", i, a, b, c, F(a), F(b), F(c));
		if(fabs(F(c))<EPSILON) {
			printf("Root = %lf\n", c); exit(0);
		}
		if(F(a)*F(c)<0) b = c;
		else a = c;
	}
}
*/

