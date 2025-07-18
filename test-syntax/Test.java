// Single line comment
/* Multi-line comment
   with multiple lines */

/**
 * JavaDoc documentation for the main test class
 * This class demonstrates various Java syntax elements
 * for testing theme highlighting
 *
 * @author Java Developer
 * @version 1.0
 * @since Java 8
 */

package com.example.syntax.test;

import java.io.*;
import java.nio.file.*;
import java.time.*;
import java.time.format.DateTimeFormatter;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.stream.*;
import static java.lang.System.*;
import static java.util.stream.Collectors.*;

// Sealed class (Java 17+)
public sealed class SyntaxTest permits Employee, Manager {

    // Constants
    public static final String CONSTANT_STRING = "CONSTANT_VALUE";
    public static final int MAX_SIZE = 100;
    public static final double PI = 3.14159;
    private static final long TIMEOUT = 5000L;

    // Static initialization block
    static {
        out.println("Static block executed");
    }

    // Instance initialization block
    {
        out.println("Instance block executed");
    }

    // Fields with different access modifiers
    private String name;
    protected int age;
    public String email;
    String packagePrivateField; // package-private

    // Generic field
    private List<String> tags = new ArrayList<>();
    private Map<String, Object> metadata = new HashMap<>();

    // Constructor
    public SyntaxTest(String name, int age) {
        this.name = Objects.requireNonNull(name, "Name cannot be null");
        this.age = age;
        validateAge(age);
    }

    // Overloaded constructor
    public SyntaxTest(String name, int age, String email) {
        this(name, age); // Constructor chaining
        this.email = email;
    }

    // Getter methods
    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public String getEmail() {
        return email;
    }

    // Setter methods with validation
    public void setName(String name) {
        if (name == null || name.trim().isEmpty()) {
            throw new IllegalArgumentException("Name cannot be null or empty");
        }
        this.name = name;
    }

    public void setAge(int age) {
        validateAge(age);
        this.age = age;
    }

    public void setEmail(String email) {
        if (email != null && !isValidEmail(email)) {
            throw new IllegalArgumentException("Invalid email format");
        }
        this.email = email;
    }

    // Private helper method
    private void validateAge(int age) {
        if (age < 0 || age > 150) {
            throw new IllegalArgumentException("Age must be between 0 and 150");
        }
    }

    // Method with varargs
    public void addTags(String... newTags) {
        Collections.addAll(tags, newTags);
    }

    // Generic method
    public <T> T getMetadata(String key, Class<T> type) {
        Object value = metadata.get(key);
        return type.isInstance(value) ? type.cast(value) : null;
    }

    // Method with throws clause
    public void saveToFile(String filename) throws IOException {
        try (BufferedWriter writer = Files.newBufferedWriter(Paths.get(filename))) {
            writer.write(toString());
        }
    }

    // Static method
    public static boolean isValidEmail(String email) {
        return email != null && email.matches("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    }

    // Abstract method (if class were abstract)
    // public abstract void abstractMethod();

    // Final method
    public final String getDisplayName() {
        return String.format("%s (%d years old)", name, age);
    }

    // Synchronized method
    public synchronized void incrementCounter() {
        // Thread-safe operation
    }

    // Native method declaration
    // public native void nativeMethod();

    // Method with lambda expressions (Java 8+)
    public void demonstrateLambdas() {
        // Simple lambda
        Runnable task = () -> out.println("Lambda executed");
        task.run();

        // Lambda with parameters
        BinaryOperator<Integer> add = (a, b) -> a + b;
        Integer result = add.apply(5, 3);

        // Method reference
        tags.forEach(out::println);

        // Constructor reference
        Supplier<List<String>> listSupplier = ArrayList::new;
        List<String> newList = listSupplier.get();
    }

    // Method with streams (Java 8+)
    public void demonstrateStreams() {
        List<Integer> numbers = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

        // Stream operations
        List<Integer> evenSquares = numbers.stream()
            .filter(n -> n % 2 == 0)
            .map(n -> n * n)
            .collect(toList());

        // Parallel stream
        OptionalDouble average = numbers.parallelStream()
            .mapToInt(Integer::intValue)
            .average();

        // Grouping
        Map<Boolean, List<Integer>> partitioned = numbers.stream()
            .collect(partitioningBy(n -> n % 2 == 0));

        // Finding elements
        Optional<Integer> max = numbers.stream()
            .max(Integer::compareTo);

        // Reduce operation
        Integer sum = numbers.stream()
            .reduce(0, Integer::sum);
    }

    // Method with text blocks (Java 13+)
    public String getJsonExample() {
        return """
            {
                "name": "%s",
                "age": %d,
                "email": "%s",
                "tags": %s
            }
            """.formatted(name, age, email != null ? email : "null", tags);
    }

    // Method with switch expressions (Java 12+)
    public String getAgeCategory() {
        return switch (age) {
            case 0, 1, 2 -> "Baby";
            case 3, 4, 5 -> "Toddler";
            default -> {
                if (age < 13) yield "Child";
                else if (age < 20) yield "Teenager";
                else if (age < 65) yield "Adult";
                else yield "Senior";
            }
        };
    }

    // Method with pattern matching (Java 17+)
    public String describeObject(Object obj) {
        return switch (obj) {
            case String s -> "String with length: " + s.length();
            case Integer i -> "Integer with value: " + i;
            case List<?> list -> "List with size: " + list.size();
            case null -> "Null object";
            default -> "Unknown type: " + obj.getClass().getSimpleName();
        };
    }

    // Method demonstrating various control structures
    public void demonstrateControlFlow() {
        // If-else statements
        if (age < 18) {
            out.println("Minor");
        } else if (age < 65) {
            out.println("Adult");
        } else {
            out.println("Senior");
        }

        // Traditional for loop
        for (int i = 0; i < 10; i++) {
            if (i % 2 == 0) {
                continue; // Skip even numbers
            }
            out.println("Odd number: " + i);
            if (i > 7) {
                break; // Exit loop early
            }
        }

        // Enhanced for loop
        for (String tag : tags) {
            out.println("Tag: " + tag);
        }

        // While loop
        int count = 0;
        while (count < 5) {
            out.println("Count: " + count);
            count++;
        }

        // Do-while loop
        int i = 0;
        do {
            out.println("Do-while iteration: " + i);
            i++;
        } while (i < 3);

        // Traditional switch statement
        int dayOfWeek = LocalDate.now().getDayOfWeek().getValue();
        switch (dayOfWeek) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                out.println("Weekday");
                break;
            case 6:
            case 7:
                out.println("Weekend");
                break;
            default:
                out.println("Invalid day");
        }
    }

    // Method demonstrating exception handling
    public void demonstrateExceptionHandling() {
        // Try-catch-finally
        try {
            String result = riskyOperation();
            out.println("Operation successful: " + result);
        } catch (IllegalArgumentException e) {
            err.println("Illegal argument: " + e.getMessage());
        } catch (RuntimeException e) {
            err.println("Runtime exception: " + e.getMessage());
        } catch (Exception e) {
            err.println("General exception: " + e.getMessage());
        } finally {
            out.println("Cleanup code executed");
        }

        // Try-with-resources
        try (FileInputStream fis = new FileInputStream("test.txt");
             BufferedReader reader = new BufferedReader(new InputStreamReader(fis))) {

            String line = reader.readLine();
            out.println("Read line: " + line);

        } catch (IOException e) {
            err.println("IO Error: " + e.getMessage());
        }

        // Multi-catch
        try {
            performOperation();
        } catch (IOException | SQLException e) {
            err.println("Database or IO error: " + e.getMessage());
        }
    }

    // Methods that throw exceptions
    private String riskyOperation() throws Exception {
        if (Math.random() < 0.5) {
            throw new RuntimeException("Random failure");
        }
        return "Success";
    }

    private void performOperation() throws IOException, SQLException {
        // Simulated operation that might throw exceptions
    }

    // Override methods
    @Override
    public String toString() {
        return String.format("SyntaxTest{name='%s', age=%d, email='%s'}",
                           name, age, email);
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;

        SyntaxTest that = (SyntaxTest) obj;
        return age == that.age &&
               Objects.equals(name, that.name) &&
               Objects.equals(email, that.email);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, age, email);
    }

    // Inner classes
    public class InnerClass {
        private String innerField;

        public InnerClass(String value) {
            this.innerField = value;
        }

        public void accessOuterClass() {
            out.println("Accessing outer class: " + SyntaxTest.this.name);
        }
    }

    // Static nested class
    public static class StaticNestedClass {
        private static final String NESTED_CONSTANT = "Nested";

        public void doSomething() {
            out.println("Static nested class method");
        }
    }

    // Local class example
    public void demonstrateLocalClass() {
        final String localVariable = "Local";

        class LocalClass {
            void localMethod() {
                out.println("Local class accessing: " + localVariable);
            }
        }

        LocalClass local = new LocalClass();
        local.localMethod();
    }

    // Anonymous class example
    public void demonstrateAnonymousClass() {
        Runnable anonymous = new Runnable() {
            @Override
            public void run() {
                out.println("Anonymous class implementation");
            }
        };
        anonymous.run();

        // Anonymous class with interface
        Comparator<String> stringComparator = new Comparator<String>() {
            @Override
            public int compare(String s1, String s2) {
                return s1.compareToIgnoreCase(s2);
            }
        };
    }

    // Main method
    public static void main(String[] args) {
        out.println("Starting Java syntax test...");

        // Object creation
        SyntaxTest test = new SyntaxTest("John Doe", 30, "john@example.com");
        test.addTags("developer", "java", "programming");

        // Method calls
        out.println(test.getDisplayName());
        out.println("Age category: " + test.getAgeCategory());

        // Demonstrate various features
        test.demonstrateLambdas();
        test.demonstrateStreams();
        test.demonstrateControlFlow();
        test.demonstrateExceptionHandling();
        test.demonstrateLocalClass();
        test.demonstrateAnonymousClass();

        // JSON output
        out.println("JSON representation:");
        out.println(test.getJsonExample());

        // Object description
        out.println(test.describeObject("Hello World"));
        out.println(test.describeObject(42));
        out.println(test.describeObject(Arrays.asList(1, 2, 3)));

        // Collections demonstration
        List<String> list = new ArrayList<>();
        Set<String> set = new HashSet<>();
        Map<String, Integer> map = new HashMap<>();

        // Array operations
        int[] numbers = {1, 2, 3, 4, 5};
        String[] names = new String[10];
        Object[][] matrix = new Object[3][3];

        // Primitive types
        byte byteVar = 127;
        short shortVar = 32767;
        int intVar = 2147483647;
        long longVar = 9223372036854775807L;
        float floatVar = 3.14f;
        double doubleVar = 3.141592653589793;
        char charVar = 'A';
        boolean boolVar = true;

        // Wrapper classes
        Integer integerWrapper = Integer.valueOf(42);
        Double doubleWrapper = Double.valueOf(3.14);
        Boolean booleanWrapper = Boolean.TRUE;

        // String operations
        String str1 = "Hello";
        String str2 = new String("World");
        String concatenated = str1 + " " + str2;
        String formatted = String.format("Name: %s, Age: %d", test.getName(), test.getAge());

        out.println("Java syntax test completed!");
    }
}

// Interface definition
interface Greeter {
    // Abstract method
    String greet();

    // Default method (Java 8+)
    default String greetFormal() {
        return "Good day, " + greet();
    }

    // Static method (Java 8+)
    static String getGreetingFormat() {
        return "Hello, %s!";
    }

    // Constant (implicitly public static final)
    String DEFAULT_GREETING = "Hello";
}

// Functional interface (Java 8+)
@FunctionalInterface
interface Calculator {
    int calculate(int a, int b);
}

// Annotation definition
@interface CustomAnnotation {
    String value() default "";
    int priority() default 0;
    String[] tags() default {};
}

// Enum definition
enum Status {
    ACTIVE("Active", 1),
    INACTIVE("Inactive", 0),
    PENDING("Pending", 2);

    private final String description;
    private final int code;

    Status(String description, int code) {
        this.description = description;
        this.code = code;
    }

    public String getDescription() {
        return description;
    }

    public int getCode() {
        return code;
    }

    // Enum with abstract method
    public abstract void performAction();
}

// Enhanced enum with abstract methods
enum Operation {
    PLUS("+") {
        @Override
        public double apply(double x, double y) {
            return x + y;
        }
    },
    MINUS("-") {
        @Override
        public double apply(double x, double y) {
            return x - y;
        }
    },
    MULTIPLY("*") {
        @Override
        public double apply(double x, double y) {
            return x * y;
        }
    },
    DIVIDE("/") {
        @Override
        public double apply(double x, double y) {
            return x / y;
        }
    };

    private final String symbol;

    Operation(String symbol) {
        this.symbol = symbol;
    }

    public abstract double apply(double x, double y);

    public String getSymbol() {
        return symbol;
    }
}

// Record class (Java 14+)
record PersonRecord(String name, int age, String email) {
    // Compact constructor
    public PersonRecord {
        if (age < 0) {
            throw new IllegalArgumentException("Age cannot be negative");
        }
        if (name == null || name.isBlank()) {
            throw new IllegalArgumentException("Name cannot be null or blank");
        }
    }

    // Additional constructor
    public PersonRecord(String name, int age) {
        this(name, age, null);
    }

    // Instance method
    public String getDisplayName() {
        return String.format("%s (%d)", name, age);
    }

    // Static method
    public static PersonRecord createChild(String name) {
        return new PersonRecord(name, 0);
    }
}

// Sealed class implementations
final class Employee extends SyntaxTest {
    private String employeeId;
    private String department;

    public Employee(String name, int age, String employeeId, String department) {
        super(name, age);
        this.employeeId = employeeId;
        this.department = department;
    }

    public String getEmployeeId() {
        return employeeId;
    }

    public String getDepartment() {
        return department;
    }
}

final class Manager extends Employee {
    private List<Employee> directReports;

    public Manager(String name, int age, String employeeId, String department) {
        super(name, age, employeeId, department);
        this.directReports = new ArrayList<>();
    }

    public void addDirectReport(Employee employee) {
        directReports.add(employee);
    }

    public List<Employee> getDirectReports() {
        return Collections.unmodifiableList(directReports);
    }
}

// Exception classes
class CustomException extends Exception {
    public CustomException(String message) {
        super(message);
    }

    public CustomException(String message, Throwable cause) {
        super(message, cause);
    }
}

class ValidationException extends RuntimeException {
    private final String field;

    public ValidationException(String field, String message) {
        super(message);
        this.field = field;
    }

    public String getField() {
        return field;
    }
}
