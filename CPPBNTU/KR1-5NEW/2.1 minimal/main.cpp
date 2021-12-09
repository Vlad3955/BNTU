    #include <iostream>
    void prompt(int *val);
    void prompt(long *val);
    void prompt(double *val);
    int main()
    {
        int a1;
        long a2;
        double a3;
        prompt(&a1);
        prompt(&a2);
        prompt(&a3);
        std::cout << "You entered: " << a1 << '\t' << a2 << '\t' << a3;
    }
    void prompt(int *val)
    {
        std::cout << "Enter integer number: "; std::cin >> *val; std::cout << std::endl;
    }
    void prompt(long *val)
    {
        std::cout << "Enter long integer number: "; std::cin >> *val; std::cout << std::endl;
    }
    void prompt(double *val)
    {
        std::cout << "Enter floating number: "; std::cin >> *val; std::cout << std::endl;
    }