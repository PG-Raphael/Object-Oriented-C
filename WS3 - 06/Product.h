#ifndef W6_PRODUCT_H
#define W6_PRODUCT_H
#include <fstream>
#include <string>
#include "iProduct.h"


namespace w6
{
	class Product : public iProduct
	{ 
		std::string c_proNum;
		double c_proCost;
	public:
		Product(std::string, const double );

		double getPrice() const;
		void display(std::ostream& os) const;
	};
}
#endif