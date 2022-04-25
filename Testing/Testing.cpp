#include <iostream>
#include "../Licensing/Licensing.h"
using namespace std;

int main()
{
	CLicensing test;
	test.initializeLicenses();
	test.printMap();
	test.checkOut("SolidModeling");
	test.checkOut("Basic");
	test.printMap();
	test.checkIn("SolidModeling");
	test.printMap();
	test.shutdownLicenses();
	test.printMap();
}
