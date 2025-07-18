// Single line comment
/* Multi-line comment
   with multiple lines */

/**
 * @file test.cpp
 * @brief Comprehensive C++ syntax test file for theme highlighting
 * @author C++ Developer
 * @version 1.0
 * @date 2024
 */

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <thread>
#include <future>
#include <chrono>
#include <functional>
#include <exception>
#include <fstream>
#include <sstream>
#include <regex>
#include <optional>
#include <variant>
#include <any>

// Preprocessor directives
#define MAX_SIZE 100
#define PI 3.14159
#define SQUARE(x) ((x) * (x))

#ifdef DEBUG
    #define DEBUG_PRINT(x) std::cout << "DEBUG: " << x << std::endl
#else
    #define DEBUG_PRINT(x)
#endif

#ifndef CUSTOM_HEADER_H
#define CUSTOM_HEADER_H
// Header guard content
#endif

// Using declarations
using namespace std;
using std::cout;
using std::endl;

// Type aliases (C++11)
using StringVector = std::vector<std::string>;
using IntMap = std::map<int, std::string>;

// Template aliases (C++11)
template<typename T>
using SharedPtr = std::shared_ptr<T>;

template<typename T>
using Vector = std::vector<T>;

// Namespace definition
namespace CustomNamespace {
    const int NAMESPACE_CONSTANT = 42;
    
    void namespaceFunction() {
        std::cout << "Function in namespace" << std::endl;
    }
    
    // Nested namespace (C++17)
    namespace Nested {
        void nestedFunction() {
            std::cout << "Nested namespace function" << std::endl;
        }
    }
}

// Anonymous namespace
namespace {
    static int internalCounter = 0;
    
    void internalFunction() {
        ++internalCounter;
    }
}

// Forward declarations
class ForwardDeclared;
template<typename T> class TemplateClass;

// Enum definitions
enum Color {
    RED,
    GREEN,
    BLUE
};

// Scoped enum (C++11)
enum class Status : int {
    Active = 1,
    Inactive = 0,
    Pending = 2
};

// Struct definition
struct Point {
    double x, y;
    
    Point() : x(0.0), y(0.0) {}
    Point(double x, double y) : x(x), y(y) {}
    
    // Operator overloading
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
    
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    
    // Friend function
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
};

// Union definition
union Number {
    int intValue;
    float floatValue;
    double doubleValue;
    
    Number(int i) : intValue(i) {}
    Number(float f) : floatValue(f) {}
    Number(double d) : doubleValue(d) {}
};

// Base class with virtual functions
class Shape {
protected:
    std::string name;
    
public:
    explicit Shape(const std::string& name) : name(name) {}
    
    // Pure virtual function
    virtual double area() const = 0;
    
    // Virtual function
    virtual double perimeter() const {
        return 0.0;
    }
    
    // Virtual destructor
    virtual ~Shape() = default;
    
    // Non-virtual function
    const std::string& getName() const {
        return name;
    }
    
    // Static member function
    static int getShapeCount() {
        static int count = 0;
        return ++count;
    }
};

// Derived class
class Rectangle : public Shape {
private:
    double width, height;
    
public:
    Rectangle(double w, double h) 
        : Shape("Rectangle"), width(w), height(h) {
        if (w <= 0 || h <= 0) {
            throw std::invalid_argument("Width and height must be positive");
        }
    }
    
    // Override virtual function
    double area() const override {
        return width * height;
    }
    
    double perimeter() const override {
        return 2 * (width + height);
    }
    
    // Getter methods
    double getWidth() const { return width; }
    double getHeight() const { return height; }
    
    // Setter methods
    void setWidth(double w) {
        if (w <= 0) throw std::invalid_argument("Width must be positive");
        width = w;
    }
    
    void setHeight(double h) {
        if (h <= 0) throw std::invalid_argument("Height must be positive");
        height = h;
    }
};

// Multiple inheritance
class Drawable {
public:
    virtual void draw() const = 0;
    virtual ~Drawable() = default;
};

class Colorable {
protected:
    Color color;
    
public:
    explicit Colorable(Color c) : color(c) {}
    virtual void setColor(Color c) { color = c; }
    Color getColor() const { return color; }
    virtual ~Colorable() = default;
};

class ColoredRectangle : public Rectangle, public Drawable, public Colorable {
public:
    ColoredRectangle(double w, double h, Color c) 
        : Rectangle(w, h), Colorable(c) {}
    
    void draw() const override {
        std::cout << "Drawing a " << getColor() << " rectangle (" 
                  << getWidth() << "x" << getHeight() << ")" << std::endl;
    }
};

// Template class
template<typename T>
class Container {
private:
    std::vector<T> data;
    
public:
    // Default constructor
    Container() = default;
    
    // Copy constructor
    Container(const Container& other) : data(other.data) {}
    
    // Move constructor (C++11)
    Container(Container&& other) noexcept : data(std::move(other.data)) {}
    
    // Copy assignment operator
    Container& operator=(const Container& other) {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }
    
    // Move assignment operator (C++11)
    Container& operator=(Container&& other) noexcept {
        if (this != &other) {
            data = std::move(other.data);
        }
        return *this;
    }
    
    // Destructor
    ~Container() = default;
    
    // Member functions
    void add(const T& item) {
        data.push_back(item);
    }
    
    void add(T&& item) {
        data.push_back(std::move(item));
    }
    
    template<typename... Args>
    void emplace(Args&&... args) {
        data.emplace_back(std::forward<Args>(args)...);
    }
    
    T& operator[](size_t index) {
        return data[index];
    }
    
    const T& operator[](size_t index) const {
        return data[index];
    }
    
    size_t size() const {
        return data.size();
    }
    
    bool empty() const {
        return data.empty();
    }
    
    // Iterator support
    typename std::vector<T>::iterator begin() { return data.begin(); }
    typename std::vector<T>::iterator end() { return data.end(); }
    typename std::vector<T>::const_iterator begin() const { return data.begin(); }
    typename std::vector<T>::const_iterator end() const { return data.end(); }
    
    // Range-based for loop support
    typename std::vector<T>::const_iterator cbegin() const { return data.cbegin(); }
    typename std::vector<T>::const_iterator cend() const { return data.cend(); }
};

// Template specialization
template<>
class Container<bool> {
private:
    std::vector<bool> data;
    
public:
    void add(bool value) {
        data.push_back(value);
    }
    
    bool operator[](size_t index) const {
        return data[index];
    }
    
    size_t size() const {
        return data.size();
    }
};

// Template function
template<typename T>
T maximum(const T& a, const T& b) {
    return (a > b) ? a : b;
}

// Template function with multiple parameters
template<typename T, typename U>
auto add(T&& t, U&& u) -> decltype(t + u) {
    return std::forward<T>(t) + std::forward<U>(u);
}

// Variadic template (C++11)
template<typename T>
void print(const T& value) {
    std::cout << value << std::endl;
}

template<typename T, typename... Args>
void print(const T& first, const Args&... args) {
    std::cout << first << " ";
    print(args...);
}

// SFINAE example
template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type
absolute(T value) {
    return value < 0 ? -value : value;
}

// Function pointer
typedef int (*FunctionPtr)(int, int);

// Function object (functor)
struct Multiply {
    int operator()(int a, int b) const {
        return a * b;
    }
};

// Exception classes
class CustomException : public std::exception {
private:
    std::string message;
    
public:
    explicit CustomException(const std::string& msg) : message(msg) {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class ValidationException : public CustomException {
public:
    explicit ValidationException(const std::string& field) 
        : CustomException("Validation failed for field: " + field) {}
};

// Regular functions
int add(int a, int b) {
    return a + b;
}

// Function overloading
double add(double a, double b) {
    return a + b;
}

std::string add(const std::string& a, const std::string& b) {
    return a + b;
}

// Function with default parameters
void greet(const std::string& name, const std::string& greeting = "Hello") {
    std::cout << greeting << ", " << name << "!" << std::endl;
}

// Const function
int getConstValue() const {
    return 42;
}

// Inline function
inline int square(int x) {
    return x * x;
}

// Constexpr function (C++11)
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

// Lambda functions and modern C++ features demonstration
void demonstrateModernCpp() {
    // Auto keyword (C++11)
    auto intVar = 42;
    auto doubleVar = 3.14;
    auto stringVar = std::string("Hello");
    
    // Range-based for loop (C++11)
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Lambda expressions (C++11)
    auto square = [](int x) -> int {
        return x * x;
    };
    
    auto add = [](int a, int b) {
        return a + b;
    };
    
    // Capture by value
    int multiplier = 2;
    auto multiplyBy = [multiplier](int x) {
        return x * multiplier;
    };
    
    // Capture by reference
    int counter = 0;
    auto increment = [&counter]() {
        ++counter;
    };
    
    // Capture all by value
    auto captureAll = [=](int x) {
        return x + multiplier;
    };
    
    // Capture all by reference
    auto captureAllRef = [&](int x) {
        counter += x;
        return counter;
    };
    
    // Mutable lambda
    auto mutableLambda = [counter](int x) mutable {
        counter += x;
        return counter;
    };
    
    // Generic lambda (C++14)
    auto genericLambda = [](auto a, auto b) {
        return a + b;
    };
    
    // Smart pointers (C++11)
    std::unique_ptr<int> uniquePtr = std::make_unique<int>(42);
    std::shared_ptr<std::string> sharedPtr = std::make_shared<std::string>("Hello");
    std::weak_ptr<std::string> weakPtr = sharedPtr;
    
    // Move semantics
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = std::move(vec1);
    
    // Perfect forwarding
    auto forwardFunc = [](auto&& arg) {
        return std::forward<decltype(arg)>(arg);
    };
    
    // STL algorithms with lambdas
    std::vector<int> data = {5, 2, 8, 1, 9, 3};
    
    // Sort with lambda
    std::sort(data.begin(), data.end(), [](int a, int b) {
        return a < b;
    });
    
    // Find with lambda
    auto it = std::find_if(data.begin(), data.end(), [](int x) {
        return x > 5;
    });
    
    // Transform with lambda
    std::vector<int> squared(data.size());
    std::transform(data.begin(), data.end(), squared.begin(), [](int x) {
        return x * x;
    });
    
    // Count if with lambda
    int evenCount = std::count_if(data.begin(), data.end(), [](int x) {
        return x % 2 == 0;
    });
    
    // Optional (C++17)
    std::optional<int> optionalValue = std::make_optional(42);
    if (optionalValue.has_value()) {
        std::cout << "Optional value: " << *optionalValue << std::endl;
    }
    
    // Variant (C++17)
    std::variant<int, std::string, double> variantValue = 42;
    std::visit([](const auto& value) {
        std::cout << "Variant value: " << value << std::endl;
    }, variantValue);
    
    // Any (C++17)
    std::any anyValue = std::string("Hello");
    try {
        std::string str = std::any_cast<std::string>(anyValue);
        std::cout << "Any value: " << str << std::endl;
    } catch (const std::bad_any_cast& e) {
        std::cout << "Bad any cast: " << e.what() << std::endl;
    }
}

// Thread and concurrency demonstration
void demonstrateConcurrency() {
    // Thread creation
    std::thread t1([]() {
        std::cout << "Thread 1 executing" << std::endl;
    });
    
    std::thread t2([](int value) {
        std::cout << "Thread 2 with value: " << value << std::endl;
    }, 42);
    
    // Join threads
    t1.join();
    t2.join();
    
    // Async and future
    std::future<int> futureResult = std::async(std::launch::async, []() {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        return 42;
    });
    
    int result = futureResult.get();
    std::cout << "Async result: " << result << std::endl;
    
    // Promise and future
    std::promise<std::string> promise;
    std::future<std::string> future = promise.get_future();
    
    std::thread promiseThread([&promise]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        promise.set_value("Promise fulfilled");
    });
    
    std::string promiseResult = future.get();
    std::cout << "Promise result: " << promiseResult << std::endl;
    
    promiseThread.join();
}

// Main function with comprehensive examples
int main() {
    std::cout << "Starting C++ syntax test..." << std::endl;
    
    // Basic data types
    char charVar = 'A';
    signed char signedCharVar = -128;
    unsigned char unsignedCharVar = 255;
    short shortVar = 32767;
    unsigned short unsignedShortVar = 65535;
    int intVar = 2147483647;
    unsigned int unsignedIntVar = 4294967295U;
    long longVar = 2147483647L;
    unsigned long unsignedLongVar = 4294967295UL;
    long long longLongVar = 9223372036854775807LL;
    unsigned long long unsignedLongLongVar = 18446744073709551615ULL;
    float floatVar = 3.14f;
    double doubleVar = 3.141592653589793;
    long double longDoubleVar = 3.141592653589793L;
    bool boolVar = true;
    
    // Pointers and references
    int value = 42;
    int* ptr = &value;
    int& ref = value;
    const int* constPtr = &value;
    int* const ptrConst = &value;
    const int* const constPtrConst = &value;
    
    // Null pointer (C++11)
    int* nullPtr = nullptr;
    
    // Arrays
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    // Dynamic arrays
    int* dynamicArray = new int[10];
    for (int i = 0; i < 10; ++i) {
        dynamicArray[i] = i * i;
    }
    delete[] dynamicArray;
    
    // String literals
    const char* cString = "C-style string";
    std::string cppString = "C++ string";
    std::string rawString = R"(Raw string with "quotes" and \backslashes)";
    
    // Control structures
    // If-else statements
    if (intVar > 0) {
        std::cout << "Positive number" << std::endl;
    } else if (intVar < 0) {
        std::cout << "Negative number" << std::endl;
    } else {
        std::cout << "Zero" << std::endl;
    }
    
    // Ternary operator
    std::string sign = (intVar >= 0) ? "non-negative" : "negative";
    
    // Switch statement
    Status status = Status::Active;
    switch (status) {
        case Status::Active:
            std::cout << "Status is active" << std::endl;
            break;
        case Status::Inactive:
            std::cout << "Status is inactive" << std::endl;
            break;
        case Status::Pending:
            std::cout << "Status is pending" << std::endl;
            break;
        default:
            std::cout << "Unknown status" << std::endl;
            break;
    }
    
    // Loops
    // For loop
    for (int i = 0; i < 10; ++i) {
        if (i % 2 == 0) {
            continue; // Skip even numbers
        }
        std::cout << "Odd number: " << i << std::endl;
        if (i > 7) {
            break; // Exit loop early
        }
    }
    
    // Range-based for loop (C++11)
    std::vector<std::string> words = {"hello", "world", "cpp", "syntax"};
    for (const auto& word : words) {
        std::cout << "Word: " << word << std::endl;
    }
    
    // While loop
    int count = 0;
    while (count < 5) {
        std::cout << "Count: " << count << std::endl;
        ++count;
    }
    
    // Do-while loop
    int j = 0;
    do {
        std::cout << "Do-while iteration: " << j << std::endl;
        ++j;
    } while (j < 3);
    
    // Exception handling
    try {
        Rectangle rect(5.0, 3.0);
        std::cout << "Rectangle area: " << rect.area() << std::endl;
        std::cout << "Rectangle perimeter: " << rect.perimeter() << std::endl;
        
        // This will throw an exception
        Rectangle invalidRect(-1.0, 2.0);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Standard exception: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception" << std::endl;
    }
    
    // Custom exception
    try {
        throw CustomException("This is a custom exception");
    } catch (const CustomException& e) {
        std::cerr << "Custom exception: " << e.what() << std::endl;
    }
    
    // STL containers
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::list<std::string> lst = {"apple", "banana", "cherry"};
    std::map<std::string, int> mp = {{"one", 1}, {"two", 2}, {"three", 3}};
    std::unordered_map<int, std::string> ump = {{1, "one"}, {2, "two"}, {3, "three"}};
    std::set<int> st = {5, 2, 8, 1, 9};
    std::unordered_set<std::string> ust = {"red", "green", "blue"};
    
    // STL algorithms
    std::sort(vec.begin(), vec.end());
    std::reverse(vec.begin(), vec.end());
    
    auto it = std::find(vec.begin(), vec.end(), 3);
    if (it != vec.end()) {
        std::cout << "Found element: " << *it << std::endl;
    }
    
    // Object creation and polymorphism
    std::unique_ptr<Shape> shape = std::make_unique<Rectangle>(4.0, 6.0);
    std::cout << "Shape area: " << shape->area() << std::endl;
    std::cout << "Shape perimeter: " << shape->perimeter() << std::endl;
    
    // Template usage
    Container<int> intContainer;
    intContainer.add(1);
    intContainer.add(2);
    intContainer.add(3);
    
    Container<std::string> stringContainer;
    stringContainer.add("hello");
    stringContainer.add("world");
    
    // Template function usage
    int maxInt = maximum(10, 20);
    double maxDouble = maximum(3.14, 2.71);
    
    // Function pointers
    FunctionPtr funcPtr = add;
    int sum = funcPtr(5, 3);
    
    // Functor usage
    Multiply mult;
    int product = mult(4, 7);
    
    // Lambda usage
    auto lambda = [](int x) { return x * x; };
    int squared = lambda(5);
    
    // Modern C++ features
    demonstrateModernCpp();
    
    // Concurrency features
    demonstrateConcurrency();
    
    // Namespace usage
    CustomNamespace::namespaceFunction();
    CustomNamespace::Nested::nestedFunction();
    
    // Casting
    double pi = 3.14159;
    int intPi = static_cast<int>(pi);
    const int constValue = 42;
    int& nonConstRef = const_cast<int&>(constValue);
    
    // Base* to Derived* casting
    Rectangle* rectPtr = dynamic_cast<Rectangle*>(shape.get());
    if (rectPtr) {
        std::cout << "Dynamic cast successful" << std::endl;
    }
    
    // C-style cast (not recommended)
    int cStyleCast = (int)pi;
    
    // Reinterpret cast
    void* voidPtr = reinterpret_cast<void*>(&intVar);
    
    // sizeof operator
    std::cout << "Size of int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "Size of Rectangle: " << sizeof(Rectangle) << " bytes" << std::endl;
    
    // Operator examples
    int a = 10, b = 3;
    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a - b = " << (a - b) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;
    std::cout << "a / b = " << (a / b) << std::endl;
    std::cout << "a % b = " << (a % b) << std::endl;
    std::cout << "a++ = " << (a++) << std::endl;
    std::cout << "++b = " << (++b) << std::endl;
    
    // Bitwise operators
    std::cout << "a & b = " << (a & b) << std::endl;
    std::cout << "a | b = " << (a | b) << std::endl;
    std::cout << "a ^ b = " << (a ^ b) << std::endl;
    std::cout << "~a = " << (~a) << std::endl;
    std::cout << "a << 2 = " << (a << 2) << std::endl;
    std::cout << "a >> 1 = " << (a >> 1) << std::endl;
    
    // Logical operators
    bool x = true, y = false;
    std::cout << "x && y = " << (x && y) << std::endl;
    std::cout << "x || y = " << (x || y) << std::endl;
    std::cout << "!x = " << (!x) << std::endl;
    
    // Comparison operators
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    
    std::cout << "C++ syntax test completed!" << std::endl;
    return 0;
}

// Global variable definitions
int globalVariable = 100;
const int globalConstant = 200;
static int staticGlobalVariable = 300;
extern int externVariable; // Declaration only