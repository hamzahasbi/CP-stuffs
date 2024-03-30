use std::io;



fn main() {
  let mut input : String = String::new();
  io::stdin().read_line(&mut input);
  let mut t :i32 = input.trim().parse::<i32>().unwrap();
  while t > 0 {
    input = String::new();
    io::stdin().read_line(&mut input);
    let a: Vec<i32> = input.trim().split_whitespace().map(|x| x.parse().unwrap()).collect();
    if a[0] < a[1] && a[1] < a[2] {
      println!("STAIR");
    } else if a[1] > a[0] && a[1] > a[2] {
      println!("PEAK");
    } else {
      println!("NONE");
    }
    t -= 1;
  }
}
