mod max_flow {
    use std;
    type F = i32;
    pub const INF: F = 1000000000;
    const ZERO: F = 0;
    fn non_zero(f: F) -> bool {
        f > ZERO
    }
    fn min(a: F, b: F) -> F {
        if a < b {a} else {b}
    }
    pub struct Graph {
        n: usize,
        depth: Vec<usize>,
        it: Vec<usize>,
        g: Vec<Vec<(usize, F, usize)>>,
    }
    impl Graph {
        pub fn new(n: usize) -> Graph {
            Graph {
                n: n,
                depth: vec![n + 1; n],
                it: vec![0; n],
                g: vec![vec![]; n],
            }
        }
        pub fn add_edge(&mut self, s: usize, t: usize, f: F) {
            let x = self.g[s].len();
            let y = self.g[t].len();
            self.g[s].push((t, f, y));
            self.g[t].push((s, ZERO, x));
        }
        fn bfs(&mut self, src: usize, dst: usize) {
            let g = &self.g;
            let n = self.n;
            let dp  = &mut self.depth;
            dp.clear();
            dp.resize(n, n + 1);
            dp[src] = 0;
            let mut q = std::collections::VecDeque::new();
            q.push_back(src);
            'outer: while let Some(v) = q.pop_front() {
                for &(u, f, _) in g[v].iter() {
                    if dp[u] > dp[v] + 1 && non_zero(f) {
                        dp[u] = dp[v] + 1;
                        if u == dst {
                            break 'outer;
                        }
                        q.push_back(u);
                    }
                }
            }
        }
        fn dfs(&mut self, v: usize, src: usize, f: F) -> F {
            if v == src {
                return f;
            }
            while self.it[v] < self.g[v].len() {
                let (u, _, inv) = self.g[v][self.it[v]];
                if self.depth[u] < self.depth[v] && non_zero(self.g[u][inv].1) {
                    let capa = min(f, self.g[u][inv].1);
                    let c = self.dfs(u, src, capa);
                    if non_zero(c) {
                        self.g[v][self.it[v]].1 += c;
                        self.g[u][inv].1 -= c;
                        return c;
                    }
                }
                self.it[v] += 1;
            }
            ZERO
        }
        pub fn flow(&mut self, src: usize, dst: usize) -> F {
            let mut ans = ZERO;
            loop {
                self.bfs(src, dst);
                if self.depth[dst] > self.n {
                    break;
                }
                self.it.clear();
                self.it.resize(self.n, 0);
                loop {
                    let f = self.dfs(dst, src, INF);
                    if non_zero(f) {
                        ans += f;
                    } else {
                        break;
                    }
                }
            }
            ans
        }
    }
}
// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
macro_rules! input {
    (source = $s:expr, $($r:tt)*) => {
        let mut iter = $s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
    ($($r:tt)*) => {
        let s = {
            use std::io::Read;
            let mut s = String::new();
            std::io::stdin().read_to_string(&mut s).unwrap();
            s
        };
        let mut iter = s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
}

macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

macro_rules! read_value {
    ($iter:expr, ( $($t:tt),* )) => {
        ( $(read_value!($iter, $t)),* )
    };
    ($iter:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| read_value!($iter, $t)).collect::<Vec<_>>()
    };
    ($iter:expr, chars) => {
        read_value!($iter, String).chars().collect::<Vec<char>>()
    };
    ($iter:expr, bytes) => {
        read_value!($iter, String).bytes().collect::<Vec<u8>>()
    };
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}
// ---------- end input macro ----------

fn run() {
    input! {
        n: usize,
        a: [usize; n],
        b: [i32; n],
    }
    let mut edge = vec![];
    let mut id = n + 2;
    let src = n;
    let dst = n + 1;
    let inf = 1_000_000_000;
    let mut ans = 0;
    let empty = 500000;
    let mut sum = vec![empty; 100 + 1];
    for (i, (&a, &b)) in a.iter().zip(b.iter()).enumerate() {
        if b > 0 {
            ans += b;
            edge.push((src, i, b));
        } else {
            edge.push((i, dst, -b));
        }
        let v = id;
        id += 1;
        edge.push((i, v, inf));
        edge.push((v, i, inf));
        if sum[a] != empty {
            edge.push((v, sum[a], inf));
        }
        sum[a] = v;
        for d in 1..a {
            if a % d == 0 && sum[d] != empty {
                edge.push((v, sum[d], inf));
            }
        }
    }
    let mut g = max_flow::Graph::new(id);
    for (a, b, c) in edge {
        g.add_edge(a, b, c);
    }
    ans -= g.flow(src, dst);
    println!("{}", ans);
}

fn main() {
    run();
}