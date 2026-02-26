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
}