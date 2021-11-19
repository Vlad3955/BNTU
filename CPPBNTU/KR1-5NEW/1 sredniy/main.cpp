#include "Timer.h"
#include <Windows.h>
int main()
{
    Timer t;
    t.start();
    Sleep(15);
    t.stop();
    t.printElapsedTime();
}
