#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>
#define fors(c) for( int i = 0 ; i < c ; i++ )
using namespace std;

class quicksort
{
public:
	void quick_sort(int a[], int len);
	void quick_sort2(int a[], int sta, int end);
	int seek(int a[], int i);
};

void quicksort::quick_sort(int a[], int len)
{
	if (len <= 1)return;
	int compare = a[0];
	int sta = 0;
	int end = len-1;
	for (; sta < end;)
	{
		while (end > sta && a[end] >= compare)end--;
		a[sta] = a[end];
		while (sta < end&&a[sta] <= compare)sta++;
		a[end] = a[sta];
	}
	a[end] = compare;
	quick_sort(a, end);
	quick_sort(a + end + 1,len-(end+1));
}

void quicksort::quick_sort2(int *a, int sta, int end)
{
	if (sta >= end)return;
	int i = sta;
	int j = end;
	int cmp = a[i];
	while (i < j)
	{
		while ((a[j] >= cmp) && (i < j))
		{
			j--;
		}
		a[i] = a[j];
		while ((a[i] <= cmp) && (i < j))
		{
			i++;
		}
		a[j] = a[i];
	}

	a[i] = cmp;

	quick_sort2(a, sta, i - 1);

	quick_sort2(a, i + 1, end);
}

int quicksort::seek(int a[], int i)
{
	int rate = 1;
	int dero = 0;
	for (int i=0;rate<i;i++)
	{
		for (int c=0;c<i;c++)
		{
			for (int j = 0; j < i; j++)dero += a[j];
			if (dero >= a[i])
				rate++;
			if (rate == i)return dero;
			dero = 0;
		}
		rate++;
	}
	return a[i];
}


