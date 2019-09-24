/**The purpose of this file is to practice STL library containers, iterator, and
*containers. Functions are implemented to check if a string os palindrome or not,
*find the second largest element in a container, count number of strings having length n,
*find the frequency of each character in a string input, and sort strings according to
*increasing lengths and lexicographical order.
**/
#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>
#include<vector>
#include<map>
#include<set>
#include<functional>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::remove_copy_if;
using std::transform;
using std::equal;
using std::insert_iterator;
using std::map;
using std::for_each;
using std::count_if;

/**Function to check if a string is palindrome
*@param string phrase represents input string
*@return bool represents true when string is palindrome, otherwise false
**/
bool is_palindrome(const std::string& phrase)
{
	string temp;

	remove_copy_if(phrase.begin(), phrase.end(), insert_iterator<string>(temp, temp.begin()), [](char ch) -> bool {
		if (!isalpha(ch)) {
			return true;
		}
		return false;
	}
	);

	transform(temp.begin(), temp.end(), temp.begin(), [](char ch) {return tolower(ch); });

	return equal(temp.begin(), temp.begin() + temp.size() / 2, temp.rbegin());
}

/**Function to test the is_palindrome function.
**/
void test_is_palindrome()
{
	std::string str_i = std::string("Was it a car or a cat I saw?");
	std::string str_u = std::string("Was it a car or a cat U saw?");
	cout << "the phrase \"" + str_i + "\" is " +
		(is_palindrome(str_i) ? "" : "not ") + "a palindrome \n";
	cout << "the phrase \"" + str_u + "\" is " +
		(is_palindrome(str_u) ? "" : "not ") + "a palindrome \n";
}


/**Function to find the second largest element in a container
*@param start represents the start of iterator
*@param finish represents the end of the iterator
*@return pair<Iterator,bool> represents iterator to second max element when bool is true,
*otherwise false represents finish when there are no elements and iterator to start element when
*all the elements are the same.
**/
template <class Iterator > // template header
std::pair < Iterator, bool > // function template return type
second_max(Iterator start, Iterator finish) // function signature
{
	if (start == finish) {
		return std::make_pair(finish, false);
	}
	auto firstMax{ start };
	auto secondMax{ start };
	for (Iterator it{ start }; it != finish; it++) {
		if (*it > * firstMax) {
			secondMax = firstMax;
			firstMax = it;
		}
		else if (*firstMax == *secondMax) {
			if (*secondMax > * it) {
				secondMax = it;
			}
		}
		else if (*it > * secondMax && *it < *firstMax) {
			secondMax = it;
		}
	}

	if (*firstMax != *secondMax) {
		return std::make_pair(secondMax, true);
	}
	else {
		return std::make_pair(start, false);
	}
}

/**Function to test the second_max function
*@param vec represents the input vector of int
**/
void test_second_max(std::vector <int > vec)
{
	// note : auto in the following statement is deduced as
	// std :: pair <std :: vector <int >:: iterator , bool >
	auto retval = second_max(vec.begin(), vec.end());
	if (retval.second)
	{
		cout << "The second largest element in vec is "
			<< *retval.first << endl;
	}
	else
	{
		if (retval.first == vec.end())
			cout << "List empty , no elements \n";
		else
			cout << "Container's elements are all equal to "
			<< *retval.first << endl;
	}
}

/**Function to count strings of length n using lambda
*@param &vecstr represents reference to a vector of strings
*@param n represents the length of string as int
*@return int represents the count of strings having length n
**/
int testCountStringLambda(const std::vector<string>& vecstr, int n)
{
	auto countStringLambda = [n](string str) -> bool {
		if (str.length() == n) {
			return true;
		}
		return false;
	};
	int result{ 0 };
	result = count_if(vecstr.begin(), vecstr.end(), countStringLambda);
	return result;
}

/**This class is used to create a function object for count_if function
**/
class StringFunctor {
	/**Represents the length of string
	**/
	int n;
public:
	/**Constructor initializes the value of n
	**/
	StringFunctor(int n) :n{ n } {}

	/**Function call operator overload
	*@param &str represents a reference to a constant string
	*@bool represents true if length of str is equal to n, otherwise false
	**/
	bool operator() (const string& str) {
		if (str.length() == n) {
			return true;
		}
		return false;
	}
};

/**Function to count strings of length n using function objects
*@param &vecstr represents reference to a vector of strings
*@param n represents the length of string as int
*@return int represents the count of strings having length n
**/
int testCountStringFunctor(const std::vector<string>& vecstr, int n)
{
	int result{ 0 };
	StringFunctor countStringFunctor{ n };
	result = count_if(vecstr.begin(), vecstr.end(), countStringFunctor);
	return result;
}

/**Function to check if length of string is equal to n
*@param &str represents reference to a constant string
*@param n represents the length of string
*@bool represents true if length of str is equal to n, otherwise false
**/
bool isStringOfLength_N(const string& str, string::size_type n) {
	return str.size() == n;
}

/**Function to count strings of length n using free function
*@param &vecstr represents reference to a constant vector of strings
*@param n represents the length of string as constant int
*@return int represents the count of strings having length n
**/
int testCountStringFreeFun(const std::vector<string>& vecstr, const int n) {
	using namespace std::placeholders;
	int result{ 0 };
	result = count_if(vecstr.begin(), vecstr.end(), std::bind(isStringOfLength_N, _1, n));
	return result;
}

/**Function reads a string of any number of characters from keyboard and
*counts the frequency of each character(except whitespace).
**/
void charFrequency()
{
	cout << "Enter one or more lines of text." << endl
		<< "To end input press Ctrl-Z in Windows and Ctrl-D in Linux" << endl;
	map<char, int, std::less<char>> freqMap;
	std::istream_iterator<char> start{ cin }, finish{};
	for_each(start, finish, [&freqMap](char ch) {
		if (!isspace(ch))
			++freqMap[ch];
	}
	);

	for (map<char, int, std::less<char>>::const_iterator itr = freqMap.begin(); itr != freqMap.end(); ++itr) {
		cout << itr->first << " " << (*itr).second << endl;
	}
}

/**This class is used to implement my own comparator
**/
class MyComparator
{
public:
	/**Function call operator overload
	*@param s1 represents reference to first constant string
	*@param s2 represents reference to second constant string
	*@return bool, ( s1 < s2 ) if s1 and s2 have the same length;
	*otherwise, returns (s1.size() < s2.size()).
	**/
	bool operator() (const std::string& s1, const std::string& s2) const
	{
		if (s1.size() == s2.size()) return s1 < s2;
		else return s1.size() < s2.size();
	}
};

/**Function to sort	a vector of strings according to increasing lengths
*and lexicographical order
**/
void multisetUsingMyComparator()
{
	std::multiset <std::string, MyComparator> strSet; // an empty set
	// a set that uses the default std :: less <int > to sort the set elements
	std::vector <std::string > vec{ "C", "BB", "A", "CC", "A", "B",
		 "BB", "A", "D", "CC", "DDD", "AAA" };

	// copy the vector elements to our set.
	// We must use a general (not front or back) inserter
	// (set does not have push_front or push_back members ,
	// so we can't use front or back inserter)
	std::copy(vec.begin(), vec.end(), // source container range
		std::inserter(strSet, strSet.begin())); // general inserter

		// create an ostream_iterator for writing to cout ,
		// using a space " " as a separator
	std::ostream_iterator <std::string > out(cout, " ");

	// output the set elements to cout separating them with a space
	std::copy(strSet.begin(), strSet.end(), out);
}

/**Main function to practice the STL library containers, iterators, and
algorithms using functions defined above in this file.
*@return int represents 0 when exit successfully, otherwise non-zero
**/
int main()
{	// problem 1:
	test_is_palindrome();
	cout << "\n";
	// problem 2:
	std::vector <int > v1{ 1 }; // one element
	test_second_max(v1);
	std::vector <int > v2{ 1, 1 }; // all elements equal
	test_second_max(v2);
	std::vector <int > v3{ 1, 1, 3, 3, 7, 7 }; // at least with two distict elements
	test_second_max(v3);
	cout << "\n";
	//// problem 3:
	std::vector <std::string > vecstr
	{ "count_if", "Returns", "the", "number", "of", "elements", "in", "the",
	"range", "[first", "last)", "for", "which", "pred", "is", "true."
	};
	cout << testCountStringLambda(vecstr, 5) << endl;

	cout << testCountStringFreeFun(vecstr, 5) << endl;

	cout << testCountStringFunctor(vecstr, 5) << endl;
	cout << "\n";
	//problem 4:
	charFrequency();
	cout << "\n";
	// problem 5:
	multisetUsingMyComparator();
	cout << "\n";
	return 0;
}

