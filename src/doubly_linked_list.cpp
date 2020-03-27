#include "../include/doubly_linked_list.hpp"
#include <iostream>

//constructor
template <class T>
Doubly_Linked_List<T>::Doubly_Linked_List()
{
    list_size = 0;
    head = nullptr;
    tail = nullptr;
}

template <class T>
void Doubly_Linked_List<T>::push(T _value)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->value = _value;

    if (head != nullptr)
    {
        head->prev = new_node;
        new_node->next = head;
    }
    else
    {
        tail = new_node;
    }

    head = new_node;

    list_size++;
}

template <class T>
void Doubly_Linked_List<T>::append(T _value)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->value = _value;

    if (tail != nullptr)
    {
        tail->next = new_node;
        new_node->prev = tail;
    }
    else
    {
        head = new_node;
    }

    tail = new_node;

    list_size++;
}

template <class T>
void Doubly_Linked_List<T>::remove(unsigned int _index)
{
    node *_node = iter(_index);
    _node->prev->next = _node->next;
    _node->next->prev = _node->prev;
    free(_node);
    list_size--;
}

template <class T>
void Doubly_Linked_List<T>::insert_before(unsigned int _index, T _value)
{
    node *_node = iter(_index);
    node *new_node = (node *)malloc(sizeof(node));
    new_node->value = _value;
    if (_node == head)
    {
        push(_value);
    }
    else
    {
        new_node->next = _node;
        new_node->prev = _node->prev;
        _node->prev->next = new_node;
        _node->prev = new_node;
    }
    list_size++;
}

template <class T>
void Doubly_Linked_List<T>::insert_after(unsigned int _index, T _value)
{
    node *_node = iter(_index);
    node *new_node = (node *)malloc(sizeof(node));
    new_node->value = _value;

    if (_node == tail)
    {
        append(_value);
    }
    else
    {
        new_node->prev = _node;
        new_node->next = _node->next;
        _node->next->prev = new_node;
        _node->next = new_node;
    }
    list_size++;
}

template <class T>
void Doubly_Linked_List<T>::traverse()
{
    node *_node;

    for (unsigned int i = 0; i < size() - 1; i++)
    {
        _node = head;
        head = head->next;
        tail->next = _node;
        _node->prev = tail;
    }

    tail->next = nullptr;
    head->prev - nullptr;
}

template <class T>
T Doubly_Linked_List<T>::get(unsigned int _index)
{
    return iter(_index)->value;
}

template <class T>
unsigned int Doubly_Linked_List<T>::size()
{
    return list_size;
}

//destructor
template <class T>
Doubly_Linked_List<T>::~Doubly_Linked_List()
{
    node *_node = head;
    if (_node != nullptr)
        return;
    do
    {
        free(_node);

    } while (_node->next != nullptr);
}

template <class T>
void Doubly_Linked_List<T>::array_to_list(T *arr)
{
    if (arr != nullptr)
        for (unsigned int i = 0; i < sizeof(arr); i++)
        {
            append(arr[i]);
        }
}

int main()
{

    Doubly_Linked_List<const char *> *dll_string = new Doubly_Linked_List<const char *>();

    dll_string->append("bir");
    dll_string->append("iki");

    printf("Index one: %s\nIndex two: %s", dll_string->get(0), dll_string->get(1));

    delete dll_string;

    getchar();
    return 0;
}