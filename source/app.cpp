#include "include/app.hpp"
#include <iostream>
#include <string>


DocumentManager dc;
int comandNum = 0;

void printMenu ()
{
	while (comandNum != 5)
	{
		std::cout << "Welcome to Simple Document Manager " 
	         	  << "\nOptions :"
	          	  << "\n1. Create Document"
	      	  	  << "\n2. Edit Document"
	      	  	  << "\n3. View"
	      	  	  << "\n4. Show"
	      	  	  << "\n5. Exit" << std::endl;

    		std::cin >> comandNum;
		completeCommand(dc,comandNum);
	}

}

void completeCommand(DocumentManager& dc, int comandNum)
{
	switch (comandNum)
	{
	    case 1: dc.createDocument();
		    break;
	    case 2: dc.editDocument();
		    break;
            case 3: dc.viewDocument();
		    break;
            case 4: dc.showDocuments();
		    break;
	}
}
