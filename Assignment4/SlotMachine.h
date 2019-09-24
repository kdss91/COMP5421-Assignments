/**The purpose of this file is to mimic a classical slot machine.
*The slot machine has three reels, and each reel can have four different shapes.
**/
#ifndef _MY_SLOTMACHINE_H
#define _MY_SLOTMACHINE_H
#include"Rhombus.h"
#include"AcuteTriangle.h"
#include"RightTriangle.h"
#include"Rectangle.h"
#include<array>
#include<cstdlib>
#include<ctime>
#include<chrono>
#include<iostream>
using std::array;
using std::unique_ptr;
using std::cout;
using std::cin;
using std::max;
using std::endl;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;
using std::chrono::system_clock;


/**This class implements all functions relating to a slot machine.
*It creates three random shapes in a reel array and displays it
*on the screen.
**/
class SlotMachine
{	/**Represents an array containing three shape objects
	**/
	array <unique_ptr <Shape >, 3> reel{};

	/**Function generates three shapes randomly
	**/
	void make_shapes();

	/**Function generates one shape randomly
	**/
	void make_shape(int k);

	/**Function to draw the slot machine having three reels
	**/
	void display();
public:
	/**Default Contructor
	**/
	SlotMachine() = default;

	/**Deleted default copy constructor
	**/
	SlotMachine(const SlotMachine&) = delete; // copy ctor

	/**Deleted move constructor
	**/
	SlotMachine(SlotMachine&&) = delete; // move ctor

	/**Deleted copy assignment
	**/
	SlotMachine& operator =(const SlotMachine&) = delete; // copy assignment

	/**Deleted move assignment
	**/
	SlotMachine& operator =(SlotMachine&&) = delete; // move assignment

	/**Default destructor
	**/
	virtual ~SlotMachine() = default;

	/**Function to run the slot machine getting player's inputs
	*and implement prize payout
	**/
	void run();
};
#endif