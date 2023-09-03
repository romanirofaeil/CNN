#include "CNN.cpp"
#include <fstream>
#include <sstream>
#include <iomanip>

void printOutputLayerOne(double matrix[outputRowsLayerOne][outputColumnsLayerOne])
{
    for (int i = 0; i < outputRowsLayerOne; i++)
    {
        for (int j = 0; j < outputColumnsLayerOne; j++)
            cout << setw(12) << matrix[i][j];
        cout << endl;
    }
}

void printOutputLayerTwo(double matrix[outputRowsLayerTwo][outputColumnsLayerTwo])
{
    for (int i = 0; i < outputRowsLayerTwo; i++)
    {
        for (int j = 0; j < outputColumnsLayerTwo; j++)
            cout << setw(12) << matrix[i][j];
        cout << endl;
    }
}

int main()
{
    double inputLayerOne[inputRowsLayerOne][inputColumnsLayerOne];
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
                inputLayerOne[i][j] = stod(field);
            }
    }
    double filterLayerOne[filterRowsLayerOne][filterColumnsLayerOne] = {{0.09147772, 0.08124895},
                                                                        {-0.20509367, -0.0041643}};
    double filterLayerTwo[filterRowsLayerTwo][filterColumnsLayerTwo] = {{0.04559669, -0.36797318},
                                                                        {-0.08351272, -0.36409515}};
    double outputLayerOne[outputRowsLayerOne][outputColumnsLayerOne];
    double outputLayerTwo[outputRowsLayerTwo][outputColumnsLayerTwo];
    convolutionNeuralNetwork(inputLayerOne, filterLayerOne, strideLayerOne, outputLayerOne, filterLayerTwo, strideLayerTwo, outputLayerTwo);
    cout << "========================================================================== Output Of Layer One ==========================================================================\n";
    printOutputLayerOne(outputLayerOne);
    cout << "========================================================================== Output Of Layer Two ==========================================================================\n";
    printOutputLayerTwo(outputLayerTwo);
    return 0;
}
