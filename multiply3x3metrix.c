#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
 	int i,j,k;
 	int a[3][3], b[3][3], mul[3][3];
 	clock_t start, end;

	srand(time(0));
	for(i=0; i< 3; i++)
	{
		for(j=0; j<3; j++)
		{
			a[i][j] = rand() % 10 + 1;
			b[i][j] = rand() % 10 + 1;
			mul[i][j] = 0;
		}
	}
	
	
	printf("First matrix:\n");
	for(i=0;i< 3;i++)
	{
 		for(j=0;j< 3;j++)
  		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	
	printf("Second matrix:\n");
	for(i=0;i< 3;i++)
	{
 		for(j=0;j< 3;j++)
  		{
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	
	
/*	printf("Enter elements of first matrix:\n");
	for(i=0;i< 3;i++)
	{
 		for(j=0;j< 3;j++)
  		{
			//printf("a[%d][%d]=",i,j);
			//scanf("%d", &a[i][j]);
			a[i][j] = rand() % 10 + 1;
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
 
	printf("Enter elements of second matrix:\n");
	for(i=0;i< 3;i++)
	{
		for(j=0;j< 3;j++)
		{
			//printf("b[%d][%d]=",i,j);
			//scanf("%d", &b[i][j]);
			b[i][j] = rand() % 10 + 1;
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
*/
 	start = clock();
 
	for(i=0;i< 3;i++)
	{
		for(j=0;j< 3;j++)
		{
			// mul[i][j] = 0
			for(k=0;k< 3;k++)
			{
				mul[i][j] += a[i][k]*b[k][j];
   			}
  		}
 	}
	end = clock(); 	
	double duration = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Time taken to execute in seconds : %lf\n", duration);

 
	printf("Multiplied matrix is:\n");
	for(i=0;i< 3;i++)
	{
		for(j=0;j< 3;j++)
		{
			printf("%d\t", mul[i][j]);
  		}
  		printf("\n");
 	}
 	return 0;
}

