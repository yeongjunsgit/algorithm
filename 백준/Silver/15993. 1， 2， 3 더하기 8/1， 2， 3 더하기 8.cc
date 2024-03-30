#include <iostream>
#include <vector>


using namespace std;


int main ()
{
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);

  long long dp_odd[100001];
  long long dp_even[100001];

  dp_odd[1] = 1;
  dp_even[1] = 0;
  dp_odd[2] = 1;
  dp_even[2] = 1;
  dp_odd[3] = 2;
  dp_even[3] = 2;


  long long MOD = 1000000009;

  for (int i = 4; i < 100001; ++i)
  {
      dp_odd[i] = ((dp_even[i - 1] % MOD) + (dp_even[i - 2] % MOD) + (dp_even[i - 3] % MOD)) % MOD;
      dp_even[i] = ((dp_odd[i - 1] % MOD) + (dp_odd[i - 2] % MOD) + (dp_odd[i - 3] % MOD)) % MOD;
  }
  int T;
  cin >> T;

  for (int i = 0; i < T; ++i)
	{
	  int N;

	  cin >> N;

	  cout << dp_odd[N] << " " << dp_even[N] << "\n";
	}


  return 0;
}
