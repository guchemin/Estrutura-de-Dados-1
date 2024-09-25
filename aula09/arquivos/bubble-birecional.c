#include "utils.h"

/* */
// VERSÃO ITERATIVA
void bubble_bidirecional (int *A, int n) {
    int i, j;
    int inicio = 0, fim = n - 1;
    while (inicio < fim){
        for(i = inicio; i < fim; i++){
            if(A[i] > A[i+1])
                swap(A, i, i+1);
        }
        for(; i > inicio; i--){
            if(A[i] < A[i-1])
                swap(A, i, i-1);
        }
        inicio++;
        fim--;
    }
}

// VERSÃO RECURSIVA
void bubble_bidirecional_rec (int *A, int n) {
    int i;
    for(i = 0; i < n - 1; i++){
        if(A[i] > A[i+1])
            swap(A, i, i+1);
    }
    for(; i > 0; i--){
        if(A[i] < A[i-1])
            swap(A, i, i-1);
    }
    if(n > 1)
        bubble_bidirecional_rec(A + 1, n - 2);
}

/* */
int main (int argc, char *argv[]) {

  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));

  /*if (argc < 2) {
    printf("run: %s [size]\n", argv[0]);
    exit(1);
  }*/

  int i;
  int n = 10; //atoi(argv[1]);;
  int range = 10; /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    A[i] = rand() % (n+1); /*valores aleatórios*/
  }

  start = clock();
  //print (A, n, "Input");
  bubble_bidirecional (A, n);
  //bubble_bidirecional_rec (A, n);
  //print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  free (A);
  return 0;
}

