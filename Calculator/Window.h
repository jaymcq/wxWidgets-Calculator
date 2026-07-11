#pragma once
#include "wx/wx.h"


class Window : public wxFrame
{
private:

	// Number Buttons:
	wxButton* button1 = nullptr;
	wxButton* button2 = nullptr;
	wxButton* button3 = nullptr;
	wxButton* button4 = nullptr;
	wxButton* button5 = nullptr;
	wxButton* button6 = nullptr;
	wxButton* button7 = nullptr;
	wxButton* button8 = nullptr;
	wxButton* button9 = nullptr;
	wxButton* button0 = nullptr;

	// Operator Buttons:
	wxButton* buttonAdd = nullptr;
	wxButton* buttonSubtract = nullptr;
	wxButton* buttonMultiply = nullptr;
	wxButton* buttonDivide = nullptr;
	wxButton* buttonModulo = nullptr;

	// Other Buttons:
	wxButton* buttonClear = nullptr;
	wxButton* buttonDecimal = nullptr;
	wxButton* buttonBackspace = nullptr;
	wxButton* buttonEquals = nullptr;
	wxButton* buttonPlusMinus = nullptr;
	wxButton* buttonSquareRoot = nullptr;
	wxButton* buttonSin = nullptr;
	wxButton* buttonCos = nullptr;
	wxButton* buttonTan = nullptr;

	// Output Box:
	wxTextCtrl* textBox = nullptr;

public:

	// Default constructor:
	Window();

};