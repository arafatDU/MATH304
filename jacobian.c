#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#define EPS .0001;

double mat[3][4]={
    {20,1,-2,17},
    {3,20,-1,-18},
    {2,-3,20,25}
};
double initial[3]={0,0,0};
double x[3];

bool Dominant()
{
    int x=0;
    for(int i =0;i<3;i++)
    {
        for(int j=0;j<3;j++){

            if(i!=j){
                x=x+fabs(mat[i][j]);
            }
        }
        if(fabs(mat[i][i])> x)
        return true;
    }
}

void jacobian()
{
    bool flag = true;
    int iteration = 0;

    while (flag)
    {
        flag = false; 

        for (int i = 0; i < 3; i++)
        {
            double sum = 0;

            for (int j = 0; j < 3; j++)
            {
                if (i != j)
                {
                    sum += mat[i][j] * initial[j];
                }
            }

            x[i] =  (mat[i][3] - sum)/mat[i][i];

            if (fabs(x[i] - initial[i]) > .0001) 
            {
                flag = true;
            }

            initial[i] = x[i]; 
        }

        iteration++;
    }


   

    
    printf("Solution after %d iterations \n", iteration);
    for (int i = 0; i < 3; i++)
    {
        printf("x[%d] = %lf\n", i, x[i]);
    }
}



int main()
{
    if(Dominant()){
        jacobian();
    }else
    printf("not dominant ");

    return 0;
}





	

