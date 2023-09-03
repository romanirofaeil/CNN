#include "LayerOne.h"
#include "LayerTwo.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <queue>

int sc_main(int argc, char* argv[]) {
    sc_signal<double> inputSignal[inputRowsLayerOne][inputColumnsLayerOne];
    sc_signal<double> filterOneSignal[filterRowsLayerOne][filterColumnsLayerOne];
    sc_signal<double> filterTwoSignal[filterRowsLayerTwo][filterColumnsLayerTwo];
    sc_signal<double> outputOneSignal[outputRowsLayerOne][outputColumnsLayerOne];
    sc_signal<double> outputTwoSignal[outputRowsLayerTwo][outputColumnsLayerTwo];
    sc_clock clkSignal;

    LayerOne firstLayer("LayerOne");
    for(int i = 0; i < inputRowsLayerOne; i++)
        for (int j = 0; j < inputColumnsLayerOne; j++)
        {
            firstLayer.input[i][j](inputSignal[i][j]);
        }
    for (int i = 0; i < filterRowsLayerOne; i++)
        for (int j = 0; j < filterColumnsLayerOne; j++)
        {
            firstLayer.filter[i][j](filterOneSignal[i][j]);
        }
    for (int i = 0; i < outputRowsLayerOne; i++)
        for (int j = 0; j < outputColumnsLayerOne; j++)
        {
            firstLayer.output[i][j](outputOneSignal[i][j]);
        }
    firstLayer.clk(clkSignal);

    LayerTwo secondLayer("LayerTwo");
    for(int i = 0; i < inputRowsLayerTwo; i++)
        for (int j = 0; j < inputColumnsLayerTwo; j++)
        {
            secondLayer.input[i][j](outputOneSignal[i][j]);
        }
    for (int i = 0; i < filterRowsLayerTwo; i++)
        for (int j = 0; j < filterColumnsLayerTwo; j++)
        {
            secondLayer.filter[i][j](filterTwoSignal[i][j]);
        }
    for (int i = 0; i < outputRowsLayerTwo; i++)
        for (int j = 0; j < outputColumnsLayerTwo; j++)
        {
            secondLayer.output[i][j](outputTwoSignal[i][j]);
        }
    secondLayer.clk(clkSignal);

    sc_start(1, SC_NS);
    ifstream file("inputs.csv");
    string line;
    if (getline(file, line))
    {
        stringstream ss(line);
        string field;
        for (int i = 0; i < inputRowsLayerOne; i++)
            for (int j = 0; j < inputColumnsLayerOne; j++)
            {
                getline(ss, field, ',');
                inputSignal[i][j] = stod(field);
            }
    }
    double filterLayerOne[filterRowsLayerOne][filterColumnsLayerOne] = {{0.09147772, 0.08124895},
                                                                        {-0.20509367, -0.0041643}};
    for (int i = 0; i < filterRowsLayerOne; i++)
        for (int j = 0; j < filterColumnsLayerOne; j++)
        {
            filterOneSignal[i][j] = filterLayerOne[i][j];
        }

    sc_start(1, SC_NS);
    cout << "layer one result" << '\n';
    for (int i = 0; i < outputRowsLayerOne; i++)
    {
        for (int j = 0; j < outputColumnsLayerOne; j++)
            cout << setw(12) << outputOneSignal[i][j];
        cout << endl;
    }

    sc_start(1, SC_NS);
    double filterLayerTwo[filterRowsLayerTwo][filterColumnsLayerTwo] = {{0.04559669, -0.36797318},
                                                                        {-0.08351272, -0.36409515}};
    for (int i = 0; i < filterRowsLayerTwo; i++)
        for (int j = 0; j < filterColumnsLayerTwo; j++)
        {
            filterTwoSignal[i][j] = filterLayerTwo[i][j];
        }
    
    sc_start(1, SC_NS);
    cout << "layer two result" << '\n';
    for (int i = 0; i < outputRowsLayerTwo; i++)
    {
        for (int j = 0; j < outputColumnsLayerTwo; j++)
            cout << setw(12) << outputTwoSignal[i][j];
        cout << endl;
    }

    return 0;
};
