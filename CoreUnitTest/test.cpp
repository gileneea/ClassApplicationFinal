#include "../Licensing/Licensing.h"
#include "../FlexLM/FlexLM.h"
#include "pch.h"
#include "..\Core\StringUtils.h"
#include <string>
#include <fstream>
using namespace std;

vector<string> readLicenses(string);

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
	string file = "Licenses.txt";
	vector<string> licenses = readLicenses(file);
	bool val = false;
	if (licenses.at(0) == "Basic" && licenses.at(1) == "PartOperations" && licenses.at(2) == "SolidModeling") {
		val = true;
	}
	EXPECT_TRUE(val);
}

/// <summary>
/// Tests to ensure the checkOut() function correctly checks licenses out
/// </summary>
TEST(LicenseAPITests, verifyCheckOutLicense)
{
	CLicensing licenses;
	licenses.initializeLicenses();
	licenses.checkOut("Basic");
	string checkOutStatus = licenses.licensesMap.at("Basic");
	bool val = false;
	if (checkOutStatus == "out") {
		val = true;
	}
	EXPECT_TRUE(val);
}

/// <summary>
/// Tests to ensure the checkIn() function correctly checks licenses in
/// </summary>
TEST(LicenseAPITests, verifyCheckInLicense)
{
	CLicensing licenses;
	licenses.initializeLicenses();
	licenses.checkOut("Basic");
	string checkOutStatus = licenses.licensesMap.at("Basic");
	bool val = false;
	if (checkOutStatus == "out") {
		licenses.checkIn("Basic");
		checkOutStatus = licenses.licensesMap.at("Basic");
		if (checkOutStatus == "in") {
			val = true;
		}
	}
	EXPECT_TRUE(val);
}

/// <summary>
/// Tests to ensure the initializeLicense() function correctly initializes a licenses and adds them to the licenses map.
/// </summary>
TEST(LicenseAPITests, verifyInitializeLicense)
{
	CLicensing licenses;
	licenses.initializeLicenses();
	bool val = false;
	if (!licenses.licensesMap.empty()) {
		val = true;
	}
	EXPECT_TRUE(val);
}

/// <summary>
/// Tests to ensure the shutdownLicense() function correctly shuts down licenses and removes them from the licenses map.
/// </summary>
TEST(LicenseAPITests, verifyShutdownLicense)
{
	CLicensing licenses;
	licenses.initializeLicenses();
	licenses.shutdownLicenses();
	bool val = false;
	if (licenses.licensesMap.empty()) {
		val = true;
	}
	EXPECT_TRUE(val);
}
