#pragma once
#include "wx/wx.h"

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
	BUTTON_EQUALS = 1017,
	BUTTON_PLUSMINUS = 1018,
	BUTTON_COS = 1019,
	BUTTON_SIN = 1020,
	BUTTON_TAN = 1021,
	BUTTON_BACKSPACE = 1022,
	BUTTON_LEFTPAREN = 1023,
	BUTTON_RIGHTPAREN = 1024,
};

class ButtonFactory
{
public:

	static wxButton* CreateButton(wxWindow* parent, wxWindowID id, const wxString& name, const wxPoint& point = wxDefaultPosition, const wxSize& = wxSize(65, 35));

	// Create function buttons:
	static wxButton* CreateAddButton(wxWindow* parent);
	static wxButton* CreateSubtractButton(wxWindow* parent);
	static wxButton* CreateMultiplyButton(wxWindow* parent);
	static wxButton* CreateDivideButton(wxWindow* parent);
	static wxButton* CreateModuloButton(wxWindow* parent);

	// Create number buttons:
	static wxButton* CreateNumberButton(wxWindow* parent, wxWindowID id, const wxString& number);

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

