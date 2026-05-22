#include "LineList.h"

template <class T>
LineListElem<T>::LineListElem(const T& adata, LineListElem<T>* anext)
    : data(adata), next(anext) {
}

template <class T>
const T& LineListElem<T>::getData() const
{
    return data;
}

template <class T>
LineListElem<T>* LineListElem<T>::getNext()
{
    return next;
}

template <class T>
LineList<T>::LineList() : start(nullptr), last(nullptr) {}

template <class T>
LineList<T>::~LineList()
{
    while (start)
        deleteFirst();
}

template <class T>
LineListElem<T>* LineList<T>::getStart()
{
    return start;
}

template <class T>
LineListElem<T>* LineList<T>::getLast()
{
    return last;
}

template <class T>
void LineList<T>::insertFirst(const T& data)
{
    if (!start)
    {
        start = new LineListElem<T>(data, nullptr);
        start->next = start;
        last = start;
    }
    else
    {
        LineListElem<T>* newFirst = new LineListElem<T>(data, start);
        last->next = newFirst;
        start = newFirst;
    }
}

template <class T>
void LineList<T>::insertAfter(LineListElem<T>* ptr, const T& data)
{
    if (!ptr) return;
    LineListElem<T>* newNode = new LineListElem<T>(data, ptr->next);
    ptr->next = newNode;
    if (ptr == last)
        last = newNode;
}

template <class T>
void LineList<T>::deleteFirst()
{
    if (!start)
        throw LineListException();

    if (start == last)
    {
        delete start;
        start = last = nullptr;
    }
    else
    {
        LineListElem<T>* newStart = start->next;
        last->next = newStart;
        delete start;
        start = newStart;
    }
}

template <class T>
void LineList<T>::deleteAfter(LineListElem<T>* ptr)
{
    if (!ptr || ptr->next == ptr)
        throw LineListException();

    LineListElem<T>* toDelete = ptr->next;
    if (toDelete == start)
    {
        start = start->next;
        last->next = start;
        ptr->next = start;
    }
    else
    {
        ptr->next = toDelete->next;
        if (toDelete == last)
            last = ptr;
    }
    delete toDelete;
}
