#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* mergeLists(Node* list1, Node* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    Node* mergedList = NULL;
    if (list1->data <= list2->data) {
        mergedList = list1;
        mergedList->next = mergeLists(list1->next, list2);
    } else {
        mergedList = list2;
        mergedList->next = mergeLists(list1, list2->next);
    }
    return mergedList;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);
	Node* list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);
    Node* mergedList = mergeLists(list1, list2);
    printf("Birleþtirilmiþ Liste: ");
    printList(mergedList);

    return 0;
}

