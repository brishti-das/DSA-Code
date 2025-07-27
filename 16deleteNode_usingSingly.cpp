#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* root = nullptr;

void add_node(int data) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = nullptr;
    if (root == nullptr)
        root = new_node;
    else {
        Node* current_node = root;
        while (current_node->next != nullptr) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

void delete_node(int index)
{
    if (root == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    //delete last node
    if (index == -1) {
        if (root->next == nullptr) {
            delete root;
            root = nullptr;
            return;
        }
        Node* current_node = root;
        while (current_node->next->next != nullptr) {
            current_node = current_node->next;
        }
        delete current_node->next;
        current_node->next = nullptr;
        return;
    }

    // Delete node at specific index
    if (index == 0) {
        Node* temp = root;
        root = root->next;
        delete temp;
        return;
    }

    Node* current_node = root;
    for (int i = 0; i < index - 1 && current_node != nullptr; i++) {
        current_node = current_node->next;
    }
    if (current_node == nullptr || current_node->next == nullptr) {
        cout << "Index out of bound" << endl;
        return;
    }
    Node* temp = current_node->next;
    current_node->next = temp->next;
    delete temp;
}
void display()
{
    if (root == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = root;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    for (int i = 0; i < n; i++)
        add_node(arr[i]);

    delete_node(0);
    delete_node(2);
    delete_node(-1);

    display();

    return 0;
}
