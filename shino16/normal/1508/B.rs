use crate::lib::stdio::*;

fn main() {
    prtln!(new cout);

    scan!(new cin, t: usize);
    for _ in 0..t {
        scan!(from cin, n: usize, mut k: u64);
        k -= 1;
        let mut res = Vec::with_capacity(n);
        while res.len() < n {
            let i = res.len();
            let (mut lb, mut ub) = (i, n);
            while ub - lb > 1 {
                let m = (lb + ub) / 2;
                let t = (2_u64.saturating_pow((m - i) as _) - 1)
                    .saturating_mul(2_u64.saturating_pow((n - m - 1) as _));
                if t > k {
                    ub = m;
                } else {
                    lb = m;
                }
            }
            let m = lb;
            let t = (2_u64.saturating_pow((m - i) as _) - 1)
                .saturating_mul(2_u64.saturating_pow((n - m - 1) as _));
            k -= t;
            for v in (i..=m).rev() {
                res.push(v);
            }
        }
        if k != 0 {
            prtln!(to cout, -1);
        } else {
            prtln!(to cout, iter=res.iter().map(|v| v + 1));
        }
    }
}


pub mod lib {

pub mod stdio {

pub use crate::prtln;
pub use crate::scan;
use std::io::{stdout, BufWriter, StdoutLock};

pub fn stdout_buf() -> BufWriter<StdoutLock<'static>> {
    let out = Box::leak(Box::new(stdout()));
    BufWriter::new(out.lock())
}

#[macro_export]
macro_rules! prtln {
    (@ $dst:expr, iter=$v:expr) => { $crate::prtln!(@ $dst, iter=$v, sep=" "); };
    (@ $dst:expr, iter=$v:expr, sep=$sep:expr) => { {
        let mut iter = $v.into_iter();
        if let Some(expr) = iter.next() {
            std::write!($dst, "{}", expr).unwrap();
            for v in iter { std::write!($dst, "{}{}", $sep, v).unwrap(); }
        }
        $crate::prtln!(@ $dst, "");
    } };
    (@ $dst:expr, bytes=$v:expr) => {
        $crate::prtln!(@ $dst, std::str::from_utf8(&$v).unwrap());
    };
    (@ $dst:expr, YesNo=$v:expr) => { $crate::prtln!(@ $dst, if $v { "Yes" } else { "No" }); };
    (@ $dst:expr, YESNO=$v:expr) => { $crate::prtln!(@ $dst, if $v { "YES" } else { "NO" }); };
    (@ $dst:expr, $v:expr, no eol) => { std::write!($dst, "{}", $v).unwrap(); };
    (@ $dst:expr, $v:expr) => { std::writeln!($dst, "{}", $v).unwrap(); };
    (@ $dst:expr, $v:expr, $($t:tt)*) => { {
        std::write!($dst, "{} ", $v).unwrap();
        $crate::prtln!(@ $dst, $($t),*);
    } };
    (new $var:ident $(,)?) => { let mut $var = stdout_buf(); };
    (new $var:ident, $($t:tt)*) => {
        $crate::prtln!(new $var);
        $crate::prtln!(to $var, $($t)*);
    };
    (to $var:ident, $($t:tt)*) => { {
        use std::io::Write;
        $crate::prtln!(@ $var, $($t)*);
    } };
    ($($t:tt)*) => { {
        $crate::prtln!(new __prtln, $($t)*);
        std::mem::drop(__prtln);
    } };
}

#[macro_export]
macro_rules! scan {
    (@ $iter:expr $(,)?) => {};
    (@ $iter:expr, mut $var:ident : $t:tt $($r:tt)*) => {
        #[allow(non_snake_case)]
        let mut $var = $crate::scan_value!($iter, $t);
        $crate::scan!(@ $iter $($r)*)
    };
    (@ $iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        #[allow(non_snake_case)]
        let $var = $crate::scan_value!($iter, $t);
        $crate::scan!(@ $iter $($r)*)
    };
    (@ $iter:expr, $pat:pat in $t:tt $($r:tt)*) => {
        let $pat = $crate::scan_value!($iter, $t);
        $crate::scan!(@ $iter $($r)*)
    };
    (from $s:expr, $($r:tt)*) => { $crate::scan!(@ $s, $($r)*); };
    (new $var:ident, $($r:tt)*) => {
        let mut __input = String::new();
        std::io::Read::read_to_string(&mut std::io::stdin(), &mut __input).unwrap();
        let $var = &mut __input.split_ascii_whitespace();
        $crate::scan!(@ $var, $($r)*);
    };
    ($($r:tt)*) => { $crate::scan!(new __scan, $($r)*); };
}

#[macro_export]
macro_rules! scan_value {
    ($iter:expr, ( $($t:tt),* )) => { ( $($crate::scan_value!($iter, $t)),* ) };
    ($iter:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| $crate::scan_value!($iter, $t)).collect::<Vec<_>>()
    };
    ($iter:expr, bytes) => { $iter.next().unwrap().as_bytes() };
    ($iter:expr, [u8]) => { $iter.next().unwrap().as_bytes().to_vec() };
    ($iter:expr, [char]) => { $iter.next().unwrap().chars().collect::<Vec<_>>() };
    ($iter:expr, usize1) => { $crate::scan_value!($iter, usize) - 1 };
    (@graph $iter:expr, $n:expr, $m:expr) => { {
        let mut graph = vec![Vec::new(); $n];
        for _ in 0..$m {
            let (a, b) = $crate::scan_value!($iter, (usize1, usize1));
            graph[a].push(b);
            graph[b].push(a);
        }
        graph
    } };
    ($iter:expr, graph) => { {
        let (n, m) = $crate::scan_value!($iter, (usize, usize));
        $crate::scan_value!(@graph $iter, n, m)
    } };
    ($iter:expr, tree) => { {
        let n = $crate::scan_value!($iter, usize);
        $crate::scan_value!(@graph $iter, n, n - 1)
    } };
    ($iter:expr, $t:ty) => { $iter.next().unwrap().parse::<$t>().unwrap() };
}

}  // mod stdio

}  // mod lib