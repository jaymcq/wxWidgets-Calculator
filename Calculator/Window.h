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
	wxButton* buttonLeftParen = nullptr;
	wxButton* buttonRightParen = nullptr;
	wxButton* buttonSin = nullptr;
	wxButton* buttonCos = nullptr;
	wxButton* buttonTan = nullptr;

	// Output Box:
	wxTextCtrl* textBox = nullptr;

public:

	// Default constructor:
	Window();

	void OnButtonClicked(wxCommandEvent& event);

	// Event handler for button clicks:
	wxCommandEvent event; 

	// Result of the calculation:
	double result = 0;
	std::string leftOperand = "", rightOperand = "";

	// Active Operand:
	enum Operand { Left_Operand, Right_Operand };

	// Operation:
	enum Operation { Add, Subtract, Multiply, Divide, Modulo, Sin, Cos, Tan };
	
	Operand activeOperand = Left_Operand;
	Operation currentOperation;


	void OnAdd(wxCommandEvent& event);
	void OnSubtract(wxCommandEvent& event);
	void OnDivide(wxCommandEvent& event);
	void OnMultiply(wxCommandEvent& event);
	void OnClear(wxCommandEvent& event);
	void OnDecimal(wxCommandEvent& event);
	void OnButton1(wxCommandEvent& event);
	void OnButton2(wxCommandEvent& event);
	void OnButton3(wxCommandEvent& event);
	void OnButton4(wxCommandEvent& event);
	void OnButton5(wxCommandEvent& event);
	void OnButton6(wxCommandEvent& event);
	void OnButton7(wxCommandEvent& event);
	void OnButton8(wxCommandEvent& event);
	void OnButton9(wxCommandEvent& event);
	void OnButton0(wxCommandEvent& event);
	void onButtonBackspace(wxCommandEvent& event);
	void onButtonPlusMinus(wxCommandEvent& event);
	void onButtonLeftParen(wxCommandEvent& event);
	void onButtonRightParen(wxCommandEvent& event);
	void onButtonSin(wxCommandEvent& event);
	void onButtonCos(wxCommandEvent& event);
	void onButtonTan(wxCommandEvent& event);
	void onButtonModulo(wxCommandEvent& event);
	void onButtonEquals(wxCommandEvent& event);
	void UpdateResultDisplay();
	void onKeypadInput(wxKeyEvent& event);

	void UpdateResult();

};