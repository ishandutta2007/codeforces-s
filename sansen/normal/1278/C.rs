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
        let a: Vec<usize> = (0..(2 * n)).map(|_| sc.next()).collect();
        let mut map = std::collections::BTreeMap::<i32, usize>::new();
        let mut cnt = 0;
        map.insert(cnt, 0);
        for (i, a) in a[..n].iter().enumerate() {
            cnt += if *a == 1 {1} else {-1};
            map.insert(cnt, i + 1);
        }
        let mut ans = n + (n - *map.get(&0).unwrap());
        let mut cnt = 0;
        for (i, a) in a[n..].iter().rev().enumerate() {
            cnt += if *a == 2 {1} else {-1};
            if let Some(&v) = map.get(&cnt) {
                ans = std::cmp::min(ans, 2 * n - v - (i + 1));
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}