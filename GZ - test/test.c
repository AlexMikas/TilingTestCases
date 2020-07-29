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

#define K 40
#define N 100+2
#define M 100+2

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
  srand(time(NULL));
  //srand(42);
	double u[N][M];
	double u_src[N][M];
	double u_transf[N][M];
	double u_transf1[N][M];
	
  const int BASE = 2;
  for (int i = 0; i < N; ++i ){
		for (int j = 0; j < M; ++j ){
			u_src[i][j] = 0;
			u_transf[i][j] = 0;
			u_transf1[i][j] = 0;
		}	 
	}

	for (int i = 0; i < N; ++i ){
		for (int j = 0; j < M; ++j ){
			u_src[i][j] = (double)rand()/(double)(RAND_MAX);  // 1.0 * (rand() % BASE);
			u_transf[i][j] = u_src[i][j];
			u_transf1[i][j] = u_src[i][j];
			u[i][j] = u_src[i][j];
		}	 
	}
	printf(">>>>>>>>>>>>>>>>>>");
{
	for (int k = 0; k < K; ++k ) // K – кол-во итераций
		for (int i = 1; i < N - 1; ++i )
			for (int j = 1; j < M - 1; ++j )
				u_src[i][j] = ( u_src[i-1][j] + u_src[i + 1][j] + u_src[i][j-1] + u_src[i][j + 1] )/4.0;
}			
	printf(">>>>>>>>>>>>>>>>>>");
	// Размеры блоков
	int d1=2, d2=4, d3=4; 
	// Количество потоков
	int thread_count = 6;

{
    int i;
    int j;
    int __uni28j;
    {
      int k;
      int __uni29__uni28j;
      int __uni30i;
      int __uni31__uni29__uni28j;
      int __uni32__uni30i;
      int __uni33k;
      int __uni45__uni42__uni31__uni29__uni28j;
      for (__uni45__uni42__uni31__uni29__uni28j = (0 + 0 * 1) + 0 * 1; __uni45__uni42__uni31__uni29__uni28j < (((((((((M - 1) - 1) + ((((N - 1) - 1) + K * 1) - K * 1) * 1) + K * 1) - 1) - 1) - 1) / d3 + 1) + (((((((N - 1) - 1) + K * 1) - 1) - 1) / d2 + 1) - 1) * 1) + (K / d1 - 1) * 1; __uni45__uni42__uni31__uni29__uni28j = __uni45__uni42__uni31__uni29__uni28j + 1)
      {
        int __uni42__uni31__uni29__uni28j;
        int __uni46__uni33k;
        int __uni47__uni33k;
        if (0 > ((__uni45__uni42__uni31__uni29__uni28j - (((((((((M - 1) - 1) + ((((N - 1) - 1) + K * 1) - K * 1) * 1) + K * 1) - 1) - 1) - 1) / d3 + 1) + (((((((N - 1) - 1) + K * 1) - 1) - 1) / d2 + 1) - 1) * 1)) + 1) / 1)
        {
          __uni46__uni33k = 0;
        }
        else
        {
          __uni46__uni33k = ((__uni45__uni42__uni31__uni29__uni28j - (((((((((M - 1) - 1) + ((((N - 1) - 1) + K * 1) - K * 1) * 1) + K * 1) - 1) - 1) - 1) / d3 + 1) + (((((((N - 1) - 1) + K * 1) - 1) - 1) / d2 + 1) - 1) * 1)) + 1) / 1;
        }
        if (K / d1 < ((__uni45__uni42__uni31__uni29__uni28j - 0) + 1) / 1)
        {
          __uni47__uni33k = K / d1;
        }
        else
        {
          __uni47__uni33k = ((__uni45__uni42__uni31__uni29__uni28j - 0) + 1) / 1;
        }
        for (__uni33k = __uni46__uni33k; __uni33k < __uni47__uni33k; __uni33k = __uni33k + 1)
        {
          int __uni43__uni32__uni30i;
          int __uni44__uni32__uni30i;
          __uni42__uni31__uni29__uni28j = __uni45__uni42__uni31__uni29__uni28j - __uni33k * 1;
          if (0 > ((__uni42__uni31__uni29__uni28j - ((((((((M - 1) - 1) + ((((N - 1) - 1) + K * 1) - K * 1) * 1) + K * 1) - 1) - 1) - 1) / d3 + 1)) + 1) / 1)
          {
            __uni43__uni32__uni30i = 0;
          }
          else
          {
            __uni43__uni32__uni30i = ((__uni42__uni31__uni29__uni28j - ((((((((M - 1) - 1) + ((((N - 1) - 1) + K * 1) - K * 1) * 1) + K * 1) - 1) - 1) - 1) / d3 + 1)) + 1) / 1;
          }
          if ((((((N - 1) - 1) + K * 1) - 1) - 1) / d2 + 1 < ((__uni42__uni31__uni29__uni28j - 0) + 1) / 1)
          {
            __uni44__uni32__uni30i = (((((N - 1) - 1) + K * 1) - 1) - 1) / d2 + 1;
          }
          else
          {
            __uni44__uni32__uni30i = ((__uni42__uni31__uni29__uni28j - 0) + 1) / 1;
          }
          for (__uni32__uni30i = __uni43__uni32__uni30i; __uni32__uni30i < __uni44__uni32__uni30i; __uni32__uni30i = __uni32__uni30i + 1)
          {
            int __uni36__uni29__uni28j;
            int __uni37__uni29__uni28j;
            __uni31__uni29__uni28j = __uni42__uni31__uni29__uni28j - __uni32__uni30i * 1;
            if ((0 + (__uni32__uni30i * d2 - (__uni33k * d1) * 1) * 1) + (__uni33k * d1) * 1 > __uni31__uni29__uni28j * d3)
            {
              __uni36__uni29__uni28j = (0 + (__uni32__uni30i * d2 - (__uni33k * d1) * 1) * 1) + (__uni33k * d1) * 1;
            }
            else
            {
              __uni36__uni29__uni28j = __uni31__uni29__uni28j * d3;
            }
            if ((((M - 1) - 1) + ((__uni32__uni30i + 1) * d2 - ((__uni33k + 1) * d1) * 1) * 1) + ((__uni33k + 1) * d1) * 1 < (__uni31__uni29__uni28j + 1) * d3)
            {
              __uni37__uni29__uni28j = (((M - 1) - 1) + ((__uni32__uni30i + 1) * d2 - ((__uni33k + 1) * d1) * 1) * 1) + ((__uni33k + 1) * d1) * 1;
            }
            else
            {
              __uni37__uni29__uni28j = (__uni31__uni29__uni28j + 1) * d3;
            }
            for (__uni29__uni28j = __uni36__uni29__uni28j; __uni29__uni28j < __uni37__uni29__uni28j; __uni29__uni28j = __uni29__uni28j + 1)
            {
              int __uni34__uni30i;
              int __uni35__uni30i;
              int __uni40k;
              int __uni41k;
              if ((__uni29__uni28j + 1) / 1 < (__uni33k + 1) * d1)
              {
                __uni41k = (__uni29__uni28j + 1) / 1;
              }
              else
              {
                __uni41k = (__uni33k + 1) * d1;
              }
              if ((((__uni29__uni28j - ((M - 1) - 1)) - (__uni32__uni30i + 1) * d2) + 1) / 1 > __uni33k * d1)
              {
                __uni40k = (((__uni29__uni28j - ((M - 1) - 1)) - (__uni32__uni30i + 1) * d2) + 1) / 1;
              }
              else
              {
                __uni40k = __uni33k * d1;
              }
              for (k = __uni40k; k < __uni41k; k = k + 1)
              {
                int __uni38__uni30i;
                int __uni39__uni30i;
                if (0 + k * 1 > __uni32__uni30i * d2)
                {
                  __uni34__uni30i = 0 + k * 1;
                }
                else
                {
                  __uni34__uni30i = __uni32__uni30i * d2;
                }
                if (((N - 1) - 1) + k * 1 < (__uni32__uni30i + 1) * d2)
                {
                  __uni35__uni30i = ((N - 1) - 1) + k * 1;
                }
                else
                {
                  __uni35__uni30i = (__uni32__uni30i + 1) * d2;
                }
                if ((__uni29__uni28j + 1) / 1 < __uni35__uni30i)
                {
                  __uni39__uni30i = (__uni29__uni28j + 1) / 1;
                }
                else
                {
                  __uni39__uni30i = __uni35__uni30i;
                }
                if ((((__uni29__uni28j - ((M - 1) - 1)) - 0) + 1) / 1 > __uni34__uni30i)
                {
                  __uni38__uni30i = (((__uni29__uni28j - ((M - 1) - 1)) - 0) + 1) / 1;
                }
                else
                {
                  __uni38__uni30i = __uni34__uni30i;
                }
                for (__uni30i = __uni38__uni30i; __uni30i < __uni39__uni30i; __uni30i = __uni30i + 1)
                {
                  i = __uni30i - k * 1;
                  __uni28j = __uni29__uni28j - k * 1;
                  j = __uni28j - i * 1;
                  u[(1 + i)][(1 + j)] = (((u[((1 + i) - 1)][(1 + j)] + u[((1 + i) + 1)][(1 + j)]) + u[(1 + i)][((1 + j) - 1)]) + u[(1 + i)][((1 + j) + 1)]) / 4.;
                }
              }
            }
          }
        }
      }
    }
  }

/*
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
                  u_transf[(1 + i)][(1 + j)] = (((u_transf[((1 + i) - 1)][(1 + j)] + u_transf[((1 + i) + 1)][(1 + j)]) + u_transf[(1 + i)][((1 + j) - 1)]) + u_transf[(1 + i)][((1 + j) + 1)])/4.0 ;
                  //x[k][i][j]+=1;
                }
              }
            }
          }
        }
      }
    }
  }
*/
	printf(">>>>>>>>>>>>>>>>>>");
/*
  {
    {
      int k;
      int i;
      int j;
      int __uni11j;
      int __uni12i;
      int __uni13k;
      for (__uni13k = 0; __uni13k < 4 / 2; __uni13k = __uni13k + 1)
      {
        for (__uni12i = 0; __uni12i < (((8 + 2) - 1) - 1) / 2; __uni12i = __uni12i + 1)
        {
          for (__uni11j = 0; __uni11j < (((8 + 2) - 1) - 1) / 2; __uni11j = __uni11j + 1)
          {
            for (k = __uni13k * 2; k < (__uni13k + 1) * 2; k = k + 1)
            {
              for (i = __uni12i * 2; i < (__uni12i + 1) * 2; i = i + 1)
              {
                for (j = __uni11j * 2; j < (__uni11j + 1) * 2; j = j + 1)
                {
                  u[(1 + i)][(1 + j)] = (((u[((1 + i) - 1)][(1 + j)] + u[((1 + i) + 1)][(1 + j)]) + u[(1 + i)][((1 + j) - 1)]) + u[(1 + i)][((1 + j) + 1)]) / 4.;
                }
              }
            }
          }
        }
      }
      for (k = 0; k < 4; k = k + 1)
      {
        for (i = 2 * ((((8 + 2) - 1) - 1) / 2); i < ((8 + 2) - 1) - 1; i = i + 1)
        {
          for (__uni11j = 0; __uni11j < (((8 + 2) - 1) - 1) / 2; __uni11j = __uni11j + 1)
          {
            for (j = __uni11j * 2; j < (__uni11j + 1) * 2; j = j + 1)
            {
              u[(1 + i)][(1 + j)] = (((u[((1 + i) - 1)][(1 + j)] + u[((1 + i) + 1)][(1 + j)]) + u[(1 + i)][((1 + j) - 1)]) + u[(1 + i)][((1 + j) + 1)]) / 4.;
            }
          }
        }
      }
      for (k = 0; k < 4; k = k + 1)
      {
        for (i = 0; i < ((8 + 2) - 1) - 1; i = i + 1)
        {
          for (j = 2 * ((((8 + 2) - 1) - 1) / 2); j < ((8 + 2) - 1) - 1; j = j + 1)
          {
            u[(1 + i)][(1 + j)] = (((u[((1 + i) - 1)][(1 + j)] + u[((1 + i) + 1)][(1 + j)]) + u[(1 + i)][((1 + j) - 1)]) + u[(1 + i)][((1 + j) + 1)]) / 4.;
          }
        }
      }
    }
  }
*/
  printf(">>>>>>>>>>>>>>>>>>");

	for (int i = 0; i < N; i ++){
		for (int j = 0; j < M; j++){
			if (u_src[i][j] != u[i][j])
				printf(">>> er %i %i src = %f, transf = %f -> %f\n", i,j, u_src[i][j], u[i][j], u_src[i][j] - u[i][j]);
				//printf(">>> er %i %i src = %f, transf = %f -> %f\n", i,j, u_src[i][j], u[i][j], u_src[i][j] - u[i][j]);
		}
	}

	return 0;
}
