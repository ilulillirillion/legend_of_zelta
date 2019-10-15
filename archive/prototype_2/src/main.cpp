#include <Windows.h>
#include "engine.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
  Engine* engine = new Engine();

  try {
    engine->Go();
  } 
  catch(char* e) {
    MessageBoxA(NULL, e, "Exception Occured", MB_OK | MB_IConerror);
  }
}
