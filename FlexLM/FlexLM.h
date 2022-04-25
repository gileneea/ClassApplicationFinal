#include <string>
#include <vector>

#ifdef FLEXLM_EXPORTS
#define FLEXLM_API __declspec(dllexport)
#else
#define FLEXLM_API __declspec(dllimport)
#endif

/// <summary>
/// FlexLM class declaration.
/// </summary>
class FLEXLM_API CFlexLM {
public:
	CFlexLM(void);
};

extern FLEXLM_API int nFlexLM;

FLEXLM_API std::vector<std::string> readLicenses(std::string);
