/**The purpose of this file is to model text lines as a doubly linked list.
*The doubly linked consists of Nodes. Each node consists of a pointer to previous node,
*a Line object, and a pointer to next node. Node is implemented as a private member of class LineList.
*This file also provides some simple operations on a linked list such as push/pop, insert, remove and get.
*/
#ifndef _MY_LINELIST_H
#define _MY_LINELIST_H
#include "Line.h"

using std::cout;
using std::endl;


/**This class stores all the Nodes (lines) as a doubly linked list.
*It also performs all the push/pop and other functions related
*to a linked list.
*/
class LineList {
private:

	/**Stores the number of nodes in LineList
	*/
	int theSize;

	/**It represents the fields of a Node object.
	*prev and next pointer to other nodes.
	*Line Object stores the contents of the line.
	*/
	class Node {
	public:

		/**Line object to store the contents of the line
		*/
		Line data;

		/**Pointer to previous Node
		*/
		Node* prev{ nullptr };

		/**Pointer to next Node
		*/
		Node* next{ nullptr };

		/**Node constructor
		*Used to initialize the Node elements.
		*@param ln Line object passed as reference
		*@param prv pointer to previous Node
		*@param nxt pointer to next Node
		*/
		Node(const Line& ln, Node* prv, Node* nxt);
	};

	/**Denotes the header of the LineList
	*/
	Node* head{ nullptr };

	/**Denotes the tail of the LineList
	*/
	Node* tail{ nullptr };

public:

	/**Default constructor implementation.
	*It creates head and tail nodes and links them.
	*/
	LineList();

	/**Destructor implementation.
	*Deallocates memory from nodes and then deletes
	*head and tail nodes.
	*/
	virtual ~LineList();


	/**Copy constructor implementation.
	*Creates a new linked list and initializes it with
	*the contents of nodes in the rhs object.
	*@param LineList object passed as reference
	*/
	LineList(const LineList& rhs);

	/**Implementation for assignment operator overloading.
	*@param LineList right hand side LineList object
	*@return Linelist with the updated contents of this object.
	*/
	const LineList& operator =(const LineList& rhs);

	/**It iterates over all nodes and prints all the
	*line objects in linelist.
	*/
	void print();


	/**It pushes a line to the front of Linked list.
	*@param Line object passed as reference
	*/
	void push_front(const Line& line);


	/**It pushes a line (Node) to the end of Linked list.
	*@param Line object passed as reference
	*/
	void push_back(const Line& line);

	/**It removes a Node (line) from front of linked list.
	*/
	void pop_front();

	/**It removes a Node (line) from end of linked list.
	*/
	void pop_back();

	/**Find the number of nodes in linelist.
	*@return int size of linelist
	*/
	int size() const;

	/**Checks if linelist is empty.
	*@return true if linelist is empty, otherwise false
	*/
	bool empty() const;

	/**Inserts a line (Node) at the position k in linelist
	*@param line Line object passed as reference
	*@param k position to insert at in linelist.
	*/
	void insert(const Line& line, int k);

	/**Removes a line (Node) at the position k in linelist
	*@param k position to remove at in linelist.
	*/
	void remove(int k);

	/**Get the line from node at the position k in linelist
	*@param k position in linelist.
	*@return Line object
	*/
	Line get(int k) const;
};
#endif

