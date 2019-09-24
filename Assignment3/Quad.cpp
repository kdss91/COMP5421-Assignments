#include "Quad.h"

/**Constructor used to initialize contents of quad number array.
*@param long long int x1 represents numerator of real part
*@param long long int x2 represents denominator of real part
*@param long long int x3 represents numerator of quad part
*@param long long int x4 represents denominator of quad part
**/
Quad::Quad(long long int x1, long long int x2, long long int x3, long long int x4) :quadNum{ { x1, x2, x3, x4 } } {
	if (x2 == 0 || x4 == 0) {
		throw invalid_argument("Either x2 or x4 is zero. Quad cannot be created.");
	}

	standardize();
}

/**Add and assign operator overload
*@param Quad& represents right hand side quad object
*@return Quad& represents reference to the updated quad object
**/
Quad& Quad::operator+= (const Quad& rhs) {
	long long int x1{ quadNum[0] };
	long long int x2{ quadNum[1] };
	long long int x3{ quadNum[2] };
	long long int x4{ quadNum[3] };
	long long int y1{ rhs.getQuadNum()[0] };
	long long int y2{ rhs.getQuadNum()[1] };
	long long int y3{ rhs.getQuadNum()[2] };
	long long int y4{ rhs.getQuadNum()[3] };

	quadNum[0] = (x1 * y2) + (x2 * y1);
	quadNum[1] = x2 * y2;
	quadNum[2] = (x3 * y4) + (x4 * y3);
	quadNum[3] = x4 * y4;

	standardize();

	return *this;
}

/**Subtract and assign operator overload
*@param Quad& represents right hand side quad object
*@return Quad& represents reference to the updated quad object
**/
Quad& Quad::operator-= (const Quad& rhs) {
	long long int x1{ quadNum[0] };
	long long int x2{ quadNum[1] };
	long long int x3{ quadNum[2] };
	long long int x4{ quadNum[3] };
	long long int y1{ rhs.getQuadNum()[0] };
	long long int y2{ rhs.getQuadNum()[1] };
	long long int y3{ rhs.getQuadNum()[2] };
	long long int y4{ rhs.getQuadNum()[3] };

	quadNum[0] = (x1 * y2) - (x2 * y1);
	quadNum[1] = x2 * y2;
	quadNum[2] = (x3 * y4) - (x4 * y3);
	quadNum[3] = x4 * y4;

	standardize();

	return *this;

}


/**Multiply and assign operator overload
*@param Quad& represents right hand side quad object
*@return Quad& represents reference to the updated quad object
**/
Quad& Quad::operator*= (const Quad& rhs) {
	long long int x1{ quadNum[0] };
	long long int x2{ quadNum[1] };
	long long int x3{ quadNum[2] };
	long long int x4{ quadNum[3] };
	long long int y1{ rhs.getQuadNum()[0] };
	long long int y2{ rhs.getQuadNum()[1] };
	long long int y3{ rhs.getQuadNum()[2] };
	long long int y4{ rhs.getQuadNum()[3] };

	quadNum[0] = (x1 * y1 * x4 * y4) + (2 * x3 * y3 * x2 * y2);
	quadNum[1] = x2 * y2 * x4 * y4;
	quadNum[2] = (x1 * y3 * y2 * x4) + (y1 * x3 * x2 * y4);
	quadNum[3] = x2 * y2 * x4 * y4;

	standardize();

	return *this;

}

/**Divide and assign operator overload
*@param Quad& represents right hand side quad object
*@return Quad& represents reference to the updated quad object
**/
Quad& Quad::operator/= (const Quad& rhs) {
	Quad yInv = rhs.inverse();

	long long int y1Inv{ yInv.getQuadNum()[0] };
	long long int y2Inv{ yInv.getQuadNum()[1] };
	long long int y3Inv{ yInv.getQuadNum()[2] };
	long long int y4Inv{ yInv.getQuadNum()[3] };

	long long int x1{ quadNum[0] };
	long long int x2{ quadNum[1] };
	long long int x3{ quadNum[2] };
	long long int x4{ quadNum[3] };

	quadNum[0] = (x1 * y1Inv * x4 * y4Inv) + (2 * x3 * y3Inv * x2 * y2Inv);
	quadNum[1] = x2 * y2Inv * x4 * y4Inv;
	quadNum[2] = (x1 * y3Inv * y2Inv * x4) + (y1Inv * x3 * x2 * y4Inv);
	quadNum[3] = x2 * y2Inv * x4 * y4Inv;

	standardize();

	return *this;
}

/**Add and assign operator overload
*@param long long int& represents right hand side long long int
*@return Quad& represents reference to the updated quad object
**/
Quad& Quad::operator+= (const long long int& rhs) {
	quadNum[0] += rhs * quadNum[1];
	standardize();

	return *this;
}

/**Subtract and assign operator overload
*@param long long int& represents right hand side long long int
*@return Quad& represents reference to the updated quad object
**/
Quad& Quad::operator-= (const long long int& rhs) {
	quadNum[0] -= rhs * quadNum[1];
	standardize();

	return *this;
}

/**Multiply and assign operator overload
*@param long long int& represents right hand side long long int
*@return Quad& represents reference to the updated quad object
**/
Quad& Quad::operator*= (const long long int& rhs) {
	quadNum[0] = rhs * quadNum[0];
	quadNum[2] = rhs * quadNum[2];
	standardize();

	return *this;
}

/**Divide and assign operator overload
*@param long long int& represents right hand side long long int
*@return Quad& represents reference to the updated quad object
**/
Quad& Quad::operator/= (const long long int& rhs) {
	quadNum[1] = rhs * quadNum[1];
	quadNum[3] = rhs * quadNum[3];
	standardize();

	return *this;
}

/**Pre increment operator overload
*return Quad& represents the updated quad object
**/
Quad& Quad::operator++ () {
	*this += 1;

	return *this;
}


/**Post increment operator overload
*param int represents a zero value
*return Quad represents the updated quad object
**/
Quad Quad::operator++ (int tmp) {
	Quad tmpQuad{ *this };
	++(*this);

	return tmpQuad;
}

/**Pre decrement operator overload
*return Quad& represents the updated quad object
**/
Quad& Quad::operator-- () {
	*this -= 1;

	return *this;
}

/**Post decrement operator overload
*param int represents a zero value
*return Quad represents the updated quad object
**/
Quad Quad::operator-- (int tmp) {
	Quad tmpQuad{ *this };
	--(*this);

	return tmpQuad;
}

/**Unary plus operator implementation
*@return Quad& represents reference to the resulting quad object
**/
Quad& Quad::operator+ () {
	return *this;
}

/**Unary minus operator implementation
*@return Quad& represents reference to the resulting quad object
**/
Quad& Quad::operator- () {
	quadNum[0] = -quadNum[0];
	quadNum[2] = -quadNum[2];

	return *this;
}

/**Non-const version of subscript operator overload
*@param int represents position element
*@return long long int& represents reference to value of element at position
**/
long long int& Quad::operator[] (const int& pos) {
	if (pos < 1 || pos > 4) {
		throw invalid_argument("index out of bounds");
	}

	return quadNum[pos - 1];
}

/**Const version of subscript operator overload
*@param int represents position element
*@return long long int& represents reference to value of element at position
**/
const long long int& Quad::operator[] (const int& pos) const {
	if (pos < 1 || pos > 4) {
		throw invalid_argument("index out of bounds");
	}

	return quadNum[pos - 1];
}

/**Function call operator overload
*@return double represents the absolute value
**/
double Quad::operator() () {
	return absoluteValue();
}

/**Norm of quad number
*return double represents norm of x
**/
double Quad::norm() const {
	return (((double)(quadNum[0] * quadNum[0]) / (quadNum[1] * quadNum[1])) + ((double)(quadNum[2] * quadNum[2]) / (quadNum[3] * quadNum[3])));
}

/**Absolute value of quad number
*@return double represents absolute value of x
**/
double Quad::absoluteValue() {
	return sqrt(norm());
}

/**Find if quad is similar to another quad
*@param Quad& represents quad object
*@return bool true when similar, otherwise false
**/
bool Quad::isSimilar(const Quad& y) {
	long long int x1{ quadNum[0] };
	long long int x2{ quadNum[1] };
	long long int x3{ quadNum[2] };
	long long int x4{ quadNum[3] };
	long long int y1{ y.getQuadNum()[0] };
	long long int y2{ y.getQuadNum()[1] };
	long long int y3{ y.getQuadNum()[2] };
	long long int y4{ y.getQuadNum()[3] };

	return ((x1 * y2 == y1 * x2) && (x3 * y4 == y3 * x4));
}

/**Find if quad is similar Quad(k)
*@param long long int& represents a number k
*@return bool true when similar, otherwise false
**/
bool Quad::isSimilar(const long long int& k) {
	return isSimilar(Quad(k));
}

/**Getter to fetch the quad number
*@return an array of size four
**/
array<long long int, 4> Quad::getQuadNum() const {
	return this->quadNum;
}

/**Setter to set the quad number
*@param array of size four
**/
void Quad::setQuadNum(array<long long int, 4> quadNum) {
	this->quadNum = quadNum;
}

/**Finds inverse of current object
*@return Quad represents inverse of quad number
**/
Quad Quad::inverse() const {
	long long int x1{ quadNum[0] };
	long long int x2{ quadNum[1] };
	long long int x3{ quadNum[2] };
	long long int x4{ quadNum[3] };

	long long int x1Inv{ x1 * x2 * x4 * x4 };
	long long int x2Inv{ x1 * x1 * x4 * x4 - 2 * x2 * x2 * x3 * x3 };
	long long int x3Inv{ -x2 * x2 * x3 * x4 };
	long long int x4Inv{ x1 * x1 * x4 * x4 - 2 * x2 * x2 * x3 * x3 };

	if (x2Inv == 0) {
		throw invalid_argument("Alpha is zero. Inverse is not possible.");
	}

	Quad invQuad(x1Inv, x2Inv, x3Inv, x4Inv);

	return invQuad;
}

/**Normalizes current quad number
**/
void Quad::normalize() {
	if (quadNum[1] < 0) {
		quadNum[0] = -quadNum[0];
		quadNum[1] = -quadNum[1];
	}

	if (quadNum[3] < 0) {
		quadNum[2] = -quadNum[2];
		quadNum[3] = -quadNum[3];
	}
}

/**Reduces current quad number
**/
void Quad::reduce() {
	long long int gcd1{ gcd(quadNum[0], quadNum[1]) };
	long long int gcd2{ gcd(quadNum[2], quadNum[3]) };
	quadNum[0] /= gcd1;
	quadNum[1] /= gcd1;
	quadNum[2] /= gcd2;
	quadNum[3] /= gcd2;
}

/**It calculates the gcd of two numbers
*@param long long int x represents the first number
*@param long long int y represents the second number
@return long long int represents the gcd result
**/
long long int Quad::gcd(long long int x, long long int y)
{
	x = abs(x);
	y = abs(y);
	long long int z{ x % y };
	for (; z != 0;)
	{
		x = y;
		y = z;
		z = x % y;
	}
	return y;
}

/**Standardizes current quad number by
*performing both reduce and normalize
**/
void Quad::standardize() {
	reduce();
	normalize();
}

/**Finds conjugate of current quad number x
*@return Quad represents the conjugate of x
**/
Quad Quad::conjugate() {
	long long int x1{ quadNum[0] };
	long long int x2{ quadNum[1] };
	long long int x3{ -quadNum[2] };
	long long int x4{ quadNum[3] };

	if (x2 == 0 || x4 == 0) {
		throw invalid_argument("Either x2 or x4 is zero. Conjugate is not possible.");
	}
	Quad quad(x1, x2, x3, x4);

	return quad;
}

/**Implementation for stream insertion operator overload
*@param out ostream object passed as reference
*@param quad constant Quad object passed as reference
*@return ostream object returned as reference to allow multiple insertions at once
**/
ostream& operator<< (ostream& out, const Quad& quad) {
	out << "[" << quad.getQuadNum()[0] << "," << quad.getQuadNum()[1] << "," << quad.getQuadNum()[2] << "," << quad.getQuadNum()[3] << "]";
	return out;
}

/**Implementation for stream extraction operator overload.
*@param in istream object passed as reference
*@param quad Quad object passed as reference
*@return istream object returned as reference to allow multiple extractions at once
**/
istream& operator>> (istream& in, Quad& quad) {
	cout << "About to create the quad [a, b, c, d]" << endl;
	cout << "Enter four numbers a, b, c, d, in that order:" << endl;
	long long int x1, x2, x3, x4;
	in >> x1 >> x2 >> x3 >> x4;
	quad.setQuadNum({ x1, x2, x3, x4 });
	quad.standardize();
	return in;
}

/**Addition of two Quad objects
*@param Quad& represents first quad object x
*@param Quad& represents second quad object y
*@return Quad represents the resultant Quad object
**/
Quad operator+ (const Quad& x, const Quad& y) {
	long long int x1{ x.getQuadNum()[0] };
	long long int x2{ x.getQuadNum()[1] };
	long long int x3{ x.getQuadNum()[2] };
	long long int x4{ x.getQuadNum()[3] };
	long long int y1{ y.getQuadNum()[0] };
	long long int y2{ y.getQuadNum()[1] };
	long long int y3{ y.getQuadNum()[2] };
	long long int y4{ y.getQuadNum()[3] };

	Quad tmpQuad((x1 * y2) + (x2 * y1), x2 * y2, (x3 * y4) + (x4 * y3), x4 * y4);
	return tmpQuad;
}

/**Subtraction of two Quad objects
*@param Quad& represents first quad object x
*@param Quad& represents second quad object y
*@return Quad represents the resultant Quad object
**/
Quad operator- (const Quad& x, const Quad& y) {
	long long int x1{ x.getQuadNum()[0] };
	long long int x2{ x.getQuadNum()[1] };
	long long int x3{ x.getQuadNum()[2] };
	long long int x4{ x.getQuadNum()[3] };
	long long int y1{ y.getQuadNum()[0] };
	long long int y2{ y.getQuadNum()[1] };
	long long int y3{ y.getQuadNum()[2] };
	long long int y4{ y.getQuadNum()[3] };

	Quad tmpQuad((x1 * y2) - (x2 * y1), x2 * y2, (x3 * y4) - (x4 * y3), x4 * y4);
	return tmpQuad;
}

/**Multiplication of two Quad objects
*@param Quad& represents first quad object x
*@param Quad& represents second quad object y
*@return Quad represents the resultant Quad object
**/
Quad operator* (const Quad& x, const Quad& y) {
	long long int x1{ x.getQuadNum()[0] };
	long long int x2{ x.getQuadNum()[1] };
	long long int x3{ x.getQuadNum()[2] };
	long long int x4{ x.getQuadNum()[3] };
	long long int y1{ y.getQuadNum()[0] };
	long long int y2{ y.getQuadNum()[1] };
	long long int y3{ y.getQuadNum()[2] };
	long long int y4{ y.getQuadNum()[3] };

	Quad tmpQuad((x1 * y1 * x4 * y4) + (2 * x3 * y3 * x2 * y2), x2 * y2 * x4 * y4, (x1 * y3 * y2 * x4) + (y1 * x3 * x2 * y4), x2 * y2 * x4 * y4);
	return tmpQuad;
}

/**Division of two Quad objects
*@param Quad& represents first quad object x
*@param Quad& represents second quad object y
*@return Quad represents the resultant Quad object
**/
Quad operator/ (const Quad& x, const Quad& y) {
	Quad yInv = y.inverse();

	long long int y1Inv{ yInv.getQuadNum()[0] };
	long long int y2Inv{ yInv.getQuadNum()[1] };
	long long int y3Inv{ yInv.getQuadNum()[2] };
	long long int y4Inv{ yInv.getQuadNum()[3] };

	long long int x1{ x.getQuadNum()[0] };
	long long int x2{ x.getQuadNum()[1] };
	long long int x3{ x.getQuadNum()[2] };
	long long int x4{ x.getQuadNum()[3] };


	Quad tmpQuad((x1 * y1Inv * x4 * y4Inv) + (2 * x3 * y3Inv * x2 * y2Inv), x2 * y2Inv * x4 * y4Inv, (x1 * y3Inv * y2Inv * x4) + (y1Inv * x3 * x2 * y4Inv),
		x2 * y2Inv * x4 * y4Inv);

	return tmpQuad;

}

/**Addition of Quad object and long long int value
*@param Quad& represents first quad object x
*@param long long int& represents a value
*@return Quad represents the resultant Quad object
**/
Quad operator+ (const Quad& x, const long long int& k) {
	long long int x1{ x.getQuadNum()[0] };
	long long int x2{ x.getQuadNum()[1] };
	long long int x3{ x.getQuadNum()[2] };
	long long int x4{ x.getQuadNum()[3] };

	Quad tmpQuad(x1 + (k * x2), x2, x3, x4);

	return tmpQuad;
}

/**Subtraction of Quad object and long long int value
*@param Quad& represents first quad object x
*@param long long int& represents a value
*@return Quad represents the resultant Quad object
**/
Quad operator- (const Quad& x, const long long int& k) {
	long long int x1{ x.getQuadNum()[0] };
	long long int x2{ x.getQuadNum()[1] };
	long long int x3{ x.getQuadNum()[2] };
	long long int x4{ x.getQuadNum()[3] };

	Quad tmpQuad(x1 - (k * x2), x2, x3, x4);

	return tmpQuad;
}

/**Multiplication of Quad object and long long int value
*@param Quad& represents first quad object x
*@param long long int& represents a value
*@return Quad represents the resultant Quad object
**/
Quad operator* (const Quad& x, const long long int& k) {
	long long int x1{ x.getQuadNum()[0] };
	long long int x2{ x.getQuadNum()[1] };
	long long int x3{ x.getQuadNum()[2] };
	long long int x4{ x.getQuadNum()[3] };

	Quad tmpQuad(k * x1, x2, k * x3, x4);
	return tmpQuad;
}

/**Division of Quad object and long long int value
*@param Quad& represents first quad object x
*@param long long int& represents a value
*@return Quad represents the resultant Quad object
**/
Quad operator/ (const Quad& x, const long long int& k) {
	long long int x1{ x.getQuadNum()[0] };
	long long int x2{ x.getQuadNum()[1] };
	long long int x3{ x.getQuadNum()[2] };
	long long int x4{ x.getQuadNum()[3] };

	Quad tmpQuad(x1, k * x2, x3, k * x4);
	return tmpQuad;
}

/**Addition of long long int value and Quad object
*@param long long int& represents a value
*@param Quad& represents first quad object x
*@return Quad represents the resultant Quad object
**/
Quad operator+ (const long long int& k, const Quad& x) {
	long long int x1{ x.getQuadNum()[0] };
	long long int x2{ x.getQuadNum()[1] };
	long long int x3{ x.getQuadNum()[2] };
	long long int x4{ x.getQuadNum()[3] };

	Quad tmpQuad(x1 + (k * x2), x2, x3, x4);

	return tmpQuad;
}

/**Subtraction of long long int value and Quad object
*@param long long int& represents a value
*@param Quad& represents first quad object x
*@return Quad represents the resultant Quad object
**/
Quad operator- (const long long int& k, const Quad& x) {
	long long int x1{ x.getQuadNum()[0] };
	long long int x2{ x.getQuadNum()[1] };
	long long int x3{ x.getQuadNum()[2] };
	long long int x4{ x.getQuadNum()[3] };

	Quad tmpQuad(-x1 + (k * x2), x2, -x3, x4);

	return tmpQuad;
}

/**Multiplication of long long int value and Quad object
*@param long long int& represents a value
*@param Quad& represents first quad object x
*@return Quad represents the resultant Quad object
**/
Quad operator* (const long long int& k, const Quad& x) {
	long long int x1{ x.getQuadNum()[0] };
	long long int x2{ x.getQuadNum()[1] };
	long long int x3{ x.getQuadNum()[2] };
	long long int x4{ x.getQuadNum()[3] };

	Quad tmpQuad(k * x1, x2, k * x3, x4);
	return tmpQuad;
}

/**Division of long long int value and Quad object
*@param long long int& represents a value
*@param Quad& represents first quad object x
*@return Quad represents the resultant Quad object
**/
Quad operator/ (const long long int& k, const Quad& x) {
	Quad xInv = x.inverse();

	long long int x1Inv{ xInv.getQuadNum()[0] };
	long long int x2Inv{ xInv.getQuadNum()[1] };
	long long int x3Inv{ xInv.getQuadNum()[2] };
	long long int x4Inv{ xInv.getQuadNum()[3] };

	if (x2Inv == 0) {
		cout << "Division not possible." << endl;
		return x;
	}

	Quad tmpQuad(k * x1Inv, x2Inv, k * x3Inv, x4Inv);
	return tmpQuad;
}

/**This operator checks if first operand is lesser than second operand
*@param Quad& represents first quad object x
*@param Quad& represents second quad object y
*@return bool true if x < y, otherwise false
**/
bool operator< (const Quad& x, const Quad& y) {
	return(x.norm() < y.norm());
}

/**This operator checks if first operand is less than or equal to second operand
*@param Quad& represents first quad object x
*@param Quad& represents second quad object y
*@return bool true if x <= y, otherwise false
**/
bool operator<= (const Quad& x, const Quad& y) {
	return(x.norm() <= y.norm());
}

/**This operator checks if first operand is greater than second operand
*@param Quad& represents first quad object x
*@param Quad& represents second quad object y
*@return bool true if x > y, otherwise false
**/
bool operator> (const Quad& x, const Quad& y) {
	return(x.norm() > y.norm());
}

/**This operator checks if first operand is greater than or equal to second operand
*@param Quad& represents first quad object x
*@param Quad& represents second quad object y
*@return bool true if x >= y, otherwise false
**/
bool operator>= (const Quad& x, const Quad& y) {
	return(x.norm() >= y.norm());
}

/**This operator checks if both operands are equal or not
*@param Quad& represents first quad object x
*@param Quad& represents second quad object y
*@return bool true if x == y, otherwise false
**/
bool operator== (const Quad& x, const Quad& y) {
	long long int x1{ x.getQuadNum()[0] };
	long long int x2{ x.getQuadNum()[1] };
	long long int x3{ x.getQuadNum()[2] };
	long long int x4{ x.getQuadNum()[3] };
	long long int y1{ y.getQuadNum()[0] };
	long long int y2{ y.getQuadNum()[1] };
	long long int y3{ y.getQuadNum()[2] };
	long long int y4{ y.getQuadNum()[3] };

	return(x1 == y1 && x2 == y2 && x3 == y3 && x4 == y4);
}

/**This operator checks if both operands are equal or not
*@param Quad& represents first quad object x
*@param Quad& represents second quad object y
*@return bool true if x != y, otherwise false
**/
bool operator!= (const Quad& x, const Quad& y) {
	return (!(x == y));
}

/**This operator checks if first operand is lesser than second operand (Quad(k))
*@param Quad& represents first quad object x
*@param long long int& represents a value k
*@return bool true if x < Quad(k), otherwise false
**/
bool operator< (const Quad& x, const long long int& k) {
	const Quad tmpQuad{ k };
	return (x.norm() < tmpQuad.norm());
}

/**This operator checks if first operand is less than or equal to second operand (Quad(k))
*@param Quad& represents first quad object x
*@param long long int& represents a value k
*@return bool true if x <= Quad(k), otherwise false
**/
bool operator<= (const Quad& x, const long long int& k) {
	const Quad tmpQuad{ k };
	return (x.norm() <= tmpQuad.norm());
}

/**This operator checks if first operand is greater than second operand (Quad(k))
*@param Quad& represents first quad object x
*@param long long int& represents a value k
*@return bool true if x > Quad(k), otherwise false
**/
bool operator> (const Quad& x, const long long int& k) {
	const Quad tmpQuad{ k };
	return (x.norm() > tmpQuad.norm());
}

/**This operator checks if first operand is greater than or equal to second operand (Quad(k))
*@param Quad& represents first quad object x
*@param long long int& represents a value k
*@return bool true if x >= Quad(k), otherwise false
**/
bool operator>= (const Quad& x, const long long int& k) {
	const Quad tmpQuad{ k };
	return (x.norm() >= tmpQuad.norm());
}

/**This operator checks if first operand is equal to second operand (Quad(k))
*@param Quad& represents first quad object x
*@param long long int& represents a value k
*@return bool true if x == Quad(k), otherwise false
**/
bool operator== (const Quad& x, const long long int& k) {
	const Quad tmpQuad{ k };
	return (x == tmpQuad);
}

/**This operator checks if first operand is equal to second operand (Quad(k))
*@param Quad& represents first quad object x
*@param long long int& represents a value k
*@return bool true if x != Quad(k), otherwise false
**/
bool operator!= (const Quad& x, const long long int& k) {
	return (!(x == k));
}

/**This operator checks if first operand (Quad(k)) is lesser than second operand x
*@param long long int& represents a value k
*@param Quad& represents quad object x
*@return bool true if Quad(k) < x, otherwise false
**/
bool operator< (const long long int& k, const Quad& x) {
	const Quad tmpQuad{ k };
	return (tmpQuad.norm() < x.norm());
}

/**This operator checks if first operand (Quad(k)) is lesser than second operand x
*@param long long int& represents a value k
*@param Quad& represents quad object x
*@return bool true if Quad(k) <= x, otherwise false
**/
bool operator<= (const long long int& k, const Quad& x) {
	const Quad tmpQuad{ k };
	return (tmpQuad.norm() <= x.norm());
}

/**This operator checks if first operand (Quad(k)) is greater than second operand x
*@param long long int& represents a value k
*@param Quad& represents quad object x
*@return bool true if Quad(k) > x, otherwise false
**/
bool operator> (const long long int& k, const Quad& x) {
	const Quad tmpQuad{ k };
	return (tmpQuad.norm() > x.norm());
}

/**This operator checks if first operand (Quad(k)) is greater than or equal to second operand x
*@param long long int& represents a value k
*@param Quad& represents quad object x
*@return bool true if Quad(k) >= x, otherwise false
**/
bool operator>= (const long long int& k, const Quad& x) {
	const Quad tmpQuad{ k };
	return (tmpQuad.norm() >= x.norm());
}

/**This operator checks if first operand (Quad(k)) is equal to second operand x
*@param long long int& represents a value k
*@param Quad& represents quad object x
*@return bool true if Quad(k) == x, otherwise false
**/
bool operator== (const long long int& k, const Quad& x) {
	const Quad tmpQuad{ k };
	return (tmpQuad == x);
}

/**This operator checks if first operand (Quad(k)) is equal to second operand x
*@param long long int& represents a value k
*@param Quad& represents quad object x
*@return bool true if Quad(k) != x, otherwise false
**/
bool operator!= (const long long int& k, const Quad& x) {
	return (!(k == x));
}

/**XOR operator overload
*@return Quad represents the result from raising x to the power k
**/
Quad operator^ (const Quad& x, const int& k) {
	if (x.getQuadNum()[0] == 0 && x.getQuadNum()[2] == 0) {
		return Quad{ 0,1,0,1 };
	}

	if (k == 0) {
		return Quad{ 1,1,0,1 };
	}
	else if (k < 0) {
		Quad tmpQuad{ x.inverse() };
		Quad resultQuad{ x.inverse() };
		int count{ k + 1 };
		while (count < 0) {
			resultQuad = resultQuad * tmpQuad;
			++count;
		}
		return resultQuad;

	}
	else {
		Quad tmpQuad{ x };
		Quad resultQuad{ x };
		int count{ k - 1 };
		while (count > 0) {
			resultQuad = resultQuad * tmpQuad;
			--count;
		}
		return resultQuad;
	}
}

/**Convert quad object to double
*returns the absolute value
**/
Quad::operator double() {
	return absoluteValue();
}