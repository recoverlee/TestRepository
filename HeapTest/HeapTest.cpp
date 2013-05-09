#include "Heap.h"
#include <string>

struct IntCompare
{
	int operator() (int value1, int value2)
	{
		if (value1 > value2)
		{	
			return 1;
		}
		else if(value1 < value2)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
};

template< typename T >
class PriorityQueue
{
public:
	struct HeapNode
	{
		int priority;
		T data;
	};

	struct HeapNodeCompare
	{
		int operator() (HeapNode value1, HeapNode value2)
		{
			if (value1.priority > value2.priority )
			{	
				return 1;
			}
			else if(value1.priority  < value2.priority)
			{
				return -1;
			}
			else
			{
				return 0;
			}
		}
	};

	

public:
	PriorityQueue() {}
	~PriorityQueue() {}

	void Add(HeapNode node);
	HeapNode Remove(void)
	{
		return __heap.Remove();
	}
	void Print(void)
	{
		for (int i = 0 ; i < __heap.GetCount() ; i++)
		{
			std::cout << "priority : " << __heap.__data[i].priority << " data : " << __heap.__data[i].data << std::endl;
		}
	}
	
	int GetCount(void)
	{
		return __heap.GetCount();
	}
		
private:

	Heap<HeapNode, HeapNodeCompare> __heap;
};

template<typename T>
void PriorityQueue<T>::Add(HeapNode node)
{
	__heap.Add(node);
}

//typedef PriorityQueue<std::string>::HeapNode Node;

//template<typename T>
//Node PriorityQueue<T>::Remove(void)
//{
	//return __heap.Remove();
//}



int main(void)
{
	Heap<int, IntCompare> heap;

	heap.Add(5);
	heap.Add(1);
	heap.Add(9);
	heap.Add(8);
	heap.Add(9);
	heap.Add(2);
	heap.Add(4);
	heap.Add(7);
	heap.PrintHeap();

	while (heap.GetCount())
	{
		heap.Remove();
		heap.PrintHeap();
	}


	PriorityQueue<std::string> queue; 

	PriorityQueue<std::string>::HeapNode node[8] =  { 
		{5, "°¡Á·"},
		{1, "È¸»ç"},
		{9, "¿ìÄí·¼·¹"},
		{8, "½ºÅÍµð"},
		{9, "»ç¶û"},
		{2, "¿ìÁ¤"},
		{4, "ÇÇ°ï"},
		{7, "±«·Î¿ò"}
	};
						
	for ( int i = 0 ; i < 8 ; i++)
	{
		queue.Add(node[i]);
	}
	
	queue.Print();


	while (queue.GetCount())
	{
		std::cout << std::endl;
		queue.Remove();
		queue.Print();
		
	}

	
	return 0;

}