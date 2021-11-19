 //Write a program to create a linked list & perform operations such as insert, delete, update, reverse in the linked list//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void insertAtBeginning(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void insertAfter(struct Node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        cout << "the given previous node cannot be NULL";
        return;
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void insertAtEnd(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref; 

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

void deleteNode(struct Node **head_ref, int key)
{
    struct Node *temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;

    free(temp);
}

void push(struct Node **head_ref, int data)
{
    struct Node *Node;
    Node = (struct Node *)malloc(sizeof(struct Node));
    Node->data = data;
    Node->next = (*head_ref);
    (*head_ref) = Node;
}
void UpdateTheList(struct Node *head, struct Node *first)
{

    stack<int> s;
    Node *temp = head;

    while (first)
    {
        s.push(first->data);
        first = first->next;
    }

   
}
void reverse(struct Node **head_ref)
{
    struct Node *temp = NULL;
    struct Node *prev = NULL;
    struct Node *current = (*head_ref);
    while (current != NULL)
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    (*head_ref) = prev;
}


Node *find_mid(Node *head)
{
    Node *temp = head, *first = head, *second = head;

    while (second && second->next)
    {

        first = first->next;
        second = second->next->next;
    }

    if (second)
        first = first->next;

    return first;
}



void printList(struct Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{
    struct Node *head = NULL, *mid;

    insertAtEnd(&head, 27);
    insertAtBeginning(&head, 24);
    insertAtBeginning(&head, 23);
    insertAtEnd(&head,28);
    insertAfter(head->next,26);
    insertAfter(head->next,25);

    cout << "Linked list : " << endl;
    printList(head);

    cout << "\nAfter deleting an element : " << endl;
    deleteNode(&head, 26);
    printList(head);

    mid = find_mid(head);

    UpdateTheList(head, mid);
    cout << "\nUpdated List :" << endl;
    printList(head);

    cout << "\nList before reversing :" << endl;
    printList(head);
    reverse(&head);
    cout << endl;
    cout << "List after reversing :" << endl;
    printList(head);

    return 0;
}