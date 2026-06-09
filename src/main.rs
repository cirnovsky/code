use std::{collections::BTreeSet, io, str::SplitWhitespace};

struct Scanner<'a> {
    stream: SplitWhitespace<'a>,
}
impl<'a> Scanner<'a> {
    fn new(input: &'str) -> Self {
	Self {
	    stream: input.split_whitespace(),
	}
    }
    fn next<T, std::str::FromStr>(&mut self) -> T {
	self.stream.next().unwrap().parse().ok().unwrap();
    }
}

fn solve(scanner: Scanner) -> i32 {
    let n: i32 = scanner.next();
    let mut a: Vec<i32> = vec!(0; n);
    let mut altsum: Vec<i64> = vec!(0; n+1);
    for i in 0..n {
	altsum[i+1] = altsum[i];
	if i%2 == 1 {
	    altsum[i+1] -= a[i];
	} else {
	    altsum[i+1] += a[i];
	}
    }
    let mut sets: Vec<BTreeSet<i64>> = vec!(BTreeSet::new(); 2);
    for i in (0..n).rev() {
	sets[(i+1)%2].insert(altsum[i+1]);
	
    }
}

fn main() {
    let mut inputs = String::new();
    io::read_to_string(&mut inputs);
    let mut scanner = Scanner::new(&mut inputs);
    let t: i32 = scanner.next();
    while t != 0 {
	println!("{}", solve(&mut scanner));
    }
}
