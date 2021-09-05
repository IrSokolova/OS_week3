#include<stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;


void addNode(int data, Node *head) {
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp -> data = data;
    tmp -> next = NULL;
    Node *p = head;
    while (p -> next != NULL)
        p = p -> next;
    p -> next = tmp;
}

Node* deleteNode(int data, Node *head){

        Node *tmp = head->next, *current = NULL;

        if (head->next == NULL)
            printf("The list is empty\n");
        else {

        while (tmp && tmp -> data != data)
        {
            current = tmp;
            tmp = tmp -> next;
        }

        if (tmp == head->next)
        {
            head -> next = tmp->next;
            return head;
        }
        if (!tmp)
            printf("The element is not on the list\n");
        else {
            current->next = tmp->next;
            free(tmp);
        }
        return head;
    }
}


void printList(Node *head){
    if (head->next==NULL){
        printf("The list is empty");
    } else {
        head = head->next;
        printf("Current list: ");
        while (head != NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
    }
    printf("\n");
}



int main()
{
    Node *head = (Node*)malloc(sizeof(Node));
    head -> next = NULL;

    int operation;
    int end = 0;
    int value;
    while (end!=1){
        printf("List of operations: 1-Add node, 2-Delete node, 3-Print list, 0-Finish the work\n");
        scanf("%d", &operation);
        switch (operation) {
            case 1:
                printf("Enter the value\n");
                scanf("%d", &value);
                addNode(value, head);
                break;
            case 2:
                printf("Enter the value\n");
                scanf("%d", &value);
                head = deleteNode(value, head);
                break;
            case 3:
                printList(head);
                break;
            case 0:
                end=1;
                break;
        }
    }

    return 0;
}
