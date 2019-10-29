# MinHeap
Assuming that there are n data objects (n>=100), n random numbers are now generated as the priority of the n objects, and the smaller the value, the higher the priority. Let the n objects enter the team and then dequeue according to the priority level. The rule is: the object with high priority is first out. To achieve the above operation, the possible solutions are as follows: 
 Solution 1: Let n objects enter the queue in turn, and then search the queue according to the priority of the object when the team is drawn, and find out the elements with high priority. 
 Solution 2: N objects are sorted by priority using direct insertion sorting or direct selection sorting method that they have learned, and then dequeued in turn. 
 Solution 3: Build the minimum heap of n objects, and then let the root node elements dequeue, and re-adjust the elements in the queue to the minimum heap after each dequeue operation.
 
 1. There are element comparison operations in all three schemes. The three schemes are used to calculate the number of comparisons required for the highest priority elements in the current queue to complete the dequeue operation and all the n elements are dequeued. The total number of comparisons of the dequeue, and comparative analysis of the space-time cost of the three options.
2. According to the definition and operation characteristics of the heap, n objects are sorted according to their priorities.

假设有n个数据对象（n>=100），现产生n个随机数分别作为这n个对象的优先级，值越小，表示优先级越高。让这个n个对象进队，再按优先级的高低出队，规则为：优先级高的对象先出队。
为实现以上操作，可能的方案如下：
方案一：让n个对象依次进队，出队时再根据对象的优先级去搜索队列，查找出优先级高的元素出队。
方案二：将n个对象使用曾经学过的直接插入排序或直接选择排序方法将其按优先级进行排序，再依次出队。
方案三：将n个对象构建最小堆，再让根结点元素出队，每次出队操作后重新将队列中的元素调整为最小堆。

1、这三种方案中均存在元素比较操作，试通过实验对此三个方案分别统计当前队列中优先级最高的元素完成出队操作所需要的比较次数以及所有n个元素按出队规则全部出队的总的比较次数，并对比分析三种方案的时空代价。
2、根据堆的定义和操作特点，将n个对象按其优先级进行排序处理。
