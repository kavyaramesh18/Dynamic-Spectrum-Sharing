#include <iostream>
#include <vector>
#include <map>

using namespace std;
void allocate_spectrum(map<string, int>& system_allocations, const vector<int>& spectrum_bands) {
    string system;
    int band;

    cout << "Enter system name: ";
    cin >> system;
    cout << "Enter spectrum band to allocate: ";
    cin >> band;

    bool valid_band = false;
    for (int valid_band_value : spectrum_bands) {
        if (band == valid_band_value) {
            valid_band = true;
            break;
        }
    }

    if (!valid_band) {
        cout << "Invalid spectrum band. Please try again." << endl;
        return;
    }
    for (const auto& allocation : system_allocations) {
        if (allocation.second == band) {
            cout << "Band already allocated to another system. Please try again." << endl;
            return;
        }
    }
    system_allocations[system] = band;
    cout << "Allocated Spectrum Band " << band << " to " << system << "." << endl;
}

int main() {
    vector<int> spectrum_bands = {1, 2, 3, 4, 5};
    map<string, int> system_allocations;
    char continue_prompt;
    do {
        cout << "--- Dynamic Spectrum Sharing ---" << endl;
        cout << "Available Spectrum Bands: ";
        for (int band : spectrum_bands) {
            cout << band << " ";
        }
        cout << endl;

        cout << "System Allocations:" << endl;
        for (const auto& allocation : system_allocations) {
            cout << allocation.first << ": " << allocation.second << endl;
        }

        allocate_spectrum(system_allocations, spectrum_bands);

        cout << "Do you want to continue? (y/n): ";
        cin >> continue_prompt;
    } while (continue_prompt == 'y' || continue_prompt == 'Y');

    cout << "Exiting DSS Implementation." << endl;

    return 0;
}
