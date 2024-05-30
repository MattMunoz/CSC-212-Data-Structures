// Name: Matthew Munoz
// Email: mmunoz005@citymail.cuny.edu

/*
INVARIANT for the sequence class:
	1. The amount of items in the sequence is stored in the variable count
	2. The variable that is currently being looked at is stored in the variable curr,
	   which is the index of the current variable
	3. Count is never greater than the CAPACITY
	4. The items are input in an array called data. The items are stored starting at data[0] 
	   until data[CAPACITY]
*/

#include <assert.h>
#include "sequence1.h"

namespace main_savitch_3
{
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
		assert(size() < CAPACITY);

		if (is_item())
		{
			for (int i = count; curr < i; i--)
			{
				data[i] = data[i-1];
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
		assert(size() < CAPACITY);

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
		assert(is_item());

		if (is_item())
		{
			for (int i = curr; i < count; i++)
			{
				data[i] = data[i + 1];
			}

			count--;

			if (size() == 0)
			{
				curr = CAPACITY + 1;
			}
		}
	}
}