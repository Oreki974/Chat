#pragma once
#include <Application.h>

extern Chat::Application* Chat::CreateApplication(int argc, char** argv);
bool g_ApplicationRunning = true;

namespace Chat {

	int Main(int argc, char** argv)
	{
		while (g_ApplicationRunning)
		{
			Chat::Application* app = Chat::CreateApplication(argc, argv);
			app->Run();
			delete app;
		}

		return 0;
	}

}

#if defined(WL_PLATFORM_WINDOWS) && !defined(WL_HEADLESS) && defined(WL_DIST)

#include <Windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
	return Chat::Main(__argc, __argv);
}

#else

int main(int argc, char** argv)
{
	return Chat::Main(argc, argv);
}

#endif // defined(WL_PLATFORM_WINDOWS) && defined(WL_DIST)