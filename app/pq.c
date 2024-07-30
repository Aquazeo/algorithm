#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

struct function
{
    int A, B, C;
    int x, y;
};

struct priority_queue q;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    q.A = (struct pq_item **)malloc(n * sizeof(struct pq_item *));

    struct function *f;
    struct pq_item *item;
    for (int i = 1; i <= n; i ++)
    {
        f = (struct function *)malloc(n * sizeof(struct function));
        scanf("%d%d%d", &f->A, &f->B, &f->C);
        f->x = 1;
        f->y = f->A + f->B + f->C;

        item = (struct pq_item *)malloc(sizeof(struct pq_item));
        item->key = f->y;
        item->data = (void *)f;
        min_pq_insert(&q, item, n);
    }

    int ans[m];
    int index = 0;
    struct pq_item *max;
    while (index < m)
    {
        max = min_pq_extract_min(&q);
        ans[index] = max->key;
        index ++;

        struct function *func = (struct function *)(max->data);
        func->x ++;
        func->y = func->A * func->x * func->x + func->B * func->x + func->C;
        max->key = func->y;
        min_pq_insert(&q, max, n);
    }

    for (int i = 0; i < m; i ++)
        printf("%d ", ans[i]);
    
    puts("");

    return 0;
}
