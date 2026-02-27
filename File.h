/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class: 	CSC 242
** Assignment: 	Assignment 5: Comprehensive Program Challenge
** File: File.h
** Description:
** This program reads words from a dictionary file and a document file,
** then compares the document words against the dictionary to identify
** and display any misspelled words. The program uses functions to
** organize tasks such as loading files and checking spelling.
**
** Author: 	Alexandra Gonzalez, Karon Eley, Edward Davis
** Date: 	2/24/26
** -------------------------------------------------------------------------*/


#pragma once // This prevents the file from being included more than once.

/*
   Simply a class that holds a struct; this struct defines methods for 
   searching and opening text files. It also holds the method that is used for 
   the spell check of the document text. 

   If you end up changing text files you need to update the strings in main
   that holds the current text files path.
*/ 

//In simple terms: This header file defines the structure (RFile), ceclares functions, and tells which other files exist.


#include <iostream> // for cout - cin
#include <fstream> // For reading files
#include <vector> // To store words
#include <string>

struct RFile
{   
	std::vector<std::string> dictionaryWords; // To store all words from dictionary.txt
	std::vector<std::string> documentWords; // To store all words from dictionary.txt

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
	// All words from dictionary.txt
};