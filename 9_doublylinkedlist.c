#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node {
    int data;
    struct node *Llink;
    struct node *Rlink;
};

struct node *head = NULL;

void insertFirst() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL) {
        printf("\n No Space available");
        return;
    }

    newnode->Llink = NULL;
    newnode->Rlink = NULL;

    printf("\n Enter the element to insert");
    scanf("%d", &newnode->data);

    if(head == NULL) {
        head = newnode;
    }
    else {
        newnode->Rlink = head;
        head->Llink = newnode;
        head = newnode;
    }
    printf("\n %d inserted sucessfully", newnode->data);
}

void insertLast() {
    struct node *newnode, *temp = head;
    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL) {
        printf("\n Error: No space available for a new node.\n");
        return;
    }

    newnode->Llink = NULL;
    newnode->Rlink = NULL;

    printf("\n Enter the element to insert");
    scanf("%d", &newnode->data);

    if(head == NULL) {
        head = newnode;
    }
    else {
        while(temp->Rlink != NULL) {
            temp = temp->Rlink;
        }
        temp->Rlink = newnode;
        newnode->Llink = temp;
    }

    printf("%d inserted succesfully", newnode->data);
}

void insertLocation() {
    struct node *newnode, *temp = head;
    int key;

    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL) {
        printf("\n NO space available \n");
        return;
    }

    printf("\n Enter the key were after you want to add Element ");
    scanf("%d", &key);

    printf("\n Enter the Element to inserted ");
    scanf("%d", &newnode->data);

    while(temp != NULL && temp->data != key) {
        temp = temp->Rlink;
    }

    if(temp == NULL) {
        printf("\n key not found \n");
        return;
    }

    newnode->Rlink = temp->Rlink;
    newnode->Llink = temp;

    if(temp->Rlink != NULL)
        temp->Rlink->Llink = newnode;

    temp->Rlink = newnode;

    printf("\n %d inserted successfully", newnode->data);
}

void deleteFirst() {
    struct node *temp = head;

    if(head == NULL) {
        printf("\n List Empty");
        return;
    }

    printf("\n %d deleted from front", temp->data);

    head = head->Rlink;

    if(head != NULL)
        head->Llink = NULL;

    free(temp);
}

void deleteLast() {
    struct node *temp = head;

    if(head == NULL) {
        printf("\n List Empty");
        return;
    }

    if(head->Rlink == NULL) {
        printf("\n %d deleted", head->data);
        free(head);
        head = NULL;
        return;
    }

    while(temp->Rlink != NULL) {
        temp = temp->Rlink;
    }

    printf("\n %d deleted", temp->data);

    temp->Llink->Rlink = NULL;
    free(temp);
}

void deleteLocation() {
    struct node *temp = head;
    int key;

    if(head == NULL) {
        printf("\n List Empty");
        return;
    }

    printf("\n Enter the key to delete");
    scanf("%d", &key);

    while(temp != NULL && temp->data != key) {
        temp = temp->Rlink;
    }

    if(temp == NULL) {
        printf("\n Element not found \n");
        return;
    }

    if(temp->Llink != NULL)
        temp->Llink->Rlink = temp->Rlink;

    if(temp->Rlink != NULL)
        temp->Rlink->Llink = temp->Llink;

    if(temp == head)
        head = temp->Rlink;

    printf("\n %d deleted successfully", key);
    free(temp);
}

void search() {
    int key, pos = 0, found = 0;
    struct node *temp = head;

    if(head == NULL) {
        printf("\n LIST EMPTY \n");
        return;
    }

    printf("\n Enter the key to search");
    scanf("%d", &key);

    while(temp != NULL) {
        if(temp->data == key) {
            printf("%d is found at location %d", temp->data, pos);
            found = 1;
            break;
        }
        temp = temp->Rlink;
        pos++;
    }

    if(!found)
        printf("\n ELEMENT NOT FOUND \n");
}

void display() {
    struct node *temp = head;

    if(head == NULL) {
        printf("\n NO ELEMENTS IN LIST ");
        return;
    }

    printf("\n ** ELEMENTS IN LIST **  \n");

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->Rlink;
    }
}

void main() {
    int choice;

    do {
        printf("\n*****DOUBLY LINKEDLIST ****\n");
        printf("\n 1-> insert First  \n  2->insert Last  \n  3->insert Location  \n  4->delete First");
        printf("\n  5->delete Last  \n  6->delete Location  \n 7-> Search  \n  8->Display  \n  9->Exit  \n");

        printf("Enter the choice ");
        scanf("%d",&choice);

        switch(choice) {
            case 1: insertFirst(); break;
            case 2: insertLast(); break;
            case 3: insertLocation(); break;
            case 4: deleteFirst(); break;
            case 5: deleteLast(); break;
            case 6: deleteLocation(); break;
            case 7: search(); break;
            case 8: display(); break;
            case 9: exit(0);
            default: printf("enter valid choice"); break;
        }

    } while(choice != 9);
}
