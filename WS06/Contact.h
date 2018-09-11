/*-----------------------------------------------------------------------
name : Seungmin Yun
student No. :010820132
section: IPC144SJJ
----------------------------------------------------------------------*/
#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H
//making a name space
namespace sict {
	//declare class
	class Contact {
		//private members which are encapsulated
		char c_name[20];
		long long* c_phoneNum;
		int c_numOfPhoneNumber;

	public:
		//constructor to initiate values
		Contact();
		Contact(const char*, long long*, int);
		//copy constructor
		Contact(const Contact&);
		//copy assignment operators
		Contact& operator=(const Contact&);
		Contact& operator+=(long long);
		//destructor
		~Contact();
		//member functions
		bool isEmpty() const;
		void display() const;
	};
}

#endif