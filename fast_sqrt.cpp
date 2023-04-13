#include <iostream>
#include <vector>
using namespace std;

namespace CS142 {

    void fast_sqrt(const std::vector<float>& inputs, std::vector<float>& outputs) {
        for (const auto& input : inputs) {              // iterate over each input number in the vector
            int i = *(int*)&input;                      // reinterpret input as an integer
            i = 0x5f3999df - (i >> 1);                  // initial guess using bit manipulation
            float x = *(float*)&i;                      // reinterpret integer as a float
            x = x * (1.5f - (0.5f * input * x * x));    // improve the estimate using Newton's method (could loop)
            outputs.push_back(x * input);               // convert from inverse to normal and store answer
        }
    }

}

int main() {
    vector<float> inputs { 1.2f, 2.0f, 1194877489.0f };
    vector<float> outputs;
    CS142::fast_sqrt(inputs, outputs);
    cout << "Inputs: ";
    for (const auto& input : inputs) {
        cout << input << " ";
    }
    cout << "\nOutputs: ";
    for (const auto& output : outputs) {
        cout << output << " ";
    }
    return 0;
}

