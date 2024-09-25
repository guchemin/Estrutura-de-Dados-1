#include "utils.h"

/* */
int partition (int A[], int left, int right) {
    int p = right;
    int i = left - 1;
    int j;
    for(j = left; j < right; j++){
        if(A[j] < A[p]){
            i++;
            swap(A, i, j);
        }
    }
    swap(A, i+1, p);
    return i+1;
}

int partition_median_of_three (int A[], int left, int right) {
    int pos = (left + right) / 2;
    /* checa se left é mediana */
    if ((A[left] >= A[pos] && A[left] <= A[right]) || (A[left] <= A[pos] && A[left] >= A[right]))
        pos = left;
    /* checa se right é mediana */
    else if ((A[right] > A[pos] && A[right] < A[left]) || (A[right] < A[pos] && A[right] > A[left]))
        pos = right;

    swap(A, pos, right);
    return partition (A, left, right);
}

/* */
void quick_sort (int *A, int left, int right) {
    if(left < right){
        int p = partition_median_of_three(A, left, right);
        quick_sort(A, left, p-1);
        quick_sort(A, p+1, right);
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
  int n = 10; //atoi(argv[1]);;
  int range = 10; /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    A[i] = rand() % (n+1); /*valores aleatórios*/
    //A[i] = i; /*ordem crescente*/
    //A[i] = n-i; /*ordem descrente*/
    //A[i] = 0; /*iguais*/
  }

  start = clock();
  print (A, n, "Input");
  quick_sort (A, 0, n-1);
  print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  free (A);
  return 0;
}

