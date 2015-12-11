#include "Histogramme.h"

#define HISTO_SIZE 20

void Histogramme::createHistogramme (const string& path, const string& name_csv)
{	
	FileManager f_m;
	f_m.scanFolders (path);
	f_m.sort();
	//
	int tab [HISTO_SIZE];
	int lim [HISTO_SIZE];
	for (int i=0; i<HISTO_SIZE; i++)
	{
		tab [i]=0;
		lim [i]=1<<i;
	}
	
	ofstream file("result.csv", ios::in|ios::trunc);
	_file =f_m.getFile();
	if (file)
	{
		cout<<_file.size()<<endl;
		for (unsigned int i=1; i<_file.size(); i++)
		{
			int t =_file[i]-_file[i-1];
			int j=0;
			cout<<t<<endl;
			while (t>=lim[j])
			{
				cout<<"t:"<<t<<endl;
				cout<<"j:"<<lim[j]<<endl;
				j++;
			}
			tab [j]++;
		}
		
		for (int i=1; i<HISTO_SIZE-1; i++)
		{
			if ((tab[i]<tab[i-1])&&(tab[i]<tab[i+1]))
			{
				_min.push_back(tab[i]);
				cout<<"min"<<lim[i]<<endl;
			}
		}
		
		for (int i=0; i<HISTO_SIZE; i++)
		{
			file << lim[i] <<";" << tab[i]<<endl;
		}
		
		file.close();
	}
	else
	{
		cout<<"pb ouverture"<<endl;
	}
		
}
