use std::collections::*;

// dijkstra?
// 
// 
// 1->N inf
// 1->2->...->N 1
// 1->2
//
// 
//
// dis[v]: v
// 
// dis[v] = min_S (|S| + 1 + max_u dis[u])
// 
// 

fn run() {
    input! {
        n: usize,
        m: usize,
        e: [(usize1, usize1); m],
    }
    let mut h = vec![vec![]; n];
    let mut out = vec![0; n];
    for &(a, b) in e.iter() {
        out[a] += 1;
        h[b].push(a);
    }
    let inf = 10i32.pow(6);
    let mut dp = vec![inf; n];
    dp[n - 1] = 0;
    let mut q = BinaryHeap::new();
    q.push((0, n - 1));
    while let Some((d, v)) = q.pop() {
        let d = -d;
        if d > dp[v] {
            continue;
        }
        for &u in h[v].iter() {
            out[u] -= 1;
            let d = d + 1 + out[u];
            if d < dp[u] {
                dp[u] = d;
                q.push((-d, u));
            }
        }
    }
    println!("{}", dp[0]);
}

fn main() {
    run();
}

// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
#[macro_export]
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

#[macro_export]
macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[macro_export]
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