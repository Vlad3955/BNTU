#include <iostream>
#include "String_c.h"
int main()
{
    String_c s1("abcdabceabcf");
    String_c s2("abc");
    std::cout << "s1 = " << s1 << std::endl;
    std::cout << "s2 = " << s2 << std::endl;
    std::cout << "s1 - s2 = " << s1 - s2 << std::endl;
    std::cout << "s1 / s2 == " << s1 / s2 << std::endl;
    std::cout << "s3 = s1 + s2"; std::cout << std::endl;
    String_c s3 = s1 + s2;
    std::cout << "s3 = " << s3 << std::endl;
    std::cout << "s3 := s2" << std::endl;
    s3 = s2;
    std::cout << "s3 = " << s3 << std::endl;
    std::cout << std::boolalpha << "s3 == s2? - " << (s3 == s2) << std::endl;
    std::cout << std::boolalpha << "s1 == s2? - " << (s1 == s2) << std::endl;
    std::cout << "Position of 3rd entry of s2 into s1 = " << s1.at(s2, 3);
}
