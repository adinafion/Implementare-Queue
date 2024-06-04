#include <iostream>
#include <fstream>

typedef std::pair<std::string, int> Persoana;

struct node
{
	Persoana info;
	node* next;
};

struct Queue
{
	node* first = nullptr, * last = nullptr;
	int nr_elem;

	void push(Persoana elem)
	{
		node* nod_nou = new node;
		nod_nou->info = elem;
		nod_nou->next = nullptr;
		if (last == nullptr)
		{
			first = nod_nou;
		}
		else
		{
			last->next = nod_nou;
		}
		last = nod_nou;
	}

	void pop()
	{
		node* nod_nou = new node;
		nod_nou = first;
		if (first == last)
		{
			first = nullptr;
			last = nullptr;
		}
		else
		{
			first = first->next;
		}
		delete nod_nou;
	}

	node* front()
	{
		return first;
	}

	node* back()
	{
		return last;
	}

	bool empty()
	{
		return last == nullptr;
	}

	void clear()
	{
		for (int i = 0; i < nr_elem; i++)
			pop();
	}

	int size()
	{
		return nr_elem;
	}

};

int main()
{
	std::ifstream fin("date.in");
	if (!fin)
	{
		std::cerr << "Eroare la deschiderea fisierului";
		return -1;
	}

	Queue C;
	int t, t1, t2, n, durata;
	std::string nume;

	fin >> t >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> nume >> durata;
		Persoana pers = { nume, durata };
		C.push(pers);
	}
	C.nr_elem = n;
	t1 = t * 60;
	t2 = t1;

	auto it = C.first;
	while (t1 - (it->info.second) >= 0)
	{
		t1 = t1 - (it->info.second);
		C.pop();
		//C.nr_elem--;
		it = C.first;
	}

	std::ofstream fout("date.out");

	if (C.empty())
		fout << "Toti elevii au fost examinati in prima zi.\n";
	else
		while (it != nullptr)
		{
			fout << it->info.first << " " << it->info.second << '\n';
			it = it->next;
		}

	fin.close();
	fout.close();
	return 0;
}
