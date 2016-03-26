#include <iostream>
#include "list.h"

using namespace std;

template <typename T>
bool List<T>::find(const T *file)
{
  int findCheck = 0, findCheck2 = 0;

  while(curr)
  {
    if(*(curr->data) == *file)
    {
      return (curr->data)->find(file);
    } //file found
    
    else //go backwards
      if(*(curr->data) > *file) 
    {
      findCheck = 1;

      if (curr->prev) curr = curr->prev;
      else return false; //past head
    } //go backwards
    
    else // go forwards
      if(*(curr->data) < *file) 
    {
      findCheck2 = 1;

      if (curr->next) curr = curr->next;
      else return false; //past tail
    } // go forwards  
    
    if(findCheck == 1 && findCheck2 == 1) break;
  }//walking list
  
  return false;
}//find

template <typename T>
ListNode<T>::ListNode(T *dat, ListNode<T>* pre, ListNode<T>* nex): 
  data(dat), prev(pre), next(nex)
{
} // listNode constructor

template <typename T>
ListNode<T>::~ListNode()
{
  delete data;
}// ListNode destructor

template <typename T>
List<T>::List(): head(NULL), curr(NULL)
{ 
}// List constructor

template <typename T>
List<T>::~List()
{ 
  for(curr = head; curr; curr = head)
  {
    head = curr->next;
    delete curr;
  }// delete List
}// List destructor

template <typename T>
void List<T>::traverseBack(T *dat)
{
  while(curr->prev != NULL)
  {
    curr = curr->prev;

    if(*(curr->data) == *dat)
    {
      curr->data->insert(dat);
      return;
    } // inside directory

    if(*(curr->data) < *dat)  
    {
      curr->next = (curr->next->prev = 
                    new ListNode<T>(dat, curr, curr->next)); 
      return;
    } // position found   
  } // traverse backwards if possible

  if(curr->prev == NULL) // create new head
    head = (curr->prev = new ListNode<T>(dat, NULL, curr));
} // traverseBack

template <typename T>
void List<T>::traverseForw(T *dat)
{
  while(curr->next != NULL)
  {
    curr = curr->next;

  if(*(curr->data) == *dat)
  {
    curr->data->insert(dat);
    return;
  } // inside directory

  if(*(curr->data) > *dat)  
  {
    curr->prev = (curr->prev->next = 
                  new ListNode<T>(dat, curr->prev, curr)); 
    return;
  } // position found    
    } // traverse forwards if possible
      
  if(curr->next == NULL) // create new tail
    curr->next = new ListNode<T>(dat, curr, NULL);
} // traverseForw()

template <typename T>
void List<T>::insert(T *dat)
{ 
  if(head == NULL)
  {
    head = new ListNode<T>(dat, NULL, NULL); 
    curr = head;
    return;
  } // create head
  
  if(*(curr->data) == *dat) 
  {
    curr->data->insert(dat);
    return;
  } // inside directory
    
  else // traverse backwards
    if(*(curr->data) > *dat) 
  this->traverseBack(dat);   

  else // traverse forwards
    if(*(curr->data) < *dat) 
  this->traverseForw(dat);
} // insert()

template <typename T>
void List<T>::print()
{
  for(curr = head; curr; curr = curr->next)
    cout << (curr->data)->getName() << endl;
  curr = head;
}// print()
