#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<class type>
class tree
{
public:
	bool isempty()const;
	void insert();
	struct treenodes
	{
		type data;
		tree* leftnode;
		tree* rigtnode;
	}treenode;
private:

};

template<class type>
void tree<type>::insert()
{
	treenode.data = 1;
}


void main()
{
	tree<int>  *c = new tree<int>();
	c->insert();
	delete c;
}