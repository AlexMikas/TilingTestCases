#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define K 256
#define N 4000+2
#define M 4000+2

double u[N][M];

time_t start, end;

int main () {
	srand(time(NULL));
	
	for (int i = 0; i < N; ++i ){
		for (int j = 0; j < M; ++j ){
			u[i][j] = (double)rand()/(double)(RAND_MAX);
		}	 
	}

	start = clock();

	for (int k = 0; k < K; ++k ) // K – кол-во итераций
		for (int i = 1; i < N - 1; ++i )
			for (int j = 1; j < M - 1; ++j )
				u[i][j] = ( u[i-1][j] + u[i + 1][j] + u[i][j-1] + u[i][j + 1] ) / 4.0;

	end = clock();
	printf("%.10f\n", (double)(end - start) / CLOCKS_PER_SEC); //seconds

	return 0;
}
