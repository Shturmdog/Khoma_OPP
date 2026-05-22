#pragma once
#include <iostream>

class LineListException {};

template <class T> class LineListElem;
template <class T>
class LineListElem
{
    T data;
    LineListElem* next;

public:
    LineListElem(const T& adata, LineListElem* anext);
    const T& getData() const;
    LineListElem* getNext();
    template <class U> friend class LineList;
};

template <class T>
class LineList
{
    LineListElem<T>* start;
    LineListElem<T>* last;

    LineList(const LineList& list);
    LineList& operator = (const LineList& list);

public:
    LineList();
    ~LineList();

    LineListElem<T>* getStart();
    LineListElem<T>* getLast();

    void deleteFirst();
    void deleteAfter(LineListElem<T>* ptr);
    void insertFirst(const T& data);
    void insertAfter(LineListElem<T>* ptr, const T& data);

    friend std::ostream& operator << (std::ostream& out, LineList<T>& list)
    {
        LineListElem<T>* ptr = list.start;
        if (!ptr)
            out << "EMPTY ";
        else do
        {
            out << ptr->getData() << ' ';
            ptr = ptr->getNext();
        } while (ptr != list.start);
        return out;
    }
};

#include "LineList.cpp"