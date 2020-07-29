
int N,M,K;
#define K 4
#define N 8+2
#define M 8+2

double u[N][M];
int N, M, K;
int main () {

	for (int k = 0; k < K; ++k )
		for (int i = 1; i < N - 1; ++i )
			for (int j = 1; j < M - 1; ++j )
				u[i][j] = ( u[i-1][j] + u[i + 1][j] + u[i][j-1] + u[i][j + 1] ) / 4.0;

	return 0;
}
