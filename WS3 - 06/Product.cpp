/******************************
Name: Seungmin Yun            *
ID: 010820132                 *
E-mail: syun7@myseneca.ca     *
Date: 2018-11-02              *
*******************************/


#include <iostream>
#include <iomanip>
#include "Product.h"

namespace w6 {
	Product::Product (std::string _productNum, const double _productCost) {
		c_proNum = _productNum;
		c_proCost = _productCost;
	}

	double Product::getPrice() const {
		return c_proCost;
	}

	void Product::display(std::ostream& os) const {
		os << std::setw(16) << std::right;
		os << c_proNum;
		os << std::setw(16) << std::right;
		os << c_proCost << std::endl;	
	}
}