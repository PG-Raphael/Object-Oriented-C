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
#include "Perishable.h"
#include "Product.h"
#include "Date.h"

namespace AMA {
	Perishable::Perishable() : Product('P')
	{
		c_expiry = Date();
	}

	std::fstream& Perishable::store(std::fstream& file, bool newLine) const
	{
		Product::store(file, false);
		file << "," << c_expiry;
		if (newLine)
		{
			file << '\n';
		}
		return file;
	}

	std::fstream & Perishable::load(std::fstream & file) {
		Product::load(file);
		c_expiry.read(file);
		file.ignore();
		return file;
	}

	std::ostream & Perishable::write(std::ostream & os, bool linear) const {
		Product::write(os, linear);
		if (isClear() && !isEmpty()) { //checking value is not empty and no error
			if (linear) {
				c_expiry.write(os);
			}
			else {
				os << endl << " Expiry date: ";
				c_expiry.write(os);
			}
		}
		return os;
	}

	std::istream& Perishable::read(std::istream& is) {
		Product::read(is);
		if(!is.fail()) { 
			cout << " Expiry date (YYYY/MM/DD): ";
			Date tmp;
			tmp.read(is);
			if (tmp.bad()) {
				is.istream::setstate(std::ios::failbit);
				if (tmp.errCode() == CIN_FAILED) {
					Product::message("Invalid Date Entry");
				}
				else if (tmp.errCode() == YEAR_ERROR) {
					Product::message("Invalid Year in Date Entry");
				}
				else if (tmp.errCode() == MON_ERROR) {
					Product::message("Invalid Month in Date Entry");
				}
				else if (tmp.errCode() == DAY_ERROR) {
					Product::message("Invalid Day in Date Entry");
				}
			}
			else {
				c_expiry = tmp;
			}
		}
		return is;
	}

	const Date & Perishable::expiry() const {
		return c_expiry;
	}

}