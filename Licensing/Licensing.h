#include <string>
#include <map>
using namespace std;

#ifdef LICENSING_EXPORTS
#define LICENSING_API __declspec(dllexport)
#else
#define LICENSING_API __declspec(dllimport)
#endif

/// <summary>
/// License class declaration
/// </summary>
class LICENSING_API CLicensing {
public:
	CLicensing(void);
	void initializeLicenses();
	void checkIn(string);
	void checkOut(string);
	void shutdownLicenses();
	void printMap();

	map<string, string> licensesMap;
};
