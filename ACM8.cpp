#include<iostream>
#include<time.h>
#include<sys/timeb.h>
#include<ctime>
using namespace std;
class PrimerNumber
{
public:
	PrimerNumber();
	~PrimerNumber();
	bool IsPrimerNumber(int z);
	bool IsCheck();
	int Check(int z);
	void out();
private:
	void add(int z ,bool state);
	void StorageSort();
	int SerachStorage(int z);
	int** storage;
	int checknumer;
	bool check;
};

PrimerNumber::PrimerNumber()
{
	storage = new int*[100];
	for (int i = 0; i < 100; i++)
		storage[i] = new int[3];
	checknumer = 0;
}

PrimerNumber::~PrimerNumber()
{
	for (int i = 0; i < 100; i++)
		delete storage[i];
	delete storage;
}

bool inline PrimerNumber::IsPrimerNumber(int z)
{
	if (SerachStorage(z) > -1)
	{
		if (storage[SerachStorage(z)][1] == 1)return true;
		else return false;
	}
	if (z <= 2)
	{
		add(z,false);
		return false;
	}
	for (int i = 2; i <= z/2; i++)
	{
		if (z%i == 0) { add(z,false); return false; }
	}
	add(z,true);
	return true;
}

bool PrimerNumber::IsCheck()
{
	if (check)return true;
	else return false;
}

int PrimerNumber::Check(int z)
{
	for (int i = 0; i < checknumer; i++)
	{
		if (storage[i][0] == z)
			if (storage[i][1] == 1) { storage[i][2]++; return 1; }
		    else return 0;
	}
	return -1;
}

void PrimerNumber::out()
{
	for (int i = 0; i < 100; i++)
		cout << storage[i][0] << " " << storage[i][1] << " " << storage[i][2]<<endl;
}

int PrimerNumber::SerachStorage(int z)
{
	for (int i = 0; i < checknumer; i++)
		if (storage[i][0]==z)return i;
	return -1;
}

void PrimerNumber::add(int z,bool state)
{
	if(SerachStorage(z)>-1)
		storage[SerachStorage(z)][2]++;
	storage[checknumer][0]=z;
	if (state == true)storage[checknumer][1] = 1;
	else storage[checknumer][1] = 0;
	storage[checknumer][2] = 1;
	if (checknumer++ >= 99)checknumer = 0;
}

void PrimerNumber::StorageSort()
{
	for (int i=0;i<100;i++)
		for (i = 0; i < 100; i++)
		{
			if (storage[i+1][2]>storage[i][2]);
		}
}
/*
void main()
{
	PrimerNumber *p = new PrimerNumber;
	unsigned long t1= clock()*1000 / CLOCKS_PER_SEC;
	for (int i = 0;i<100000;i++)
	p->IsPrimerNumber(i);
	cout << (clock()*1000/CLOCKS_PER_SEC) - t1 << " time"<<endl;
	p->out();
	p->~PrimerNumber();
	cout << endl<<sizeof (p);
	int* a;
	cout << sizeof(a);
	int **c;
	cout << sizeof(c);
	_sleep(10000);
	system("pause");
}
*/