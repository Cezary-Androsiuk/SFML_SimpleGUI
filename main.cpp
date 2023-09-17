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
