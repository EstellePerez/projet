#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "Entry.h"

using namespace std;

class Directory : public Entry
{
	private:
		
	public:
		bool isDir () {return true;}
};

#endif
