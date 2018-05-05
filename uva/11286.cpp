// 11286 - Conformity
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
  int num_tests;
  for (;;) {
    cin >> num_tests;

    if (num_tests == 0) break;

    multiset<string> multi_set;
    set<string> key_set;
    vector<string> v;
    for (int i = 0; i < num_tests; ++i) {
      map<int, int> m;
      for (int j=0; j< 5; ++j) {
	int course;
	cin >> course;
	m.insert({course, course});
      }

      string s;
      for (auto& mm: m) {
	s += to_string(mm.first);
      }

      multi_set.insert(s);
      key_set.insert(s);
    }

    int max_popularity = 0;
    vector<int> popularity_count;
    for (const auto& m_key_set: key_set) {
      int popularity = multi_set.count(m_key_set);
      popularity_count.push_back(popularity);
      if (popularity > max_popularity) {
	max_popularity = popularity;
      }
    }

    int total_most_popular = 0;
    for (const auto& p: popularity_count) {
      if (p == max_popularity) {
	total_most_popular += p;
      }
    }
    cout << total_most_popular << endl;
  }
  return 0;
}

//int main() {
//    int num_tests;
//    for (;;) {
//        cin >> num_tests;
//
//        if (num_tests == 0) break;
//
//        multiset<string> multi_set;
//        set<string> key_set;
//        for (int i = 0; i < num_tests; ++i) {
//            map<int, int> m;
//            for (int j=0; j< 5; ++j) {
//                int course;
//                cin >> course;
//                m.insert({course, course});
//            }
//
//            string s;
//            for (auto& mm: m) {
//                s += to_string(mm.first);
//            }
//
//            multi_set.insert(s);
//            key_set.insert(s);
//        }
//
//        int max_popularity = 0;
//        for (const auto& m_key_set: key_set) {
//            int new_popularity = multi_set.count(m_key_set);
//            if (new_popularity > max_popularity) {
//                max_popularity = new_popularity;
//            }
//        }
//
//        cout << max_popularity << endl;
//    }
//    return 0;
//
