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
using namespace std;

/* -----------------------------------------------------------
   Function: FetchText
   
   Description:
   Opens the file at the given file path and reads each word
   into the provided vector. Returns true if the file was
   successfully opened and processed, otherwise returns false.
------------------------------------------------------------ */
                      
bool RFile::FetchText(string filePath, vector< string>& wordCache)
{
	// If the file path is empty, stop execution
	if (filePath.empty()) return false;

	// Attempt to open the file
	ifstream file(filePath);

	// Check if file opened successfully
	if (!file.fail())

	{
		string foundWord{};

		// Read each word from the file and store it in the vector
		while (file >> foundWord)
		{
			//Caching all found words in the file.
			wordCache.push_back(foundWord);
		}
		return true; // Return true to indicate the file was successfully opened andwords were Loaded
	}
	else { cerr << "[-] Failed to open file at " << filePath << endl; return false; }
}

/* -----------------------------------------------------------
   Function: toLower
   Author: Karon Eley
   
   Description:
   Converts all characters in a string to lowercase.
   This allows for case-insensitive word comparisons.
------------------------------------------------------------ */

string toLower(const string& str)
{
	string lowerStr = str;
	transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
		[](unsigned char c) {return tolower(c); });
	return lowerStr;
}
/* -----------------------------------------------------------
   Function: RemovePunctuation
   Author: Alexandra Gonzalez

   Description:
   Removes punctuation characters from a word before it is
   compared to dictionary entries. This ensures that words
   followed by commas, periods, or other punctuation marks
   are still recognized correctly during spell checking.
------------------------------------------------------------ */
string RemovePunctuation(const string& word)
{
	string cleanWord;
	for (unsigned char c : word)
	{
		if (!ispunct(c))
			cleanWord += static_cast<char>(c);
	}

	return cleanWord;
}

/* -----------------------------------------------------------
   Function: SearchDocument
   Author: Edward Davis

   Description:
   Compares each word in the document against the dictionary.
   If a word is not found in the dictionary, it is reported
   as a misspelling. Displays the total number of misspellings.
------------------------------------------------------------ */
void RFile::SearchDocument(vector<string>& dictionaryCache, vector< string>& documentCache)
{
	if (dictionaryCache.empty() && documentCache.empty()) return;

	int errorCount = 0;
	for (int i{}; i < documentCache.size(); i++)
	{
		bool realWordFound = false;
		for (int j{}; j < dictionaryCache.size(); j++)
		{
			if (toLower(RemovePunctuation(documentCache.at(i))) == toLower(RemovePunctuation(dictionaryCache.at(j))))
			{ 
				realWordFound = true;
				break; 
			}
		}
		if (!realWordFound)
		{
			cout << documentCache.at(i) << ": " << " Does not exist." << "\n";
			errorCount++;
		}
	}
	cout << "Found " << errorCount << " misspellings" << endl;
}