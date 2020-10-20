#include "lib.h"

int main()
{
    float det;
    matrixOptional *matrixA;
    matrixOptional *matrixB;
    matrixOptional *matrixSum;
    matrixOptional *matrixMul;
    
    matrixA = matrixInput(2, 2);
    matrixB = matrixInput(2, 2);

    det = matrixDeterminant(matrixA);
    matrixSum = matrixFold(matrixA, matrixB);
    matrixMul = matrixMultiplication(matrixA, matrixB);
    matrixProductPerNumber(matrixA, 2);

    printf("determinant is %f\n", det); 
    matrixOutput(matrixA);
    matrixOutput(matrixSum);
    matrixOutput(matrixMul);
    
    matrixFree(matrixB);
    matrixFree(matrixA);
    matrixFree(matrixSum);
    matrixFree(matrixMul);
    return 0;
}
