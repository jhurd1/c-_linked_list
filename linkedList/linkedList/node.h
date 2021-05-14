/***********************************************************************
* Header:
*    NODE_H
* Summary:
*    Contains all the functions for Node to work.
* Authors:
*    Jamie Hurd, Tyler Williams, and David Aruldass
************************************************************************/
#ifndef NODE_H
#define NODE_H
namespace custom
{
template <class T>
class Node
{
    /************************************
     * PRIVATE
     ************************************/
private:
    
    /************************************
    * PUBLIC
    ************************************/
public:
    //variables
    T *data;
    Node *pNext; //can use arrow operators to chain values between node objects
    //note: it's okay to chain these
    Node *pPrev;
    Node *pHead;
    T *value;
    
    //functions
    Node();
    Node(T value);
    
}; //END CLASS
}
//BEGIN IMPLEMENTATION
/************************************
* CONSTRUCTORS
************************************/
/************************************
* default
************************************/
template<class T>
custom :: Node<T> :: Node ()
{
    data = NULL;
    pNext = NULL;
    pPrev = NULL;
    pHead = NULL;
}
/************************************
* non-default
************************************/
template <class T>
custom :: Node<T> :: Node (T value)
{
    this->data = data;
    this->pNext = pNext;
    this->pPrev = pPrev;
    this->pHead = pHead;
    this->value = &value;
}
/************************************
* NON_MEMBERS
************************************/
/************************************
* insert
*************************************/
template <class T>
custom :: Node <T> * insert (custom :: Node <T> *previousNode, T value, bool after = true)
{
    //custom :: Node <T> *pNext;
    custom :: Node <T> *newNode = new custom :: Node <T>(value); //instance a new node
    if (previousNode == NULL)
    {
        throw ("Previous node can't be NULL");
    }
    if (after) //defaults to the after node
    {
        newNode->pNext = previousNode->pNext; // make new node's pNext the pNext of object pPrev
        previousNode->pNext = newNode; //make previousNode's pNext value point to the new node
        newNode->pNext->pPrev = newNode; //make the latter node's pPrev pointer reference the new node
        newNode->pPrev = previousNode; //does not need to correlate with pPrev because what you named the
    } else
    {
        previousNode->pNext = newNode;
        newNode->pPrev = previousNode;
    }
    return newNode; //returns as a pointer because of its instantiation on 67 as a pointer
}
/************************************
* remove
************************************/
template <class T>
custom :: Node <T> * remove (custom :: Node <T> *pPrev)
{
    if (pPrev == NULL)
    {
        throw ("Node already gone");
    }
    if (pPrev->pPrev) //presumably a bool testing the presence of a pPrev ref for node pPrev
    {
        pPrev->pNext = pPrev->pPrev->pNext; //assign to pPrev's pNext ref pNext's pPrev's pPrev ref.
    }
    if (pPrev->pNext) //presumably a bool testing the presence of a pPrev ref for node pNext
    {
        pPrev->pPrev = pPrev->pNext->pPrev; //assign to pPrev's pPrev ref the pPrev's Pnext ref to pPrev node.
    }
    pPrev->pNext = pPrev->pNext->pNext; //Generally, remove the node
    remove(pPrev); //free the memory
    return pPrev;
}
/************************************
* freeData
* adapted from geeksforgeeks.org
* equivalent to the "clear" described
************************************/
template <class T>
custom :: Node <T> * freeData (custom :: Node <T> *pHead)
{
    custom :: Node <T> *pPrev;
    while (pHead != NULL) //iterator for a linked list
    {
        if (pPrev->pNext == NULL)
        {
            throw ("No such pNext reference.");
        }
        pPrev->pNext = pPrev->pNext->pNext; //remove nodes
    }
    remove(pHead);
    return pPrev;
}
/************************************
* copy
************************************/
 template <class T>
custom::Node <T> * copy (custom::Node <T> *pSource)
{
    custom :: Node<T> node;
    T value;
    custom :: Node <T> *n1 = NULL;
    for (int i = 0; i < sizeof(node); i++)
    {
        n1 = insert (n1, value);
        custom :: Node <T> *n2 = NULL;
        n2 = copy (n1);
        freeData (n1);
    }
    return pSource;
}
/**************************************
* find
* forced to do a linear search
* as binary search not possible
* with linkedList
**************************************/
template <class T>
custom :: Node <T> * find (custom :: Node <T> *pHead, T value)
{
    while (pHead != NULL)
    {
        if (*pHead->data == value)
        {
            return pHead;
        } else if (*pHead->data != value)
        {
             pHead = pHead->pNext;
        } else
        {
            throw ("Node not here.");
        }
    }
    return pHead;
}
/************************************
* operator <<
* Display the contents of a given linked-list.
* adapted from geeksforgeeks.org/
* operator-overloading
************************************/
template <class T>
std::ostream &operator << (std::ostream &whatevz, custom :: Node<T> *pHead)
{
    if (pHead != NULL)
    {
        std::cout << pHead->data;
        pHead = pHead->pNext;
    }
    while (pHead != NULL)
    {
        std::cout << "->" << pHead->data;
        pHead = pHead->pNext;
    }
    return whatevz;
}
#endif
