#include <iostream>
#include "Buffer.h"
int main()
{
    Buffer buf;
    buf.append(1.f);
    buf.append(2.f);
    buf.append(3.f);
    std::cout << "Size: " << buf.getOccupiedSpaceSize() << std::endl;
    std::cout << "Space left: " << buf.getFreeSpaceSize() << std::endl;
    std::cout << "First element: " << buf.pop() << std::endl;
    std::cout << "Second element: " << buf.pop() << std::endl;
    std::cout << "Third element: " << buf.pop() << std::endl;
    std::cout << "Size: " << buf.getOccupiedSpaceSize() << std::endl;
    std::cout << "Space left: " << buf.getFreeSpaceSize() << std::endl;
}
