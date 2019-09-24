/**The purpose of this file is to implement all the
*functionalities of right triangle object.
**/
#ifndef _MY_RIGHTTRIANGLE_H
#define _MY_RIGHTTRIANGLE_H
#include"Triangle.h"

/**This class represents the characteristics of right triangle and
*implements the abstract functions of Triangle class.
**/
class RightTriangle :public Triangle {
public:
	/**Constructor initializes the right triangle components
	*@param side represents the side of the right triangle
	*@param name represents the name of the right triangle
	*@param description represents the decsciption of the right triangle
	**/
	RightTriangle(int base, string name = "Right triangle", string description = "One right and two acute angles");

	/**Function computes the geometric area
	*@return double represents the geometric area
	**/
	double geoArea() const override;

	/**Function computes the geometric parameter
	*@return double represents the geometric perimeter
	**/
	double geoPerimeter() const override;

	/**Function computes the number of characters that form the textual image of the right triangle
	*@return int represents the screen area
	**/
	int screenArea() const override;

	/**Function computes the number of characters on the borders of the textual
	*image of the right triangle
	*@return int represents the screen perimeter
	**/
	int screenPerimeter() const override;

	/**Function to draw a textual image of the shape object on a two dimensional grid
	*@return vector<vector<char>> represents the two dimensional grid
	**/
	vector<vector<char>> draw(char fChar = '*', char bChar = ' ') const override;

	/**Function computes the height of the right-triangle's bounding box
	*@return int represents the height of the smallest rectangular box enclosing
	*the textual image of the right triangle
	**/
	int boundingHeight() const override;

	/**Function computes the width of the right-triangle's bounding box
	*@return int represents the width of the smallest rectangular box enclosing
	*the textual image of the right triangle
	**/
	int boundingWidth() const override;
};
#endif