#include <iostream>
#include <string>
using namespace std;

int main() {
    int num_of_participants, budget, num_of_hotels, num_of_weeks;

//    cin >> num_of_participants >> budget >> num_of_hotels >> num_of_weeks;

    while(scanf("%d %d %d %d", &num_of_participants, &budget, &num_of_hotels, &num_of_weeks) == 4) {
        int best_budget = budget;
        bool stay_home = true;
        for (int i = 0; i < num_of_hotels; ++i) {
            int price;
            cin >> price;
            for (int j = 0; j < num_of_weeks; ++j) {
                int num_of_beds;
                cin >> num_of_beds;
                if (num_of_beds < num_of_participants) {
                    continue;
                }
                int cost = price * num_of_participants;
                if (cost <= best_budget) {
                    best_budget = cost;
                    stay_home = false;
                }
            }
        }
        if (stay_home) {
            cout << "stay home" << endl;
        } else {
            cout << best_budget << endl;
        }
    }


    //cout << (stay_home==true?"stay home":best_budget) << endl;

    return 0;
}