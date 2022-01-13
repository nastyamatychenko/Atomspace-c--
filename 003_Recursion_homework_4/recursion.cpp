#include <iostream>

unsigned long factorial (int);
unsigned int fibonacci(int);

int main()
{
    setlocale( LC_ALL,"Russian" );
    std::cout << "Enter number" << std::endl;
    int number; std::cin>>number;
    unsigned long result;
    result=factorial(number);
    std::cout <<"Factorial of number is:\t"<<result<< std::endl;
    result=fibonacci(number);
    std::cout <<"Fibonacci is:\t"<<result<< std::endl;
    return 0;
}


unsigned long factorial(int val)
{
    if(val>1)
    {
        return val*factorial(val-1);
    }
    return 1;
}

unsigned int fibonacci(int val)
{
    if (val<=1)
    {
        return 1;
    }
    return fibonacci(val-1)+fibonacci(val-2);
}
