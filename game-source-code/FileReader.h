#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
using namespace std;

class FileReader
{
public:	
	FileReader(const string& file_name);
	int getHighScore();
	void setHighScore(int score);
	void closeFile();

private:
	string _filename;
	fstream file;
	int _high_score;
};

#endif

