#pragma once
#include "wx/wx.h"


class ButtonFactory
{
public:

	static wxButton* CreateButton(wxWindow* parent, wxWindowID id, const wxString& name, const wxPoint& point, const wxSize& size);

	// Create function buttons:
	static wxButton* CreateAddButton(wxWindow* parent);
	static wxButton* CreateSubtractButton(wxWindow* parent);
	static wxButton* CreateMultiplyButton(wxWindow* parent);
	static wxButton* CreateDivideButton(wxWindow* parent);
	static wxButton* CreateModuloButton(wxWindow* parent);

	// Create number buttons:
	static wxButton* CreateZeroButton(wxWindow* parent);
	static wxButton* CreateOneButton(wxWindow* parent);
	static wxButton* CreateTwoButton(wxWindow* parent);
	static wxButton* CreateThreeButton(wxWindow* parent);
	static wxButton* CreateFourButton(wxWindow* parent);
	static wxButton* CreateFiveButton(wxWindow* parent);
	static wxButton* CreateSixButton(wxWindow* parent);
	static wxButton* CreateSevenButton(wxWindow* parent);
	static wxButton* CreateEightButton(wxWindow* parent);
	static wxButton* CreateNineButton(wxWindow* parent);

	// Other buttons:
	static wxButton* CreateDecimalButton(wxWindow* parent);
	static wxButton* CreatePlusMinusButton(wxWindow* parent);
	static wxButton* CreateCosButton(wxWindow* parent);
	static wxButton* CreateSinButton(wxWindow* parent);
	static wxButton* CreateTanButton(wxWindow* parent);
	static wxButton* CreateBackspaceButton(wxWindow* parent);
	static wxButton* CreateEqualsButton(wxWindow* parent);
	static wxButton* CreateLeftParenButton(wxWindow* parent);
	static wxButton* CreateRightParenButton(wxWindow* parent);
	static wxButton* CreateClearButton(wxWindow* parent);


};

