use std::io;

fn main() {
  let mut input : String = String::new();
  io::stdin().read_line(&mut input);
  let mut t :i32 = input.trim().parse::<i32>().unwrap();
  while t > 0 {
    input = String::new();
    io::stdin().read_line(&mut input);
    let n : usize = input.trim().parse::<usize>().unwrap();
    input = String::new();
    io::stdin().read_line(&mut input);
    let s : Vec<char> = input.chars().collect();
    let mut i :usize = 1;
    let mut ans = 0;
    let mut last_p = usize::MAX;
    while i < n - 1 {
      if s[i] == 'a' {
        if s[i - 1] == 'm' && s[i + 1] == 'p'{
          ans += 1;
          last_p = i + 1;
        }
      } else if s[i] == 'i' && last_p != i - 1 {
        if s[i - 1] == 'p' && s[i + 1] == 'e'{
          ans += 1;
        }
      }
      i += 1;
    }
    println!("{}", ans);
    t -= 1;
  }
}
