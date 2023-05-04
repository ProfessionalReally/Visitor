#pragma once

#include<iostream>

using namespace std;

class Patient;
class Paramedic;

class Visitor
{
public:
	virtual void visit(Patient*) = 0;
	virtual void visit(Paramedic*) = 0;
};

class CountVisitor : public Visitor
{
private:
	int NumPatient, NumParamedic;
public:
	CountVisitor() { NumPatient = NumParamedic = 0; }
	void visit(Patient*) { ++NumPatient; }
	void visit(Paramedic*) { ++NumParamedic; }
	void PrintNum()
	{
		cout << "Patient - " << NumPatient 
			<< ", Paramedic - " << NumParamedic << endl;
	}
};

class GetTypeVisitor : public Visitor
{
public:
	void visit(Patient*) { cout << "Patient" << endl; }
	void visit(Paramedic*) { cout << "Paramedic" << endl; }
};

class Users
{
public:
	virtual void accept(Visitor*) = 0;
};

class Patient : public Users
{
public:
	void accept(Visitor*);
	void PrintPatient() { cout << "Patient::PrintPatient\n"; }
};

class Paramedic : public Users
{
public:
	void accept(Visitor*);
	void PrintParamedic() { cout << "Paramedic::PrintParamedic\n"; }
};

void Patient::accept(Visitor* v)
{
	v->visit(this);
}

void Paramedic::accept(Visitor* v)
{
	v->visit(this);
}