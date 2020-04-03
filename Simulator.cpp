#include "Simulator.h"
#include"ANDGate.h"
#include"ORGate.h"
#include<fstream>
using namespace std;


Simulator::Simulator()
{
	
}


Simulator::~Simulator()
{
	int i;
	for (i = 0; i < NA.size(); i++)
		delete NA[i];
	for (i = 0; i < GA.size(); i++)
		delete GA[i];
}
int Simulator::GetNSize() {
	return NA.size();

}
int Simulator::GetGSize() {
	return GA.size();

}
Node* Simulator::FindNode(string N) 
{
	int i;
	for (i = 0; i < NA.size(); i++)
	{
		if (NA[i]->GetName() == N)
			return NA[i];

	}
	return NULL;
}

Node*Simulator::AddNode(string N) {
	Node*p = new Node(N);
	NA.push_back(p);
	return p;
}
Node*Simulator::FindOrAdd(string N) {

	Node*P = FindNode(N);
	if (P != NULL)
		return P;
	return AddNode(N);
}
Gate* Simulator::AddGate(string Type) {
	
	Gate*p=NULL;
	if (Type == "AND")
		p = new ANDGate();
	else if (Type == "OR")
		p = new ORGate();
	GA.push_back(p);
	return p;


}
void Simulator::Sim() {
	int i;
	for (int i = 0; i < GA.size(); i++) {
		GA[i]->CalcOut();
	}
}
void Simulator::PrintAllNodes() {
	for (int i = 0; i < NA.size(); i++)
		NA[i]->PrintNode();

}

void Simulator::Load(string FileName) {
	ifstream f1;
	f1.open(FileName);
	while (!f1.eof())
	{
		string s;
		f1 >> s;
		if (s == "SET")
		{
			string N;
			short V;
			f1 >> N >> V;
			FindOrAdd(N)->Setvalue(V);
		}
		else if (s == "OUT")
		{
			string N;
			f1 >> N;
			if (N == "ALL") PrintAllNodes();
			else
				FindOrAdd(N)->PrintNode();

		}
		else if (s == "SIM")
			Sim();
		else
		{
			Gate*g = AddGate(s);
			string N1, N2, N3;
			f1 >> N1 >> N2 >> N3;
			 g->SetIn1(FindOrAdd(N1));
			 g->SetIn2(FindOrAdd(N1));
			 g->SetOut1(FindOrAdd(N1));

		}
	}
	f1.close();
}
