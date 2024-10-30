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

//

use std::io::Write;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        t: usize,
        ask: [(i64, i64, i64); t],
    }
    for (l, r, m) in ask {
        let mut ans = (0, 0, 0, 0);
        let diff = r - l;
        'outer: for a in l..=r {
            let n = m / a;
            for n in (n - 2)..=(n + 2) {
                if n > 0 && (m - n * a).abs() <= diff {
                    ans.0 = a;
                    ans.1 = l;
                    ans.2 = l;
                    if m - n * a >= 0 {
                        ans.1 += m - n * a;
                    } else {
                        ans.2 -= m - n * a;
                    }
                    ans.3 = n;
                    break 'outer;
                }
            }
        }
        assert!(ans.0 > 0 && ans.0 * ans.3 + ans.1 - ans.2 == m);
        writeln!(out, "{} {} {}", ans.0, ans.1, ans.2).ok();
    }
}

fn main() {
    run();
}