/**The purpose of this file is to store the elements of a command line which are symbol,
*address1, address2. It parses a command line represented as a string.
**/
#ifndef _MY_COMMAND_H
#define _MY_COMMAND_H
#include<iostream>
#include<string>
#include<sstream>
#include<istream>
#include<vector>
#include<iterator>
#include<map>
#include<regex>
#include<ctype.h>

using std::string;
using std::vector;
using std::size_t;
using std::map;
using std::remove;
using std::cout;
using std::endl;
using std::to_string;
using std::stoi;

/**This class parses a command and stores its elements.
**/
class Command
{
private:
	/**String which stores a command line
	**/
	string command_line;

	/**Boolean which represents of overall command is valid or not
	**/
	bool status;

	/**Boolean which represents of the symbol is valid or not
	**/
	bool symbolStatus;

	/**Boolean which represents if address1 is valid or not
	**/
	bool address1Status;

	/**Boolean which represents if address2 is valid or not
	**/
	bool address2Status;

	/**String which stores the symbol of the command
	**/
	string symbol;

	/**String which stores the address1 of the command
	**/
	string address1;

	/**String which stores the address2 of the command
	**/
	string address2;

public:
	/**Constructor takes command line as a string and
	*intializes all the elements of the command.
	**/
	Command(const string& command_line);

	/**This function parses the command line parsed as string
	@param string& represents the command line passed
	**/
	void parse(const string& command_line);

	/**Getter to fetch the command symbol
	*@return string represents the symbol
	**/
	string getSymbol();

	/**Getter to fetch the address1
	*@return string represents the address1
	**/
	string getAddress1();

	/**Getter to fetch the address2
	*@return string represents the address2
	**/
	string getAddress2();

	/**Setter to set the symbol of the command
	*@param string represents the symbol
	**/
	void setSymbol(string symbol);

	/**Setter to set the address1
	*@param string represents the address1
	**/
	void setAddress1(string adrs1);

	/**Setter to set the address2
	*@param string represents the address2
	**/
	void setAddress2(string adrs2);

	/**Getter to fetch the overall command line status
	*@return true if command line is valid, otherwise false
	**/
	bool getStatus();

	/**Setter to set the command line status
	*@param bool represents the command line status
	**/
	void setStatus(bool status);

	/**Getter to fetch the symbol status
	*@return bool true if symbol is valid, otherwise false
	**/
	bool getSymbolStatus();

	/**Setter to set the symbol status
	*@param bool represents the symbol status
	**/
	void setSymbolStatus(bool symbolStatus);

	/**Getter to fetch the address1 status
	*@return bool true if address1 is valid, otherwise false
	**/
	bool getAdress1Status();

	/**Setter to set the address1 status
	*@param bool represents the address1 status
	**/
	void setAddress1Status(bool address1Status);

	/**Getter to fetch the address2 status
	*@return bool true if address2 is valid, otherwise false
	**/
	bool getAdress2Status();

	/**Setter to set the address2 status
	*@param bool represents the address2 status
	**/
	void setAddress2Status(bool address2Status);

	/**It checks if the number represented by a string is a valid number
	*@return true if string represents a valid number, otherwise false
	**/
	bool checkIfStringIsNumber(string str);
};
#endif



