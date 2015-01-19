#include <iostream>
#include <malloc.h>
using namespace std;

struct node{
int data;
node* next;
};

void add (node** head_ref, int new_data)
{

     node* new_node =
        (node*) malloc(sizeof(struct node));

    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList (node *node)
{
    while (node != NULL)
    {
        cout<<"\n"<<node->data;
        node = node->next;
    }
}

void removeCopies(node *head)
{
  node *temp = head;
  node *aux = head;
  node *auxi = NULL;
  int x = head->next->data;
  while(head!=NULL)
  {

      head = head->next;
  }
  while(aux!=NULL)
  {
      add(&auxi,aux->data);
      aux = aux->next;
  }
  head = auxi;
  cout<<"\n Modified List is:\n";
  printList(head);
}

int main()
{

    node* head = NULL;
    add(&head, 67);
    add(&head, 14);
    add(&head, 14);
    add(&head, 18);
    add(&head, 45);
    add(&head, 16);
    add(&head, 16);
    cout <<"\nThe Linked List, for now is:\n";
    printList(head);
    removeCopies(head);
    return 0;
}


