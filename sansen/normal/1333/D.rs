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
        n: usize,
        k: usize,
        s: chars,
    }
    let mut s = s;
    s.push('R');
    s.reverse();
    s.push('L');
    s.reverse();
    let mut ans = vec![];
    loop {
        let mut a = vec![];
        let mut i = 1;
        while i + 1 <= n {
            if s[i] == 'R' && s[i + 1] == 'L' {
                s[i] = 'L';
                s[i + 1] = 'R';
                a.push(i);
                i += 2;
            } else {
                i += 1;
            }
        }
        if a.len() == 0 {
            break;
        }
        ans.push(a);
    }
    if ans.iter().fold(0, |s, a| s + a.len()) < k || ans.len() > k {
        println!("-1");
        return;
    }
    let mut x = vec![];
    while ans.len() + x.len() < k {
        let mut a = ans.pop().unwrap();
        while a.len() > 0 && ans.len() + x.len() + 1 < k {
            let a = a.pop().unwrap();
            x.push(vec![a]);
        }
        if a.len() > 0 {
            x.push(a);
        }
    }
    x.reverse();
    ans.append(&mut x);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for a in ans {
        write!(out, "{}", a.len()).ok();
        for a in a {
            write!(out, " {}", a).ok();
        }
        writeln!(out, "").ok();
    }
}

fn main() {
    run();
}