
#define N 5000L
#define T 32L

double A[2][N+2][N+2];


int main () {


	for (int t = 0; t < T*2; t++) 
        for (int i = 1; i < N+1; i++) 
            for (int j = 1; j < N+1; j++) 
                A[(t+1)%2][i][j] =   0.125 * (A[(t)%2][i+1][j] - 2.0 * A[(t)%2][i][j] + A[(t)%2][i-1][j])
                                 + 0.125 * (A[(t)%2][i][j+1] - 2.0 * A[(t)%2][i][j] + A[(t)%2][i][j-1])
                                 + A[(t)%2][i][j];


	return 0;
}
