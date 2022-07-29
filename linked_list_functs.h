/*====
  header file for a collection of functions I hope will be useful
      for linked lists created using the Node class

  by: Sharon Tuttle
  and: Casey Cooper and Joey Dugan
  last modified: 2022-03-25 - adding get_size, <other function you chose>
                 2022-03-24 - adding print_list, delete_list, search_for
                 2022-03-23 - starting with insert_at_front
====*/

#ifndef LINKED_LIST_FUNCTS_H
#define LINKED_LIST_FUNCTS_H

#include <string>
#include "Node.h"
using namespace std;

void insert_at_front(Node*& start_ptr, NodeDataType new_element);

void print_list(Node *start_ptr);

int delete_list(Node*& start_ptr);

bool search_for(Node* start_ptr, NodeDataType desired_val);

int get_size(Node* start_ptr);

NodeDataType remove_at(Node*& start_ptr, int index);

NodeDataType sum_list(Node* start_ptr);

int insert_at_end(Node*& start_ptr, NodeDataType new_element);

// put headers for your Week 9 Lab Exercise functions here

#endif