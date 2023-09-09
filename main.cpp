#include "Program/Program.hpp"

int main()
{
    Program p;
    while(p.running())
    {
        p.update();
        p.render();
    }
}

/*

TODO add enable/disable and visible options

*/