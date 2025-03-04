/**
 * @FileName    :SpiralMatrix.c
 * @Date        :2025-03-04 14:54:46
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :螺旋矩阵（Spiral Matrix）
 * @Description :操作系统课程设计作业：根据输入的行数和列数生成螺旋矩阵
 */

#include <stdio.h>

void generateSpiralMatrix(int rows, int cols) {
    char matrix[rows][cols];
    char currentChar = 'A';
    int offset = 0;
    int rowStart = 0, rowEnd = rows - 1;
    int colStart = 0, colEnd = cols - 1;
    int i, j;

    while (rowStart <= rowEnd && colStart <= colEnd) {
        // Fill the top row from left to right
        for (j = colStart; j <= colEnd; j++)
            matrix[rowStart][j] = (currentChar + offset++ % 26);

        if (rowStart == rowEnd)
            break;

        // Fill the right column from top to bottom
        for (i = rowStart + 1; i <= rowEnd; i++)
            matrix[i][colEnd] = (currentChar + offset++ % 26);

        if (colStart == colEnd)
            break;

        // Fill the bottom row from right to left
        for (j = colEnd - 1; j >= colStart; j--)
            matrix[rowEnd][j] = (currentChar + offset++ % 26);

        // Fill the left column from bottom to top
        for (i = rowEnd - 1; i > rowStart; i--)
            matrix[i][colStart] = (currentChar + offset++ % 26);

        // Move to inner matrix
        rowStart++;
        rowEnd--;
        colStart++;
        colEnd--;
    }

    // Print the generated matrix
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    generateSpiralMatrix(rows, cols);

    return 0;
}
