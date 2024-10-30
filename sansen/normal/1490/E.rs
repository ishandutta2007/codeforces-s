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
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let a: Vec<u64> = sc.next_vec(n);
        let mut b = a.into_iter().enumerate().collect::<Vec<_>>();
        b.sort_by_key(|p| p.1);
        let mut ok = vec![false; n];
        let mut sum = 0;
        let mut i = 0;
        while i < n {
            sum += b[i].1;
            let s = i;
            i += 1;
            while i < n && sum >= b[i].1 {
                sum += b[i].1;
                i += 1;
            }
            if i == n {
                for b in b[s..].iter() {
                    ok[b.0] = true;
                }
            }
        }
        writeln!(out, "{}", ok.iter().filter(|p| **p).count()).ok();
        let mut s = String::new();
        for (i, ok) in ok.iter().enumerate() {
            if *ok {
                s.push_str(&format!("{} ", i + 1));
            }
        }
        s.pop();
        writeln!(out, "{}", s).ok();
    }
}