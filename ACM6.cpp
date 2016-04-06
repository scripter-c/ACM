#include<iostream>
using namespace std;

class node
{
public:
	node() { ; };
	node* next();
	node* front();
	int datas();
	int check();
	int data;
	node *fronts;
	node *nexts;
};
node* node::front()
{
	return fronts;
}
node* node::next()
{
	return nexts;
}
int node::datas()
{
	return data;
}
int node::check()
{
	node *a=this;
	node *b=this;
	for (int i = 1;; i++)
	{
		a = a->next();
		if (i % 2 == 0)
			b = b->next();
		if (a == nullptr)return 0;
		if (a==b)return 1;
	}
}
/*
void main()
{
	node *a=new node;
	node *z = a;
	for (int i = 1; i < 100; i++)
	{
		node *c = new node();
		c->data = i;
		z->nexts = c;
		c->fronts=z;
		z = c;
	}
	z->nexts = a;

	z = a;
	for (int i = 0; i < 100; i++)
	{
		cout << z->data << " ";
		z = z->next();
	}
	cout << a->check();
	system("pause");
}*/