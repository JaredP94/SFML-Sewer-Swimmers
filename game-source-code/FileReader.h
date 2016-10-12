#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
using namespace std;

/**
* FileCannotBeOpened class - exception class used in error handling when file can't be opened.
*/
class FileCannotBeOpened{};

/**
* FileReader class - manages the input and output of game high scores to and from a data file.
* Loads in past high score for current game. Writes high score to file if a new high score is achieved.
*/
class FileReader
{
public:	
	/**
	* Constructor. Creates FileReader object which searches for a high score file to read from and write to.
	* @param file_name is a const reference to a string which contains the name of the file required to retrieve and output high score data.
	*/
	FileReader(const string& file_name);
	/**
	* Returns current high score from data file.
	* @return int containing high score from data file.
	*/
	int getHighScore();
	/**
	* Sets new high score which is then written to data file.
	* @param score is an int which contains the new high score to be written to the data file.
	*/
	void setHighScore(int score);
	/**
	* Closes data file when game ends to ensure data in file is correctly preserved.
	*/
	void closeFile();

private:
	string _filename;
	fstream file;
	int _high_score;
};

#endif

