#include<iostream>
#include<string>
using namespace std;
#include<ctime>

class vector
{
public:
	vector() { x = 0; y = 0; };
	vector(int x, int y) { this->x = x; this->y = y; };
	vector(vector *a) {};
	double value() { int v = x*x + y*y; for (double value = 0;; value += 0.01) { if (value*value >= v)return value; } };
	double angle_sin() { double v = x*x + y*y; v = (x*x) / v; for (double c = 0;; c += 0.01)if (c*c >=v)return c; };
	double angle_cos() { double v = x*x + y*y; v = (y*y) / v; for (double c = 0;; c += 0.01) if (c*c > v)if (x > 0)return c; else return -1 * c; }
	double angle_tan() { return (double)x / (double)y; };
	int test() { for (int i = 0;i<100;i+=1)if (i >= 100) return i; }
	//template<class ctype>

	friend ostream & operator <<(ostream & os, vector &vc) { cout << vc.x; return os; };
	friend istream & operator >>(istream & os, vector &vc) { return os; };
	void draw()
	{
		int _x=1;
		int _y=1;
		int x1 = 50;
		int y1 = 20;
		if (angle_tan() > 1)
		{
			int count1;
			x1/=angle_tan();
			for (int i = 1;; i += 1)
			{
				count1 = x1 - 50 / i;
				if (count1 <= 1)
					if ((-1 * count1) < (x1 - (50 / (i - 1))))
					{
						_x = -1 * count1;
						break;
					}
					else
					{
						_x = (x1 - (50 / (i - 1)));
						break;
					}
			}
		}
		else
		{
			y1 *= angle_tan();
			int count1;
			for (int i = 1;; i += 1)
			{
				count1 = y1 - 20 / i;
				if (count1 <= 1 )
					if ((-1 * count1) < (y1 - (20 / (i - 1))))
					{
						_y = -1 * count1;
						break;
					}
					else
					{
						_y = (x1 - (20 / (i - 1)));
						break;
					}
			}
		}
		
		for (int i = 0; i < 22; i += 1, cout << endl)
		{
			for (int j = 0; j < 52; j += 1)
			{
				if ((j == x1 || i == 0 || i == 21 || j == 0 || j == 51) && y1 == j&&x1 == i)
				{
					cout << "*";
				}
				else cout << " ";
			}
		}
	}

private:
	int x;
	int y;
};

vector than(vector a, vector b)
{
	if (a.value() >= b.value())
		return a;
	else return b;
}
/*
void main()
{
	vector a=new vector;
	int c;
	cout << a;
	cin >> a;
	system("pause");
	vector b(50,100);
	vector z=than(a, b);
	system("pause");
	cout<<z.test()<<endl;
	cout << a.angle_cos()<<endl;
	cout << a.angle_sin()<<endl;
	cout << a.angle_tan()<<endl;
	cout << z.angle_cos() << endl;
	z.draw();

	cout<<z.test();
	system("pause");

	long c1 = clock();
	for (int i = 0; i < 10000; i += 1)
		cout << endl;
	long c2 = clock();
	c1 = c2 - c1;
	for (int i = 0; i < 10000; i += 1)
		cout << "\n";
	c2 = clock() - c2;
	system("pause");
}
*/