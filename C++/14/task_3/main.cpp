#include <iostream>

void inputMatrix(int matrix[][4]);
bool compareMatrices(int matrix1[][4], int matrix2[][4]);
void convertToDiagonalMatrix(int matrix[][4]);
void outputMatrix(int matrix[][4]);

int main()
{
    int matrix1[4][4];
    int matrix2[4][4];

    //input matrices
    std::cout << "Input two matrices. First matrix:" << std::endl;
    inputMatrix(matrix1);
    std::cout << "Input second matrix:" << std::endl;
    inputMatrix(matrix2);

    if(compareMatrices(matrix1, matrix2))
    {
        std::cout << "Matrices are equal" << std::endl;
        convertToDiagonalMatrix(matrix1);
        //output 1 matrix
        outputMatrix(matrix1);
    }
    else
    {
        std::cout << "Matrices are not equal";
    }
    return 0;
}

void inputMatrix(int matrix[][4])
{
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }
}

bool compareMatrices(int matrix1[][4], int matrix2[][4])
{
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            if(matrix1[i][j]!=matrix2[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

void convertToDiagonalMatrix(int matrix[][4])
{
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            if(i != j)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

void outputMatrix(int matrix[][4])
{
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}