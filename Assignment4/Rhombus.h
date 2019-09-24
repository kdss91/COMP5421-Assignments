/**The purpose of this file is to implement all the
*functionalities of rhombic object.
**/
#ifndef _MY_RHOMBUS_H
#define _MY_RHOMBUS_H
#include "Shape.h"
using std::pow;
using std::sqrt;

/**This class represents the characteristics of rhombus and
*implements the abstract functions of Shape class.
**/
class Rhombus : public Shape {
private:
	/**Represents the side of the rhombus
	**/
	int side;
public:
	/**Constructor initializes the rhombus components
	*@param side represents the side of the rhombus
	*@param name represents the name of the rhombus
	*@param description represents the decsciption of the rhombus
	**/
	Rhombus(int side, string name = "Diamond", string description = "A parallelogram with equal sides");

	/**Function computes the geometric area
	*@return double represents the geometric area
	**/
	double geoArea() const override;

	/**Function computes the geometric parameter
	*@return double represents the geometric perimeter
	**/
	double geoPerimeter() const override;

	/**Function computes the number of characters that form the textual image of the rhombus
	*@return int represents the screen area
	**/
	int screenArea() const override;

	/**Function computes the number of characters on the borders of the textual
	*image of the rhombus
	*@return int represents the screen perimeter
	**/
	int screenPerimeter() const override;

	/**Function to draw a textual image of the shape object on a two dimensional grid
	*@return vector<vector<char>> represents the two dimensional grid
	**/
	vector<vector<char>> draw(char fChar = '*', char bChar = ' ') const override;

	/**Function computes the height of the rhombus's bounding box
	*@return int represents the height of the smallest rectangular box enclosing
	*the textual image of the rhombus
	**/
	int boundingHeight() const override;

	/**Function computes the width of the rhombus's bounding box
	*@return int represents the width of the smallest rectangular box enclosing
	*the textual image of the rhombus
	**/
	int boundingWidth() const override;
};
#endif

