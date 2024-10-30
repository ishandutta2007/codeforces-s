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

use std::io::Write;

fn run() {
    input! {
        t: usize,
        s: [bytes; t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for mut s in s {
        for (i, s) in s.iter_mut().enumerate() {
            if *s != b'?' && i & 1 == 1 {
                *s ^= b'0' ^ b'1';
            }
        }
        let s = s.into_iter().map(|c| {
            match c {
                b'0' => 0,
                b'1' => 1,
                _ => 2,
            }
        }).collect::<Vec<_>>();
        let n = s.len();
        let mut ans = 0u64;
        let mut r = 0;
        let mut cnt = [0; 3];
        for l in 0..n {
            while r < n && (s[r] == 2 || cnt[s[r] ^ 1] == 0) {
                cnt[s[r]] += 1;
                r += 1;
            }
            ans += (r - l) as u64;
            cnt[s[l]] -= 1;
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}