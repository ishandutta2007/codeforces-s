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

fn run() {
    input! {
        n: usize,
        _m: i32,
        d: i32,
        a: [i32; n],
    }
    let mut a = a.into_iter().enumerate().collect::<Vec<_>>();
    a.sort_by_key(|a| a.1);
    let mut ok = n;
    let mut ng = 0;
    while ok - ng > 1 {
        let mid = (ok + ng) / 2;
        if a.windows(mid + 1).all(|a| a[mid].1 - a[0].1 > d) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    let mut ans = vec![0; n];
    for ((x, _), k) in a.into_iter().zip((1..=ok).cycle()) {
        ans[x] = k;
    }
    println!("{}", ok);
    let s = ans.iter().map(|a| a.to_string()).collect::<Vec<_>>().join(" ");
    println!("{}", s);
}

fn main() {
    run();
}