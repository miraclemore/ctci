#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUM 32

#define container_of(ptr, type, member) ({                            \
            (type *)((char *) ptr - (char *)&(((type *)0)->member));  \
        })

struct dlist {
    struct dlist *prev, *next;
};

struct element {
    int value;
    struct dlist list;
};

int dlist_add(struct dlist *head, struct dlist *new)
{
    if (!head || !new)
        return -1;

    new->prev = head;
    new->next = head->next;
    head->next->prev = new;
    head->next = new;
    return 0;
}

int dlist_add_tail(struct dlist *head, struct dlist *new)
{
    new->prev = head->prev;
    new->next = head;
    head->prev->next = new;
    head->prev = new;

    return 0;
}

int dlist_del(struct dlist *entry)
{
    if (!entry)
        return -1;

    entry->prev->next = entry->next;
    entry->next->prev = entry->prev;

    return 0;
}

int dlist_empty(struct dlist *head)
{
    if (!head)
        return -1;

    if (head->next == head)
        return 1;

    return 0;
}

int dlist_traverse(struct dlist *head)
{
    struct dlist *p;
    struct element *e;

    if (!head)
    return -1;

    if (dlist_empty(head)) {
        printf("The list is empty\n");
        return 0;
    }

    p = head->next;

    while(p != head) {
        e = container_of(p, struct element, list);
        printf("%d ", e->value);
        p = p->next;
    }

    printf("\n");
    return 0;
}

int main(void)
{
    int i;
    struct dlist *head;

    head = (struct dlist *) malloc(sizeof(struct dlist));
    if (!head)
        return -1;

    /* Initialize list head */
    head->next = head;
    head->prev = head;

    struct element *e[MAX_NUM];

    /* Initial list */
    for (i = 0; i < MAX_NUM; i++) {
        e[i] = (struct element *) malloc(sizeof(struct element));
        e[i]->value = i;
        dlist_add_tail(head, &e[i]->list);
    }

    dlist_traverse(head);

    dlist_del(&e[0]->list);
    free(e[0]);

    dlist_traverse(head);

    dlist_del(&e[31]->list);
    free(e[31]);

    dlist_traverse(head);

    for (i = 0; i < MAX_NUM; i++) {
        if (e[i])
            free(e[i]);
    }

    if (head)
        free(head);

    return 0;
}
