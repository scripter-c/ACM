#include<iostream>
#include<ctime>
using namespace std;
#define unsigned long int ;
int test(int* a,int length,int answer);
int mult(int* a,int length);

class longnumber
{
public:
	void out() { cout << datas; }
	longnumber(int k) { datas = k; };
	longnumber(longnumber *n) {};
	~longnumber() {};
	longnumber operator *(int n) {};
	longnumber operator -(int n) {};
	longnumber operator +(int n) { longnumber a = this; return a; };
	longnumber operator /(int n) {};
	longnumber operator %(int n) { longnumber a = this; int num = 0; for (int i = 0; i < 100; i += 9) { num = 0; for (int j = 0; j < 9 && (i + j) < 100; j += 1) num += 0; for (int j = 0; j < 9 && (i + j) < 100; j++); } };
private:
		int datas = 3;
		int data[100];
};


int getnumber(int *a,int length,int *arrays)
{
	int publicnumber = 1;
	for (int site = 0; site < length; site++)
		arrays[site] = a[site];
	for (int i = 0; i < length-1; i += 1)
	{
		for (int k = i + 1; k < length; k++)
		{
			if (arrays[i] == 0)
				return 1;
			int refer = arrays[i];
			for (int j = refer; j >= 2; j -= 1)
			{
				if (refer % j == 0)
				{
					if (arrays[k] % j == 0)
					{
						publicnumber *= j;
						arrays[k] /= j;
						refer /= j;
					}
				}
			}
		}
	}
	return publicnumber;
}
/* 求N个数的公倍数问题，注解：int储存位数有限，需要更好的数据结构来储存运算数

void main()
{
	srand(time(NULL));
	int length=-1;
	while(cin >> length)
		if(length>0)
			break;
	int *a = new int(length+1);
	for (int i = 0; i < length; i++)
		cin >> a[i];
	int* arrays = new int(length);
	for (int i=0;i<100000;i+=1)
	{
		a[length] = getnumber(a,length,arrays);
		if (test(a,length, mult(a,length)/a[length]) == 1)
		{
			cout << "true" << " ";
		}
		else
		{
			a[length] = getnumber(a, length, arrays);
			cout << "false" << endl;
		}
		for (int j = 0; j <= length; j += 1)
			a[j] = rand()%100+1;
	}
	cin >> a[length];
}
*/
int test(int *a,int length,int answer)
{
	int value = mult(a,length);
	if (value == 0)
		return 1;
	int k = 0;
	int i;
	for (i = 2; i <= value; i += 1)
	{
		for (int j = 0; j < length; j++)
		{
			if (i%a[j] == 0)
				k++;
			else break;
			if (k == length)
			{
			if (i == answer)
				return 1;
			else if (i < answer)
				return 0;
			else
				return -1;
			}
		}
		k = 0;
	}
	
}


int mult(int *a, int length)
{
	int value=1;
	for (int i = 0; i < length; i += 1)
		value *= a[i];
	return value;
}

/*
void main()
{
	longnumber a(5);
	a.out();
	cout << endl;
	longnumber b = a;
	b.out();
	a.~longnumber();
	cout << endl;
	a.out();
	cout << endl;
	b.out();
	cout << endl;
	a + 3;
	a.out();
	cout << endl;
	system("pause");
}*/