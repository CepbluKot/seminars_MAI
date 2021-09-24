#include <iostream>
#include <stdlib.h>
class Massiv {
    
public:
    int len;
    Massiv(int lenParameter)
    {   
        len = lenParameter;
    }
    ~Massiv()
    {

    }
    
    int* array = (int*) malloc (len * sizeof (int));
    int* ptr = array;

    void show() 
	{
        std::cout << ptr;
    }
    
    void setter(int num, int setterIndex) {
        if (num >= -100 && num <= 100 && setterIndex < len) 
        {
            ptr[setterIndex] = num;
            
        }
    }
    
    void getter(int getterIndex) 
    {
        if (getterIndex < len) std::cout << ptr[getterIndex]; // trojan warn
    }
    
    void copy(Massiv from, Massiv to)
	{
    	for(int i = 0; i < len; i++) to.ptr[i] = from.ptr[i];
	}
	void beyond(int num)
	{	
		if(num >= -100 && num <= 100)
		{
		len += 1;
		array = (int*) realloc (array, len * sizeof (int));
		ptr[len - 1] = num;
		}
	}
	
};
	
	
int* sum(Massiv* array1, Massiv* array2)
	{
		int* arrayFullSum = (int*) malloc (array1->len * sizeof (int));
		for(int i = 0; i < array1->len; i++)
		{
			arrayFullSum[i] = array1->ptr[i] + array2->ptr[i];
		}
		
		return arrayFullSum;	
	}


int main()
{
    
}


