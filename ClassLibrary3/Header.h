#pragma once
#include <iostream>
#include"MyForm.h"
class vectorClass
{
    char* arr;
    int capacity;
    int current;

public:
    vectorClass()
    {

        arr = new char[10];

        capacity = 10;

        current = 0;

    }
    ~vectorClass()
    {
        delete[] arr;
    }

    void push(char data)
    {

        arr[current] = data;

        current++;

    }
    

    char ellment(int index)
    {
        return arr[index];
    }

  

    void sort()
    {
        for (int i = 1; i < 10; ++i)
        {
            for (int r = 0; r < 10 - i; r++)
            {
                if (arr[r] < arr[r + 1])
                {
                    // Обмен местами
                    char temp = arr[r];
                    arr[r] = arr[r + 1];
                    arr[r + 1] = temp;
                }
            }
        }
    }

    void print()


    {
        for (int i = 0; i < current; i++) {

            std::cout << arr[i];

        }
        std::cout << std::endl;
    }


};