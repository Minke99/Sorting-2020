template<class T> //此处先不涉及空间置配器
class list{    //list类
　　public:
　　　　struct _Node;
　　typedef struct _Node* _Nodeptr;  //指向节点的指针类型
　　struct _Node{   //_Node这个是节点类型
        　　_Nodeptr _Prev;    //前驱节点
        　　_Nodeptr _Next;    //后继节点
       　　 T      _Value;   //模板数据类型
};
//////////////////////////////////////////////////////////////////////////////
list 容器的使用、创建和初始化
list 容器的构造函数的用法类似于 vector 或 deque 容器。下面这条语句生成了一个空的 list 容器：
	std::list<T> words;
可以创建一个带有给定数量的默认元素的列表：
	std::list<std::string> sayings {20}; // A list of 20 empty strings
元素的个数由构造函数的参数指定，每一个元素都由默认的构造函数生成，因此这里调用 string() 来生成元素。

下面展示如何生成一个包含给定数量的相同元素的列表：
	std::list<double> values(50, 3.14159265);
这里生成了一个具有 50 个 double 型值的列表，并且每一个值都等于 π。注意在圆括号中，不能使用初始化列表 {50,3.14159265}，这样列表将仅仅包含两个元素。

list 容器有一个拷贝构造函数，因此可以生成一个现有 list 容器的副本：
	std::list<double> save_values {values}; // Duplicate of values
可以用另一个序列的开始和结束迭代器所指定的一段元素，来构造 list 容器的初始化列表：
	std::list<double> samples {++cbegin(values), --cend(values)};
除了 value 中的第一个和最后一个元素，其他元素都被用来生成列表。
因为 list 容器的 begin() 和 end() 函数返回的都是双向迭代器，所以不能用它们加减整数。
修改双向迭代器的唯一方式是使用自增或自减运算符。当然，在上面的语句中，初始化列表中的迭代器可以代表任意容器的一段元素，而不仅仅只是 list 容器。

可以通过调用 list 容器的成员函数 size() 来获取它的元素个数。也可以使用它的 resize() 函数来改变元素个数。如果 resize() 的参数小于当前元素个数，
会从尾部开始删除多余的元素。如果参数比当前元素个数大，会使用所保存元素类型的默认构造函数来添加元素。
//////////////////////////////////////////////////////////////////////////////
1	c.empty()					//容器为空返回true，不为空返回false，相当于size()==0
2	c.size()					//返回当前元素的个数
3	c.max_size()				//返回元素个数之最大可能量
4	c1==c2						//对每个元素调用c1==c2，全部相等返回true
5	c1！=c2						//只要有一个元素相等，返回true，相当于!(c1==c2)
6	c1>c2,c1>=c2,c1<c2,c1<=c2	//同上，依次类推
7	c.front()					//返回第一个元素（不检查是否存在第一个元素）
8	c.back()					//返回最后一个元素（不检查是否存在最后一个元素）
1	c.push_back(elem)			//在list末尾插入元素elem
2	c.pop_back()				//移除最后一个元素，但是不返回该元素
3	c.push_front(elem)			//在首部插入元素elem
4	c.pop_front()				//移除首部元素，但是不返回该元素
5	c.insert(pos,elem)			//在iterator指向的pos位置的前方插入一个元素elem的副本，并返回新元素的位置（此时返回的是整型，而非iterator）
6	c.insert(pos,n,elem)		//在iterator指向的pos位置的前方插入n个元素的副本，并返回第一个新元素的位置
7	c.insert(pos,beg,end)		//在iterator指向的pos位置的前方插入区间[beg,end)内所有元素的副本，并返回第一个新元素的位置
8	c.insert(pos,initlist)		//在iterator指向的pos位置的前方插入初始化列表所有元素的副本，并返回第一个元素的位置（C++11新特性）
9	c.erase(pos)				//移除iterator位置pos上的元素，返回下一个元素的位置
10	c.erase(beg,end)			//移除区间[beg,end)所指向的元素所有内容，返回下一个元素的位置
11	c.resize(num)				//将list大小调整为num，若大小增大，新元素以默认构造函数或者零值进行初始化
12	c.resize(num,elem)			//将list大小调整为num，若大小增大，新元素以elem进行初始化
13	c.remove(val)				//移除所有值为val的元素
14	c.clear()					//移除所有元素，容器清空
//迭代器辅助函数
advance(it, n)			//it 表示某个迭代器，n 为整数。该函数的功能是将 it 迭代器前进或后退 n 个位置。
distance(first, last)	//first 和 last 都是迭代器，该函数的功能是计算 first 和 last 之间的距离。
begin(cont)				//cont 表示某个容器，该函数可以返回一个指向 cont 容器中第一个元素的迭代器。
end(cont)				//cont 表示某个容器，该函数可以返回一个指向 cont 容器中最后一个元素之后位置的迭代器。
prev(it)				//it 为指定的迭代器，该函数默认可以返回一个指向上一个位置处的迭代器。注意，it 至少为双向迭代器。
next(it)				//it 为指定的迭代器，该函数默认可以返回一个指向下一个位置处的迭代器。注意，it 最少为前向迭代器。
//////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <list>
#include <numeric>
#include <algorithm>
 
using namespace std;
 
//创建一个list容器的实例LISTINT
typedef list<int> LISTINT;
 
//创建一个list容器的实例LISTCHAR
typedef list<char> LISTCHAR;
 ///////////////////////
 //如果不写这两句，申明（claim）时： list<int> listOne;
 //写了之后：                  LISTINT listOne;
 //////////////////////
void main(void)
{
    //--------------------------
    //用list容器处理整型数据
    //--------------------------
    //用LISTINT创建一个名为listOne的list对象
    LISTINT listOne;
    //声明i为迭代器
    LISTINT::iterator i;
 
    //从前面向listOne容器中添加数据
    listOne.push_front (2);
    listOne.push_front (1);
 
    //从后面向listOne容器中添加数据
    listOne.push_back (3);
    listOne.push_back (4);
 
    //从前向后显示listOne中的数据
    cout<<"listOne.begin()--- listOne.end():"<<endl;
    for (i = listOne.begin(); i != listOne.end(); ++i)
        cout << *i << " ";
    cout << endl;
 
    //从后向后显示listOne中的数据
	LISTINT::reverse_iterator ir;
    cout<<"listOne.rbegin()---listOne.rend():"<<endl;
    for (ir =listOne.rbegin(); ir!=listOne.rend();ir++) {
        cout << *ir << " ";
    }
    cout << endl;
 

 
    //--------------------------
    //用list容器处理字符型数据
    //--------------------------
 
    //用LISTCHAR创建一个名为listOne的list对象
    LISTCHAR listTwo;
    //声明i为迭代器
    LISTCHAR::iterator j;
 
    //从前面向listTwo容器中添加数据
    listTwo.push_front ('A');
    listTwo.push_front ('B');
 
    //从后面向listTwo容器中添加数据
    listTwo.push_back ('x');
    listTwo.push_back ('y');
 
    //从前向后显示listTwo中的数据
    cout<<"listTwo.begin()---listTwo.end():"<<endl;
    for (j = listTwo.begin(); j != listTwo.end(); ++j)
        cout << char(*j) << " ";
    cout << endl;
 

 
#include <iostream>
#include <list>
 
using namespace std;
typedef list<int> INTLIST;
 
//从前向后显示list队列的全部元素
void put_list(INTLIST list, char *name)
{
    INTLIST::iterator plist;
 
    cout << "The contents of " << name << " : ";
    for(plist = list.begin(); plist != list.end(); plist++)
        cout << *plist << " ";
    cout<<endl;
}
 
//测试list容器的功能
void main(void)
{
//list1对象初始为空
    INTLIST list1;   
    //list2对象最初有10个值为6的元素 
    INTLIST list2(10,6); 
    //list3对象最初有3个值为6的元素 
    INTLIST list3(list2.begin(),--list2.end()); 
 
    //声明一个名为i的双向迭代器
    INTLIST::iterator i;
 
    //从前向后显示各list对象的元素
    put_list(list1,"list1");
    put_list(list2,"list2");
    put_list(list3,"list3");
    
	//对list1容器排序
	list1.sort();
    put_list(list1,"list1");
    
	//结合处理
	list1.splice(++list1.begin(), list3);
    put_list(list1,"list1");
    put_list(list3,"list3"); 
};
