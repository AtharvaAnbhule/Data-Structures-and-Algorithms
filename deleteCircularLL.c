#include<stdio.h>
#include<stdlib.h>
// structure for Circular Linked List
struct Node
{
  int data;
  struct Node *next;
};

int calcSize (struct Node *head);

void deleteBegin(struct Node **head)
{

  struct Node *tempNode = *head;

  // if there are no nodes in Linked List can't delete
  if (*head == NULL)
    {
      printf ("Linked List Empty, nothing to delete");
      return;
    }

  // if only 1 node in CLL
  if (tempNode->next == *head)
    {
      *head = NULL;
      return;
    }

  struct Node *curr = *head;

  // traverse till last node in CLL
  while (curr->next != *head)
    curr = curr->next;

  // assign last node's next to 2nd node in CLL
  curr->next = (*head)->next;

  // move head to next node
  *head = (*head)->next;
  free (tempNode);
}

void deleteEnd (struct Node **head)
{
  struct Node *tempNode = *head;
  struct Node *previous;

  // if there are no nodes in Linked List can't delete
  if (*head == NULL)
    {
      printf ("Linked List Empty, nothing to delete");
      return;
    }

  // if Linked List has only 1 node
  if (tempNode->next == *head)
    {
      *head = NULL;
      return;
    }

  // else traverse to the last node
  while (tempNode->next != *head)
    {
      // store previous link node as we need to change its next val
      previous = tempNode;
      tempNode = tempNode->next;
    }
  // Curr assign 2nd last node's next to head
  previous->next = *head;
  // delete the last node
  free (tempNode);
  // 2nd last now becomes the last node
}

void deletePos (struct Node **head, int n)
{

  int size = calcSize (*head);

  if (n < 1 || size < n)
    {
      printf ("Can't delete, %d is not a valid position\n", n);
    }

  else if (n == 1)
    deleteBegin(head);

  else if (n == size)
    deleteEnd (head);

  else
    {
      struct Node *tempNode = *head;
      struct Node *previous;

      // traverse to the nth node 
      while (--n)
	{
	  // store previous link node as we need to change its next val 
	  previous = tempNode;
	  tempNode = tempNode->next;
	}

      // change previous node's next node to nth node's next node
      previous->next = tempNode->next;
      // delete this nth node
      free (tempNode);
    }
}

void insert (struct Node **head, int data)
{
  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));
  newNode->data = data;

  if (*head == NULL)
    {
      *head = newNode;
      (*head)->next = *head;
      return;
    }

  struct Node *curr = *head;

  while (curr->next != *head)
    {
      curr = curr->next;
    }

  curr->next = newNode;
  newNode->next = *head;
  *head = newNode;
}

int calcSize (struct Node *head)
{
  int size = 0;
  struct Node *temp = head;

  if (temp == NULL)
    return size;

  do
    {
      size++;
      temp = temp->next;

    }
  while (temp != head);

  return size;
}

void display (struct Node *head)
{
  // if there are no node in CLL
  if (head == NULL)
    return;

  struct Node *temp = head;

  //need to take care of circular structure of CLL
  do
    {
      printf ("%d ", temp->data);
      temp = temp->next;

    }
  while (temp != head);
  printf ("\n");
}

int main ()
{

  // first node will be null at creation    
  struct Node *head = NULL;

  insert (&head, 10);
  insert (&head, 11);
  insert (&head, 12);
  insert (&head, 13);
  insert (&head, 14);
  insert (&head, 15);
  insert (&head, 16);

  display (head);

  deleteBegin(&head);
  display (head);

  deleteEnd (&head);
  display (head);

  deletePos (&head, 3);
  display (head);

  return 0;
}
