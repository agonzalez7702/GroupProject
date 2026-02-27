/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class: 	CSC 242
** Assignment: 	Assignment 5: Comprehensive Program Challenge
** File: File.cpp
** Description:
** This program reads words from a dictionary file and a document file,
** then compares the document words against the dictionary to identify
** and display any misspelled words. The program uses functions to
** organize tasks such as loading files and checking spelling.
**
** Author: 	Alexandra Gonzalez, Karon Eley, Edward Davis
** Date: 	2/24/26
** -------------------------------------------------------------------------*/


#include "File.h"
#include <algorithm>
#include <cctype>

                      
bool RFile::FetchText(std::string filePath, std::vector<std::string>& wordCache)
{
	if (filePath.empty()) return false;

	//Opening the file based on the given file path.
	std::ifstream file(filePath);
	if (!file.fail())
	{
		std::string foundWord{};
		while (file >> foundWord)
		{
			//Caching all found words in the file.
			wordCache.push_back(foundWord);
		}
		return true; // Return true to indicate the file was successfully opened andwords were Loaded
	}
	else { std::cerr << "[-] Failed to open file at " << filePath << std::endl; return false; }
}
// Converts a string to Lowercase for case-insensitive comparison
std::string toLower(const std::string& str)
{
	std::string lowerStr = str;
	std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
		[](unsigned char c) {return std::tolower(c); });
	return lowerStr;
}
void RFile::SearchDocument(std::vector<std::string>& dictionaryCache, std::vector<std::string>& documentCache)
{
	if (dictionaryCache.empty() && documentCache.empty()) return;

	int errorCount = 0;
	for (int i{}; i < documentCache.size(); i++)
	{
		bool realWordFound = false;
		for (int j{}; j < dictionaryCache.size(); j++)
		{
			if (toLower(documentCache.at(i)) == toLower(dictionaryCache.at(j)))
			{ 
				realWordFound = true;
				break; 
			}
		}
		if (!realWordFound)
		{
			std::cout << documentCache.at(i) << ": " << " Does not exist." << "\n";
			errorCount++;
		}
	}
	std::cout << "Found " << errorCount << " misspellings" << std::endl;
}