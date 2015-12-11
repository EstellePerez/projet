#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <exiv2/exiv2.hpp>
#include <iostream>
#include <ctime>
#include <cwchar>
#include <dirent.h>
#include <cstring>
#include "File.h"


using namespace std;

class FileManager
{

	private:
		static string _sep;
		vector<File> _file;
		
	public:
		
		
		void scanFolders (const string& name);
		string extractDate (const string& path);
		void sort ();
		vector<File>& getFile () {return _file;}
};

#endif

