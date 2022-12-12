#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>

// linha possui id, A e B, para y = ax + b
typedef struct {
   int lno;
   double m;
   double c;
} line;

// ponto qualquer
typedef struct {
   double x, y;
} point;

// achar linha a partir de 2 pontos (x1, y1) e (x2, y2)
line lineeqn ( int i, double x1, double y1, double x2, double y2 )
{
   line L;

   L.lno = i;
   L.m = (y2 - y1) / (x2 - x1);
   L.c = y1 - (L.m) * x1;
   return L;
}

// gera linhas
line *genlines ( int n )
{
   line *L;
   int i, t;
   double a, b;

   L = (line *)malloc(n * sizeof(line));
   #ifdef _ASGN_DEMO
      L[0] = lineeqn(0, 0, 3, 15, 9);
      L[1] = lineeqn(1, 0, 9, 15, 6);
      L[2] = lineeqn(2, 2.5, 0, 15, 14);
      L[3] = lineeqn(3, 0, 1.5, 15, 1.5);
      L[4] = lineeqn(4, 0, 12, 12, 0);
      L[5] = lineeqn(5, 0, 7, 15, 1);
      L[6] = lineeqn(6, 0, 15, 6.5, 0);
      L[7] = lineeqn(7, 9.5, 0, 13.5, 15);
      L[8] = lineeqn(8, 5, 0, 15, 7);
      for (i=0; i<n; ++i) printf("%16.10lf %16.10lf\n", L[i].m, L[i].c);
      return L;
   #endif
   for (i=0; i<n; ++i) {
      a = 1 + rand() % 9999;
      b = 1 + rand() % 9999;
      t = rand() % 4;
      if (t == 1) a = -a;
      else if (t == 2) b = -b;
      else if (t == 3) { a = -a; b = -b; }
      /* Convert x / a + y / b = 1 to y = mx + c */
      L[i].lno = i; L[i].m = -b / a; L[i].c = b;
      printf("%16.10lf %16.10lf\n", L[i].m, L[i].c);
   }
   return L;
}

void printlines ( line *L, int n )
{
   int i;

   for (i=0; i<n; ++i) {
      printf("Line %4d: y = ", L[i].lno);
      printf(" %16.10lf", L[i].m);
      if (L[i].c > 0) printf(" x + %15.10lf\n", L[i].c);
      else printf(" x - %15.10lf\n", -L[i].c);
   }
}

// achar intersecção das linhas com ids 'i' e 'j'
point findintersection ( line *L, int i, int j )
{
   point P;

    // Se linha 'i' tem mesmo gradiente que linha 'j', erro
   if (L[i].m == L[j].m) {
      fprintf(stderr, "*** Error in findintersection: Parallel lines\n");
      exit(1);
   }

   // x <-- (b1-b2)/(a1-a2)
   P.x = (L[j].c - L[i].c) / (L[i].m - L[j].m);

   // y <- a1*x + b1
   P.y = L[i].m * P.x + L[i].c;

   // ponto interseção = ((b1-b2)/(a1-a2), a1*x + b1)
   return P;
}

// intercalação das lista
void mergelists ( line *L, int n )
{
   line *T;
   int i, j, k, src, u, v;

   T = (line *)malloc(n * sizeof(line));
   i = 0; j = u = n / 2; v = n; k = 0;
   while ((i < u) || (j < v)) {
      if (j == v) src = 1;
      else if (i == u) src = 2;
      else src = (L[i].m < L[j].m) ? 1 : 2;
      if (src == 1) {
         T[k] = L[i];
         ++i;
      } else {
         T[k] = L[j];
         ++j;
      }
      ++k;
   }
   for (i=0; i<n; ++i) L[i] = T[i];
   free(T);
}

// ordena linhas por gradiente usando mergesort
void sortlines ( line *L, int n )
{
   int m;

   if (n <= 1) return;
   m = n / 2;
   sortlines(L,m);
   sortlines(L+m,n-m);
   mergelists(L,n);
}

void method2 ( line *L, int n )
{
   int *S, top, i, j;
   point *F, *T, P;

    // pilha de ids de linhas que compõem os limites do ceu visível
   S = (int *)malloc(n * sizeof(int));

    // F <- [1..n]  vetor de pontos
   F = (point *)malloc(n * sizeof(point));
    // T <- [1..n] vetor de pontos
   T = (point *)malloc(n * sizeof(point));


    // joga na pilha a linha de id 0 (linha com menor gradiente)
   S[0] = 0;
   // seta o ponto da linha 0 para (-inf, -inf)
   F[0] = (point){-DBL_MAX, -DBL_MAX};
    // seta o ponto da linha 0 para (+inf, +inf)
   T[0] = (point){DBL_MAX, DBL_MAX};

   // tamanho da pilha é 0 (topo)
   top = 0;

   // para todas as linhas i de L[1..n]
   for (i=1; i<n; ++i) {
       // enquanto verdade
      while (1) {
          // j <-- topo pilha (id da linha alterada por último)
         j = S[top];
         // acha intersecção entre linha alterada por último e a linha i
         P = findintersection(L,j,i);
         // se ponto de intersecção x achado for maior que ponto de intersecção x da linha no topo da pilha, break
         if (P.x > F[top].x) break;
         // da pop na pilha
         --top;
      }
    // adiciona o ponto de intersecção na lista T
      T[top] = P;
      
      ++top;
      S[top] = i;
      F[top] = P;
      T[top] = (point){DBL_MAX, DBL_MAX};
   }
   printf("\n+++ Method 2\n");
   for (i=0; i<=top; ++i) {
      printf("Line %4d: From ", L[S[i]].lno);
      if (F[i].x == -DBL_MAX) printf("MINUS_INFINITY to ");
      else printf("(%.10lf,%.10lf) to ", F[i].x, F[i].y);
      if (T[i].x == DBL_MAX) printf("PLUS_INFINITY\n");
      else printf("(%.10lf,%.10lf)\n", T[i].x, T[i].y);
   }
   free(S);
   free(F);
   free(T);
}

int main ( int argc, char *argv[] )
{
   int n;
   line *L;

   srand((unsigned int)time(NULL));
   #ifdef _ASGN_DEMO
      n = 9;
   #else
      if (argc > 1) n = atoi(argv[1]); else scanf("%d", &n);
   #endif
   printf("n = %d\n", n);

   L = genlines(n);
   printf("\n+++ Lines before sorting\n"); printlines(L,n);

// ordena n linhas do vetor de linhas em tempo O(n.logn)
   sortlines(L,n);
   printf("\n+++ Lines after sorting\n"); printlines(L,n);

    // acha área visível de linhas ordenadas em O(n)
   method2(L,n);

   exit(0);
}