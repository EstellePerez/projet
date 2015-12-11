#ifndef FILE_H
#define FILE_H

#include "Entry.h"

using namespace std;

class File : public Entry
{
	private:
		string _path; 
		time_t _date;
		
	public:
		File (const string& path, const string& date);
		const time_t& getDate () { return _date;}
		time_t operator-(const File& file);
		bool isDir () {return false;}
		
};

#endif
