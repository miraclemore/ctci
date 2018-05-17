#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUM 32

#define container_of(ptr, type, member) ({                        \
            (type *)((char *) ptr - (char *)&(((type *)0)->member)); \
        })

struct list {
    struct list *next;
};

struct element {
    int value;
    struct list list;
};

int list_add(struct list *head, struct list *new)
{
    if (!head || !new)
        return -1;

    new->next = head->next;
    head->next = new;

    return 0;
}

int list_add_tail(struct list *head, struct list *new)
{
    struct list *p, *q;

    if (!head || !new)
        return -1;

    q = head;
    p = head->next;

    while(p) {
        q = p;
        p = p->next;
    }

    q->next = new;

    return 0;
}

int list_del(struct list *head, struct list *entry)
{
    struct list *prev, *p;

    if (!head || !entry)
        return -1;

    p = head->next;
    prev = head;

    while (p != entry) {
        prev = p;
        p = p->next;
    }

    prev->next = p->next;

    return 0;
}

int list_empty(struct list *head)
{
    if (!head)
        return -1;

    if (head->next)
        return 0;
    else
        return 1;
}

int list_traverse(struct list *head)
{
    struct list *p;
    struct element *e;

    if (!head)
        return -1;

    if (list_empty(head)) {
        printf("The list is empty\n");
        return 0;
    }

    p = head->next;

    while(p) {
        e = container_of(p, struct element, list);
        printf("%d ", e->value);
        p = p->next;
    }

    printf("\n");
    return 0;
}

int list_reverse(struct list *head)
{
    struct list *p, *q, *t;

    if (!head)
        return -1;

    if (list_empty(head)) {
        printf("The list is empty\n");
        return 0;
    }

    p = head->next;
    q = p->next;
    /* only one element */
    if (!q)
        return 0;
    t = q->next;

    while (t) {
        q->next = p;
        p = q;
        q = t;
        t = t->next;
    }

    q->next = p;
    head->next->next = NULL;
    head->next = q;

    return 0;
}

int main(void)
{
    int i;
    struct list *head;

    head = (struct list *) malloc(sizeof(struct list));
    if (!head)
        return -1;

    struct element *e[MAX_NUM];

    /* Initial list */
    for (i = 0; i < MAX_NUM; i++) {
        e[i] = (struct element *) malloc(sizeof(struct element));
        e[i]->value = i;
        e[i]->list.next = NULL;
        list_add(head, &e[i]->list);
    }

    list_traverse(head);

    list_reverse(head);

    list_traverse(head);

    list_del(head, &e[0]->list);
    free(e[0]);

    list_traverse(head);

    list_del(head, &e[31]->list);
    free(e[31]);

    list_traverse(head);

    for (i = 0; i < MAX_NUM; i++) {
        if (e[i])
            free(e[i]);
    }

    if (head)
        free(head);

    return 0;
}
