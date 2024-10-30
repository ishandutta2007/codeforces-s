#line 2 "lib/prelude.hpp"
#ifndef LOCAL
#pragma GCC optimize("O3")
/* #pragma GCC target("avx2") */
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)
#define repr2(i, m, n) for (auto i = (n); i-- > (m);)
#define repr(i, n) repr2(i, 0, n)
#define all(x) begin(x), end(x)
template <class T>
auto ndvec(size_t n, T&& x) { return vector(n, forward<T>(x)); }
template <class... Ts>
auto ndvec(size_t n, Ts&&... xs) { return vector(n, ndvec(forward<Ts>(xs)...)); }
#line 3 "lib/io.hpp"

struct int1 {
  int val;
  int1(int a = 1) : val(a - 1) {}
  operator int() const { return val; }
};

template <size_t BufSize = 1 << 26>
class stdin_reader {
 public: stdin_reader() { buf[fread(buf, 1, sizeof(buf), stdin)] = 0; } template <class T> enable_if_t<is_integral_v<T>> read(T& x) { skip(); [[maybe_unused]] bool neg = false; if constexpr (is_signed_v<T>) neg = *p == '-' ? (p++, true) : false; x = 0; while (*p > ' ') x = x * 10 + (*p++ & 0x0F); if constexpr (is_signed_v<T>) x = neg ? -x : x; } template <class T> void_t<decltype(&T::val)> read(T& x) { x = T((unsigned)(*this)); } void read(char*& q) { skip(); q = p; while (*p > ' ') p++; *p = 0; } template <size_t N> void read(char (&s)[N]) { read(s); } void read(string& s) { skip(); char* p0 = p; while (*p > ' ') p++; s.assign(p0, p); } template <class T, void_t<decltype(tuple_size<T>::value)>* = nullptr> void read(T& x) { read_tuple_impl(x, make_index_sequence<tuple_size_v<T>>{}); } template <class T, class U> void read(pair<T, U>& x) { read(x.first), read(x.second); } template <class T, size_t N> void read(T (&a)[N]) { for (auto& e : a) read(e); } template <class T> operator T() { T x; return read(x), x; } template <class... Ts> void operator()(Ts&... xs) { (read(xs), ...); } int operator--() { return (int)*this - 1; } template <class T> T* arr(int n) { T* p = new T[n + 1]; rep(i, n) read(p[i]); return p; } template <class T> void vec(vector<T>& v, int n) { v.resize(n); for (auto& e : v) read(e); } template <class T> vector<T> vec(int n) { vector<T> v; return vec(v, n), v; } template <class... Ts> tuple<vector<Ts>...> vecs(int n) { tuple<vector<Ts>...> res; vecs_impl(res, n, make_index_sequence<sizeof...(Ts)>{}); return res; } template <class T> void vvec(vector<vector<T>>& v, int n, int m) { v.resize(n); for (auto& e : v) vec(e, m); } template <class T> vector<vector<T>> vvec(int n, int m) { vector<vector<T>> v; return vvec(v, n, m), v; } template <class... Ts> auto cols(int n) { return transpose(vec<tuple<Ts...>>(n)); } private: char buf[BufSize], *p = buf; void skip() { while (*p <= ' ') p++; } template <class T, size_t... Is> void read_tuple_impl(T& x, index_sequence<Is...>) { (*this)(get<Is>(x)...); } template <class T, size_t... Is> void vecs_impl(T& x, int n, index_sequence<Is...>) { (vec(get<Is>(x), n), ...); } template <class T, size_t... Is> static auto transpose_impl(const vector<T>& v, index_sequence<Is...>) { tuple<vector<decay_t<tuple_element_t<Is, T>>>...> w; (get<Is>(w).reserve(v.size()), ...); for (const auto& row : v) (get<Is>(w).push_back(get<Is>(row)), ...); return w; } template <class T> static auto transpose(const vector<T>& v) { return transpose_impl(v, make_index_sequence<tuple_size_v<T>>{}); }
};

template <size_t BufSize = 1 << 26>
class stdout_writer {
 public: ~stdout_writer() { flush(); } void flush() { fwrite(buf, 1, p - buf, stdout), p = buf; } void write_char(char c) { *p++ = c; } void write(char c) { write_char(c); } template <class T> enable_if_t<is_integral_v<T>> write(T x) { if (!x) return write_char('0'); if constexpr (is_signed_v<T>) if (x < 0) write_char('-'), x = -x; static char tmp[16]; char* q = end(tmp); while (x >= 10000) memcpy(q -= 4, digits.data + x % 10000 * 4, 4), x /= 10000; if (x < 10) write_char('0' + x); else if (x < 100) write_char('0' + (uint8_t)x / 10), write_char('0' + (uint8_t)x % 10); else if (x < 1000) memcpy(p, digits.data + x * 4 + 1, 3), p += 3; else memcpy(p, digits.data + x * 4, 4), p += 4; memcpy(p, q, end(tmp) - q), p += end(tmp) - q; } template <class T> void_t<decltype(&T::val)> write(T x) { write(x.val()); } void write(double x) { static char tmp[40]; sprintf(tmp, "%.15f", x); write(tmp); } void write(const char* s) { while (*s) *p++ = *s++; } void write(const string& s) { memcpy(p, s.c_str(), s.size()), p += s.size(); } template <class T, class U> void write(const pair<T, U>& x) { write(x.first), write_char(' '), write(x.second); } template <class... Ts> void write(const tuple<Ts...>& x) { write_tuple(x, make_index_sequence<sizeof...(Ts)>{}); } template <class... Ts> void write(const Ts&... xs) { ((write(xs), write_char(' ')), ...), --p; } template <class... Ts> void writeln(const Ts&... xs) { write(xs...), write_char('\n'); } template <class... Ts> void operator()(const Ts&... xs) { writeln(xs...); } template <class It> void iter(It first, It last, char sep = ' ') { if (first == last) write_char('\n'); else { while (first != last) write(*first++), write_char(sep); p[-1] = '\n'; } } void Yes(bool b = true) { writeln(b ? "Yes" : "No"); } void YES(bool b = true) { writeln(b ? "YES" : "NO"); } void Takahashi(bool b = true) { writeln(b ? "Takahashi" : "Aoki"); } private: char buf[BufSize], *p = buf; template <class T, size_t... Is> void write_tuple(const T& x, index_sequence<Is...>) { ((write(get<Is>(x)), write_char(' ')), ...), --p; } struct four_digits { char data[40000]; constexpr four_digits() : data() { for (int i = 0; i < 10000; i++) for (int n = i, j = 4; j--;) data[i * 4 + j] = n % 10 + '0', n /= 10; } } static constexpr digits{}; public:
#define INSTANT(s) void s() { writeln(#s); }
  INSTANT(No) INSTANT(NO) INSTANT(Aoki) INSTANT(possible) INSTANT(Possible) INSTANT(POSSIBLE) INSTANT(impossible) INSTANT(Impossible) INSTANT(IMPOSSIBLE)
#undef INSTANT
};

stdin_reader<> in;
stdout_writer<> out;

#line 1 "lib/mod/modint.hpp"



#line 6 "lib/mod/modint.hpp"
#include <type_traits>

#ifdef _MSC_VER
#include <intrin.h>
#endif

#line 1 "lib/atcoder/internal_math.hpp"



#line 5 "lib/atcoder/internal_math.hpp"

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param m `1 <= m`
// @return x mod m
constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

// Fast modular multiplication by barrett reduction
// Reference: https://en.wikipedia.org/wiki/Barrett_reduction
// NOTE: reconsider after Ice Lake
struct barrett {
    unsigned int _m;
    unsigned long long im;

    // @param m `1 <= m < 2^31`
    explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

    // @return m
    unsigned int umod() const { return _m; }

    // @param a `0 <= a < m`
    // @param b `0 <= b < m`
    // @return `a * b % m`
    unsigned int mul(unsigned int a, unsigned int b) const {
        // [1] m = 1
        // a = b = im = 0, so okay

        // [2] m >= 2
        // im = ceil(2^64 / m)
        // -> im * m = 2^64 + r (0 <= r < m)
        // let z = a*b = c*m + d (0 <= c, d < m)
        // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64 + c*r + d*im
        // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64 + m * (m + 1) < 2^64 * 2
        // ((ab * im) >> 64) == c or c + 1
        unsigned long long z = a;
        z *= b;
#ifdef _MSC_VER
        unsigned long long x;
        _umul128(z, im, &x);
#else
        unsigned long long x =
            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);
#endif
        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};

// @param n `0 <= n`
// @param m `1 <= m`
// @return `(x ** n) % m`
constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}

// Reference:
// M. Forisek and J. Jancina,
// Fast Primality Testing for Integers That Fit into a Machine Word
// @param n `0 <= n`
constexpr bool is_prime_constexpr(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = pow_mod_constexpr(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}
template <int n> constexpr bool is_prime = is_prime_constexpr(n);

// @param b `1 <= b`
// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g
constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};

    // Contracts:
    // [1] s - m0 * a = 0 (mod b)
    // [2] t - m1 * a = 0 (mod b)
    // [3] s * |m1| + t * |m0| <= b
    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b

        // [3]:
        // (s - t * u) * |m1| + t * |m0 - m1 * u|
        // <= s * |m1| - t * u * |m1| + t * (|m0| + |m1| * u)
        // = s * |m1| + t * |m0| <= b

        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    // by [3]: |m0| <= b/g
    // by g != b: |m0| < b/g
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}

// Compile time primitive root
// @param m must be prime
// @return primitive root (and minimum in now)
constexpr int primitive_root_constexpr(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; (long long)(i)*i <= x; i += 2) {
        if (x % i == 0) {
            divs[cnt++] = i;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        divs[cnt++] = x;
    }
    for (int g = 2;; g++) {
        bool ok = true;
        for (int i = 0; i < cnt; i++) {
            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = primitive_root_constexpr(m);

// @param n `n < 2^32`
// @param m `1 <= m < 2^32`
// @return sum_{i=0}^{n-1} floor((ai + b) / m) (mod 2^64)
unsigned long long floor_sum_unsigned(unsigned long long n,
                                      unsigned long long m,
                                      unsigned long long a,
                                      unsigned long long b) {
    unsigned long long ans = 0;
    while (true) {
        if (a >= m) {
            ans += n * (n - 1) / 2 * (a / m);
            a %= m;
        }
        if (b >= m) {
            ans += n * (b / m);
            b %= m;
        }

        unsigned long long y_max = a * n + b;
        if (y_max < m) break;
        // y_max < m * (n + 1)
        // floor(y_max / m) <= n
        n = (unsigned long long)(y_max / m);
        b = (unsigned long long)(y_max % m);
        std::swap(m, a);
    }
    return ans;
}

}  // namespace internal

}  // namespace atcoder


#line 1 "lib/atcoder/internal_type_traits.hpp"



#line 7 "lib/atcoder/internal_type_traits.hpp"

namespace atcoder {

namespace internal {

#ifndef _MSC_VER
template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;

#else

template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;

#endif

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  // namespace internal

}  // namespace atcoder


#line 14 "lib/mod/modint.hpp"

namespace atcoder {

namespace internal {

struct modint_base {};
struct static_modint_base : modint_base {};

template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

}  // namespace internal

template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct static_modint : internal::static_modint_base {
    using mint = static_modint;

  public:
    static constexpr int mod() { return m; }
    static constexpr mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    constexpr static_modint() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    constexpr static_modint(T v) : _v() {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    constexpr static_modint(T v) : _v() {
        _v = (unsigned int)(v % umod());
    }

    constexpr unsigned int val() const { return _v; }

    constexpr mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    constexpr mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    constexpr mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    constexpr mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    constexpr mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    constexpr mint& operator-=(const mint& rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    constexpr mint& operator*=(const mint& rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    constexpr mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    constexpr mint operator+() const { return *this; }
    constexpr mint operator-() const { return mint() - *this; }

    constexpr mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    constexpr mint inv() const {
        if (prime) {
            assert(_v);
            return pow(umod() - 2);
        } else {
            auto eg = internal::inv_gcd(_v, m);
            assert(eg.first == 1);
            return eg.second;
        }
    }

    constexpr friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    constexpr friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    constexpr friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    constexpr friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    constexpr friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    constexpr friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }
    static constexpr bool prime = internal::is_prime<m>;
};

template <int id> struct dynamic_modint : internal::modint_base {
    using mint = dynamic_modint;

  public:
    static int mod() { return (int)(bt.umod()); }
    static void set_mod(int m) {
        assert(1 <= m);
        bt = internal::barrett(m);
    }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    dynamic_modint() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    dynamic_modint(T v) {
        long long x = (long long)(v % (long long)(mod()));
        if (x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    dynamic_modint(T v) {
        _v = (unsigned int)(v % mod());
    }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v += mod() - rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        _v = bt.mul(_v, rhs._v);
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        auto eg = internal::inv_gcd(_v, mod());
        assert(eg.first == 1);
        return eg.second;
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static internal::barrett bt;
    static unsigned int umod() { return bt.umod(); }
};
template <int id> internal::barrett dynamic_modint<id>::bt(998244353);

using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;
using modint = dynamic_modint<-1>;

namespace internal {

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<dynamic_modint<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  // namespace internal

}  // namespace atcoder


#line 3 "main.cpp"
using mint = atcoder::modint1000000007;

mint pl[1000000], f[1000000], g[1000001];
mint powi2[1000001], pow2[1000001];

void solve() {
  int n = in;
  if (n == 1) return out(1);
  if (n == 2) return out(0), out(1);
  f[n] = 2;
  g[n] = powi2[n] * f[n];
  auto gg = [=](int i) { return i <= n ? g[i] : 0; };
  repr(i, n) {
    f[i] = pow2[i] * (gg(i+1) - gg(i*2));
    g[i] = powi2[i] * f[i] + g[i+1];
  }
  rep(i, n) out(pl[i] * f[i+1]);
}

int main() {
  constexpr mint i2 = mint(2).inv();
  rep(i, size(pl)) pl[i] = i ? i2.pow(i - (i - 1) / 2) : i2;
  powi2[0] = 1;
  pow2[0] = 1;
  rep(i, size(powi2) - 1) powi2[i + 1] = powi2[i] * i2, pow2[i+1] = pow2[i] * 2;
  int T = in;
  while (T--) solve();
}