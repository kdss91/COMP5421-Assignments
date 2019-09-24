#include "LineEd.h"

/**This map stores all the valid commands.
**/
map<string, int> LineEd::commands = {
	{"a",1},
	{"i",2},
	{"v",3},
	{"d",4},
	{"x",5},
	{"j",6},
	{"p",7},
	{"c",8},
	{"u",9},
	{"n",10},
	{"g",11},
	{"w",12},
	{"q",13}
};


/**Default constructor takes filename to be operated upon.
*@param string represents name of the file
**/
LineEd::LineEd(string filename) :filename{ filename }, currentLine{ 0 } {
	if (filename.empty()) {
		cout << "\"?\" [New File]" << endl;
		cout << "Entering command mode." << endl;
		cout << "? ";
		return;
	}

	std::ifstream ifs(filename, std::ifstream::in);

	if (ifs.is_open())
	{
		cout << "\"" << filename << "\" ";
		int lineno{ 0 };
		std::string line;
		while (getline(ifs, line)) // Read until end of file
		{
			buffer.push_back(line);
			++lineno;
		}
		cout << lineno << " lines" << endl;
		this->currentLine = lineno;
	}
	else {
		cout << "\"" << filename << "\" [New File]" << endl;
	}
	cout << "Entering command mode." << endl;
	cout << "? ";
}

/**It verifies that the command is valid. It performs command execution.
*@param string& represents command as a string
**/
void LineEd::runCommand(const string& command_line) {
	Command cmd{ command_line };
	if (buffer.empty()) {
		if (cmd.getSymbol().compare("a")==0 || cmd.getSymbol().compare("i") == 0 || cmd.getSymbol().compare("q") == 0 || (!clipboard.empty() && cmd.getSymbol().compare("v")==0)) {
		}
		else {
			if (isValidCommand(cmd.getSymbol())) {
				if (clipboard.empty()) {
					cout << "File empty. Must use one of I, A, Q commands." << endl;
					return;
				}
				else {
					cout << "File empty. Must use one of I, A, Q, V commands." << endl;
					return;
				}
			}
		}
	}

	if (!isValidCommand(cmd.getSymbol())) {
		cmd.setSymbolStatus(false);
		cmd.setStatus(false);
	}
	if (!cmd.getSymbolStatus()) {
		cout << "bad command: " << cmd.getSymbol() << endl;
		return;
	}
	else if (!cmd.getAdress1Status()) {
		cout << "bad address 1: " << cmd.getAddress1() << endl;
		return;
	}
	else if (!cmd.getAdress2Status()) {
		cout << "bad address 2: " << cmd.getAddress2() << endl;
		return;
	}
	verifyAddress(cmd);
	if (strcmp(cmd.getSymbol().c_str(), "a") == 0) {
		commandA();
	}
	else if (strcmp(cmd.getSymbol().c_str(), "i") == 0) {
		commandI(cmd);
	}
	else if (strcmp(cmd.getSymbol().c_str(), "v") == 0) {
		commandV(cmd);
	}
	else if (strcmp(cmd.getSymbol().c_str(), "d") == 0) {
		commandD(cmd);
	}
	else if (strcmp(cmd.getSymbol().c_str(), "x") == 0) {
		commandX(cmd);
	}
	else if (strcmp(cmd.getSymbol().c_str(), "j") == 0) {
		commandJ(cmd);
	}
	else if (strcmp(cmd.getSymbol().c_str(), "p") == 0) {
		commandP(cmd);
	}
	else if (strcmp(cmd.getSymbol().c_str(), "c") == 0) {
		commandC(cmd);
	}
	else if (strcmp(cmd.getSymbol().c_str(), "u") == 0) {
		commandU();
	}
	else if (strcmp(cmd.getSymbol().c_str(), "n") == 0) {
		commandN();
	}
	else if (strcmp(cmd.getSymbol().c_str(), "g") == 0) {
		commandG(cmd);
	}
	else if (strcmp(cmd.getSymbol().c_str(), "w") == 0) {
		commandW();
	}
	else if (strcmp(cmd.getSymbol().c_str(), "q") == 0) {
		commandQ();
	}
}

/**It takes commands from the user until user quits the program
**/
void LineEd::run() {
	string command_line;
	do {
		getline(cin, command_line);
		runCommand(command_line);
		if (strcmp(command_line.c_str(), "q") != 0)
			cout << "? ";
	} while (strcmp(command_line.c_str(), "q") != 0);
}

/**It converts a string representing line number to unsigned int.
*It includes checking for special characters '.' and '$'
*@param string represents line number
*return size_t represents line number as unsigned int
**/
size_t LineEd::findLineNumber(string number) {
	size_t tmp;
	if (number.compare(".") == 0) {
		tmp = this->currentLine;
	}
	else if (number.compare("$") == 0) {
		tmp = this->buffer.size();
	}
	else {
		tmp = stoi(number);
	}

	if (tmp <= 0) {
		return 1;
	}

	if (tmp > buffer.size()) {
		return buffer.size();
	}

	return tmp;
}

/**It verifies if the address is valid and corrects -ve or out of bound addresses.
*@param Command object represents a command
**/
void LineEd::verifyAddress(Command& cmd) {
	if (cmd.checkIfStringIsNumber(cmd.getAddress1())) {
		int number1{ stoi(cmd.getAddress1()) };
		if (number1 <= 0) {
			cmd.setAddress1("1");
		}
		else if (number1 > buffer.size()) {
			cmd.setAddress1(to_string(buffer.size()));
		}

		if (cmd.checkIfStringIsNumber(cmd.getAddress2())) {
			int number2{ stoi(cmd.getAddress2()) };
			if (number2 <= 0) {
				cmd.setAddress2("1");
			}
			else if (number2 > buffer.size()) {
				cmd.setAddress2(to_string(buffer.size()));
			}

			if (number1 > number2) {
				string tmp{ cmd.getAddress1() };
				cmd.setAddress1(cmd.getAddress2());
				cmd.setAddress2(tmp);
			}
		}
		else {
			if (cmd.getAddress2().compare(".") == 0) {
				if (number1 > this->currentLine) {
					string tmp{ cmd.getAddress1() };
					cmd.setAddress1(cmd.getAddress2());
					cmd.setAddress2(tmp);
				}
			}
		}
	}
	else {
		if (cmd.getAddress1().compare(".") == 0) {
			if (cmd.checkIfStringIsNumber(cmd.getAddress2())) {
				int number2{ stoi(cmd.getAddress2()) };
				if (number2 <= 0) {
					cmd.setAddress2("1");
				}
				else if (number2 > buffer.size()) {
					cmd.setAddress2(to_string(buffer.size()));
				}

				if (this->currentLine > number2) {
					string tmp{ cmd.getAddress1() };
					cmd.setAddress1(cmd.getAddress2());
					cmd.setAddress2(tmp);
				}
			}
		}
		else {
			if (cmd.checkIfStringIsNumber(cmd.getAddress2())) {
				int number2{ stoi(cmd.getAddress2()) };
				if (number2 <= 0) {
					cmd.setAddress2("1");
					number2 = 1;
				}
				if (number2 < buffer.size()) {
					string tmp{ cmd.getAddress1() };
					cmd.setAddress1(cmd.getAddress2());
					cmd.setAddress2(tmp);
				}
			}
			else {
				if (cmd.getAddress2().compare(".") == 0) {
					if (this->currentLine < buffer.size()) {
						string tmp{ cmd.getAddress1() };
						cmd.setAddress1(cmd.getAddress2());
						cmd.setAddress2(tmp);
					}
				}
			}
		}
	}
}

/**It prints the contents of the buffer elements in a range.
*@param int x represents starting line number
*@param int y represents ending line number
**/
void LineEd::print(int x, int y) {
	if (buffer.empty()) {
		return;
	}
	list<string>::iterator itr1;
	itr1 = buffer.begin();
	int pos{ x - 1 };
	int count1{ x };
	int count2{ y };
	while (pos > 0) {
		++itr1;
		--pos;
	}
	int diff{ count2 - count1 + 1 };
	int lineNumber{ x };
	while (diff > 0) {
		if (this->currentLine == lineNumber) {
			cout << lineNumber++ << "> " << *itr1 << endl;
		}
		else {
			cout << lineNumber++ << ": " << *itr1 << endl;
		}
		++itr1;
		--diff;
	}
}

/**It checks if the command is valid or not
*@param string represents a command
*@return bool true if command is valid, otherwise false
**/
bool LineEd::isValidCommand(string cmd) {
	if (LineEd::commands.find(cmd) != LineEd::commands.end()) {
		return true;
	}
	return false;
}


/**It implements the code for appending text to buffer
**/
void LineEd::commandA() {
	cout << "\nEntering input mode." << endl;
	string text;
	getline(cin, text);
	while (strcmp(text.c_str(), ".") != 0) {
		buffer.push_back(text);
		getline(cin, text);
	}
	this->currentLine = buffer.size();
	cout << "Entering command mode." << endl;
}

/**It implements the code for inserting text into the buffer
*@param Command represents the current command line object
**/
void LineEd::commandI(Command& cmd) {
	cout << "\nEntering input mode." << endl;
	size_t size{ buffer.size() };
	string line;
	list<string>::iterator it{ buffer.begin() };
	advance(it, findLineNumber(cmd.getAddress1()) - 1);
	int numOfLines{ 0 };
	while (getline(cin, line)) {
		if (line.compare(".") == 0) {
			break;
		}
		buffer.insert(it, line);
		numOfLines++;
	}
	if (size == 0) {
		this->currentLine = numOfLines;
	}
	else {
		this->currentLine = findLineNumber(cmd.getAddress1()) + numOfLines - 1;
	}
	cout << "Entering command mode." << endl;
}

/**It implements the code to paste text from the clipboard to the buffer
*@param Command represents the current command line object
**/
void LineEd::commandV(Command& cmd) {
	size_t size{ buffer.size() };
	list<string>::iterator it{ buffer.begin() };
	advance(it, findLineNumber(cmd.getAddress1()) - 1);
	int numOfLines{ 0 };
	for (string line : clipboard) {
		buffer.insert(it, line);
		numOfLines++;
	}
	clipboard.clear();
	if (size == 0) {
		this->currentLine = numOfLines;
	}
	else {
		this->currentLine = findLineNumber(cmd.getAddress1()) + numOfLines - 1;
	}
}

/**It implements the code to delete lines from the buffer
*@param Command represents the current command line object
**/
void LineEd::commandD(Command& cmd) {
	size_t size{ buffer.size() };
	if (size == 0) {
		return;
	}
	list<string>::iterator itr1;
	itr1 = buffer.begin();
	size_t pos{ findLineNumber(cmd.getAddress1()) - 1 };
	size_t count1{ findLineNumber(cmd.getAddress1()) };
	size_t count2{ findLineNumber(cmd.getAddress2()) };
	while (pos > 0) {
		++itr1;
		--pos;
	}
	size_t diff{ count2 - count1 + 1 };

	while (diff > 0) {
		itr1 = buffer.erase(itr1);
		--diff;
	}

	if (buffer.empty()) {
		this->currentLine = 0;
	}
	else if (count2 >= size) {
		this->currentLine = count1 - 1;
	}
	else {
		this->currentLine = count1;
	}
}

/**It implements the code to delete lines from the buffer
*@param Command represents the current command line object
**/
void LineEd::commandX(Command& cmd) {
	size_t size{ buffer.size() };
	if (size == 0) {
		return;
	}
	list<string>::iterator itr1;
	itr1 = buffer.begin();
	size_t pos{ findLineNumber(cmd.getAddress1()) - 1 };
	size_t count1{ findLineNumber(cmd.getAddress1()) };
	size_t count2{ findLineNumber(cmd.getAddress2()) };
	while (pos > 0) {
		++itr1;
		--pos;
	}
	size_t diff{ count2 - count1 + 1 };
	clipboard.clear();
	while (diff > 0) {
		clipboard.push_back(*itr1);
		itr1 = buffer.erase(itr1);
		--diff;
	}

	if (buffer.empty()) {
		this->currentLine = 0;
	}
	else if (count2 >= size) {
		this->currentLine = count1 - 1;
	}
	else {
		this->currentLine = count1;
	}
}

/**It implements the code to join the text from the specified range
*together on one line at some address
*@param Command represents the current command line object
**/
void LineEd::commandJ(Command& cmd) {
	size_t size{ buffer.size() };
	if (size == 0) {
		return;
	}
	list<string>::iterator itr1;
	itr1 = buffer.begin();
	size_t pos{ findLineNumber(cmd.getAddress1()) - 1 };
	size_t count1{ findLineNumber(cmd.getAddress1()) };
	size_t count2{ findLineNumber(cmd.getAddress2()) };
	while (pos > 0) {
		++itr1;
		--pos;
	}
	size_t diff{ count2 - count1 };
	string result;
	result += *itr1;
	++itr1;
	while (diff > 0) {
		result += *itr1;
		itr1 = buffer.erase(itr1);
		--diff;
	}

	itr1 = buffer.begin();
	pos = findLineNumber(cmd.getAddress1()) - 1;
	while (pos > 0) {
		++itr1;
		--pos;
	}
	*itr1 = result;
	this->currentLine = count1;
}

/**It implements the code to print the elements in some line range of the buffer
*@param Command represents the current command line object
**/
void LineEd::commandP(Command& cmd) {
	size_t adrs1{ findLineNumber(cmd.getAddress1()) };
	size_t adrs2{ findLineNumber(cmd.getAddress2()) };
	print(adrs1, adrs2);
}

/**It implements the code to replace text in some line range in the buffer
*@param Command represents the current command line object
**/
void LineEd::commandC(Command& cmd) {
	cout << "change? ";
	string searchString;
	getline(cin, searchString);
	cout << "    to? ";
	string replaceString;
	getline(cin, replaceString);
	size_t size{ buffer.size() };
	if (size == 0) {
		return;
	}
	list<string>::iterator itr1;
	itr1 = buffer.begin();
	size_t pos{ findLineNumber(cmd.getAddress1()) - 1 };
	size_t count1{ findLineNumber(cmd.getAddress1()) };
	size_t count2{ findLineNumber(cmd.getAddress2()) };
	while (pos > 0) {
		++itr1;
		--pos;
	}
	size_t diff{ count2 - count1 + 1 };
	bool flag{ false };
	size_t currentLine{ count1 };
	size_t lastChangedLine;
	while (diff > 0) {
		size_t position{ 0 };
		bool flag1{ false };
		while ((position = (*itr1).find(searchString, position)) != string::npos) {
			flag = true;
			flag1 = true;
			(*itr1).replace(position, searchString.length(), replaceString);
			position += replaceString.length();
		}
		if (flag1) {
			lastChangedLine = currentLine;
		}
		++currentLine;
		++itr1;
		--diff;
	}
	if (flag) {
		this->currentLine = lastChangedLine;
	}
}

/**It implements the code to move the current line up by one line
**/
void LineEd::commandU() {
	if (buffer.size() <= 1 || this->currentLine == 1) {
		cout << "BOF reached." << endl;
		return;
	}
	this->currentLine--;
	print(this->currentLine, this->currentLine);
}

/**It implements the code to move the current line down by one line
**/
void LineEd::commandN() {
	if (buffer.size() <= 1 || this->currentLine == buffer.size()) {
		cout << "EOF reached." << endl;
		return;
	}
	this->currentLine++;
	print(this->currentLine, this->currentLine);
}

/**It implements the code to move to a specified line in the buffer
*@param Command represents the current command line object
**/
void LineEd::commandG(Command& cmd) {
	if (buffer.size() == 0) {
		return;
	}
	size_t count1{ findLineNumber(cmd.getAddress1()) };
	this->currentLine = count1;
	print(this->currentLine, this->currentLine);
}

/**It implements the code to save the buffer contents to a file
**/
void LineEd::commandW() {
	if (filename.empty()) {
		cout << "Enter the name of a file to write to: ";
		string file;
		getline(cin, file);
		ofstream ofs(file, ofstream::out | ofstream::trunc);
		if (!ofs.is_open()) {
			cout << "Unable to create new file " << file << endl;
			return;
		}
		int lineCount{ 0 };
		for (string line : buffer) {
			++lineCount;
			if (lineCount == buffer.size()) {
				ofs << line;
			}
			else {
				ofs << line << "\n";
			}
		}
		this->currentLine = buffer.size();
		cout << lineCount << " lines written to file \"" << file << "\"" << endl;
		ofs.close();
	}
	else {
		cout << "Save changes to file: " << filename << " (y or n)? ";
		string option;
		getline(cin, option);
		if (option.compare("y") != 0) {
			cout << "Enter the name of a file to write to: ";
			string file;
			getline(cin, file);
			ofstream ofs(file, ofstream::out | ofstream::trunc);
			if (!ofs.is_open()) {
				cout << "Unable to create new file " << file << endl;
				return;
			}
			int lineCount{ 0 };
			for (string line : buffer) {
				++lineCount;
				if (lineCount == buffer.size()) {
					ofs << line;
				}
				else {
					ofs << line << "\n";
				}
			}
			this->currentLine = buffer.size();
			cout << lineCount << " lines written to file \"" << file << "\"" << endl;
			ofs.close();
		}
		else {
			ofstream ofs(filename, ofstream::out | ofstream::trunc);
			if (!ofs.is_open()) {
				cout << "Unable to open file " << filename << endl;
				return;
			}
			int lineCount{ 0 };
			for (string line : buffer) {
				++lineCount;
				if (lineCount == buffer.size()) {
					ofs << line;
				}
				else {
					ofs << line << "\n";
				}
			}
			this->currentLine = buffer.size();
			cout << lineCount << " lines written to file \"" << filename << "\"" << endl;
			ofs.close();
		}
	}
}

/**It implements the code to quit and save the buffer contents to a file
**/
void LineEd::commandQ() {
	cout << "There are unsaved changes." << endl;
	cout << "Do you wish to save the changes (y or n)? ";
	string choice;
	getline(cin, choice);
	if (choice.compare("y") == 0) {
		if (!filename.empty()) {
			cout << "Save changes to the file: " << filename << " (y or n)? ";
			string nextChoice;
			getline(cin, nextChoice);
			if (nextChoice.compare("y") == 0) {
				ofstream ofs(filename, ofstream::out | ofstream::trunc);
				if (!ofs.is_open()) {
					cout << "Unable to open file " << filename << endl;
					return;
				}
				int lineCount{ 0 };
				for (string line : buffer) {
					++lineCount;
					if (lineCount == buffer.size()) {
						ofs << line;
					}
					else {
						ofs << line << "\n";
					}
				}
				cout << lineCount << " lines written to file \"" << filename << "\"" << endl;
				cout << "bye" << endl;
				ofs.close();
				return;
			}
		}
		cout << "Enter the name of a file to write to: ";
		string file;
		getline(cin, file);
		ofstream ofs(file, ofstream::out | ofstream::trunc);
		if (!ofs.is_open()) {
			cout << "Unable to create new file " << file << endl;
			return;
		}
		int lineCount{ 0 };
		for (string line : buffer) {
			++lineCount;
			if (lineCount == buffer.size()) {
				ofs << line;
			}
			else {
				ofs << line << "\n";
			}
		}
		cout << lineCount << " lines written to file \"" << file << "\"" << endl;
		cout << "bye" << endl;
		ofs.close();
	}
}
