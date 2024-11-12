#include<stdlib.h>
#include<stdio.h>

typedef struct Node{
    int value;
    struct Node *next;
} Node;

void add_tail(Node **root, int value)
{
    Node *element = malloc(sizeof(Node));
    element->value = value;
    element->next = NULL;
    if (*root == NULL)
    {
        *root = element;
    }
    else
    {
        Node *curr = *root;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = element;
    }
    return;
}

void add_head(Node **root, int value)
{
    Node *element = malloc(sizeof(Node));
    element -> value = value;
    element -> next = *root;
    *root = element;
    return;
}

void dealloc(Node **root)
{
    Node *curr = *root;
    Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        free(curr);
        curr = next;
    }
    *root = NULL;
    return;
}

int main(int argc, char const *argv[])
{
    Node *root = NULL;
    add_tail(&root, 12);
    add_tail(&root, 11);
    add_tail(&root, 10);

    add_head(&root, 104);

    for (Node *curr = root; curr != NULL; curr = curr -> next)
    {
        printf("\nElement: %d", curr -> value);
    }
    
    dealloc(&root);
    return 0;
}
