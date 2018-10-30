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
    let n: usize = get_word();

    let mut sv: Vec<String> = Vec::new();
    for i in 0..n {
        sv.push(get_line());
    }

    for i in 0..n {
        for j in i+1..n {
            if sv[i] == sv[j] {
                println!("No");
                return;
            }
        }
    }

    for i in 0..n-1 {
        if sv[i].chars().last().unwrap() != sv[i + 1].chars().next().unwrap() {
            println!("No");
            return;
        }
    }

    println!("Yes");
}
