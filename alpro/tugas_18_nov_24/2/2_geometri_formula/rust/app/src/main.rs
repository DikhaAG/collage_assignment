use core::str;
use std::io;

struct BujurSangkar {
    side: f32,
}
impl BujurSangkar {
    fn calculate_area(&self) {
        println!("Area : {} cm^2", self.side * self.side);
    }
}
fn calculate_bujur_sangkar() {
    'main: loop {
        println!("------BUJUR SANGKAR------");
        let mut bujur_sangkar: BujurSangkar = BujurSangkar { side: 0.0 };
        bujur_sangkar.side = get_input_f32("sisi");
        bujur_sangkar.calculate_area();
        
        'option: loop {
            println!("kembali ke utama? [Y/N] ");
            let mut is_finished: String = String::new();
            io::stdin()
                .read_line(&mut is_finished)
                .expect("cannot get the input");
            match &is_finished.trim() as &str {
                "y" => break 'main,
                "n" => continue 'main,
                _ => {
                    println!("cannot read {}", is_finished);
                    continue 'option;
                }
            }
        }
    }
}
struct Triangle {
    bottom: f32,
    height: f32
}
impl Triangle {
    fn calculate_area(&self) {
        println!("Area : {} cm^2", ((self.bottom*self.height) / 2.0));
    }
}
fn calculate_triangle() {
    'main: loop {
        println!("------Segitiga-------");
        let mut triangle= Triangle { bottom: 0.0, height: 0.0 };
        triangle.bottom = get_input_f32("alas");
        triangle.height = get_input_f32("tinggi");
        triangle.calculate_area();
        
        'option: loop {
            println!("kembali ke utama? [Y/N] ");
            let mut is_finished: String = String::new();
            io::stdin()
                .read_line(&mut is_finished)
                .expect("cannot get the input");
            match &is_finished.trim() as &str {
                "y" => break 'main,
                "n" => continue 'main,
                _ => {
                    println!("cannot read {}", is_finished);
                    continue 'option;
                }
            }
        }
    }
}
struct Trapezoid {
    long_base: f32,
    short_base: f32,
    height: f32
}
impl Trapezoid {
    fn calculate_area(&self) {
        println!("Area : {} cm^2", ((self.long_base + self.short_base) / 2.0) * self.height);
    }
}
fn calculate_trapezoid () {
    'main: loop {
        println!("------Trapesium-------");
        let mut trapezoid = Trapezoid {short_base: 0.0, long_base: 0.0, height: 0.0};
        trapezoid.long_base = get_input_f32("basis panjang");
        trapezoid.short_base = get_input_f32("basis pendek");
        trapezoid.height = get_input_f32("tinggi");
        trapezoid.calculate_area();

        'option: loop {
            println!("kembali ke utama? [Y/N] ");
            let mut is_finished: String = String::new();
            io::stdin()
                .read_line(&mut is_finished)
                .expect("cannot get the input");
            match &is_finished.trim() as &str {
                "y" => break 'main,
                "n" => continue 'main,
                _ => {
                    println!("cannot read {}", is_finished);
                    continue 'option;
                }
            }
        }
    }
}
fn main() {
    loop {
        let mut opt: String = String::new();
        println!("Choose an option : ");
        println!("1. Bujur sangkar");
        println!("2. Segitiga");
        println!("3. Trapesium");
        println!("4. Exit program");
        io::stdin()
            .read_line(&mut opt)
            .expect("Cannot read the option");
        let opt: u8 = match opt.trim().parse() {
            Ok(res) => res,
            Err(_) => continue
        };
        match opt {
            1 => calculate_bujur_sangkar(),
            2 => calculate_triangle(),
            3 => calculate_trapezoid(),
            4 => break,
            _ => println!("choose a valid option")
        }
    }
}

fn get_input_f32(prompt: &str) -> f32 {
    loop {
        let mut input: String = String::new();
        println!("Input {} : ", prompt);
        io::stdin()
            .read_line(&mut input)
            .expect("cannot read line");
        let input: f32 = match input.trim().parse() {
            Ok(res) => {
                res
            },
            Err(_) => continue
        };
        return input;
    }
}