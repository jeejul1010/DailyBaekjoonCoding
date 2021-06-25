#pragma once
#include <iostream>
#include <vector>
using namespace std;

typedef struct nodeR
{
	int id;
	bool visited;
	vector<int> adjacent;

	nodeR()
	{
		id = 0;
		visited = false;
	}
}nodeR;

typedef nodeR* nodePtr;
class GraphA
{
private:
	int v;
	nodePtr nodes;
public:
	GraphA(int v);
	~GraphA();
	void insertEdge(int v1, int v2);


};

