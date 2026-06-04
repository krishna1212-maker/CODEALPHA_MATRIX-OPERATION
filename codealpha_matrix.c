#include <stdio.h>

#define MAX 10


void inputMatrix(int matrix[MAX][MAX], int rows, int cols, char name)
{
    printf("\nEnter elements of Matrix %c:\n", name);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("  [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}


void displayMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        printf("  | ");
        for (int j = 0; j < cols; j++)
        {
            printf("%4d ", matrix[i][j]);
        }
        printf("|\n");
    }
}


void addMatrix(int a[MAX][MAX], int b[MAX][MAX],
               int result[MAX][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = a[i][j] + b[i][j];
}


void multiplyMatrix(int a[MAX][MAX], int b[MAX][MAX],
                    int result[MAX][MAX], int r1, int c1, int c2)
{
    // Initialize result matrix to 0 first
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            result[i][j] = 0;

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                result[i][j] += a[i][k] * b[k][j];
}


void transposeMatrix(int matrix[MAX][MAX],
                     int result[MAX][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[j][i] = matrix[i][j];
}



int main()
{
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2;

   
    printf("        MATRIX OPERATIONS IN C          \n");
    

    printf("\nEnter rows and columns for Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &r2, &c2);

    inputMatrix(a, r1, c1, 'A');
    inputMatrix(b, r2, c2, 'B');

    int choice;
   
    printf("  Select Operation:\n");
    printf("  1. Matrix Addition\n");
    printf("  2. Matrix Multiplication\n");
    printf("  3. Transpose of Matrix A\n");
    printf("  4. Transpose of Matrix B\n");
    
    printf("  Enter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            if (r1 != r2 || c1 != c2)
            {
                printf("\nError: Addition requires same dimensions!\n");
                printf("Matrix A is %dx%d, Matrix B is %dx%d\n", r1, c1, r2, c2);
            }
            else
            {
                addMatrix(a, b, result, r1, c1);
                printf("\nResult of A + B:\n");
                displayMatrix(result, r1, c1);
            }
            break;

        case 2:
            if (c1 != r2)
            {
                printf("\nError: Multiplication requires cols of A == rows of B!\n");
                printf("Matrix A is %dx%d, Matrix B is %dx%d\n", r1, c1, r2, c2);
            }
            else
            {
                multiplyMatrix(a, b, result, r1, c1, c2);
                printf("\nResult of A x B:\n");
                displayMatrix(result, r1, c2);
            }
            break;

        case 3:
            transposeMatrix(a, result, r1, c1);
            printf("\nTranspose of Matrix A:\n");
            displayMatrix(result, c1, r1);
            break;

        case 4:
            transposeMatrix(b, result, r2, c2);
            printf("\nTranspose of Matrix B:\n");
            displayMatrix(result, c2, r2);
            break;

        default:
            printf("\nError: Invalid choice!\n");
    }

    return 0;
}
