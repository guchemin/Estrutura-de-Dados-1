#include "list.h"

List* replicate (List *l, int k) {
    if(l == NULL || k <= 1)
        return l;

    int i;
    List *t = l;
    List *n;
    while(t != NULL){
        for(i = 1; i<k; i++){
            n = (List *)malloc(sizeof(List));
            n->data = t->data;
            n->next = t;
            n->prev = t->prev;
            if(t->prev != NULL)
                t->prev->next = n;
            t->prev = n;
        }
        t = t->next;
    }
    while(l->prev != NULL)
        l = l->prev;

    return l;
}

int main () {
  int i;
  int k = 3;
  int n = 4;
  List *l = create ();
  for (i = n; i >= 1; i--) {
    l = insert_front (l, i);
  }
  print (l);
  l = replicate (l, k);
  print (l);
  destroy (l);
  return 0;
}
