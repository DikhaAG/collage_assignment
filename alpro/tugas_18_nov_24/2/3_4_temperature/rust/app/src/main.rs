use std::io;

fn get_input_f32(prompt: &str) -> f32 {
    loop {
        let mut input = String::new();
        println!("Input {prompt} : ");
        io::stdin()
            .read_line(&mut input)
            .expect("cannot read line");
        match input.trim().parse::<f32>() {
            Ok(res) => return res,
            Err(_) => {
                println!("input a valid number!");
                continue;
            }
        }
    }
}

fn f(c: &f32) -> f32 {
    ((9.0/5.0) * c) + 32.0
}
fn c(f: &f32) -> f32 {
    (5.0/9.0) * (f - 32.0)
}
fn c_to_f() {
    let c = get_input_f32("C");
    println!("=> {}F", f(&c));
}
fn f_to_c() {
    let f = get_input_f32("F");
    println!("F = {}", c(&f));
}
fn main() {
    'main: loop {
        let mut opt = String::new();
        println!("Pilih : ");
        println!("1. Konversi Celcius ke Fahrenheit");
        println!("2. Konversi Fahrenheit ke Celcius");
        println!("3. Keluar");
        io::stdin()
            .read_line(&mut opt)
            .expect("cannot read option line");
        'opt: loop {
            match &opt.trim() as &str {
                "1" => {
                    c_to_f();
                    break 'opt
                },
                "2" => {
                    f_to_c();
                    break 'opt
                },
                "3" => break 'main,
                _ => {
                    println!("cannot read {}", opt);
                    continue 'opt;
                }
            }
        }
    }
}
