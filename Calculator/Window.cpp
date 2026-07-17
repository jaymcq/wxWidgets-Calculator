#include "Window.h"
#include "ButtonFactory.h"

enum {
	BUTTON_0 = 1000,
	BUTTON_1 = 1001,
	BUTTON_2 = 1002,
	BUTTON_3 = 1003,
	BUTTON_4 = 1004,
	BUTTON_5 = 1005,
	BUTTON_6 = 1006,
	BUTTON_7 = 1007,
	BUTTON_8 = 1008,
	BUTTON_9 = 1009,
	BUTTON_ADD = 1010,
	BUTTON_SUBTRACT = 1011,
	BUTTON_MULTIPLY = 1012,
	BUTTON_DIVIDE = 1013,
	BUTTON_MODULO = 1014,
	BUTTON_CLEAR = 1015,
	BUTTON_DECIMAL = 1016,
	BUTTON_BACKSPACE = 1017,
	BUTTON_PLUS_MINUS = 1018,
	BUTTON_LEFT_PAREN = 1019,
	BUTTON_RIGHT_PAREN = 1020,
	BUTTON_SIN = 1021,
	BUTTON_COS = 1022,
	BUTTON_TAN = 1023,
	BUTTON_EQUALS = 1024
};



Window::Window() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(100, 100), wxSize(320, 375)) {
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* topLevelSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* textCtrlSizer = new wxBoxSizer(wxHORIZONTAL);

	// Implement all buttons and text box here:

	// Output Box:
	textBox = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1, 40));
	if (!textBox->HasFlag(wxTE_MULTILINE))
		textBox->SetMaxLength(40);
	else
		textBox->SetMaxLength(40);

	textCtrlSizer->Add(textBox, 1, wxALL | wxEXPAND, 5);

	topLevelSizer->Add(textCtrlSizer, 1, wxEXPAND, 5);

	wxGridSizer* GridButtonSizer = new wxGridSizer(6, 4, 6, 6);



	// Operator Buttons:
	wxButton* addButton = ButtonFactory::CreateAddButton(this);
	wxButton* subtractButton = ButtonFactory::CreateSubtractButton(this);
	wxButton* multiplyButton = ButtonFactory::CreateMultiplyButton(this);
	wxButton* modButton = ButtonFactory::CreateModuloButton(this);
	wxButton* divideButton = ButtonFactory::CreateDivideButton(this);
	wxButton* clearButton = ButtonFactory::CreateClearButton(this);
	wxButton* decimalButton = ButtonFactory::CreateDecimalButton(this);
	wxButton* backspaceButton = ButtonFactory::CreateBackspaceButton(this);
	wxButton* subButton = ButtonFactory::CreatePlusMinusButton(this);
	wxButton* leftParenButton = ButtonFactory::CreateLeftParenButton(this);
	wxButton* rightParenButton = ButtonFactory::CreateRightParenButton(this);
	wxButton* sinButton = ButtonFactory::CreateSinButton(this);
	wxButton* cosButton = ButtonFactory::CreateCosButton(this);
	wxButton* tanButton = ButtonFactory::CreateTanButton(this);
	wxButton* equalsButton = ButtonFactory::CreateEqualsButton(this);
	

	// Number Buttons:
	numberButtons.push_back(std::shared_ptr<wxButton>(ButtonFactory::CreateZeroButton(this)));
	numberButtons.push_back(std::shared_ptr<wxButton>(ButtonFactory::CreateOneButton(this)));
	numberButtons.push_back(std::shared_ptr<wxButton>(ButtonFactory::CreateTwoButton(this)));
	numberButtons.push_back(std::shared_ptr<wxButton>(ButtonFactory::CreateThreeButton(this)));
	numberButtons.push_back(std::shared_ptr<wxButton>(ButtonFactory::CreateFourButton(this)));
	numberButtons.push_back(std::shared_ptr<wxButton>(ButtonFactory::CreateFiveButton(this)));
	numberButtons.push_back(std::shared_ptr<wxButton>(ButtonFactory::CreateSixButton(this)));
	numberButtons.push_back(std::shared_ptr<wxButton>(ButtonFactory::CreateSevenButton(this)));
	numberButtons.push_back(std::shared_ptr<wxButton>(ButtonFactory::CreateEightButton(this)));
	numberButtons.push_back(std::shared_ptr<wxButton>(ButtonFactory::CreateNineButton(this)));



	GridButtonSizer->Add(numberButtons[7].get(), 0, wxEXPAND);
	GridButtonSizer->Add(numberButtons[8].get(), 0, wxEXPAND);
	GridButtonSizer->Add(numberButtons[9].get(), 0, wxEXPAND);
	GridButtonSizer->Add(buttonDivide, 0, wxEXPAND);

	GridButtonSizer->Add(numberButtons[4].get(), 0, wxEXPAND);
	GridButtonSizer->Add(numberButtons[5].get(), 0, wxEXPAND);
	GridButtonSizer->Add(numberButtons[6].get(), 0, wxEXPAND);
	GridButtonSizer->Add(buttonMultiply, 0, wxEXPAND);

	GridButtonSizer->Add(numberButtons[1].get(), 0, wxEXPAND);
	GridButtonSizer->Add(numberButtons[2].get(), 0, wxEXPAND);
	GridButtonSizer->Add(numberButtons[3].get(), 0, wxEXPAND);
	GridButtonSizer->Add(buttonSubtract, 0, wxEXPAND);

	GridButtonSizer->Add(numberButtons[0].get(), 0, wxEXPAND);
	GridButtonSizer->Add(buttonDecimal, 0, wxEXPAND);
	GridButtonSizer->Add(buttonEquals, 0, wxEXPAND);
	GridButtonSizer->Add(buttonAdd, 0, wxEXPAND);

	GridButtonSizer->Add(buttonLeftParen, 0, wxEXPAND);
	GridButtonSizer->Add(buttonRightParen, 0, wxEXPAND);
	GridButtonSizer->Add(buttonBackspace, 0, wxEXPAND);
	GridButtonSizer->Add(buttonClear, 0, wxEXPAND);

	GridButtonSizer->Add(buttonSin, 0, wxEXPAND);
	GridButtonSizer->Add(buttonCos, 0, wxEXPAND);
	GridButtonSizer->Add(buttonTan, 0, wxEXPAND);
	GridButtonSizer->Add(buttonModulo, 0, wxEXPAND);

	// Used Bind instead of an Event Table due to DLL Errors?
	Bind(wxEVT_BUTTON, &Window::OnButton0, this, BUTTON_0);
	Bind(wxEVT_BUTTON, &Window::OnButton1, this, BUTTON_1);
	Bind(wxEVT_BUTTON, &Window::OnButton2, this, BUTTON_2);
	Bind(wxEVT_BUTTON, &Window::OnButton3, this, BUTTON_3);
	Bind(wxEVT_BUTTON, &Window::OnButton4, this, BUTTON_4);
	Bind(wxEVT_BUTTON, &Window::OnButton5, this, BUTTON_5);
	Bind(wxEVT_BUTTON, &Window::OnButton6, this, BUTTON_6);
	Bind(wxEVT_BUTTON, &Window::OnButton7, this, BUTTON_7);
	Bind(wxEVT_BUTTON, &Window::OnButton8, this, BUTTON_8);
	Bind(wxEVT_BUTTON, &Window::OnButton9, this, BUTTON_9);

	Bind(wxEVT_BUTTON, &Window::OnAdd, this, BUTTON_ADD);
	Bind(wxEVT_BUTTON, &Window::OnSubtract, this, BUTTON_SUBTRACT);
	Bind(wxEVT_BUTTON, &Window::OnMultiply, this, BUTTON_MULTIPLY);
	Bind(wxEVT_BUTTON, &Window::OnDivide, this, BUTTON_DIVIDE);
	Bind(wxEVT_BUTTON, &Window::OnButtonModulo, this, BUTTON_MODULO);

	Bind(wxEVT_BUTTON, &Window::OnClear, this, BUTTON_CLEAR);
	Bind(wxEVT_BUTTON, &Window::OnDecimal, this, BUTTON_DECIMAL);
	Bind(wxEVT_BUTTON, &Window::OnButtonBackspace, this, BUTTON_BACKSPACE);
	Bind(wxEVT_BUTTON, &Window::OnButtonPlusMinus, this, BUTTON_PLUS_MINUS);
	Bind(wxEVT_BUTTON, &Window::OnButtonLeftParen, this, BUTTON_LEFT_PAREN);
	Bind(wxEVT_BUTTON, &Window::OnButtonRightParen, this, BUTTON_RIGHT_PAREN);
	Bind(wxEVT_BUTTON, &Window::OnButtonSin, this, BUTTON_SIN);
	Bind(wxEVT_BUTTON, &Window::OnButtonCos, this, BUTTON_COS);
	Bind(wxEVT_BUTTON, &Window::OnButtonTan, this, BUTTON_TAN);
	Bind(wxEVT_BUTTON, &Window::OnButtonEquals, this, BUTTON_EQUALS);

	topLevelSizer->Add(GridButtonSizer, 1, wxEXPAND, 5);

	this->SetSizer(topLevelSizer);
	this->Layout();

	this->Center(wxBOTH);

}



void Window::OnAdd(wxCommandEvent& event)
{
	activeOperand = Right_Operand;
	currentOperation = Add;
	textBox->SetFocus();
}

void Window::OnSubtract(wxCommandEvent& event)
{
	activeOperand = Right_Operand;
	currentOperation = Subtract;
	textBox->SetFocus();
}

void Window::OnDivide(wxCommandEvent& event)
{
	activeOperand = Right_Operand;
	currentOperation = Divide;
	textBox->SetFocus();
}

void Window::OnMultiply(wxCommandEvent& event)
{
	activeOperand = Right_Operand;
	currentOperation = Multiply;
	textBox->SetFocus();
}

void Window::OnClear(wxCommandEvent& event)
{
	leftOperand.clear();
	rightOperand.clear();
	result = 0;
	textBox->Clear();
	textBox->SetFocus();
}

void Window::OnDecimal(wxCommandEvent& event)
{
	if(activeOperand == Left_Operand)
		leftOperand += ".";
	else
		rightOperand += ".";
	UpdateResult();
}

void Window::OnButton1(wxCommandEvent& event)
{
	if (activeOperand == Left_Operand)
		leftOperand += "1";
	else
		rightOperand += "1";
	UpdateResult();
}

void Window::OnButton2(wxCommandEvent& event)
{
	if (activeOperand == Left_Operand)
		leftOperand += "2";
	else
		rightOperand += "2";
	UpdateResult();
}

void Window::OnButton3(wxCommandEvent& event)
{
	if (activeOperand == Left_Operand)
		leftOperand += "3";
	else
		rightOperand += "3";
	UpdateResult();
}

void Window::OnButton4(wxCommandEvent& event)
{
	if (activeOperand == Left_Operand)
		leftOperand += "4";
	else
		rightOperand += "4";
	UpdateResult();
}

void Window::OnButton5(wxCommandEvent& event)
{
	if (activeOperand == Left_Operand)
		leftOperand += "5";
	else
		rightOperand += "5";
	UpdateResult();
}

void Window::OnButton6(wxCommandEvent& event)
{
	if (activeOperand == Left_Operand)
		leftOperand += "6";
	else
		rightOperand += "6";
	UpdateResult();
}

void Window::OnButton7(wxCommandEvent& event)
{
	if (activeOperand == Left_Operand)
		leftOperand += "7";
	else
		rightOperand += "7";
	UpdateResult();
}

void Window::OnButton8(wxCommandEvent& event)
{
	if (activeOperand == Left_Operand)
		leftOperand += "8";
	else
		rightOperand += "8";
	UpdateResult();
}

void Window::OnButton9(wxCommandEvent& event)
{
	if (activeOperand == Left_Operand)
		leftOperand += "9";
	else
		rightOperand += "9";
	UpdateResult();
}

void Window::OnButton0(wxCommandEvent& event)
{
	if (activeOperand == Left_Operand)
		leftOperand += "0";
	else
		rightOperand += "0";
	UpdateResult();
}

void Window::OnButtonBackspace(wxCommandEvent& event)
{
	if (activeOperand == Left_Operand)
		leftOperand.pop_back();
	else
		rightOperand.pop_back();
	UpdateResult();
}

void Window::OnButtonPlusMinus(wxCommandEvent& event)
{
}

void Window::OnButtonLeftParen(wxCommandEvent& event)
{
	if (activeOperand == Left_Operand)
		leftOperand += "(";
	else
		rightOperand += "(";
	UpdateResult();
}

void Window::OnButtonRightParen(wxCommandEvent& event)
{
	if (activeOperand == Left_Operand)
		leftOperand += ")";
	else
		rightOperand += ")";
	UpdateResult();
}

void Window::OnButtonSin(wxCommandEvent& event)
{
	if (activeOperand == Right_Operand) {
		result = std::sin(std::stod(leftOperand));
		textBox->Clear();
		textBox->AppendText(wxString::Format("%f", result));
		activeOperand = Left_Operand;
		leftOperand = std::to_string(result);
		rightOperand.clear();
	}
}

void Window::OnButtonCos(wxCommandEvent& event)
{
	if (activeOperand == Right_Operand) {
		result = std::cos(std::stod(leftOperand));
		textBox->Clear();
		textBox->AppendText(wxString::Format("%f", result));
		activeOperand = Left_Operand;
		leftOperand = std::to_string(result);
		rightOperand.clear();
	}
}

void Window::OnButtonTan(wxCommandEvent& event)
{
	if (activeOperand == Right_Operand) {
		result = std::tan(std::stod(leftOperand));
		textBox->Clear();
		textBox->AppendText(wxString::Format("%f", result));
		activeOperand = Left_Operand;
		leftOperand = std::to_string(result);
		rightOperand.clear();
	}
}

void Window::OnButtonModulo(wxCommandEvent& event)
{
	if (activeOperand == Right_Operand) {
		result = std::fmod(std::stod(leftOperand), std::stod(rightOperand));
		textBox->Clear();
		textBox->AppendText(wxString::Format("%f", result));
		activeOperand = Left_Operand;
		leftOperand = std::to_string(result);
		rightOperand.clear();
	}
}

void Window::OnButtonEquals(wxCommandEvent& event)
{
	if (activeOperand == Right_Operand) {
		if(currentOperation == Add)
			result = std::stod(leftOperand) + std::stod(rightOperand);
		else if (currentOperation == Subtract)
			result = std::stod(leftOperand) - std::stod(rightOperand);
		else if (currentOperation == Multiply)
			result = std::stod(leftOperand) * std::stod(rightOperand);
		else if (currentOperation == Divide)
			result = std::stod(leftOperand) / std::stod(rightOperand);
		else if (currentOperation == Modulo)
			result = std::fmod(std::stod(leftOperand), std::stod(rightOperand));

		textBox->Clear();
		textBox->AppendText(wxString::Format("%f", result));
		activeOperand = Left_Operand;
		leftOperand = std::to_string(result);
		rightOperand.clear();
	}
	textBox->SetFocus();
}

void Window::UpdateResult()
{
	if (activeOperand == Left_Operand){
		textBox->Clear();
		textBox->AppendText(leftOperand);
	}
	else {
		textBox->Clear();
		textBox->AppendText(rightOperand);
	}
}

void Window::OnKeypadInput(wxKeyEvent& event)
{
	event.Skip(); // Skip if unable to process event

	if (event.GetKeyCode() == WXK_NUMPAD0) OnButton0(e);
	else if (event.GetKeyCode() == WXK_NUMPAD1) OnButton1(e);
	else if (event.GetKeyCode() == WXK_NUMPAD2) OnButton2(e);
	else if (event.GetKeyCode() == WXK_NUMPAD3) OnButton3(e);
	else if (event.GetKeyCode() == WXK_NUMPAD4) OnButton4(e);
	else if (event.GetKeyCode() == WXK_NUMPAD5) OnButton5(e);
	else if (event.GetKeyCode() == WXK_NUMPAD6) OnButton6(e);
	else if (event.GetKeyCode() == WXK_NUMPAD7) OnButton7(e);
	else if (event.GetKeyCode() == WXK_NUMPAD8) OnButton8(e);
	else if (event.GetKeyCode() == WXK_NUMPAD9) OnButton9(e);
	else if (event.GetKeyCode() == WXK_NUMPAD_ADD) OnAdd(e);
	else if (event.GetKeyCode() == WXK_NUMPAD_SUBTRACT) OnSubtract(e);
	else if (event.GetKeyCode() == WXK_NUMPAD_MULTIPLY) OnMultiply(e);
	else if (event.GetKeyCode() == WXK_NUMPAD_DIVIDE) OnDivide(e);
	else if (event.GetKeyCode() == WXK_NUMPAD_DECIMAL) OnDecimal(e);
	else if (event.GetKeyCode() == WXK_RETURN || event.GetKeyCode() == WXK_NUMPAD_ENTER) OnButtonEquals(e);
	else if (event.GetKeyCode() == WXK_ESCAPE) OnClear(e);
	else if (event.GetKeyCode() == WXK_LEFT) OnButtonLeftParen(e);
	else if (event.GetKeyCode() == WXK_RIGHT) OnButtonRightParen(e);
	else if (event.GetKeyCode() == WXK_F1) OnButtonSin(e);
	else if (event.GetKeyCode() == WXK_F2) OnButtonCos(e);
	else if (event.GetKeyCode() == WXK_F3) OnButtonTan(e);
	else if (event.GetKeyCode() == WXK_BACK){
		if(activeOperand == Left_Operand && leftOperand.size()) leftOperand.pop_back();
		else if(activeOperand == Right_Operand && rightOperand.size()) rightOperand.pop_back();
		UpdateResult();
	}
}

