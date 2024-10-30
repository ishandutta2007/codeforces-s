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

struct ID(usize);

impl ID {
    fn next(&mut self) -> usize {
        let a = self.0;
        self.0 -= 1;
        a
    }
}

fn run() {
    input! {
        n: usize,
    }
    if n <= 2 {
        println!("-1");
        return;
    }
    let mut ans = vec![vec![0; n]; n];
    let mut id = ID(n * n);
    ans[0][1] = id.next();
    ans[2][2] = id.next();
    ans[2][0] = id.next();
    ans[0][2] = id.next();
    ans[1][2] = id.next();
    ans[1][1] = id.next();
    ans[2][1] = id.next();
    ans[1][0] = id.next();
    ans[0][0] = id.next();
    for i in 3..n {
        if i % 2 == 1 {
            for j in 0..=i {
                ans[j][i] = id.next();
            }
            for j in (0..i).rev() {
                ans[i][j] = id.next();
            }
        } else {
            for j in 0..=i {
                ans[i][j] = id.next();
            }
            for j in (0..i).rev() {
                ans[j][i] = id.next();
            }
        }
    }
    let mut s = String::new();
    for a in ans {
        for a in a {
            s.push_str(&format!("{} ", a));
        }
        s.pop();
        s.push('\n');
    }
    print!("{}", s);
}

fn main() {
    run();
}