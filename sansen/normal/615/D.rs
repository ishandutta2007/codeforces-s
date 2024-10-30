// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
macro_rules! input {
    (source = $s:expr, $($r:tt)*) => {
        let mut iter = $s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
    ($($r:tt)*) => {
        let s = {
            use std::io::Read;
            let mut s = String::new();
            std::io::stdin().read_to_string(&mut s).unwrap();
            s
        };
        let mut iter = s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
}

macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

macro_rules! read_value {
    ($iter:expr, ( $($t:tt),* )) => {
        ( $(read_value!($iter, $t)),* )
    };
    ($iter:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| read_value!($iter, $t)).collect::<Vec<_>>()
    };
    ($iter:expr, chars) => {
        read_value!($iter, String).chars().collect::<Vec<char>>()
    };
    ($iter:expr, bytes) => {
        read_value!($iter, String).bytes().collect::<Vec<u8>>()
    };
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}
// ---------- end input macro ----------

const MOD: u64 = 1_000_000_007;
 
fn pow(r: u64, mut n: u64, m: u64) -> u64 {
    let mut t = 1;
    let mut s = r;
    while n > 0 {
        if n & 1 == 1 {
            t = t * s % m;
        }
        s = s * s % m;
        n >>= 1;
    }
    t
}

fn run() {
    input! {
        m: usize,
        p: [u64; m],
    }
    let mut map = std::collections::BTreeMap::new();
    for p in p {
        *map.entry(p).or_insert(0) += 1;
    }
    let p = map.into_iter().collect::<Vec<_>>();
    let prod = {
        let m = 2 * (MOD - 1);
        let c = p.iter().fold(1, |s, p| s * (p.1 + 1) % m);
        p.iter().fold(1, |s, p| s * pow(p.0, p.1 * c / 2, MOD) % MOD)
    };
    println!("{}", prod);
}

fn main() {
    run();
}