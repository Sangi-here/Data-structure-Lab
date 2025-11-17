#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head = NULL;

void insertFirst()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("\n NO space avilable \n");
        return;
    }

    printf("\n Enter the value to insert to Front \n");
    scanf("%d",&newnode->data);

    newnode->link = NULL;

    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->link = head;
        head = newnode;
    }

    printf("\n value inserted successfully %d \n", newnode->data);
}

void insertLast()
{
    struct node *newnode, *temp = head;
    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("\n NO space available \n");
        return;
    }

    newnode->link = NULL;

    printf("\n Enter the element to insert Last \n");
    scanf("%d",&newnode->data);

    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newnode;
    }

    printf("\n element inserted successfully  %d \n", newnode->data);
}

void insertLocation()
{
    struct node *newnode, *temp = head;
    int key;

    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("\n NO space available \n");
        return;
    }

    printf("\n Enter the key were after you want to add Element \n");
    scanf("%d",&key);

    printf("\n Enter the Element to inserted \n");
    scanf("%d",&newnode->data);

    while(temp != NULL && temp->data != key)
    {
        temp = temp->link;
    }

    if(temp == NULL)
    {
        printf("\n key not found \n");
        return;
    }

    newnode->link = temp->link;
    temp->link = newnode;

    printf("\n value inserted successfully %d \n", newnode->data);
}

void deleteFirst()
{
    struct node *temp = head;

    if(head == NULL)
    {
        printf("\n List Empty \n");
        return;
    }

    printf("\n %d deleted from front\n", temp->data);
    head = head->link;
    free(temp);
}

void deleteLast()
{
    struct node *temp = head, *prev;

    if(head == NULL)
    {
        printf("\n List Empty \n");
        return;
    }

    if(head->link == NULL)
    {
        printf("\n %d deleted \n", head->data);
        free(head);
        head = NULL;
        return;
    }

    while(temp->link != NULL)
    {
        prev = temp;
        temp = temp->link;
    }

    printf("\n %d deleted \n", temp->data);
    prev->link = NULL;
    free(temp);
}

void deleteLocation()
{
    struct node *temp = head, *prev;
    int key;

    if(head == NULL)
    {
        printf("\n List Empty \n");
        return;
    }

    printf("\n Enter element to delete \n");
    scanf("%d",&key);

    if(head->data == key)
    {
        temp = head;
        head = head->link;
        free(temp);
        printf("\n %d deleted \n", key);
        return;
    }

    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->link;
    }

    if(temp == NULL)
    {
        printf("\n Element not found \n");
        return;
    }

    prev->link = temp->link;
    printf("\n %d deleted \n", key);
    free(temp);
}

void search()
{
    struct node *temp = head;
    int val, pos = 0, found = 0;

    if(head == NULL)
    {
        printf("\n List Empty \n");
        return;
    }

    printf("\n Enter the value to search");
    scanf("%d",&val);

    while(temp != NULL)
    {
        if(temp->data == val)
        {
            printf("\n%d value found at %d location  \n", val, pos);
            found = 1;
            break;
        }
        temp = temp->link;
        pos++;
    }

    if(!found)
        printf("\n Element not found \n");
}

void display()
{
    struct node *temp = head;

    if(temp == NULL)
    {
        printf("\n List Empty");
        return;
    }

    printf("\n Elements in the List \n");

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
}

void main()
{
    int choice;

    printf("\n SINGLY LINKED LIST \n");

    do
    {
        printf("\n 1-> InsertFirst \n 2-> InsertLast \n 3-> Insert Location \n 4-> Delete first \n");
        printf(" 5-> Delete last \n 6-> Delete location \n 7-> Search \n 8-> Display \n 9-> Exit");

        printf("\n Enter Choice: \n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: insertFirst();
                    break;
            case 2: insertLast();
                    break;
            case 3: insertLocation();
                    break;
            case 4: deleteFirst();
                    break;
            case 5: deleteLast();
                    break;
            case 6: deleteLocation();
                    break;
            case 7: search();
                    break;
            case 8: display();
                    break;
            case 9: return;
            default: printf("\n INVALID CHOICE \n");
        }

    } while(choice != 9);
}
