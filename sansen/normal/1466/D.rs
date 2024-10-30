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
        let w: Vec<u64> = sc.next_vec(n);
        let mut deg = vec![0; n];
        for _ in 1..n {
            let x = sc.next::<usize>() - 1;
            deg[x] += 1;
            let x = sc.next::<usize>() - 1;
            deg[x] += 1;
        }
        let mut a = vec![];
        for (w, d) in w.iter().zip(deg.iter()) {
            for _ in 1..*d {
                a.push(w);
            }
        }
        a.sort();
        let mut s = String::new();
        let mut ans = w.iter().sum::<u64>();
        s.push_str(&format!("{}", ans));
        while let Some(a) = a.pop() {
            ans += a;
            s.push_str(&format!(" {}", ans));
        }
        writeln!(out, "{}", s).ok();
    }
}