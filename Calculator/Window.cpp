#include "Window.h"
#include "ButtonFactory.h"
#include "CalculatorProcessor.h"





Window::Window() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(100, 100), wxSize(320, 375)) {
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetBackgroundColour(wxColour(64, 64, 64)); // Dark-grey border around the controls

	SetBackgroundColour(wxString("DARK GREY"));

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

	wxGridSizer* GridButtonSizer = new wxGridSizer(5, 5, 5, 5);



	// Operator Buttons:
	wxButton* addButton = ButtonFactory::CreateAddButton(this);
	wxButton* subtractButton = ButtonFactory::CreateSubtractButton(this);
	wxButton* multiplyButton = ButtonFactory::CreateMultiplyButton(this);
	wxButton* moduloButton = ButtonFactory::CreateModuloButton(this);
	wxButton* divideButton = ButtonFactory::CreateDivideButton(this);
	wxButton* clearButton = ButtonFactory::CreateClearButton(this);
	wxButton* decimalButton = ButtonFactory::CreateDecimalButton(this);
	wxButton* backspaceButton = ButtonFactory::CreateBackspaceButton(this);
	wxButton* plusMinusButton = ButtonFactory::CreatePlusMinusButton(this);
	wxButton* leftParenButton = ButtonFactory::CreateLeftParenButton(this);
	wxButton* rightParenButton = ButtonFactory::CreateRightParenButton(this);
	wxButton* sinButton = ButtonFactory::CreateSinButton(this);
	wxButton* cosButton = ButtonFactory::CreateCosButton(this);
	wxButton* tanButton = ButtonFactory::CreateTanButton(this);
	wxButton* equalsButton = ButtonFactory::CreateEqualsButton(this);
	

	// Number Buttons:
	numberButtons.push_back(std::shared_ptr<wxButton>(ButtonFactory::CreateNumberButton(this, BUTTON_0, "0")));
	numberButtons.push_back(std::shared_ptr<wxButton>(ButtonFactory::CreateNumberButton(this, BUTTON_1, "1")));
	numberButtons.push_back(std::shared_ptr<wxButton>(ButtonFactory::CreateNumberButton(this, BUTTON_2, "2")));
	numberButtons.push_back(std::shared_ptr<wxButton>(ButtonFactory::CreateNumberButton(this, BUTTON_3, "3")));
	numberButtons.push_back(std::shared_ptr<wxButton>(ButtonFactory::CreateNumberButton(this, BUTTON_4, "4")));
	numberButtons.push_back(std::shared_ptr<wxButton>(ButtonFactory::CreateNumberButton(this, BUTTON_5, "5")));
	numberButtons.push_back(std::shared_ptr<wxButton>(ButtonFactory::CreateNumberButton(this, BUTTON_6, "6")));
	numberButtons.push_back(std::shared_ptr<wxButton>(ButtonFactory::CreateNumberButton(this, BUTTON_7, "7")));
	numberButtons.push_back(std::shared_ptr<wxButton>(ButtonFactory::CreateNumberButton(this, BUTTON_8, "8")));
	numberButtons.push_back(std::shared_ptr<wxButton>(ButtonFactory::CreateNumberButton(this, BUTTON_9, "9")));

	GridButtonSizer->Add(sinButton, 0, wxEXPAND);
	GridButtonSizer->Add(cosButton, 0, wxEXPAND);
	GridButtonSizer->Add(tanButton, 0, wxEXPAND);
	GridButtonSizer->Add(moduloButton, 0, wxEXPAND);
	GridButtonSizer->Add(clearButton, 0, wxEXPAND);

	GridButtonSizer->Add(numberButtons[7].get(), 0, wxEXPAND);
	GridButtonSizer->Add(numberButtons[8].get(), 0, wxEXPAND);
	GridButtonSizer->Add(numberButtons[9].get(), 0, wxEXPAND);
	GridButtonSizer->Add(divideButton, 0, wxEXPAND);
	GridButtonSizer->Add(plusMinusButton, 0, wxEXPAND);

	GridButtonSizer->Add(numberButtons[4].get(), 0, wxEXPAND);
	GridButtonSizer->Add(numberButtons[5].get(), 0, wxEXPAND);
	GridButtonSizer->Add(numberButtons[6].get(), 0, wxEXPAND);
	GridButtonSizer->Add(multiplyButton, 0, wxEXPAND);
	GridButtonSizer->Add(backspaceButton, 0, wxEXPAND);

	GridButtonSizer->Add(numberButtons[3].get(), 0, wxEXPAND);
	GridButtonSizer->Add(numberButtons[2].get(), 0, wxEXPAND);
	GridButtonSizer->Add(numberButtons[1].get(), 0, wxEXPAND);
	GridButtonSizer->Add(subtractButton, 0, wxEXPAND);
	GridButtonSizer->Add(addButton, 0, wxEXPAND);

	GridButtonSizer->Add(leftParenButton, 0, wxEXPAND);
	GridButtonSizer->Add(numberButtons[0].get(), 0, wxEXPAND);
	GridButtonSizer->Add(rightParenButton, 0, wxEXPAND);
	GridButtonSizer->Add(decimalButton, 0, wxEXPAND);
	GridButtonSizer->Add(equalsButton, 0, wxEXPAND);



	// Bind number buttons:
	numberButtons[0]->Bind(wxEVT_BUTTON, &Window::OnButton0, this);
	numberButtons[1]->Bind(wxEVT_BUTTON, &Window::OnButton1, this);
	numberButtons[2]->Bind(wxEVT_BUTTON, &Window::OnButton2, this);
	numberButtons[3]->Bind(wxEVT_BUTTON, &Window::OnButton3, this);
	numberButtons[4]->Bind(wxEVT_BUTTON, &Window::OnButton4, this);
	numberButtons[5]->Bind(wxEVT_BUTTON, &Window::OnButton5, this);
	numberButtons[6]->Bind(wxEVT_BUTTON, &Window::OnButton6, this);
	numberButtons[7]->Bind(wxEVT_BUTTON, &Window::OnButton7, this);
	numberButtons[8]->Bind(wxEVT_BUTTON, &Window::OnButton8, this);
	numberButtons[9]->Bind(wxEVT_BUTTON, &Window::OnButton9, this);

	// Bind functions:
	addButton->Bind(wxEVT_BUTTON, &Window::OnAdd, this);
	subtractButton->Bind(wxEVT_BUTTON, &Window::OnSubtract, this);
	multiplyButton->Bind(wxEVT_BUTTON, &Window::OnMultiply, this);
	divideButton->Bind(wxEVT_BUTTON, &Window::OnDivide, this);
	moduloButton->Bind(wxEVT_BUTTON, &Window::OnButtonModulo, this);
	sinButton->Bind(wxEVT_BUTTON, &Window::OnButtonSin, this);
	cosButton->Bind(wxEVT_BUTTON, &Window::OnButtonCos, this);
	tanButton->Bind(wxEVT_BUTTON, &Window::OnButtonTan, this);
	equalsButton->Bind(wxEVT_BUTTON, &Window::OnButtonEquals, this);
	
	// Bind extras:
	clearButton->Bind(wxEVT_BUTTON, &Window::OnClear, this);
	decimalButton->Bind(wxEVT_BUTTON, &Window::OnDecimal, this);
	backspaceButton->Bind(wxEVT_BUTTON, &Window::OnButtonBackspace, this);
	plusMinusButton->Bind(wxEVT_BUTTON, &Window::OnButtonPlusMinus, this);
	leftParenButton->Bind(wxEVT_BUTTON, &Window::OnButtonLeftParen, this);
	rightParenButton->Bind(wxEVT_BUTTON, &Window::OnButtonRightParen, this);

	topLevelSizer->Add(GridButtonSizer, 1, wxEXPAND, 5);

	this->SetSizer(topLevelSizer);
	this->Layout();

	this->Center(wxBOTH);

}


void Window::OnAdd(wxCommandEvent& event)
{
	AppendExpression("+");
}

void Window::OnSubtract(wxCommandEvent& event)
{
	AppendExpression("-");
}

void Window::OnDivide(wxCommandEvent& event)
{
	AppendExpression("/");
}

void Window::OnMultiply(wxCommandEvent& event)
{
	AppendExpression("*");
}

void Window::OnClear(wxCommandEvent& event)
{
	textBox->Clear();
	textBox->SetFocus();
}

void Window::OnDecimal(wxCommandEvent& event)
{
	AppendExpression(".");
}

void Window::OnButton1(wxCommandEvent& event)
{
	AppendExpression("1");
}

void Window::OnButton2(wxCommandEvent& event)
{
	AppendExpression("2");
}

void Window::OnButton3(wxCommandEvent& event)
{
	AppendExpression("3");
}

void Window::OnButton4(wxCommandEvent& event)
{
	AppendExpression("4");
}

void Window::OnButton5(wxCommandEvent& event)
{
	AppendExpression("5");
}

void Window::OnButton6(wxCommandEvent& event)
{
	AppendExpression("6");
}

void Window::OnButton7(wxCommandEvent& event)
{
	AppendExpression("7");
}

void Window::OnButton8(wxCommandEvent& event)
{
	AppendExpression("8");
}

void Window::OnButton9(wxCommandEvent& event)
{
	AppendExpression("9");
}

void Window::OnButton0(wxCommandEvent& event)
{
	AppendExpression("0");
}

void Window::OnButtonBackspace(wxCommandEvent& event)
{
	const long position = textBox->GetInsertionPoint();
	if (position > 0) {
		textBox->Remove(position - 1, position);
		textBox->SetInsertionPoint(position - 1);
	}
}

void Window::OnButtonPlusMinus(wxCommandEvent& event)
{
	AppendExpression("-");
}

void Window::OnButtonLeftParen(wxCommandEvent& event)
{
	AppendExpression("(");
}

void Window::OnButtonRightParen(wxCommandEvent& event)
{
	AppendExpression(")");
}

void Window::OnButtonSin(wxCommandEvent& event)
{
	AppendExpression("Sin");
}

void Window::OnButtonCos(wxCommandEvent& event)
{
	AppendExpression("Cos");
}

void Window::OnButtonTan(wxCommandEvent& event)
{
	AppendExpression("Tan");
}

void Window::OnButtonModulo(wxCommandEvent& event)
{
	AppendExpression("%");
}

void Window::OnButtonEquals(wxCommandEvent& event)
{
	try {
		const std::string expression = textBox->GetValue().ToStdString();
		const double result = CalculatorProcessor::GetInstance()->Calculate(expression);
		textBox->SetValue(wxString::Format("%.12g", result));
	}
	catch (const std::exception& error) {
		textBox->SetValue("Error: " + wxString::FromUTF8(error.what()));
	}
	textBox->SetFocus();
}

void Window::AppendExpression(const wxString& value)
{
	if (textBox->GetValue().StartsWith("Error:")) textBox->Clear();
	textBox->WriteText(value);
	textBox->SetFocus();
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
		OnButtonBackspace(e);
	}
}
