#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::swap;
using std::pair;
using std::make_pair;
using std::min;

class HeapBuilder {
 private:
  vector<int> _data;
  vector< pair<int, int> > _swaps;

  void WriteResponse() const {
    cout << _swaps.size() << "\n";
    for (int i = 0; i < _swaps.size(); ++i)
      cout << _swaps[i].first << " " << _swaps[i].second << endl;
  }

  void ReadData() {
    int n;
    cin >> n;
    _data.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> _data[i];
  }

  void SiftUp(int i, vector<int> &_data) {
    int size = _data.size();
    int minIndex = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l <= size-1 && _data[l] < _data[minIndex])
      minIndex = l;
    if (r <= size-1 && _data[r] < _data[minIndex])
      minIndex = r;
    if (i != minIndex) {
      // cout << "Swapping: " << _data[minIndex] << " is less than " << _data[i] << std::endl;
      _swaps.push_back(make_pair(i, minIndex));
      swap(_data[i], _data[minIndex]);
      SiftUp(minIndex, _data);
    }
  }

  void GenerateSwaps() {
    _swaps.clear();
    int size = _data.size();
    for (int i = (size/2) - 1; i > -1; --i)   // integer division gives floor
      SiftUp(i, _data);
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
