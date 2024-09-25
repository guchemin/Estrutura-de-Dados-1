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

/* */
void quick_sort (int *A, int left, int right, int *calls, int ident) {
    for(int i = 0; i < (ident)*4; i++)
        printf(" ");
    printf("quick_sort (%d, %d)\n", left, right);
    if(left < right){
        for(int i = 0; i < (ident+1)*4; i++)
            printf(" ");
        printf("P: {");
        for(int i = left; i < right; i++) {
            printf("%d", A[i]);
            if(i < right -1)
                printf(", ");
        }
        printf("}\n");
        int p = partition(A, left, right);
        quick_sort(A, left, p-1, calls, ident+1);
        (*calls)++;
        quick_sort(A, p+1, right, calls, ident+1);
        (*calls)++;
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

  int calls = 1;
  for (i = 0; i < n; i++) {
    //A[i] = rand() % (n+1); /*valores aleatórios*/
    A[i] = i; /*ordem crescente*/
    //A[i] = n-i; /*ordem descrente*/
    //A[i] = 0; /*iguais*/
  }

  start = clock();
  print (A, n, "Input");
  quick_sort (A, 0, n-1, &calls, 0);
  printf("Number of calls: %d\n", calls);
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
