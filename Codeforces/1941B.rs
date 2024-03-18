use std::io;

fn main() {
  let mut input : String = String::new();
  io::stdin().read_line(&mut input);
  let mut t :i32 = input.trim().parse::<i32>().unwrap();
  while t > 0 {
    input = String::new();
    io::stdin().read_line(&mut input);
    let n : i32 = input.trim().parse::<i32>().unwrap();
    input = String::new();
    io::stdin().read_line(&mut input);
    let mut a : Vec<i64> = input.trim().split_whitespace().map(|x| x.parse::<i64>().unwrap()).collect();
    let mut i : usize = 0;
    while i < (n - 2) as usize {
        let _curr : i64 = a[i];
        if a[i] < 0 {
          break;
        }
        a[i] -= _curr;
        a[i + 1] -= 2 * _curr;
        a[i + 2] -= _curr;
        // println!("{:?}", a);
        i += 1;
    }
    let _ans : Vec<&i64> = a.iter().filter(|&&x| x != 0).collect();
    // println!("{:?}", _ans);
    println!("{}", if _ans.len() > 0 {"NO"} else {"YES"});
    t -= 1;
  }
}
