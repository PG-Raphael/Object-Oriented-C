// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name   Seungmin Yun            Date                 Reason
/////////////////////////////////////////////////////////////////

#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H

#include "ErrorState.h"
#include "iProduct.h"
namespace AMA {
	const int max_sku_length = 7;
	const int max_unit_length = 10;//the units¡¯ descriptor for a product 
	const int max_name_length = 75; //user¡¯s name descriptor for a product length
	const int tax = 13;

	class Product : public iProduct {
		char c_ptype;
		char c_psku[max_sku_length + 1];
		char c_punit[max_unit_length + 1];
		char* c_name;
		int c_quantity;
		int c_nQuantity; //need quantity
		double c_price;
		bool c_taxable;
		
	protected:
		ErrorState c_error;
		void name(const char*);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double price() const;
		double cost() const;
		void message(const char*);
		bool isClear() const;
	public:
		Product(char = 'N');
		Product(const char*, const char*, const char*, int = 0, bool = true, double = 0.0, int = 0);
		Product(const Product&);
		Product& operator=(const Product&);
		~Product();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char*) const;
		double total_cost() const;

		bool empty() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		bool operator>(const iProduct&) const;
		int operator+=(int);
	};
	std::ostream& operator<<(std::ostream&, const iProduct&);
	std::istream& operator>>(std::istream&, iProduct&);
	double operator+=(double&, const iProduct&);
}
#endif