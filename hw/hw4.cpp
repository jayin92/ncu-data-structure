#include<bits/stdc++.h>

using namespace std;

int main(){
    int n1, m1;
    cin >> n1 >> m1;
    vector<vector<pair<int, int>>> a(n1);
    int tmp = 0;
    for(int i=0;i<n1;i++){
        for(int j=0;j<m1;j++){
            cin >> tmp;
            if(tmp != 0){
                a[i].push_back({j, tmp});
            }
        }
    }
    int n2, m2;
    cin >> n2 >> m2;
    vector<vector<int>> b(n2, vector<int>(m2));
    for(int i=0;i<n2;i++){
        for(int j=0;j<m2;j++){
            cin >> b[i][j];
        }
    }

    vector<vector<pair<int, int>>> bt(m2);
    for(int j=0;j<m2;j++){
        for(int i=0;i<n2;i++){
            if(b[i][j] != 0){
                bt[j].push_back({i, b[i][j]});
            }
        }
    }

    vector<vector<int>> res(n1, vector<int>(m2, 0));
    for(int i=0;i<n1;i++){
        for(int k=0;k<m2;k++){
            for(int j=0;j<(int)a[i].size();j++){
                for(int l=0;l<(int)bt[k].size();l++){
                    if(a[i][j].first == bt[k][l].first){
                        res[i][k] += a[i][j].second * bt[k][l].second;
                    }
                }
            }
            if(res[i][k] != 0){
                cout << i << " " << k << " " << res[i][k] << endl;
            }
        }
        

    }
}