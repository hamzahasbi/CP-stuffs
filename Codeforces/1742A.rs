use std::io;
use std::collections::HashMap;

fn main() {

    // Create a mutable string to store the input
    let mut input : String = String::new();
    io::stdin().read_line(&mut input);
    let mut t: i32 = input.trim().parse().unwrap();
    while t > 0 {
      input = String::new();
      io::stdin().read_line(&mut input);
      let a : Vec<&str> = input.trim().split_whitespace().collect();
      let mut b : Vec<i32> = Vec::new();
      for sub in a {
        b.push(sub.parse::<i32>().unwrap());
      }
      let mut x = false;
      x |= b[0] + b[1] == b[2];
      x |= b[0] + b[2] == b[1];
      x |= b[1] + b[2] == b[0];
      // println!("{} {:?}", x, b);
      println!("{}", if x {"YES"} else {"NO"});
      t -= 1;
    }
}
