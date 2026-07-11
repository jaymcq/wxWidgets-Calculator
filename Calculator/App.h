#pragma once
#include "wx/wx.h"

// Forward declaration of the Window class:
class Window;

class App : public wxApp
{
	Window* window = nullptr;

public:
	virtual bool OnInit();
};