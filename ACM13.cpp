#include<iostream>
using namespace std;
/*规划最优购买问题
void main()
{
	int num, n;
	int a[10][3];
	int i = 0;
	int j = -1;
	cin >> num >> n;
	while (cin >> a[j++][i])
	{
		i = 0;
		while (cin >> a[j][i++] && i< 3);
		if (j == 9)
			break;
	}
	
	int data[10][2];
	int length=0;
	for (int z = 0; z < j; z += 1)
	{
		if (a[z][2] == 0)
		{
			data[length][0] = a[z][0] * a[z][1];
			data[length++][1] = a[z][3];
		}
	}


	int data_add[10][2];
	int length_add=0;
	for (int z = 0; z < j; z++)
	{
		if (a[z][2] != 0)
			data_add[length_add][0] = a[z][0] * a[z][1] + a[a[z][2]][0] * a[a[z][2]][1] / 2;
		data_add[length_add++][1] = a[z][2];
	}

	for (int z=0;z<10;z+=1)
	{
	}
}

*/



