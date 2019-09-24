/**The purpose of this file is to model various geometric shapes.
*It consists of various abstract methods which are implemented in
*child classes. It generates unique ID for each shape object.
**/
#ifndef _MY_SHAPE_H
#define _MY_SHAPE_H
#include<string>
#include<sstream>
#include<vector>
#include<iostream>
#include<ostream>
#include<typeinfo>
#include<iomanip>
#include<memory>
using std::string;
using std::vector;
using std::ostream;
using std::cout;
using std::endl;
using std::to_string;
using std::ostringstream;
using std::fixed;
using std::setprecision;

using Grid = vector<vector<char>>;

/**This class specifies the common characteristics of various geometric shapes.
*It is an abstract class containing abstract methods to be implemented
*by the child classes.
**/
class Shape {
	/**Implementation for stream insertion operator overload.
	*@param out ostream object passed as reference
	*@param shape constant Shape object passed as reference
	*@return ostream object returned as reference to allow multiple insertions at once
	**/
	friend ostream& operator<< (ostream& out, const Shape& shape);
private:
	/**Identitiy number, distinct for every shape
	**/
	int id{ 0 };

	/**User supplied name for the shape
	**/
	string name;

	/**User supplied description for the shape
	**/
	string description;

	/**Function to generate unique ID for every shape
	*@return int represents the unique ID generated
	**/
	static int generateID();
public:
	/**Constructor initializes the name and description
	*@param name represents the name of the shape
	*@param description represents the description of the shape
	**/
	Shape(string name, string description);

	/**Getter to fetch the ID
	*@return int represents the unique ID of the shape
	**/
	int getID();

	/**Getter to fetch the name of the shape
	*@return string represents the name of the shape
	**/
	string getName();

	/**Getter to fetch the description of the shape
	*@return string represents the description of the shape
	**/
	string getDesciption();

	/**Sets the name of the shape
	*@param name represents the name of the shape
	**/
	void setName(string name);

	/**Sets the description of the shape
	*@param description represents the description of the shape
	**/
	void setDescription(string description);

	/**Function represents the shape object as a string
	*@return string represents the string representation for the shape object
	**/
	string toString() const;

	/**Function computes the geometric area
	@return double represents the geometric area
	**/
	virtual double geoArea() const = 0;

	/**Function computes the geometric parameter
	*return double represents the geometric perimeter
	**/
	virtual double geoPerimeter() const = 0;

	/**Function computes the number of characters that form the textual image of the shape
	*@return int represents the screen area
	**/
	virtual int screenArea() const = 0;

	/**Function computes the number of characters on the borders of the textual
	*image of the shape
	*@return int represents the screen perimeter
	**/
	virtual int screenPerimeter() const = 0;

	/**Function to draw a textual image of the shape object on a two dimensional grid
	*@return vector<vector<char>> represents the two dimensional grid
	**/
	virtual vector<vector<char>> draw(char fChar = '*', char bChar = ' ') const = 0;

	/**Function computes the height of the object's bounding box
	*@return int represents the height of the smallest rectangular box enclosing
	*the textual image of the shape
	**/
	virtual int boundingHeight() const = 0;

	/**Function computes the width of the object's bounding box
	*@return int represents the width of the smallest rectangular box enclosing
	*the textual image of the shape
	**/
	virtual int boundingWidth() const = 0;
};
#endif 