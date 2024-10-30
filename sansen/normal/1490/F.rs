// ---------- begin Run Length Encoding ----------
fn run_length_encoding<T: Clone + Eq>(a: &[T]) -> Vec<(T, usize)> {
    let mut a = a.iter().map(|a| (a.clone(), 1)).collect::<Vec<_>>();
    a.dedup_by(|a, b| {
        a.0 == b.0 && {
            b.1 += a.1;
            true
        }
    });
    a
}
// ---------- end Run Length Encoding ----------
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
        let mut a: Vec<u32> = sc.next_vec(n);
        a.sort();
        let z = run_length_encoding(&a);
        let mut cnt = vec![0; n + 1];
        for (_, c) in z {
            cnt[c] += 1;
        }
        let mut ans = n + 1;
        let mut k = 0;
        let mut sum = n;
        let mut u = 0;
        for (i, c) in cnt.iter().enumerate().rev() {
            sum -= *c * i;
            u += *c * i;
            k += *c;
            ans = ans.min(sum + u - i * k);
        }
        writeln!(out, "{}", ans).ok();
    }
}