// test
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <math.h>


#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#define N 40L
#define T 32L

double A[2][N+2][N+2];
double A_t[2][N+2][N+2];

//double u[N][M];

time_t start, end;
/*
void src(int** u)
{
	for (int k = 0; k < K; ++k ) // K – кол-во итераций
		for (int i = 1; i < N - 1; ++i )
			for (int j = 1; j < M - 1; ++j )
				u[i][j] = ( u[i-1][j] + u[i + 1][j] + u[i][j-1] + u[i][j + 1] ) / 4.0;
}
*/
/*
void transf(int** u)
{
	// Размеры блоков
	int d1=4, d2=4, d3=4; 
	// Количество потоков
	int thread_count = 6;

	{
    int j;
    int __uni258j;
    {
      int k;
      int i;
      int __uni259__uni258j;
      int __uni260__uni259__uni258j;
      int __uni261i;
      int __uni262k;
      int __uni272__uni269__uni260__uni259__uni258j;
      for (__uni272__uni269__uni260__uni259__uni258j = (0 + 0 * 1) + 0 * 1; __uni272__uni269__uni260__uni259__uni258j < ((((((((((N - 1) - 1) + (K - 0) * 1) - 1) - 1) + (((N - 1) - 1) - 0) * 1) - 1) - 1) / d3 + 1) + (((N - 1) - 1) / d2 - 1) * 1) + (K / d1 - 1) * 1; __uni272__uni269__uni260__uni259__uni258j = __uni272__uni269__uni260__uni259__uni258j + 1)
      {
        int __uni269__uni260__uni259__uni258j;
        int __uni273__uni262k;
        int __uni274__uni262k;
        if (0 > ((__uni272__uni269__uni260__uni259__uni258j - ((((((((((N - 1) - 1) + (K - 0) * 1) - 1) - 1) + (((N - 1) - 1) - 0) * 1) - 1) - 1) / d3 + 1) + (((N - 1) - 1) / d2 - 1) * 1)) + 1) / 1)
        {
          __uni273__uni262k = 0;
        }
        else
        {
          __uni273__uni262k = ((__uni272__uni269__uni260__uni259__uni258j - ((((((((((N - 1) - 1) + (K - 0) * 1) - 1) - 1) + (((N - 1) - 1) - 0) * 1) - 1) - 1) / d3 + 1) + (((N - 1) - 1) / d2 - 1) * 1)) + 1) / 1;
        }
        if (K / d1 < ((__uni272__uni269__uni260__uni259__uni258j - 0) + 1) / 1)
        {
          __uni274__uni262k = K / d1;
        }
        else
        {
          __uni274__uni262k = ((__uni272__uni269__uni260__uni259__uni258j - 0) + 1) / 1;
        }

        #pragma omp parallel num_threads(thread_count) private (i, j, k, __uni258j, __uni259__uni258j, __uni260__uni259__uni258j, __uni261i, __uni262k) firstprivate( __uni272__uni269__uni260__uni259__uni258j)
        
        for (__uni262k = __uni273__uni262k; __uni262k < __uni274__uni262k; __uni262k = __uni262k + 1)
        {
          int __uni270__uni261i;
          int __uni271__uni261i;
          __uni269__uni260__uni259__uni258j = __uni272__uni269__uni260__uni259__uni258j - __uni262k * 1;
          if (0 > ((__uni269__uni260__uni259__uni258j - (((((((((N - 1) - 1) + (K - 0) * 1) - 1) - 1) + (((N - 1) - 1) - 0) * 1) - 1) - 1) / d3 + 1)) + 1) / 1)
          {
            __uni270__uni261i = 0;
          }
          else
          {
            __uni270__uni261i = ((__uni269__uni260__uni259__uni258j - (((((((((N - 1) - 1) + (K - 0) * 1) - 1) - 1) + (((N - 1) - 1) - 0) * 1) - 1) - 1) / d3 + 1)) + 1) / 1;
          }
          if (((N - 1) - 1) / d2 < ((__uni269__uni260__uni259__uni258j - 0) + 1) / 1)
          {
            __uni271__uni261i = ((N - 1) - 1) / d2;
          }
          else
          {
            __uni271__uni261i = ((__uni269__uni260__uni259__uni258j - 0) + 1) / 1;
          }

          #pragma omp for 

          for (__uni261i = __uni270__uni261i; __uni261i < __uni271__uni261i; __uni261i = __uni261i + 1)
          {
            int __uni263__uni259__uni258j;
            int __uni264__uni259__uni258j;
            __uni260__uni259__uni258j = __uni269__uni260__uni259__uni258j - __uni261i * 1;
            if ((0 + (__uni262k * d1) * 1) + (__uni261i * d2) * 1 > __uni260__uni259__uni258j * d3)
            {
              __uni263__uni259__uni258j = (0 + (__uni262k * d1) * 1) + (__uni261i * d2) * 1;
            }
            else
            {
              __uni263__uni259__uni258j = __uni260__uni259__uni258j * d3;
            }
            if (((((N - 1) - 1) - 0) + ((__uni262k + 1) * d1) * 1) + ((__uni261i + 1) * d2) * 1 < (__uni260__uni259__uni258j + 1) * d3)
            {
              __uni264__uni259__uni258j = ((((N - 1) - 1) - 0) + ((__uni262k + 1) * d1) * 1) + ((__uni261i + 1) * d2) * 1;
            }
            else
            {
              __uni264__uni259__uni258j = (__uni260__uni259__uni258j + 1) * d3;
            }
            for (__uni259__uni258j = __uni263__uni259__uni258j; __uni259__uni258j < __uni264__uni259__uni258j; __uni259__uni258j = __uni259__uni258j + 1)
            {
              int __uni265__uni259__uni258j;
              int __uni266__uni259__uni258j;
              if (__uni262k * d1 > ((__uni259__uni258j - (((N - 1) - 1) - 0)) + 1) / 1 - (__uni261i + 1) * d2)
              {
                __uni265__uni259__uni258j = __uni262k * d1;
              }
              else
              {
                __uni265__uni259__uni258j = ((__uni259__uni258j - (((N - 1) - 1) - 0)) + 1) / 1 - (__uni261i + 1) * d2;
              }
              if ((__uni262k + 1) * d1 < (__uni259__uni258j + 1) / 1)
              {
                __uni266__uni259__uni258j = (__uni262k + 1) * d1;
              }
              else
              {
                __uni266__uni259__uni258j = (__uni259__uni258j + 1) / 1;
              }
              for (k = __uni265__uni259__uni258j; k < __uni266__uni259__uni258j; k = k + 1)
              {
                int __uni267__uni259__uni258j;
                int __uni268__uni259__uni258j;
                __uni258j = __uni259__uni258j - k * 1;
                if (__uni261i * d2 > ((__uni258j - (((N - 1) - 1) - 0)) + 1) / 1)
                {
                  __uni267__uni259__uni258j = __uni261i * d2;
                }
                else
                {
                  __uni267__uni259__uni258j = ((__uni258j - (((N - 1) - 1) - 0)) + 1) / 1;
                }
                if ((__uni261i + 1) * d2 < (__uni258j + 1) / 1)
                {
                  __uni268__uni259__uni258j = (__uni261i + 1) * d2;
                }
                else
                {
                  __uni268__uni259__uni258j = (__uni258j + 1) / 1;
                }
                for (i = __uni267__uni259__uni258j; i < __uni268__uni259__uni258j; i = i + 1)
                {
                  j = __uni258j - i * 1;
                  u[(1 + i)][(1 + j)] = (((u[((1 + i) - 1)][(1 + j)] + u[((1 + i) + 1)][(1 + j)]) + u[(1 + i)][((1 + j) - 1)]) + u[(1 + i)][((1 + j) + 1)]) / 4.;
                  //x[k][i][j]+=1;
                }
              }
            }
          }
        }
      }
    }
  }
}
*/

int main () {	
  //srand(time(NULL));
  srand(42);

	
  const int BASE = 2;
  for (int i = 0; i < N+2; ++i ){
		for (int j = 0; j < N+2; ++j ){
			A[0][i][j] = 0;
			A_t[0][i][j] = 0;
		}	 
	}
    for (int i = 1; i < N+1; i++) {
        for (int j = 1; j < N+1; j++) {
            A[0][i][j] = 1.0 * (rand() % BASE);
            A_t[0][i][j] = A[0][i][j];
        }
    }

	printf(">>>>>>>>>>>>>>>>>>");
{
  long int t, i, j;
	for (t = 0; t < T*2; t++) {
        for (i = 1; i < N+1; i++) {
            for (j = 1; j < N+1; j++) {
                A[(t+1)%2][i][j] =   0.125 * (A[(t)%2][i+1][j] - 2.0 * A[(t)%2][i][j] + A[(t)%2][i-1][j])
                                 + 0.125 * (A[(t)%2][i][j+1] - 2.0 * A[(t)%2][i][j] + A[(t)%2][i][j-1])
                                 + A[(t)%2][i][j];
            }
        }
    }
}			
	printf(">>>>>>>>>>>>>>>>>>");
	// Размеры блоков
	int d1=2, d2=4, d3=4; 
	// Количество потоков
	int thread_count = 6;

{
    int i;
    int j;
    int __uni0j;
    {
      int t;
      int __uni1__uni0j;
      int __uni2i;
      int __uni3__uni1__uni0j;
      int __uni4__uni2i;
      int __uni5t;
      int __uni17__uni14__uni3__uni1__uni0j;
      for (__uni17__uni14__uni3__uni1__uni0j = (0 + 0 * 1) + 0 * 1; __uni17__uni14__uni3__uni1__uni0j < (((((((((N + 1) - 1) + ((((N + 1) - 1) + (T * 2) * 1) - (T * 2) * 1) * 1) + (T * 2) * 1) - 1) - 1) - 1) / d3 + 1) + (((((((N + 1) - 1) + (T * 2) * 1) - 1) - 1) / d2 + 1) - 1) * 1) + ((T * 2) / d1 - 1) * 1; __uni17__uni14__uni3__uni1__uni0j = __uni17__uni14__uni3__uni1__uni0j + 1)
      {
        int __uni14__uni3__uni1__uni0j;
        int __uni18__uni5t;
        int __uni19__uni5t;
        if (0 > ((__uni17__uni14__uni3__uni1__uni0j - (((((((((N + 1) - 1) + ((((N + 1) - 1) + (T * 2) * 1) - (T * 2) * 1) * 1) + (T * 2) * 1) - 1) - 1) - 1) / d3 + 1) + (((((((N + 1) - 1) + (T * 2) * 1) - 1) - 1) / d2 + 1) - 1) * 1)) + 1) / 1)
        {
          __uni18__uni5t = 0;
        }
        else
        {
          __uni18__uni5t = ((__uni17__uni14__uni3__uni1__uni0j - (((((((((N + 1) - 1) + ((((N + 1) - 1) + (T * 2) * 1) - (T * 2) * 1) * 1) + (T * 2) * 1) - 1) - 1) - 1) / d3 + 1) + (((((((N + 1) - 1) + (T * 2) * 1) - 1) - 1) / d2 + 1) - 1) * 1)) + 1) / 1;
        }
        if ((T * 2) / d1 < ((__uni17__uni14__uni3__uni1__uni0j - 0) + 1) / 1)
        {
          __uni19__uni5t = (T * 2) / d1;
        }
        else
        {
          __uni19__uni5t = ((__uni17__uni14__uni3__uni1__uni0j - 0) + 1) / 1;
        }
        for (__uni5t = __uni18__uni5t; __uni5t < __uni19__uni5t; __uni5t = __uni5t + 1)
        {
          int __uni15__uni4__uni2i;
          int __uni16__uni4__uni2i;
          __uni14__uni3__uni1__uni0j = __uni17__uni14__uni3__uni1__uni0j - __uni5t * 1;
          if (0 > ((__uni14__uni3__uni1__uni0j - ((((((((N + 1) - 1) + ((((N + 1) - 1) + (T * 2) * 1) - (T * 2) * 1) * 1) + (T * 2) * 1) - 1) - 1) - 1) / d3 + 1)) + 1) / 1)
          {
            __uni15__uni4__uni2i = 0;
          }
          else
          {
            __uni15__uni4__uni2i = ((__uni14__uni3__uni1__uni0j - ((((((((N + 1) - 1) + ((((N + 1) - 1) + (T * 2) * 1) - (T * 2) * 1) * 1) + (T * 2) * 1) - 1) - 1) - 1) / d3 + 1)) + 1) / 1;
          }
          if ((((((N + 1) - 1) + (T * 2) * 1) - 1) - 1) / d2 + 1 < ((__uni14__uni3__uni1__uni0j - 0) + 1) / 1)
          {
            __uni16__uni4__uni2i = (((((N + 1) - 1) + (T * 2) * 1) - 1) - 1) / d2 + 1;
          }
          else
          {
            __uni16__uni4__uni2i = ((__uni14__uni3__uni1__uni0j - 0) + 1) / 1;
          }
          for (__uni4__uni2i = __uni15__uni4__uni2i; __uni4__uni2i < __uni16__uni4__uni2i; __uni4__uni2i = __uni4__uni2i + 1)
          {
            int __uni8__uni1__uni0j;
            int __uni9__uni1__uni0j;
            __uni3__uni1__uni0j = __uni14__uni3__uni1__uni0j - __uni4__uni2i * 1;
            if ((0 + (__uni4__uni2i * d2 - (__uni5t * d1) * 1) * 1) + (__uni5t * d1) * 1 > __uni3__uni1__uni0j * d3)
            {
              __uni8__uni1__uni0j = (0 + (__uni4__uni2i * d2 - (__uni5t * d1) * 1) * 1) + (__uni5t * d1) * 1;
            }
            else
            {
              __uni8__uni1__uni0j = __uni3__uni1__uni0j * d3;
            }
            if ((((N + 1) - 1) + ((__uni4__uni2i + 1) * d2 - ((__uni5t + 1) * d1) * 1) * 1) + ((__uni5t + 1) * d1) * 1 < (__uni3__uni1__uni0j + 1) * d3)
            {
              __uni9__uni1__uni0j = (((N + 1) - 1) + ((__uni4__uni2i + 1) * d2 - ((__uni5t + 1) * d1) * 1) * 1) + ((__uni5t + 1) * d1) * 1;
            }
            else
            {
              __uni9__uni1__uni0j = (__uni3__uni1__uni0j + 1) * d3;
            }
            for (__uni1__uni0j = __uni8__uni1__uni0j; __uni1__uni0j < __uni9__uni1__uni0j; __uni1__uni0j = __uni1__uni0j + 1)
            {
              int __uni6__uni2i;
              int __uni7__uni2i;
              int __uni12t;
              int __uni13t;
              if ((__uni1__uni0j + 1) / 1 < (__uni5t + 1) * d1)
              {
                __uni13t = (__uni1__uni0j + 1) / 1;
              }
              else
              {
                __uni13t = (__uni5t + 1) * d1;
              }
              if ((((__uni1__uni0j - ((N + 1) - 1)) - (__uni4__uni2i + 1) * d2) + 1) / 1 > __uni5t * d1)
              {
                __uni12t = (((__uni1__uni0j - ((N + 1) - 1)) - (__uni4__uni2i + 1) * d2) + 1) / 1;
              }
              else
              {
                __uni12t = __uni5t * d1;
              }
              for (t = __uni12t; t < __uni13t; t = t + 1)
              {
                int __uni10__uni2i;
                int __uni11__uni2i;
                if (0 + t * 1 > __uni4__uni2i * d2)
                {
                  __uni6__uni2i = 0 + t * 1;
                }
                else
                {
                  __uni6__uni2i = __uni4__uni2i * d2;
                }
                if (((N + 1) - 1) + t * 1 < (__uni4__uni2i + 1) * d2)
                {
                  __uni7__uni2i = ((N + 1) - 1) + t * 1;
                }
                else
                {
                  __uni7__uni2i = (__uni4__uni2i + 1) * d2;
                }
                if ((__uni1__uni0j + 1) / 1 < __uni7__uni2i)
                {
                  __uni11__uni2i = (__uni1__uni0j + 1) / 1;
                }
                else
                {
                  __uni11__uni2i = __uni7__uni2i;
                }
                if ((((__uni1__uni0j - ((N + 1) - 1)) - 0) + 1) / 1 > __uni6__uni2i)
                {
                  __uni10__uni2i = (((__uni1__uni0j - ((N + 1) - 1)) - 0) + 1) / 1;
                }
                else
                {
                  __uni10__uni2i = __uni6__uni2i;
                }
                for (__uni2i = __uni10__uni2i; __uni2i < __uni11__uni2i; __uni2i = __uni2i + 1)
                {
                  i = __uni2i - t * 1;
                  __uni0j = __uni1__uni0j - t * 1;
                  j = __uni0j - i * 1;
                  A_t[((t + 1) % 2)][(1 + i)][(1 + j)] = (0.125 * ((A_t[(t % 2)][((1 + i) + 1)][(1 + j)] - 2. * A_t[(t % 2)][(1 + i)][(1 + j)]) + A_t[(t % 2)][((1 + i) - 1)][(1 + j)]) + 0.125 * ((A_t[(t % 2)][(1 + i)][((1 + j) + 1)] - 2. * A_t[(t % 2)][(1 + i)][(1 + j)]) + A_t[(t % 2)][(1 + i)][((1 + j) - 1)])) + A_t[(t % 2)][(1 + i)][(1 + j)];
                }
              }
            }
          }
        }
      }
    }
  }
  printf(">>>>>>>>>>>>>>>>>>");
for (int t = 0; t <= 1; t++)
	for (int i = 0; i < N+2; i ++){
		for (int j = 0; j < N+2; j++){
			if (A[t][i][j] != A_t[t][i][j])
				printf(">>> er %i %i %i src = %f, transf = %f -> %f\n",t, i,j, A[t][i][j], A_t[t][i][j],  A[t][i][j] - A_t[t][i][j]);
        printf("%f %f\n", A[t][i][j], A_t[t][i][j]);
		}
	}

	return 0;
}
