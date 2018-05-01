#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void generate_rate(vector<double> &depreciation_rate)
{
  double previous_rate = depreciation_rate[0];

  for (int i=0; i<depreciation_rate.size(); ++i) {
    if (depreciation_rate[i] == 0) {
      depreciation_rate[i] = previous_rate;
    }
    previous_rate = depreciation_rate[i];
  }
}


int main() {
  int months,depreciation_month, depreciation_records_count;
  double  down_payment, total, depreciation_rate, buyer_owes, current_car_value, monthly_payment;
  vector<double> monthly_deprecation_rate;
  cin >> months >> down_payment >> total >> depreciation_records_count;
  if (months > 0) {
    // array<int, months> monthly_deprecation_rate; //error array size not known at compile time

    for (int i=0; i< months; ++i) {
      //monthly_deprecation_rate[i] = 0;
      monthly_deprecation_rate.push_back(0.0);
    }
    for (int i=0; i<depreciation_records_count; ++i) {
      cin >> depreciation_month >> depreciation_rate;
      monthly_deprecation_rate[depreciation_month] =  depreciation_rate;
    }
  }

  generate_rate(monthly_deprecation_rate);

  current_car_value = total + down_payment; // Note: the description told you car total value
  buyer_owes = total;
  monthly_payment = total/months; // Note: the description does not tell you monthly payment
  for (int i=0; i<months; ++i) {
    current_car_value = current_car_value * (1.0- monthly_deprecation_rate[i]);
    buyer_owes = buyer_owes - monthly_payment;
    if (buyer_owes < current_car_value ) {
      cout << i + 1;
      if (i+ 1>1) {
	cout << " months";
      } else {
	cout << " month" ;
      }
      cout << endl;
      break;
    }
  }
}

