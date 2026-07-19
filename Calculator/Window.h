#pragma once
#include "wx/wx.h"
#include "ButtonFactory.h"



class Window : public wxFrame
{
private:

	// Number Buttons:
	std::vector<std::shared_ptr<wxButton>> numberButtons; // Vector to hold number buttons
	

	// Operator Buttons:
	wxButton *buttonAdd, *buttonSubtract, *buttonMultiply, *buttonDivide, *buttonModulo;

	// Other Buttons:
	wxButton *buttonClear, *buttonDecimal, *buttonBackspace, *buttonEquals, *buttonPlusMinus, *buttonLeftParen, *buttonRightParen, *buttonSin, *buttonCos, *buttonTan;


	// Output Box:
	wxTextCtrl* textBox = nullptr;

	// Event handler for button clicks:
	wxCommandEvent e; 


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
	void OnButtonBackspace(wxCommandEvent& event);
	void OnButtonPlusMinus(wxCommandEvent& event);
	void OnButtonLeftParen(wxCommandEvent& event);
	void OnButtonRightParen(wxCommandEvent& event);
	void OnButtonSin(wxCommandEvent& event);
	void OnButtonCos(wxCommandEvent& event);
	void OnButtonTan(wxCommandEvent& event);
	void OnButtonModulo(wxCommandEvent& event);
	void OnButtonEquals(wxCommandEvent& event);
    void AppendExpression(const wxString& value);
	void OnKeypadInput(wxKeyEvent& event);


public:

	// Default constructor:
	Window();



};
