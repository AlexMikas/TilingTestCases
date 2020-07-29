#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 200L
#define T 150L

double A[2][N+2][N+2][N+2];

time_t start, end;

int main () {

	srand(time(NULL));
	
    long int t, i, j, k;
    const int BASE = 1024;

    printf("Number of points = %ld\t|Number of timesteps = %ld\t", N, T);

    /* Initialization */
    srand(42); // seed with a constant value to verify results

    for (i = 1; i < N+1; i++) {
        for (j = 1; j < N+1; j++) {
            for (k = 1; k < N+1; k++) {
                A[0][i][j][k] = 1.0 * (rand() % BASE);
            }
        }
    }

	start = clock();

	for (t = 0; t < T-1; t++) {
        for (i = 1; i < N+1; i++) {
            for (j = 1; j < N+1; j++) {
                for (k = 1; k < N+1; k++) {
                    A[(t+1)%2][i][j][k] =   0.125 * (A[(t)%2][i+1][j][k] - 2.0 * A[(t)%2][i][j][k] + A[(t)%2][i-1][j][k])
                                        + 0.125 * (A[(t)%2][i][j+1][k] - 2.0 * A[(t)%2][i][j][k] + A[(t)%2][i][j-1][k])
                                        + 0.125 * (A[(t)%2][i][j][k-1] - 2.0 * A[(t)%2][i][j][k] + A[(t)%2][i][j][k+1])
                                        + A[(t)%2][i][j][k];
                }
            }
        }
    }

	end = clock();
	printf("%.10f\n", (double)(end - start) / CLOCKS_PER_SEC); //seconds

	return 0;
}
