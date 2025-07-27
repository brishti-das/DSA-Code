#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* root = nullptr;

void add_node(int data)
{
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

int count_nodes()
{
    int count = 0;
    Node* current_node = root;
    while (current_node != nullptr) {
        count++;
        current_node = current_node->next;
    }
    return count;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    for (int i = 0; i < n; i++)
        add_node(arr[i]);

    cout << "Number of nodes in the list: " << count_nodes() << endl;
    return 0;
}
