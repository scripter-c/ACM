#include<iostream>
using namespace std;
template <class type>
class linklist
{
public:
	type data()
	{
		return datas;
	};
	linklist* next()
	{
		return nexts;
	};
	void setdata(type c)
	{
		datas = c;
	};
	void set_next_node(linklist *next)
	{
		nexts = next;
	};
	void trans_time()
	{
		int i = 0;
		linklist *a = this;
		while(a->next()!=nullptr && a->next()!=this)
		{
			a = a->next();
			i += 1;
		}
		a = this;
		for (int z = 0; z < i / 2; z += 1)
		{
			linklist *sign=this;
			for (int c = 0; c < i - z; c += 1)
				sign =sign->next();
			a = a->next();
			type temporary =sign->data();
			sign->setdata(a->data());
			a->setdata(temporary);
		}
	};

	void trans_space()
	{
		int i = 0;
		linklist *a = this;
		while (a->next() != nullptr && a->next() != this)
		{
			i++;
			a = a->next();
		}
		linklist **c = new linklist*[i];
		a = this;
		for (int site = 0; site < i; site += 1)
		{
			a = a->next();
			c[site] = a;
		}
		for (int site=0;site<i/2;site+=1)
		{
			type temporary = c[site]->data();
			c[site]->setdata(c[i-site-1]->data());
			c[i - site - 1]->setdata(temporary);
		}
	};


	void  trans_point_space()
	{
		int i = 0;
		linklist *a = this;
		while (a->next() != nullptr && a->next() != this)
		{
			i++;
			a = a->next();
		}
		linklist **c = new linklist*[i];
		a = this;
		for (int site = 0; site < i; site += 1)
		{
			a = a->next();
			c[site] = a;
		}
		this->set_next_node(c[i-1]);
		c[0]->set_next_node(c[i-1]->next());
		for (int site = i-1; site > 0 ; site -= 1)
		{
			c[site]->set_next_node(c[site-1]);
		}
	};

	void trans_point_recursion()
	{
		int i = 0;
		linklist *a = this;
		linklist *head = this;
		while (a->next() != nullptr && a->next() != this)
		{
			a = a->next();
			i+=1;
		}
		linklist *temporary = a->next();
		linklist *temporary_node = head->next();
		trans(head->next());
		this->set_next_node(a);
		temporary_node->set_next_node(temporary);
	}

private:
		type datas = 0;
		linklist* nexts = nullptr;
		void trans(linklist *c)
		{
			if (c->next() == this || c->next() == nullptr)
				return;
			linklist *refer = c->next();
			trans(refer);
			refer->set_next_node(c);
		};
};
/*
void main()
{
	srand(128989);
	linklist<int> a;
	linklist<int> *head = &a;
	linklist<int> *refer = &a;
	for (int i = 0; i < 100; i += 1)
	{
		linklist<int> *c = new linklist<int>() ;
		refer->set_next_node(c);
		c->setdata(rand());
		refer = c;
	}
	for (linklist<int> *go = head->next();go != nullptr && go !=head;go=go->next())
	{
		cout << go->data() <<" ";
	}
	head->trans_time();
	cout << endl<<endl;
	for (linklist<int> *go = head->next(); go != nullptr && go !=head; go = go->next())
	{
		cout << go->data() << " ";
	}
	head->trans_space();
	cout << endl << endl;
	for (linklist<int> *go = head->next(); go != nullptr && go != head; go = go->next())
	{
		cout << go->data() << " ";
	}
	head->trans_point_space();
	cout << endl << endl;
	for (linklist<int> *go = head->next(); go != nullptr && go != head; go = go->next())
	{
		cout << go->data() << " ";
	}
	head->trans_point_recursion();
	cout << endl << endl;
	for (linklist<int> *go = head->next(); go != nullptr && go != head; go = go->next())
	{
		cout << go->data() << " ";
	}
	system("pause");
}
*/