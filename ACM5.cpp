#include<iostream>
#define fors(loop) for(int i=0;i<loop;i++)

class quick_sort
{
public:
	void input();
	void sort();
	void out();
private:
	int *a;
	int c[100];
	int length;
	bool sort_pas=false;
	void sort_pass();
	inline void sort(int *a, int sta, int end,int z);
};

void quick_sort::input()
{
	std::cout << "输入数字数量" << std::endl;
	std::cin >> length;
	//a = new int(length);
	a = c;
	std::cout << "依次输入数据，空格间隔please~" << std::endl;
	fors(length)
		std::cin >> a[i];
	std::cout << "是否显示排序过程？是的输入y~" << std::endl;
	char y;
	std::cin >> y;
	if (y == 'y')
		sort_pass();
}

void quick_sort::sort_pass()
{
	sort_pas=true;
}

void quick_sort:: out()
{
	fors(length)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}

void quick_sort::sort()
{
	sort(a,0,length-1,0);
}

void quick_sort::sort(int a[], int sta, int end,int z)
{
	if (sta >= end)
		return;
	int i = sta;
	int j = end;
	int reference = a[sta];
	while (sta < end)
	{
		while (a[end] > reference && end>sta)end--;
		a[sta] = a[end];
		while (a[sta] < reference && end>sta)sta++;
		a[end] = a[sta];
	}
	a[end] = reference;
	if (sort_pas)
	{
		std::cout << "递归深度：" << z <<"，  数组状态：";
		out();
	}
	sort(a, i, end - 1, z + 1);
	sort(a,end+1,j, z + 1);
}


class quicksort_node
{
public:
	quick_sort input;
};

void msin()
{
	quick_sort qst;
	qst.input();
	qst.sort();
	qst.out();
	system("pause");

}
class base
{
    int mx;
public:
    static int xxx;
    static void fun(int x)
    {
        xxx=x;
    }
    base(int x):mx(x){}
    friend std::ostream& operator<<(std::ostream& ,base&);
};
int base::xxx=0;

class test:public base
{
    public:
    test(int x):base(x){}
};

std::ostream& operator<<(std::ostream& os,base& s)
{
    os<<s.mx;
    return os;
}
class tevv :test
{
public :
	tevv() :test(0) {}
};

