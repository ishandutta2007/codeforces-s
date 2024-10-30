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
        s: chars,
    }
    let mut ans = 0u64;
    for i in 2..=n {
        ans += (n + 1 - i) as u64;
    }
    for i in 0..(n - 1) {
        if s[i] == s[i + 1] {
            continue;
        }
        let mut j = i + 1;
        while j < n && s[i + 1] == s[j] {
            ans -= 1;
            j += 1;
        }
    }
    for i in 1..n {
        if s[i] == s[i - 1] {
            continue;
        }
        let mut j = i - 1;
        while j < n && s[i - 1] == s[j] {
            ans -= 1;
            j -= 1;
        }
    }
    for i in 1..n {
        if s[i] != s[i - 1] {
            ans += 1;
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}