#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    float **matrix;
    int rows;
    int columns;
} matrixOptional; /*structure, that contains numbers of rows and columns of certain matrix, and a pointer to that matrix*/

matrixOptional *memoryAllocation(int row, int column);

matrixOptional *matrixInput(int row, int column);

matrixOptional *matrixFold(matrixOptional *matrix1, matrixOptional *matrix2);

matrixOptional *matrixProductPerNumber(matrixOptional *matrix1, float factor);

matrixOptional *matrixMultiplication(matrixOptional *matrix1, matrixOptional *matrix2);

float matrixDeterminant(matrixOptional *matrix1);

void matrixOutput(matrixOptional *matrix1);

void matrixFree(matrixOptional *matrix1);
