#include "utils.h"

void merge (int A[], int l, int m, int r, int O[]) {
    int i = l, j = m+1, k = l;
    while(i <= m && j <= r){
        if(A[i] <= A[j])
            O[k++] = A[i++];
        else
            O[k++] = A[j++];
    }
    while(i <= m)
        O[k++] = A[i++];
    while(j <= r)
        O[k++] = A[j++];
    for(i = l; i <= r; i++)
        A[i] = O[i];
}

/* */
void merge_sort (int A[], int l, int r, int O[]) {
    if(l < r){
        int m = l + (r-l)/2;
        merge_sort(A, l, m, O);
        merge_sort(A, m+1, r, O);
        merge(A, l, m, r, O);
    }
}

/* */
int two_sum (int A[], int n, int S) {
    int i = 0, j = n-1;
    while(i < j){
        if(A[i] + A[j] == S)
            return 1;
        if(A[i] + A[j] > S)
            j--;
        else
            i++;
    }
    return 0;
}

/* */
int main ( ) {
  clock_t start, end;
  double elapsed_time;
  int n = 5; /*quantidade de elementos*/
  int S = 4; /*soma exata*/
  int A[] = {1, -2, 1, 0, 5};
  int O[n];  /*vetor auxiliar*/
  start = clock();
  print (A, n, "Input");
  merge_sort (A, 0, n-1, O);
  print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  if (two_sum (A, n, S))
    printf ("Existem dois inteiros que somam %d\n", S);
  else
    printf ("Nao existem dois inteiros que somam %d\n", S);
  return 0;
}

