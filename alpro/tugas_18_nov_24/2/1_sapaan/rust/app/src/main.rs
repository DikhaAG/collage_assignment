use std::io;
struct Person {
    name: String,
    city: String,
}
impl Person {
    fn greeting(&self) {
        print!("Senang bertemu dengan-mu, {}", self.name); print!("di kota {}", self.city);
    }
}
fn main() {
    let mut person: Person = Person {name: "".to_string(), city: "".to_string()};
    println!("Hola!, siapa nama-mu?");
    io::stdin()
        .read_line(&mut person.name)
        .expect("cannot get the input name!");
    println!("Dikota apa kamu sekarang?");
    io::stdin()
        .read_line(&mut person.city)
        .expect("cannot get the input name!");
    person.greeting();
}
