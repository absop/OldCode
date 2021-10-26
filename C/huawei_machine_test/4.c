#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

#define MAXN  (1<<20)
typedef struct _keyval keyval_t;
typedef struct _hash hash_t;
struct _keyval {
    int key;
    int val;
    keyval_t *next;
};

struct _hash {
    keyval_t *bucket[MAXN];
    keyval_t **vector;
    int count;
    int size;
};

void add(hash_t *hash, int key, int val)
{
    int idx = key & MAXN;
    keyval_t *p = hash->bucket[idx];
    for (; p != NULL; p = p->next) {
        if (p->key == key) {
            p->val += val;
            return;
        }
    }
    keyval_t *node = malloc(sizeof(keyval_t));
    node->key = key;
    node->val = val;
    node->next = hash->bucket[idx];
    hash->bucket[idx] = node;

    hash->vector[hash->count++] = node;
}

int cmp(const void *p, const void *q)
{
    keyval_t *a = *((keyval_t **)p);
    keyval_t *b = *((keyval_t **)q);

    return a->key - b->key;
}

void print_and_free(hash_t *hash)
{
    qsort(hash->vector, hash->count, sizeof(keyval_t *), cmp);
    for (int i = 0; i < hash->count; ++i) {
        keyval_t *p = hash->vector[i];
        printf("%d %d\n", p->key, p->val);
        free(p);
    }
    free(hash->vector);
    free(hash);
}

int main()
{
    int n;
    int key, val;
    scanf("%d", &n);

    hash_t *hash = malloc(sizeof(hash_t));
    hash->vector = (keyval_t **)malloc(sizeof(keyval_t *) * n);
    hash->size = n;
    hash->count = 0;

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &key, &val);
        add(hash, key, val);
    }

    print_and_free(hash);

    return 0;
}
