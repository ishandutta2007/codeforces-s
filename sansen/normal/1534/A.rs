// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    pub struct Scanner<'a> {
        it: std::str::SplitWhitespace<'a>,
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace(),
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            self.it.next().unwrap().parse::<T>().ok().unwrap()
        }
        pub fn next_bytes(&mut self) -> Vec<u8> {
            self.it.next().unwrap().bytes().collect()
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.it.next().unwrap().chars().collect()
        }
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
        }
    }
}
// ---------- end scannner ----------

use std::io::Write;

fn main() {
    use std::io::Read;
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut sc = scanner::Scanner::new(&s);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let h: usize = sc.next();
        let w: usize = sc.next();
        let s: Vec<Vec<char>> = (0..h).map(|_| sc.next_chars()).collect::<Vec<_>>();
        let mut ans = None;
        for &(a, b) in [('R', 'W'), ('W', 'R')].iter() {
            let mut t = vec![vec!['.'; w]; h];
            for (i, t) in t.iter_mut().enumerate() {
                for (j, t) in t.iter_mut().enumerate() {
                    *t = if (i + j) & 1 == 0 {a} else {b};
                }
            }
            if t.iter().flatten().zip(s.iter().flatten()).all(|(t, s)| *s == '.' || *s == *t) {
                ans = Some(t);
            }
        }
        if let Some(s) = ans {
            writeln!(out, "YES").ok();
            for s in s {
                for s in s {
                    write!(out, "{}", s).ok();
                }
                writeln!(out).ok();
            }
        } else {
            writeln!(out, "NO").ok();
        }
    }
}