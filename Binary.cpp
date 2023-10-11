#include <iostream>

// Define a basic linked list node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function for binary search on the linked list
Node* binarySearch(Node* head, int target) {
    Node* low = head;
    Node* high = nullptr;

    while (low != high) {
        Node* mid = low;
        int count = 0;

        while (mid != high) {
            mid = mid->next;
            count++;
        }

        mid = low;
        for (int i = 0; i < count / 2; i++) {
            mid = mid->next;
        }

        if (mid->data == target) return mid;
        if (mid->data < target) low = mid->next;
        else high = mid;
    }

    return nullptr; // Not found
}

int main() {
    // Create a sorted linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int target = 3;
    Node* result = binarySearch(head, target);

    if (result) {
        std::cout << "Found: " << result->data << std::endl;
    } else {
        std::cout << "Not found." << std::endl;
    }

    // Don't forget to deallocate memory for the linked list in a real application
    delete head;
    return 0;
}
