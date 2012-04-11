#include <iostream>

#include "InterfaceGUIControls.h"


int main(int argc, char *argv[])
{
  InterfaceGUIControls *MainWindow = new InterfaceGUIControls(0,0,1010,715,"Win");
  
  Fl::run();
  delete MainWindow;
  
  return 1;
}
