#include"Triangle.h"

/**Contructor initializes the triangle components
*@param base represents the length of the base
*@param height represents the height length
*@param name represents the name of the triangle
*@param description represents the description of the triangle
**/
Triangle::Triangle(int base, int height, string name, string description) : base{ base }, height{ height }, Shape(name, description){}

/**Getter to fetch the base length of the triangle
*@return int represents the base length
**/
int Triangle::getBase() const {
	return this->base;
}

/**Getter to fetch the height length
*@return int represents the height length
**/
int Triangle::getHeight() const {
	return this->height;
}