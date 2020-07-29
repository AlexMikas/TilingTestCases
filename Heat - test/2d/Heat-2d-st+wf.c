#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 2000L
#define T 64L

double A[2][N+2][N+2];

time_t start, end;

int main (int argc, char *argv[])
{
// Размеры блоков
  int d1=4, d2=10, d3=10; 
// Количество потоков
  int thread_count = 6;

	if (argc == 4)
	{
		d1 = atoi(argv[1]);
		d2 = atoi(argv[2]);
    d3 = atoi(argv[2]);
    thread_count = atoi(argv[3]);
	}
	srand(time(NULL));
	
    const int BASE = 1024;

    /* Initialization */
    srand(42); // seed with a constant value to verify results

    for (int i = 1; i < N+1; i++) {
        for (int j = 1; j < N+1; j++) {
            A[0][i][j] = 1.0 * (rand() % BASE);
        }
    }

	start = clock();
  
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
        #pragma omp parallel num_threads(thread_count) private (i, j, t, __uni0j, __uni1__uni0j, __uni3__uni1__uni0j, __uni2i, __uni4__uni2i,__uni5t) firstprivate( __uni17__uni14__uni3__uni1__uni0j)
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
          #pragma omp for 
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
                  A[((t + 1) % 2)][(1 + i)][(1 + j)] = (0.125 * ((A[(t % 2)][((1 + i) + 1)][(1 + j)] - 2. * A[(t % 2)][(1 + i)][(1 + j)]) + A[(t % 2)][((1 + i) - 1)][(1 + j)]) + 0.125 * ((A[(t % 2)][(1 + i)][((1 + j) + 1)] - 2. * A[(t % 2)][(1 + i)][(1 + j)]) + A[(t % 2)][(1 + i)][((1 + j) - 1)])) + A[(t % 2)][(1 + i)][(1 + j)];
                }
              }
            }
          }
        }
      }
    }
  }

	end = clock();
	printf("%.10f\n", (double)(end - start) / CLOCKS_PER_SEC); //seconds

  return 0;
}
