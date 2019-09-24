/**The purpose of this file is to create an abstract data type and
*implement it in C++ using operator overloading. Learn about function objects
*and how to define them.
**/
#ifndef _MY_QUAD_H
#define _MY_QUAD_H
#include<array>
#include<iostream>
#include<stdexcept>
#include<iomanip>

using std::array;
using std::istream;
using std::ostream;
using std::endl;
using std::cout;
using std::invalid_argument;
using std::cin;
using std::setw;
using std::abs;


/**This class stores a Quad which is an abstract data type consisting of
*a real and quad part. It performs all the functions related to a Quad number.
**/
class Quad {
private:
	/**Array which stores a quad number
	**/
	array<long long int, 4> quadNum;

	/**It calculates the gcd of two numbers
	*@param long long int x represents the first number
	*@param long long int y represents the second number
	@return long long int represents the gcd result
	**/
	long long int gcd(long long int x, long long int y);

public:
	/**Constructor used to initialize contents of quad number array.
	*@param long long int x1 represents numerator of real part
	*@param long long int x2 represents denominator of real part
	*@param long long int x3 represents numerator of quad part
	*@param long long int x4 represents denominator of quad part
	**/
	Quad(long long int x1 = 0, long long int x2 = 1, long long int x3 = 0, long long int x4 = 1);

	/**Copy constructor used to copy contents from other quad object
	*@param Quad& represents quad object passed as reference
	**/
	Quad(const Quad& initQuad) = default;

	/**Assignment operator overload used to assign values
	*@param Quad& rhs represent right hand side quad object
	*@return Quad& represents reference to the updated quad object
	**/
	Quad& operator= (const Quad& rhs) = default;

	/**Default destructor
	**/
	virtual ~Quad() = default;

	/**Add and assign operator overload
	*@param Quad& represents right hand side quad object
	*@return Quad& represents reference to the updated quad object
	**/
	Quad& operator+= (const Quad& rhs);

	/**Subtract and assign operator overload
	*@param Quad& represents right hand side quad object
	*@return Quad& represents reference to the updated quad object
	**/
	Quad& operator-= (const Quad& rhs);

	/**Multiply and assign operator overload
	*@param Quad& represents right hand side quad object
	*@return Quad& represents reference to the updated quad object
	**/
	Quad& operator*= (const Quad& rhs);

	/**Divide and assign operator overload
	*@param Quad& represents right hand side quad object
	*@return Quad& represents reference to the updated quad object
	**/
	Quad& operator/= (const Quad& rhs);

	/**Add and assign operator overload
	*@param long long int& represents right hand side long long int
	*@return Quad& represents reference to the updated quad object
	**/
	Quad& operator+= (const long long int& rhs);

	/**Subtract and assign operator overload
	*@param long long int& represents right hand side long long int
	*@return Quad& represents reference to the updated quad object
	**/
	Quad& operator-= (const long long int& rhs);

	/**Multiply and assign operator overload
	*@param long long int& represents right hand side long long int
	*@return Quad& represents reference to the updated quad object
	**/
	Quad& operator*= (const long long int& rhs);

	/**Divide and assign operator overload
	*@param long long int& represents right hand side long long int
	*@return Quad& represents reference to the updated quad object
	**/
	Quad& operator/= (const long long int& rhs);

	/**Pre increment operator overload
	*return Quad& represents the updated quad object
	**/
	Quad& operator++ ();

	/**Post increment operator overload
	*param int represents a zero value
	*return Quad represents the updated quad object
	**/
	Quad operator++ (int tmp);

	/**Pre decrement operator overload
	*return Quad& represents the updated quad object
	**/
	Quad& operator-- ();

	/**Post decrement operator overload
	*param int represents a zero value
	*return Quad represents the updated quad object
	**/
	Quad operator-- (int tmp);

	/**Unary plus operator implementation
	*@return Quad& represents reference to the resulting quad object
	**/
	Quad& operator+ ();

	/**Unary minus operator implementation
	*@return Quad& represents reference to the resulting quad object
	**/
	Quad& operator- ();

	/**Non-const version of subscript operator overload
	*@param int& represents position element
	*@return long long int& represents reference to value of element at position
	**/
	long long int& operator[] (const int& pos);

	/**Const version of subscript operator overload
	*@param int& represents position element
	*@return long long int& represents reference to value of element at position
	**/
	const long long int& operator[] (const int& pos) const;

	/**Function call operator overload
	*@return double represents the absolute value
	**/
	double operator() ();

	/**Convert quad object to double
	*returns the absolute value
	**/
	operator double();

	/**Getter to fetch the quad number
	*@return an array of size four
	**/
	array<long long int, 4> getQuadNum() const;

	/**Setter to set the quad number
	*@param array of size four
	**/
	void setQuadNum(array<long long int, 4> quadNum);

	/**Norm of quad number
	*return double represents norm of x
	**/
	double norm() const;

	/**Absolute value of quad number
	*@return double represents absolute value of x
	**/
	double absoluteValue();

	/**Find if quad is similar to another quad
	*@param Quad& represents quad object
	*@return bool true when similar, otherwise false
	**/
	bool isSimilar(const Quad& y);

	/**Find if quad is similar Quad(k)
	*@param long long int& represents a number k
	*@return bool true when similar, otherwise false
	**/
	bool isSimilar(const long long int& k);

	/**Finds inverse of current object
	*@return Quad represents inverse of quad number
	**/
	Quad inverse() const;

	/**Normalizes current quad number
	**/
	void normalize();

	/**Reduces current quad number
	**/
	void reduce();

	/**Standardizes current quad number by
	*performing both reduce and normalize
	**/
	void standardize();

	/**Finds conjugate of current quad number x
	*@return Quad represents the conjugate of x
	**/
	Quad conjugate();
};

/**Implementation for stream insertion operator overload
*@param out ostream object passed as reference
*@param quad constant Quad object passed as reference
*@return ostream object returned as reference to allow multiple insertions at once
**/
ostream& operator<< (ostream& out, const Quad& quad);

/**Implementation for stream extraction operator overload.
*@param in istream object passed as reference
*@param quad Quad object passed as reference
*@return istream object returned as reference to allow multiple extractions at once
**/
istream& operator>> (istream& in, Quad& quad);

/**Addition of two Quad objects
*@param Quad& represents first quad object x
*@param Quad& represents second quad object y
*@return Quad represents the resultant Quad object
**/
Quad operator+ (const Quad& x, const Quad& y);

/**Subtraction of two Quad objects
*@param Quad& represents first quad object x
*@param Quad& represents second quad object y
*@return Quad represents the resultant Quad object
**/
Quad operator- (const Quad& x, const Quad& y);

/**Multiplication of two Quad objects
*@param Quad& represents first quad object x
*@param Quad& represents second quad object y
*@return Quad represents the resultant Quad object
**/
Quad operator* (const Quad& x, const Quad& y);

/**Division of two Quad objects
*@param Quad& represents first quad object x
*@param Quad& represents second quad object y
*@return Quad represents the resultant Quad object
**/
Quad operator/ (const Quad& x, const Quad& y);


/**Addition of Quad object and long long int value
*@param Quad& represents first quad object x
*@param long long int& represents a value
*@return Quad represents the resultant Quad object
**/
Quad operator+ (const Quad& x, const long long int& k);

/**Subtraction of Quad object and long long int value
*@param Quad& represents first quad object x
*@param long long int& represents a value
*@return Quad represents the resultant Quad object
**/
Quad operator- (const Quad& x, const long long int& k);

/**Multiplication of Quad object and long long int value
*@param Quad& represents first quad object x
*@param long long int& represents a value
*@return Quad represents the resultant Quad object
**/
Quad operator* (const Quad& x, const long long int& k);

/**Division of Quad object and long long int value
*@param Quad& represents first quad object x
*@param long long int& represents a value
*@return Quad represents the resultant Quad object
**/
Quad operator/ (const Quad& x, const long long int& k);

/**Addition of long long int value and Quad object
*@param long long int& represents a value
*@param Quad& represents first quad object x
*@return Quad represents the resultant Quad object
**/
Quad operator+ (const long long int& k, const Quad& x);

/**Subtraction of long long int value and Quad object
*@param long long int& represents a value
*@param Quad& represents first quad object x
*@return Quad represents the resultant Quad object
**/
Quad operator- (const long long int& k, const Quad& x);

/**Multiplication of long long int value and Quad object
*@param long long int& represents a value
*@param Quad& represents first quad object x
*@return Quad represents the resultant Quad object
**/
Quad operator* (const long long int& k, const Quad& x);

/**Division of long long int value and Quad object
*@param long long int& represents a value
*@param Quad& represents first quad object x
*@return Quad represents the resultant Quad object
**/
Quad operator/ (const long long int& k, const Quad& x);

/**This operator checks if first operand is lesser than second operand
*@param Quad& represents first quad object x
*@param Quad& represents second quad object y
*@return bool true if x < y, otherwise false
**/
bool operator< (const Quad& x, const Quad& y);

/**This operator checks if first operand is less than or equal to second operand
*@param Quad& represents first quad object x
*@param Quad& represents second quad object y
*@return bool true if x <= y, otherwise false
**/
bool operator<= (const Quad& x, const Quad& y);

/**This operator checks if first operand is greater than second operand
*@param Quad& represents first quad object x
*@param Quad& represents second quad object y
*@return bool true if x > y, otherwise false
**/
bool operator> (const Quad& x, const Quad& y);

/**This operator checks if first operand is greater than or equal to second operand
*@param Quad& represents first quad object x
*@param Quad& represents second quad object y
*@return bool true if x >= y, otherwise false
**/
bool operator>= (const Quad& x, const Quad& y);

/**This operator checks if both operands are equal or not
*@param Quad& represents first quad object x
*@param Quad& represents second quad object y
*@return bool true if x == y, otherwise false
**/
bool operator== (const Quad& x, const Quad& y);

/**This operator checks if both operands are equal or not
*@param Quad& represents first quad object x
*@param Quad& represents second quad object y
*@return bool true if x != y, otherwise false
**/
bool operator!= (const Quad& x, const Quad& y);


/**This operator checks if first operand is lesser than second operand (Quad(k))
*@param Quad& represents first quad object x
*@param long long int& represents a value k
*@return bool true if x < Quad(k), otherwise false
**/
bool operator< (const Quad& x, const long long int& k);

/**This operator checks if first operand is less than or equal to second operand (Quad(k))
*@param Quad& represents first quad object x
*@param long long int& represents a value k
*@return bool true if x <= Quad(k), otherwise false
**/
bool operator<= (const Quad& x, const long long int& k);

/**This operator checks if first operand is greater than second operand (Quad(k))
*@param Quad& represents first quad object x
*@param long long int& represents a value k
*@return bool true if x > Quad(k), otherwise false
**/
bool operator> (const Quad& x, const long long int& k);

/**This operator checks if first operand is greater than or equal to second operand (Quad(k))
*@param Quad& represents first quad object x
*@param long long int& represents a value k
*@return bool true if x >= Quad(k), otherwise false
**/
bool operator>= (const Quad& x, const long long int& k);

/**This operator checks if first operand is equal to second operand (Quad(k))
*@param Quad& represents first quad object x
*@param long long int& represents a value k
*@return bool true if x == Quad(k), otherwise false
**/
bool operator== (const Quad& x, const long long int& k);

/**This operator checks if first operand is equal to second operand (Quad(k))
*@param Quad& represents first quad object x
*@param long long int& represents a value k
*@return bool true if x != Quad(k), otherwise false
**/
bool operator!= (const Quad& x, const long long int& k);

/**This operator checks if first operand (Quad(k)) is lesser than second operand x
*@param long long int& represents a value k
*@param Quad& represents quad object x
*@return bool true if Quad(k) < x, otherwise false
**/
bool operator< (const long long int& k, const Quad& x);

/**This operator checks if first operand (Quad(k)) is lesser than second operand x
*@param long long int& represents a value k
*@param Quad& represents quad object x
*@return bool true if Quad(k) <= x, otherwise false
**/
bool operator<= (const long long int& k, const Quad& x);

/**This operator checks if first operand (Quad(k)) is greater than second operand x
*@param long long int& represents a value k
*@param Quad& represents quad object x
*@return bool true if Quad(k) > x, otherwise false
**/
bool operator> (const long long int& k, const Quad& x);

/**This operator checks if first operand (Quad(k)) is greater than or equal to second operand x
*@param long long int& represents a value k
*@param Quad& represents quad object x
*@return bool true if Quad(k) >= x, otherwise false
**/
bool operator>= (const long long int& k, const Quad& x);

/**This operator checks if first operand (Quad(k)) is equal to second operand x
*@param long long int& represents a value k
*@param Quad& represents quad object x
*@return bool true if Quad(k) == x, otherwise false
**/
bool operator== (const long long int& k, const Quad& x);

/**This operator checks if first operand (Quad(k)) is equal to second operand x
*@param long long int& represents a value k
*@param Quad& represents quad object x
*@return bool true if Quad(k) != x, otherwise false
**/
bool operator!= (const long long int& k, const Quad& x);


/**XOR operator overload
*@return Quad represents the result from raising x to the power k
**/
Quad operator^ (const Quad& x, const int& k);
#endif
