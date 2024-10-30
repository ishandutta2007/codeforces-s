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

fn gcd(a: usize, b: usize) -> usize {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

fn run() {
    input! {
        n: usize,
        a: [usize; n],
    }
    let m = 10_000_000;
    let mut f = (0..=m).collect::<Vec<_>>();
    for i in 2.. {
        if i * i > m {
            break;
        }
        if f[i] == i {
            let mut j = i * i;
            while let Some(f) = f.get_mut(j) {
                *f = i;
                j += i;
            }
        }
    }
    let mut ans = vec![[-1; 2]; n];
    for (ans, a) in ans.iter_mut().zip(a.iter()) {
        let mut x = *a;
        let p = f[x];
        let mut q = 1;
        while x % p == 0 {
            q *= p;
            x /= p;
        }
        if x > 1 {
            ans[0] = x as i32;
            ans[1] = q as i32;
        }
    }
    let mut a = String::new();
    let mut b = String::new();
    for x in ans.iter() {
        a.push_str(&format!("{} ", x[0]));
        b.push_str(&format!("{} ", x[1]));
    }
    a.pop();
    b.pop();
    println!("{}\n{}", a, b);
}

fn main() {
    run();
}