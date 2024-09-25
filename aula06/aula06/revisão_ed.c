int max_itr(List *l){
    List *t = l;
    int maior = -INT_MAX;
    while(t != NULL){
        if(t->data > maior)
            maior = t->data;
        t = t->next;
    }
    return maior;
}

int max_rec (List *l){
    List *t = l;
    int maior;
    if(t == NULL)
        return -INT_MAX;
    else{
        maior = max_rec(t->next);
    }
    if(t->data > maior)
        maior = t->data;

    return maior;
}

List* remove_all(List *l, int k){
    if(l == NULL)
        return NULL;
    else{
        l->next = remove_all(l->next, k);
    }
    if(l->data == k){
        List *t = l->next;
        free(l);
        return t;
    }
    return l;
}

Stack *push(Stack *l, int elem){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = elem;
    s->prev = NULL;
    s->next = l;
    if(l != NULL){
        l->prev = s;
    }
    return s;
}

Stack* pop (Stack *l){
    if(l == NULL)
        return NULL;
    Stack *s = l->next;
    if(s != NULL)
        s->prev = NULL;
    free(l);
    return s;
}

int peek (Stack *l){
    if(l != NULL)
        return l->data;
    else
        return ERROR;
}

int empty (Stack *l){
    if(l == NULL)
        return 1;
    return 0;
}

void enqueue (Pilha *p, int elem) {
    if(!full(p)){
        push(p, elem);
    }
}

int dequeue (Pilha *p) {
    Pilha *t = create(p->size);
    while(!empty(p)){
        push(t, pop(p));
    }

    int elem = pop(t);

    for(i = 0; i < t->size; i++){
        push(p, pop(t));
    }

    return elem;
}

int ligacoes(List *l){
    int tam_ini = size(l);
    int achou_lig = 1;
    List *t = l;
    while(t != NULL && t->next != NULL && achou_lig){
        List *n = t;
        achou_lig = 0;
        while(n != NULL && n->next != NULL){
            int a = n->data;
            int b = n->next->data;
            if((a == 'C' && b == 'F') || (b == 'C' && a == 'F') || (a == 'B' && b == 'S') || (b == 'C' && a == 'F')){
                removek(n, a);
                removek(n, b);
                achou_lig = 1;
            }
            else
                n = n->next;
        }
    }
    int tam_fin = size(t);

    return (tam_ini-tam_fin)/2;
}




//==================================================

List* insert_sort (List *l, int k){
    if(l == NULL)
        return NULL;
    if(l->data < k){
        l->next = insert_sort(l->next, k);
    }
    else{
        List *n = (List *)malloc(sizeof(List));
        n->data = k;
        n->next = l;
        return n;
    }
    return l;
}


List* removek (List *l, int k){
    if(l == NULL)
        return l;
    if(l->data != k){
        l->next = removek(l->next, k);
    }
    else
        return l->next;
    return l;
}


List* copy (List *A){
    if(A == NULL)
        return NULL;
    List *B = (List *)malloc(sizeof(List));
    B->data = A->data;
    B->next = copy(A->next);
    return B;
}


int similar (List *A, List *B){
    if(A == NULL && B == NULL)
        return 1;
    else if(A == NULL && B != NULL || A != NULL && B == NULL)
        return 0;
    int flag = (A->data == B->data);

    return flag && similar(A->next, B->next);
}

List* intersection (List *A, List *B){
    if(A == NULL)
        return NULL;
    List *inters = malloc(List *)malloc(sizeof(List));
    if(in(B, A->data)){
        inters->data = A->data;
        inters->next = intersection(A->next, B);
    }
    inters = intersection(A->next, B);

    return inters;
}

void print_reverse (List *l){
    if(l == NULL)
        return;
    print_reverse(l->next);

    printf("%d ", l->data);
}






