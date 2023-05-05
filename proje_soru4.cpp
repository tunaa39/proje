#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* addLists(struct Node* list1, struct Node* list2) {
    struct Node *result = NULL, *prev = NULL, *temp = NULL;
    int carry = 0, sum;

    while (list1 != NULL && list2 != NULL) {
        sum = carry + list1->data + list2->data;
        carry = sum / 10;
        sum %= 10;

        temp = newNode(sum);

        if (result == NULL) {
            result = temp;
        } else {
            prev->next = temp;
        }

        prev = temp;
        list1 = list1->next;
        list2 = list2->next;
    }

    while (list1 != NULL) {
        sum = carry + list1->data;
        carry = sum / 10;
        sum %= 10;
        temp = newNode(sum);
        prev->next = temp;
        prev = temp;
        list1 = list1->next;
    }

    while (list2 != NULL) {
        sum = carry + list2->data;
        carry = sum / 10;
        sum %= 10;
        temp = newNode(sum);
        prev->next = temp;
        prev = temp;
        list2 = list2->next;
    }

    if (carry > 0) {
        temp = newNode(carry);
        prev->next = temp;
        prev = temp;
    }

    return result;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* list1 = newNode(2);
    list1->next = newNode(4);
    list1->next->next = newNode(3);

    struct Node* list2 = newNode(5);
    list2->next = newNode(6);
    list2->next->next = newNode(4);

    printf("Liste 1: ");
    printList(list1);
    printf("\nListe 2: ");
    printList(list2);

    struct Node* result = addLists(list1, list2);

    printf("\nSonuc: ");
    printList(result);
    printf("\n");

    return 0;
}




