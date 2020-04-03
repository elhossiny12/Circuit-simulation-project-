#include<string>
#ifndef NODE_H
#define NODE_H
using namespace std;

class Node 
{
	string Name;
	short Value;
public:
	Node();
	Node(string N);
	Node(string N, short V);
	void SetName(string N);
	string GetName();
	void Setvalue(short v);
	short GetValue();
	void PrintNode();



};
#endif