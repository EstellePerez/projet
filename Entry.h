#ifndef ENTRY_H
#define ENTRY_H

#include <iostream>
#include <ctime>
#include <cwchar>
#include <string>
#include <sstream> 
#include <locale>
#include <iomanip>

using namespace std;

class Entry 
{
	private:
		string _path; 
		
	public:
		Entry (const string& path);
		virtual ~Entry();
		const string& getPath () { return _path;}
		virtual bool isDir () = 0;
};

#endif
