#include "LineList.h"

/**Default constructor implementation.
*It creates head and tail nodes and links them.
*/
LineList::LineList() {
	this->theSize = 0;
	const char* myHead{ "head" };
	const char* myTail{ "tail" };
	const Line headLine{ Line(myHead) };
	const Line tailLine{ Line(myTail) };
	this->head = new Node(headLine, nullptr, nullptr);
	this->tail = new Node(tailLine, nullptr, nullptr);
	this->head->next = this->tail;				//points to tail node
	this->tail->prev = this->head;				//points to head node
}

/**Destructor implementation.
*Deallocates memory from nodes and then deletes
*head and tail nodes.
*/
LineList::~LineList() {
	while (!empty()) {
		pop_back();		//Deallocate and delete Nodes in LineList
	}
	delete tail;
	delete head;
	tail = nullptr;
	head = nullptr;
}

/**Copy constructor implementation.
*Creates a new linked list and initializes it with
*the contents of nodes in the rhs object.
*@param LineList object passed as reference
*/
LineList::LineList(const LineList& rhs) {
	this->theSize = 0;
	const char* myHead{ "head" };
	const char* myTail{ "tail" };
	const Line headLine{ Line(myHead) };
	const Line tailLine{ Line(myTail) };
	this->head = new Node(headLine, nullptr, nullptr);
	this->tail = new Node(tailLine, nullptr, nullptr);
	this->head->next = this->tail;
	this->tail->prev = this->head;

	Node* latestNode1{ rhs.head };

	while ((latestNode1 = latestNode1->next) != rhs.tail) {
		push_back(Line(latestNode1->data));				//Push line object (Node) to end of Line List
	}
}

/**Implementation for assignment operator overloading.
*@param LineList right hand side LineList object.
*@return Linelist with the updated contents of this object.
*/
const LineList& LineList::operator =(const LineList& rhs) {
	if (this == &rhs) {
		return *this;
	}

	while (!empty()) {
		pop_back();			//Empty the contents of Line List
	}

	Node* latestNode1{ rhs.head };

	while ((latestNode1 = latestNode1->next) != rhs.tail) {
		push_back(Line(latestNode1->data));             //Push line object (Node) to end of Line List
	}

	return *this;
}

/**It pushes a line to the front of Linked list.
*@param Line object passed as reference
*/
void LineList::push_front(const Line& line) {
	Node* myNode{ new Node(line, this->head, this->head->next) };
	this->head->next->prev = myNode;
	this->head->next = myNode;
	this->theSize++;
}

/**It pushes a line (Node) to the end of Linked list.
*@param Line object
*/
void LineList::push_back(const Line& line) {
	Node* myNode{ new Node(line, this->tail->prev, this->tail) };
	this->tail->prev->next = myNode;
	this->tail->prev = myNode;
	this->theSize++;
}

/**It removes a Node (line) from front of linked list.
*/
void LineList::pop_front() {
	if (empty()) {
		return;
	}

	Node* tmpNode{ this->head->next->next };
	delete this->head->next;
	this->head->next = tmpNode;
	tmpNode->prev = this->head;
	this->theSize--;
}

/**It removes a Node (line) from end of linked list.
*/
void LineList::pop_back() {
	if (empty()) {
		return;
	}

	Node* tmpNode{ this->tail->prev->prev };
	delete this->tail->prev;
	this->tail->prev = tmpNode;
	tmpNode->next = this->tail;
	this->theSize--;
}

/**Find the number of nodes in linelist.
*@return int size of linelist
*/
int LineList::size() const {
	return this->theSize;
}

/**Checks if linelist is empty.
*@return true if linelist is empty, otherwise false
*/
bool LineList::empty() const {
	return (size() == 0 || this->head->next == this->tail);
}

/**Inserts a line (Node) at the position k in linelist
*@param line Line object passed as reference
*@param k position to insert at in linelist
*/
void LineList::insert(const Line& line, int k) {
	if (k > this->theSize || k <= 0) {				//check if position is out of bounds
		return;
	}
	int posCount = 1;
	Node* prevNode{ this->head };
	Node* nextNode{ this->head };
	while (posCount <= k && nextNode->next != this->tail) {			//reach Node at position k 
		prevNode = nextNode;
		nextNode = nextNode->next;
		posCount++;
	}
	Node* myNode{ new Node(line, prevNode, nextNode) };
	prevNode->next = myNode;
	nextNode->prev = myNode;
	this->theSize++;
}

/**Removes a line (Node) at the position k in linelist
*@param k position to remove at in linelist
*/
void LineList::remove(int k) {
	if (k > this->theSize || k <= 0) {				//check if position is out of bounds
		return;
	}
	int posCount = 1;
	Node* prevNode{ this->head };
	Node* nextNode{ this->head };
	while (posCount <= k && nextNode->next != this->tail) {   //reach Node at position k 
		prevNode = nextNode;
		nextNode = nextNode->next;
		posCount++;
	}

	if (nextNode->next != nullptr) {
		Node* tmpNode{ nextNode->next };    //Points to Node at position k+1
		prevNode->next = tmpNode;
		tmpNode->prev = prevNode;
		delete nextNode;
		nextNode = nullptr;
		this->theSize--;
	}
}


/**Get the line from node at the position k in linelist
*@param k position in linelist
*@return Line object
*/
Line LineList::get(int k) const {          //k starts from position 1
	if (k > this->theSize || k <= 0) {				//check if position is out of bounds
		return nullptr;
	}

	int posCount = 1;
	Node* nextNode{ this->head };
	while (posCount <= k && nextNode->next != this->tail) {			//reach Node at position k 
		nextNode = nextNode->next;
		posCount++;
	}

	return nextNode->data;
}

/**It iterates over all nodes and prints all the
*line objects in linelist.
*/
void LineList::print() {
	cout << "\n***********************************************************\n";
	Node* latestNode{ this->head };
	int lineNumber{ 1 };
	while ((latestNode = latestNode->next) != this->tail) {
		cout << "(" << lineNumber++ << ") " << latestNode->data.cstr() << endl;
	}
	cout << "***********************************************************\n";
}

/**Node constructor
*Used to initialize the Node elements.
*@param ln Line object passed as reference
*@param prv pointer to previous Node
*@param nxt pointer to next Node
*/
LineList::Node::Node(const Line& ln, Node* prv, Node* nxt) : data{ ln }, prev{ prv }, next{ nxt } {}
