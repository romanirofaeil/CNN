#include <systemc.h>

using namespace std;

const int inputRowsLayerTwo = 14;
const int inputColumnsLayerTwo = 14;
const int filterRowsLayerTwo = 2;
const int filterColumnsLayerTwo = 2;
const int strideLayerTwo = 2;
const int outputRowsLayerTwo = (inputRowsLayerTwo - filterRowsLayerTwo) / strideLayerTwo + 1;
const int outputColumnsLayerTwo = (inputColumnsLayerTwo - filterColumnsLayerTwo) / strideLayerTwo + 1;

SC_MODULE(LayerTwo)
{
    sc_in<bool> clk;
    sc_in<double> input[inputRowsLayerTwo][inputColumnsLayerTwo];
    sc_in<double> filter[filterRowsLayerTwo][filterColumnsLayerTwo];
    sc_out<double> output[outputRowsLayerTwo][outputColumnsLayerTwo];

    void convolution();

    SC_CTOR(LayerTwo)
    {
        SC_METHOD(convolution);
        sensitive << clk.pos();
    }
};
