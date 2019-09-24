/**The purpose of this file is to implement all the
*functionalities of rectangular object.
**/
#ifndef _MY_RECTANGLE_H
#define _MY_RECTANGLE_H
#include "Shape.h"

/**This class represents the characteristics of rectangle and
*implements the abstract functions of Shape class.
**/
class Rectangle : public Shape {
private:
	/**Represents the height of the rectangle
	**/
	int height;

	/**Represents the width of the rectangle
	**/
	int width;
public:
	/**Constructor initializes the rectangle components
	*@param width represents the width of the rectangle
	*@param height represents the name of the rectangle
	*@param name represents the name of the rectangle
	*@param description represents the decsciption of the rectangle
	**/
	Rectangle(int width, int height, string name = "Four-sided", string description = "Four right angles");

	/**Function computes the geometric area
	*@return double represents the geometric area
	**/
	double geoArea() const override;

	/**Function computes the geometric parameter
	*@return double represents the geometric perimeter
	**/
	double geoPerimeter() const override;

	/**Function computes the number of characters that form the textual image of the rectangle
	*@return int represents the screen area
	**/
	int screenArea() const override;

	/**Function computes the number of characters on the borders of the textual
	*image of the rectangle
	*@return int represents the screen perimeter
	**/
	int screenPerimeter() const override;

	/**Function to draw a textual image of the shape object on a two dimensional grid
	*@return vector<vector<char>> represents the two dimensional grid
	**/
	vector<vector<char>> draw(char fChar = '*', char bChar = ' ') const override;

	/**Function computes the height of the rectangle's bounding box
	*@return int represents the height of the smallest rectangular box enclosing
	*the textual image of the rectangle
	**/
	int boundingHeight() const override;

	/**Function computes the width of the rectangle's bounding box
	*@return int represents the width of the smallest rectangular box enclosing
	*the textual image of the rectangle
	**/
	int boundingWidth() const override;
};
#endif 

