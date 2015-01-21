#include <iostream>
#include <malloc.h>
using namespace std;

struct node{
int data;
node* next;
};
void removeCopies(struct node *head);
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

void mergeLists(node* head, node* tail)
{
  node *finalList = NULL;
  node *last = NULL;
  node *temp = finalList;
  int a,b,c;

  while(head!=NULL && tail!=NULL)
  {
      add(&finalList,head->data);
      add(&finalList,tail->data);
      head = head->next;
      tail = tail->next;
  }

  while(finalList!=NULL)
  {         temp = finalList;
      while(temp->next!=NULL)
      {
          a = finalList->data;
              b = temp->next->data;
          if(finalList->data > temp->next->data)
          {

             add(&last,a);
          }
          else add(&last,b);
          temp = temp->next;
      }
      finalList = finalList->next;
  }

  removeCopies(last);
  cout<<"\n The Merged List is:\n ";
  printList(last);

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
    node* tail = NULL;
    add(&head, 1);
    add(&head, 3);
    add(&head, 5);
    add(&head, 7);
    add(&head, 9);
    add(&head, 11);
    add(&head, 13);
    add(&tail, 2);
    add(&tail, 4);
    add(&tail, 6);
    add(&tail, 8);
    add(&tail, 10);
    add(&tail, 12);
    add(&tail, 14);
    cout <<"\nThe First Linked List is:\n";
    printList(head);
    cout <<"\nThe Second Linked List is:\n";
    printList(tail);
    mergeLists(head,tail);
    return 0;
}
