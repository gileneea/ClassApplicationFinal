Eric Gilene

Josh Lenhart

Final Project Part 1 – Estimate and Requirements

**Requirements:**
| **Requirement**                                   | **Classification** | **Description**                                                                                                                   |
|---------------------------------------------------|--------------------|-----------------------------------------------------------------------------------------------------------------------------------|
|     Implement   Licensing Library                 |     Required       |     Implement a   licensing library that will sit on top of your fake FlexLM libraries.                                           |
|     Library API                                   |     Required       |     Need to be   able to check out license, check back in, initialize licensing, and shutdown   licensing as part of your API.    |
|     Contexts                                      |     Required       |     Library   should have concept of contexts                                                                                     |
|     Add   additional licensing                    |     Desired        |     Add the   ability to add additional licensing to the library API in order to   accommodate future work.                       |
|     Implement Batch Operations                    |     Optional       |     Implement the   ability to run licensing API calls in a batch mode to run against multiple   libraries.                       |
|     Localization   support for the fake FlexLM    |     Optional       |     Implement the   ability to read in multiple localizations of text files for the fake FlexLM                                   |

|       Task                                        |       Estimation      | Actual |
|---------------------------------------------------|-----------------------|--------|
|     Write up   requirements                       |     1                 | 1      |
|     Implement   fake FlexLM system                |     4                 | 2      |
|     Implement   licensing library                 |     4                 | 2      |
|     Write   licensing API – Check out license     |     1                 | 1      |
|     Write   licensing API – Check in license      |     1                 | 1      |
|     Write   licensing API – Initialize license    |     1                 | 2      |
|     Write   licensing API – Shutdown license      |     1                 | 1      |
|     Implement   contexts                          |     2                 | 2      |
|     Testing/Debug                                 |     4                 | 4      |
|     Total:                                        |     19                | 16     |

**Conclusion:**

There were four major requirements for us to accomplish. We met those requirements through the creation of two libraries. The FlexLM library which housed the functions to read in the licenses file and the Licenses library which housed all of the API functions for the licenses. Inside of our Licensing library we generated a map from the licenses.txt file. With this map and our API functions we could update the checkin and checkout status of every license individually. We also ensured that we had a function to shutdown the licenses by removing them from the map and therefore from the memory. The time it took us to complete the project was fairly accurate to what our estimation was. Implementing the FlexLM library took less time than we had initially thought it would which allowed us to get ahead. Feel free to use or add any of our code to the GitHub project. If we had more time to continue to develop the functionality of the licensing library we would need to implement a way to check what licenses other users currently have checked out but that would require some sort of server implementation.

**Notes:**

We added a custom UI to the MainExe.cpp file for easy manual testing of the licensing API. To use simply run the project.

