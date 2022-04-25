#include "framework.h"
#include "FlexLM.h"
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
using namespace std;

// This is an example of an exported variable
FLEXLM_API int nFlexLM=0;

// This is the constructor of a class that has been exported.
CFlexLM::CFlexLM()
{
    return;
}

/// <summary>
/// Function to read the license text file and return a vector of strings containing all available licenses to the user.
/// </summary>
FLEXLM_API vector<string> readLicenses(string file)
{
    string filePath = "C:\\Users\\Eric\\Desktop\\School\\SA\\Final_Project\\SoftwareArchitectureCLassApplication-main\\ClassApplicationFinal\\FlexLM\\" + file;
    vector<string> licenses;
    fstream licenseFile;
    licenseFile.open(filePath, ios::in);
    if (licenseFile.is_open()) { 
        string license;
        while (getline(licenseFile, license)) {
            licenses.push_back(license);
        }
        licenseFile.close();
    }
    return licenses;
}