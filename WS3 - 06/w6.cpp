// Workshop 6 - STL Containers
// w6.cpp
// Updated by cornel on 27.09.2018

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "iProduct.h"
#include "ProdUtil.h"

int main(int argc, char** argv) {

	std::cout << "Command Line: ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;
	if (argc != 2) {
		std::cerr << "\n***Incorrect number of arguments***\n";
		return 1;
	}
	std::ifstream productList(argv[1]);
	if (!productList) {
		std::cerr << "\n***Failed to open file " << argv[1] << "***\n";
		return 2;
	}
	std::cout << std::fixed << std::setprecision(2);

	// TODO: Define a variable of type vector named "products"
	//vector type is pointer of iProduct abstract class
	std::vector<w6::iProduct*> products;
	
	std::cout << "====================================\n";
	std::cout << "Reading data from the file\n";
	std::cout << "====================================\n";
	
		// TODO: Read from the file one record at a time and create a product.
	//create temporary object to store value from the file
	w6::iProduct* temp = nullptr;
	//count record
	int i = 1;
	do {
		std::cout << "Processing record " << i << ": ";
		try {
			//copy the data from the file
			temp = w6::readProduct(productList);
			if (temp) {
				//store the temp's data to vector object
				products.push_back(temp);
				std::cout << "done!" << std::endl;
			}
			else {
				std::cout << "no such record! Reached the end of the file!" << std::endl;
			}
		}
		//if there is an error catch and throw
		catch (std::string err) {
			std::cout << err << std::endl;
		};
		++i;
	} while (temp != nullptr);

	
	std::cout << "====================================\n";

	std::cout << std::endl;
	std::cout << "====================================\n";
	std::cout << "Printing the content of the vector\n";
	std::cout << "====================================\n";

	double total = 0.0;
	std::cout << "      Product No         Taxable\n";
	std::cout << "------------------------------------\n";
	for (auto i = 0u; i < products.size(); i++) {
		total += products[i]->getPrice();
		std::cout << *products[i];
	}
	std::cout << "------------------------------------\n";
	std::cout << std::setw(22) << "Total: ";
	std::cout << std::setw(10) << total << std::endl;
	std::cout << "====================================\n";

	return 0;
}
