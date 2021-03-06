#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template<typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  if (range_end - range_begin < 2) {
    return;
  }
  vector<typename RandomIt::value_type> elements(range_begin,
      range_end);
  auto t_begin = elements.begin();
  auto t_end = elements.end();
  auto t_third1 = t_begin + (t_end - t_begin) / 3;
  auto t_third2 = t_begin + 2 * (t_end - t_begin) / 3;
  MergeSort(t_begin, t_third1);
  MergeSort(t_third1, t_third2);
  MergeSort(t_third2, t_end);
  vector<typename RandomIt::value_type> temp;
  merge(t_begin, t_third1, t_third1, t_third2, back_inserter(temp));
  merge(temp.begin(), temp.end(), t_third2, t_end, range_begin);

}

int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
