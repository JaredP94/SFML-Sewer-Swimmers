#include "gtest/gtest.h"
#include "FileReader.h"

#include <iostream>

TEST (FileReader, FileLoadsCorrectly)
{
	EXPECT_NO_THROW(FileReader test_File_Reader("test.txt"));
}

TEST (FileReader, ErrorThrownIfFileNotFound)
{
	FileReader test_File_Reader("test1.txt");
	EXPECT_THROW(test_File_Reader.getHighScore(), std::logic_error);
}

TEST (FileReader, returnsCorrectHighScore)
{
	FileReader test_File_Reader("test.txt");
	EXPECT_EQ(test_File_Reader.getHighScore(), 10000);
}

TEST (FileReader, canUpdateHighScore)
{
	FileReader test_File_Reader("test.txt");
	test_File_Reader.setHighScore(20000);
	EXPECT_EQ(test_File_Reader.getHighScore(), 20000);
	test_File_Reader.setHighScore(10000); //resetting high score to default test value
}