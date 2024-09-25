#include "utils.h"

int find_digit(int num, int digit){
    int i;
    for(i = 0; i < digit; i++)
        num /= 10;
    return num % 10;
}
/* */
void counting_sort (int *A, int n, int digit, int digit_range) {
  int i, j, d;

  /*Alocando vetores auxiliares: */
  int *T = (int *)malloc(n * sizeof(int)); /*temporário*/
  int *C = (int *)malloc((digit_range+1) * sizeof(int)); /*contador*/

  for(i = 0; i <= digit_range; i++)
    C[i] = 0;

  for(j = 0; j < n; j++){
    d = find_digit(A[j], digit);
    C[d]++;
  }

  for(i = 1; i <= digit_range; i++)
    C[i] += C[i-1];

  for(j = n-1; j >= 0; j--){
    d = find_digit(A[j], digit);
    T[C[d]-1] = A[j];
    C[d]--;
  }

  for(j = 0; j < n; j++)
    A[j] = T[j];

  /*Desalocando vetores auxiliares: */
  free (T);
  free (C);
}

/* */
void radix_sort (int *A, int n, int range) {
  int digit;
  int digit_range = 9; /*números de 0 a 9 (para inteiros)*/
  int i;
  int maior = A[0];

  for(i = 1; i < n; i++)
    if(A[i] > maior)
        maior = A[i];

  digit = 0;

  while(maior > 0){
    maior /= 10;
    digit++;
  }

  for(i = 0; i < digit; i++){
    counting_sort(A, n, i, digit_range);
  }

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
  int n = 100; //atoi(argv[1]);;
  int range = 100; /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    A[i] = rand() % range; /*valores aleatórios*/
  }

  start = clock();
  //print (A, n, "Input");
  radix_sort (A, n, range);
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

