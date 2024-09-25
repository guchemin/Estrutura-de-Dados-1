#include "list.h"

List* create_circular (List *head) {
    if(head != NULL){
        List *end = head;
        while(end->next != NULL)
            end = end->next;
        end->next = head;
        head->prev = end;
    }
    return head;
}

int is_circular (List *l) {
    if(l == NULL)
        return 0;
    List *t = l;
    while(t->next != NULL){
        if(t->next == l)
            return 1;
        t = t->next;
    }
    return 0;
}

int main () {
  int i;
  int n = 4;
  List *l = create ();
  for (i = n; i >= 0; i--) {
    l = insert_front (l, i);
  }
  print (l);
  printf("Is circular: %d\n", is_circular(l));
  l = create_circular(l);
  printf("Is circular: %d\n", is_circular(l));
  return 0;
}
