/*-----------------------------------------------------------------------
name : Seungmin Yun
student No. :010820132
section: IPC144SJJ
----------------------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Contact.h"

using namespace std;
using namespace sict;

//when an object is created, the value will be 0 or null;
Contact::Contact()
{
	c_name[0] = '\0';
	c_phoneNum = nullptr;
	c_numOfPhoneNumber = 0;
}
//copy the value from user inputs and store into the private members.
Contact::Contact(const char* name, long long* phoneNumber, int numOfPhoneNumber)
{
	long long check;
	int contry = 0;
	int area = 0;
	int pNumber = 0;
	//condition check, if name has values copy the data.
	if (name != nullptr && name[0] != '\0')
	{
		strncpy(c_name, name, 20);
		c_name[19] = '\0';
		c_phoneNum = new long long[numOfPhoneNumber];
		c_numOfPhoneNumber = numOfPhoneNumber;
		for (int j = 0; j < numOfPhoneNumber; j++)
		{
			check = phoneNumber[j];
			contry = check / 10000000000;// subsitute as ie10
			area = check / 10000000 % 1000;
			pNumber = check % 10000000;
			//checking the valid numbers, if it is true then store.
			if ((contry >= 1 && contry <= 99) && (area >= 100 && area <= 999) && (pNumber >= 1000000 && pNumber <= 9999999))
			{
				c_phoneNum[j] = phoneNumber[j];
			}
		}
	}
	else {
		c_name[0] = '\0';
		c_phoneNum = nullptr;
		c_numOfPhoneNumber = 0;
	}
}
//once objects is out of scope, this will be executed to delete dynamic memory
Contact::~Contact()
{
	delete[] c_phoneNum;
	c_phoneNum = nullptr;
}
//condition check which is no values
bool Contact::isEmpty() const
{
	return c_name[0] == '\0' ? true : false;
}
//when object has values, display the data
void Contact::display() const
{
	int countryCode;
	int areaCode;
	int phoneNumber;
	int PhoneNumber1;
	int PhoneNumber2;
	if (isEmpty()) {
		cout << "Empty contact!" << endl;
	}
	else {
		cout << c_name << endl;
		//store phone number into each section
		if (c_phoneNum != nullptr) {
			for (int i = 0; i < c_numOfPhoneNumber; i++) {

				countryCode = (c_phoneNum[i] / 10000000000);//subsitute as ie10
				areaCode = ((c_phoneNum[i] % 10000000000) / 10000000);
				phoneNumber = c_phoneNum[i] % 10000000;

				PhoneNumber1 = phoneNumber / 10000;
				PhoneNumber2 = phoneNumber % 10000;
				if (countryCode > 0 && countryCode < 13) {
					cout << "(+" << countryCode << ") " << areaCode << " " << PhoneNumber1 << "-";
					cout.width(4);
					cout.fill('0');
					cout << PhoneNumber2 << endl;
				}
			}
		}
	}
}
//copy the values to new object
Contact::Contact(const Contact& rhs) {
	if (!rhs.isEmpty()) {
		strncpy(c_name, rhs.c_name, 20);
		c_name[19] = '\0';
		c_numOfPhoneNumber = rhs.c_numOfPhoneNumber;

		if (c_numOfPhoneNumber > 0) {
			//memory allocation then store the value
			long long *tmp = new long long[c_numOfPhoneNumber];
			for (int i = 0; i < c_numOfPhoneNumber; i++) {
				tmp[i] = rhs.c_phoneNum[i];
			}
			c_phoneNum = tmp;
		}
		else {
			c_phoneNum = nullptr;
		}
	}
	else {
		c_name[0] = '\0';
		delete[] c_phoneNum;
		c_phoneNum = nullptr;
		c_numOfPhoneNumber = 0;
	}
}
//copy assignment operator for deep copying
Contact& Contact::operator=(const Contact& rhs) {
	//check for self-assignment
	if (this != &rhs) {
		if (c_phoneNum != nullptr) {
			delete[] c_phoneNum;
			c_phoneNum = nullptr;
		}
		//shallow copy 
		if(rhs.isEmpty()){
			c_name[0] = '\0';
			delete[] c_phoneNum;
			c_phoneNum = nullptr;
			c_numOfPhoneNumber = 0;
		}
		else {
			strncpy(c_name, rhs.c_name, 20);
			c_name[19] = '\0';
			c_numOfPhoneNumber = rhs.c_numOfPhoneNumber;
			c_phoneNum = new long long[c_numOfPhoneNumber];
			//deep copy from newly allocated memory
			for (int i = 0; i < c_numOfPhoneNumber; i++) {
				c_phoneNum[i] = rhs.c_phoneNum[i];
			}
		}
	}
	return *this;
}
//add the phone numbers into the object
Contact& Contact::operator+=(const long long phoneNum) {
	bool valid = isEmpty();
	long long *tmp;
	tmp = new long long[c_numOfPhoneNumber + 1];
	if (valid == false) {
		for (int i = 0; i < c_numOfPhoneNumber; i++) {
			tmp[i] = c_phoneNum[i];
		}
	}
	c_numOfPhoneNumber++;
	if (c_phoneNum != nullptr) {
		delete[] c_phoneNum;
	}
	c_phoneNum = new long long[c_numOfPhoneNumber];
	for (int i = 0; i < c_numOfPhoneNumber; i++) {
		c_phoneNum[i] = tmp[i];
	}
	c_phoneNum[c_numOfPhoneNumber - 1] = phoneNum;
	delete[] tmp;
	return *this;
}


