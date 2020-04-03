#include"Node.h" 
#include<iostream>
using namespace std;
Node::Node()
{
	Name = " ";
	Value = 0;

}
Node::Node(string N) 
{
	Name = N;
Value = 0;

}
Node::Node(string N,short v)
{
	Name = N;
	Value = v;

}
void Node::SetName(string N)
{
	Name = N;

}
string Node::GetName()
{
	return Name;


}
void Node::Setvalue(short v) 
{
	Value = v;
}
short Node::GetValue()
{
	return Value; 

}
void Node::PrintNode() 
{
	cout << Name << " " << Value << endl;

}
