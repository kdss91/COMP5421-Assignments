#include "Shape.h"

/**Constructor initializes the name and description
*@param name represents the name of the shape
*@param description represents the description of the shape
**/
Shape::Shape(string name, string description) : id{ generateID() }, name{ name }, description{ description } {}

/**Getter to fetch the ID
*@return int represents the unique ID of the shape
**/
int Shape::getID() {
	return this->id;
}

/**Getter to fetch the name of the shape
*@return string represents the name of the shape
**/
string Shape::getName() {
	return this->name;
}

/**Getter to fetch the description of the shape
*@return string represents the description of the shape
**/
string Shape::getDesciption() {
	return this->description;
}

/**Sets the name of the shape
*@param name represents the name of the shape
**/
void Shape::setName(string name) {
	this->name = name;
}

/**Sets the description of the shape
*@param description represents the description of the shape
**/
void Shape::setDescription(string description) {
	this->description = description;
}

/**Function represents the shape object as a string
*@return string represents the string representation for the shape object
**/
string Shape::toString() const {
	ostringstream gArea;
	gArea << fixed << setprecision(2) << geoArea();
	ostringstream gPerimeter;
	gPerimeter << fixed << setprecision(2) << geoPerimeter();
	string result{ "\nShape Information\n-----------------\nid:            " + to_string(id) + "\nShape name:    " + name + "\nDescription:   " + description +
					"\nB. box width:  " + to_string(boundingWidth()) + "\nB. box height: " + to_string(boundingHeight()) +
				   "\nScr area:      " + to_string(screenArea()) + "\nGeo area:      " + gArea.str() + "\nScr perimeter: " +
					to_string(screenPerimeter()) + "\nGeo perimeter: " + gPerimeter.str() + "\nStatic type:   " + typeid(this).name() +
					"\nDynamic type:  " + typeid(*this).name() + "\n" };
	return result;
}

/**Function to generate unique ID for every shape
*@return int represents the unique ID generated
**/
int Shape::generateID() {
	static int currentID{ 0 };
	return ++currentID;
}

/**Implementation for stream insertion operator overload.
*@param out ostream object passed as reference
*@param shape constant Shape object passed as reference
*@return ostream object returned as reference to allow multiple insertions at once
**/
ostream& operator<< (ostream& out, const Shape& shape) {
	out << shape.toString();
	return out;
}