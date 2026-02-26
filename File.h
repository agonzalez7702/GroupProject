#pragma once

/*
   Simply a class that holds a struct; this struct defines methods for 
   searching and opening text files. It also holds the method that is used for 
   the spell check of the document text. 

   If you end up changing text files you need to update the strings in main
   that holds the current text files path.
*/ 


#include <iostream>
#include <fstream>
#include <vector>

struct RFile
{   
	std::vector<std::string> dictionaryWords;
	std::vector<std::string> documentWords;

	/*
	   Opens a text file based on the given path, and caches the words into 
	   the passed vector.
	*/
	 bool FetchText(std::string filePath, std::vector<std::string>& wordCache);

	 /*
	    Checks the document words for misspellings.
	 */
	 void SearchDocument(std::vector<std::string>& dictionaryCache, std::vector<std::string>& DocumentCache);

	RFile() :
	dictionaryWords(), documentWords()
	{ }
};