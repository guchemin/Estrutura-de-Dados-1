#include "deque.h"

/* */
Deque* create_deque () {
  return NULL;
}

/* */
Point get_front (Deque *d) {
  if (d != NULL) {
    return d->p;
  }
}

/* */
Point get_back (Deque *d) {
  if (d != NULL) {
    Deque *aux = d;
    while (aux->next != NULL) {
      aux = aux->next;
    }
    return aux->p;
  }
}

/* */
Deque* insert_front (Deque *d, Point p, char field[][SIZE]) {
    field[p.x][p.y] = '*';
    Deque *n = (Deque *)malloc(sizeof(Deque));
    n->p = p;
    n->next = d;
    n->prev = NULL;
    if(d != NULL)
        d->prev = n;

    return n;
}

/* */
Deque* insert_back (Deque *d, Point p, char field[][SIZE]) {
    field[p.x][p.y] = '*';
    Deque *n = (Deque *)malloc(sizeof(Deque));
    n->p = p;
    n->next = NULL;
    n->prev = NULL;
    if(d == NULL)
        return n;
    Deque *t = d;
    while(t->next != NULL)
        t = t->next;
    t->next = n;
    n->prev = t;

    return d;
}

/* */
Deque* delete_front (Deque *d, char field[][SIZE]) {
    if(d == NULL)
        return d;

    field[d->p.x][d->p.y] = ' ';
    Deque* n = d->next;
    n->prev = NULL;
    free(d);

    return n;
}

/* */
Deque* delete_back (Deque *d, char field[][SIZE]) {
    if(d == NULL)
        return d;

    Deque *t = d;
    while(t->next != NULL){
        t = t->next;
    }
    field[t->p.x][t->p.y] = ' ';
    t->prev->next = NULL;
    free(t);

    return d;
}












