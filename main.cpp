#include "src/Program.hpp"

/* WINDOWS COMPILE COMANDS 

mkdir build
cd build
cmake -G "MinGW Makefiles" .. 
mingw32-make -j4
.\SimpleGUI.exe

*/


int main()
{
    Program p;
    while(p.running())
    {
        p.update();
        p.render();
    }
}
