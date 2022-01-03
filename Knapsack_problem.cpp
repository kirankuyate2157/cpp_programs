#include <bits/stdc++.h>
using namespace std;
int
main ()
{
  int n, wt;
  cin >> n >> wt;
  vector < pair < int, int >>item;
  for (int i = 0; i < n; i++)
    {
      int weight, value;
      cin >> weight >> value;
      item.push_back (
		       {
		       weight, value});
    }
  sort (item.begin (), item.end ());
  int dp[n + 1][wt + 1];
  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < wt; j++)
	{
	  if (i == 0 || j == 0)
	    {
	      dp[i][j] = 0;
	    }
	  else if (item[i - 1].first > j)
	    {
	      dp[i][j] = dp[i - 1][j];
	    }
	  else
	    {
	      int include =
		item[i - 1].second + dp[i - 1][j - item[i - 1].first];
	      int notinclude = dp[i - 1][j];
	      dp[i][j] = max (include, notinclude);
	    }
	}
    }


  for (int i = 0; i <n; i++)
    {
      for (int j = 0; j < wt; j++)
	{
	  cout << dp[i][j] << " ";
	}
      cout << endl;
      
    }
    cout<<dp[n-1][wt-1];
}
