#include "include/documentManager.hpp"
#include <iostream>
#include <fstream>

void DocumentManager::chekFileFormat (const std::string& fileName)
{
	std::string correctFileFormat = ".txt";
        std::string failFormat = fileName.substr(fileName.size() - correctFileFormat.size());
        if (failFormat != correctFileFormat)
        {
                throw std::invalid_argument("Error: Wrong File Format: ");
        }
}

void DocumentManager::chekFileName (const std::string& fileName)
{
        bool flag = true;
	for (auto& file : m_fileNames)
	{
		if(file == fileName)
		{
			flag = false;
		}
	}

	if (flag)
        {
                throw std::invalid_argument("Error: Wrong File Name: ");
        }	
}

void DocumentManager::createDocument ()
{
	std::string fileName;
	std::cout << "Please enter file name: " << std::endl;
	std::cin >> fileName;
        
	chekFileFormat(fileName);
	
	m_fileNames.push_back(fileName);
	std::ofstream newFile;
	newFile.open(fileName);
	
	if(!newFile.is_open())
	{
		throw std::invalid_argument("Error: Failed to Open Filxe: ");
	}
	else
	{
		std::string str;

		std::cout << "Document " << fileName << " created successfully." 
			  << "\nEnter the contents:" 
			  << "\nTo stop, type in a new line  '!!' " << std::endl;
		
		while (std::getline(std::cin, str) && str != "!!") 
		{
        		newFile << str;
		}
		
		newFile << "\n";


	}

	newFile.close();
}

void DocumentManager::editDocument ()
{
	std::string fileName;
        std::cout << "Please enter file name: " << std::endl;
        std::cin >> fileName;

	chekFileFormat(fileName);
        chekFileName(fileName);

        std::ofstream editFile;
	editFile.open(fileName, std::ios::app);

        if(!editFile.is_open())
        {
                throw std::invalid_argument("Error: Failed to Open File: ");
        }
        else
        {
                std::string str;

                std::cout << "You can edit " << fileName << " document."
                          << "\n Enter the contents:" 
			  << "\nTo stop, type in a new line  '!!' "<< std::endl;

                while (std::getline(std::cin, str) && str != "!!")
                {
                        editFile << str;
                }

                editFile << "\n";


        }

        editFile.close();

}

void DocumentManager::viewDocument ()
{
	std::string fileName;
        std::cout << "Please enter file name: " << std::endl;
        std::cin >> fileName;

	chekFileFormat(fileName);
        chekFileName(fileName);

	std::ifstream viewFile;
	viewFile.open(fileName);

        if(!viewFile.is_open())
        {
                throw std::invalid_argument("Error: Failed to Open File: ");
        }
        else
        {
		char ch;
		while (viewFile.get(ch))
		{
			std::cout << ch;
		}
	}

	viewFile.close();

}

void DocumentManager::showDocuments()
{
	std::cout << "All documents in :" << std::endl;
	
	for (auto& file : m_fileNames)
        {
                std::cout << file << std::endl;
        }

}
