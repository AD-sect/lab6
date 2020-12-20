#pragma once
#include "LinkedList.h"
#include "ArraySequence.h"
#include "LinkedListSequence.h"

//граф по таблице смежности
template <typename T>
class Graph : public LinkedList<T>
{
private:
	LinkedListSequence<T>** graph{ nullptr };
	int count;
public:

	Graph(int count)
	{
		this->graph= new LinkedListSequence<T>*[count];
		for (int i(0); i < count; i++)
			this->graph[i] = new LinkedListSequence<T>;

		this->count = count;
	}

	Graph(int count, T* vert)//массив с вершинами
	{
		this->graph = new LinkedListSequence<T>*[count];
		for (int i(0); i < count; i++)
		{
			this->graph[i] = new LinkedListSequence<T>;
			this->graph[i]->Append(vert[i]);
		}
		this->count = count;
	}

	~Graph()
	{
		for (int i(0); i < count; i++)
		{
			delete this->graph[i];
			this->graph[i] = nullptr;
		}
		delete this->graph;
		this->graph = nullptr;

	}

	LinkedListSequence<T>* GetGraph( int vert)
	{
		int i(0);
		while (this->graph[i]->GetFirst() != vert)
			i++;
		return this->graph[i];
	}

	int GetCount()
	{
		return this->count;
	}

	int GetCountPaths()
	{
		int count(0);
		for (int i(0); i < this->count; i++)
			count += this->graph[i].GetLength();
		return count - this->count;
	}

	bool CheckVert(T vert1, T vert2)
	{
		int i(SearchVert(vert1));
		bool check(true);

		if (i == -1)
			return false;

		for (int k(0); k < this->graph[i].GetLength(); k++)
			if (this->graph[i].Get(k) == vert2)
				check = true;
		return check;




	}

	void SetPaths(T vert, T* paths, int size)
	{
		for (int i(0); i < size; i++)
			AddPath(vert, paths[i]);
	}

	void AddPath(T vert, T element)
	{
		for (int i(0); i < count; i++)
			if (this->graph[i]->GetFirst() == vert)
				this->graph[i]->Prepend(element);
	}

	void Print()
	{
		std::cout << " " << std::endl;
		std::cout << " Vertex " << "| " <<"Paths" << std::endl;
		for (int i(0); i < count; i++)
		{
			std::cout << i + 1 << ":";
			this->graph[i]->Print();
			std::cout << " " << std::endl;
		}
	}

	int SearchVert(T vert)
	{
		int i(0);
		while (this->graph[i]->GetFirst() != vert)
			i++;
		if (i == this->count + 1)
			return -1;
		else
			return i;
	}

	ArraySequence<int>* BFS(T vertFrom, T vertTo)
	{
		int i(0);
		while (this->graph[i]->GetFirst() != vertFrom)
			i++;

		int k(0);
		while (this->graph[k]-> GetFirst() != vertTo)
			k++;

		LinkedListSequence<T>* queue = new LinkedListSequence<T>;
		queue->Append(i);
		bool* used = new bool[this->count];
		int* dist = new int[this->count];
		int* pred = new int[this->count];

		for (int j(0); j < count; j++)
		{
			used[j] = false;
			dist[j] = 0;
			pred[i] = -1;
		}

		used[i] = true;
		dist[i] = 0;

		while (queue->Empty()) 
		{
			int v(queue->GetFirst());
			queue->DeleteFirst();
	
			for (int i(1); i < graph[v]->GetLength(); ++i)
			{
				int j(0);
				int el = graph[v]->Get(i);
				while (this->graph[j]->GetFirst() != el)
					j++;

				if (!used[j])
				{
					used[j] = true;
					queue->Append(j);
					dist[j] = dist[v] + 1;
					pred[j] = v;
				}
			}
		}

		ArraySequence<int>* path = new ArraySequence<int>[count];

		if (!used[k])
		{
			path->Append(-1);
			return path;
		}

		int cur(k);         
		path->Prepend(cur);

		while (pred[cur] != -1) 
		{   
			cur = pred[cur];        
			path->Prepend(cur);    
		}
		ArraySequence<int>* path1 = new ArraySequence<int>[count];
		for (int i(0); i < path->GetLength(); i++)
			path1->Append(path->Get(i));

		return path1;
	}
	




};

