#include<assert.h>
#include <iostream>
using namespace std;
#include <stdlib.h>
template <class T>
class PQueue 
{
	private:
		T *pqelements;//存放数组
		int count;  //队列元素计数
	    int maxPQSize;//最大元素个数
	    void adjust(); 
	    int tmp;    
	public:
	     PQueue(int sz = 1000);
	    ~PQueue(){ delete [ ] pqelements; }
	    bool Push(T x);
	    bool RemoveMin(T& x); 
	    bool GetFront(T& x); 
	    void MakeEmpty() { count = 0; }
  	    bool IsEmpty() const { return count == 0; }
		bool IsFull() const 
		{ return count == maxPQSize; }	
		int Length() const { return count; }
		bool show();
};
template <class T> 
PQueue<T>::PQueue(int sz) 
{ 
	maxPQSize = sz;  
	count = 0; 
	tmp=0;
	pqelements = new T[maxPQSize];	
	assert (pqelements != NULL); 
}

template <class T> 
bool PQueue<T>::Push(T x) 
{
	  if (IsFull() == true) 
		 return false;    //判队满断
	  pqelements[count++] = x;  //插入
	  adjust();  
	 return true;
}

template <class T> 
void PQueue<T>::adjust() 
{
	  T temp = pqelements[count-1];
	  //将最后元素暂存再从后向前找插入位置
	int j;
	for (j = count-2;  j >= 0;  j--)
	 {
			if (pqelements[j] <= temp){
				tmp++;
				break; 
			}
			
			else pqelements[j+1] = pqelements[j];
	}
	pqelements[j+1] = temp;
	  
}
template <class T> 
bool PQueue<T>::RemoveMin(T& x) 
{
	  if (IsEmpty()) 
		 return false;
	  x = pqelements[0]; //取出0号元素
	  for (int i = 1; i < count; i++)
			pqelements[i-1] = pqelements[i];
			 //从后向前逐个移动元素填补空位
	  count--;
	  return true;
} 
template <class T>
bool PQueue<T>::GetFront (T& x) 
{
	  if (IsEmpty() == true) 
		 return false;
	  x = pqelements[0];  
	  return true;
}
template<class T>
bool PQueue<T>::show()
{
	if (IsEmpty() == true) 
		return false;
	for(int i=0;i < count;i++)
	{
		cout<< pqelements[i]<<" ";
	}
	cout<<"\n优先级队列排序的比较次数为"<<tmp<<"次！"<<endl;
	return true;
}