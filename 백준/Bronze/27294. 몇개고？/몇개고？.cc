#include <iostream>

using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  if (M == 1) {
      cout << 280;
  }
  else {
      if (12 <= N && N <= 16) cout << 320;
      else cout << 280;
  }
 
  return 0;
}