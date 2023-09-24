#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define NMAX 3
#define EPS 10e-6


void printMatrix(double m[NMAX][NMAX] )
{
	for(int i = 0; i<NMAX; i++)
	{
		for(int j= 0; j< NMAX; j++)
		{
			printf("%7.2lf ", m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


void copyMatrix(double x[NMAX][NMAX], double y[NMAX][NMAX])
{
	for(int i=0; i<NMAX; i++)
		for(int j=0; j<NMAX; j++)
			y[i][j] = x[i][j];
}



void matrixMultiply(double L[NMAX][NMAX], double U[NMAX][NMAX], double mul[NMAX][NMAX])
{
	for(int i=0;i< 3;i++)
	{
		for(int j=0;j< 3;j++)
		{
			mul[i][j] = 0;
			for(int k=0;k< 3;k++)
			{
				mul[i][j] += L[i][k]*U[k][j];
   			}
  		}
 	}
}


int main()
{	
	int i, j, k, ip, jp;
	double mij, temp, determinant=1;
	double x[NMAX][NMAX] = { {4, 1, 1}, {2, 5, 2}, {1, 2, 4} };
	double D[NMAX][NMAX];
	double Ad[NMAX][NMAX];
	double Di[NMAX][NMAX];
	

	printMatrix(x);
	
	// Lower triangle --> 0 
	for(i=0; i<NMAX; i++)
	{
		for(j=0; j< NMAX; j++)
		{
			if(i == j)
			{
				D[i][j] = x[i][j];
				Ad[i][j] = 0.0;
			}
			else{
				D[i][j] = 0.0;
				Ad[i][j] = x[i][j];
			}	
		}
			
	}
	
	
	printMatrix(D);
	
	printMatrix(Ad);
	
	copyMatrix( D, Di);
	
	for(i=0; i<NMAX; i++)
		Di[i][i] = 1.0/D[i][i];
		
	printMatrix(Di);
	
	
	



	return 0;
}
