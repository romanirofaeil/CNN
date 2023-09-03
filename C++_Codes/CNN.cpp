#include "CNN.h"
#include <iostream>

Queue<double, 196> convolutionLayerOne(double input[inputRowsLayerOne][inputColumnsLayerOne], double filter[filterRowsLayerOne][filterColumnsLayerOne], int stride, Queue<double, 196> FIFO)
{
    for (int i = 0; i < outputRowsLayerOne; i++)
        for (int j = 0; j < outputColumnsLayerOne; j++)
        {
            double sum = 0;
            for (int k = 0; k < filterRowsLayerOne; k++)
                for (int l = 0; l < filterColumnsLayerOne; l++)
                    sum += input[i * stride + k][j * stride + l] * filter[k][l];
            FIFO.push(sum);
        }
    return FIFO;
}

void convolutionLayerTwo(double input[inputRowsLayerTwo][inputColumnsLayerTwo], double filter[filterRowsLayerTwo][filterColumnsLayerTwo], int stride, double output[outputRowsLayerTwo][outputColumnsLayerTwo])
{
    for (int i = 0; i < outputRowsLayerTwo; i++)
        for (int j = 0; j < outputColumnsLayerTwo; j++)
        {
            double sum = 0;
            for (int k = 0; k < filterRowsLayerTwo; k++)
                for (int l = 0; l < filterColumnsLayerTwo; l++)
                    sum += input[i * stride + k][j * stride + l] * filter[k][l];
            output[i][j] = sum;
        }
}

void convolutionNeuralNetwork(double input[inputRowsLayerOne][inputColumnsLayerOne], double filterLayerOne[filterRowsLayerOne][filterColumnsLayerOne], int strideLayerOne, double outputLayerOne[outputRowsLayerOne][outputColumnsLayerOne], double filterLayerTwo[filterRowsLayerTwo][filterColumnsLayerTwo], int strideLayerTwo, double output[outputRowsLayerTwo][outputColumnsLayerTwo])
{
    Queue<double, 196> FIFO;
    FIFO = convolutionLayerOne(input, filterLayerOne, strideLayerOne, FIFO);
    for (int i = 0; i < outputRowsLayerOne; i++)
        for (int j = 0; j < outputColumnsLayerOne; j++)
        {
            outputLayerOne[i][j] = FIFO.front();
            FIFO.pop();
        }
    convolutionLayerTwo(outputLayerOne, filterLayerTwo, strideLayerTwo, output);
}
