// CppReferencesPointersProject.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>

void StartExample();
void DynamicArrayExample();
void VoidPointerExample();
void AddressArithmExample();
void MatrixDynamicExample();

int** MatrixCreate(int rows);
void MatrixInit(int** matrix, int rows);
void MatrixPrint(int** matrix, int rows);
void MatrixDelete(int** matrix, int rows);

void ArraySort(int* array);


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
    srand(time(nullptr));

    int rows{ 5 };
    int** matrix = MatrixCreate(rows);
    MatrixPrint(matrix, rows);

    MatrixInit(matrix, rows);
    MatrixPrint(matrix, rows);

    for (int i{}; i < rows; i++)
        ArraySort(matrix[i]);
    MatrixPrint(matrix, rows);

    MatrixDelete(matrix, rows);

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

void DynamicArrayExample()
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

void VoidPointerExample()
{
    int n{ 123 };
    int* iptr;

    float x{ 123.0 };
    float* fptr{ &x };

    void* vptr;
    vptr = fptr;

    iptr = (int*)vptr;

    std::cout << fptr << " " << iptr << "\n";
    std::cout << *fptr << " " << *iptr << "\n";

    *iptr = 123;

    std::cout << *fptr << " " << *iptr << "\n";
}

void AddressArithmExample()
{
    srand(time(nullptr));

    int size{ 10 };
    int* array = new int[size];

    for (int i{}; i < size; i++)
        //array[i] = rand() % 100;
        *(array + i) = rand() % 100;


    int n{ 123 };
    int* iptr{ &n };

    std::cout << iptr << " " << iptr + 2 << "\n";

    *iptr = 500;
    *(iptr + 2) = 500;

    std::cout << *iptr << " " << *(iptr + 2) << "\n";

    auto a{ 123 };
    auto b{ 34.78 };
    auto c{ '$' };
    auto d{ false };

    auto e{ a };
}

void MatrixDynamicExample()
{
    int n{ 123 };
    int* iptr{ &n };
    int** ipptr{ &iptr };

    std::cout << "ref of n: " << &n << "\n";
    std::cout << "value n: " << n << "\n\n";

    std::cout << "value of iptr: " << iptr << "\n";
    std::cout << "deref of iptr: " << *iptr << "\n";
    std::cout << "ref of iptr: " << &iptr << "\n\n";

    std::cout << "value of ipptr: " << ipptr << "\n";
    std::cout << "deref of ipptr: " << *ipptr << "\n";
    std::cout << "double deref of ipptr: " << **ipptr << "\n\n";

    // one dim array
    int size{ 10 };
    int* array = new int[size];
    delete[] array;

    // two dim matrix
    int rows{ 5 };
    int columns{ 7 };
    srand(time(nullptr));

    int** matrix = new int* [rows];
    int* sizes = new int[rows];
    for (int i{}; i < rows; i++)
    {
        //sizes[i] = 1 + rand() % 5;
        //matrix[i] = new int[sizes[i]];
        int size = 1 + rand() % 5;
        matrix[i] = new int[size + 1];
        matrix[i][0] = size;
    }


    /*for (int i{}; i < rows; i++)
        for (int j{}; j < columns; j++)
            matrix[i][j] = (i + 1) * 10 + (j + 1);

    for (int i{}; i < rows; i++)
    {
        for (int j{}; j < columns; j++)
            std::cout << std::setw(3) << matrix[i][j];
        std::cout << "\n";
    }*/




    for (int i{}; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;
}

int** MatrixCreate(int rows)
{
    
    int** matrix = new int*[rows];
    for (int i{}; i < rows; i++)
    {
        int size{ rand() % 6 + 5 };
        matrix[i] = new int[size + 1] {};
        matrix[i][0] = size;
    }
    return matrix;
}

void MatrixInit(int** matrix, int rows)
{
    for (int i{}; i < rows; i++)
        for (int j{ 1 }; j < matrix[i][0] + 1; j++)
            matrix[i][j] = rand() % 100;
}

void MatrixPrint(int** matrix, int rows)
{
    for (int i{}; i < rows; i++)
    {
        for (int j{}; j < matrix[i][0] + 1; j++)
            std::cout << std::setw(3) << matrix[i][j];
        std::cout << "\n";
    }
    std::cout << "\n";
}

void MatrixDelete(int** matrix, int rows)
{
    for (int i{}; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;
}

void ArraySort(int* array)
{
    for (int i{ 1 }; i < array[0] + 1; i++)
    {
        for (int j{ array[0] }; j > i; j--)
            if (array[j] < array[j - 1])
                Swap(array[j], array[j - 1]);
    }
}
