/*
 Created by xjh on 2019/10/26.
*/
#include <iostream>
#include <vector>
#include "PreQueue.h"
#include "minheap.h"
#include <time.h>
using namespace std;
const int MAX_NUM = 100000;
vector<int> get_random(int n, int N);//产生n个小于N的随机数
void select(vector<int> randsample);
void MinHeapSelect(vector<int> randsample);
void PreQueueselect(vector<int> randsample);
int main()
{
	srand((unsigned int)time(0));
	vector<int> randsample=get_random(500,MAX_NUM);
	//方案一进行优先级队列排序
	cout<<"简单选择排序："<<endl;
	clock_t start,finish;
	double totaltime;
	start=clock();
	select(randsample);
	finish=clock();
	totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
	cout<<"\n简单选择排序的运行时间为"<<totaltime<<"秒！"<<endl;
	cout<<endl;
	//方案二进行优先级选择排序
	cout<<"优先级队列排序："<<endl;
	start=clock();
	PreQueueselect(randsample);
	finish=clock();
	totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
	cout<<"\n优先级队列排序的运行时间为"<<totaltime<<"秒！"<<endl;
	cout<<endl;
	cout<<"最小堆排序："<<endl;
	start=clock();
	MinHeapSelect(randsample);
	finish=clock();
	totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
	cout<<"\n最小堆排序的运行时间为"<<totaltime<<"秒！"<<endl;
	cout<<endl;
	
}
vector<int> get_random(int n, int N)
{
	vector<int> vec(N);//N代表初始状态分配的空间大小
	vector<int> out_vec;
	for(int i=0;i<N;++i)
	{
		vec[i]=i;
	}
	for (int i=0;i<n;++i)
	{
		int rand_value=rand()%N;
		out_vec.push_back(vec[rand_value]);
		vec[rand_value]=vec[N-1];//将数组vec的元素
		N--;
	}
	return out_vec;
}
void select(vector<int> randsample)
{
	int count=0;
	int n=randsample.size();
	int a[n];
	for (size_t i=0;i<randsample.size();++i)
	{
		a[i]=randsample[i];
	}
	//下面对整个数组进行从小到大排序
	for(int i = 0; i<n-1 ;++i){     //每次循环将第i小的元素放好 
		int tmpMin = i;  //用来记录从第i个到第n-1个元素中,最小的那个元素的下标 
		for(int j=i; j<n;++j){
			if(a[j]<a[tmpMin])
			{
				count++;
				tmpMin = j;
			}
		}
	//下面将第i小的元素放在第i个位置上,并将原来占着第i个位置的那个元素挪到后面
		int tmp = a[i];
		a[i] = a[tmpMin];
		a[tmpMin] = tmp; 
	}
	//下面两行将排序好的n个元素输出
	for(int i=0;i<n;++i)
		cout << a[i]<<" ";
	cout<<"\n队列排序的比较次数为："<<count<<"次！"<<endl;
}
void PreQueueselect(vector<int> randsample)
{
	PQueue<int> tmp;
	int n=randsample.size();
	for(int i=0;i<n;i++)
	{
		tmp.Push(randsample[i]);
	}
	tmp.show();
}
void MinHeapSelect(vector<int> randsample)
{
	MinHeap<int> tmp;
	int n=randsample.size();
	for(int i=0;i<n;i++)
	{
		tmp.Insert(randsample[i]);
	}
	tmp.show();
}