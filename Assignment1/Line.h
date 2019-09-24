/**The purpose of this file is to model a line of text.
*A line is stored in a dynamically created array of characters.
*This file provides some simple operations on a line such as push/pop and
*assignment operator overload.
*/
#ifndef _MY_LINE_H
#define _MY_LINE_H
#include<iostream>
#include<cstring>
using std::ostream;
using std::istream;
using std::endl;

/**This class stores the contents and related fields of a line.
*It also performs all required functions related to a line.
*/
class Line {
	/**Implementation for stream insertion operator overload.
	*@param out ostream object passed as reference
	*@param line constant Line object passed as reference
	*@return ostream object returned as reference to allow multiple insertions at once
	*/
	friend ostream& operator <<(ostream& out, const Line& line);

	/**Implementation for stream extraction operator overload.
	*@param in istream object passed as reference
	*@param line Line object passed as reference
	*@return istream object returned as reference to allow multiple extractions at once
	*/
	friend istream& operator >>(istream& in, Line& line);

public:

	/**Default constructor implementation used to initialize values.
	*/
	Line() = default;

	/**Constructor which takes text and copies its
	*contents to linePtr.
	*@param char* pointer to a constant char
	*/
	Line(const char* text);

	/**Copy constructor which copies contents from Line object
	*@param Line constant line object passed as reference
	*/
	Line(const Line& ln);

	/**Implementation for assignment operator overloading.
	*@param Line right hand side Line object.
	*@return Line with the updated contents of this object.
	*/
	const Line& operator =(const Line& rhs);

	/**Destructor implementation.
	*Deallocates memory assigned to linePtr
	*/
	virtual ~Line();

	/**Points to contents of linePtr
	*@return char* pointer to a constant char
	*/
	const char* cstr() const;

	/**Finds the length of linePtr
	*@return int length of linePtr
	*/
	int  length() const;

	/**Finds if line is empty or not
	*@return bool true if empty, otherwise false
	*/
	bool empty() const;

	/**Finds of line is full or not
	*@return bool true is full, otherwise false
	*/
	bool full() const;

	/**Finds the capacity of line
	*@return int capacity of line
	*/
	int capacity() const;

	/**Used to resize the capacity of line.
	*It doubles the capacity of line if it is full.
	*/
	void resize();

	/**Pushes a character to the end of the line
	*@param char constant character passed as reference
	*/
	void push_back(const char& ch);


	/**Pops a character from the end of the line
	*/
	void pop_back();


private:
	/**Pointer which points to the contents of the line
	*/
	char* linePtr{ nullptr };

	/**Integer which stores the length if the line
	*/
	int lineLength{ 0 };

	/**Integer which stores the capacity of the line
	*/
	int lineCapacity{ 0 };
};
#endif 