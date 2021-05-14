/***********************************************************************
 * Header:
 *    INSERTION SORT
 * Summary:
 *    This will contain just the prototype for insertionSortTest(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Jamie Hurd, Tyler Williams, and David Aruldass
 ************************************************************************/

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "node.h"
/***********************************************
 * INSERTION SORT
 * Sort the items in the array
 **********************************************/
template <class T>
void insertionSort (T array[], int num)
{
    T value;
    custom :: Node <T> *pHead = nullptr;
    T *newArray = new T[num]; //num equates with the size of the new array; parallels index number
    for (int i = 0; i < num; i++) //begin array traversal
    {
        // call insert here to insert values into the linked list
        if (pHead == NULL) // this is going to evaluate true every time
        {
            if (pHead->data < &value)
            {
                pHead->data = &value;
            }
            pHead = pHead->pNext; //array traversal will get us out of this list traversal
        }
        // push the value into each iterated array[num] index
        pHead->data = &array[i];
        array[i] = newArray[num]; 
        //create a destructor to manually delete newArray when the heap dies? If so, where?
    }
    delete [] array; //delete first array after the for loop, not in it
}
#endif // INSERTION_SORT_H
