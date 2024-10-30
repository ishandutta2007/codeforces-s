// ---------- begin ModInt ----------
const MOD: u32 = 1_000_000_007;

#[derive(Clone, Copy)]
struct ModInt(u32);

impl std::ops::Add for ModInt {
    type Output = ModInt;
    fn add(self, rhs: ModInt) -> Self::Output {
        let mut d = self.0 + rhs.0;
        if d >= MOD {
            d -= MOD;
        }
        ModInt(d)
    }
}

impl std::ops::AddAssign for ModInt {
    fn add_assign(&mut self, rhs: ModInt) {
        *self = *self + rhs;
    }
}

impl std::ops::Sub for ModInt {
    type Output = ModInt;
    fn sub(self, rhs: ModInt) -> Self::Output {
        let mut d = self.0 + MOD - rhs.0;
        if d >= MOD {
            d -= MOD;
        }
        ModInt(d)
    }
}

impl std::ops::SubAssign for ModInt {
    fn sub_assign(&mut self, rhs: ModInt) {
        *self = *self - rhs;
    }
}

impl std::ops::Mul for ModInt {
    type Output = ModInt;
    fn mul(self, rhs: ModInt) -> Self::Output {
        ModInt((self.0 as u64 * rhs.0 as u64 % MOD as u64) as u32)
    }
}

impl std::ops::MulAssign for ModInt {
    fn mul_assign(&mut self, rhs: ModInt) {
        *self = *self * rhs;
    }
}

impl std::ops::Neg for ModInt {
    type Output = ModInt;
    fn neg(self) -> Self::Output {
        ModInt(if self.0 == 0 {0} else {MOD - self.0})
    }
}

/* 
impl std::fmt::Display for ModInt {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", self.0)
    }
}
*/

#[allow(dead_code)]
impl ModInt {
    pub fn new(n: u32) -> ModInt {
        ModInt(n % MOD)
    }
    pub fn zero() -> ModInt {
        ModInt(0)
    }
    pub fn one() -> ModInt {
        ModInt(1)
    }
    pub fn pow(self, mut n: u32) -> ModInt {
        let mut t = ModInt::one();
        let mut s = self;
        while n > 0 {
            if n & 1 == 1 {
                t *= s;
            }
            s *= s;
            n >>= 1;
        }
        t
    }
    pub fn inv(self) -> ModInt {
        self.pow(MOD - 2)
    }
}
// ---------- end ModInt ----------
// ---------- begin Precalc ----------
#[allow(dead_code)]
struct Precalc {
    inv: Vec<ModInt>,
    fact: Vec<ModInt>,
    ifact: Vec<ModInt>,
}

#[allow(dead_code)]
impl Precalc {
    pub fn new(n: usize) -> Precalc {
        let mut inv = vec![ModInt::one(); n + 1];
        let mut fact = vec![ModInt::one(); n + 1];
        let mut ifact = vec![ModInt::one(); n + 1];
        for i in 2..(n + 1) {
            inv[i] = -inv[MOD as usize % i] * ModInt(MOD / i as u32);
            fact[i] = fact[i - 1] * ModInt(i as u32);
            ifact[i] = ifact[i - 1] * inv[i];
        }
        Precalc {
            inv: inv,
            fact: fact,
            ifact: ifact,
        }
    }
    pub fn inv(&self, n: usize) -> ModInt {
        self.inv[n]
    }
    pub fn fact(&self, n: usize) -> ModInt {
        self.fact[n]
    }
    pub fn ifact(&self, n: usize) -> ModInt {
        self.ifact[n]
    }
    pub fn comb(&self, n: usize, k: usize) -> ModInt {
        if k > n {
            return ModInt::zero();
        }
        self.fact[n] * self.ifact[k] * self.ifact[n - k]
    }
}
// ---------- end Precalc ---------- 

fn run() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let n: usize = s.trim().parse().unwrap();
    let mut len = 0;
    while (2 << len) <= n {
        len += 1;
    }
    let mut cnt = vec![0; len + 2];
    for i in 0..=len {
        cnt[i] = n / (1 << i);
    }
    let mut dp = vec![ModInt::zero(); len + 2];
    dp[len] = ModInt::one();
    for i in 1..n {
        let mut next = vec![ModInt::zero(); len + 2];
        for j in 0..len {
            if cnt[j] > i {
                next[j] += dp[j] * ModInt((cnt[j] - i) as u32);
                next[j] += dp[j + 1] * ModInt((cnt[j] - cnt[j + 1]) as u32);
            }
        }
        dp = next;
    }
    let mut ans = dp[0];
    if (1 << len) / 2 * 3 <= n {
        let len = len - 1;
        let mut cnt = vec![vec![0; len + 2]; 2];
        for i in 0..=len {
            cnt[0][i] = n / (1 << i);
            cnt[1][i] = n / (1 << i) / 3;
        }
        let mut dp = vec![vec![ModInt::zero(); len + 2]; 2];
        dp[1][len] = ModInt::one();
        for i in 1..n {
            let mut next = vec![vec![ModInt::zero(); len + 2]; 2];
            for j in 0..=len {
                if cnt[0][j] > i {
                    next[0][j] += dp[0][j] * ModInt((cnt[0][j] - i) as u32);
                    next[0][j] += dp[1][j] * ModInt((cnt[0][j] - cnt[1][j]) as u32);
                    next[0][j] += dp[0][j + 1] * ModInt((cnt[0][j] - cnt[0][j + 1]) as u32);
                }
                if cnt[1][j] > i {
                    next[1][j] += dp[1][j] * ModInt((cnt[1][j] - i) as u32);
                    next[1][j] += dp[1][j + 1] * ModInt((cnt[1][j] - cnt[1][j + 1]) as u32);
                }
            }
            dp = next;
        }
        ans += dp[0][0];
    }
    println!("{}", ans.0);
}

fn main() {
    run();
}