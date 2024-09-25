#include "list.h"

/**/
List* create () {
  List *l = (List *)malloc(sizeof(List));
  l->head = NULL;
  l->tail = NULL;
  return l;
}

/**/
void insert_front (List *l, int elem) {
  Node *n = (Node *)malloc(sizeof(Node));
  n->data = elem;
  n->prev = NULL;
  if (l->head != NULL) {
    n->next = l->head;
    l->head->prev = n;
  }
  else {
    n->next = NULL;
    l->tail = n;
  }
  l->head = n;
}

/**/
void insert_back (List *l, int elem) {
  Node *n = (Node *)malloc(sizeof(Node));
  n->data = elem;
  n->next = NULL;
  if(l->tail != NULL){
    n->prev = l->tail;
    l->tail->next = n;
  }
  else{
    n->prev = NULL;
    l->head = n;
  }
  l->tail = n;
}

/**/
void remove_front (List *l) {
  if (l->head != NULL) {
    Node *n = l->head->next;
    free (l->head);
    if (n != NULL)
       n->prev = NULL;
    else
       l->tail = NULL;
        l->head = n;
  }
}

/**/
void remove_back (List *l) {
  if (l->tail != NULL) {
    Node *p = l->tail->prev;
    if(p != NULL){
        p->next = NULL;
    }
    else{
        l->head = NULL;
    }
    free(l->tail);
    l->tail = p;
  }
}

/**/
Node* search (List *l, int k) {
  if (l != NULL) {
    Node *n = l->head;
    while (n != NULL) {
      if (n->data == k)
        return n;
      n = n->next;
    }
  }
  return NULL;
}

/**/
void remove_k (List *l, int k) {
  if (l != NULL) {
    if (l->head != NULL) {
      Node *h = l->head; /*head pointer*/
      Node *t = l->tail; /*tail pointer*/
      while(h != NULL){
        if(h->data == k){
            if (h->prev != NULL){ h->prev->next = h->next; }
            else { l->head = h->next; }
            if (h->next != NULL){ h->next->prev = h->prev; }
            else { l->tail = h->prev; }
            free(h);
            break;
        }
      h = h->next;
      }
    }
  }
}

/**/
void print_head_to_tail (List *l) {
  Node *t;
  t = l->head;
  printf("head to tail: ");
  while(t != NULL){
    printf("%d ", t->data);
    t = t->next;
  }
}

/**/
void print_tail_to_head (List *l) {
  Node *t;
  t = l->tail;
  printf("tail to head: ");
  while(t != NULL){
    printf("%d ", t->data);
    t = t->prev;
  }
}

/**/
int middle (List *l) {
    Node *h = l->head;
    Node *t = l->tail;
    while(h != t && h->next != t){
        h = h->next;
        t = t->prev;
    }
    return h->data;
}

/**/
void destroy (List *l) {
  if (l != NULL) {
    Node *h = l->head;
    while (h != NULL) {
      Node *t = h->next;
      free (h);
      h = t;
    }
  }
}

int palindrome (List *l){

}


/*====== FUNÇÕES DE FILA ======*/

void enqueue (List *l, int elem){
    //igual a insert_front
    insert_front(l, elem);
}

int dequeue (List *l){
    //análogo a remove_back
    if (l->tail != NULL) {
        int elem = l->tail->data;
        remove_back(l);
        return elem;
    }
}

int front (List *l){
    if(l->head != NULL)
        return l->head->data;
    return ERROR;
}

int empty_queue (List *l){
    if(l->head == NULL)
        return 1;
    return 0;
}

/*====== FUNÇÕES DE PILHA ======*/

void push (List *l, int elem){
    //igual insert_front
    insert_front(l, elem);
}

int pop (List *l){
    //anaálogo a remove_front
    if (l->head != NULL) {
        int elem = l->head->data;
        remove_front(l);
        return elem;
    }
}

int peek (List *l){
    if(l->head != NULL)
        return l->head->data;
    return ERROR;
}

int empty_stack (List *l){
    if(l->head == NULL)
        return 1;
    return 0;
}
