#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* root = NULL;

void add_node(int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (root == NULL)
        root = new_node;
    else {
        struct Node* current_node = root;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

void insert_node(int index, int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (index == 0)
        {
        new_node->next = root;
        root = new_node;
        return;
    }
    struct Node* current_node = root;
    for (int i = 0; i < index - 1 && current_node != NULL; i++) {
        current_node = current_node->next;
    }
    if (current_node == NULL) {
        printf("Index out of bound\n");
        free(new_node);
        return;
    }
    new_node->next = current_node->next;
    current_node->next = new_node;
}

void display()
{
    if (root == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = root;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    for (int i = 0; i < n; i++)
        add_node(arr[i]);

    insert_node(0, 50);
    insert_node(2, 10);
    insert_node(7, 20);

    display();

    return 0;
}
