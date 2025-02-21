#include "sparkle.hpp"

int main()
{
	spk::GraphicalApplication app = spk::GraphicalApplication();

	spk::SafePointer<spk::Window> win = app.createWindow(L"Sparkle Dummy Project", {{0, 0}, {800, 800}});
	
	return (app.run());
}