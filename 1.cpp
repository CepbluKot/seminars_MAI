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

    void show() {
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
        if (getterIndex < len) std::cout << ptr[getterIndex];
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

int main()
{
    Massiv from(5);
    Massiv to(5);
    for (int i = 0; i < 5; i++) from.setter(i,i);
    for (int i = 0; i < 5; i++) from.getter(i);
    std::cout<<"\n";
    to.copy(from, to);
    for (int i = 0; i < 5; i++) to.getter(i);
    std::cout<<"\n";
    to.beyond(88);
    for (int i = 0; i < 6; i++) to.getter(i);
    
}


