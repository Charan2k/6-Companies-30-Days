#include<iostream>
#include<algorithm>
using namespace std;


class Solution{
    public:
    string colName (long long int n)
    {
        string ans;
        while(n){
            int mod = n%26;
            if(mod==0){
                mod = 26;
            }
            ans += ('A'+(mod - 1));
            n = (n-1)/26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}