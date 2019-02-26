#include <iostream>

struct Node {
    int   data;
    Node* next;
};

Node* arrayToList(const int arr[], size_t size) {
        // ...
}

Node* removeOdd(Node* head) {
    // ...
}

void showList(const Node* head) {
    // ...
}

void deleteList(Node*& head) {
    // ...
}

int main() {
    int arr[] = {1,2,3,4,5,6};
    size_t size = sizeof(arr)/sizeof(*arr);
    Node* head = arrayToList(arr,size);
    showList(head);
    head = removeOdd(head);
    showList(head);
    deleteList(head);
    showList(head);
}
