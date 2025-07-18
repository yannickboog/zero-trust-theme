// Single line comment
/* Multi-line comment
   with multiple lines */

//! Documentation comment for module
/// Documentation comment for items

use std::collections::HashMap;
use std::fmt::{Display, Formatter, Result as FmtResult};
use std::io::{self, Write};
use std::error::Error;

// Constants
const MAX_SIZE: usize = 100;
const PI: f64 = 3.14159;
static GLOBAL_COUNTER: std::sync::atomic::AtomicU32 = std::sync::atomic::AtomicU32::new(0);

// Enum with variants
#[derive(Debug, Clone, PartialEq)]
pub enum Status {
    Active,
    Inactive,
    Pending { reason: String },
}

// Struct definition
#[derive(Debug, Clone)]
pub struct Person {
    pub name: String,
    pub age: u32,
    pub email: Option<String>,
    status: Status,
}

// Implementation block
impl Person {
    /// Creates a new Person
    pub fn new(name: &str, age: u32) -> Self {
        Self {
            name: name.to_string(),
            age,
            email: None,
            status: Status::Active,
        }
    }

    pub fn greet(&self) -> String {
        format!("Hello, my name is {} and I'm {} years old", self.name, self.age)
    }

    pub fn set_email(&mut self, email: String) {
        self.email = Some(email);
    }

    pub fn is_adult(&self) -> bool {
        self.age >= 18
    }
}

// Trait definition
trait Greeter {
    fn greet(&self) -> String;

    fn greet_formal(&self) -> String {
        format!("Good day, {}", self.greet())
    }
}

// Trait implementation
impl Greeter for Person {
    fn greet(&self) -> String {
        format!("Hi, I'm {}", self.name)
    }
}

// Display trait implementation
impl Display for Person {
    fn fmt(&self, f: &mut Formatter<'_>) -> FmtResult {
        write!(f, "Person {{ name: {}, age: {} }}", self.name, self.age)
    }
}

// Generic function
fn find_max<T: PartialOrd + Clone>(items: &[T]) -> Option<T> {
    if items.is_empty() {
        return None;
    }

    let mut max = items[0].clone();
    for item in items.iter().skip(1) {
        if item > &max {
            max = item.clone();
        }
    }
    Some(max)
}

// Function with lifetime parameters
fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() {
        x
    } else {
        y
    }
}

// Async function
async fn fetch_data(url: &str) -> Result<String, Box<dyn Error>> {
    // Simulated async operation
    tokio::time::sleep(tokio::time::Duration::from_millis(100)).await;
    Ok(format!("Data from {}", url))
}

// Macro definition
macro_rules! debug_print {
    ($($arg:tt)*) => {
        println!("[DEBUG] {}", format!($($arg)*));
    };
}

// Main function
fn main() -> Result<(), Box<dyn Error>> {
    // Basic types
    let numbers = vec![1, 2, 3, 4, 5];
    let mut counter = 0u32;
    let pi = 3.14159f64;
    let is_active = true;
    let name = "John Doe";
    let byte_string = b"Hello, World!";
    let raw_string = r#"Raw string with "quotes""#;

    // Mutable vs immutable
    let immutable_var = 42;
    let mut mutable_var = 10;
    mutable_var += 5;

    // Pattern matching
    let status = Status::Pending { reason: "Verification needed".to_string() };
    match status {
        Status::Active => println!("User is active"),
        Status::Inactive => println!("User is inactive"),
        Status::Pending { reason } => println!("User is pending: {}", reason),
    }

    // Control flow
    for i in 0..10 {
        if i % 2 == 0 {
            println!("Even number: {}", i);
        } else {
            println!("Odd number: {}", i);
        }
    }

    // Iterator methods
    let doubled: Vec<i32> = numbers
        .iter()
        .map(|x| x * 2)
        .filter(|&x| x > 5)
        .collect();

    // HashMap usage
    let mut scores = HashMap::new();
    scores.insert("Alice", 95);
    scores.insert("Bob", 87);
    scores.insert("Charlie", 92);

    // Option handling
    let person = Person::new("Alice", 30);
    if let Some(email) = &person.email {
        println!("Email: {}", email);
    } else {
        println!("No email provided");
    }

    // Result handling
    match divide(10.0, 2.0) {
        Ok(result) => println!("Division result: {}", result),
        Err(e) => println!("Error: {}", e),
    }

    // Closure definitions
    let square = |x: i32| x * x;
    let add = |a, b| a + b;

    // Using closures
    let squared_numbers: Vec<i32> = numbers.iter().map(|&x| square(x)).collect();
    println!("Squared numbers: {:?}", squared_numbers);

    // Error propagation with ?
    let result = risky_operation()?;
    println!("Risky operation result: {}", result);

    // Struct instantiation and method calls
    let mut person = Person::new("Bob", 25);
    person.set_email("bob@example.com".to_string());
    println!("{}", person.greet());

    // Trait usage
    println!("{}", person.greet_formal());

    // Reference and borrowing
    let person_ref = &person;
    println!("Person reference: {}", person_ref);

    // Mutable reference
    let person_mut = &mut person;
    person_mut.set_email("new_email@example.com".to_string());

    // String operations
    let mut greeting = String::from("Hello");
    greeting.push_str(", World!");
    greeting.push('!');

    // Vector operations
    let mut vec = Vec::new();
    vec.push(1);
    vec.push(2);
    vec.push(3);

    // Range operations
    for i in 1..=5 {
        debug_print!("Range value: {}", i);
    }

    // Tuple usage
    let tuple = (42, "hello", 3.14);
    let (a, b, c) = tuple;
    println!("Tuple values: {}, {}, {}", a, b, c);

    // Array usage
    let array = [1, 2, 3, 4, 5];
    let slice = &array[1..3];
    println!("Slice: {:?}", slice);

    // Generic function usage
    let max_number = find_max(&numbers);
    println!("Max number: {:?}", max_number);

    // Lifetime usage
    let str1 = "Hello";
    let str2 = "World!";
    let longest_str = longest(str1, str2);
    println!("Longest string: {}", longest_str);

    // Attributes and cfg
    #[cfg(debug_assertions)]
    println!("Debug mode enabled");

    #[allow(unused_variables)]
    let unused_var = 42;

    Ok(())
}

// Function with Result return type
fn divide(a: f64, b: f64) -> Result<f64, String> {
    if b == 0.0 {
        Err("Division by zero".to_string())
    } else {
        Ok(a / b)
    }
}

// Function that can fail
fn risky_operation() -> Result<i32, Box<dyn Error>> {
    let random_value = 42; // Simulated random value
    if random_value > 20 {
        Ok(random_value)
    } else {
        Err("Value too small".into())
    }
}

// Unit tests
#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_person_creation() {
        let person = Person::new("Test", 25);
        assert_eq!(person.name, "Test");
        assert_eq!(person.age, 25);
        assert!(person.email.is_none());
    }

    #[test]
    fn test_divide() {
        assert_eq!(divide(10.0, 2.0).unwrap(), 5.0);
        assert!(divide(10.0, 0.0).is_err());
    }

    #[test]
    fn test_find_max() {
        let numbers = vec![1, 5, 3, 9, 2];
        assert_eq!(find_max(&numbers), Some(9));

        let empty: Vec<i32> = vec![];
        assert_eq!(find_max(&empty), None);
    }
}
