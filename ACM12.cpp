#include<iostream>
using namespace std;

int figure(int k)
{
	int i,j,n;
	for ( i = 0; i*i < k; i += 1);
	j = i;
	n = i*j;
	if (i*(j - 1) >= k)return 4 * i - 2;
	else return 4 * i;
}

//È¦µØÓÎÏ·
/*
void main()
{
	int k;
	while (cin >> k&& k>0  )
	{
		cout << figure(k)<<endl;
	}
}*/