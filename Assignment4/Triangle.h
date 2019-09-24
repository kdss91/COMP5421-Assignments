/**The purpose of this file is to act as abstract class for
*various triangular shapes such as acute triangle and right triangle.
**/

#ifndef _MY_TRIANGLE_H
#define _MY_TRIANGLE_H
#include "Shape.h"
using std::sqrt;

/**This class specifies the common characteristics of various triangular shapes
**/
class Triangle : public Shape {
private:
	/**Represents horizontal base of triangle
	**/
	int base;

	/**Represents the length of line perpendicular to the base from the
	*intersection of the other two sides
	**/
	int height;

public:
	/**Contructor initializes the triangle components
	*@param base represents the length of the base
	*@param height represents the height length
	*@param name represents the name of the triangle
	*@param description represents the description of the triangle
	**/
	Triangle(int base, int height, string name, string description);

	/**Getter to fetch the base length of the triangle
	*@return int represents the base length
	**/
	int getBase() const;

	/**Getter to fetch the height length
	*@return int represents the height length
	**/
	int getHeight() const;
};
#endif 