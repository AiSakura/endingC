#include <stdio.h>
#include <malloc.h>

#define MAX_LENG 7

struct node
{
    int height;
    int key;
    struct node* right;
    struct node* left;
};

void print(struct node* p)
{
    if (p)
    {
        printf("%d ", p->key);
        print(p->left);
        print(p->right);
    }
}

struct node* init(struct node* p, int key)
{
    if (!(p = (struct node*)malloc(sizeof(struct node))))
    {
        printf("not enought memory");
    }

    p->key = key;
    p->height = 1;
    p->left = NULL;
    p->right = NULL;
    return p;
}

int height(struct node* p)
{
    return p ? p->height : 0;
}

int factor(struct node* p)
{
    return height(p->right) - height(p->left);
}

void fix_height(struct node* p)
{
    int hl = height(p->left);
    int hr = height(p->right);
    p->height = (hl > hr ? hl : hr) + 1;
}

struct node* rotate_right(struct node* p)
{
    struct node* q = p->left;
    p->left = q->right;
    q->right = p;
    fix_height(p);
    fix_height(q);
    return q;
}

struct node* rotate_left(struct node* q)
{
    struct node* p = q->right;
    q->right = p->left;
    p->left = q;
    fix_height(q);
    fix_height(p);
    return p;
}

struct node* balance(struct node* p)
{
    fix_height(p);

    if (factor(p) == 2)
    {
        if (factor(p->right) < 0)
        {
            p->right = rotate_right(p->right);
        }

        return rotate_left(p);
    }

    if (factor(p) == -2)
    {
        if (factor(p->left) > 0)
        {
            p->left = rotate_left(p->left);
        }

        return rotate_right(p);
    }

    return p;
}

struct node* add(struct node* p, int k)
{
    if (!p)
    {
        return init(p, k);
    }

    if (p->key > k)
    {
        p->left = add(p->left, k);
    }
    else if (p->key < k)
    {
        p->right = add(p->right, k);
    }

    return balance(p);
}

struct node* array_init(struct node* p, int array[], int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        p = add(p, array[i]);
    }

    return p;
}

void add_tree_to_tree(struct node* p1, struct node* p2)
{
    if (p2)
    {
        p1 = add(p1, p2->key);
        add_tree_to_tree(p1, p2->left);
        add_tree_to_tree(p1, p2->right);
    }
}

void tree_free(struct node* p)
{
    if (p)
    {
        tree_free(p->left);
        tree_free(p->right);
        free(p);
    }
}

int main(void)
{
    printf("\n");
    struct node* tree1 = NULL;
    struct node* tree2 = NULL;
    int number1[MAX_LENG] = { 1, 2, 3, 4, 5, 6, 7 };
    int number2[MAX_LENG] = { 2, 3, 4, 5, 6, 7, 8 };
    tree1 = array_init(tree1, number1, MAX_LENG);
    tree2 = array_init(tree2, number2, MAX_LENG);
    printf("first tree :\n");
    print(tree1);
    printf("\nsecond tree :\n");
    print(tree2);
    printf("\nadd second tree to first :\n");
    add_tree_to_tree(tree1, tree2);
    print(tree1);
    printf("\n");
    tree_free(tree1);
    tree_free(tree2);
    return 0;
}