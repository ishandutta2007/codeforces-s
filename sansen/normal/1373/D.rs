// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    use std::str::SplitWhitespace;
    use std::io::Read;
    use std;
    pub struct Scanner<'a> {
        it: SplitWhitespace<'a>
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace()
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            match self.it.next().unwrap().parse::<T>() {
                Ok(v) => v,
                _ => panic!("Scanner error")
            }
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.next::<String>().chars().collect()
        }
    }
    pub fn read_string() -> String {
        let mut s = String::new();
        std::io::stdin().read_to_string(&mut s).unwrap();
        s
    }
}
// ---------- end scannner ----------

use std::io::Write;

fn main() {
    let sc = scanner::read_string();
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let a: Vec<i64> = (0..n).map(|_| sc.next()).collect();
        let mut ans = 0;
        for (i, a) in a.iter().enumerate() {
            if i & 1 == 0 {
                ans += *a;
            }
        }
        let mut add = 0;
        let mut p = 0;
        let mut s = 0;
        for i in 0..n {
            if i + 1 >= n {
                break;
            }
            if i & 1 == 0 {
                let v = a[i + 1] - a[i];
                s += v;
                add = std::cmp::max(add, s - p);
                p = std::cmp::min(p, s);
            }
        }
        let mut p = 0;
        let mut s = 0;
        for i in 0..n {
            if i + 1 >= n {
                break;
            }
            if i & 1 == 1 {
                let v = a[i] - a[i + 1];
                s += v;
                add = std::cmp::max(add, s - p);
                p = std::cmp::min(p, s);
            }
        }
        ans += add;
        writeln!(out, "{}", ans).ok();
    }
}