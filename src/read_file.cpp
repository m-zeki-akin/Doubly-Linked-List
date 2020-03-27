#include "../include/read_file.hpp"

int *read_file()
{
    std::ifstream infile("../input.txt");

    if (!infile.is_open())
    { // if no file create it.
        std::ofstream outfile("../input.txt");

        srand(time(NULL));
        for (int i = 0; i < rand() % 12 + 8; i++)
        {
            srand(time(NULL));
            outfile << rand() % 1024;
        }

        outfile.close();
        infile.open("../input.txt");
    }

    int *arr;
    int input;

    int i = 0;
    while (infile >> input)
    {

        arr[i] = input;
        i++;
    }

    infile.close();

    return arr;
}