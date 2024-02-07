// CppReferencesPointersProject.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

void StartExample();


void func(const int& a)
{
    //a = 100;
    int c = a + 100;
}

void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}


void funcArray(int*& array)
{
    delete[] array;
}

int main()
{

    int n = 20;
    int m = 30;

    std::cout << n << " " << m << "\n";
    
    n = 50;
    Swap(n, m);

    std::cout << n << " " << m << "\n";

    //const int max = 200;
    //func(max);
    
    int size;
    std::cout << "input size: ";
    std::cin >> size;

    int* array{ nullptr };
    array = new int[size]; // = nullptr;

    delete[] array;
    array = nullptr;

    //


    /*    
    array = new int[size];
    for (int i{}; i < size; i++)
        array[i] = i + 1;

    funcArray(array);

    for (int i{}; i < size; i++)
        std::cout << array[i] << " ";*/



}

void StartExample()
{
    int n{ 123 };
    double x{ 34.56 };
    std::cout << n << " " << &n << "\n";
    std::cout << x << " " << &x << "\n\n";

    int* ptr = &n;
    double* fptr = &x;

    std::cout << ptr << " " << *ptr << "\n";
    std::cout << fptr << " " << *fptr << "\n\n";

    *ptr = 500;

    std::cout << n << "\n";

    const int& m{ n };
    n = 1000;

    const int* cptr = &n;
    //*cptr = 246;
    n = 246;

    int w{ 777 };

    int* const icptr = &n;
    cptr = &w;

    //const int* const cccptr = &n;
}
