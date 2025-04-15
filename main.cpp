#include <iostream>
template <typename T>
class GenericArray
{
	private:
	T* data;
	int size;
	
	public:
    	GenericArray() : data(NULL), size(0) {}

    	void addElement(const T& element);

    	T at(int param);

    	int getSize();

    	T sum();

    	T max();

    	T min();

    	T* slice(int begin, int end);
};











template <typename T>
void GenericArray<T>::addElement(const T& element)
{
	T *newData = new T[size +1];

	for (int i = 0 ; i < size ; i++)
	{
		newData[i] = data[i];
	}
	
	newData[size] = element;

	delete[] data;

	data = newData;
	size ++;	
}

template <typename T> 
T GenericArray<T>::at(int param)
{
	if (param < 0 || param >= size)
	{
		std::cout<< "is out of bounds" <<std::endl;
		return T();
	}

	return data[param];
}


template <typename T>
int GenericArray<T>::getSize()
{
	return size;
}






template <typename T> 
T GenericArray<T>::sum()
{
	T sum = T();
	for (int i = 0 ; i < size; i++)
	{
		sum += data[i];

	}
	return sum;
}

template <typename T>
T GenericArray<T>::max()
{
	T max = T();
	for (int i = 0; i <size; i++)
	{
		if (max < data[i])
		{
			max = data[i];
		}
	}
	return max;
}

template <typename T>
T GenericArray<T>::min()
{
        T min = data[0];
        for (int i = 0; i <size; i++)
        {
                if (min > data[i])
                {
                        min = data[i];
                }
        }
        return min;
}

template <typename T>
T* GenericArray<T>::slice(int begin, int end)
{
	if (begin < 0 || end >= size || begin > end) 
	{
		std::cout<< " invalid indeices";
		return NULL;		
	}
	int sliceSize = end - begin + 1;
        T* sliceArry = new T[sliceSize];


	for (int i = 0; i < sliceSize; i++)
	{
		sliceArry[i] = data[begin+i];
	}
	return sliceArry;
}



int main()
{
	GenericArray<int> int_array;
	int_array.addElement(10);
   	int_array.addElement(20);
    	int_array.addElement(30);
	int_array.addElement(40);
	int_array.addElement(50);

	std::cout << "size of array is " << int_array.getSize() << std::endl;
	std::cout << "sum of the array is " << int_array.sum() << std::endl;
	std::cout << "maximum of array is " << int_array.max() <<std::endl;
	std::cout << "minimum of array is " << int_array.min() <<std::endl; 
	

    	int* sliced_array = int_array.slice(1, 3);
    	if (sliced_array != NULL) 
	{
        	int sliceSize = 3;
        	std::cout << "Sliced array elements: ";
        	
		for (int i = 0; i < sliceSize; ++i) 
		{
            		std::cout << sliced_array[i] << " ";
 		}

	delete[] sliced_array;
	return 0;
	}	

}







