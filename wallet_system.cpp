#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,t;
    cin >> n;
    map<int,int>mp;
    for (int i=0;i<n;i++) {
        int userID, bal;
        cin>>userID>>bal;
        mp[userID]=bal;
    }
    cin>>t;
    for (int i=0;i<t;i++) {
        int f_userID,t_userID,amount;
        cin>>f_userID>>t_userID>>amount;
        if (mp[f_userID]>=amount) {
            mp[f_userID] -= amount;
            mp[t_userID] += amount;
            cout << "Success" << endl;
        } else {
            cout << "Failure" << endl;
        }
    }
    cout<<endl;
    vector<pair<int, int>>sorted(mp.begin(), mp.end());
    sort(sorted.begin(),sorted.end(),[](const pair<int,int>&a,const pair<int,int>& b) {
        if (a.second == b.second) {
            return a.first<b.first;
        }
        return a.second<b.second;
    });
    for (const auto& user:sorted) {
        cout << user.first<<" "<<user.second<<endl;
    }

    return 0;
}
