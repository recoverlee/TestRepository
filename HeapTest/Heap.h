#ifndef _HEAP_H_
#define _HEAP_H_

static const int MAX_HEAP_LENGTH = 50;

#include <iostream>

template< typename T, typename Cmp >
class Heap
{
public:
	Heap();
	~Heap();
	void Add(T data);
	T Remove(void);
	int GetCount()
	{
		return __count;
	}

	void PrintHeap(void)
	{
		for (int i = 0 ; i < __count ; i++)
		{
			std::cout << __data[i] << "\t";
		}
		std::cout << std::endl;
		
	}
	
public:
	void Swap(T& value1, T& value2);

	T __data[MAX_HEAP_LENGTH];
	int __count;
};

template< typename T, typename Cmp >
Heap<T,Cmp>::Heap()
	: __count(0)
{

}

template< typename T, typename Cmp >
Heap<T,Cmp>::~Heap()
{

}

// Up heap 적용
template< typename T, typename Cmp >
void Heap<T,Cmp>::Add(T data)
{
	// 우선 배열의 맨 끝에 저장
	__data[__count] = data;
		
	int currentIndex = __count;

	int parentIndex = (currentIndex-1) / 2;

	// 부모보다 클 동안 swap
	while (currentIndex != 0 && Cmp()(__data[currentIndex], __data[parentIndex]) > 0 )
	{
		Swap(__data[currentIndex],__data[parentIndex]);

		currentIndex = parentIndex;
		parentIndex = (currentIndex-1) / 2;
	}
	__count++;
}

// Down heap 적용
template< typename T, typename Cmp >
T Heap<T,Cmp>::Remove(void)
{
	T retData = __data[0];
	__count--;
	__data[0] = __data[__count];

	int currentIndex = 0;
	int leftChildIndex = 2 * currentIndex + 1;	
	int rightChildIndex = 2 * currentIndex + 2;

	int childIndex = leftChildIndex; //일단 좌측 자식을 넣어서 시작

	// 좌측 child index가 leaf node인지 판단
	while (childIndex <= __count)
	{
		rightChildIndex = childIndex + 1;

		// 우측 child index가 leaf node인지 판단 및 우측이 더 값이 큰 지 판단
		if (rightChildIndex <= __count && Cmp()(__data[rightChildIndex], __data[childIndex]) > 0)
		{
			childIndex = rightChildIndex;
		}

		
		if (Cmp()(__data[childIndex], __data[currentIndex]) > 0)
		{
			Swap(__data[childIndex],__data[currentIndex]);
		}
		else
		{
			break;
		}
		currentIndex = childIndex;
		childIndex = 2 * currentIndex + 1;
	}
	
	return retData;
}



template< typename T, typename Cmp >
void Heap<T,Cmp>::Swap(T& value1, T& value2)
{
	T temp = value1;
	value1 = value2;
	value2 = temp;
}



#endif
