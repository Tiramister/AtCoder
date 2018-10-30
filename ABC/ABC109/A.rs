use std::io::*;
use std::str::FromStr;

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



/* ---------- ここまでテンプレ ---------- */


fn main() {
    let v: Vec<u64> = get_vec();
    println!("{}",
        match v[0] * v[1] % 2 {
            0 => "No",
            1 => "Yes",
            _ => "",
        }
    );
}
