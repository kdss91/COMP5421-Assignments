#include"Rhombus.h"

/**Constructor initializes the rhombus components
*@param side represents the side of the rhombus
*@param name represents the name of the rhombus
*@param description represents the decsciption of the rhombus
**/
Rhombus::Rhombus(int side, string name, string description) :side{ side }, Shape(name, description){
	if (this->side % 2 == 0) {
		this->side++;
	}
}

/**Function computes the geometric area
*@return double represents the geometric area
**/
double Rhombus::geoArea() const {
	return ((double)pow(side, 2) / 2);
}

/**Function computes the geometric parameter
*@return double represents the geometric perimeter
**/
double Rhombus::geoPerimeter() const {
	return (2 * sqrt(2) * (double)side);
}

/**Function computes the number of characters that form the textual image of the rhombus
*@return int represents the screen area
**/
int Rhombus::screenArea() const {
	int tmp{ side / 2 };
	return (2 * tmp * (tmp + 1) + 1);
}

/**Function computes the number of characters on the borders of the textual
*image of the rhombus
*@return int represents the screen perimeter
**/
int Rhombus::screenPerimeter() const {
	return (2 * (side - 1));
}

/**Function to draw a textual image of the shape object on a two dimensional grid
*@return vector<vector<char>> represents the two dimensional grid
**/
vector<vector<char>> Rhombus::draw(char fChar, char bChar) const {
	int numfChar{ 1 };
	int numbChar{ ((side + 1) / 2) - 1 };
	Grid opGrid{ unsigned(side),vector<char>(unsigned(side), bChar) };
	int i, j;
	for (i = 0; i < side; ++i) {
		j = 0;
		for (j = 0; j < numbChar; j++) {
			opGrid[i][j] = bChar;
		}
		int lastElement{ j + (numfChar * 2) - 1 };
		for (; j < lastElement; j++) {
			opGrid[i][j] = fChar;
		}
		int midRow{ ((side + 1) / 2) - 1 };
		if (i < midRow) {
			numbChar--;
			numfChar++;
		}
		else {
			numbChar++;
			numfChar--;
		}
	}
	return opGrid;
}

/**Function computes the height of the rhombus's bounding box
*@return int represents the height of the smallest rectangular box enclosing
*the textual image of the rhombus
**/
int Rhombus::boundingHeight() const {
	return this->side;
}

/**Function computes the width of the rhombus's bounding box
*@return int represents the width of the smallest rectangular box enclosing
*the textual image of the rhombus
**/
int Rhombus::boundingWidth() const {
	return this->side;
}