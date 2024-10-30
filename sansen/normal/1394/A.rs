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

fn run() {
    input! {
        n: usize,
        d: usize,
        m: u64,
        a: [u64; n],
    }
    let mut b = vec![];
    let mut c = vec![];
    for a in a.iter() {
        if *a <= m {
            b.push(*a);
        } else {
            c.push(*a);
        }
    }
    b.sort();
    b.reverse();
    c.sort();
    let mut ans = b.iter().sum::<u64>();
    let mut sum = ans;
    let mut x = b.len();
    for (i, c) in c.iter().rev().enumerate() {
        while x > 0 && i * (d + 1) + 1 + x > n {
            x -= 1;
            sum -= b[x];
        }
        sum += *c;
        if i * (d + 1) + 1 + x <= n {
            ans = std::cmp::max(ans, sum);
        } else {
            break;
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}