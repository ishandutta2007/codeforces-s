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
        _n: usize,
        m: usize,
        a: [i64; m],
    }
    let mut a = a;
    a.dedup();
    let mut map = std::collections::BTreeMap::new();
    let mut sum = 0;
    for a in a.windows(2) {
        sum += (a[0] - a[1]).abs();
        map.entry(a[0]).or_insert(vec![]).push(a[1]);
        map.entry(a[1]).or_insert(vec![]).push(a[0]);
    }
    let mut ans = sum;
    for (v, mut a) in map {
        let sum = sum - a.iter().map(|a| (*a - v).abs()).sum::<i64>();
        a.sort();
        let mut r = a.len() as i64;
        let mut l = 0;
        let mut pre = a[0];
        let mut cost = a.iter().sum::<i64>() - pre * r;
        ans = ans.min(sum + cost);
        for &a in a.iter() {
            let d = a - pre;
            cost -= d * r;
            cost += d * l;
            r -= 1;
            l += 1;
            pre = a;
            ans = ans.min(sum + cost);
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}