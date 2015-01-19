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
        cout<<node->data<<"-->";
        node = node->next;
    }
    cout<<"\n\n";
}

void removeCopies(struct node *start)
{
  struct node *temp, *aux, *dup;
  temp = start;

  while(temp!= NULL)
  {
     aux = temp;
     while(aux->next != NULL)
     {
       if(temp->data == aux->next->data)
       {
          dup = aux->next;
          aux->next = aux->next->next;
          free(dup);
       }
       else
       {
          aux = aux->next;
            
       }
     }
     temp = temp->next;
  }

  cout<<"\n The Modified list is:\n";
  printList(start);
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
    add(&head, 67);
    cout <<"\nThe Linked List, for now is:\n";
    printList(head);
    removeCopies(head);
    return 0;
}


