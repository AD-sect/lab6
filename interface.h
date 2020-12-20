#pragma once
#include "Graph.h"
#include "TestGraph.h"

void interface()
{
	int choice{ 0 };
	std::cout << "*** GRAPH ***" << std::endl;
	bool exit{ false };
	bool exit1{ false };
	while (!exit1)
	{
		int size(0);
		std::cout << " " << std::endl;
		std::cout << "Write the quontaties and the vertexes of a graph:" << std::endl
			<< " Quontaty of elements: ";

		std::cin >> size;
		int* vert = new int[size];
		std::cout << "The vertexes: ";
		for (int i(0); i < size; i++)
			std::cin >> vert[i];

		Graph<int> graph(size, vert);
		ArraySequence<int> paths;

		std::cout << "Write the paths for every vertexes: " << std::endl;
		for (int i(0); i < size; i++)
		{
			std::cout << vert[i] << ":" << "  " << "quontaty: ";
			int quont(0);
			int a(0);
			std::cin >> quont;
			std::cout << "   " << " Paths: ";
	
			for (int k(0); k < quont; k++)
			{
				std::cin >> a;
				graph.AddPath(vert[i], a);

			}
		}

		std::cout << "The adjacency list of a graph: " << std::endl;
		std::cout << "  " << std::endl;
		graph.Print();

		while (!exit)
		{
			int a(0);
			int b(0);
			std::cout << " Write the vertexes fo finding the shortest path:" << std::endl;
			std::cout << " " << std::endl;
			std::cout << "From: ";
			std::cin >> a;
			std::cout << "   " << "To: ";
			std::cin >> b;

			ArraySequence<int> path(graph.BFS(a, b));
			for (int i(0); i < path.GetLength(); i++)
			{
				if (i != path.GetLength() - 1)
					std::cout << path.Get(i) + 1 << " -> ";
				else
					std::cout << path.Get(i) + 1 << std::endl;
			}
			std::cout << std::endl;

			std::cout << "Choose thw option: " << std::endl 
				<< " " << std::endl
				<< " 1.Find another path " << std::endl 
				<< " 2. Change the graph" << std::endl 
				<< " 3. Exit" << std::endl;

			std::cin >> choice;
			if (choice == 1)
				exit = false;
			if (choice == 2)
				exit = true;
			if (choice == 3)
			{
				exit = true;
				exit1 = true;
			}
		}
	}



}
