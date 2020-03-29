#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

template <typename T>
struct doubly_linked_node
{
    doubly_linked_node *next;
    doubly_linked_node *prev;
    T value;
};

template <class T>
class Doubly_Linked_List
{
private:
    typedef doubly_linked_node<T> node;
    // Props
    node *head;
    node *tail;
    unsigned int list_size;

    //Methods
    node *find(unsigned int _index)
    {
        unsigned int _size = size();
        node *_node;

        if (_size == 0)
        {
            throw "Empty List.";
        }
        else if (_index > _size - 1)
        {
            throw "Out of range.";
        }

        if (_size / 2 > _index)
        {
            _node = head;
            for (unsigned int i = 0; i < _index; i++)
            {
                _node = _node->next;
            }
        }
        else
        {
            _index -= (_size - 1);
            _node = tail;
            for (unsigned int i = 0; i < _index; i++)
            {
                _node = _node->prev;
            }
        }

        return _node;
    }

public:
    Doubly_Linked_List();
    ~Doubly_Linked_List();

    void push(T);
    void append(T);
    void remove(unsigned int _index);
    void insert_before(unsigned int _index, T _value);
    void insert_after(unsigned int _index, T _value);
    void invert();
    void swap(unsigned int a_index, unsigned int b_index);
    T get(unsigned int _index);
    unsigned int size();
    void array_to_list(T *arr);
};

#endif