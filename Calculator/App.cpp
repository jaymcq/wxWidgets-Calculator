#include "App.h"
#include "Window.h"

wxIMPLEMENT_APP(App);

// Initialize the application:
bool App::OnInit() {
	window = new Window();
	window->Show();
	return true;
}
