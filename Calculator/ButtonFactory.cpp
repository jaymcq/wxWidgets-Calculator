#include "ButtonFactory.h"
#include "wx/wx.h"

wxButton* ButtonFactory::CreateButton(wxWindow* parent, wxWindowID id, const wxString& name, const wxPoint& point, const wxSize& size)
{
    return new wxButton(parent, id, name, point, size);
}

wxButton* ButtonFactory::CreateNumberButton(wxWindow* parent, wxWindowID id, const wxString& number)
{
    return CreateButton(parent, id, number);
}

wxButton* ButtonFactory::CreateAddButton(wxWindow* parent)
{
    return CreateButton(parent, ButtonId::Add, "+");
}

wxButton* ButtonFactory::CreateSubtractButton(wxWindow* parent)
{
    return CreateButton(parent, ButtonId::Subtract, "-");
}

wxButton* ButtonFactory::CreateMultiplyButton(wxWindow* parent)
{
    return CreateButton(parent, ButtonId::Multiply, "*");
}

wxButton* ButtonFactory::CreateDivideButton(wxWindow* parent)
{
    return CreateButton(parent, ButtonId::Divide, "/");
}

wxButton* ButtonFactory::CreateModuloButton(wxWindow* parent)
{
    return CreateButton(parent, ButtonId::Modulo, "%");
}

wxButton* ButtonFactory::CreateDecimalButton(wxWindow* parent)
{
    return CreateButton(parent, ButtonId::Decimal, ".");
}

wxButton* ButtonFactory::CreatePlusMinusButton(wxWindow* parent)
{
    return CreateButton(parent, ButtonId::PlusMinus, "+/-");
}

wxButton* ButtonFactory::CreateCosButton(wxWindow* parent)
{
    return CreateButton(parent, ButtonId::Cos, "COS");
}

wxButton* ButtonFactory::CreateSinButton(wxWindow* parent)
{
    return CreateButton(parent, ButtonId::Sin, "SIN");
}

wxButton* ButtonFactory::CreateTanButton(wxWindow* parent)
{
    return CreateButton(parent, ButtonId::Tan, "TAN");
}

wxButton* ButtonFactory::CreateBackspaceButton(wxWindow* parent)
{
    return CreateButton(parent, ButtonId::Backspace, "<-");
}

wxButton* ButtonFactory::CreateEqualsButton(wxWindow* parent)
{
    return CreateButton(parent, ButtonId::Equals, "=");
}

wxButton* ButtonFactory::CreateLeftParenButton(wxWindow* parent)
{
    return CreateButton(parent, ButtonId::LeftParenthesis, "(");
}

wxButton* ButtonFactory::CreateRightParenButton(wxWindow* parent)
{
    return CreateButton(parent, ButtonId::RightParenthesis, ")");
}

wxButton* ButtonFactory::CreateClearButton(wxWindow* parent)
{
    return CreateButton(parent, ButtonId::Clear, "Clear");
}
