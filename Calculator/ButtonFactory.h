#pragma once
#include "wx/wx.h"

namespace ButtonId
{
	constexpr wxWindowID Zero = 1000;
	constexpr wxWindowID One = 1001;
	constexpr wxWindowID Two = 1002;
	constexpr wxWindowID Three = 1003;
	constexpr wxWindowID Four = 1004;
	constexpr wxWindowID Five = 1005;
	constexpr wxWindowID Six = 1006;
	constexpr wxWindowID Seven = 1007;
	constexpr wxWindowID Eight = 1008;
	constexpr wxWindowID Nine = 1009;
	constexpr wxWindowID Add = 1010;
	constexpr wxWindowID Subtract = 1011;
	constexpr wxWindowID Multiply = 1012;
	constexpr wxWindowID Divide = 1013;
	constexpr wxWindowID Modulo = 1014;
	constexpr wxWindowID Clear = 1015;
	constexpr wxWindowID Decimal = 1016;
	constexpr wxWindowID Backspace = 1017;
	constexpr wxWindowID PlusMinus = 1018;
	constexpr wxWindowID LeftParenthesis = 1019;
	constexpr wxWindowID RightParenthesis = 1020;
	constexpr wxWindowID Sin = 1021;
	constexpr wxWindowID Cos = 1022;
	constexpr wxWindowID Tan = 1023;
	constexpr wxWindowID Equals = 1024;
}

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

