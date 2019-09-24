#include"RightTriangle.h"

/**Constructor initializes the right triangle components
*@param side represents the side of the right triangle
*@param name represents the name of the right triangle
*@param description represents the decsciption of the right triangle
**/
RightTriangle::RightTriangle(int base, string name, string description) : Triangle(base, base, name, description) {}

/**Function computes the geometric area
*@return double represents the geometric area
**/
double RightTriangle::geoArea() const {
	return ((getHeight() * (double)getBase()) / 2);
}

/**Function computes the geometric parameter
*@return double represents the geometric perimeter
**/
double RightTriangle::geoPerimeter() const {
	return ((2 + sqrt(2)) * (double)getHeight());
}

/**Function computes the number of characters that form the textual image of the right triangle
*@return int represents the screen area
**/
int RightTriangle::screenArea() const {
	return ((getHeight() * (getHeight() + 1)) / 2);
}

/**Function computes the number of characters on the borders of the textual
*image of the right triangle
*@return int represents the screen perimeter
**/
int RightTriangle::screenPerimeter() const {
	return (3 * (getHeight() - 1));
}

/**Function to draw a textual image of the shape object on a two dimensional grid
*@return vector<vector<char>> represents the two dimensional grid
**/
vector<vector<char>> RightTriangle::draw(char fChar, char bChar) const {
	Grid opGrid{ unsigned(getHeight()),vector<char>(unsigned(getBase()), bChar) };

	for (int i{ 1 }; i <= getHeight(); ++i) {
		for (int j{ 1 }; j <= i; ++j) {
			opGrid[i - 1][j - 1] = fChar;
		}
	}
	return opGrid;
}

/**Function computes the height of the right-triangle's bounding box
*@return int represents the height of the smallest rectangular box enclosing
*the textual image of the right triangle
**/
int RightTriangle::boundingHeight() const {
	return getHeight();
}

/**Function computes the width of the right-triangle's bounding box
*@return int represents the width of the smallest rectangular box enclosing
*the textual image of the right triangle
**/
int RightTriangle::boundingWidth() const {
	return getBase();
}