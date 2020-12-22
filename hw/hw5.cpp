// maze problem

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<double,double> pdd;
#define SQ(i) ((i)*(i))
#define MEM(a, b) memset(a, (b), sizeof(a))
#define SZ(i) int(i.size())
#define FOR(i, j, k, in) for (int i=j ; i<(k) ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=(k) ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define REP1(i,j) FOR(i, 1, j+1, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define ALL(_a) _a.begin(),_a.end()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define X first
#define Y second
#ifdef jayinnn
#define TIME(i) Timer i(#i)
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<", ";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
template<typename It> ostream& _OUTC(ostream &_s,It _ita,It _itb)
{
    _s<<"{";
    for(It _it=_ita;_it!=_itb;_it++)
    {
        _s<<(_it==_ita?"":",")<<*_it;
    }
    _s<<"}";
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s,vector<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,deque<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
class Timer {
private:
    string scope_name;
    chrono::high_resolution_clock::time_point start_time;
public:
    Timer (string name) : scope_name(name) {
        start_time = chrono::high_resolution_clock::now();
    }
    ~Timer () {
        auto stop_time = chrono::high_resolution_clock::now();
        auto length = chrono::duration_cast<chrono::microseconds>(stop_time - start_time).count();
        double mlength = double(length) * 0.001;
        debug(scope_name, mlength);
    }
};
#else
#define TIME(i)
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
#endif

const ll MOD = 1000000007;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int iNF = 0x3f3f3f3f;
const ll MAXN = 100005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node
{
    Node* nxt = nullptr;
    int val;
};

Node* find(Node* root, int n){
    Node* cur = root;
    for(int i=0;i<n;cur=cur->nxt,i++){
        if(cur == nullptr) return nullptr;
        debug(i, cur -> val);
    }
    return cur;
}

Node* pre_find(Node* root, int n){
    Node* cur = root;
    for(int i=0;i<n-1;cur=cur->nxt,i++){
        if(cur == nullptr) return nullptr;
    }
    return cur;
    
}

Node* tail_find(Node* root){
    Node* cur = root;
    while(cur -> nxt != nullptr){
        cur = cur -> nxt;
    }
    return cur;
}

void print(Node* root){
    Node* cur = root -> nxt;
    while(cur -> nxt != nullptr){
        cout << cur -> val << " ";
        cur = cur -> nxt;
    }
    cout << cur -> val << endl;
}

int main(){
    string s;
    Node* root = new Node;
    root -> val = -1203;
    // Node* tail = root;
    while(cin >> s){
        if(s == "ADD"){
            int n;
            cin >> n;
            Node* nod = new Node;
            Node* tail = tail_find(root);
            nod -> val = n;
            tail -> nxt = nod;
            print(root);
        } else if(s == "INSERT"){
            string tmp;
            int tar_, n_;
            cin >> tar_ >> tmp >> n_;
            Node* tar = find(root, n_);
            bool flag = true;
            if(tar == nullptr){
                cout << "Index is out of range!!" << endl;
                flag = false;
            }
            if(flag){
                Node* nod = new Node;
                nod -> val = tar_;
                nod -> nxt = tar -> nxt;
                tar -> nxt = nod;
            }
            print(root);

        } else if(s == "DELETE"){
            int n;
            cin >> n;
            Node* pre = pre_find(root, n);
            bool flag = true;
            if(pre == nullptr){
                cout << "Index is out of range!!" << endl;
                flag = false;
            }
            if(flag){
                Node* tar = pre -> nxt;
                pre -> nxt = tar -> nxt;
                delete tar;            
            }
            print(root);

        } else if(s == "REVERSE"){
            Node* left = root -> nxt;
            if(left != nullptr){
                Node* mid = left -> nxt;
                left -> nxt = nullptr;
                if(mid != nullptr){
                    Node* right = mid -> nxt;
                    while(right != nullptr){
                        debug(left -> val, mid -> val, right -> val);
                        mid -> nxt = left;
                        left = mid;
                        mid = right;
                        right = mid -> nxt;
                    }
                } else {
                    left -> nxt = nullptr;
                }
                mid -> nxt = left;
                root -> nxt = mid;
            }
            print(root);
        }
        
    }
}
