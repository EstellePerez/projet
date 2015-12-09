#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <exiv2/exiv2.hpp>
#include <iostream>
#include <ctime>
#include <cwchar>
#include <dirent.h>
#include <cstring>


using namespace std;

class FileManager
{

	private:
		static string _sep;
	public:
		class File 
		{
			private:
				string _path; 
				time_t _date;
			public:
				File (const string& path, const string& date);
				const string& getPath () { return _path;}
				const time_t& getDate () { return _date;}
				time_t operator-(const File& file);
				
		};
		
		void scanFolders (const string& name);
		string extractDate (const string& path);
		void sort ();
		vector<File>& getFile () {return _file;}
	
	private :
		vector<File> _file;
};

#endif

