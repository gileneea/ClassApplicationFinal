#include "pch.h"
#include "..\Core\StringUtils.h"
#include <string>
#include <fstream>
using namespace std;

TEST(StringUtilsTests, startsWithNegativeTest)
{

	std::string a = "aaaabbbb";
	std::string prefix = "bbbb";
	bool val = startsWith(a, prefix);


	EXPECT_FALSE(val);
	 
}

TEST(StringUtilsTests, startsWithPostiveTest)
{
	std::string a = "aaaabbbb";
	std::string prefix = "aaaa";
	bool val = startsWith(a, prefix);

	EXPECT_TRUE(val);

}

/// <summary>
/// Tests to ensure the readLicenses() function correctly returns the licenses inside the file
/// </summary>
TEST(LicenseAPITests, correctLicenseImport)
{
	string file = "license.txt";
	string licenses[2] = readLicenses(file);	// readLicenses() definition and implementation needed
	bool val = false;
	if (licenses[0] == "Basic" && licenses[0] == "PartOperations" && licenses[0] == "SolidModeling") {
		val = true;
	}
	EXPECT_TRUE(val);
}

/// <summary>
/// Tests to ensure the checkOut() function correctly checks licenses out
/// </summary>
TEST(LicenseAPITests, verifyCheckOutLicense)
{
	// Write license file for test
	ofstream myfile;
	myfile.open("license.txt");
	myfile << "Basic\nSolid_modeling\n";
	myfile.close();
	string file = "license.txt";
	string license = "Basic";
	string licenses[2] = readLicenses(file);	// readLicenses() definition and implementation needed
	bool val = false;
	if(find(begin(licenses), end(licenses), license)) {
		checkOut("Basic");						// checkOut() definition and implementation needed
		licenses[1] = readLicenses(file);		// readLicenses() definition and implementation needed
		if (!find(begin(licenses), end(licenses), license)) {
			val = true;
		}
	}
	EXPECT_TRUE(val);
}

/// <summary>
/// Tests to ensure the checkIn() function correctly checks licenses in
/// </summary>
TEST(LicenseAPITests, verifyCheckInLicense)
{
	// Write license file for test
	ofstream myfile;
	myfile.open("license.txt");
	myfile << "Solid_modeling\n";
	myfile.close();
	string file = "license.txt";
	string license = "Basic";
	string licenses[1] = readLicenses(file);	// readLicenses() definition and implementation needed
	bool val = false;
	if (!find(begin(licenses), end(licenses), license)) {
		checkIn("Basic");						// checkIn() definition and implementation needed
		licenses[2] = readLicenses(file);		// readLicenses() definition and implementation needed
		if (find(begin(licenses), end(licenses), license)) {
			val = true;
		}
	}
	EXPECT_TRUE(val);
}

/// <summary>
/// Tests to ensure the initializeLicense() function correctly initializes a licenses and adds them to the licenses.txt
/// </summary>
TEST(LicenseAPITests, verifyInitializeLicense)
{
	// Write license file for test
	ofstream myfile;
	myfile.open("license.txt");
	myfile << "Basic\nSolid_modeling\n";
	myfile.close();
	string file = "license.txt";
	string license = "Advanced";
	bool val = false;
	initializeLicense("Advanced");							// initializeLicense() definition and implementation needed
	string licenses[3] = readLicenses(file);				// readLicenses() definition and implementation needed
	if (find(begin(licenses), end(licenses), license)) {
		val = true;
	}
	EXPECT_TRUE(val);
}

/// <summary>
/// Tests to ensure the shutdownLicense() function correctly shuts down licenses and removes them from the licenses.txt
/// </summary>
TEST(LicenseAPITests, verifyShutdownLicense)
{
	// Write license file for test
	ofstream myfile;
	myfile.open("license.txt");
	myfile << "Basic\nSolid_modeling\n";
	myfile.close();
	string file = "license.txt";
	string license = "Basic";
	bool val = false;
	shutdownLicense("Basic");								// shutdownLicense() definition and implementation needed
	string licenses[1] = readLicenses(file);				// readLicenses() definition and implementation needed
	if (find(begin(licenses), end(licenses), license)) {
		val = true;
	}
	EXPECT_TRUE(val);
}