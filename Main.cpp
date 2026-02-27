/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class: 	CSC 242
** Assignment: 	Assignment 5: Comprehensive Program Challenge
** File: Main.cpp
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


int main()
{
	//Variables.
	RFile file;
	std::string dictionaryPath{ "dictionary.txt" };
	std::string documentPath{ "Doc.txt" };

	//Searching for both text files.
	if (file.FetchText(dictionaryPath, file.dictionaryWords) && file.FetchText(documentPath, file.documentWords))
	{
		//Searching document text for errors.
		file.SearchDocument(file.dictionaryWords, file.documentWords);
	}

	else
	{
		std::cout << "File loading failed. Spell check aborted."
			<< std::endl;
	}

	return 0;
}