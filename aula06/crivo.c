#include <math.h>
#include "list.h"

void crivo (int n) {
    int i, sq = sqrt(n);
    List *l = create ();
    for(i = 2; i <= n; i++)
        l = insert_back(l, i);
    List *t = l;
    while(t != NULL){
        for(i = t->data * 2; i <= n; i += t->data)
            t = remove_queue(t, i);
        t = t->next;
    }
    print(l);
    destroy (l);
}

int main () {
  int n = 100;
  crivo (n);
  return 0;
}
