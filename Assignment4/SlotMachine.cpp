#include"SlotMachine.h"

/**Function to run the slot machine getting player's inputs
*and implement prize payout
**/
void SlotMachine::run() {
	cout << "Welcome to 3 - Reel Lucky Slot Machine Game !\nEach reel will randomly display one of four shapes, each in 25 sizes."
		<< "\nTo win 3 x bet Get 2 similar shapes AND 2 shapes with equal Scr Areas\nTo win 2 x bet Get 3 similar shapes"
		<< "\nTo win 1 x bet Get(Middle) Scr Area > (Left + Right) Scr Areas\nTo win or lose nothing Get same Left and Right shapes"
		<< "\nOtherwise, you lose your bet.\nYou start with 10 free slot tokens !\n";

	int bet;
	int tokens{ 10 };
	do {
		if (tokens == 0) {
			cout << "\nYou have zero tokens left." << endl;
			cout << "Thank you for playing, come back soon!" << endl;
			cout << "Game Over.\n";
			break;
		}
		cout << "\nHow much would you like to bet(enter 0 to quit)? ";
		cin >> bet;
		if (bet < 0) {
			cout << "No negative bets, try again!" << endl;
			continue;
		}
		else if (bet > tokens) {
			cout << "You can't bet more than " << tokens << ", try again!" << endl;
			continue;
		}
		else if (bet == 0) {
			cout << "Thank you for playing, come back soon!"
				<< "\nBe sure you cash in your remaining " << tokens << " tokens at the bar!"
				<< "\nGame Over.\n";
			break;
		}
		make_shapes();
		display();
		if ((typeid(*reel[0]).name() == typeid(*reel[1]).name() || typeid(*reel[0]).name() == typeid(*reel[2]).name() || typeid(*reel[1]).name() == typeid(*reel[2]).name()) &&
			(reel[0]->screenArea() == reel[1]->screenArea() || reel[0]->screenArea() == reel[2]->screenArea() || reel[1]->screenArea() == reel[2]->screenArea())) {
			cout << "Jackpot! 2 Similar Shapes AND 2 Equal Screen Areas"
				<< "\nCongratulations! you win 3 times your bet : " << 3 * bet;
			tokens += 3 * bet;
		}
		else if (typeid(*reel[0]).name() == typeid(*reel[1]).name() && typeid(*reel[0]).name() == typeid(*reel[2]).name()) {
			cout << "Three similar shapes"
				<< "\nCongratulations! you win 2 times your bet : " << 2 * bet;
			tokens += 2 * bet;
		}
		else if (reel[1]->screenArea() > reel[0]->screenArea() + reel[2]->screenArea()) {
			cout << "Middle > Left + Right, in Screen Areas"
				<< "\nCongratulations! you win your bet : " << bet;
			tokens += bet;
		}
		else if (typeid(*reel[0]).name() == typeid(*reel[2]).name()) {
			cout << "Lucky this time!" << "\nYou don't win, you don't lose, your are safe!";
		}
		else {
			tokens -= bet;
			cout << "Oh No!" << "\nYou lose your bet";
		}
		cout << "\nYou now have " << tokens << " tokens" << endl;
	} while (bet != 0);
}


/**Function generates three shapes randomly
**/
void SlotMachine::make_shapes() {
	for (int i{ 0 }; i < 3; ++i) {
		make_shape(i);
	}
}

/**Function generates one shape randomly
**/
void SlotMachine::make_shape(int k) {
	unsigned long long int currentTime;
	currentTime = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
	srand(unsigned(currentTime));
	int n{ rand() % 4 };
	int w{ rand() % 25 + 1 };
	if (n == 0) {
		reel[k].reset(new Rhombus(w));
	}
	else if (n == 1) {
		reel[k].reset(new AcuteTriangle(w));
	}
	else if (n == 2) {
		reel[k].reset(new RightTriangle(w));
	}
	else {
		int h{ rand() % 25 + 1 };
		reel[k].reset(new Rectangle(h, w));
	}
}

/**Function to draw the slot machine having three reels
**/
void SlotMachine::display() {
	const int reelHeight1{ reel[0]->boundingHeight() };
	const int reelHeight2{ reel[1]->boundingHeight() };
	const int reelHeight3{ reel[2]->boundingHeight() };
	const int maxHeight{ max(reelHeight1, max(reelHeight2, reelHeight3)) };

	Grid box_0 = reel[0]->draw();
	Grid box_1 = reel[1]->draw();
	Grid box_2 = reel[2]->draw();

	Grid opGrid{ unsigned(maxHeight + 2), vector<char>(unsigned(reel[0]->boundingWidth() + reel[1]->boundingWidth() + reel[2]->boundingWidth() + 10), ' ') };

	for (size_t i{ 0 }; i < opGrid.size(); ++i) {
		if (i == 0 || i == opGrid.size() - 1) {
			opGrid[i][0] = '+';
			int j{ 1 };
			for (; j <= reel[0]->boundingWidth() + 2; ++j) {
				opGrid[i][j] = '-';
			}
			opGrid[i][j] = '+';
			++j;
			int lastElement{ j + reel[1]->boundingWidth() + 2 };
			for (; j < lastElement; ++j) {
				opGrid[i][j] = '-';
			}
			opGrid[i][j] = '+';
			++j;
			lastElement = j + reel[2]->boundingWidth() + 2;
			for (; j < lastElement; ++j) {
				opGrid[i][j] = '-';
			}
			opGrid[i][j] = '+';
		}
		else {
			int j{ 0 };
			opGrid[i][j] = '|';
			j += reel[0]->boundingWidth() + 3;
			opGrid[i][j] = '|';
			j += reel[1]->boundingWidth() + 3;
			opGrid[i][j] = '|';
			j += reel[2]->boundingWidth() + 3;
			opGrid[i][j] = '|';
		}
	}

	for (size_t i{ 0 }; i < box_0.size(); ++i) {
		for (size_t j{ 0 }; j < box_0[i].size(); ++j) {
			opGrid[i + 1][j + 2] = box_0[i][j];
		}
	}

	for (size_t i{ 0 }; i < box_1.size(); ++i) {
		for (size_t j{ 0 }; j < box_1[i].size(); ++j) {
			opGrid[i + 1][j + reel[0]->boundingWidth() + 5] = box_1[i][j];
		}
	}

	for (size_t i{ 0 }; i < box_2.size(); ++i) {
		for (size_t j{ 0 }; j < box_2[i].size(); ++j) {
			opGrid[i + 1][j + reel[0]->boundingWidth() + reel[1]->boundingWidth() + 8] = box_2[i][j];
		}
	}

	for (const auto& row : opGrid)
	{
		for (const auto& element : row)
		{
			cout << element;
		}
		cout << endl;
	}

	cout << "(" << reel[0]->getName() << ", " << reel[0]->boundingHeight() << ", " << reel[0]->boundingWidth() << ") ("
		<< reel[1]->getName() << ", " << reel[1]->boundingHeight() << ", " << reel[1]->boundingWidth() << ") ("
		<< reel[2]->getName() << ", " << reel[2]->boundingHeight() << ", " << reel[2]->boundingWidth() << ")" << endl;
}

