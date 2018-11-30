#ifndef W6_TAXABLEPRODUCT_H
#define W6_TAXABLEPRODUCT_H
#include <fstream>
#include "Product.h"

namespace w6
{
	
	class TaxableProduct : public Product
	{
		//hold product number as a string
		std::string c_proNumTax;
		//hold cost
		double c_proCostTax;
		//hold taxtype
		char c_taxType;
		/*static const double taxRate[2];*/

	public:
		TaxableProduct(std::string _producNum, const double _productCost, const char _taxType);

		double getPrice() const;
		void display(std::ostream& os) const;
	};	
}
#endif