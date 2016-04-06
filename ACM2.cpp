#include<iostream>
#include<string>
#define fors(c) for(int i=0;i<c;i++)
using namespace std;

class richnumber
{
public:
	void get();
	void multipliers();
	void out();
	richnumber operator *(richnumber a);
private:
	int a[101] = {0};
	int site;
	int multiplier=0;
	int out_site;
};


void richnumber::get()
{
again:
	site = -1;
	string number;
	cin >> number;
	fors(number.size())
		if (number[i] == '.')
			site = i;
	if (site == -1)
	{
		cout << "input false!"<<endl<<"try again!"<<endl;
		goto again;
	}
	out_site=number.size()-site-1;
	fors(number.size())
	{
		if (i == site);
		else 
		{
			multiplier += number[i]-48;
			multiplier *= 10;
		}
	}
}
void richnumber::multipliers()
{
	int k;
	cout << "´ÎÊý£º";
	cin >> k;
	a[99] = 1;

	fors(k)
	{
		for (int i = 1; i <= 100; i++)
			a[i] *= multiplier;
		for (int i = 100;i>0;i--)
			while (a[i]>=10)
			{
				a[i]-=10;
				a[i - 1]++;
			}
	}
	out_site *= k;
}

void richnumber::out()
{
	int i = 0;
	int j = 100;
	while (a[++i] == 0);
	while (a[--j] != 0);
	for (int k = i; k <= j; k++)
		if(k!= ( (j-i) + 1 ) - out_site )
		cout << a[k];
		else cout << "." << a[k];
}

void main2()
{
	richnumber mel;
	mel. get();
	mel.multipliers();
	mel.out();
}