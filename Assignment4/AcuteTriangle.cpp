#include"AcuteTriangle.h"

/**Constructor initializes the acute triangle components
*@param side represents the side of the acute triangle
*@param name represents the name of the acute triangle
*@param description represents the decsciption of the acute triangle
**/
AcuteTriangle::AcuteTriangle(int base, string name, string description) : Triangle(base % 2 == 0 ? ++base : base, (base + 1) / 2, name, description) {}

/**Function computes the geometric area
*@return double represents the geometric area
**/
double AcuteTriangle::geoArea() const {
	return ((getHeight() * (double)getBase()) / 2);
}

/**Function computes the geometric parameter
*@return double represents the geometric perimeter
**/
double AcuteTriangle::geoPerimeter() const {
	return (getBase() + (2 * sqrt(0.25 * getBase() * getBase() + getHeight() * double(getHeight()))));
}

/**Function computes the number of characters that form the textual image of the acute triangle
*@return int represents the screen area
**/
int AcuteTriangle::screenArea() const {
	return (getHeight() * getHeight());
}

/**Function computes the number of characters on the borders of the textual
*image of the acute triangle
*@return int represents the screen perimeter
**/
int AcuteTriangle::screenPerimeter() const {
	return (4 * (getHeight() - 1));
}

/**Function to draw a textual image of the shape object on a two dimensional grid
*@return vector<vector<char>> represents the two dimensional grid
**/
vector<vector<char>> AcuteTriangle::draw(char fChar, char bChar) const {
	const unsigned int h{ unsigned(getHeight()) };
	const unsigned int b{ unsigned(getBase()) };
	Grid opGrid{ h,vector<char>(b, bChar) };
	int i, j;
	for (i = 0; i < getHeight(); ++i) {
		for (j = 0; j < getHeight() - i - 1; j++) {
			opGrid[i][j] = bChar;
		}
		int lastElement{ j + (2 * (i + 1)) - 1 };
		for (; j < lastElement; j++) {
			opGrid[i][j] = fChar;
		}
	}
	return opGrid;
}

/**Function computes the height of the acute-triangle's bounding box
*@return int represents the height of the smallest rectangular box enclosing
*the textual image of the acute triangle
**/
int AcuteTriangle::boundingHeight() const {
	return getHeight();
}

/**Function computes the width of the acute-triangle's bounding box
*@return int represents the width of the smallest rectangular box enclosing
*the textual image of the acute triangle
**/
int AcuteTriangle::boundingWidth() const {
	return getBase();
}