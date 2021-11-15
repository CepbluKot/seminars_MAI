#include <iostream>
#include <stdlib.h>
class Massiv
{

public:
    Massiv(int lenParameter)
    {
        len = lenParameter;
        array = (int *)malloc(len * sizeof(int));
        ptr = array;
    }
    ~Massiv()
    {
        delete[] array;
    }

    void show()
    {
        for (int i = 0; i < len; i++)
        {
            std::cout << "\n"
                      << ptr[i];
        }
    }

    void setter(int num, int setterIndex)
    {
        bool success = true;
        if (num >= -100 && num <= 100 && setterIndex < len)
            ptr[setterIndex] = num;
        if (ptr[setterIndex] != num)
            success = false;
        std::cout << "\nsuccess: " << success << std::endl;
    }

    void getter(int getterIndex)
    {
        if (getterIndex < len)
            std::cout << "\n" << ptr[getterIndex];
    }

    void copy(Massiv from, Massiv to)
    {
        bool success = true;
        for (int i = 0; i < len; i++)
            to.ptr[i] = from.ptr[i];
        for (int i = 0; i < len; i++)
        {
            if (to.ptr[i] != from.ptr[i])
            {
                success = false;
                break;
            }
        }
        std::cout << "\nsuccess: " << success << std::endl;
    }
    void beyond(int num)
    {
        int prevLen = len;
        bool success = true;
        if (num >= -100 && num <= 100)
        {
            len += 1;
            array = (int *)realloc(array, len * sizeof(int));
            ptr[len - 1] = num;
        }
        if (ptr[len - 1] != num || prevLen == len)
            success = false;
        std::cout << "\nsuccess: " << success << std::endl;
    }

    int *sum(Massiv *array1, Massiv *array2)
    {
        bool success = true;
        int *arrayFullSum = (int *)malloc(array1->len * sizeof(int));
        for (int i = 0; i < array1->len; i++)
        {
            arrayFullSum[i] = array1->ptr[i] + array2->ptr[i];
        }
        for (int i = 0; i < array1->len; i++)
        {
            if (arrayFullSum[i] != array1->ptr[i] + array2->ptr[i])
            {
                success = false;
                break;
            }
        }
        std::cout << "\nsuccess: " << success << std::endl;
        return arrayFullSum;
    }

private:
    int len;
    int *array;
    int *ptr;
};

int main()
{
    Massiv array(5);

    for (int i = 0; i < 5; i++)
    {
        array.setter(i, i);
    }
    array.beyond(99);
    array.show();
    
}
