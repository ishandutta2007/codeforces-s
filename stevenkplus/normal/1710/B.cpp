// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A> ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A> ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e: v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
struct node;
ostream& operator<<(ostream &os, const node &node);
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef STEVEN
#define pp(...) cerr << "\t[" << #__VA_ARGS__ << "]:\t", dbg_out(__VA_ARGS__)
#define ppp(x) cerr << x << "\n"
#else
#define pp(...)
#define ppp(...)
#endif
template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define yc y_combinator
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define data _data
// =========== Book ============ //


template <int MOD_> struct modnum {
   static constexpr int MOD = MOD_;
   static_assert(MOD_ > 0, "MOD must be positive");
   private:
   using ll = long long;
   int v;
   static int minv(int a, int m) {
      a %= m;
      assert(a);
      return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
   }
   public:
   modnum() : v(0) {}
   modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
   explicit operator int() const { return v; }
   friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
   friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }
   friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
   friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }
   modnum inv() const {
      modnum res;
      res.v = minv(v, MOD);
      return res;
   }
   friend modnum inv(const modnum& m) { return m.inv(); }
   modnum neg() const {
      modnum res;
      res.v = v ? MOD-v : 0;
      return res;
   }
   friend modnum neg(const modnum& m) { return m.neg(); }
   modnum operator- () const {
      return neg();
   }
   modnum operator+ () const {
      return modnum(*this);
   }
   modnum& operator ++ () {
      v ++;
      if (v == MOD) v = 0;
      return *this;
   }
   modnum& operator -- () {
      if (v == 0) v = MOD;
      v --;
      return *this;
   }
   modnum& operator += (const modnum& o) {
      v += o.v;
      if (v >= MOD) v -= MOD;
      return *this;
   }
   modnum& operator -= (const modnum& o) {
      v -= o.v;
      if (v < 0) v += MOD;
      return *this;
   }
   modnum& operator *= (const modnum& o) {
      v = int(ll(v) * ll(o.v) % MOD);
      return *this;
   }
   modnum& operator /= (const modnum& o) {
      return *this *= o.inv();
   }
   friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
   friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
   friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
   friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
   friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
   friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};
// ============= Solution ============= //
int main() {
   int T;
   cin >> T;
   while (T--) {
      int q, m;
      cin >> q >> m;
      vector<int> x(q), p(q);
      map<int, int> mp;
      for (int i = 0; i < q; ++i) {
         cin >> x[i] >> p[i];
         mp[x[i]];
         mp[x[i] - p[i]];
         mp[x[i] + p[i]];
      }
      int n = 0;
      vector<int> pos;
      for (auto &it: mp) {
         it.se = n++;
         pos.push_back(it.fi);
      }

      vector<ll> a(n);
      vector<ll> slopes(n);
      for (int i = 0; i < q; ++i) {
         ++slopes[mp[x[i] - p[i]]];
         slopes[mp[x[i]]] -= 2;
         ++slopes[mp[x[i] + p[i]]];
      }
      ll prv = pos[0];
      ll curslope = 0;
      ll val = 0;
      for (int i = 0; i < n; ++i) {
         val += (pos[i] - prv) * curslope;
         a[i] = val;
         curslope += slopes[i];
         prv = pos[i];
      }

      pp(pos);
      pp(a);

      vector<ll> seg1(n * 2), seg2(n * 2);
      for (int i = 0; i < n; ++i) {
         seg1[i + n] = a[i] - pos[i];
         seg2[i + n] = a[i] + pos[i];
      }
      for (int i = n - 1; i > 0; --i) {
         seg1[i] = max(seg1[i * 2], seg1[i * 2 + 1]);
         seg2[i] = max(seg2[i * 2], seg2[i * 2 + 1]);
      }
      auto ask = [&](vector<ll> &seg, int l, int r) -> ll {
         ll res = -1E9;
         for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) res = max(res, seg[l++]);
            if (r & 1) res = max(res, seg[--r]);
         }
         return res;
      };
      vector<bool> floodedLeft(n + 1), floodedRight(n + 1);
      for (int i = 0; i < n; ++i) {
         floodedLeft[i + 1] = floodedLeft[i];
         if (a[i] > m) {
            floodedLeft[i + 1] = true;
         }
      }
      for (int i = n - 1; i >= 0; --i) {
         floodedRight[i] = floodedRight[i + 1];
         if (a[i] > m) {
            floodedRight[i] = true;
         }
      }
      for (int i = 0; i < q; ++i) {
         pp(i, x[i], p[i]);
         ll v1 = ask(seg1, mp[x[i] - p[i]], mp[x[i]] + 1);
         ll v2 = ask(seg2, mp[x[i]], mp[x[i] + p[i]] + 1);

         pp(mp[x[i] - p[i]], mp[x[i]], mp[x[i] + p[i]]);
         pp(v1, v2);
         ll mv = max(v1 - p[i] + x[i], v2 - p[i] - x[i]);
         if (mv > m || floodedLeft[mp[x[i] - p[i]]] || floodedRight[mp[x[i] + p[i]] + 1]) {
            cout << "0";
         } else {
            cout << "1";
         }
      }
      cout << "\n";
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - forgot to initialize data (is 0 the right value? -1, inf, -inf?)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases