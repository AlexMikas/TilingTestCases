#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 2000L
#define T 64L

double A[2][N+2][N+2];

time_t start, end;

int main () {

	srand(time(NULL));
	
    long int t, i, j;
    const int BASE = 1024;

    /* Initialization */
    srand(42); // seed with a constant value to verify results

    for (i = 1; i < N+1; i++) {
        for (j = 1; j < N+1; j++) {
            A[0][i][j] = 1.0 * (rand() % BASE);
        }
    }

	start = clock();

	for (t = 0; t < T*2; t++) {
        for (i = 1; i < N+1; i++) {
            for (j = 1; j < N+1; j++) {
                A[(t+1)%2][i][j] =   0.125 * (A[(t)%2][i+1][j] - 2.0 * A[(t)%2][i][j] + A[(t)%2][i-1][j])
                                 + 0.125 * (A[(t)%2][i][j+1] - 2.0 * A[(t)%2][i][j] + A[(t)%2][i][j-1])
                                 + A[(t)%2][i][j];
            }
        }
    }

	end = clock();
	printf("%.10f\n", (double)(end - start) / CLOCKS_PER_SEC); //seconds

	return 0;
}
