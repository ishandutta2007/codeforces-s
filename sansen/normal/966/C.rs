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

fn run() {
    input! {
        n: usize,
        b: [u64; n],
    }
    let m = 60;
    let mut a = vec![vec![]; m];
    for b in b {
        for i in (0..m).rev() {
            if (b >> i as u64) & 1 == 1 {
                a[i].push(b);
                break;
            }
        }
    }
    let mut ans = vec![];
    let mut xor = 0;
    for i in 1..=n {
        for (j, a) in a.iter_mut().enumerate() {
            if a.len() > 0 && (xor >> j as u64) & 1 == 0 {
                let v = a.pop().unwrap();
                xor ^= v;
                ans.push(v);
                break;
            }
        }
        if ans.len() != i {
            println!("No");
            return;
        }
    }
    let mut out = String::new();
    out.push_str("Yes\n");
    for a in ans {
        out.push_str(&format!("{} ", a));
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}