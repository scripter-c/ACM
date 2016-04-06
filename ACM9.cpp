#include<iostream>
#include<ctime>
using namespace std;
void sirt(int *a, int s, int e);
char* test(int *a,int length);
int test_int(int *a,int length);
int array_change(int *a,int *b,int length);
void array_equal(int *a, int *b,int length );
union as
{
	int c;
	nullptr_t n;
};

struct  structs
{
	int c;
	nullptr_t n;
};


class number
{
public:
	number(int i)
	{
		if (i > 0)
		{
			cout << i << " ";
			number z(i-1);
		}
	}
};
/*
void main()
{


	
	as df;
	df.c = 1;
	cout << (int)df.n<<endl;
	structs ts;
	ts.c = 1;
	ts.n = nullptr;
	cout << (int)ts.n << endl;
	system("pause");
	
	number ass(100);
	
	srand((unsigned int)time(nullptr));
	long t1 = clock() * 1000 / CLOCKS_PER_SEC;
	int a[5];
	for (int k = 0; k < 1000; k++)
	{
		for (int i = 0; i < 5; i++)
			a[i] = rand();
		
		sirt(a,0,5 -1);
		for (int i = 0;i<5;i++)
			cout<<a[i]<<" ";
		
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4 - i; j++)
				if (a[j] > a[j + 1])
				{
					int c = a[j];
					a[j] = a[j + 1];
					a[j + 1] = c;
				}
		}
		if (test(a,sizeof a/sizeof(int)) != "true")
		{
			cout << "false" << endl;
			break;
		}
		if (k == 999)
			cout << "true"<<endl;
	}
	for (int k = 0; k < 1000; k++)
	{
		for (int i = 0; i < 5; i += 1)
			a[i] = rand();
		for (int i = 0; i < 5; i++)
		{
			for (int j = i; j < 5; j++)
				if (a[i]>a[j])
				{
					int c = a[i];
					a[i] = a[j];
					a[j] = c;
				}
		}
		if (test(a,sizeof a/sizeof(int)) != "true")
		{
			cout << "false!" << endl;
			break;
		}
		if (k == 999)
			cout << "true" << endl;
	}
	long t2 = clock() * 1000 / CLOCKS_PER_SEC;
	int *b = new(nothrow) int(sizeof a / sizeof(int));
	
	for (int k = 0; k < 1000; k++)
	{
		for (int i = 0; i < 5; i += 1)
			a[i] = rand();
		array_change(a, b ,sizeof(a)/sizeof(int));
		sirt(a, 0, sizeof a/sizeof(int) - 1);
		array_equal(a,b,sizeof a/sizeof (int));
		if (test_int(a,sizeof a/sizeof(int)) != 1)
		{
			cout << "false!" << endl;
			break;
		}
		if (k == 999)
			cout << "true" << endl;
	}
	cout << "I AM THE SPLIT INE~--------------------" << endl << endl;
	t2 = clock() * 1000 / CLOCKS_PER_SEC;
	cout << (t2 - t1) <<"ms cost" <<endl;

	for (int i = 0; i < 5; i++)
		cout << a[i] << " ";
	cin >> a[5];
}
*/
void sirt(int *a, int s, int e)
{
	if (s >= e)
		return;
	int refer = a[s];
	int i=s, j=e;
	while (i<j)
	{
		for (; j > i; j--)
		{
			if (a[j] < refer)break;
		}
		a[i] = a[j];
		for (; i < j; i++)
		{
			if (a[i] > refer)break;
		}
		a[j] = a[i];
	}
	a[i] = refer;
	sirt(a,s,i-1);
	sirt(a,j+1,e);
}

char* test(int a[],int length)
{
	if (a == nullptr)
	{
		return "null";
	}for (int i = 1; i < length; i += 1)
	{
		if (a[i] < a[i - 1])
		{
			return"false";
		}
	};
	return "true";
}


int test_int(int a[],int length)
{
	if (a == nullptr)
		return -1;
	for (int i = 1; i < length; i += 1)
		if (a[i - 1] > a[i])return 0;
	return 1;
}


int array_change(int *a, int *b , int length)
{
	if (a == nullptr || b == nullptr)
		return -1;
	for (int i = 0; i < length; i += 1)
	{
		b[i] = a[i];
	}
	return 1;
}

void array_equal(int *a ,int *b, int length)
{
	for (int j = 0; j < length; j += 1)
	{
		for (int i = 0; i < length; i += 1)
		{
			if (b[j] == a[i])
				break;
			if (i == 4)
			{
				cout << "changed!" << endl;
				return;
			}
		}
	}
}