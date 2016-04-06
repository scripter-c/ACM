	#include<iostream>
	using namespace std;
	extern void  enless_exist();
	template <class type>
	class tree
	{
	public:
		tree() { leftnode = nullptr; rightnode = nullptr; };
		void setnumber(int values) { data = values; }
		int number() { return data; }
		tree **leftnp() { return &leftnode; }
		tree **rightnp() { return &rightnode; }
		void setl(tree *t) { leftnode = t; }
		void setr(tree *t) { rightnode = t; }
		tree *leftn() { return leftnode; }
		tree *rightn() { return rightnode; }
	private:
		type data;
		tree* leftnode;
		tree* rightnode;
	};

	template <class type>
	void industry(tree<type> **t, int z)
	{
		if (z < 1)
		{
			*t = new tree<type>();
			(*t)->setnumber(0);
			return;
		}
		*t = new tree<type>;
		(*t)->setnumber(z);
		if (z == 0)
			z--;
		industry((**t).leftnp(), z - 1);
		industry((**t).rightnp(), z - 1);
	}

	template<class type>
	void viewtree(tree<type>*t)
	{
		if (t == nullptr)
			return;
		viewtree(t->leftn());
		cout << t->number() << " ";
		viewtree(t->rightn());
	}

	template<class type>
	void deltree(tree<type> *t)
	{
		if (t == nullptr)
			return;
		deltree(t->leftn());
		deltree(t->rightn());
		int n = t->number();
		tree<int> * a = t;
		delete t;
		cout << a << "." << n << "  ";
	}

	int* serach_tree_node(int *a, int k)
	{
		int s;
		int z = 0;
		int i = 1;
		while ((i) <= k)
		{
			z++;
			i *= 2;
		}
		if (z > 0)
			s = z - 1;
		else return a;
		int n = i / 2;
		n--;
		if ((k - n) % 2 == 0 || k == n)
			a[0] = 2;
		else a[0] = 1;
		int ss = (n + 1) / 2 + (k - n) / 2 - 1;
		serach_tree_node(a + 1, ss);
	}

	template<class type>
	tree<type>* serach_tree(tree<type> *a, int k)
	{
		int *c = new int[100];
		int *p = serach_tree_node(c, k);
		while (c != p)
		{
			if (a == nullptr)
				return nullptr;
			if (*c == 1)
				a = a->leftn();
			else a = a->rightn();
			p--;
		}
		delete c;
		return a;
	}

	template <class type>
	tree<type>* jumpn(tree<type> *a, int z)
	{
		return serach_tree(a, z);
	}
	/*
	void main()
	{
		int a[1000] = {0};
		tree<int> *c;
		industry<int>(&c,5);
		for (int z = 0; z < 1000; z++)
		{
			tree<int> *temporary = serach_tree<int>(c, z);
			if(temporary)
			cout << " " << temporary->number()<< "->" << z << "' ";
		}system("PAUSE");
	}
	*/
