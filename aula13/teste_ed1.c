#define N
#define M

int inside(int x, int y){
    return (x >= 0 && x < N && y >= 0 && y < M);
}

int caminhos(int x_0, int y_0, int x, int y, int labirinto[][M]){
    Queue *p_x = create();
    Queue *p_y = create();
    Queue *passos = create();

    enqueue(p_x, p_0);
    enqueue(p_y, p_0);
    enqueue(passos, 0);

    while((front(p_x) != x || front(p_y) != y) && !empty(passos)){
        if(inside(front(p_x), front(p_y)) && labirinto[front(p_x)][front(p_y)]){
            enqueue(p_x, front(p_x) + 1);
            enqueue(p_y, front(p_y));
            enqueue(p_x, front(p_x) - 1);
            enqueue(p_y, front(p_y));
            enqueue(p_x, front(p_x));
            enqueue(p_y, front(p_y) + 1);
            enqueue(p_x, front(p_x));
            enqueue(p_y, front(p_y) - 1);
            for(int i = 0; i < 4; i++)
                enqueue(passos, front(passos));
        }
        dequeue(p_x);
        dequeue(p_y);
        dequeue(passos);
    }
    if(empty(passos))
        return -1;
    int tam = front(passos);

    destroy(p_x);
    destroy(p_y);
    destroy(passos);

    return tam;
}
