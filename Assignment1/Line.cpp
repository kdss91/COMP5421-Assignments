#include "Line.h"

/**Constructor which takes text and copies its
*contents to linePtr.
*@param char* pointer to a constant char
*/
Line::Line(const char* text) {
	if (text == nullptr) {
		return;
	}
	this->linePtr = new char[strlen(text) + 1];
	strcpy(this->linePtr, text);
	this->lineLength = strlen(text);
	*(linePtr + length()) = '\0';
	this->lineCapacity = strlen(text);
}

/**Copy constructor which copies contents from Line object
*@param Line constant line object passed as reference
*/
Line::Line(const Line& ln) {
	if (ln.linePtr == nullptr) {
		return;
	}
	this->linePtr = new char[strlen(ln.linePtr) + 1];
	this->lineLength = ln.lineLength;
	strcpy(this->linePtr, ln.linePtr);
	*(linePtr + length()) = '\0';
	this->lineCapacity = ln.lineCapacity;
}

/**Destructor implementation.
*Deallocates memory assigned to linePtr
*/
Line::~Line() {
	delete[] this->linePtr;
	this->linePtr = nullptr;
}

/**Implementation for assignment operator overloading.
*@param Line right hand side Line object.
*@return Line with the updated contents of this object.
*/
const Line& Line::operator =(const Line& rhs) {
	if (this == &rhs) {
		return *this;
	}

	delete[] this->linePtr;
	this->linePtr = new char[strlen(rhs.linePtr) + 1];
	this->lineLength = rhs.lineLength;
	strcpy(this->linePtr, rhs.linePtr);
	*(linePtr + length()) = '\0';
	this->lineCapacity = rhs.lineCapacity;
	std::cout << "\nLine assigned using assignment = operator " << this->linePtr << endl;
	return *this;
}

/**Points to contents of linePtr
*@return char* pointer to a constant char
*/
const char* Line::cstr() const {
	return this->linePtr;
}

/**Finds the length of linePtr
*@return int length of linePtr
*/
int Line::length() const {
	return this->lineLength;
}

/**Finds if line is empty or not
*@return bool true if empty, otherwise false
*/
bool Line::empty() const {
	return (this->linePtr == nullptr || this->lineLength == 0 || strlen(this->linePtr) == 0);
}

/**Finds of line is full or not
*@return bool true is full, otherwise false
*/
bool Line::full() const {
	return (this->lineLength >= this->lineCapacity);
}

/**Finds the capacity of line
*@return int capacity of line
*/
int Line::capacity() const {
	return this->lineCapacity;
}

/**Used to resize the capacity of line.
*It doubles the capacity of line if it is full.
*/
void Line::resize() {
	if (full()) {
		char* tmpPtr{ new char[length() + 1] };
		strcpy(tmpPtr, this->linePtr);				//copy contents to a temporary pointer
		*(tmpPtr + length()) = '\0';
		delete[] this->linePtr;
		this->linePtr = new char[2 * length() + 1];		//double the size of linePtr
		strcpy(this->linePtr, tmpPtr);
		*(linePtr + length()) = '\0';
		delete[] tmpPtr;
		tmpPtr = nullptr;
		this->lineCapacity *= 2;						//double the line capacity
	}
}

/**Pushes a character to the end of the line
*@param char constant character passed as reference
*/
void Line::push_back(const char& ch) {
	resize();
	this->lineLength++;
	this->linePtr[length() - 1] = ch;     //push character to end of line
	*(linePtr + length()) = '\0';
}

/**Pops a character from the end of the line
*/
void Line::pop_back() {
	if (empty()) {
		return;
	}
	*(linePtr + length() - 1) = '\0';
	this->lineLength--;
}

/**Implementation for stream insertion operator overload.
*@param out ostream object passed as reference
*@param line constant Line object passed as reference
*@return ostream object returned as reference to allow multiple insertions at once
*/
ostream& operator <<(ostream& out, const Line& line) {
	out << line.cstr();
	return out;
}

/**Implementation for stream extraction operator overload.
*@param in istream object passed as reference
*@param line Line object passed as reference
*@return istream object returned as reference to allow multiple extractions at once
*/
istream& operator >>(istream& in, Line& line) {
	char ch;
	while (in >> ch) {
		line.push_back(ch);
	}
	return in;
}
