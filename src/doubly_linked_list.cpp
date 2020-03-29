#include "../include/doubly_linked_list.hpp"

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
    node *_node = find(_index);
    if (_node == head)
    {
        head = head->next;
    }
    else if (_node == tail)
    {
        tail = tail->next;
    }
    _node->prev->next = _node->next;
    _node->next->prev = _node->prev;
    free(_node);
    list_size--;
}

template <class T>
void Doubly_Linked_List<T>::insert_before(unsigned int _index, T _value)
{
    node *_node = find(_index);
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
    node *_node = find(_index);
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
void Doubly_Linked_List<T>::invert()
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
    head->prev = nullptr;
}

template <class T>
T Doubly_Linked_List<T>::get(unsigned int _index)
{
    return find(_index)->value;
}

template <class T>
unsigned int Doubly_Linked_List<T>::size()
{
    return list_size;
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

template <class T>
void Doubly_Linked_List<T>::swap(unsigned int a_index, unsigned int b_index)
{
    if (a_index == b_index)
        return;

    node *a_node = find(a_index);
    node *b_node = find(b_index);
    node *b_node_tmp = b_node;

    b_node->next = a_node->next;
    b_node->prev = a_node->prev;
    a_node->next = b_node_tmp->next;
    a_node->prev = b_node_tmp->prev;

    // Endnode solutions
    if (a_node != tail)
        a_node->next->prev = b_node_tmp;
    else
        tail = b_node;

    if (a_node != head)
        a_node->prev->next = b_node_tmp;
    else
        head = b_node;

    if (b_node != tail)
        b_node->next->prev = a_node;
    else
        tail = a_node;

    if (b_node != head)
        b_node->prev->next = a_node;
    else
        head = a_node;

    b_node = a_node;
    a_node = b_node_tmp;
}

//destructor
template <class T>
Doubly_Linked_List<T>::~Doubly_Linked_List()
{
    node *_node = head;
    if (_node == nullptr)
        return;
    do
    {
        free(_node);

    } while (_node->next != nullptr);
}
