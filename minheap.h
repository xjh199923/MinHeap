template<class E>
class MinHeap
{
	private:
		E *heap;//存放元素的数组
		int count;//当前储存个数
		int maxsize;//最小堆最多允许个数
		void siftdown(int start,int m);//从start到m下滑调整成为最小堆
		void siftup(int start);//从start到0上滑调整成为最小堆
		int tmp;//封装一个tmp来计算比较次数
	public:
		MinHeap(int sz=1000);//构造函数建立空堆
		MinHeap(E arr[],int n);//构造函数，通过一个数组建立堆
		~MinHeap(){delete []heap;}//析构函数
		bool Insert(E &x);//将x插入到最小堆中
		bool Remove(E &x);//删除堆顶上的最小元素
		bool Isempty()//判断堆是否为空
		{
			return (count==0)?true:false;
		}
		bool Isfull()//判断堆是否满
		{
			return (count==maxsize)?true:false;
		}
		void makeempty()
		{
			count=0;
		}
		void show();//打印当前堆的数据
};
template<class E>
MinHeap<E>::MinHeap(int sz)
{
	maxsize=sz;
	heap=new E[maxsize];
	if(heap==NULL)
	{
		cerr<<"堆存储分配失败！"<<endl;
		exit(1);
	}
	count=0;
	tmp=0;
};

template<class E>
MinHeap<E>::MinHeap(E arr[],int n)
{
	tmp=0;
	if(10<n)
		maxsize=n;
	else
		maxsize=10;
	heap=new E[maxsize];
	if(heap==NULL)
	{
		cerr<<"堆存储分配失败！"<<endl;
		exit(1);
	}
	for(int i=0;i<n;i++)
	{
		heap[i]=arr[i];
	}
	count=n;//复制堆数组，建立当前大小
	int pos=(count-2)/2;//找最初调整位置，最后分支结点
	while(pos>=0)//自底向上逐步扩大形成堆
	{
		siftdown(pos,count-1);//局部自上向下下滑调整
		pos--;
	}
	
};
//最小堆下滑调整算法
template<class E>
void MinHeap<E>::siftdown(int start,int m)
{//私有函数，从start开始到m为止，自上向下比较，如果子女的值小于父节点的值，则关键码小的上浮，继续向下层比较，这样将一个集合局部调整为最小堆
	int i=start,j=2*i+1;//j是i的左子女位置
	E temp=heap[i];
	while(j<=m)//检查是否到最后位置
	{
		if(j<m&&heap[j]>heap[j+1])//让j指向两个子女的小者
			j++;
			tmp++;
		if(temp<=heap[j])//小则不做调整
			break;
		else//否则小者上移动，i，j,下降
		{
			heap[i]=heap[j];
			i=j;j=2*i+1;
		}
	}
	heap[i]=temp;//回放temp中暂存的元素
};
//最小堆上滑调整算法
template<class E>
void MinHeap<E>::siftup(int start)
{//私有函数，从start开始到结点0为止，自下向上比较，如果子女的值小于父节点的值，则互相交换，这样将一个集合局部调整为最小堆
	int j=start,i=(j-1)/2;
	E temp=heap[j];
	while(j>0)//沿父节点路径向上直到极限
	{
		if(heap[i]<=temp)//父节点不调整
		{
			tmp++;
			break;
		}
		else
		{
			heap[j]=heap[i];
			j=i;
			i=(i-1)/2;
		}
	}
	heap[j]=temp;
};
//最小堆插入算法
template<class E>
bool MinHeap<E>::Insert(E &x)
{
	if(count==maxsize)
	{
		cerr<<"Heap Full"<<endl;
		return false;
	}
	heap[count]=x;//插入
	siftup(count);//向上调整
	count++;//当前堆加一
	return true;
};
/*通常，从最小堆删除具有最小关键码记录的操作是将最小堆的堆顶元素，即其完全二又
树的顺序表示的第0号元素删去。在把这个元素取走后，一般以堆的最后一个结点填补取
走的堆顶元素，并将堆的实际元素个数减1。但是用最后一个元素取代堆顶元素将破书钱：
需要调用siftDown算法从堆顶向下进行调整。
*/
template<class E>
bool MinHeap<E>::Remove(E &x)
{
	if(!count)
	{
		cout<<"Heap Empty!"<<endl;
		return false;//堆空返回false
	}
	x=heap[0];
	heap[0]=heap[count-1];//最后元素填补到根结点
	count--;
	siftdown(0,count-1);//向下调整
	return true;
};
template<class E>
void MinHeap<E>::show()
{
	E m;
	while(count>0)
	{
		Remove(m);
		cout<<m<<" ";
	}
	cout<<"\n最小堆排序的比较次数为："<<tmp<<"次！"<<endl;
}