#pragma once
#include "wx/wx.h"

class ButtonFactory
{
public:
	wxButton* CreateButton(wxWindow* parent, wxWindowID id, const wxString& name, const wxPoint& point, const wxSize& size);

	// Create function buttons:
	wxButton* CreateAddButton(wxWindow* parent);
	wxButton* CreateSubtractButton(wxWindow* parent);
	wxButton* CreateMultiplyButton(wxWindow* parent);
	wxButton* CreateDivideButton(wxWindow* parent);
	wxButton* CreateModuloButton(wxWindow* parent);

	// Create number buttons:
	wxButton* CreateZeroButton(wxWindow* parent);
	wxButton* CreateOneButton(wxWindow* parent);
	wxButton* CreateTwoButton(wxWindow* parent);
	wxButton* CreateThreeButton(wxWindow* parent);
	wxButton* CreateFourButton(wxWindow* parent);
	wxButton* CreateFiveButton(wxWindow* parent);
	wxButton* CreateSixButton(wxWindow* parent);
	wxButton* CreateSevenButton(wxWindow* parent);
	wxButton* CreateEightButton(wxWindow* parent);
	wxButton* CreateNineButton(wxWindow* parent);

	// Other buttons:
	wxButton* CreateDecimalButton(wxWindow* parent);
	wxButton* CreatePosNegButton(wxWindow* parent);
	wxButton* CreateCosButton(wxWindow* parent);
	wxButton* CreateSinButton(wxWindow* parent);
	wxButton* CreateTanButton(wxWindow* parent);
	wxButton* CreateBackspaceButton(wxWindow* parent);
	wxButton* CreateEqualsButton(wxWindow* parent);
	wxButton* CreateLeftParenButton(wxWindow* parent);
	wxButton* CreateRightParenButton(wxWindow* parent);
	wxButton* CreateClearButton(wxWindow* parent);

};

