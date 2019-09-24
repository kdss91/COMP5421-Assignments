/**The purpose of this file is to implement all the
*functionalities of an acute triangle object.
**/
#ifndef _MY_ACUTETRIANGLE_H
#define _MY_ACUTETRIANGLE_H
#include"Triangle.h"

/**Ths class represents the characteristics of acute triangle and
*implements the abstract functions of Triangle class.
**/
class AcuteTriangle :public Triangle {
public:
	/**Constructor initializes the acute triangle components
	*@param side represents the side of the acute triangle
	*@param name represents the name of the acute triangle
	*@param description represents the decsciption of the acute triangle
	**/
	AcuteTriangle(int base, string name = "Acute triangle", string description = "All acute angles");

	/**Function computes the geometric area
	*@return double represents the geometric area
	**/
	double geoArea() const override;

	/**Function computes the geometric parameter
	*@return double represents the geometric perimeter
	**/
	double geoPerimeter() const override;

	/**Function computes the number of characters that form the textual image of the acute triangle
	*@return int represents the screen area
	**/
	int screenArea() const override;

	/**Function computes the number of characters on the borders of the textual
	*image of the acute triangle
	*@return int represents the screen perimeter
	**/
	int screenPerimeter() const override;

	/**Function to draw a textual image of the shape object on a two dimensional grid
	*@return vector<vector<char>> represents the two dimensional grid
	**/
	vector<vector<char>> draw(char fChar = '*', char bChar = ' ') const override;

	/**Function computes the height of the acute-triangle's bounding box
	*@return int represents the height of the smallest rectangular box enclosing
	*the textual image of the acute triangle
	**/
	int boundingHeight() const override;

	/**Function computes the width of the acute-triangle's bounding box
	*@return int represents the width of the smallest rectangular box enclosing
	*the textual image of the acute triangle
	**/
	int boundingWidth() const override;
};
#endif
