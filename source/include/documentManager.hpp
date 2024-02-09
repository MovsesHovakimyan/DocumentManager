#ifndef DOCUMENTMANAGER_HPP
#define DOCUMENTMANAGER_HPP
#include <string>
#include <vector>

class DocumentManager
{
 public:
	 DocumentManager() = default;
	 ~DocumentManager() = default;

 public:
	 void createDocument ();
	 void editDocument ();
	 void viewDocument ();
	 void showDocuments();
 
 private:
	 std::vector<std::string> m_fileNames;
	 void chekFileFormat (const std::string&);
	 void chekFileName (const std::string&);
};

#endif // DOCUMENTMANAGER_HPP
