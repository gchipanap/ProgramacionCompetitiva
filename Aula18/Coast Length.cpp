#include <stdlib.h>
#include <stdio.h>

struct point2D
{
    short x;
    short y;
};
typedef struct point2D point;

struct point2D_stack
{
    point* memory;
    point* next;
};
typedef struct point2D_stack stack;

void init(stack* s, int max_capacity)
{
    s->memory = (point*)malloc(max_capacity * sizeof(point));
    s->next = s->memory;
}

void destroy(stack* s)
{
    free(s->memory);
}

int is_empty(stack* s)
{
    return s->memory == s->next;
}

void push(stack* s, short x, short y)
{
    s->next->x = x;
    s->next->y = y;
    s->next++;
}

point* pop(stack* s)
{
    point* tmp = s->next - 1;
    s->next--;
    return tmp;
}

int main()
{
    int r, c;
    scanf("%d %d",&r,&c);

    short l_one = (short)1;

    char map[r + 2][c + 2];
    for (int i = 0; i < r; i++) scanf("%s", map[i + 1]+1);
    for (int i = 0; i < r + 2; i++)
    {
        map[i][0] = '0';
        map[i][c+1] = '0';
    }
    for (int i = 0; i < c + 2; i++)
    {
        map[0][i] = '0';
        map[r+1][i] = '0';
    }

    int coast_counter = 0;
    int total = (r + 2) * (c + 2);

    stack open;
    init(&open, total << 2);
    push(&open, 0, 0);

    char closed[total];
    memset(closed, 0, (size_t)total);

    while (!is_empty(&open))
    {
        point* current = pop(&open);
        short x_curr = current->x;
        short y_curr = current->y;
        int one_dim = y_curr * (c+2) + x_curr;
        if (closed[one_dim]) continue;
        closed[one_dim] = 1;

        if (y_curr > 0)
        {
            if (map[y_curr - 1][x_curr] == '1') coast_counter++;
            else if (!closed[(y_curr-1) * (c+2) + x_curr]) push(&open, x_curr, y_curr - l_one);
        }
        if (y_curr < r + 1)
        {
            if (map[y_curr + 1][x_curr] == '1') coast_counter++;
            else if (!closed[(y_curr+1) * (c+2) + x_curr]) push(&open, x_curr, y_curr + l_one);
        }
        if (x_curr > 0)
        {
            if (map[y_curr][x_curr - 1] == '1') coast_counter++;
            else if (!closed[y_curr * (c+2) + x_curr - 1]) push(&open, x_curr - l_one, y_curr);
        }
        if (x_curr < c + 1)
        {
            if (map[y_curr][x_curr + 1] == '1') coast_counter++;
            else if (!closed[y_curr * (c+2) + x_curr + 1]) push(&open, x_curr + l_one, y_curr);
        }
    }
    destroy(&open);
    printf("%d\n", coast_counter);
    return 0;
}