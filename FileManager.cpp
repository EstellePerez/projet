#include "FileManager.h"

using namespace std;

string FileManager::_sep="/";

FileManager::File::File (const string& path, const string& date):_path(path)
{
	struct std::tm tm;
	std::istringstream ss(date);
	ss >> std::get_time(&tm, "%Y:%m:%d %T");
	_date = mktime(&tm);
}

time_t FileManager::File::operator-(const File& file)
{
	return _date-file._date;
}


bool order (FileManager::File first, FileManager::File second)
{
	return (first.getDate() < second.getDate ());
}

void FileManager::sort ()
{
	std::sort(_file.begin(), _file.end(), order);
}

void FileManager::scanFolders (const string& name)
{
	DIR* rep = NULL;
    struct dirent* file = NULL; 
    rep = opendir(name.c_str());
	if (!rep)
	{
		return;
	}
	file = readdir(rep);
	while (file)
	{
		string file_name = file->d_name;
		string path = name + _sep + file_name;

		cout<< file_name <<endl;
		if ((file->d_type==DT_DIR) &&
			(strcmp(file_name.c_str(), ".")) &&
			(strcmp(file_name.c_str(), "..")))
		{
			scanFolders(path);
		}
		else
		{
			try 
			{
				_file.push_back (File(file_name, extractDate (path)));
			}
			catch (Exiv2::Error& e) 
			{
				
			}
		}
		file = readdir(rep);
	}
	closedir (rep);
}
		
string FileManager::extractDate (const string& path)
{
	Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(path);
	image->readMetadata();
	Exiv2::ExifData& exifData = image->exifData();
	string date_str =exifData["Exif.Photo.DateTimeOriginal"].toString();
	cout << date_str << endl;
	return date_str;
}

