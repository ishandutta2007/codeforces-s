//https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8 
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
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

//

use std::io::Write;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        m: usize,
        e: [(usize1, usize1); m],
        q: usize,
        p: [usize1; q],
    }
    let mut e = e;
    for e in e.iter_mut() {
        let x = std::cmp::min(e.0, e.1);
        let y = e.0 + e.1 - x;
        *e = (x, y);
    }
    e.sort_by_key(|e| e.1);
    let mut in_edge = vec![vec![]; n];
    let mut out_edge = vec![0u64; n];
    let mut sum = 0u64;
    for (a, b) in e {
        sum += out_edge[a];
        in_edge[a].push(b);
        out_edge[b] += 1;
    }
    writeln!(out, "{}", sum).ok();
    for v in p {
        let u = in_edge[v].clone();
        in_edge[v].clear();
        sum -= u.len() as u64 * out_edge[v];
        for &u in u.iter() {
            sum -= in_edge[u].len() as u64;
            in_edge[u].push(v);
            out_edge[u] -= 1;
            out_edge[v] += 1;
            sum += out_edge[u];
        }
        writeln!(out, "{}", sum).ok();
    }
}

fn main() {
    run();
}