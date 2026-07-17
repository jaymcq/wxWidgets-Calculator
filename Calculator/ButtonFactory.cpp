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

// Button Size:
wxSize buttonSize(65, 35);

wxButton* ButtonFactory::CreateButton(wxWindow* parent, wxWindowID id, const wxString& name, const wxPoint& point, const wxSize& size)
{
    return new wxButton(parent, id, name, point, size);
}

wxButton* ButtonFactory::CreateAddButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_ADD, "+", wxDefaultPosition, buttonSize);
}

wxButton* ButtonFactory::CreateSubtractButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_SUBTRACT, "-", wxDefaultPosition, buttonSize);
}

wxButton* ButtonFactory::CreateMultiplyButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_MULTIPLY, "*", wxDefaultPosition, buttonSize);
}

wxButton* ButtonFactory::CreateDivideButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_DIVIDE, "/", wxDefaultPosition, buttonSize);
}

wxButton* ButtonFactory::CreateModuloButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_MODULO, "%", wxDefaultPosition, buttonSize);
}

wxButton* ButtonFactory::CreateZeroButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_0, "0", wxDefaultPosition, buttonSize);
}

wxButton* ButtonFactory::CreateOneButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_1, "1", wxDefaultPosition, buttonSize);
}

wxButton* ButtonFactory::CreateTwoButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_2, "2", wxDefaultPosition, buttonSize);
}

wxButton* ButtonFactory::CreateThreeButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_3, "3", wxDefaultPosition, buttonSize);
}

wxButton* ButtonFactory::CreateFourButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_4, "4", wxDefaultPosition, buttonSize);
}

wxButton* ButtonFactory::CreateFiveButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_5, "5", wxDefaultPosition, buttonSize);
}

wxButton* ButtonFactory::CreateSixButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_6, "6", wxDefaultPosition, buttonSize);
}

wxButton* ButtonFactory::CreateSevenButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_7, "7", wxDefaultPosition, buttonSize);
}

wxButton* ButtonFactory::CreateEightButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_8, "8", wxDefaultPosition, buttonSize);
}

wxButton* ButtonFactory::CreateNineButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_9, "9", wxDefaultPosition, buttonSize);
}

wxButton* ButtonFactory::CreateDecimalButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_DECIMAL, ".", wxDefaultPosition, buttonSize);
}

wxButton* ButtonFactory::CreatePosNegButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_PLUS_MINUS, "+/-", wxDefaultPosition, buttonSize);
}

wxButton* ButtonFactory::CreateCosButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_COS, "COS", wxDefaultPosition, buttonSize);
}

wxButton* ButtonFactory::CreateSinButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_SIN, "SIN", wxDefaultPosition, buttonSize);
}

wxButton* ButtonFactory::CreateTanButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_TAN, "TAN", wxDefaultPosition, buttonSize);
}

wxButton* ButtonFactory::CreateBackspaceButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_BACKSPACE, "<-", wxDefaultPosition, buttonSize);
}

wxButton* ButtonFactory::CreateEqualsButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_EQUALS, "=", wxDefaultPosition, buttonSize);
}

wxButton* ButtonFactory::CreateLeftParenButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_LEFT_PAREN, "(", wxDefaultPosition, buttonSize);
}

wxButton* ButtonFactory::CreateRightParenButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_RIGHT_PAREN, ")", wxDefaultPosition, buttonSize);
}

wxButton* ButtonFactory::CreateClearButton(wxWindow* parent)
{
    return CreateButton(parent, BUTTON_CLEAR, "Clear", wxDefaultPosition, buttonSize);
}
