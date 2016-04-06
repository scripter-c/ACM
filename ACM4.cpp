#include<iostream>
using namespace std;

void ballon_sort(int *a, int length)
{
	for (int i = 1; i < length; i++)
		for (int j = 0; j < length - i; j++)

		{
			if (a[j + 1] < a[j])
			{
				int k = a[j + 1];
				a[j + 1] = a[j];
				a[j] = k;
			}
		};
}

void ballonsort(int *a,int length)
{
	for (int j = 1; j < length; j++)
		for (int c = 0; c < length - j; c++)
		{
			if (a[c] > a[c + 1])
			{
				int k = a[c];
				a[c] = a[c + 1];
				a[c + 1] = k;
			}
		}
}

void main_2()
{
	int a[10] = {23,45,655,87,2,43,123453,65,6545,-33};
	int b[10];
	for (int i = 0; i < 10; i++)
		b[i] = a[i];
	ballon_sort(a,10);
	for (int i = 0; i < 10; i++)
	cout << a[i]<<" ";
	cout  <<endl;
	ballonsort(b, 10);
	for (int i = 0; i < 10; i++)
	cout << b[i]<<" ";
	cin >> a[0];
}
/*
if (a[length - j - 1] > a[length - j])
{
int c = a[length - j - 1];
a[length - j - 1] = a[length - j];
a[length - j] = c;
}
*/