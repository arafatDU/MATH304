#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define NMAX 4
#define EPS 10e-6

int main()
{	
	int i, j, k, ip, jp;
	double mij, temp;
	double x[NMAX][NMAX +1] = { {1, -1, 2, -1, -8}, {2, -2, 3, -3, -20}, {1, 1, 1, 0, -2}, {1, -1, 4, 3, 4} };
	
	for(i = 0; i<NMAX; i++)
	{
		for(j= 0; j< NMAX+1; j++)
		{
			if(j==0 || j == 4) printf(" | ");
			printf("%7.2lf ", x[i][j]);
		}
		printf("|\n");
	}
	
	
	/*
	for(i=0; i<NMAX -1; i++)
	{
		if( fabs(x[i][i] < EPS))
		{
			for(j=i+1; j< NMAX; j++) 
			{
				if(fabs(x[j][i]) > EPS)
				{
					for(k = i; k< NMAX+1; k++)
					{
						temp = x[i][k];
						x[i][k] = x[j][k];
						x[j][k] = temp;
					}
					break;
				}
			}
		}
		
		for(i=0; i<NMAX-1; i++)
		{
			for(j=i+1; j< NMAX; j++)
			{
				mij = x[j][i]/x[i][i];
				for(k=i; k<NMAX+1; k++)
				{
					x[i][k] = x[j][k] - mij*x[i][k];
				}
			}
			
			printf("Round= %d\n", i+1);
			for(ip=0; ip<NMAX; ip++)
			{
				for(jp=0; jp<NMAX +1; jp++)
				{
					if(jp==0 || jp == NMAX) printf(" | ");
					printf("%7.2lf ", x[ip][jp]);	
				}
				printf("|\n");
			}
		}
	}
	*/
	
	for(i=NMAX-1; i>0; i--)
		{
			for(j=i-1; j>0; j--)
			{
				mij = x[j][i]/x[i][i];
				for(k=i; k<NMAX+1; k++)
				{
					x[i][k] = x[j][k] - mij*x[i][k];
				}
			}
			
			printf("Round= %d\n", i+1);
			for(ip=0; ip<NMAX; ip++)
			{
				for(jp=0; jp<NMAX +1; jp++)
				{
					if(jp==0 || jp == NMAX) printf(" | ");
					printf("%7.2lf ", x[ip][jp]);	
				}
				printf("|\n");
			}
		}
	
	
	

	return 0;
}
