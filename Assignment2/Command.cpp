#include "Command.h"

/**Constructor takes command line as a string and
*intializes all the elements of the command.
**/
Command::Command(const string& command_line) : status{ true }, symbolStatus{ true }, address1Status{ true }, address2Status{ true } {
	parse(command_line);
}

/**This function parses the command line parsed as string
@param string& represents the command line passed
**/
void Command::parse(const string& command_line) {
	this->command_line = command_line;
	this->status = true;
	this->symbolStatus = true;
	this->address1Status = true;
	this->address2Status = true;
	string tmpStr{ command_line };
	tmpStr.erase(remove(tmpStr.begin(), tmpStr.end(), ' '), tmpStr.end());

	if (tmpStr.empty()) {
		symbol = "p";
		address1 = ".";
		address2 = ".";
	}
	else {
	string:size_t pos = tmpStr.find(",");
		if (pos == string::npos) {
			if (isalpha(tmpStr[0])) {
				symbol = tmpStr[0];
				if (tmpStr.length() > 1) {
					string adrs1{ tmpStr.at(1) };
					if (adrs1.compare(".") == 0 || adrs1.compare("$") == 0) {
						if (tmpStr.length() > 2) {
							setAddress1(tmpStr.substr(1, tmpStr.size() - 1));
							setAddress1Status(false); //bad address1
						}
						else {
							setAddress1(adrs1);
							setAddress2(adrs1);
						}
					}
					else {
						if (checkIfStringIsNumber(tmpStr.substr(1, tmpStr.size() - 1))) {
							setAddress1(tmpStr.substr(1, tmpStr.size() - 1));
							setAddress2(tmpStr.substr(1, tmpStr.size() - 1));
						}
						else {
							setAddress1(tmpStr.substr(1, tmpStr.size() - 1));
							setAddress1Status(false); //bad address1
						}
					}
				}
				else {
					setAddress1(".");
					setAddress2(".");
				}
			}
			else {
				string adrs1{ tmpStr.at(0) };
				setSymbol("p");
				if (adrs1.compare(".") == 0 || adrs1.compare("$") == 0) {
					if (tmpStr.length() > 1) {
						setAddress1(tmpStr);
						setAddress1Status(false); //bad address1
					}
					else {
						setAddress1(adrs1);
						setAddress2(adrs1);
					}
				}
				else {
					if (checkIfStringIsNumber(tmpStr)) {
						setAddress1(tmpStr);
						setAddress2(tmpStr);
					}
					else {
						setAddress1(tmpStr);
						setAddress1Status(false); //bad address1
					}
				}
			}
		}
		else {
			if (pos == 0) {
				setSymbol("p");
				if (tmpStr.size() == 1) {
					setAddress1(".");
					setAddress2(".");
				}
				else {
					setAddress1(".");
					string adrs2{ tmpStr.at(1) };
					if (adrs2.compare(".") == 0 || adrs2.compare("$") == 0) {
						if (tmpStr.size() > 2) {
							setAddress2(tmpStr.substr(1, tmpStr.size() - 1));
							setAddress2Status(false); //bad command
						}
						else {
							setAddress2(adrs2);
						}
					}
					else {
						if (checkIfStringIsNumber(tmpStr.substr(1, tmpStr.size() - 1))) {
							setAddress2(tmpStr.substr(1, tmpStr.size() - 1));
						}
						else {
							setAddress2(tmpStr.substr(1, tmpStr.size() - 1));
							setAddress2Status(false); //bad address2
						}
					}
				}
			}
			else if (pos == tmpStr.length() - 1) {
				if (isalpha(tmpStr[0])) {
					setSymbol(to_string(tmpStr[0]));
					string adrs1{ tmpStr.at(1) };
					if (adrs1.compare(".") == 0 || adrs1.compare("$") == 0) {
						if (tmpStr.size() > 3) {
							setAddress2(tmpStr.substr(1, tmpStr.size() - 2));
							setAddress1Status(false); //bad address1
						}
						else {
							setAddress1(adrs1);
							setAddress2(adrs1);
						}
					}
					else {
						if (checkIfStringIsNumber(tmpStr.substr(1, tmpStr.size() - 2))) {
							setAddress1(tmpStr.substr(1, tmpStr.size() - 2));
							setAddress2(tmpStr.substr(1, tmpStr.size() - 2));
						}
						else {
							setAddress1(tmpStr.substr(1, tmpStr.size() - 2));
							setAddress1Status(false); //bad address1
						}
					}

				}
				else {
					setSymbol("p");
					string addr1{ tmpStr.substr(0,tmpStr.size() - 1) };
					if (addr1.compare(".") == 0 || addr1.compare("$") == 0) {
						setAddress1(addr1);
						setAddress2(addr1);
					}
					else {
						if (checkIfStringIsNumber(addr1.c_str())) {
							setAddress1(addr1);
							setAddress2(addr1);
						}
						else {
							setAddress1(tmpStr.substr(0, tmpStr.size() - 1));
							setAddress1Status(false); //bad address1
						}
					}
				}
			}
			else {
				if (isalpha(tmpStr[0])) {
					symbol = tmpStr[0];
					string adrs1{ tmpStr.at(1) };
					string nextChar{ tmpStr.at(2) };
					if (adrs1.compare(",") == 0) {
						address1 = ".";
					}
					else if (adrs1.compare(".") == 0 || adrs1.compare("$") == 0) {
						if (nextChar.compare(",") != 0) {
							setAddress1(tmpStr.substr(1, pos - 1));
							setAddress1Status(false); //bad address1
						}
						else {
							setAddress1(adrs1);
						}
					}
					else {
						if (checkIfStringIsNumber(tmpStr.substr(1, pos - 1))) {
							setAddress1(tmpStr.substr(1, pos - 1));
						}
						else {
							setAddress1(tmpStr.substr(1, pos - 1));
							setAddress1Status(false); //bad address1
						}
					}

					string adrs2{ tmpStr.at(pos + 1) };
					if (adrs2.compare(".") == 0 || adrs2.compare("$") == 0) {
						if (tmpStr.size() >= pos + 3) {
							setAddress2(adrs2);
							setAddress2Status(false); //bad address2
						}
						else {
							setAddress2(adrs2);
						}
					}
					else {
						if (checkIfStringIsNumber(tmpStr.substr(pos + 1, tmpStr.length() - pos - 1))) {
							setAddress2(tmpStr.substr(pos + 1, tmpStr.length() - pos - 1));
						}
						else {
							setAddress2(adrs2);
							setAddress2Status(false); //bad address2
						}
					}
				}
				else {
					setSymbol("p");
					string addr1{ tmpStr.substr(0,pos) };
					string addr2{ tmpStr.substr(pos + 1,tmpStr.length() - pos - 1) };
					if (addr1.compare(".") == 0 || addr1.compare("$") == 0) {
						setAddress1(addr1);
					}
					else {
						if (checkIfStringIsNumber(addr1)) {
							setAddress1(addr1);
						}
						else {
							setAddress1(addr1);
							setAddress1Status(false); //bad address1
						}
					}

					if (addr2.compare(".") == 0 || addr2.compare("$") == 0) {
						setAddress2(addr2);
					}
					else {
						if (checkIfStringIsNumber(addr2)) {
							setAddress2(addr2);
						}
						else {
							setAddress2(addr2);
							setAddress2Status(false); //bad address2
						}
					}
				}
			}
		}
	}

	if (!symbolStatus || !address1Status || !address2Status) {
		setStatus(false);
	}
}

/**Getter to fetch the command symbol
*@return string represents the symbol
**/
string Command::getSymbol() {
	return this->symbol;
}

/**Getter to fetch the address1
*@return string represents the address1
**/
string Command::getAddress1() {
	return this->address1;
}

/**Getter to fetch the address2
*@return string represents the address2
**/
string Command::getAddress2() {
	return this->address2;
}

/**Getter to fetch the overall command line status
*@return true if command line is valid, otherwise false
**/
bool Command::getStatus() {
	return this->status;
}

/**Setter to set the command line status
*@param bool represents the command line status
**/
void Command::setStatus(bool status) {
	this->status = status;
}


/**Setter to set the address1
*@param string represents the address1
**/
void Command::setAddress1(string adrs1) {
	this->address1 = adrs1;
}

/**Setter to set the address2
*@param string represents the address2
**/
void Command::setAddress2(string adrs2) {
	this->address2 = adrs2;
}

/**Getter to fetch the symbol status
*@return bool true if symbol is valid, otherwise false
**/
bool Command::getSymbolStatus() {
	return this->symbolStatus;
}

/**Setter to set the symbol of the command
*@param string represents the symbol
**/
void Command::setSymbol(string symbol) {
	this->symbol = symbol;
}

/**Setter to set the symbol status
*@param bool represents the symbol status
**/
void Command::setSymbolStatus(bool symbolStatus) {
	this->symbolStatus = symbolStatus;
}

/**Getter to fetch the address1 status
*@return bool true if address1 is valid, otherwise false
**/
bool Command::getAdress1Status() {
	return this->address1Status;
}

/**Setter to set the address1 status
*@param bool represents the address1 status
**/
void Command::setAddress1Status(bool address1Status) {
	this->address1Status = address1Status;
}


/**Getter to fetch the address2 status
*@return bool true if address2 is valid, otherwise false
**/
bool Command::getAdress2Status() {
	return this->address2Status;
}

/**Setter to set the address2 status
*@param bool represents the address2 status
**/
void Command::setAddress2Status(bool address2Status) {
	this->address2Status = address2Status;
}

/**It checks if the number represented by a string is a valid number
*@return true if string represents a valid number, otherwise false
**/
bool Command::checkIfStringIsNumber(string str) {
	for (int i = 0; i < str.size(); ++i) {
		if (str[0] == '-') {
			continue;
		}
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	return true;
}

