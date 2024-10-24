// C++ Program to merge two sorted lists
#include <bits/stdc++.h>
using namespace std;

class Node {
      public:
    int data;
    Node *next;
    Node(int key) {
        data = key;
        next = nullptr;
    }
};

Node *mergeUtil(Node *list1, Node *list2) {

    // if only one node in the first list
    // simply point its head to the second list
    if (!list1->next) {
        list1->next = list2;
        return list1;
    }

    // Initialize current and next pointers of
    // both lists
    Node *curr1 = list1, *next1 = list1->next;
    Node *curr2 = list2, *next2 = list2->next;

    while (next1 != NULL && curr2 != NULL) {

        // if curr2 lies in between curr1 and
        // next1 then do curr1->curr2->next1
        if (curr2->data >= curr1->data && curr2->data <= next1->data) {
            next2 = curr2->next;
            curr1->next = curr2;
            curr2->next = next1;

            // now let curr1 and curr2 point
            // to their immediate next pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else {

            // if more nodes in the first list
            if (next1->next != NULL) {
                next1 = next1->next;
                curr1 = curr1->next;
            }

            // else point the last node of the first list
            // to the remaining nodes of the second list
            else {
                next1->next = curr2;
                return list1;
            }
        }
    }
    return list1;
}

// Merges two given lists in-place. This function
// mainly compares head nodes and calls mergeUtil()
Node *merge(Node *list1, Node *list2) {
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    // start with the linked list
    // whose head data is the least
    if (list1->data < list2->data)
        return mergeUtil(list1, list2);
    else
        return mergeUtil(list2, list1);
}

void printList(Node *node) {
    while (node != nullptr) {
        cout << node->data << "  ";
        node = node->next;
    }
}

int main() {
  
    // 1->3->5 LinkedList created
    Node *list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    // 0->2->4 LinkedList created
    Node *list2 = new Node(0);
    list2->next = new Node(2);
    list2->next->next = new Node(4);

    Node *res = merge(list1, list2);

    printList(res);
    return 0;
}
