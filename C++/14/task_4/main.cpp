#include <iostream>

void inputMatrix(int matrix[][4], int a, int b);
int* multiplyMatrixOnVector(int matrix[][4], int vector[][4]);

int main()
{
    int matrix[4][4];
    int vector[1][4];//сделал такое объявление, чтобы с помощью одной и той же функции вводить с консоли и матрицы и вектора
    int* result;

    std::cout << "Input matrix and vector. Matrix:" << std::endl;
    inputMatrix(matrix, 4, 4);
    std::cout << "Input vector:" << std::endl;
    inputMatrix(vector, 1, 4);

    result = multiplyMatrixOnVector(matrix, vector);

    std::cout << "Output result vector:" << std::endl;
    for(int i = 0; i < 4; ++i)
    {
        std::cout << result[i] << std::endl;
    }

    return 0;
}

void inputMatrix(int matrix[][4], int a, int b)
{
    for(int i = 0; i < a; ++i)
    {
        for(int j = 0; j < b; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }
}

int* multiplyMatrixOnVector(int matrix[][4], int vector[][4])
{
    int* result = new int[4];
    //если объявлял здесь статический массив int result[4], то не компилировалось,
    //выдавал ошибку присваивания на 17 строчке в main, не понял почему
    //ведь массив - это же указатель
    //поясните пожалуйста

    for(int i = 0, sum = 0; i < 4; ++i, sum = 0)
    {
        for(int j = 0; j < 4; ++j)
        {
            sum += matrix[i][j]*vector[1][j];
        }
        result[i] = sum;
    }
    return result;
}
