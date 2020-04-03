#pragma once
#include"Node.h"
class Gate
{
protected:
	Node*In1;
	Node*In2;
	Node*Out1;

public:
	void SetIn1(Node*);
	void SetIn2(Node*);
	void SetOut1(Node*);
	Node*GetIn1();
	Node*GetIn2();
	Node*GetOut1();
	virtual void CalcOut() = 0;
	Gate();
};

