#include "framework.h"
#include "Licensing.h"
#include "../FlexLM/FlexLM.h"
#include <string>
#include <iostream>
using namespace std;

CLicensing::CLicensing()
{
    return;
}

/// <summary>
/// Function to initialize the licenses.
/// </summary>
void CLicensing::initializeLicenses()
{   
    string fileName = "Licenses.txt";
    vector<string> licenses = readLicenses(fileName);   // Read license text file in and save to a vector
    for (int i = 0; i < licenses.size(); i++) {
        licensesMap.insert(pair<string, string>(licenses.at(i), "in")); // Convert vector into a map to save checkin/checkout status
    }
}

/// <summary>
/// Function to check in a license.
/// </summary>
void CLicensing::checkIn(string license)
{
    map<string, string>::iterator licenseIterator = licensesMap.find(license);  // Locate license to modify
    if (licenseIterator != licensesMap.end()) {
        licenseIterator->second = "in";     // Change status to "in"
    }
}

/// <summary>
/// Function to check out a license.
/// </summary>
void CLicensing::checkOut(string license)
{
    map<string, string>::iterator licenseIterator = licensesMap.find(license);  // Locate license to modify
    if (licenseIterator != licensesMap.end()) {
        licenseIterator->second = "out";     // Change status to "out"
    }
}

/// <summary>
/// Function to shutdown licenses and remove from memory.
/// </summary>
void CLicensing::shutdownLicenses()
{
    licensesMap.clear();    // Wipe license map from memory
}

/// <summary>
/// Function to print the current license map including their checkin checkout status.
/// </summary>
void CLicensing::printMap()
{
    for (auto it = licensesMap.cbegin(); it != licensesMap.cend(); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;   // Print map
    }
}
