#include "ButtonFactory.h"
#include "wx/wx.h"

wxButton* ButtonFactory::CreateButton(wxWindow* parent, wxWindowID id, const wxString& name, const wxPoint& point, const wxSize& size)
{
    wxButton* button = new wxButton(parent, id, name, point, size);
    button->SetBackgroundColour(wxColour(211, 211, 211)); // Light grey
    button->SetForegroundColour(*wxBLACK);
    return button;
}

wxButton* ButtonFactory::CreateNumberButton(wxWindow* parent, wxWindowID id, const wxString& number)
{
    return CreateButton(parent, id, number);
}

wxButton* ButtonFactory::CreateAddButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_ADD, "+");
}

wxButton* ButtonFactory::CreateSubtractButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_SUBTRACT, "-");
}

wxButton* ButtonFactory::CreateMultiplyButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_MULTIPLY, "*");
}

wxButton* ButtonFactory::CreateDivideButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_DIVIDE, "/");
}

wxButton* ButtonFactory::CreateModuloButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_MODULO, "%");
}

wxButton* ButtonFactory::CreateDecimalButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_DECIMAL, ".");
}

wxButton* ButtonFactory::CreatePlusMinusButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_PLUSMINUS, "+/-");
}

wxButton* ButtonFactory::CreateCosButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_COS, "COS");
}

wxButton* ButtonFactory::CreateSinButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_SIN, "SIN");
}

wxButton* ButtonFactory::CreateTanButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_TAN, "TAN");
}

wxButton* ButtonFactory::CreateBackspaceButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_BACKSPACE, "<-");
}

wxButton* ButtonFactory::CreateEqualsButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_EQUALS, "=");
}

wxButton* ButtonFactory::CreateLeftParenButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_LEFTPAREN, "(");
}

wxButton* ButtonFactory::CreateRightParenButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_RIGHTPAREN, ")");
}

wxButton* ButtonFactory::CreateClearButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_CLEAR, "Clear");
}
