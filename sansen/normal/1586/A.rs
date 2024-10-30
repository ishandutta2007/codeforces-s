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

fn is_prime(n: u32) -> bool {
    for i in (2..).take_while(|p| p * p <= n) {
        if n % i == 0 {
            return false;
        }
    }
    true
}

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let a: Vec<u32> = sc.next_vec(n);
        let sum = a.iter().sum::<u32>();
        let mut ans = (1..=n).collect::<Vec<_>>();
        if is_prime(sum) {
            for i in 0..n {
                if a[i] % 2 == 1 {
                    ans.remove(i);
                    break;
                }
            }
        }
        writeln!(out, "{}", ans.len()).ok();
        let s = ans.iter().map(|a| a.to_string()).collect::<Vec<_>>().join(" ");
        writeln!(out, "{}", s).ok();
    }
}