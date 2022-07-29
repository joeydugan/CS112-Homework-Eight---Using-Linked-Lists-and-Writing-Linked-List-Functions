/*----
  signature: main: void -> int
  purpose: testing program for our collection of linked
      list functions

  (Tests assume NodeDataType is int.)

  compile using: (but all on one line!)
      g++ linked_list_functs_test.cpp linked_list_functs.cpp Node.cpp -o linked_list_functs_test
  run using:
      ./linked_list_functs_test

  by: Sharon Tuttle
  modified by: Casey Cooper and Joey Dugan
  last modified: 2022-03-31 - adding sum_list, insert_at_end, remove_from_front - Joey Dugan, Sharon Tuttle
                 2022-03-25 - adding get_size, remove_at - Casey Cooper, Joey Dugan
                 2022-03-24 - adding print_list, delete_list, search_for - Sharon Tuttle
                 2022-03-23 - starting with insert_at_front - Sharon Tuttle
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "Node.h"
#include "linked_list_functs.h"
using namespace std;

int main()
{
    cout << boolalpha;

    //---
    // testing insert_at_front

    cout << "\n*** Testing function insert_at_front ***\n";

    // starting with an empty list

    Node* head = NULL;

    insert_at_front(head, 47);  // change for new NodeDataType

    cout << (head->get_data() == 47) << endl;
    cout << (head->get_next() == NULL) << endl;

    insert_at_front(head, 36);

    cout << (head->get_data() == 36) << endl;
    cout << (head->get_next()->get_data() == 47) << endl;

    // need to deallocate dynamic memory used for these two nodes!

    cout << "hope to see 2 nodes deleted: ";
    cout << delete_list(head) << endl;

    //---
    // testing print_list

    cout << "\n*** Testing function print_list ***\n";

    Node *my_first = NULL;

    cout << "should see just List header, and no contents:"
         << endl;

    print_list(my_first);

    cout << "\nshould see list header, then contents\n"
         << "   24, 5, 13:\n";

    insert_at_front(my_first, 13);
    insert_at_front(my_first, 5);
    insert_at_front(my_first, 24);
    print_list(my_first);

    cout << "hope to see 3 nodes deleted: ";
    cout << delete_list(my_first) << endl;

    //---
    // testing delete_list

    cout << "\n*** Testing function delete_list ***\n";

    Node* begin = NULL;

    cout << (delete_list(begin) == 0) << endl;


    //cout << "hope to delete nodes with 9, then 1, then 80, then 25"
    //     << endl;

    insert_at_front(begin, 25);
    insert_at_front(begin, 80);
    insert_at_front(begin, 1);
    insert_at_front(begin, 9);

    cout << (delete_list(begin) == 4) << endl;

    //---
    // testing search_for

    cout << "\n*** Testing function search_for ***\n";

    Node* stuff = NULL;

    insert_at_front(stuff, 300);
    insert_at_front(stuff, 400);
    insert_at_front(stuff, 250);
    insert_at_front(stuff, 400);
    insert_at_front(stuff, 25);

    cout << (search_for(stuff, 12) == false) << endl;
    cout << (search_for(stuff, 25) == true) << endl;
    cout << (search_for(stuff, 400) == true) << endl;

    cout << "hope to see 5 nodes deleted: ";
    cout << delete_list(stuff) << endl << endl;

    cout << "\n*** Testing function get_size ***\n";

    cout << (get_size(head) == 0) << endl;

    insert_at_front(head, 3);
    insert_at_front(head, 5);
    insert_at_front(head, 7);
    insert_at_front(head, 9);
    insert_at_front(head, 4);

    cout << (get_size(head) == 5) << endl;

    delete_list(head);

    cout << "\n*** Testing function remove_at ***\n";

    Node* remove_test = NULL;
    insert_at_front(remove_test, 3);
    insert_at_front(remove_test, 5);
    insert_at_front(remove_test, 7);
    insert_at_front(remove_test, 9);
    insert_at_front(remove_test, 4);

    cout << (remove_at(remove_test, 1) == 4) << endl;
    cout << (remove_at(remove_test, 3) == 5) << endl;
    cout << (remove_at(remove_test, 5) == 0) << endl;
    delete_list(remove_test);

    cout << "\n*** Testing function sum_list ***\n";

    cout << (sum_list(head) == 0) << endl;

    insert_at_front(head, 3);
    insert_at_front(head, 5);
    insert_at_front(head, 7);
    insert_at_front(head, 9);
    insert_at_front(head, 4);

    cout << (sum_list(head) == 28) << endl;

    delete_list(head);

    cout << "\n*** Testing function insert_at_end ***\n";

    insert_at_end(head, 8);
    insert_at_end(head, 9);
    insert_at_end(head, 10);

    cout << "\nShould print 8, 9, 10 all on their own lines" << endl;
    print_list(head);

    insert_at_end(head, 11);
    insert_at_end(head, 12);

    cout << "\nShould print 8, 9, 10, 11, 12 all on their own lines" << endl;
    print_list(head);

    return EXIT_SUCCESS;
}