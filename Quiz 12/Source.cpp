#include <iostream>
using namespace std;

void search(int [], size_t, size_t, int, bool&, size_t&);

int main()
{
    const size_t cap = 100;
    int arr[cap];
    bool found;
    size_t location;
    int target = 52;

    for (size_t i = 0; i < cap; i++)
    {
       arr[i] = 2*i;
    }

    search(arr, 0, cap, target, found, location);

    if (found)
        cout << target << " is at location " << location;
    else
        cout << target << " is not in the list";

    return 0;
}


void search(int a[], size_t first, size_t last, int target,
    bool& found, size_t& location)
{
    size_t middle;

    if (first > last)
        found = false;
    else
    {
        middle = (first + last) / 2;
        if (target == a[middle])
        {
            location = middle;
            found = true;
        }
        else if (target < a[middle])
            search(a, first, middle - 1, target, found, location);
        else
            search(a, middle + 1, last, target, found, location);
    }
}