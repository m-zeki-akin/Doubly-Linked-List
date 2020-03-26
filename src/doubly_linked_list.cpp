#include "../include/doubly_linked_list.hpp"

//constructors
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
    size--;
}

template <class T>
void Doubly_Linked_List<T>::insert_before(unsigned int _index, T _value)
{
    node *_node = iter(_index);
    node *new_node = (node *)malloc(sizeof(node));
    if (_node == head)
    {
        push(_value);
    }
    else
    {
        new_node->next = _node;
        new_node->prev = _node->prev;
        _node->prev->next = new_node;
        _node->prev = new_node
    }
}

//destructor
template <class T>
Doubly_Linked_List<T>::~Doubly_Linked_List()
{
    node *_node = head;
    if (_node != nullptr)
    {
        do
        {
            free(_node);
        } while (_node->next != nullptr);
    }
    else
        return;
}