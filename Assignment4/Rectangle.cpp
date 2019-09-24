#include"Rectangle.h"

/**Constructor initializes the rectangle components
*@param width represents the width of the rectangle
*@param height represents the name of the rectangle
*@param name represents the name of the rectangle
*@param description represents the decsciption of the rectangle
**/
Rectangle::Rectangle(int width, int height, string name, string description) :height{ height }, width{ width }, Shape(name, description){}

/**Function computes the geometric area
*@return double represents the geometric area
**/
double Rectangle::geoArea() const {
	return height * double(width);
}

/**Function computes the geometric parameter
*@return double represents the geometric perimeter
**/
double Rectangle::geoPerimeter() const {
	return 2 * (height + double(width));
}

/**Function computes the number of characters that form the textual image of the rectangle
*@return int represents the screen area
**/
int Rectangle::screenArea() const {
	return height * width;
}

/**Function computes the number of characters on the borders of the textual
*image of the rectangle
*@return int represents the screen perimeter
**/
int Rectangle::screenPerimeter() const {
	return (2 * (height + width) - 4);
}

/**Function to draw a textual image of the shape object on a two dimensional grid
*@return vector<vector<char>> represents the two dimensional grid
**/
vector<vector<char>> Rectangle::draw(char fChar, char bChar) const {
	Grid opGrid{ unsigned(height),vector<char>(unsigned(width)) };
	for (int h{ 0 }; h < height; ++h) {
		for (int w{ 0 }; w < width; ++w) {
			opGrid[h][w] = fChar;
		}
	}
	return opGrid;
}

/**Function computes the height of the rectangle's bounding box
*@return int represents the height of the smallest rectangular box enclosing
*the textual image of the rectangle
**/
int Rectangle::boundingHeight() const {
	return this->height;
}

/**Function computes the width of the rectangle's bounding box
*@return int represents the width of the smallest rectangular box enclosing
*the textual image of the rectangle
**/
int Rectangle::boundingWidth() const {
	return this->width;
}