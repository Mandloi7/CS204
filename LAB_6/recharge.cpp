#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli BinarySearch(vector<lli> A, lli l, lli r, lli SEARCH);  

lli BinarySearch(vector<lli> A, lli l, lli r, lli SEARCH) {
    if(l > r) {
        return -1;
    }

    lli mid = (l + r) / 2;
    if(A[mid] < SEARCH) {
        return BinarySearch(A, mid+1, r, SEARCH);
    } else if(A[mid] > SEARCH) {
        return BinarySearch(A, l, mid-1, SEARCH);
    }
    return mid;
}


int main() {
    lli n;
    cin >> n;
    vector<lli> USER;
    lli t;
    cin >> t;
    lli quer[t][3];
   
    for(lli i = 0; i < t; i++) {
        cin >> quer[i][0];
        if(quer[i][0] == 1) {
            cin >> quer[i][1] >> quer[i][2];
            USER.push_back(quer[i][1]);
        }
    }

    sort(USER.begin(),USER.end());                                                            // SORTING THE USER IDs
    
    lli j = 1;
    for(lli i = 1; i < USER.size(); i++) {                                                   //REMOVING REPEATED ENTRIES
        if(USER[i] != USER[i-1]) {
            USER[j] = USER[i];
            j++;
        }
    }
    
    
     vector<lli> recharge(j, 0);              // VECTOR CONTAINING  THE SUM OF RECHARGES OF ONLY THE USERS INPUTED

    lli usermax = -1;
    lli maxrchg = 0;
    
   

    for(lli i = 0; i < t; i++) {
        if(quer[i][0] == 1) {
            lli user_index = BinarySearch(USER, 0, j-1, quer[i][1]);
            recharge[user_index] += quer[i][2];
            if(maxrchg < recharge[user_index]) {
                maxrchg = recharge[user_index];
                usermax = quer[i][1];
            }
        } else {
            if(maxrchg) {
                cout << usermax << endl;
            } else {
                cout << "No data available." << endl;
            }
        }
    }


    return 0;
}
