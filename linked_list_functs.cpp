/*====
  a collection of functions I hope will be useful
      for linked lists created using the Node class

  by: Sharon Tuttle
  and: Casey Cooper and Joey Dugan
  last modified: 2022-03-31 - adding sum_list, insert_at_end, remove_from_front - Joey Dugan, Sharon Tuttle
                 2022-03-25 - adding get_size, remove_at - Casey Cooper, Joey Dugan
                 2022-03-24 - adding print_list, delete_list, search_for - Joey Dugan
                 2022-03-23 - starting with insert_at_front - Joey Dugan
====*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "Node.h"
using namespace std;

/*----
  signature: insert_at_front: Node*& NodeDataType -> void
  purpose: expects a start pointer to a linked list
      PASSED BY REFERENCE, and data desired for the new first
      list element, has the side-effects of:
      *   creating a new Node with this data
      *   adding that Node to the FRONT of this
          linked list (CHANGING the argument pointer's
          value),
      and returns nothing
  tests:
      for:
      Node* head = NULL;

      insert_at_front(head, 47);  // change for new NodeDataType

      after this:
      head->get_data() == 47
      head->get_next() == NULL

      if I then do:

      insert_at_front(head, 36);

      after this:
      head->get_data() == 36
      head->get_next()->get_data() == 47

  by: Sharon Tuttle
  last modified: 2022-03-23
----*/

void insert_at_front(Node*& start_ptr, NodeDataType new_element)
{
    Node* new_node_ptr;

    // make the new first node, with the desired list element

    new_node_ptr = new Node(new_element);

    // if the list is currently empty, make this new node
    //    the first node in this list

    if (start_ptr == NULL)
    {
        start_ptr = new_node_ptr;
    }

    // if the list is NOT empty right now, make this new node
    //    the new first element (and LEAD to the "old" first)

    else
    {
        // BUT note the ORDER here -- make the new node lead
        //     to the previous starting node FIRST!

        new_node_ptr->set_next(start_ptr);
        start_ptr = new_node_ptr;
    }
}

/*----
  signature: print_list: Node* -> void
  purpose: expects a pointer to the beginning of a linked
      list, has the side-effect of printing the data in each
      node to the screen, and returns nothing
  tests:
      for:
      Node *my_first = NULL;

      print_list(my_first);

List:
=====
=====

      insert_at_front(my_first, 13);
      insert_at_front(my_first, 5);
      insert_at_front(my_first, 24);
      print_list(my_first);

List:
=====
13
5
24
=====
----*/

void print_list(Node *start_ptr)
{
    cout << "\nList:" << endl
         << "=====" << endl;

    Node *curr_node_ptr = start_ptr;

    while (curr_node_ptr != NULL)
    {
        cout << curr_node_ptr->get_data() << endl;
        curr_node_ptr = curr_node_ptr->get_next();
    }

    cout << "=====" << endl;
}

/*----
  signature: delete_list: Node*& -> int
  purpose: expects a pointer to a linked list
      PASSED BY REFERENCE of dynamically-allocated
      nodes to be freed, has the side-effect
      of freeing all the nodes in that list,
      sets the pointer ARGUMENT to NULL,
      and returns the number of nodes freed
  tests:
      for:
      Node* begin = NULL;

      delete_list(begin) == 0

      and then:
      insert_at_front(begin, 25);
      insert_at_front(begin, 80);
      insert_at_front(begin, 1);
      insert_at_front(begin, 9);

      delete_list(begin) == 4

----*/

int delete_list(Node*& start_ptr)
{
    Node* curr_ptr = start_ptr;
    int num_freed = 0;

    while (curr_ptr != NULL)
    {
       // make start_ptr point to next node

       start_ptr = start_ptr->get_next();

       // now it is safe to delete node curr_ptr is pointing to

       // uncomment for testing purposes
       //cout << "about to delete node w/data: "
       //     << curr_ptr->get_data() << endl;

       delete curr_ptr;
       num_freed++;

       // now make curr_ptr point again to same node as start_ptr

       curr_ptr = start_ptr;
    }

    return num_freed;
}

/*---
  signature: search_for: Node* NodeDataType -> bool
  purpose: expects a pointer to the start of a linked list
     and a value of interest, and returns whether or not
     that value is anywhere in that list

  NOTE: *MAY* NEED TO BE MODIFIED IF NodeDataType is CHANGED!

  tests:
      for:
      Node* stuff = NULL;

      insert_at_front(stuff, 300);
      insert_at_front(stuff, 400);
      insert_at_front(stuff, 250);
      insert_at_front(stuff, 400);
      insert_at_front(stuff, 25);

      search_for(stuff, 12) == false
      search_for(stuff, 25) == true
      search_for(stuff, 400) == true
---*/

bool search_for(Node* start_ptr, NodeDataType desired_val)
{
    Node* curr_ptr = start_ptr;
    bool found = false;  // have not found desired value yet!

    // continue looking until you either run out of list
    //     or find the desired value

    while ((curr_ptr != NULL) && (found == false))
    {
        // NOTE: *may* need to change this bool is NodeDataType is
        //     changed

        if (curr_ptr->get_data() == desired_val)
        {
            found = true;
        }
        else
        {
            // if have not found desired value yet, continue to
            //     next node

            curr_ptr = curr_ptr->get_next();
        }
    }

    // when exit loop, found should be true if desired value was found,
    //     and false if ran out of list without finding it

    return found;
}

// put design recipe steps for your Week 9 Lab Exercise functions here

/*----
  signature: get_size: Node* -> int
  purpose: expects a pointer to the beginning of a linked list of Node instances,
            and returns the number of Nodes in the list

  tests:
    for:
    Node* head = NULL;
    get_size(head) == 0

    insert_at_front(head, 3);
    insert_at_front(head, 5);
    insert_at_front(head, 7);
    insert_at_front(head, 9);
    insert_at_front(head, 4);

    get_size(head) == 5


  by: Casey Cooper and Joey Dugan
----*/

int get_size(Node* start_ptr)
{
    Node* curr = start_ptr;
    int count = 0;

    while (curr != NULL)
    {
        count ++;
        curr = curr->get_next();
    }

    return count;
}

/*----
  signature: remove_from_front: Node*& -> NodeDataType
  purpose: expects a pointer to the beginning of a linked list
      of Node instances PASSED BY REFERENCE, has the side-effects
      of removing JUST the first node from that list (if there
      is one) and freeing/deallocating that node's memory,
      and returns the value in the data field of the 
      removed-and-deleted node.

      If the list is empty, this returns 0. [THIS WILL LIKELY NEED
      TO BE CHANGED IF NodeDataType IS CHANGED!]
 
  tests: 
      for:
      Node* my_list = NULL;

      then:
      remove_from_front(my_list) == 0
      get_size(my_list) == 0

      then:
      insert_at_front(my_list, 300);
      insert_at_front(my_list, 200);

      then:
      remove_from_front(my_list) == 200
      get_size(my_list) == 1

      print_list(my_list);
      ...should print to the screen:
List:
============
300
============

      then:
      remove_from_list(my_list) == 300
      get_size(my_list) == 0
      my_list == NULL

      print_list(my_list);
      ...should print to the screen:
List:
============
============

  by: Sharon Tuttle
----*/

NodeDataType remove_from_front(Node*& start_ptr)
{
    // handle the empty-list case

    if (start_ptr == NULL)
    {
        // LIKELY need to change if change NodeDataType!

        return 0;
    }

    // IF reach here, list is NOT empty
    //     SO: create curr_ptr and have it point to current first node

    Node* curr_node = start_ptr;

    // actually CHANGE argument start_ptr to point to whatever
    //     follows first node (whether next node, or NULL!)

    start_ptr = start_ptr->get_next();

    // grab value from node to be removed

    NodeDataType val_removed = curr_node->get_data();

    // free/deallocate former first node's memory

    delete curr_node;
    curr_node = NULL;

    return val_removed; 
}

/*----
  signature: remove_at: Node*& int -> NodeDataType
  purpose: expects a pass-by-reference pointer to a node, and a
            position of a node to be deleted, has the side-effect of removing and
            deleting the node at this position, and returns the node's value

  tests:
  for:
    Node* head = NULL;

    insert_at_front(head, 3);
    insert_at_front(head, 5);
    insert_at_front(head, 7);
    insert_at_front(head, 9);
    insert_at_front(head, 4);

    remove_at(head, 2) == 9
    remove_at(head, 5) == 0

  by: Joey Dugan
----*/

NodeDataType remove_at(Node*& start_ptr, int index)
{
    Node* curr = start_ptr;
    Node* next_ptr = NULL;
    NodeDataType removed_val;

    if(index == 1)
    {
        start_ptr = start_ptr->get_next();
        removed_val = curr->get_data();
        curr->set_next(NULL);
    }

    else if(index == (get_size(start_ptr)))
    {
        for(int i = 1; i < index-1; i++)
        {
            curr = curr->get_next();
        }
        
        next_ptr = curr->get_next();
        removed_val = next_ptr->get_data();
        next_ptr->set_next(NULL);
        curr->set_next(NULL);
        
    }
    
    else if(index > (get_size(start_ptr)))
    {
        return 0;
    }

    else
    {
        for(int i = 1; i < index-1; i++)
        {
            curr = curr->get_next();
        }

        next_ptr = curr->get_next()->get_next();
        removed_val = curr->get_next()->get_data();
        curr->get_next()->set_next(NULL);
        curr->set_next(next_ptr);
    }
    
    //  I have had some issues with both Visual Studio Code and the 
    //     CS50 IDE with double freeing issues unless I set the 
    //     pointer to NULL first to delete. This is why there is 
    //     a lack of class standards in the next two statements
    //     being reversed.
    curr = NULL;
    delete curr;
    

    return removed_val;
}

/*
signature: sum_list: Node* -> NodeDataType
purpose: adds up every single value in a linked list
         and then returns it.

tests: 
    for:
    Node* head = NULL;
    sum_list(head) == 0

    insert_at_front(head, 3);
    insert_at_front(head, 5);
    insert_at_front(head, 7);
    insert_at_front(head, 9);
    insert_at_front(head, 4);

    sum_list(head) == 28

by: Joey Dugan
*/

NodeDataType sum_list(Node* start_ptr)
{
    Node* curr = start_ptr;
    NodeDataType total = 0;

    while(curr != NULL)
    {
        total += curr->get_data();
        curr = curr->get_next();
    }

    return total;
}

/*
    signature: insert_at_end: Node*& NodeDataType -> void
    purpose: inserts a node at the end of a linked list and returns
            the new length of the linked list

    tests: 
    for:
        Node* head

        insert_at_end(head, 8);
        insert_at_end(head, 9);
        insert_at_end(head, 10);

        print_list(head);
        should print: 
        8
        9
        10

        insert_at_end(head, 11);
        insert_at_end(head, 12);

        print_list(head);
        should print:
        8
        9
        10
        11
        12

    by: Joey Dugan
*/
int insert_at_end(Node*& start_ptr, NodeDataType new_element)
{
    Node* curr = start_ptr;

    Node* new_node_ptr;
    new_node_ptr = new Node(new_element);

    if(start_ptr == NULL)
    {
        start_ptr = new_node_ptr;
    }

    else
    {
        while(curr->get_next() != NULL)
        {
            curr = curr->get_next();
        }

        curr->set_next(new_node_ptr);
    }

    return get_size(start_ptr);
}