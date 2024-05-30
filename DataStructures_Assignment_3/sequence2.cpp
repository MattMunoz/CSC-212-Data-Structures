#include "sequence2.h"
#include <algorithm>
using namespace std;

/*
INVARIANT for the dynamic sequence class:
    1. The amount of items in the sequence is stored in the variable count
    2. The variable that is currently being looked at is stored in the variable curr,
       which is the index of the current variable
    3. If count is greater than the capcaity, new memory will be allocated to the dynaoc array to 
       with enough capacity to allow insertion
    4. The items are input into an dynamic array called data. The items are stored starting at data[0]
       until data[cap], but if more room is needed for a larger sequence the array may be expanded to 
       allow for more numbers
    5. To prevent running out of memory, memory will be releases as soon as the array is no longer needed
*/

namespace main_savitch_4
{
    sequence::sequence(size_type initial_capacity)
    {
        data = new value_type[initial_capacity];
        cap = initial_capacity;
        count = 0;
    }

    sequence::sequence(const sequence& source)
    {
        data = new value_type[source.cap];
        curr = source.curr;
        cap = source.cap;
        count = source.count;
        for (int i = 0; i < count; i++)
        {
            data[i] = source.data[i];
        }
    }

    sequence::~sequence()
    {
        delete [] data;
    }

    void sequence::start()
    {
        if (count != 0)
        {
            curr = 0;
        }
    }

    void sequence::advance()
    {
        if (is_item())
        {
            curr++;
        }
    }

    void sequence::insert(const value_type& entry)
    {
        if (count == cap)
        {
            resize(cap * 1.1);
        }

        if (is_item())
        {
            for (int i = count; curr < i; i--)
            {
                data[i] = data[i - 1];
            }

            data[curr] = entry;

            count++;
        }
        else
        {
            curr = 0;
            for (int i = count; curr < i; i--)
            {
                data[i] = data[i - 1];
            }

            data[curr] = entry;

            count++;
        }
    }

    void sequence::attach(const value_type& entry)
    {
        if (count == cap)
        {
            resize(cap * 1.1);
        }

        if (is_item())
        {
            if ((curr + 1) != count)
            {
                for (int i = count; curr < i; i--)
                {
                    data[i + 1] = data[i];
                }
            }

            curr += 1;

            data[curr] = entry;

            count++;
        }
        else
        {
            curr = count;
            data[curr] = entry;
            count++;
        }
    }

    void sequence::remove_current()
    {

        if (is_item())
        {
            for (size_type i = curr; i < count; i++)
            {
                data[i] = data[i + 1];
            }

            count--;

        }
    }

    void sequence::resize(size_type new_capacity)
    {
        value_type* larger;

        if (new_capacity == cap)
            return;

        if (new_capacity < count)
            new_capacity = count * 1.1;

        larger = new value_type[new_capacity];
        copy(data, data + count, larger);
        delete[] data;
        data = larger;
        cap = new_capacity;
    }

    void sequence::operator=(const sequence& source)
    {

        if (this == &source)
        {
            return;
        }

        if (cap != source.cap)
        {
            delete[] data;
            data = new value_type[source.cap];
            cap = source.cap;
        }

        curr = source.curr;
        count = source.count;

        for (int i = 0; i < count; i++)
        {
            data[i] = source.data[i];
        }
    }

    sequence operator+(const sequence& s1, const sequence& s2)
    {
        int first_size = s1.size(), second_size = s2.size();
        sequence temp(first_size + second_size);

        for (int j = 0; j < first_size; j++)
        {
            temp.attach(s1[j]);
        }

        for (int k = 0; k < second_size; k++)
        {
            temp.attach(s2[k]);
        }

        return temp;
    }

    sequence operator+=(sequence& s1, const sequence& s2)
    {
        int second_size = s2.size();
        s1.resize(s1.size() + s2.size());

        for (int k = 0; k < second_size; k++)
        {
            s1.attach(s2[k]);
        }

        return s1;

    }
}