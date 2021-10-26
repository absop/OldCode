#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <assert.h>


typedef struct _node {
    int data;
    struct _node *next;
} node_t;

typedef struct _list {
    int length;
    node_t *head;
} list_t;


list_t *ListInit()
{
    list_t *L = (list_t *)malloc(sizeof (list_t));
    L->length = 0;
    L->head = NULL;
    return L;
}

int ListEmpty(list_t *L) { return L->length == 0; }
int ListLength(list_t *L) { return L->length; }

int ListFind(list_t *L, int x)
{
    int index = 1;
    for (node_t *p = L->head; p != NULL; p = p->next) {
        if (p->data == x)
            return index;
        ++index;
    }

    return -1;
}

/* index: From 1 to L->length */
int ListIndex(list_t *L, int index)
{
    assert((index > 0) && (index <= L->length));

    node_t *q, *p = L->head;
    for (int i = 1; i < index; ++i)
        p = p->next;
    return p->data;
}

/* index: From 1 to L->length */
int ListInsert(list_t *L, int index, int x)
{
    assert((index > 0) && (index <= (L->length + 1)));

    node_t **p = &L->head;
    for (int i = 1; i < index; ++i)
        p = &(*p)->next;

    node_t *node = (node_t *)malloc(sizeof (node_t));
    node->data = x;
    node->next = *p;
    *p = node;

    L->length++;

    return x;
}

/* index: From 1 to L->length */
int ListDelete(list_t *L, int index)
{
    assert((index > 0) && (index <= L->length));

    node_t *q, **p = &L->head;

    int x;
    for (int i = 1; i < index; ++i)
        p = &(*p)->next;
    q = *p;
    x = q->data;
    *p = (*p)->next;
    free(q);

    L->length--;

    return x;
}

void ListTraverse(list_t *L)
{
    printf("L: ");
    for (node_t *p = L->head; p != NULL; p = p->next) {
        printf("%d", p->data);
        if (p->next)
            putchar(' ');
    }
    putchar('\n');
}

void ListDestroy(list_t **L)
{
    list_t *list = *L;
    *L = NULL;

    for (node_t *q, *p = list->head; p != NULL; ) {
        q = p->next;
        free(p);
        p = q;
    }
    free(list);
}


int main()
{
    printf("��ʼ��L\n");
    list_t *L = ListInit();

    printf("ListEmpty(L)=%d\n", ListEmpty(L));
    printf("L��λ��1����Ԫ��%d\n", ListInsert(L, 1, 1));
    printf("L��λ��2����Ԫ��%d\n", ListInsert(L, 2, 3));
    printf("L��λ��3����Ԫ��%d\n", ListInsert(L, 3, 1));
    printf("L��λ��4����Ԫ��%d\n", ListInsert(L, 4, 4));
    printf("L��λ��5����Ԫ��%d\n", ListInsert(L, 5, 2));

    ListTraverse(L);
    printf("ListLength(L)=%d\n", ListLength(L));
    printf("ListEmpty(L)=%d\n", ListEmpty(L));
    printf("L�ĵ�3��Ԫ��:%d\n", ListIndex(L, 3));
    printf("��һ��ֵΪ1��Ԫ�ص��߼����Ϊ:%d\n", ListFind(L, 1));
    printf("L��λ��4����Ԫ��%d\n", ListInsert(L, 4, 5));
    ListTraverse(L);
    printf("ɾ��L�ĵ�3��Ԫ��%d\n", ListDelete(L, 3));
    ListTraverse(L);

    printf("����L\n");
    ListDestroy(&L);

    return 0;
}
