#include "LayerTwo.h"

void LayerTwo::convolution()
{
    for (int i = 0; i < outputRowsLayerTwo; i++)
        for (int j = 0; j < outputColumnsLayerTwo; j++)
        {
            double sum = 0;
            for (int k = 0; k < filterRowsLayerTwo; k++)
                for (int l = 0; l < filterColumnsLayerTwo; l++)
                    sum += input[i * strideLayerTwo + k][j * strideLayerTwo + l].read() * filter[k][l].read();
            output[i][j].write(sum);
        }
}
