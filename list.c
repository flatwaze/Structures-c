#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void print(Node *list);
void push(Node **list, int data);
int isFull(Node *list);
int pop(Node **list);
int length(Node *list);
int findByIndex(Node *list, int index);
int findByData(Node *list, int data);
void insert(Node *list, int data, int index);
int delete(Node *list, int index);


void print(Node *list){
    Node *tmp = list;
    while (tmp != NULL){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

void push(Node **list, int data){
    Node *tmp = malloc(sizeof(Node));
    tmp->data = data;
    tmp->next = (*list);
    (*list) = tmp;
}

int isFull(Node *list){
    if (list == NULL) return 0;
    return 1;
}

int pop(Node **list){
    Node *tmp = (*list);
    int data = tmp->data;
    (*list) = tmp->next; 
    free(tmp);
    return data;
}

int length(Node *list){
    int len = 0;
    Node *tmp = list;
    while(tmp != NULL){
        len++;
        tmp = tmp->next;
    }
    return len;
}

//starts from 1
int findByIndex(Node *list, int index){
    int i = 0;
    Node *tmp = list;
    while(i < index - 1){
        i++;
        tmp = tmp->next;
    }
    int data = tmp->data;
    return data;
}

//starts from 1, returns first Node with equal data
int findByData(Node *list, int data){
    int i = 0;
    Node *tmp = list;
    while (tmp != NULL){
        i++;
        if (tmp->data == data) return i;
        tmp = tmp->next;
    }
    return -1;
}

//starts from 0, I gotta fix dis
void insert(Node *list, int data, int index){
    int i = 0;
    Node *tmp = list;
    while(i < index - 1){
        i++;
        tmp = tmp->next;
    }
    Node *itmp = malloc(sizeof(Node));
    itmp->data = data;
    itmp->next = tmp->next;
    tmp->next = itmp;
}

int delete(Node *list, int index){
    int i = 0;
    Node *tmp = list;
    while (i < index - 2){
        i++;
        tmp = tmp->next;
    }
    Node *prev = tmp;
    tmp = tmp->next;
    Node *itmp = tmp;
    int data = itmp->data;
    prev->next = itmp->next;
    return data;
}

int main()
{
    Node *list = NULL;
    Node a = {1}, b = {2}, c = {3}, d = {4};
    list = &a;
    a.next = &b;
    b.next = &c;
    c.next = NULL;
    push(&list, 4);
    pop(&list);
    print(list);
    printf("%d\n", length(list));
    printf("%d\n", findByIndex(list, 2));
    printf("%d\n", findByData(list, 200));
    insert(list, 5, 2);
    delete(list, 2);
    print(list);
    return 0;
}
