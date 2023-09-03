#include "LayerOne.h"
#include <queue>

void LayerOne::convolution()
{
        queue<double> FIFO;
        for (int i = 0; i < outputRowsLayerOne; i++)
            for (int j = 0; j < outputColumnsLayerOne; j++)
            {
                double sum = 0;
                for (int k = 0; k < filterRowsLayerOne; k++)
                    for (int l = 0; l < filterColumnsLayerOne; l++)
                        sum += input[i * strideLayerOne + k][j * strideLayerOne + l].read() * filter[k][l].read();
                FIFO.push(sum);
            }
        for (int i = 0; i < outputRowsLayerOne; i++)
            for (int j = 0; j < outputColumnsLayerOne; j++)
            {
                output[i][j].write(FIFO.front());
                FIFO.pop();
            }
}
