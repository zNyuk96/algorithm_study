#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n_equipments, capability, answer = 0;
    vector<int> costs, prev;

    cin >> n_equipments >> capability;
    costs = vector<int>(capability + 1, -1);
    costs[0] = 0;

    for (int package = 0, weight, value; package < n_equipments; package++) {
        prev = vector<int>(costs);
        scanf("%d %d", &weight, &value);

        for (int i = 0; i < capability + 1; i++) {
            if (prev[i] == -1)
                continue;
            if (i + weight <= capability && prev[i + weight] < value + prev[i]) {
                costs[i + weight] = value + prev[i];
            }
        }
    }

    for (int i = 0; i < capability + 1; i++)
        answer = max(answer, costs[i]);

    cout << answer << "\n";

    return 0;
}