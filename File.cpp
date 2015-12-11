#include "File.h"

File::File (const string& path, const string& date):Entry(path)
{
	struct std::tm tm;
	std::istringstream ss(date);
	ss >> std::get_time(&tm, "%Y:%m:%d %T");
	_date = mktime(&tm);
}

time_t File::operator-(const File& file)
{
	return _date-file._date;
}
