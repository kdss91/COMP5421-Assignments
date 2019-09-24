#include<iostream>
#include<iomanip>
#include<fstream>
#include<cassert>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::string;

#include "Line.h"
#include "LineList.h"

// function prototypes
bool operator== (const LineList&, const LineList&);
bool operator!= (const LineList&, const LineList&);
bool operator== (const Line&, const Line&);
bool operator!= (const Line&, const Line&);
void load_linked_list(const char*, LineList&);
void test_linked_list_operations(LineList&);
void test_line_operations(Line&);

/**Main function
*@return int success 0 or error 1
*/
int main()
{
	const char* filename_a{ "C:\\input_a.txt" };
	const char* filename_b{ "C:\\input_b.txt" };

	LineList list_a{};
	load_linked_list(filename_a, list_a);      // load our first list list_a
	cout << "list_a loaded" << "\n";
	list_a.print();                           // print list_a

	test_linked_list_operations(list_a);      // manipulate lines in list_a
	cout << "\n" << "list_a rearranged" << "\n";
	list_a.print();                           // print manipulated list_a

	LineList list_b{};
	load_linked_list(filename_b, list_b);     // load our second list list_b

	cout << "Print list b." << endl;
	list_b.print();
	assert(list_a == list_b);                 // test operator ==

	cout << "Done!(a==b)" << endl;					//denotes assert success

	LineList list_c{};
	list_c = list_a;			//Assign list a to list c using assignment operator overload

	cout << "\nList c assigned using assignment= operator overload." << endl;
	cout << "\nPrint list c." << endl;
	list_c.print();

	assert(list_c == list_a);                 // test operator ==
	cout << "\nDone!(a==c)" << endl;					//denotes assert success



	LineList list_d{ list_a };     //list_d created using copy constructor

	cout << "\nList d created using copy constructor." << endl;
	cout << "\nPrint list d." << endl;
	list_d.print();

	assert(list_d == list_a);                 // test operator ==
	cout << "\nDone!(a==d)" << endl;					//denotes assert success


	const char* tmpLine{ "ABCDEFGH" };
	Line lineObject{};
	lineObject = Line(tmpLine);               //invokes assignment operator = overload
	test_line_operations(lineObject);          //manipulates line in lineObject
	return 0;                                // report success
}

/**Loads the supplied line_list  with the lines of a given text file.
*@param filename The name of the given text file.
*@param line_list The LineList object to load.
*/
void load_linked_list(const char* filename, LineList& line_list)
{
	std::ifstream ifs(filename, std::ifstream::in);   //ifstream object for reading file
	if (!ifs.is_open())
	{
		cout << "Unable to open file" << filename << endl;
		exit(0);
	}

	int lineno{ 0 };
	std::string line;
	while (getline(ifs, line)) // Read until end of file
	{
		++lineno;
		//cout << "(" << lineno << ") " << line << endl;
		const char* c_line{ line.c_str() }; // const makes this a safe idea
		// Get a pointer to the c-string represented by the C++ string object
		// ONLY because Line's Ctor in the call below expects a char *
		line_list.push_back(Line(c_line));

		if (ifs.eof()) {       //check if it's end of file and break
			break;
		}
	}
}

/**Tests operations provided by a given LineList object.
*@param line_list The LineList object to use throughout the test.
*/
void test_linked_list_operations(LineList& line_list)
{

	if (line_list.empty()) return;                   // test empty()

	int lastPos = line_list.size();                  // size
	line_list.remove(lastPos);                        // remove
	cout << "\nAfter removing last element.\n";
	line_list.print();

	if (line_list.empty()) return;                   // empty

	line_list.remove(1);                             // remove
	cout << "\nAfter removing first element.\n";
	line_list.print();

	if (line_list.empty()) return;                   // empty

	cout << "Getting last line at position: " << line_list.size() << endl;
	cout << line_list.get(line_list.size()).cstr() << endl;

	Line lastline = line_list.get(line_list.size()); // get, copy ctor
	cout << "\nlastline created using copy constructor.\n";
	cout << lastline.cstr() << endl;

	line_list.pop_back();                            // pop_back
	cout << "\nAfter pop back\n";
	line_list.print();

	if (line_list.empty()) return;                   // empty

	Line line1 = line_list.get(1);                   // get
	cout << "\nline1 created using copy constructor.\n";
	cout << line1.cstr() << endl;

	line_list.pop_front();                           // pop_front()
	cout << "\nAfter pop front.\n";
	line_list.print();

	if (line_list.empty()) return;                   // empty

	line1 = line_list.get(1);                        // get, operator=
	cout << "\nline1 created using assignment= operator.\n";
	cout << line1.cstr() << endl;

	line_list.pop_front();                           // pop_front();
	cout << "\nAfter pop front.\n";
	line_list.print();

	line_list.push_front(lastline);                  // push_front
	cout << "\nAfter push front.\n";
	line_list.print();

	line_list.push_back(line1);                      // push_back
	cout << "\nAfter push back.\n";
	line_list.print();

	if (line_list.size() >= 3)                       // size
		line_list.insert(Line("Line  3"), 3);         // insert
	cout << "\nAfter insert at position 3.\n";
	line_list.print();

	line_list.insert(Line("Welcome to C++"), 1);     // insert
	cout << "\nAfter insert at position 1.\n";
	line_list.print();

	line_list.push_back(Line("Have fun!"));          // push_back
	cout << "\nAfter push back.\n";
	line_list.print();

	cout << "Getting line at position 1." << endl;
	cout << line_list.get(1).cstr() << endl;
	cout << "Getting line at position 5." << endl;
	cout << line_list.get(5).cstr() << endl;
	cout << "Getting line at position " << line_list.size() - 1 << "." << endl;
	cout << line_list.get(line_list.size() - 1).cstr() << endl;
	cout << "Getting line at position " << line_list.size() << "." << endl;
	cout << line_list.get(line_list.size()).cstr() << endl;

	cout << "Inserting line at position 1." << endl;
	line_list.insert(Line("Welcome to C++"), 1);
	line_list.print();

	cout << "Removing line at position 1." << endl;
	line_list.remove(1);
	line_list.print();

	cout << "Inserting line at position 5." << endl;
	line_list.insert(Line("Welcome to C++"), 5);
	line_list.print();

	cout << "Removing line at position 5." << endl;
	line_list.remove(5);
	line_list.print();

	cout << "Inserting line at position " << line_list.size() - 1 << endl;
	line_list.insert(Line("Welcome to C++"), line_list.size() - 1);
	line_list.print();

	cout << "Removing line at position " << line_list.size() - 2 << endl;
	line_list.remove(line_list.size() - 2);
	line_list.print();

	cout << "Inserting line at position " << line_list.size() << endl;
	line_list.insert(Line("Welcome to C++"), line_list.size());
	line_list.print();

	cout << "Removing line at position " << line_list.size() - 1 << endl;
	line_list.remove(line_list.size() - 1);
	line_list.print();

}

/**Tests operations provided by a given Line object.
*@param line The Line object to use throughout the test.
*/
void test_line_operations(Line& line) {

	if (line.empty()) return;                   // test empty()

	cout << line.cstr() << endl;
	cout << "Length=" << line.length() << endl;
	cout << "Capacity=" << line.capacity() << endl;

	line.pop_back();                        // remove
	cout << "\nAfter removing last element.\n";
	cout << line.cstr() << endl;
	cout << "Length=" << line.length() << endl;
	cout << "Capacity=" << line.capacity() << endl;

	if (line.empty()) return;                   // empty

	Line newLine = line; // get, copy ctor
	cout << "\nNew line created using copy constructor.\n";
	cout << newLine.cstr() << endl;
	cout << "Length=" << line.length() << endl;
	cout << "Capacity=" << line.capacity() << endl;

	line.pop_back();                            // pop_back
	cout << "\nAfter pop back\n";
	cout << line.cstr() << endl;
	cout << "Length=" << line.length() << endl;
	cout << "Capacity=" << line.capacity() << endl;

	if (line.empty()) return;                   // empty

	cout << "\nGetting first character.\n";
	cout << *line.cstr() << endl;

	line.push_back('G');          // push_back
	cout << "\nAfter push back.\n";
	cout << line.cstr() << endl;
	cout << "Length=" << line.length() << endl;
	cout << "Capacity=" << line.capacity() << endl;

	line.push_back('H');          // push_back
	cout << "\nAfter push back.\n";
	cout << line.cstr() << endl;
	cout << "Length=" << line.length() << endl;
	cout << "Capacity=" << line.capacity() << endl;

	line.push_back('I');          // push_back
	cout << "\nAfter push back.\n";
	cout << line.cstr() << endl;
	cout << "Length=" << line.length() << endl;
	cout << "Capacity=" << line.capacity() << endl;

	line.pop_back();                            // pop_back
	cout << "\nAfter pop back\n";
	cout << line.cstr() << endl;
	cout << "Length=" << line.length() << endl;
	cout << "Capacity=" << line.capacity() << endl;

	line.pop_back();                            // pop_back
	cout << "\nAfter pop back\n";
	cout << line.cstr() << endl;
	cout << "Length=" << line.length() << endl;
	cout << "Capacity=" << line.capacity() << endl;

}

/**An overload for operator==. Considers two lists equal
*if they each have the same number of lines and same lines.
*@param list1 The left hand side operand.
*@param list2 The right hand side operand.
*@return true if both lists are equal, otherwise false
*/
bool operator== (const LineList& list1, const LineList& list2)
{
	if (list1.size() != list2.size()) return false;
	for (size_t i{ 1 }; i != list1.size(); ++i)
	{
		if (list1.get(i) != list2.get(i)) return false;
	}
	return true;
}

/**An overload for operator!=. Considers two lists unequal
*if they they are not equal.
*@param list1 The left hand side operand.
*@param list2 The right hand side operand.
*@return true if both lists are not equal, otherwise false
*/
bool operator!= (const LineList& list1, const LineList& list2)
{
	return !(list1 == list2);
}


/**An overload for operator==. Considers two lines equal
*if they each have the same number of characters and same contents.
*@param line1 The left hand side operand.
*@param line2 The right hand side operand.
*@return true if both lines are equal, otherwise false
*/
bool operator==(const Line& line1, const Line& line2) {
	if (line1.empty() || line2.empty()) {
		return false;
	}

	if (strlen(line1.cstr()) != strlen(line2.cstr())) {
		return false;
	}

	return (strcmp(line1.cstr(), line2.cstr()) == 0);
}


/**An overload for operator!=. Considers two lines unequal
*if they they are not equal.
*@param line1 The left hand side operand.
*@param line2 The right hand side operand.
*@return true if both lines are not equal, otherwise false
*/
bool operator!=(const Line& line1, const Line& line2) {
	return (!(line1 == line2));
}


