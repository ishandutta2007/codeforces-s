#ifndef LOCAL
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")
#endif

#include <vector>
#include <set>
#include <map>
#include <tuple>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <algorithm>
#include <utility>
#include <numeric>
#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

using ll = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VLL = vector<ll>;
using VVLL = vector<vector<ll>>;
using VB = vector<bool>;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
const int INF = 1000000007;
const ll INF_LL = 1'000'000'000'000'000'007;

#define __overload3(_1, _2, _3, name,...) name
#define rep(...) __overload3(__VA_ARGS__, repFromUntil, repUntil, repeat)(__VA_ARGS__)
#define repeat(times) repFromUntil(__name##__LINE__, 0, times)
#define repUntil(name, times) repFromUntil(name, 0, times)
#define repFromUntil(name, from, until) for (int name = from, name##__until = (until); name < name##__until; name++)
#define repr(...) __overload3(__VA_ARGS__, reprFromUntil, reprUntil, repeat)(__VA_ARGS__)
#define reprUntil(name, times) reprFromUntil(name, 0, times)
#define reprFromUntil(name, from, until) for (int name = until - 1, name##__from = (from); name >= name##__from; name--)

#define EXIT(out) do { OUT(out); exit(0); } while (0)

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define fs first
#define sn second

#ifdef LOCAL
#define debug(v) do {debugos << "L" << __LINE__ << " " << #v << " > ";debugos<<(v)<<newl;} while (0)
#define debugv(v) do {debugos << "L" << __LINE__ << " " << #v << " > ";for(auto e:(v)){debugos<<e<<" ";}debugos<<newl;} while (0)
#define debuga(m,w) do {debugos << "L" << __LINE__ << " " << #m << " > ";for(int x=0;x<(w);x++){debugos<<(m)[x]<<" ";}debugos<<newl;} while (0)
#define debugaa(m,h,w) do {debugos << "L" << __LINE__ << " " << #m << " > \n";for(int y=0;y<(h);y++){for(int x=0;x<(w);x++){debugos<<(m)[y][x]<<" ";}debugos<<newl;}} while (0)
#else
#define debug(v) do {v;} while (0)
#define debugv(v) do; while (0)
#define debuga(m,w) do; while (0)
#define debugaa(m,h,w) do; while (0)
#endif

#define newl "\n"
constexpr int dr[] = {1,-1,0,0};  // LRUD
constexpr int dc[] = {0,0,1,-1};

bool inside(int r, int c, int H, int W) {
  return 0 <= r and r < H and 0 <= c and c < W;
}

template <typename T> bool chmin(T& var, T x) {
  if (var > x) {
    var = x;
    return true;
  } else return false;
}

template <typename T> bool chmax(T& var, T x) {
  if (var < x) {
    var = x;
    return true;
  } else return false;
}

template <typename T> int sgn(T val) { return (T(0) < val) - (val < T(0)); }

ll power(ll e, int t, ll mod = INF_LL) {
  ll res = 1;
  while (t) {
    if (t&1) res = (res * e) % mod;
    t >>= 1;
    e = (e * e) % mod;
  }
  return res;
}

template <typename T> T divceil(T m, T d) {
  assert(m >= 0 and d > 0);
  return (m+d-1)/d;
}

template<typename T>
vector<T> make_v(size_t a, T b) { return vector<T>(a, b); }

template<typename... Ts>
auto make_v(size_t a, Ts... ts) {
  return vector<decltype(make_v(ts...))>(a, make_v(ts...));
}

string operator*(const string& s, int times) {
  string res = "";
  rep(times) res += s;
  return res;
}

class MyScanner {
public:
  int offset = 0;
  char nc(){
#ifdef LOCAL
    return getchar();
#else
    static char buf[100000],*L=buf,*R=buf;
    return L==R&&(R=(L=buf)+fread(buf,1,100000,stdin),L==R)?EOF:*L++;
#endif
  }
  template <typename T> void input_integer(T& var) {
    var = 0; T sign = 1;
    int cc = nc();
    for (; cc<'0' || '9'<cc; cc = nc())
      if (cc == '-') sign = -1;
    for (; '0' <= cc && cc <= '9'; cc = nc())
      var = (var << 3) + (var << 1) + cc - '0';
    var = var * sign; var += offset;
  }
  int c() { char c; while (c = nc(), c == ' ' or c == '\n'); return c; }
  MyScanner& operator>>(char& var) { var = c(); return *this; }
  MyScanner& operator>>(int& var) { input_integer<int>(var); return *this; }
  MyScanner& operator>>(ll& var) { input_integer<ll>(var); return *this; }
  MyScanner& operator>>(string& var) {
    var = ""; int cc = nc();
    for (; !isvisiblechar(cc); cc = nc());
    for (; isvisiblechar(cc); cc = nc())
      var.push_back(cc);
    return *this;
  }
  template <typename T>
  operator T() { T x; *this >> x; return x; }
  template <typename T>
  void operator()(T &t) { *this >> t; }
  template <typename T, typename... Ts>
  void operator()(T &t, Ts &...ts) { *this >> t; this->operator()(ts...); }
  template <typename Iter>
  void iter(Iter first, Iter last) { while (first != last) *this >> *first, first++; }
  VI vi(int n) { VI res(n); iter(all(res)); return res; }
  VVI vvi(int n, int m) { VVI res(n); rep(i, n) res[i] = vi(m); return res; }
  VLL vll(int n) { VLL res(n); iter(all(res)); return res; }
  VVLL vvll(int n, int m) { VVLL res(n); rep(i, n) res[i] = vll(m); return res; }
  template <typename T>
  vector<T> v(int n) { vector<T> res(n); iter(all(res)); return res; }
private:
  int isvisiblechar(int c) { return 0x21 <= c && c <= 0x7E; }
} IN, IN1{-1};

class MyPrinter {
public:
  template <typename T>
  void output_integer(T var) {
    if (var == 0) { putchar('0'); return; }
    if (var < 0) putchar('-'), var = -var;
    char stack[32]; int stack_p = 0;
    while (var) stack[stack_p++] = '0' + (var % 10), var /= 10;
    while (stack_p) putchar(stack[--stack_p]);
  }
  MyPrinter& operator<<(char c) { putchar(c); return *this; }
  MyPrinter& operator<<(double x) { printf("%.10f\n", x); return *this; }
  template <typename T> MyPrinter& operator<<(T var) { output_integer<T>(var); return *this; }
  MyPrinter& operator<<(char* str_p) { while (*str_p) putchar(*(str_p++)); return *this; }
  MyPrinter& operator<<(const char* str_p) { while (*str_p) putchar(*(str_p++)); return *this; }
  MyPrinter& operator<<(const string& str) {
    const char* p = str.c_str();
    const char* l = p + str.size();
    while (p < l) putchar(*p++);
    return *this;
  }
  template <typename T>
  void operator()(T x) { *this << x << newl; }
  template <typename T, typename... Ts>
  void operator()(T x, Ts ...xs) { *this << x << " "; this->operator()(xs...); }
  template <typename Iter>
  void iter(Iter s, Iter t) {
    if (s == t) *this << "\n";
    else {
      for (; s != t; s++) {
        *this << *s << " \n"[next(s, 1) == t];
      }
    }
  }
  template <typename Range>
  void range(const Range& r) { iter(begin(r), end(r)); }
} OUT;

class DebugPrint {
public:
  template <typename T>
  DebugPrint& operator <<(const T& v) {
#ifdef LOCAL
    cerr << v;
#endif
    return *this;
  }
} debugos;

template <typename OutStream, typename T, typename U>
OutStream& operator<<(OutStream& out, pair<T, U> var) {
  return out << var.first << " " << var.second;
}
template <typename OutStream, typename Tuple, size_t I, size_t N,
          enable_if_t<I == N>* = nullptr>
OutStream& tuple_impl(OutStream& out, Tuple var) {
  return out;
}
template <typename OutStream, typename Tuple, size_t I, size_t N,
          enable_if_t<I != N>* = nullptr>
OutStream& tuple_impl(OutStream& out, Tuple var) {
  out << get<I>(var) << " ";
  return tuple_impl<Tuple, I+1, N>(out, var);
}
template <typename OutStream, typename... Ts>
OutStream& operator<<(OutStream& out, tuple<Ts...> var) {
  return tuple_impl<tuple<Ts...>, 0, sizeof...(Ts)>(out, var);
}
template <typename InStream, typename T, typename U>
InStream& operator>>(InStream& in, pair<T, U>& var) {
  return in >> var.first >> var.second;
}
template <typename InStream, typename... Ts>
InStream& operator>>(InStream& in, tuple<Ts...>& var) {
  return tuple_impl<tuple<Ts...>, 0, sizeof...(Ts)>(in, var);
}
template <typename InStream, typename Tuple, size_t I, size_t N,
          enable_if_t<I == N>* = nullptr>
InStream& tuple_impl(InStream& in, Tuple& var) {
  return in;
}
template <typename InStream, typename Tuple, size_t I, size_t N,
          enable_if_t<I != N>* = nullptr>
InStream& tuple_impl(InStream& in, Tuple& var) {
  in >> get<I>(var);
  return tuple_impl<Tuple, I+1, N>(in, var);
}

template <typename T = int>
struct Pt {
  using ld = double;
  T x, y;

  Pt(T x_ = 0, T y_ = 0): x(x_), y(y_) { }

  Pt operator +(const Pt<T>& rhs) const {
    return Pt(x+rhs.x, y+rhs.y);
  }
  Pt operator -(const Pt<T>& rhs) const {
    return Pt(x-rhs.x, y-rhs.y);
  }
  Pt operator -() const {
    return Pt(-x, -y);
  }
  Pt operator *(const Pt<T>& rhs) const {
    return Pt(x*rhs.x - y*rhs.y, x*rhs.y + y*rhs.x);
  }
  Pt operator *(const T rhs) const {
    return Pt(x*rhs, y*rhs);
  }
  Pt& operator +=(const Pt<T>& rhs) const {
    return *this = *this + rhs;
  }
  Pt& operator -=(const Pt<T>& rhs) const {
    return *this = *this - rhs;
  }
  Pt& operator *=(const Pt<T>& rhs) {
    return *this = *this * rhs;
  }
  Pt& operator *=(const T rhs) const {
    return *this = *this * rhs;
  }
  bool operator ==(const Pt<T>& rhs) const {
    return x == rhs.x and y == rhs.y;
  }
  bool operator !=(const Pt<T>& rhs) const {
    return not (*this == rhs);
  }
  ld abs() const {
    return hypot(x, y);
  }
  T dot(const Pt<T>& rhs) const {
    return x*rhs.x + y*rhs.y;
  }
  T det(const Pt<T>& rhs) const {
    return x*rhs.y - y*rhs.x;
  }
};

template <typename OutStream, typename T>
OutStream& operator<<(OutStream& out, const Pt<T>& var) {
  return out << var.x << " " << var.y;
}

template <typename InStream, typename T>
InStream& operator>>(InStream& in, Pt<T>& var) {
  return in >> var.x >> var.y;
}



int main() {
  int n = IN;
  if (n % 2) EXIT("NO");
  auto p = IN.v<Pt<>>(n);
  rep(i, n/2) if (p[i+1]-p[i] != p[i+n/2] - p[(i+1+n/2)%n]) EXIT("NO");
  OUT("YES");
}