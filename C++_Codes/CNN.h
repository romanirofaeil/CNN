#include "Queue.cpp"

using namespace std;

const int inputRowsLayerOne = 28;
const int inputColumnsLayerOne = 28;
const int filterRowsLayerOne = 2;
const int filterColumnsLayerOne = 2;
const int strideLayerOne = 2;
const int outputRowsLayerOne = (inputRowsLayerOne - filterRowsLayerOne) / strideLayerOne + 1;
const int outputColumnsLayerOne = (inputColumnsLayerOne - filterColumnsLayerOne) / strideLayerOne + 1;
const int inputRowsLayerTwo = outputRowsLayerOne;
const int inputColumnsLayerTwo = outputColumnsLayerOne;
const int filterRowsLayerTwo = 2;
const int filterColumnsLayerTwo = 2;
const int strideLayerTwo = 2;
const int outputRowsLayerTwo = (inputRowsLayerTwo - filterRowsLayerTwo) / strideLayerTwo + 1;
const int outputColumnsLayerTwo = (inputColumnsLayerTwo - filterColumnsLayerTwo) / strideLayerTwo + 1;

Queue<double, 196> convolutionLayerOne(double input[inputRowsLayerOne][inputColumnsLayerOne], double filter[filterRowsLayerOne][filterColumnsLayerOne], int stride, Queue<double, 196> FIFO);

void convolutionLayerTwo(double input[inputRowsLayerTwo][inputColumnsLayerTwo], double filter[filterRowsLayerTwo][filterColumnsLayerTwo], int stride, double output[outputRowsLayerTwo][outputColumnsLayerTwo]);

void convolutionNeuralNetwork(double input[inputRowsLayerOne][inputColumnsLayerOne], double filterLayerOne[filterRowsLayerOne][filterColumnsLayerOne], int strideLayerOne, double outputLayerOne[outputRowsLayerOne][outputColumnsLayerOne], double filterLayerTwo[filterRowsLayerTwo][filterColumnsLayerTwo], int strideLayerTwo, double output[outputRowsLayerTwo][outputColumnsLayerTwo]);
