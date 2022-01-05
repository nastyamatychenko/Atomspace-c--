#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <complex>
#include <utility>

using namespace std;

int get_value() { return 3; }
void mumble();


int main()
{
	//C++ supports two forms of variable initialization.
	{ 
	    //The first form is an explicit syntax using the assignment operator;
		int ival = 1024;
		string project = "Fnatasia 2000";
		cout << "The first form:\t" << ival << "\tproject\t:" << project << endl;

		//The second or 'implicit' form, the first value is placed within parenthses;
		int ivalImplicit(1024);
		string projectImplicit("Fantasia 2000");
		cout << "The second form:\t" << ivalImplicit << "\tprojectImplicit\t:" << projectImplicit << endl;
	}
	

	//An object can be initialized with an arbitrarily complre expression,
	//including the return value of a function.	
	{
		double price = 109.99,
			discount = 0.16;
		double sale_price(price*discount);
		string pet("wrinkles");
		int get_value();
		int val = get_value();
		unsigned abs_val = abs(val);
	}
	
	//POINTER TYPES
	{
		int ival = -1024, ival2 = 2048;
		int *pi = &ival;
		*pi = abs(*pi);// ival=abs(ival);
		*pi = *pi + 1;  //ival =ival+1;
		cout << "Ival after transformation:\t"<<ival;
        
		int i=0, j=0, k=0;
		int *res = &i;
		cout << "\n*res:\t" << *res << "res:\t" << res <<"\ti:\t"<<&i<< endl;
		*res = *res + 2;
		cout << "*res:\t" << *res << "res:\t" << res << endl;
		res = res + 2;

		int mass[10];
		int *iter = &mass[0];
		int *iter_end = &mass[10];
		while (iter != iter_end)
		{
			cout << "*iter:\t" << *iter << "\titer:\t" << iter << endl;
			++iter;
		}

	}

	//STRING TYPES
	{
		int len = 0;
		const char *st = "The expense of spirit\n";
		while (*st++) { ++len; }
		cout << "Length of the string:\t" << len;

		string st2;
		if (!st2.size()) { cout << "empty string"; }

		//Concatenation
		const char *pc = ", ";
		string s1("hello"),
			s2("world!");
		string s3 = s1 + pc + s2 + "\n";

		//Replacement
		//string st("Hello! My name is Nastya and I am trying to learn C++ language.");
		//int count = 0;
        //TODO:
		//while (*st++)
		//{
		//	if (*st == ' ')
		//	{
		//		st[count] = '(';
		//	}
		//	count++;
		//}
		

	}

	//const Qualifier
	{
		for (int i = 0; i < 512; i++)
		{
			if (i == 2) //Error i=2
			{
				cout << "Ok";
			}
		}
		//const double minWage = 9.60;
		//double *ptr = &minWage;
		//cout << ptr;
		//minWage is a const obkect, so it is guaranteed not be written over with a new value.
		//ptr is an ordinary pointer, and there is nothing to stop subsequently writing.

		const double *pc = 0;
		const double minWage = 9.60;
		pc = &minWage;
		cout << "\nPC:\t" << pc << endl;
		double dval = 3.14;
		pc = &dval;
		dval = 3.14;
		//*pc = 3.14; // error


		int errNumb = 0;
		int *const curErr = &errNumb;
		//we cannot assign curErr another address value, but we can modify the value curErr addresses.

		for (int i = 0; i < 5; i++)
		{
			if (*curErr)
			{
				cout << "curErr:\t" << *curErr << endl;
			}
			*curErr = i;
		}

		const double cu = 3.4;
		const double *const cu_ptr = &cu;
		//neithrr the value of the object addressed by cu_ptr nor the address itsellf can be changed
	}

	//REFERENCE TYPES allows for the indirect manipulation of an object in a manner similar to
	//the use of a pointer but without requiring use of pointer syntax.
	{
		//Example of references
		{
			int ival = 1024;
			int &refval = ival;
			int *pi = &ival;
			int *&ptrVal12 = pi;
		}
		{
			//defines two objets of type int
			int ival = 1024, ival2 = 2048;
			//defines one reference and one onject
			int &rval = ival, rval2 = ival2;
			//defines one object, one pointer,one rederence
			int ival3 = 1024, *pi = &ival3, &ri = ival3;
			//defines two refernces
			int &rval3 = ival3, &rval4 = ival2;
			cout <<"Hi"<< pi << "\n" << ri << endl;
			cout << rval3 << "\n" << rval4 << endl;
		}
		//A const reference can be initialized to an object of a different type as well as 
		//to nonaddressable values, such as literal constants.
		{
			double dval = 3.14159;
			// only constant refernces
			const int &ir = 1924;
			const double &ir2 = dval;
			const double &dr = dval + 1.0;
			cout << "dr:\t" << dr << "\tdval\t" << dval << endl;
		}
		{
			const int ival = 1024;
			const int *const &pi_ref = &ival;
		}
		//Two primary differences between a reference and pointer are that a reference must always refer to an object and that the assignment
		//of one reference with another changes the object being referenced and not the reference itself.Let's look at an example. When we
		//write
		{
			//const int &ri = 0;
			int temp = 13;
			//cout <<"H:\t"<< ri;
			const int &ri = temp;
			cout << "F:\t" << ri;
		}
	}

	//BOOL TYPE
	{
		bool found = false;
		string st="Hello world";
		for (int i = 0; i < st.length(); i++)
		{
			if (st[i] == 'o')
			{
				found = true; 
				break;
			}
		}
	}

	//ENUMERATION TYPE
	{
		enum open_modes {input=1,output,append};
		//An enumeration is defined with the enum keyword, an optional enumeration name, and a comma-separated list of enumerators
		//enclosed in braces.By default, the first enumerator is assigned the value 0. Each subsequent enumerator is assigned a value 1 greater
	    //than the value of the enumerator that immediately precedes it.
		enum Forms {shape,sphere,cylinder,polygon};
		//An object of enumeration type can be initialized and assigned only with another object of the same enumeration
		//type or with one of its set of enumerators.
		mumble();
	}
	

	//ARRAY TYPES
	{
		int *ok = new int[1,2,3,4,5,6];
		for (int i = 0; i < sizeof(ok); i++)
		{
			cout << ok[i];
		}
		char kh[] = "Hello world";
	}

	//Multidimensional Arrays
	{
		int ia[4][3] = { {0,1,2},{2,3,4},{5,6,7},{6,7,8} };	
	}

	//Relationship of Array and Pointer Types
	{
		int ia[9] = { 0,1,2,3,4,5,6,7,8 },
			*pbegin = ia,
			*pend = ia + 9;
		while (pbegin != ia + 9)
		{
			cout << *pbegin << endl;
			++pbegin;
		}
	}

	//Vector Container Type
	{
		vector<int> ivec(10);
		vector<int> vec(10, -1);
		//vec contains ten elements of type int each intitalized to -1
		int ia[9] = { 0,1,2,3,4,5,6,7,8 };
		vector<int> vec3(ia, ia + 6);
		//copies the 6 elements of ia into ivec
		for (vector<int>::iterator it = vec3.begin(); it != vec.end(); it++)
		{
			cout << *it << endl;
		}
	}

	//Complex Number Types
	{
		complex<double> purei(0, 7);
		cout << purei.imag() << endl;
		complex<double> conjugate[2] = 
		{
			complex<double>(2,3),
			complex<double>(2,-3)
		};
		cout<<conjugate->_Val;
	}

	//Tyoedef Names (mneminic synonym)
	{
		typedef double wages;
		typedef vector<int> vec_unt;
		vec_unt ve = { 1,2,3 };
	}


	//volatile Qualifier
	//The volatile qualifier is used in much the same way as is the const
	//qualifier — as an additional modifier to a type.
	{
		volatile int display_register;
		//An object is declared volatile when its value can possibly be changed in ways outside either the control or detection of the
		//compiler — for example, a variable updated by the system clock.
	}
	

	//The Pair Type
	{
		pair< string, string > author("James", "Joyce");
		typedef pair< string, string > Authors;
		Authors proust("marcel", "proust");
		Authors joyce("james", "joyce");
		Authors musil("robert", "musil");
	}


	return 0;
	
}

void mumble()
{
	enum Points {point2d=2,point2w,point3d,point3w};
	Points ptd3d = point3d;
}