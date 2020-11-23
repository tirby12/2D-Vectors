#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>


int sum;
#define M 3
#define K 2
#define N 3

int A[M][K]={ {1,4}, {2,5},{3,6}};
int B[K][N]={ {8,7,6},{5,4,3}};
int C[M][N];

typedef struct {
int i;
int j;
} ij_values;

void *worker(void *param);
int main()
{
// Arrays to store information about each thread.

	pthread_t workers[N*M];
	pthread_attr_t attr[N*M];
// TODO: Create a thread for calculating each element
// of matrix C.
// Wait for each thread to complete.

	for (int i = 0; i < N*M; i++)
	{
		pthread_join(workers[i], NULL);
	}
	printf("the array C is: %d" ,C[M][N]);


	return 1;
}
void *worker(void *param)
{
	int i,j,h;
	int total=0;
	for(i=0;i<3;i++)
	{ 
		for(h=0;h<3;h++)
		{
			total=0;
			for(j=0;j<2;j++)
			{
				total += A[i][j] * B[j][i];
			}
		C[h][i]= total;
		}
	}
}


