// Single line comment
/* Multi-line comment
   with multiple lines */

/**
 * @file test.c
 * @brief Comprehensive C syntax test file for theme highlighting
 * @author C Developer
 * @version 1.0
 * @date 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>

// Preprocessor directives
#define MAX_SIZE 100
#define PI 3.14159
#define SQUARE(x) ((x) * (x))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#ifdef DEBUG
    #define DEBUG_PRINT(fmt, ...) printf("DEBUG: " fmt "\n", ##__VA_ARGS__)
#else
    #define DEBUG_PRINT(fmt, ...)
#endif

#ifndef VERSION
    #define VERSION "1.0.0"
#endif

// Conditional compilation
#if defined(__GNUC__)
    #define COMPILER "GCC"
#elif defined(_MSC_VER)
    #define COMPILER "MSVC"
#else
    #define COMPILER "Unknown"
#endif

// Constants
const int GLOBAL_CONSTANT = 42;
const char* PROGRAM_NAME = "C Syntax Test";
const float EPSILON = 1e-6f;

// Global variables
static int static_counter = 0;
extern int external_variable;
int global_variable = 100;
volatile int hardware_register = 0;

// Type definitions
typedef struct Point Point;
typedef struct Person Person;
typedef union Number Number;
typedef enum Status Status;
typedef int (*FunctionPtr)(int, int);
typedef void (*CallbackPtr)(const char*);

// Enum definitions
enum Color {
    RED,
    GREEN,
    BLUE,
    YELLOW = 10,
    PURPLE,
    ORANGE
};

enum Status {
    STATUS_INACTIVE = 0,
    STATUS_ACTIVE = 1,
    STATUS_PENDING = 2,
    STATUS_ERROR = -1
};

// Struct definitions
struct Point {
    double x;
    double y;
    char label[32];
};

struct Person {
    char name[50];
    int age;
    char email[100];
    Status status;
    struct Point location;
    struct Person* next; // Self-referencing pointer
};

// Union definition
union Number {
    int intValue;
    float floatValue;
    double doubleValue;
    char bytes[8];
};

// Bit fields
struct Flags {
    unsigned int flag1 : 1;
    unsigned int flag2 : 1;
    unsigned int flag3 : 1;
    unsigned int reserved : 5;
    unsigned int count : 24;
};

// Function prototypes
void print_banner(void);
int add_numbers(int a, int b);
double calculate_distance(Point p1, Point p2);
Person* create_person(const char* name, int age, const char* email);
void free_person(Person* person);
void print_person(const Person* person);
int compare_persons_by_age(const void* a, const void* b);
void demonstrate_arrays(void);
void demonstrate_strings(void);
void demonstrate_pointers(void);
void demonstrate_control_flow(void);
void demonstrate_functions(void);
void demonstrate_file_operations(void);
char* safe_string_copy(char* dest, const char* src, size_t dest_size);
int fibonacci(int n);
int factorial(int n);
void bubble_sort(int arr[], int n);
void callback_example(CallbackPtr callback);
void sample_callback(const char* message);

// Function implementations
void print_banner(void) {
    printf("===========================================\n");
    printf("        %s v%s\n", PROGRAM_NAME, VERSION);
    printf("        Compiled with %s\n", COMPILER);
    printf("===========================================\n");
}

int add_numbers(int a, int b) {
    return a + b;
}

double calculate_distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

Person* create_person(const char* name, int age, const char* email) {
    if (name == NULL || email == NULL) {
        return NULL;
    }

    Person* person = (Person*)malloc(sizeof(Person));
    if (person == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    // Initialize the person
    strncpy(person->name, name, sizeof(person->name) - 1);
    person->name[sizeof(person->name) - 1] = '\0';
    
    person->age = age;
    
    strncpy(person->email, email, sizeof(person->email) - 1);
    person->email[sizeof(person->email) - 1] = '\0';
    
    person->status = STATUS_ACTIVE;
    person->location.x = 0.0;
    person->location.y = 0.0;
    strcpy(person->location.label, "Origin");
    person->next = NULL;

    return person;
}

void free_person(Person* person) {
    if (person != NULL) {
        free(person);
    }
}

void print_person(const Person* person) {
    if (person == NULL) {
        printf("Person is NULL\n");
        return;
    }

    printf("Person Information:\n");
    printf("  Name: %s\n", person->name);
    printf("  Age: %d\n", person->age);
    printf("  Email: %s\n", person->email);
    printf("  Status: %d\n", person->status);
    printf("  Location: (%.2f, %.2f) - %s\n", 
           person->location.x, person->location.y, person->location.label);
}

int compare_persons_by_age(const void* a, const void* b) {
    const Person* person_a = (const Person*)a;
    const Person* person_b = (const Person*)b;
    return person_a->age - person_b->age;
}

void demonstrate_arrays(void) {
    printf("\n--- Array Demonstration ---\n");
    
    // Array declarations and initializations
    int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int partial_init[5] = {1, 2}; // Remaining elements are 0
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    char message[] = "Hello, World!";
    
    // Multi-dimensional arrays
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // Array of strings
    const char* days[] = {
        "Monday", "Tuesday", "Wednesday", "Thursday",
        "Friday", "Saturday", "Sunday"
    };
    
    // Print arrays
    printf("Numbers array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    printf("Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    printf("Days of the week:\n");
    for (size_t i = 0; i < sizeof(days) / sizeof(days[0]); i++) {
        printf("  %zu: %s\n", i + 1, days[i]);
    }
    
    // Array pointer arithmetic
    int* ptr = numbers;
    printf("Using pointer arithmetic: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
}

void demonstrate_strings(void) {
    printf("\n--- String Demonstration ---\n");
    
    // String literals
    char str1[] = "String literal";
    char str2[100] = "Another string";
    const char* str3 = "Constant string";
    char str4[50];
    
    // String operations
    strcpy(str4, "Copied string");
    strcat(str2, " with concatenation");
    
    printf("str1: %s (length: %lu)\n", str1, strlen(str1));
    printf("str2: %s (length: %lu)\n", str2, strlen(str2));
    printf("str3: %s\n", str3);
    printf("str4: %s\n", str4);
    
    // String comparison
    if (strcmp(str1, str4) == 0) {
        printf("str1 and str4 are equal\n");
    } else {
        printf("str1 and str4 are different\n");
    }
    
    // Character operations
    char ch = 'A';
    printf("Character: %c, ASCII: %d\n", ch, ch);
    printf("Is uppercase: %s\n", isupper(ch) ? "Yes" : "No");
    printf("Lowercase: %c\n", tolower(ch));
    
    // String parsing
    char numbers_str[] = "123 456 789";
    char* token = strtok(numbers_str, " ");
    printf("Tokens: ");
    while (token != NULL) {
        printf("%s ", token);
        token = strtok(NULL, " ");
    }
    printf("\n");
}

void demonstrate_pointers(void) {
    printf("\n--- Pointer Demonstration ---\n");
    
    // Basic pointers
    int value = 42;
    int* ptr = &value;
    int** double_ptr = &ptr;
    
    printf("value = %d\n", value);
    printf("ptr = %p, *ptr = %d\n", (void*)ptr, *ptr);
    printf("double_ptr = %p, *double_ptr = %p, **double_ptr = %d\n", 
           (void*)double_ptr, (void*)*double_ptr, **double_ptr);
    
    // Pointer arithmetic
    int array[] = {10, 20, 30, 40, 50};
    int* arr_ptr = array;
    
    printf("Array using pointer arithmetic:\n");
    for (int i = 0; i < 5; i++) {
        printf("  array[%d] = %d, *(arr_ptr + %d) = %d\n", 
               i, array[i], i, *(arr_ptr + i));
    }
    
    // Function pointers
    FunctionPtr func_ptr = add_numbers;
    int sum = func_ptr(15, 25);
    printf("Function pointer result: %d\n", sum);
    
    // Null pointer
    int* null_ptr = NULL;
    if (null_ptr == NULL) {
        printf("null_ptr is NULL\n");
    }
    
    // Dynamic memory allocation
    int* dynamic_array = (int*)malloc(5 * sizeof(int));
    if (dynamic_array != NULL) {
        for (int i = 0; i < 5; i++) {
            dynamic_array[i] = i * i;
        }
        
        printf("Dynamic array: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", dynamic_array[i]);
        }
        printf("\n");
        
        free(dynamic_array);
    }
    
    // Void pointer
    void* void_ptr = &value;
    int* int_ptr_from_void = (int*)void_ptr;
    printf("Value through void pointer: %d\n", *int_ptr_from_void);
}

void demonstrate_control_flow(void) {
    printf("\n--- Control Flow Demonstration ---\n");
    
    // If-else statements
    int number = 15;
    if (number > 0) {
        printf("%d is positive\n", number);
    } else if (number < 0) {
        printf("%d is negative\n", number);
    } else {
        printf("%d is zero\n", number);
    }
    
    // Ternary operator
    const char* parity = (number % 2 == 0) ? "even" : "odd";
    printf("%d is %s\n", number, parity);
    
    // Switch statement
    enum Color color = BLUE;
    switch (color) {
        case RED:
            printf("Color is red\n");
            break;
        case GREEN:
            printf("Color is green\n");
            break;
        case BLUE:
            printf("Color is blue\n");
            break;
        case YELLOW:
            printf("Color is yellow\n");
            break;
        default:
            printf("Unknown color\n");
            break;
    }
    
    // For loops
    printf("For loop (ascending): ");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    printf("For loop (descending): ");
    for (int i = 5; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\n");
    
    // While loop
    printf("While loop: ");
    int count = 1;
    while (count <= 5) {
        printf("%d ", count);
        count++;
    }
    printf("\n");
    
    // Do-while loop
    printf("Do-while loop: ");
    int i = 1;
    do {
        printf("%d ", i);
        i++;
    } while (i <= 5);
    printf("\n");
    
    // Nested loops with break and continue
    printf("Nested loops with break and continue:\n");
    for (int outer = 1; outer <= 3; outer++) {
        printf("  Outer loop %d: ", outer);
        for (int inner = 1; inner <= 5; inner++) {
            if (inner == 3) {
                continue; // Skip 3
            }
            if (inner == 5 && outer == 2) {
                break; // Break inner loop when outer is 2
            }
            printf("%d ", inner);
        }
        printf("\n");
    }
    
    // Goto statement (rarely used, but part of C)
    printf("Using goto (demonstration only): ");
    int j = 1;
    loop_start:
        if (j <= 3) {
            printf("%d ", j);
            j++;
            goto loop_start;
        }
    printf("\n");
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sample_callback(const char* message) {
    printf("Callback received: %s\n", message);
}

void callback_example(CallbackPtr callback) {
    if (callback != NULL) {
        callback("Hello from callback!");
    }
}

void demonstrate_functions(void) {
    printf("\n--- Function Demonstration ---\n");
    
    // Function calls
    int sum = add_numbers(10, 20);
    printf("Sum of 10 and 20: %d\n", sum);
    
    // Recursive functions
    printf("Fibonacci sequence (first 10): ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    
    printf("Factorials:\n");
    for (int i = 1; i <= 5; i++) {
        printf("  %d! = %d\n", i, factorial(i));
    }
    
    // Function with array parameter
    int numbers[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Before sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    bubble_sort(numbers, size);
    
    printf("After sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    // Callback function
    callback_example(sample_callback);
    
    // Function pointer array
    int (*operations[])(int, int) = {add_numbers};
    int result = operations[0](5, 7);
    printf("Function pointer array result: %d\n", result);
}

char* safe_string_copy(char* dest, const char* src, size_t dest_size) {
    if (dest == NULL || src == NULL || dest_size == 0) {
        return NULL;
    }
    
    strncpy(dest, src, dest_size - 1);
    dest[dest_size - 1] = '\0';
    return dest;
}

void demonstrate_file_operations(void) {
    printf("\n--- File Operations Demonstration ---\n");
    
    const char* filename = "test_output.txt";
    FILE* file;
    
    // Write to file
    file = fopen(filename, "w");
    if (file != NULL) {
        fprintf(file, "Hello, File Operations!\n");
        fprintf(file, "This is a test file.\n");
        fprintf(file, "Number: %d\n", 42);
        fprintf(file, "Float: %.2f\n", 3.14159);
        fclose(file);
        printf("Successfully wrote to %s\n", filename);
    } else {
        printf("Failed to open %s for writing\n", filename);
        return;
    }
    
    // Read from file
    file = fopen(filename, "r");
    if (file != NULL) {
        char buffer[256];
        printf("Reading from %s:\n", filename);
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("  %s", buffer);
        }
        fclose(file);
    } else {
        printf("Failed to open %s for reading\n", filename);
    }
    
    // Remove the test file
    if (remove(filename) == 0) {
        printf("Successfully removed %s\n", filename);
    } else {
        printf("Failed to remove %s\n", filename);
    }
}

// Main function
int main(int argc, char* argv[]) {
    // Print command line arguments
    printf("Command line arguments:\n");
    printf("  argc = %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("  argv[%d] = %s\n", i, argv[i]);
    }
    printf("\n");
    
    print_banner();
    
    // Basic data types
    printf("\n--- Basic Data Types ---\n");
    
    // Integer types
    char char_var = 'Z';
    signed char signed_char_var = -100;
    unsigned char unsigned_char_var = 200;
    short short_var = -32000;
    unsigned short unsigned_short_var = 60000;
    int int_var = -1000000;
    unsigned int unsigned_int_var = 2000000U;
    long long_var = -2000000000L;
    unsigned long unsigned_long_var = 4000000000UL;
    long long long_long_var = -9000000000000000LL;
    unsigned long long unsigned_long_long_var = 18000000000000000ULL;
    
    // Floating point types
    float float_var = 3.14159f;
    double double_var = 2.718281828459045;
    long double long_double_var = 1.4142135623730951L;
    
    // Boolean type (C99)
    bool bool_var = true;
    _Bool c_bool_var = 1;
    
    // Size types
    size_t size_var = sizeof(int);
    ptrdiff_t ptr_diff = &int_var - &char_var;
    
    printf("char: %c (size: %zu bytes)\n", char_var, sizeof(char_var));
    printf("int: %d (size: %zu bytes)\n", int_var, sizeof(int_var));
    printf("float: %.6f (size: %zu bytes)\n", float_var, sizeof(float_var));
    printf("double: %.15f (size: %zu bytes)\n", double_var, sizeof(double_var));
    printf("bool: %s (size: %zu bytes)\n", bool_var ? "true" : "false", sizeof(bool_var));
    
    // Hexadecimal and octal numbers
    int hex_number = 0xFF; // 255 in decimal
    int octal_number = 0377; // 255 in decimal
    int binary_representation = 0b11111111; // GCC extension
    
    printf("Hex 0xFF = %d\n", hex_number);
    printf("Octal 0377 = %d\n", octal_number);
    
    // Character escape sequences
    printf("Escape sequences:\n");
    printf("  Newline: \\n\n");
    printf("  Tab: \\t\tTabbed text\n");
    printf("  Backslash: \\\\\n");
    printf("  Quote: \"\n");
    printf("  Single quote: \'\n");
    printf("  Bell: \\a\a\n");
    printf("  Carriage return: \\r\rOverwritten\n");
    printf("  Vertical tab: \\v\vText after vtab\n");
    printf("  Form feed: \\f\fText after ff\n");
    
    // Demonstrate various C features
    demonstrate_arrays();
    demonstrate_strings();
    demonstrate_pointers();
    demonstrate_control_flow();
    demonstrate_functions();
    demonstrate_file_operations();
    
    // Struct and union demonstration
    printf("\n--- Struct and Union Demonstration ---\n");
    
    Person* person1 = create_person("Alice Smith", 30, "alice@example.com");
    Person* person2 = create_person("Bob Johnson", 25, "bob@example.com");
    
    if (person1 && person2) {
        print_person(person1);
        printf("\n");
        print_person(person2);
        
        // Calculate distance between persons
        person1->location.x = 10.5;
        person1->location.y = 20.3;
        strcpy(person1->location.label, "Home");
        
        person2->location.x = 15.2;
        person2->location.y = 25.7;
        strcpy(person2->location.label, "Office");
        
        double distance = calculate_distance(person1->location, person2->location);
        printf("\nDistance between %s and %s: %.2f units\n", 
               person1->name, person2->name, distance);
        
        free_person(person1);
        free_person(person2);
    }
    
    // Union demonstration
    Number num;
    num.intValue = 42;
    printf("\nUnion demonstration:\n");
    printf("  As int: %d\n", num.intValue);
    printf("  As float: %f (garbage, same memory)\n", num.floatValue);
    
    num.floatValue = 3.14f;
    printf("  As float: %f\n", num.floatValue);
    printf("  As int: %d (garbage, same memory)\n", num.intValue);
    
    // Bit manipulation
    printf("\n--- Bit Manipulation ---\n");
    unsigned int flags = 0;
    
    // Set bits
    flags |= (1 << 0); // Set bit 0
    flags |= (1 << 2); // Set bit 2
    flags |= (1 << 5); // Set bit 5
    
    printf("Flags after setting bits 0, 2, 5: 0x%X\n", flags);
    
    // Check bits
    if (flags & (1 << 2)) {
        printf("Bit 2 is set\n");
    }
    
    // Clear bit
    flags &= ~(1 << 2); // Clear bit 2
    printf("Flags after clearing bit 2: 0x%X\n", flags);
    
    // Toggle bit
    flags ^= (1 << 1); // Toggle bit 1
    printf("Flags after toggling bit 1: 0x%X\n", flags);
    
    // Macros and preprocessor
    printf("\n--- Macro Demonstration ---\n");
    printf("MAX_SIZE = %d\n", MAX_SIZE);
    printf("PI = %f\n", PI);
    printf("SQUARE(5) = %d\n", SQUARE(5));
    printf("MIN(10, 20) = %d\n", MIN(10, 20));
    printf("MAX(10, 20) = %d\n", MAX(10, 20));
    
    DEBUG_PRINT("This is a debug message with value: %d", 123);
    
    // Static variables
    static int static_local = 0;
    static_local++;
    static_counter++;
    printf("\nStatic variables:\n");
    printf("  static_local: %d\n", static_local);
    printf("  static_counter: %d\n", static_counter);
    
    // Register variable (hint to compiler)
    register int fast_var = 100;
    printf("  register variable: %d\n", fast_var);
    
    // Volatile variable
    printf("  volatile variable: %d\n", hardware_register);
    
    // Assert macro
    assert(1 == 1); // This will not trigger
    printf("Assert passed successfully\n");
    
    // Error handling with errno
    FILE* nonexistent = fopen("nonexistent_file.txt", "r");
    if (nonexistent == NULL) {
        printf("Failed to open file. errno = %d, error: %s\n", errno, strerror(errno));
    }
    
    // Time functions
    time_t current_time = time(NULL);
    printf("Current time: %s", ctime(&current_time));
    
    // Math functions
    printf("\n--- Math Operations ---\n");
    double angle = PI / 4; // 45 degrees
    printf("sin(PI/4) = %.6f\n", sin(angle));
    printf("cos(PI/4) = %.6f\n", cos(angle));
    printf("sqrt(16) = %.6f\n", sqrt(16.0));
    printf("pow(2, 8) = %.0f\n", pow(2.0, 8.0));
    printf("ceil(3.2) = %.0f\n", ceil(3.2));
    printf("floor(3.8) = %.0f\n", floor(3.8));
    
    printf("\nC syntax test completed successfully!\n");
    
    return EXIT_SUCCESS;
}

// Static function (internal linkage)
static void internal_function(void) {
    printf("This is an internal function\n");
}

// Inline function (C99)
inline int inline_square(int x) {
    return x * x;
}

// Function with restrict keyword (C99)
void copy_array(int* restrict dest, const int* restrict src, size_t n) {
    for (size_t i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

// Variable length array function (C99)
void print_matrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Designated initializers (C99)
void demonstrate_designated_initializers(void) {
    struct Point points[] = {
        {.x = 1.0, .y = 2.0, .label = "Point1"},
        {.x = 3.0, .y = 4.0, .label = "Point2"},
        [2] = {.x = 5.0, .y = 6.0, .label = "Point3"}
    };
    
    int array[10] = {[0] = 1, [4] = 5, [9] = 10};
}

// Compound literals (C99)
void demonstrate_compound_literals(void) {
    Point* p = &(Point){.x = 1.0, .y = 2.0, .label = "Compound"};
    
    int* arr = (int[]){1, 2, 3, 4, 5};
}