#pragma once
#include <iostream>
#include <fstream>
#include <windows.h>

class StlReplace
{
    char* arr;
    int power, actual;

public:
    StlReplace()
    {
        arr = new char[10];
        power = 10;
        actual = 0;
    }

    ~StlReplace()
    {
        delete[] arr;
    }

    void push(char data)
    {
        arr[actual] = data;
        actual++;
    }

    int accumulate()
    {
        int sum = 0;
        for (int i = 0; i < power; i++)
        {
            sum += arr[i];
        }
        return sum;
    }

    int count()
    {
        return actual;
    }

    void replace(char zamena)
    {
        for (int i = 0; i < power; i++)
        {
            if (arr[i] == zamena)
                arr[i] = zamena;
        }
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
                    // сортировка по убыванию
                    int temp = arr[r];
                    arr[r] = arr[r + 1];
                    arr[r + 1] = temp;
                }
            }
        }
    }

    void print()
    {
        for (int i = 0; i < actual; i++)
        {
            std::cout << arr[i];
        }
        std::cout << std::endl;
    }
};



