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
        let k: usize = sc.next();
        let a: Vec<usize> = (0..n).map(|_| sc.next()).collect();
        let mut imos = vec![0; 3 * k + 1];
        for i in 0..(n / 2) {
            let x = a[i];
            let y = a[n - 1 - i];
            imos[x + y] -= 2;
            imos[x + y + 1] += 2;
            let l = x + y - std::cmp::max(x - 1, y - 1);
            let r = x + y + std::cmp::max(k - x, k - y);
            imos[l] -= 1;
            imos[x + y] += 1;
            imos[x + y + 1] -= 1;
            imos[r + 1] += 1;
        }
        let mut ans = n;
        for i in 1..=(3 * k) {
            imos[i] += imos[i - 1];
            ans = std::cmp::min(ans, imos[i] + n);
        }
        writeln!(out, "{}", ans).ok();
    }
}