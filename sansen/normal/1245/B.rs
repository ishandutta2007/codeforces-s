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
    input!{
        t: usize,
        p: [(usize, [i32; 3], chars); t],
    }
    for (n, a, s) in p {
        let mut a = a;
        a.swap(1, 2);
        let mut ans = vec!['0'; n];
        let mut win = 0;
        let op: Vec<char> = "RSP".chars().collect();
        for i in 0..n {
            for k in 0..3 {
                if s[i] == op[(k + 1) % 3] && a[k] > 0 {
                    ans[i] = op[k];
                    a[k] -= 1;
                    win += 1;
                }
            }
        }
        for i in 0..n {
            for k in 0..3 {
                if ans[i] == '0' && a[k] > 0 {
                    ans[i] = op[k];
                    a[k] -= 1;
                }
            }
        }
        if 2 * win >= n {
            let ans: String = ans.into_iter().collect();
            writeln!(out, "YES\n{}", ans).ok();
        } else {
            writeln!(out, "NO").ok();
        }
    }
}

fn main() {
    run();
}