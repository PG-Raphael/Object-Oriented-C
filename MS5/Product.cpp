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

#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include "Product.h"


using namespace std;
namespace AMA {
	void Product::name(const char* name) {
		c_name = new char[strlen(name) + 1];
		strncpy(c_name, name, strlen(name) + 1);
		c_name[strlen(name) + 1] = '\0';
	}

	const char* Product::name() const {
		return c_name[0] == '\0' ? nullptr : c_name;
	}

	const char* Product::sku() const {
		return c_psku;
	}

	const char* Product::unit() const {
		return c_punit;
	}

	bool Product::taxed() const {
		return c_taxable;
	}

	double Product::price() const {
		return c_price;
	}

	double Product::cost() const {
		return c_price * tax / 100 + c_price;
	}

	void Product::message(const char* errMsg) {
		c_error.message(errMsg);
	}

	bool Product::isClear() const {
		return c_error.isClear();
	}

	Product::Product(char type) {
		c_ptype = type;
		strcpy(c_psku, "");
		strcpy(c_punit, "");
		c_name = nullptr;
		c_nQuantity = 0;
		c_quantity = 0;
		c_price = 0.0;
		c_taxable = true;
		c_error.clear();
	}

	bool Product::empty() const {
		bool check = false;
		if (c_psku[0] == '\0') {
			check = true;
		}
		return check;
	}

	Product::Product(const char* sku, const char* pname, const char* unit, int qty, bool tax, double price, int nQty) {
		c_ptype = 'N';
		strcpy(c_psku, sku);
		strcpy(c_punit, unit);
		c_name = nullptr;
		name(pname);
		if (nQty != 0 && tax != false && price != 0.0 && qty != 0) {
			c_nQuantity = nQty;
			c_quantity = qty;
			c_price = price;
			c_taxable = tax;
		}
		else {
			c_nQuantity = 0;
			c_quantity = 0;
			c_price = 0.0;
			c_taxable = true;
		}

	}

	Product::Product(const Product& p) {
		*this = p;
	}

	Product& Product::operator=(const Product& p) {
		if (this != &p) {
			c_ptype = p.c_ptype;
			strcpy(c_psku, p.c_psku);
			strcpy(c_punit, p.c_punit);
			name(p.c_name);
			c_nQuantity = p.c_nQuantity;
			c_quantity = p.c_quantity;
			c_price = p.c_price;
			c_taxable = p.c_taxable;
		}
		return *this;
	}

	Product::~Product() {
		if (c_name != nullptr) {
			c_name[0] = '\0';
		}
	}

	std::fstream& Product::store(std::fstream& file, bool newLine) const {
		if (file.is_open()) {
			file << c_ptype << ',' << c_psku << ',' << c_name << ','
				<< c_punit << ',' << c_taxable << ',' << c_price << ',' << c_quantity << ',' << c_nQuantity;
		}
		if (newLine) {
			file << endl;
		}
		return file;
	}

	std::fstream& Product::load(std::fstream& file) {
		Product tmp;
		if (file.is_open()) {
			char* tmpchar = new char[max_name_length + 1];
			file.getline(tmp.c_psku, max_sku_length, ',');
			tmp.c_psku[strlen(tmp.c_psku)] = '\0';

			file.getline(tmpchar, max_name_length, ',');
			tmpchar[max_name_length] = '\0';
			tmp.name(tmpchar);
			delete[] tmpchar;

			file.getline(tmp.c_punit, max_unit_length, ',');
			tmp.c_punit[strlen(tmp.c_punit)] = '\0';

			file >> tmp.c_taxable;
			file.ignore();
			file >> tmp.c_price;
			file.ignore();
			file >> tmp.c_quantity;
			file.ignore();
			file >> tmp.c_nQuantity;
			file.ignore();
		}
		*this = tmp;
		return file;
	}

	std::ostream& Product::write(std::ostream& os, bool linear) const {
		if (!(c_error.isClear()))
		{
			os << c_error.message();
		}
		else {
			if (!isEmpty()) {
				if (linear) {
					os << setw(max_sku_length) << left << setfill(' ') << c_psku << "|" <<
						setw(20) << left << c_name << "|" <<
						setw(7) << right << setprecision(2) << fixed;
					if (c_taxable) {
						cout << cost();
					}
					else {
						cout << c_price;
					}

					cout << "|" << setw(4) << right << c_quantity << "|"
						<< setw(10) << left << c_punit << "|"
						<< setw(4) << right << c_nQuantity << "|";
				}

				else {
					os << " Sku: " << c_psku << endl;
					os << " Name (no spaces): " << c_name << endl
						<< " Price: " << c_price << endl
						<< " Price after tax: ";
					if (c_taxable) {
						os << cost() << endl;
					}

					else {
						os << "N/A" << endl;
					}
					os << " Quantity on Hand: " << c_quantity << " " << c_punit << endl;
					os << " Quantity needed: " << c_nQuantity;
				}
			}
		}
		return os;
	}

	std::istream& Product::read(std::istream& is) {
		char option;
		char* tmp = new char[max_name_length + 1];
		c_error.clear();
		cout << " Sku: ";
		is >> c_psku;
		cout << " Name (no spaces): ";
		is >> tmp;
		name(tmp); // to save input name into private pointer member
		delete[] tmp;
		cout << " Unit: ";
		is >> c_punit;
		cout << " Taxed? (y/n): ";
		is >> option;
		if (option == 'y' || option == 'Y') {
			c_taxable = true;
		}
		else if (option == 'n' || option == 'N') {
			c_taxable = false;
		}
		else {
			c_error.message("Only (Y)es or (N)o are acceptable");
			is.istream::setstate(std::ios::failbit);
			return is;
		}
		cout << " Price: ";
		is >> c_price;
		if (is.fail()) {
			c_error.message("Invalid Price Entry");
			is.istream::setstate(std::ios::failbit);
			return is;
		}
		cout << " Quantity on hand: ";
		is >> c_quantity;
		if (is.fail()) {
			c_error.message("Invalid Quantity Entry");
			is.istream::setstate(std::ios::failbit);
			return is;
		}
		cout << " Quantity needed: ";
		is >> c_nQuantity;
		if (is.fail()) {
			c_error.message("Invalid Quantity Needed Entry");
			is.istream::setstate(std::ios::failbit);
			return is;
		}
		is.ignore();
		return is;
	}

	bool Product::operator==(const char* sku) const {
		return strcmp(this->c_psku, sku) == 0;
	}

	double Product::total_cost() const {
		double total = 0;
		total = c_price * c_quantity;
		total += total * 0.13;
		return total;
	}

	void Product::quantity(int qty) {
		c_quantity = qty;
	}

	bool Product::isEmpty() const {
		return (c_psku[0] == '\0' && c_name == nullptr &&
			c_punit[0] == '\0' && c_quantity == 0 &&
			c_nQuantity == 0 && c_price == 0 && c_taxable == true);
	}

	int Product::qtyNeeded() const {
		return c_nQuantity;
	}

	int Product::quantity() const {
		return c_quantity;
	}

	bool Product::operator>(const char* c) const {
		return c_psku > c;
	}

	bool Product::operator>(const iProduct& p) const {
		return c_name > p.name();
	}

	int Product::operator+=(int plus) {
		return plus > 0 ? c_quantity + plus : c_quantity;
	}

	std::ostream& operator<<(std::ostream& os, const iProduct& p) {
		p.write(os, true);
		return os;
	}

	std::istream& operator>>(std::istream& is, iProduct& p) {
		p.read(is);
		return is;
	}

	double operator+=(double& price, const iProduct& p) {
		price += p.total_cost();
		return price;
	}
};

