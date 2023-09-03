#include <systemc.h>

using namespace std;

const int inputRowsLayerOne = 28;
const int inputColumnsLayerOne = 28;
const int filterRowsLayerOne = 2;
const int filterColumnsLayerOne = 2;
const int strideLayerOne = 2;
const int outputRowsLayerOne = (inputRowsLayerOne - filterRowsLayerOne) / strideLayerOne + 1;
const int outputColumnsLayerOne = (inputColumnsLayerOne - filterColumnsLayerOne) / strideLayerOne + 1;

SC_MODULE(LayerOne)
{
    sc_in<bool> clk;
    sc_in<double> input[inputRowsLayerOne][inputColumnsLayerOne];
    sc_in<double> filter[filterRowsLayerOne][filterColumnsLayerOne];
    sc_out<double> output[outputRowsLayerOne][outputColumnsLayerOne];

    void convolution();

    SC_CTOR(LayerOne)
    {
        SC_METHOD(convolution);
        sensitive << clk.pos();
    }
};
