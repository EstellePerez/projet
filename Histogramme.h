#ifndef HISTOGRAMME_H
#define HISTOGRAMME_H

#include "FileManager.h"
#include <iostream>
#include <fstream>


using namespace std;


class Histogramme
{
	private:
		vector <int> _min;
		vector <File> _file;
		
	public:
		void createHistogramme (const string& path, const string& name_csv);

};

#endif

