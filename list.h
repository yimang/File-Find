#ifndef LIST_H
#define LIST_H

template <class T>
class List;

template <class T>
class ListNode
{
  T* data;
  ListNode<T> *prev;
  ListNode<T> *next;
  friend class List<T>;
public:
  ListNode(T *dat, ListNode<T> *pre, ListNode<T> *nex);
  ~ListNode();
}; // ListNode

template <class T>
class List
{
  ListNode<T> *head;
  ListNode<T> *curr;
  void traverseBack(T *dat);
  void traverseForw(T *dat);
public:
  List();
  ~List();
  bool find(const T *file);
  void insert(T *dat);
  void print();
}; // List

#include "list.cpp"

#endif // LIST_H