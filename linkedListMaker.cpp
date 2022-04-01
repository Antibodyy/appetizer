#include <bits/stdc++.h>
using namespace std;
struct Node
{   
    string data;
    Node* next;
};

void push(Node** prevHead, string str)
{
    Node* newNode = new Node();
    newNode->data = str;
    newNode->next = *prevHead;
    *prevHead = newNode;
}
void append(Node** headptr, string str)
{
    Node* newNode = new Node();
    Node* last = *headptr;
    newNode->data = str;
    newNode->next = nullptr;
    while(last->next!= nullptr)
    {
        last = last->next;
    }
    last->next = newNode;
}
void insertAfter(Node* prevNode, string str)
{
    Node* newNode = new Node();
    newNode->data = str;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}
void deleteNode(Node** head, string str)
{
    Node* tempNode = *head;
    while(tempNode->next!=nullptr && (tempNode->next)->data != str)
      tempNode = tempNode->next;
    if((tempNode->next)->data == str)
    {
        delete tempNode->next;
        tempNode->next = (tempNode->next)->next;
    }
}
void deleteSpecNode(Node** head, int pos)
{
    Node* temp = *head;
    for(int x=1; x<pos; x++)
    {
        temp = temp->next;
    }
    Node* temp2 = (temp->next)->next;
    delete temp->next;
    temp->next = temp2; 

}

void printList(Node* head)
{
    while(head != nullptr)
    {
        cout<<head->data<<"\n";
        head = head->next;
    }
}
int main()
{
    Node* head = new Node();
    head->data = "beaches";
    push(&head,"LOL");
    append(&head, "abc");
    insertAfter(head->next,"LULW");
    //deleteNode(&head,"abc");
    //deleteSpecNode(&head, 2);
    printList(head);
}