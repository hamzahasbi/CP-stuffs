use std::io;
use std::collections::HashMap;
use std::collections::BTreeSet;
use std::collections::VecDeque;



fn main() {
  let mut input : String = String::new();
  io::stdin().read_line(&mut input);
  let mut t :i32 = input.trim().parse::<i32>().unwrap();
  while t > 0 {
    input = String::new();
    io::stdin().read_line(&mut input);
    let sizes: Vec<i32> = input.trim().split_whitespace().map(|x| x.parse().unwrap()).collect();
    let n = sizes[0];
    let m = sizes[1];
    let mut x = sizes[2];
    let mut q : HashMap<i32, BTreeSet<i32>> = HashMap::new();
    for i in 0..=m {
      q.insert(i, BTreeSet::new());
    }
    q.get_mut(&0).unwrap().insert(x);


    for i in 1..=m {
      input = String::new();
      io::stdin().read_line(&mut input);
      let l: Vec<&str> = input.trim().split_whitespace().collect();

      let r: i32 = l[0].parse().unwrap();
      let c: &str = l[1];
      let last: BTreeSet<i32> = q.get(&(i - 1)).unwrap().clone();
      // println!("{}, Last ", c);
      // for o in last.iter() {
      //   print!("{} ", o);
      // }
      // println!("");
      match c {
          "0" => {
            for el in last {
              let mut curr = el;
              curr = if curr + r <= n {curr + r} else {(curr + r) - n};
              q.get_mut(&i).unwrap().insert(curr);
            }

          }
          "1" => {
            for el in last {
              let mut curr = el;
              curr = if curr - r > 0 {curr - r} else {n + (curr - r)};
              q.get_mut(&i).unwrap().insert(curr);
            }
          }
          "?" => {
            for el in last {
              let curr = el;
              let left = if curr - r > 0 {curr - r} else {(curr - r) + n};
              let right = if curr + r <= n {curr + r} else {(curr + r) - n};
              // println!("To insert for {} {:?}",el, (left, right));
              q.get_mut(&i).unwrap().insert(left);
              q.get_mut(&i).unwrap().insert(right);
            }
          }
          _ => unreachable!(),
      }
    }
    let ans = q.get(&m).unwrap();
    println!("{}", ans.len());
    for el in ans {
      print!("{} ", *el);
    }
    println!("");
    t -= 1;
  }
}
