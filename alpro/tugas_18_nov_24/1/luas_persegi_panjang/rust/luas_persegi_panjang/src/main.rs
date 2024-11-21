use std::io;
struct Rectangle {
    width: f32,
    heigth: f32,
    area: f32
}
fn get_input(prompt: &str) -> f32 {
    loop {
        let mut input: String = String::new();
        println!("Input {} :", prompt);
        io::stdin()
            .read_line(&mut input)
            .expect("failed to read line!");
        let input: f32 = match input.trim().parse::<f32>() {
            Ok(res) => res,
            Err(_) => {
                println!("not a number input!");
                input.clear();
                continue;
            }
        };
        return input;
    }
}
fn calculate_area(r: &Rectangle) -> f32 {
    println!("Calculating...");
    return r.width * r.heigth;
}
fn main() {
    let mut rectangle: Rectangle = Rectangle { width: 0.0, heigth: 0.0, area: 0.0 };
    rectangle.width = get_input("width");
    rectangle.heigth = get_input("height");
    rectangle.area = calculate_area(&rectangle);
    println!("Area of the rectangle is {} cm^2", rectangle.area);
}