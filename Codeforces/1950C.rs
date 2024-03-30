use std::io;



fn main() {
  let mut input : String = String::new();
  io::stdin().read_line(&mut input);
  let mut t :i32 = input.trim().parse::<i32>().unwrap();
  while t > 0 {
    input = String::new();
    io::stdin().read_line(&mut input);
    let a: Vec<&str> = input.trim().split(':').collect();
    let b: Vec<i32> = a.iter().map(|x| x.parse().unwrap()).collect();
    if b[0] == 0 {
      println!("12:{:02} AM", b[1]);
    }
    else {
      let h = if b[0] <= 12 {b[0]} else {b[0] - 12};
      let suffix = if b[0] >= 12 {"PM"} else {"AM"};
      println!("{:02}:{:02} {}", h, b[1], suffix);
    }
    t -= 1;
  }
}
