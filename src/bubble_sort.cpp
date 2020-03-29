#include "../include/bubble_sort.hpp"

// Not String or char
template <typename T,
          std::enable_if<!std::is_same<T, std::string>::type && !std::is_same<T, char>::type>>
Doubly_Linked_List<T> *bubble_sort(Doubly_Linked_List<T> *dll)
{
    bool swapped{false}; // Using to avoid unnecessary iterations

    // Pros: When invoke "get()" function, list iteration starts.
    // It is good for bad situations(O). List operation is harder work than
    // primal type sorting so it is good in average situations(Θ).
    // Look bubble sort algorithm for further info.
    // Cons: In every step making an assignment. In every outer loop
    // checking for expected condition to break loop

    for (unsigned int i = 0; i < dll->size() - 1; i++)
    {
        for (unsigned int j = 0; j < dll->size() - 1 - i; j++)
        {
            if (dll->get(j) > dll->get(j + 1))
            {
                dll->swap(j, j + 1);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    return dll;
}

// String or char
template <typename T,
          std::enable_if<std::is_same<T, std::string>::type && std::is_same<T, char>::type>>
Doubly_Linked_List<T> *bubble_sort(Doubly_Linked_List<T> *dll)
{
    bool swapped{false}; // Using to avoid unnecessary iterations

    // Pros: When invoke "get()" function, list iteration starts.
    // It is good for bad situations(O). List operation is harder work than
    // primal type sorting so it is good in average situations(Θ).
    // Look bubble sort algorithm for further info.
    // Cons: In every step making an assignment. In every outer loop
    // checking for expected condition to break loop

    // Alphabetical order
    std::string a, b;
    unsigned int lenght;
    char a_char, b_char;

    for (unsigned int i = 0; i < dll->size() - 1; i++)
    {
        for (unsigned int j = 0; j < dll->size() - 1 - i; j++)
        {
            a = dll->get(j);
            b = dll->get(j + 1);

            if (b.length() >= a.length())
                lenght = a.length();
            else
                lenght = b.length();

            for (unsigned int k = 0; k < lenght; k++)
            {
                a_char = a.at(k);
                b_char = b.at(k);

                // Upper to lower
                if (a_char > 96 && < 123)
                    a_char -= 32;
                if (b_char > 96 && < 123)
                    b_char -= 32;

                if (a_char > b_char)
                {
                    dll->swap(j, j + 1);
                    swapped = true;
                    break;
                }
            }
        }
        if (swapped == false)
            break;
    }
    return dll;
}