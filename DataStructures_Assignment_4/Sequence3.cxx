#include <cassert>
#include <iostream>
#include "sequence3.h"
using namespace std;

/*
----------------------------------------------------------------------------
Invariants of the sequence calss with linked list:
     1. head_ptr is a pointer to a node that points to the head, first item, 
        of the list if exists, otherwise its a NULL ptr
     2. tail_ptr  is a pointer to a node that points to the tail, last item, 
        of the list if it exists, otherwise its a NULL ptr
     3. curr is a pointer to a node that points to the node that is currently
        being looked at, otherwise its a NULL pointer
     4. previous is a pointer to a node that points to the node before the 
        one currently being looked at. If no such node exists previous is a 
        NULL pointer
     5. count is the number of nodes in the list
----------------------------------------------------------------------------

----------------------------------------------------------------------------
Big-O 
     - Due to the use of the tail_ptr, curr, and previous all operations
       are done in constatn time. Without these three pointers the 
       insertion, attachment, removal at any point other than the front 
       would be linear

                      Linked List                   Dynamic Array
copy constructor         O(n)                           O(n)
start                    O(1)                           O(1)
advance                  O(1)                           O(1)
insert                   O(1)                           O(n)
attach                   O(1)                           O(n)
remove current           O(1)                           O(n)
=                        O(n)                           O(n)
start                    O(1)                           O(1)
is_iten                  O(1)                           O(1)
current                  O(1)                           O(1)
----------------------------------------------------------------------------
*/

namespace main_savitch_5
{
    sequence::sequence()
    {
        count = 0;
        head_ptr = NULL;
        tail_ptr = NULL;
        curr = NULL;
        previous = NULL;
    }

    sequence::sequence(const sequence& source)
    {
        if (source.curr == NULL)
        {
            list_copy(source.head_ptr, head_ptr, tail_ptr);
            count = source.count;
        }
        else
        {
            list_piece(source.head_ptr, source.curr, head_ptr, previous);
            list_piece(source.curr, NULL, curr, tail_ptr);
            if (previous != NULL)
                previous->set_link(curr);
            else
                head_ptr = curr;
            count = source.count;
        }

    }

    void sequence:: displayer() const
    {
        node* displayer;
        for (displayer = head_ptr; displayer != NULL; displayer = displayer->link())
        {
            cout << displayer->data() << endl;
        }
    }

    sequence::~sequence()
    {
        list_clear(head_ptr);
        count = 0;
    }

    void sequence::start()
    {
        curr = head_ptr;
        previous = NULL;
    }

    void sequence::advance()
    {
        if (previous != NULL)
        {
            previous = curr;
            curr = curr->link();
        }
        else
        {
            curr = curr->link();
            previous = head_ptr;
        }
    }

    void sequence::insert(const value_type& entry)
    {

        if (head_ptr == NULL)
        {
            list_head_insert(head_ptr, entry);
            tail_ptr = head_ptr;
            curr = head_ptr;
        }
        else if (!(is_item()) || count == 1 || curr == head_ptr)
        {
            node* temp = head_ptr;
            list_head_insert(head_ptr, entry);
            head_ptr->set_link(temp);
            curr = head_ptr;
        }
        else
        {
            node* temp = previous;
            list_insert(previous, entry);
            temp = previous->link();
            temp->set_link(curr);
            curr = temp;
        }

        count++;
    }

    void sequence::attach(const value_type& entry)
    {

        if (head_ptr == NULL)
        {
            list_head_insert(head_ptr, entry);
            tail_ptr = head_ptr;
            curr = head_ptr;
        }
        else if (!(is_item()) || curr == tail_ptr)
        {
            previous = tail_ptr;
            list_insert(tail_ptr, entry);
            tail_ptr = tail_ptr->link();
            curr = tail_ptr;
        }
        else if (curr == head_ptr)
        {
            node* temp = curr->link();
            list_insert(curr, entry);
            curr = curr->link();
            curr->set_link(temp);
        }
        else
        {
            node* temp = previous;
            list_insert(previous, entry);
            temp = previous->link();
            temp->set_link(curr);
            curr = temp;
        }

        count++;
    }

    void sequence::remove_current()
    {
        if (count == 1 )
        {
            curr = NULL;
            list_head_remove(head_ptr);
        }
        else if(is_item() && curr == head_ptr)
        {
            curr = head_ptr->link();
            list_head_remove(head_ptr);
            head_ptr = curr;
        }
        else
        {
            curr = curr->link();
            list_remove(previous);
            previous->set_link(curr);
        }

        count--;
    }

    void sequence::operator =(const sequence& source)
    {
        if (this == &source)
            return;

        list_clear(head_ptr);
        count = 0;

        list_piece(source.head_ptr, source.curr, head_ptr, previous);
        list_piece(source.curr, NULL, curr, tail_ptr);
        if (previous != NULL)
            previous->set_link(curr);
        else
            head_ptr = curr;

        count = source.count;
    }
}