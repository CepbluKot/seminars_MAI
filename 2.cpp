#include <iostream>
#include <stdlib.h>

template <typename type>
class Massiv
{

private:
    int len;
    type *array;
    type *ptr;

public:
    Massiv(int lenParameter)
    {
        len = lenParameter;
        try
        {
            array = (type *)malloc(len * sizeof(type));
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
                std::cout << "\n  " << ptr[i];
            }
            catch (std::out_of_range &e)
            {
                std::cout << "\nout_of_range: " << e.what();
            }
        }
    }

    void setter(type, int);
    // void setter(int, int);

    type getter(int getterIndex)
    {
        try
        {
            if (getterIndex < len)
                return ptr[getterIndex];
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
                    int len;
                }
                std::cout << "\nsuccess: " << success << std::endl;
            }
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "\nout_of_range: " << e.what() << '\n';
        }
    }

    void beyond(type num)
    {

        try
        {
            int prevLen = len;
            bool success = true;
            len += 1;
            array = (type *)realloc(array, len * sizeof(type));
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

    // void beyond(type num)
    // {
    //     int prevLen = len;
    //     bool success = true;
    //     if (num >= -100 && num <= 100)
    //     {
    //         try
    //         {
    //             len += 1;
    //             array = (type *)realloc(array, len * sizeof(type));
    //             ptr[len - 1] = num;
    //             if (ptr[len - 1] != num || prevLen == len)
    //                 success = false;
    //             std::cout << "\nsuccess: " << success << std::endl;
    //         }
    //         catch (const std::bad_alloc &e)
    //         {
    //             std::cerr << "\nbad_alloc: " << e.what() << '\n';
    //         }
    //     }
    // }

    int getLen()
    {
        return len;
    }
};

// template <typename type>
// void Massiv<type>::setter(int num, int setterIndex)
//     {
//         bool success = true;
//         try
//         {
//             ptr[setterIndex] = num;
//             if (ptr[setterIndex] != num)
//                 success = false;
//             std::cout << "\nsuccess: " << success << std::endl;
//         }
//         catch (std::invalid_argument &e)
//         {
//             std::cout << "\ninvalid_argument: " << e.what() << std::endl;
//         }
//     }

template <typename type>
void Massiv<type>::setter(type num, int setterIndex)
{
    bool success = true;

    if (std::is_same_v<type, int>)
    {
        if (!(num >= -100 && num <= 100))
            return;
    }

    try
    {
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

template <typename sumType>
sumType *sum(Massiv<sumType> *array1, Massiv<sumType> *array2)
{
    bool success = true;
    try
    {
        sumType *arrayFullSum = (sumType *)malloc(array1->getLen() * sizeof(sumType));
        for (int i = 0; i < array1->getLen(); i++)
        {
            arrayFullSum[i] = array1->getter(i) + array2->getter(i);
        }
        for (int i = 0; i < array1->getLen(); i++)
        {
            if (arrayFullSum[i] != array1->getter(i) + array2->getter(i))
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

int main()
{
    Massiv<char> array(3);
    Massiv<int> arint(3);
    array.setter('a', 0);
    array.setter('b', 1);
    array.setter('c', 2);

    arint.setter(1, 0);
    arint.setter(2, 1);
    arint.setter(3, 2);
    
    array.beyond('w');
    arint.show();
    array.show();
}
