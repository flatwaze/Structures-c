#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void print(Node *list);
void push(Node **list, int data);
int isFull(Node *list);
int pop(Node **list);
int length(Node *list);
int findByIndex(Node *list, int index);
int findByData(Node *list, int data);
void insert(Node *list, int data, int index);
int delete (Node *list, int index);

void print(Node *list)
{
    Node *tmp = list;
    while (tmp != NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
    tmp = NULL;
    free(tmp);
}

void push(Node **list, int data)
{
    Node *tmp = malloc(sizeof(Node));
    tmp->data = data;
    tmp->next = (*list);
    (*list) = tmp;
    tmp = NULL;
    free(tmp);
}

int isFull(Node *list)
{
    if (list == NULL)
        return 0;
    return 1;
}

int pop(Node **list)
{
    Node *tmp = (*list);
    int data = tmp->data;
    (*list) = tmp->next;
    tmp = NULL;
    free(tmp);
    return data;
}

int length(Node *list)
{
    int len = 0;
    Node *tmp = list;
    while (tmp != NULL)
    {
        len++;
        tmp = tmp->next;
    }
    tmp = NULL;
    free(tmp);
    return len;
}

// starts from 1
int findByIndex(Node *list, int index)
{
    int i = 0;
    Node *tmp = list;
    while (i < index - 1)
    {
        i++;
        tmp = tmp->next;
    }
    int data = tmp->data;
    tmp = NULL;
    free(tmp);
    return data;
}

// starts from 1, returns first Node with equal data
int findByData(Node *list, int data)
{
    int i = 0;
    Node *tmp = list;
    while (tmp != NULL)
    {
        i++;
        if (tmp->data == data)
            return i;
        tmp = tmp->next;
    }
    tmp = NULL;
    free(tmp);
    return -1;
}

// starts from 1
void insert(Node *list, int data, int index)
{
    int i = 0;
    Node *tmp = list;
    while (i < index - 2)
    {
        i++;
        tmp = tmp->next;
    }
    Node *itmp = malloc(sizeof(Node));
    itmp->data = data;
    itmp->next = tmp->next;
    tmp->next = itmp;
    tmp = NULL;
    itmp = NULL;
    free(tmp);
    free(itmp);
}

// starts from 1
int delete (Node *list, int index)
{
    int i = 0;
    Node *tmp = list;
    while (i < index - 2)
    {
        i++;
        tmp = tmp->next;
    }
    Node *prev = tmp;
    tmp = tmp->next;
    Node *itmp = tmp;
    int data = itmp->data;
    prev->next = itmp->next;
    tmp = NULL;
    itmp = NULL;
    prev = NULL;
    free(tmp);
    free(itmp);
    free(prev);
    return data;
}

int main()
{
    printf("Check...\n");
    Node *list = NULL;
    for (int i = 0; i < 10; i++)
        push(&list, i);
    printf("Pushed: ");
    print(list);
    for (int i = 0; i < 3; i++)
    {
        printf("%d have been popped\n", pop(&list));
    }

    insert(list, 77, 5);
    insert(list, 88, 4);
    printf("Inserted: ");
    print(list);

    printf("%d have been deleted\n", delete (list, 3));
    printf("%d have been deleted\n", delete (list, 2));

    printf("Final result: ");
    print(list);
    return 0;
}
