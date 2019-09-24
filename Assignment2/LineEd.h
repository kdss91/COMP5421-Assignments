/**This file performs all the functions related to a line-oriented text editor.
*It operates on a buffer, which represents a memory in which the contents of a file are stored. The buffer can be edited continuously.
*It also contains a clipboard where cut and copied text are temporarily stored.
**/
#ifndef _MY_LINEED_H
#define _MY_LINEED_H
#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<fstream>

#include "Command.h"

using std::string;
using std::list;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::cin;
using std::stoi;

/**This class allows a user to open, edit, and save
* new or existing text files.
**/
class LineEd
{
private:
	/**Stores the contents of the buffer for editing
	**/
	list<string> buffer;

	/**It is used a temporary memory.
	*Valid operation are reading and overwriting its entire contents.
	**/
	vector<string> clipboard;

	/**It stores the name of the file to be operated upon.
	**/
	string filename;

	/**It stores the current line number.
	**/
	int currentLine;

	/**This map stores all the valid commands.
	**/
	static map<string, int> commands;

public:
	/**Default constructor takes filename to be operated upon.
	*@param string represents name of the file
	**/
	LineEd(string filename);

	/**It verifies that the command is valid. It performs command execution.
	*@param string& represents command as a string
	**/
	void runCommand(const string& command_line);

	/**It takes commands from the user until user quits the program
	**/
	void run();

	/**It converts a string representing line number to unsigned int.
	*It includes checking for special characters '.' and '$'
	*@param string represents line number
	*return size_t represents line number as unsigned int
	**/
	size_t findLineNumber(string number);

	/**It verifies if the address is valid and corrects -ve or out of bound addresses.
	*@param Command object represents a command
	**/
	void verifyAddress(Command& cmd);

	/**It prints the contents of the buffer elements in a range.
	*@param int x represents starting line number
	*@param int y represents ending line number
	**/
	void print(int x, int y);

	/**It checks if the command is valid or not
	*@param string represents a command
	*@return bool true if command is valid, otherwise false
	**/
	static bool isValidCommand(string cmd);

	/**It implements the code for appending text to buffer
	**/
	void commandA();

	/**It implements the code for inserting text into the buffer
	*@param Command represents the current command line object
	**/
	void commandI(Command& cmd);

	/**It implements the code to paste text from the clipboard to the buffer
	*@param Command represents the current command line object
	**/
	void commandV(Command& cmd);

	/**It implements the code to delete lines from the buffer
	*@param Command represents the current command line object
	**/
	void commandD(Command& cmd);

	/**It implements the code to delete lines from the buffer
	*@param Command represents the current command line object
	**/
	void commandX(Command& cmd);

	/**It implements the code to join the text from the specified range
	*together on one line at some address
	*@param Command represents the current command line object
	**/
	void commandJ(Command& cmd);

	/**It implements the code to print the elements in some line range of the buffer
	*@param Command represents the current command line object
	**/
	void commandP(Command& cmd);

	/**It implements the code to replace text in some line range in the buffer
	*@param Command represents the current command line object
	**/
	void commandC(Command& cmd);

	/**It implements the code to move the current line up by one line
	**/
	void commandU();

	/**It implements the code to move the current line down by one line
	**/
	void commandN();

	/**It implements the code to move to a specified line in the buffer
	*@param Command represents the current command line object
	**/
	void commandG(Command& cmd);

	/**It implements the code to save the buffer contents to a file
	**/
	void commandW();

	/**It implements the code to quit and save the buffer contents to a file
	**/
	void commandQ();
};
#endif



