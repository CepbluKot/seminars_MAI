#include <iostream>
using namespace std;


class DArr {
public:
	int mSize = 0;
	DArr(int size) {
		mSize = size;
	}
	
	

	int* arr = new int[mSize];
	
	
	void setArr(int ind, int val) {
		if (val >= -100 && val <= 100) {
			arr[ind] = val;
		}
	}
	void print() {
		
		for (int i = 0; i < mSize; i++) {
			cout << arr[i] << endl;
			
		}
	}
	bool getArr(int ind) {
		if (ind < int(sizeof(arr)) / int(sizeof(int))) {
			return true;
		}
		else {
			return(false);
		}
		void coper() {


	}
	}
};


int main()
{

	DArr array(2);
	array.setArr(1, 1);
	array.setArr(0, 0);
	array.print();
	
}
