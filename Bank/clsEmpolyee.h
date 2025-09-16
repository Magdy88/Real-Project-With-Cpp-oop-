#pragma once
#include<iostream>
#include "clsPerson.h";

using namespace std;





class clsEmpolyee : public clsPerson
{
private:
	string _Title;
	string _Department;
	float _Salary;


public:

	clsEmpolyee(int ID, string FristName, string LastName, string Email, string Phone,
		string Title, string Department, float Salary) :
		clsPerson(ID, FristName, LastName, Email, Phone)
	{
		_Title = Title;
		_Department = Department;
		_Salary = Salary;
	}

	void SetTitle(string Title)
	{
		_Title = Title;
	}

	string Title()
	{
		return _Title;
	}

	void SetDepartment(string Department)
	{
		_Department = Department;
	}

	string Department()
	{
		return _Department;
	}

	void SetSalary(float salary)
	{
		_Salary = salary;
	}

	float Salary()
	{
		return _Salary;
	}

	// Function Overriding  (Destroy Main fnction print())
	void Print()
	{
		//clsPerson::Print();
		cout << "\n Info:\n ";
		cout << "____________________\n";
		cout << " ID         : " << ID() << endl;
		cout << " Frist Name : " << FristName() << endl;
		cout << " Last Name  : " << LastName() << endl;
		cout << " Full Name  : " << FullName() << endl;
		cout << " Email      : " << Email() << endl;
		cout << " Phone      : " << Phone() << endl;
		cout << " Title      : " << _Title << endl;
		cout << " Department : " << _Department << endl;
		cout << " Salary     : " << _Salary << endl;
		cout << "____________________\n";



	}
};