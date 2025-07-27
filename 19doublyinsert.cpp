#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* root = nullptr;

void add_node(int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = nullptr;
    new_node->prev = nullptr;

    if (root == nullptr)
        root = new_node;
    else
    {
        Node* current_node = root;
        while (current_node->next != nullptr) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
        new_node->prev = current_node;
    }
}

void insert_node(int index, int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = nullptr;
    new_node->prev = nullptr;

    if (index == 0)
    {
        new_node->next = root;
        if (root != nullptr)
            root->prev = new_node;
        root = new_node;
        return;
    }

    Node* current_node = root;
    for (int i = 0; i < index - 1 && current_node != nullptr; i++) {
        current_node = current_node->next;
    }

    if (current_node == nullptr)
    {
        printf("Index out of bound\n");
        delete new_node;
        return;
    }

    new_node->next = current_node->next;
    new_node->prev = current_node;
    if (current_node->next != nullptr) {
        current_node->next->prev = new_node;
    }
    current_node->next = new_node;
}

void display()
{
    Node* current_node = root;
    while (current_node != nullptr) {
        cout << current_node->data << " ";
        current_node = current_node->next;
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    for (int i = 0; i < n; i++)
        add_node(arr[i]);

    insert_node(2, 21);

    display();

    return 0;
}

