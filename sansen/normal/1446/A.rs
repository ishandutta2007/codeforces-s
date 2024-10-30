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
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
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
        let w: u64 = sc.next();
        let mut a = vec![];
        let mut ans = (0, n);
        for i in 0..n {
            let v: u64 = sc.next();
            if v <= w {
                a.push((v, i));
            }
            if w >= v && v >= (w + 1) / 2 {
                ans = (v, i);
            }
        }
        if ans.1 < n {
            writeln!(out, "1\n{}", ans.1 + 1).ok();
            continue;
        }
        let mut sum = a.iter().map(|p| p.0).sum::<u64>();
        if sum < (w + 1) / 2 {
            writeln!(out, "-1").ok();
        } else {
            while sum > w {
                sum -= a.pop().unwrap().0;
            }
            writeln!(out, "{}", a.len()).ok();
            for (i, a) in a.iter().enumerate() {
                if i > 0 {
                    write!(out, " ").ok();
                }
                write!(out, "{}", a.1 + 1).ok();
            }
            writeln!(out, "").ok();
        }
    }
}