use std::io;

fn main() {
  let mut input : String = String::new();
  io::stdin().read_line(&mut input);
  let mut t: i32 = input.trim().parse().unwrap();
  while t > 0 {
    input = String::new();
    io::stdin().read_line(&mut input);
    let a : Vec<i32> = input.trim().split_whitespace().map(|el| el.parse::<i32>().unwrap()).collect();
    input = String::new();
    io::stdin().read_line(&mut input);
    let b : Vec<i32> = input.trim().split_whitespace().map(|el| el.parse::<i32>().unwrap()).collect();
    input = String::new();
    io::stdin().read_line(&mut input);
    let p : Vec<i32> = input.trim().split_whitespace().map(|el| el.parse::<i32>().unwrap()).collect();
    let mut ans : i32 = 0;

    for x in &b {
      for y in &p {
        ans += (x + y <= a[2]) as i32;
      }
    }
    println!("{}", ans);
    t -= 1;
  }

}
