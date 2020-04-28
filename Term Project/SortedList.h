/*Written by James Curtis Addy*/
#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#define DEFAULT_MAX_SIZE 25 //initial max size of container

template<class T>
class SortedList 
{
public:
	SortedList();
	SortedList(size_t max_size);
	~SortedList<T>();
	void Insert(T item);
	void Delete(T item);
	int GetPos(T item);
	void Clear();
	int GetLength();
	T operator[](int index);
private:
	size_t max_size; 
	T* items;
	size_t length;	
	void Resize();
};

/*Written by James Curtis Addy*/
template<class T>
SortedList<T>::SortedList()
{
	max_size = DEFAULT_MAX_SIZE;
	items = new T[max_size];
}

template<class T>
SortedList<T>::SortedList(size_t max_size)
{
	this->max_size = max_size;
	items = new T[max_size];
}

template<class T>
SortedList<T>::~SortedList()
{
	delete[] items;
}

template<class T>
void SortedList<T>::Resize()
{
	max_size *= 2; //double capacity
	T* new_items = new T[max_size];
	for (int i = 0; i < length; i++)
	{
		new_items[i] = items[i];
	}
	delete[] items; //free up memory 
	items = new_items;
}

template<class T>
void SortedList<T>::Insert(T item)
{
	if (length + 1 > max_size)
	{
		Resize();
	}
	int i = length - 1;
	while (i >= 0 && item < items[i])
	{
		items[i + 1] = items[i];
		i--;
	}
	items[i + 1] = item;
	length++;
}

template<class T>
void SortedList<T>::Delete(T item)
{
	int position = GetPos(item);
	if (position != -1)
	{
		for (int i = position; i < length - 1; i++)
		{
			items[i] = items[i + 1];
		}
		length--;
	}
}

template<class T>
int SortedList<T>::GetPos(T item)
{
	//Binary Search
	int first = 0;
	int last = length - 1;
	int middle;
	while (last >= first)
	{
		middle = (first + last) / 2;
		if (item == items[middle])
		{
			return middle;
		}
		else if (item < items[middle])
		{
			last = middle - 1;
		}
		else //item is > items[i]
		{			
			first = middle + 1;
		}		
	}
	return -1; //item never found
}

template<class T>
void SortedList<T>::Clear()
{
	length = 0;
}

template<class T>
int SortedList<T>::GetLength()
{
	return length;
}

template<class T>
T SortedList<T>::operator[](int index)
{
	return items[index];
}
#endif // !SORTED_LIST_H

