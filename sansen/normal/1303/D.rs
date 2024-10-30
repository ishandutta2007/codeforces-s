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
        let mut m: u64 = sc.next();
        let n: u64 = sc.next();
        let mut sum = 0;
        let mut h = std::collections::BinaryHeap::new();
        for _ in 0..n {
            let a: u64 = sc.next();
            h.push(a);
            sum += a;
        }
        if m > sum {
            writeln!(out, "-1").ok();
            continue;
        }
        let mut ans = 0;
        while m > 0 {
            let v = h.pop().unwrap();
            sum -= v;
            if v <= m {
                m -= v;
            } else if sum < m {
                sum += v;
                h.push(v / 2);
                h.push(v / 2);
                ans += 1;
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}