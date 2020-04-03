#pragma once
#include"Gate.h"
#include<vector>

class Simulator
{
	vector<Gate*>GA;
	vector<Node*>NA;

	
public:
	Simulator();
	~Simulator();
	int GetNSize();
	int GetGSize();
	Node* FindNode(string N);
	Node* AddNode(string N);
	Node* FindOrAdd(string N);
	Gate* AddGate(string Type);
	void Sim();
	void Load(string FileName);
	void PrintAllNodes();

};

