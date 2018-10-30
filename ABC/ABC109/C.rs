extern crate num;

use std::io::*;
use std::str::FromStr;
use num::integer::gcd;

#[allow(dead_code)]
fn get_line() -> String {
    let stdin = stdin();
    let mut line = String::new();
    stdin.lock().read_line(&mut line).expect("io error.");
    line.trim().to_string()
}

#[allow(dead_code)]
fn cast<T: FromStr>(s: &str) -> T {
    s.parse().ok().expect("parse error.")
}

#[allow(dead_code)]
fn get_word<T: FromStr>() -> T {
    cast(&get_line())
}

#[allow(dead_code)]
fn get_vec<T: FromStr>() -> Vec<T> {
    (&get_line()).split(' ').map(cast::<T>).collect()
}

/*
fn gcd(a: u64, b: u64) -> u64 {
    if a > b {return gcd(b, a)};

    match a {
        0 => b,
        a => gcd(b % a, a),
    }
}
*/

/* ---------- ここまでテンプレ ---------- */


fn main() {
    let v: Vec<i64> = get_vec();
    let n: usize = v[0] as usize;
    let x: i64 = v[1];

    let xv: Vec<i64> = get_vec();
    let mut dis: Vec<u64> = vec![0; n];

    for i in 0..n {
        dis[i] = (xv[i] - x).abs() as u64;
    }

    let mut ans = dis[0];
    for i in 1..n {
        ans = ans.gcd(dis[i]);
    }

    println!("{}", ans);
}
