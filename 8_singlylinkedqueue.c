#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node *head = NULL;

void enqueue() 
{
    struct node *temp = head, *newnode;
    
    newnode = (struct node*)malloc(sizeof(struct node));
    
    if(newnode == NULL){
        printf("\n NO SPACE AVAILABLE \n");
        return;
    }
    
    newnode->link = NULL;
    
    printf("\n ENTER THE ELEMENT TO INSERT \n");
    scanf("%d", &newnode->data);
    
    if(head == NULL){
        head = newnode;
    }
    else{
        while(temp->link != NULL){
            temp = temp->link;
        }
        temp->link = newnode;
    }
    
    printf("\n  %d ELEMENT INSERTED SUCCESSFULLY \n", newnode->data);
}

void dequeue() 
{
    struct node *temp = head;

    if(head == NULL){
        printf("\n NO ELEMENTS \n");
        return;
    }

    printf("\n %d IS DELETED \n", temp->data);
    head = temp->link;
    free(temp);
}

void display() 
{
    struct node *temp = head;

    if(temp == NULL){
        printf("\n Queue is empty \n");
        return;
    }

    printf("\n Elements in the queue: \n");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
}

void search()
{
    struct node *temp = head;
    int pos = 0, found = 0, val;

    if(head == NULL){
        printf("\n Queue is empty \n");
        return;
    }

    printf("\n Enter the value to search");
    scanf("%d",&val);

    while(temp != NULL){
        if(temp->data == val){
            printf("\n %d found at %d \n", val, pos);
            found = 1;
            break;
        }
        temp = temp->link;
        pos++;
    }

    if(!found){
        printf("\n Element not found \n");
    }
}

int main()
{
    int choice;

    printf("\n *****QUEUE*****\n");
    printf(" 1->Enqueue() \n 2->Dequeue() \n 3->Display() \n 4->Search() \n 5->EXIT\n");

    do{
        printf("\n ENTER THE CHOICE \n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: search();
                    break;
            case 5: printf("\n EXIT \n");
                    break;
            default: printf("Enter a valid Choice");
        }

    } while(choice != 5);

    return 0;
}
