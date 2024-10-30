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
        let mut p = vec![(0usize, 0usize); n];
        for p in p.iter_mut() {
            p.0 = sc.next();
            p.1 = sc.next();
        }
        p.sort();
        let mut ans = String::new();
        ans.push_str("YES\n");
        let mut pos = (0, 0);
        for &(x, y) in p.iter() {
            if y < pos.1 {
                ans.clear();
                ans.push_str("NO");
                break;
            }
            while pos.0 < x {
                ans.push('R');
                pos.0 += 1;
            }
            while pos.1 < y {
                ans.push('U');
                pos.1 += 1;
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}