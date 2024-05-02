use std::io;

fn main() {
  int a = 10;
  int sum = 0;
  int b [5];

  while sum > 0 {
    sum = sum - 1;
  }

  summa();
  for i in 1..a {
    sum = sum + i;
  }
  return;
}

fn summa(int a, int b) {
    b = b + 5;

    while b > 0 {
        summa();
        b = b - 1;
    }
    
    return;
}