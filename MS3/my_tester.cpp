#include "MyProduct.h"
#include "Product.h"
#define filename "ms3.txt"
using namespace std;
using namespace AMA;

void doit();

int main() {

	

	doit();
	
	std::cout << "Hello" << std::endl;
	return 0;
}

void doit() {

	Product b("word1", '\0', "word3", 1, true, 1.0, 0);
	
	
	//b.~Product();

	system("pause");
}
