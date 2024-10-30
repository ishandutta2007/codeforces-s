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
        k: usize,
        a: [usize; n],
    }
    let mut sum = a.clone();
    sum.push(0);
    for i in (0..n).rev() {
        sum[i] = sum[i + 1];
        if a[i] == 0 {
            sum[i] += 1;
        }
    }
    let mut ans = 0;
    let mut l = 0;
    let mut x = 0;
    for i in 0..n {
        while x < n && sum[i] - sum[x + 1] <= k {
            x += 1;
        }
        if x - i > ans {
            ans = x - i;
            l = i;
        }
    }
    let mut k = k;
    let mut a = a;
    for a in a[l..].iter_mut() {
        if k > 0 && *a == 0 {
            *a = 1;
            k -= 1;
        }
    }
    let mut out = String::new();
    out.push_str(&format!("{}\n", ans));
    for a in a {
        out.push_str(&format!("{} ", a));
    }
    out.pop();
    println!("{}", out) 
}

fn main() {
    run();
}