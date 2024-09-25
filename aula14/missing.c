#include "utils.h"

/* */
int missing_number (int *A, int n, int m) {
  if(n == m)
    return m;
  if(A[0] != 0)
    return 0;

  int l=0, r=n-1, meio;

  while(l <= r){
    meio = (l + r)/2;
    if(A[meio] > meio)
        r = meio-1;
    else if(A[meio] == meio)
        l = meio+1;
  }

  return A[r]+1;
}

/* */
int main () {
  int i;
  //int n = 4, m = 4;
  //int A[] = {0,1,2,3};
  //int n = 4, m = 12;
  //int A[] = {4,5,10,11};
  //int n = 7, m = 16;
  //int A[] = {0,1,2,6,9,11,15};
  //int n = 8, m = 16;
  //int A[] = {1,2,3,4,6,9,11,15};
  //int n = 7, m = 7;
  //int A[] = {0,1,2,3,4,5,6};
  int n = 8, m = 11;
  int A[] = {0,1,2,3,4,5,6,7,10};
  print (A, n, "Input");
  printf("Missing number: %d\n", missing_number (A, n, m));
  return 0;
}
