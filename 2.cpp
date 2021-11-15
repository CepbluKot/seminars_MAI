#include <iostream>
#include <stdlib.h>
class Massiv
{
private:
    int len;
    int *array;
    int *ptr;

public:
    Massiv(int lenParameter)
    {
        len = lenParameter;
        try
        {
            array = (int *)malloc(len * sizeof(int));
            ptr = array;
        }
        catch (const std::bad_alloc &e)
        {
            std::cerr << "\nbad_alloc" << e.what() << '\n';
        }
    }
    ~Massiv()
    {
        delete[] array;
    }

    void show()
    {
        for (int i = 0; i < len; i++)
        {
            try
            {
                std::cout << "\n"
                          << ptr[i];
            }
            catch (std::out_of_range &e)
            {
                std::cout << "\nout_of_range: " << e.what();
            }
        }
    }

    void setter(int num, int setterIndex)
    {
        bool success = true;
        try
        {
            if (num >= -100 && num <= 100 && setterIndex < len)
                ptr[setterIndex] = num;
            if (ptr[setterIndex] != num)
                success = false;
            std::cout << "\nsuccess: " << success << std::endl;
        }
        catch (std::invalid_argument &e)
        {
            std::cout << "\ninvalid_argument: " << e.what() << std::endl;
        }
    }

    void getter(int getterIndex)
    {
        try
        {
            if (getterIndex < len)
                std::cout << "\n"
                          << ptr[getterIndex];
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "\nout_of_range: " << e.what() << '\n';
        }
    }

    void copy(Massiv from, Massiv to)
    {
        bool success = true;
        try
        {
            for (int i = 0; i < len; i++)
            {
                to.ptr[i] = from.ptr[i];
            }
            for (int i = 0; i < len; i++)
            {
                if (to.ptr[i] != from.ptr[i])
                {
                    success = false;
                    break;
                }
                std::cout << "\nsuccess: " << success << std::endl;
            }
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "\nout_of_range: " << e.what() << '\n';
        }
    }

    void beyond(int num)
    {
        int prevLen = len;
        bool success = true;
        if (num >= -100 && num <= 100)
        {
            try
            {
                len += 1;
                array = (int *)realloc(array, len * sizeof(int));
                ptr[len - 1] = num;
                if (ptr[len - 1] != num || prevLen == len)
                    success = false;
                std::cout << "\nsuccess: " << success << std::endl;
            }
            catch (const std::bad_alloc &e)
            {
                std::cerr << "\nbad_alloc: " << e.what() << '\n';
            }
        }
    }

    int *sum(Massiv *array1, Massiv *array2)
    {
        bool success = true;
        try
        {
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
        catch (const std::bad_alloc &e)
        {
            std::cerr << "\nbad_alloc: " << e.what() << '\n';
        }
    }
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
