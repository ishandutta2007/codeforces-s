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
    input! {
        t: usize,
        s: [chars; t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for s in s {
        let mut a = vec![vec![]; 3];
        for (i, c) in s.iter().enumerate() {
            let k =c.to_digit(10).unwrap() as usize - 1;
            a[k].push(i);
        }
        let mut ans = s.len() + 1;
        while a.iter().all(|a| !a.is_empty()) {
            let r = a.iter().map(|a| *a.last().unwrap()).max().unwrap();
            let l = a.iter().map(|a| *a.last().unwrap()).min().unwrap();
            ans = std::cmp::min(ans, r - l + 1);
            for a in a.iter_mut() {
                if *a.last().unwrap() == r {
                    a.pop();
                }
            }
        }
        if ans == s.len() + 1 {
            writeln!(out, "0").ok();
        } else {
            writeln!(out, "{}", ans).ok();
        }
    }
}

fn main() {
    run();
}