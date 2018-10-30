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
    let v: Vec<usize> = get_vec();
    let (h, w) = (v[0], v[1]);

    let mut av: Vec<Vec<usize>> = Vec::new();
    for i in 0..h {
        av.push(get_vec());
    }

    let mut route: Vec<(usize, usize)> = Vec::new();
    for i in 0..h {
        if i % 2 == 0 {
            for j in 0..w {
                route.push((i, j));
            }
        } else {
            for j in (0..w).rev() {
                route.push((i, j));
            }
        }
    }

    // println!("{:?}", route);

    let mut ans: Vec<((usize, usize), (usize, usize))> = Vec::new();
    for i in 0..(h * w - 1) {
        let (x, y) = route[i];
        if av[x][y] % 2 == 1 {
            ans.push((route[i], route[i + 1]));

            let (nx, ny) = route[i + 1];
            av[x][y] -= 1;
            av[nx][ny] += 1;
        }
    }

    println!("{}", ans.len());
    for p in ans {
        println!("{} {} {} {}",
            (p.0).0 + 1, (p.0).1 + 1,
            (p.1).0 + 1, (p.1).1 + 1);
    }
}
