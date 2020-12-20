#pragma once
#include "Graph.h"
#include <assert.h>

void test_SetPaths( Graph<int>* g, int vert,  int newSize, int* checkEl)
{
	assert(g->GetGraph(vert)->GetLength() == newSize);

	for (int i(1); i < newSize; i++)
		assert(g->GetGraph(vert)->Get(i) == checkEl[i - 1]);
}
		
void test_BFS(Graph<int>* g, int vertFrom, int vertTo, int* checkMas)
{
	ArraySequence<int> mas(g->BFS(vertFrom, vertTo));
	for (int i(0); i < mas.GetLength(); i++)
	{
		std::cout << mas.Get(i) << "  " << checkMas[i] << std::endl;
		assert(mas.Get(i) == checkMas[i]);
	}
}

void test_AddPath(Graph<int>* g, int vert, int path)
{
	g->AddPath(vert, path);
	assert(g->GetGraph(vert)->GetLast() == path);
}

void test_Graph()
{
	int mas2_1[1]{ 2};
	int mas2_2[1]{ 1 };
	int masVert2[2]{ 1,2 };
	Graph<int>* g2_2 = new Graph<int>(2, masVert2);

	int masVert3[3]{ 1, 2, 3 };
	Graph<int>* g3_0 = new Graph<int>(3, masVert3);

	int masVert6[6]{ 1, 2, 3, 4, 5, 6 };
	int mas6_1[3]{ 2, 3, 6 };
	int mas6_2[2]{ 1, 3 };
	int mas6_3[5]{ 1, 2, 4, 5, 6 };
	int mas6_4[3]{ 3, 5, 6 };
	int mas6_5[3]{ 3, 4, 6 };
	int mas6_6[4]{ 1, 3, 4, 5 };
	Graph<int>* g6_5 = new Graph<int>(6, masVert6);
	
	g2_2->SetPaths(1, mas2_1, 1);
	test_SetPaths(g2_2, 1, 2, mas2_1);
	
	g2_2->SetPaths(2, mas2_2, 1);
	test_SetPaths(g2_2, 2, 2, mas2_2);

	g6_5->SetPaths(1, mas6_1, 3);
	test_SetPaths(g6_5, 1, 4, mas6_1);

	g6_5->SetPaths(2, mas6_2, 2);
	test_SetPaths(g6_5, 2, 3, mas6_2);

	g6_5->SetPaths(3, mas6_3, 5);
	test_SetPaths(g6_5, 3, 6, mas6_3);

	g6_5->SetPaths(4, mas6_4, 3);
	test_SetPaths(g6_5, 4, 4, mas6_4);

	g6_5->SetPaths(5, mas6_5, 3);
	test_SetPaths(g6_5, 5, 4, mas6_5);

	g6_5->SetPaths(6, mas6_6, 4);
	test_SetPaths(g6_5, 6, 5, mas6_6);

	int mas_c_12[2]{ 0, 1 }; 
	int mas_c_21[2]{ 1, 0 };
	test_BFS(g2_2, 1, 2, mas_c_12);
	test_BFS(g2_2, 2, 1, mas_c_21);

	int mas_c_3[1]{ -1 };
	test_BFS(g3_0, 1, 2, mas_c_3);
	test_BFS(g3_0, 1, 3, mas_c_3);
	test_BFS(g3_0, 3, 2, mas_c_3);
	test_BFS(g3_0, 2, 1, mas_c_3);

	int mas_c6_15[3]{ 0, 5, 4};
	int mas_c6_14[3]{ 0, 5, 3 };
	int mas_c6_16[2]{ 0, 5 };
	int mas_c6_25[3]{ 1, 2, 4 };
	test_BFS(g6_5, 1, 5, mas_c6_15);
	test_BFS(g6_5, 1, 4, mas_c6_14);
	test_BFS(g6_5, 1, 6, mas_c6_16);
	test_BFS(g6_5, 2, 5, mas_c6_25);











}
