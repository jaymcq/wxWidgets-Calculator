#include "Window.h"

Window::Window() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(100, 100), wxSize(500, 500)) {
	// Implement all buttons and text box here:

	// Number Buttons:
	button1 = new wxButton(this, wxID_ANY, "1", wxPoint(10, 10), wxSize(100, 100));
	button2 = new wxButton(this, wxID_ANY, "2", wxPoint(120, 10), wxSize(100, 100));
	button3 = new wxButton(this, wxID_ANY, "3", wxPoint(120, 10), wxSize(100, 100));
	button4 = new wxButton(this, wxID_ANY, "4", wxPoint(120, 10), wxSize(100, 100));
	button5 = new wxButton(this, wxID_ANY, "5", wxPoint(120, 10), wxSize(100, 100));
	button6 = new wxButton(this, wxID_ANY, "6", wxPoint(120, 10), wxSize(100, 100));
	button7 = new wxButton(this, wxID_ANY, "7", wxPoint(120, 10), wxSize(100, 100));
	button8 = new wxButton(this, wxID_ANY, "8", wxPoint(120, 10), wxSize(100, 100));
	button9 = new wxButton(this, wxID_ANY, "9", wxPoint(120, 10), wxSize(100, 100));
	button0 = new wxButton(this, wxID_ANY, "0", wxPoint(120, 10), wxSize(100, 100));

	// Operator Buttons:
	buttonAdd= new wxButton(this, wxID_ANY, "+", wxPoint(230, 10), wxSize(100, 100));
	buttonSubtract = new wxButton(this, wxID_ANY, "-", wxPoint(230, 10), wxSize(100, 100));
	buttonMultiply = new wxButton(this, wxID_ANY, "*", wxPoint(230, 10), wxSize(100, 100));
	buttonDivide = new wxButton(this, wxID_ANY, "/", wxPoint(230, 10), wxSize(100, 100));


	// Output Box:
	textBox = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 120), wxSize(230, 25));

	// Other Buttons:
	buttonClear = new wxButton(this, wxID_ANY, "Clear", wxPoint(10, 150), wxSize(100, 100));
	buttonDecimal = new wxButton(this, wxID_ANY, ".", wxPoint(120, 120), wxSize(100, 100));
	buttonBackspace = new wxButton(this, wxID_ANY, "Backspace", wxPoint(230, 120), wxSize(100, 100));
	buttonEquals = new wxButton(this, wxID_ANY, "=", wxPoint(10, 260), wxSize(100, 100));
	buttonPlusMinus = new wxButton(this, wxID_ANY, "+/-", wxPoint(120, 260), wxSize(100, 100));


}