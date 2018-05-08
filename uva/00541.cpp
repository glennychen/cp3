// UVA 00541 Error Correction
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
  for(;;) {
    int matrix_size;
    cin >> matrix_size;
    if (matrix_size == 0) break;

    vector<vector<int>> vi;
    vector<int> v_row, v_col;
    for (int i=0; i<matrix_size; ++i) {
      vector<int> vii;
      for (int j=0; j<matrix_size; ++j) {
	int input;
	cin >> input;
	vii.push_back(input);
      }
      vi.push_back(vii);
    }

    int not_parity_count_row = 0;
    for(int i=0; i<matrix_size; ++i) {
      int row_sum = 0;
      for(int j=0;j<matrix_size;++j) {
	row_sum += vi[i][j];
      }
      not_parity_count_row += row_sum%2;
      v_row.push_back(row_sum%2);
    }

    int not_parity_count_col = 0;
    for(int j=0;j<matrix_size;++j) {
      int col_sum = 0;
      for (int i=0;i<matrix_size;++i){
	col_sum += vi[i][j];
      }
      not_parity_count_col += col_sum%2;
      v_col.push_back(col_sum%2);
    }

    if (not_parity_count_row == 0 && not_parity_count_col == 0) {
      cout << "OK" << endl;
      continue;
    }

    if (not_parity_count_row > 1 || not_parity_count_col > 1) {
      cout << "Corrupt" << endl;
      continue;
    }

    if ((not_parity_count_row + not_parity_count_col) == 1) {
      cout << "Corrupt" << endl;
      continue;
    }

    if ((not_parity_count_row + not_parity_count_col) == 2) {
      int fix_row, fix_col;
      for (int i=0;i<matrix_size;++i) {
	if (v_row[i] == 1) {
	  fix_row = i+1; // the answer use 1-based index
	  break;
	}
      }
      for (int j=0;j<matrix_size;++j) {
	if (v_col[j] == 1) {
	  fix_col = j+1; // the answer use 1-based index
	  break;
	}
      }
      cout << "Change bit (" << fix_row << "," << fix_col << ")" << endl;
    }

  }

  return 0;
}
