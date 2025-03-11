#include <stdio.h>
#include <stdlib.h>
struct SLL
{
    int data;
    struct SLL *next;
};
struct SLL *first, *last = NULL;
struct SLL *createNode(int element)
{
    struct SLL *NewNode;
    NewNode = (struct SLL *)malloc(sizeof(struct SLL));
    if (NewNode == NULL)
        return NULL;
    else
    {
        NewNode->data = element;
        NewNode->next = NULL;
        return NewNode;
    }
}
void insertAtBeginning(int element)
{
    struct SLL *NewNode = createNode(element);
    if (NewNode == NULL)
        printf("Cannot allocate memory");
    else
    {
        if (first == NULL)
            first = last = NewNode;
        else
        {
            NewNode->next = first;
            first = NewNode;
        }
        printf("%d was inserted at the beginning\n", first->data);
    }
}
void insertAtTheEnd(int element)
{
    struct SLL *NewNode = createNode(element);
    if (NewNode == NULL)
        printf("Cannot allocate memory");
    else
    {
        if (first == NULL)
            first = last = NewNode;
        else
        {
            last->next = NewNode;
            last = NewNode;
        }
        printf("%d was inserted at the end\n", last->data);
    }
}
int deleteFromBeginning()
{
    struct SLL *temp;
    int element = -1;
    if (first == NULL)
    {
        printf("List is empty\n");
    }
    else if (first->next == NULL)
    {
        temp = first;
        first = last = NULL;
        element = temp->data;
        free(temp);
    }
    else
    {
        temp = first;
        first = first->next;
        element = temp->data;
        free(temp);
    }
    return element;
}
int deleteFromEnd()
{
    struct SLL *temp;
    int element = -1;
    if (first == NULL)
    {
        printf("List is empty\n");
    }
    else if (first->next == NULL)
    {
        temp = first;
        first = last = NULL;
        element = temp->data;
        free(temp);
    }
    else
    {
        temp = first;
        while (temp->next != last)
        {
            temp = temp->next;
        }
        last = temp;
        temp = temp->next;
        element = temp->data;
        free(temp);
        last->next = NULL;
    }
    return element;
}
void display()
{
    struct SLL *temp;
    if (first == NULL)
    {
        printf("LIST IS EMPTY\n");
    }
    else
    {
        temp = first;
        do
        {
            printf("%d ->", temp->data);
            temp = temp->next;
        } while (temp != NULL);
        printf("NULL\n");
    }
}
void InsertAtPosition(int position, int element)
{
    if (position < 1)
        printf("Invalid Position\n");
    struct SLL *NewNode = createNode(element);
    struct SLL *temp;
    if (NewNode == NULL)
        printf("Cannot allocate memory");
    else if (position == 1)
    {
        NewNode->next = first;
        first = NewNode;
        printf("%d was inserted at the %d position\n", element, position);
    }
    else
    {
        temp = first;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        NewNode->next = temp->next;
        temp->next = NewNode;
        printf("%d was inserted at the %d position\n", element, position);
    }
}
void DeletionAtPosition(int position)
{
    if (position < 1)
        printf("Invalid Position\n");
    struct SLL *temp, *temp1;
    if (first == NULL)
        printf("LIST IS EMPTY");
    else if (position == 1)
        deleteFromBeginning();
    else if (position == last)
        deleteFromEnd();
    else
    {
        temp = first;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        temp1 = temp->next;
        temp->next = temp1->next;
        int element = temp1->data;
        free(temp1);
        printf("%d was deleted at the %d position\n", element, position);
    }
}
int main()
{
    insertAtBeginning(100);
    display();
    insertAtTheEnd(200);
    display();
    insertAtBeginning(500);
    display();

    int data = deleteFromBeginning();
    if (data != -1)
        printf("%d WAS DELETED FROM THE BEGINNING\n", data);
    display();
    data = deleteFromEnd();
    if (data != -1)
        printf("%d WAS DELETED FROM THE END\n", data);
    display();
    InsertAtPosition(2, 30);
    display();
    InsertAtPosition(2, 40);
    display();
    DeletionAtPosition(2);
    return 0;
}
