/******************************
Name: Seungmin Yun            *
ID: 010820132                 *
E-mail: syun7@myseneca.ca     *
Date: 2018-11-02              *
*******************************/

#include <string>
#include <cctype>
#include "ProdUtil.h"
#include "Product.h"
#include "TaxableProduct.h"

namespace w6
{
	//operater to refer base virtual class for polymorphism
	std::ostream& operator<<(std::ostream& os, const iProduct& product) {
		product.display(os);
		return os;
	}
	//this function will read a data from the file with specific conditions
	iProduct* readProduct(std::ifstream& ifs) {
		//peeking first character to ensure data type
		char firstChar = ifs.peek();
		if (firstChar != EOF && firstChar != '\n') {
			std::string prodNum;
			double price;
			//first string goes in prodNum and second number goes in price
			ifs >> prodNum >> price;
			//ignore white space
			ifs.ignore(); 
			firstChar = ifs.peek();
			//if fisrt character is alphabet
			if (std::isalpha(firstChar)) {
				//read and discard 256 character untill the new line
				ifs.ignore(256, '\n');
				// valid tax code
				if (firstChar == 'H' || firstChar == 'P')
					//if statments true, it retunrs to create new TaxableProduct 
					return new TaxableProduct(prodNum, price, firstChar);
				// invalid tax code throw error
				std::string err = "Unrecognizable Tax Code!";
				throw err;
			}
			else {
				return new Product(prodNum, price);
			}
		}
		else {
			return nullptr;
		}
	}
}



