/******************************
Name: Seungmin Yun            *
ID: 010820132                 *
E-mail: syun7@myseneca.ca     *
Date: 2018-11-02              *
*******************************/


#include <iostream>
#include <iomanip>
#include "TaxableProduct.h"
#include "Product.h"

size_t productNum;
double productCost;
char taxType;

namespace w6
{
	/*const double TaxableProduct::taxRate[] = { 1.13, 1.08 };*/

	TaxableProduct::TaxableProduct(std::string _producNum, const double _productCost, const char _taxType) : Product(_producNum, _productCost) {
		c_proCostTax = _productCost;
		c_proNumTax = _producNum;
		c_taxType = _taxType;
	}
	
	//this function will get a price when it needs to caclulate with taxrate.
	double TaxableProduct::getPrice() const {
		double taxrate;
		double total = 0;
		if (c_taxType == 'H') {
			//set the tax rate
			taxrate = 1.13;
			//get total value;
			total = Product::getPrice() * taxrate;
		}
		else if (c_taxType == 'P') {
			taxrate = 1.08;
			total = Product::getPrice() * taxrate;
			/*taxrate = Product::getPrice() * taxRate[1];*/
		}
		return total;
	}

	//display outputs when input holds specific character 'H' and 'P'
	void TaxableProduct::display(std::ostream& os) const{
		os << std::setw(16) << std::right << c_proNumTax << std::setw(16) << std::right << c_proCostTax;
		os << ' ';
		if (c_taxType == 'H') {
			os << "HST";
		}
		else if (c_taxType == 'P') {
			os << "PST";
		}
		os << std::endl;
	}
}