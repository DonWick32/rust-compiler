fn main() {
    i32 x=1;
    i32 f=2;
    i32 a=3;
    
    a = x * 3 + 5;
    
    if x > a {
        println!("Hi!");
        a = x * 3 + 100;
    } 
    else {
            x = a * 3 + 100;
    }

    return;
}
