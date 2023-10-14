#include "Position.h"

Position::Position(int row, int column)
{
	//Using the "this" keyword is reference to the object so that
	//we will be able to retrieve the attributes that is hidden
	//and using "->" we will able to manipulate the attribute within the 
	//class that has been reference
	this->row = row;
	this->column = column;
}
