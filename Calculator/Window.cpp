#include "Window.h"




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

	// Buttons:

	buttonSin = new wxButton(this, wxID_ANY, _("Sin"), wxDefaultPosition, wxSize(65, 35), 0);
	GridButtonSizer->Add(buttonSin, 0, wxALL, 5);

	buttonCos = new wxButton(this, wxID_ANY, _("Cos"), wxDefaultPosition, wxSize(65, 35), 0);
	GridButtonSizer->Add(buttonCos, 0, wxALL, 5);

	buttonTan = new wxButton(this, wxID_ANY, _("Tan"), wxDefaultPosition, wxSize(65, 35), 0);
	GridButtonSizer->Add(buttonTan, 0, wxALL, 5);

	buttonClear = new wxButton(this, wxID_ANY, _("Clear"), wxDefaultPosition, wxSize(65, 35), 0);
	GridButtonSizer->Add(buttonClear, 0, wxALL, 5);

	button7 = new wxButton(this, wxID_ANY, _("7"), wxDefaultPosition, wxSize(65, 35), 0);
	GridButtonSizer->Add(button7, 0, wxALL, 5);

	button8 = new wxButton(this, wxID_ANY, _("8"), wxDefaultPosition, wxSize(65, 35), 0);
	GridButtonSizer->Add(button8, 0, wxALL, 5);

	button9 = new wxButton(this, wxID_ANY, _("9"), wxDefaultPosition, wxSize(65, 35), 0);
	GridButtonSizer->Add(button9, 0, wxALL, 5);

	buttonMultiply = new wxButton(this, wxID_ANY, _("*"), wxDefaultPosition, wxSize(65, 35), 0);
	GridButtonSizer->Add(buttonMultiply, 0, wxALL, 5);

	button4 = new wxButton(this, wxID_ANY, _("4"), wxDefaultPosition, wxSize(65, 35), 0);
	GridButtonSizer->Add(button4, 0, wxALL, 5);

	button5 = new wxButton(this, wxID_ANY, _("5"), wxDefaultPosition, wxSize(65, 35), 0);
	GridButtonSizer->Add(button5, 0, wxALL, 5);

	button6 = new wxButton(this, wxID_ANY, _("6"), wxDefaultPosition, wxSize(65, 35), 0);
	GridButtonSizer->Add(button6, 0, wxALL, 5);

	buttonDivide = new wxButton(this, wxID_ANY, _("/"), wxDefaultPosition, wxSize(65, 35), 0);
	GridButtonSizer->Add(buttonDivide, 0, wxALL, 5);

	button1 = new wxButton(this, wxID_ANY, _("1"), wxDefaultPosition, wxSize(65, 35), 0);
	GridButtonSizer->Add(button1, 0, wxALL, 5);

	button2 = new wxButton(this, wxID_ANY, _("2"), wxDefaultPosition, wxSize(65, 35), 0);
	GridButtonSizer->Add(button2, 0, wxALL, 5);

	button3 = new wxButton(this, wxID_ANY, _("3"), wxDefaultPosition, wxSize(65, 35), 0);
	GridButtonSizer->Add(button3, 0, wxALL, 5);

	buttonAdd = new wxButton(this, wxID_ANY, _("+"), wxDefaultPosition, wxSize(65, 35), 0);
	GridButtonSizer->Add(buttonAdd, 0, wxALL, 5);

	buttonDecimal = new wxButton(this, wxID_ANY, _("."), wxDefaultPosition, wxSize(65, 35), 0);
	GridButtonSizer->Add(buttonDecimal, 0, wxALL, 5);

	button0 = new wxButton(this, wxID_ANY, _("0"), wxDefaultPosition, wxSize(65, 35), 0);
	GridButtonSizer->Add(button0, 0, wxALL, 5);

	buttonEquals = new wxButton(this, wxID_ANY, _("="), wxDefaultPosition, wxSize(65, 35), 0);
	GridButtonSizer->Add(buttonEquals, 0, wxALL, 5);

	buttonLeftParen = new wxButton(this, wxID_ANY, _("("), wxDefaultPosition, wxSize(65, 35), 0);
	GridButtonSizer->Add(buttonLeftParen, 0, wxALL, 5);

	buttonBackspace = new wxButton(this, wxID_ANY, _("<-"), wxDefaultPosition, wxSize(65, 35), 0);
	GridButtonSizer->Add(buttonBackspace, 0, wxALL, 5);

	buttonPlusMinus = new wxButton(this, wxID_ANY, _("+/-"), wxDefaultPosition, wxSize(65, 35), 0);
	GridButtonSizer->Add(buttonPlusMinus, 0, wxALL, 5);

	buttonModulo = new wxButton(this, wxID_ANY, _("%"), wxDefaultPosition, wxSize(65, 35), 0);
	GridButtonSizer->Add(buttonModulo, 0, wxALL, 5);

	buttonRightParen = new wxButton(this, wxID_ANY, _(")"), wxDefaultPosition, wxSize(65, 35), 0);
	GridButtonSizer->Add(buttonRightParen, 0, wxALL, 5);

	topLevelSizer->Add(GridButtonSizer, 1, wxEXPAND, 5);

	this->SetSizer(topLevelSizer);
	this->Layout();

	this->Center(wxBOTH);




	// Event Tables:
	buttonSin->Bind(wxEVT_BUTTON, &Window::OnButtonClicked, this);
	buttonCos->Bind(wxEVT_BUTTON, &Window::OnButtonClicked, this);
	buttonTan->Bind(wxEVT_BUTTON, &Window::OnButtonClicked, this);
	buttonClear->Bind(wxEVT_BUTTON, &Window::OnButtonClicked, this);
	button7->Bind(wxEVT_BUTTON, &Window::OnButtonClicked, this);
	button8->Bind(wxEVT_BUTTON, &Window::OnButtonClicked, this);
	button9->Bind(wxEVT_BUTTON, &Window::OnButtonClicked, this);
	buttonMultiply->Bind(wxEVT_BUTTON, &Window::OnButtonClicked, this);
	button4->Bind(wxEVT_BUTTON, &Window::OnButtonClicked, this);
	button5->Bind(wxEVT_BUTTON, &Window::OnButtonClicked, this);
	button6->Bind(wxEVT_BUTTON, &Window::OnButtonClicked, this);
	buttonDivide->Bind(wxEVT_BUTTON, &Window::OnButtonClicked, this);
	button1->Bind(wxEVT_BUTTON, &Window::OnButtonClicked, this);
	button2->Bind(wxEVT_BUTTON, &Window::OnButtonClicked, this);
	button3->Bind(wxEVT_BUTTON, &Window::OnButtonClicked, this);
	buttonAdd->Bind(wxEVT_BUTTON, &Window::OnButtonClicked, this);
	buttonDecimal->Bind(wxEVT_BUTTON, &Window::OnButtonClicked, this);
	button0->Bind(wxEVT_BUTTON, &Window::OnButtonClicked, this);
	buttonEquals->Bind(wxEVT_BUTTON, &Window::OnButtonClicked, this);
	buttonLeftParen->Bind(wxEVT_BUTTON, &Window::OnButtonClicked, this);
	buttonBackspace->Bind(wxEVT_BUTTON, &Window::OnButtonClicked, this);
	buttonPlusMinus->Bind(wxEVT_BUTTON, &Window::OnButtonClicked, this);
	buttonModulo->Bind(wxEVT_BUTTON, &Window::OnButtonClicked, this);
	buttonRightParen->Bind(wxEVT_BUTTON, &Window::OnButtonClicked, this);

}

void Window::OnButtonClicked(wxCommandEvent& event)
{
	wxObject* obj = event.GetEventObject();
	wxButton* button = dynamic_cast<wxButton*>(obj);
	if (!button || !textBox)
		return;

	wxString buttonLabel = button->GetLabel();
	if (buttonLabel == "Clear")
		textBox->Clear();
	else if (buttonLabel == "<-") {
		wxString currentText = textBox->GetValue();
		if (!currentText.IsEmpty()) {
			currentText.RemoveLast();
			textBox->SetValue(currentText);
		}
		else if (buttonLabel == "=") {
			wxString currentText = textBox->GetValue();
			//double result = EvaluateExpression(currentText);
			//textBox->SetValue(wxString::Format("%f", result));
		}
		else {
			textBox->AppendText(buttonLabel);
		}
	}
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

void Window::onButtonBackspace(wxCommandEvent& event)
{
	if (activeOperand == Left_Operand)
		leftOperand.pop_back();
	else
		rightOperand.pop_back();
	UpdateResult();
}

void Window::onButtonPlusMinus(wxCommandEvent& event)
{
}

void Window::onButtonLeftParen(wxCommandEvent& event)
{
}

void Window::onButtonRightParen(wxCommandEvent& event)
{
}

void Window::onButtonSin(wxCommandEvent& event)
{
}

void Window::onButtonCos(wxCommandEvent& event)
{
}

void Window::onButtonTan(wxCommandEvent& event)
{
}

void Window::onButtonModulo(wxCommandEvent& event)
{
}

void Window::onButtonEquals(wxCommandEvent& event)
{
}

void Window::UpdateResultDisplay()
{
}

void Window::onKeypadInput(wxKeyEvent& event)
{
}

void Window::UpdateResult(){
	if (activeOperand == Left_Operand)
	{
		result = std::stod(leftOperand);
	}
	else if (activeOperand == Right_Operand)
	{
		result = std::stod(rightOperand);
	}
	UpdateResultDisplay();
}
