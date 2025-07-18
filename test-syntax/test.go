// Single line comment
/* Multi-line comment
   with multiple lines */

package main

import (
	"context"
	"encoding/json"
	"errors"
	"fmt"
	"log"
	"sort"
	"strconv"
	"strings"
	"sync"
	"time"
)

// Constants
const (
	MaxRetries     = 3
	DefaultTimeout = 30 * time.Second
	APIVersion     = "v1.0"
)

// Variables
var (
	globalCounter int
	mu            sync.Mutex
	ErrNotFound   = errors.New("item not found")
)

// Type definitions
type UserID int64
type Status string

// Enum-like constants
const (
	StatusActive   Status = "active"
	StatusInactive Status = "inactive"
	StatusPending  Status = "pending"
)

// Struct with JSON tags
type Person struct {
	ID       UserID                 `json:"id"`
	Name     string                 `json:"name"`
	Age      int                    `json:"age"`
	Email    *string                `json:"email,omitempty"`
	Status   Status                 `json:"status"`
	Created  time.Time              `json:"created"`
	Tags     []string               `json:"tags"`
	Metadata map[string]interface{} `json:"metadata"`
}

// Method with receiver
func (p *Person) Greet() string {
	return fmt.Sprintf("Hello, my name is %s and I'm %d years old", p.Name, p.Age)
}

// Method with value receiver
func (p Person) IsAdult() bool {
	return p.Age >= 18
}

// Method with pointer receiver
func (p *Person) SetEmail(email string) {
	p.Email = &email
}

// String method for fmt.Stringer interface
func (p Person) String() string {
	return fmt.Sprintf("Person{ID: %d, Name: %s, Age: %d}", p.ID, p.Name, p.Age)
}

// Interface definition
type Greeter interface {
	Greet() string
}

// Interface with multiple methods
type PersonManager interface {
	Greeter
	IsAdult() bool
	SetEmail(string)
}

// Embedded struct
type Employee struct {
	Person
	Department string  `json:"department"`
	Salary     float64 `json:"salary"`
}

// Method for embedded struct
func (e *Employee) GetFullInfo() string {
	return fmt.Sprintf("%s works in %s with salary $%.2f", e.Name, e.Department, e.Salary)
}

// Generic function (Go 1.18+)
func FindMax[T comparable](items []T, less func(T, T) bool) T {
	if len(items) == 0 {
		var zero T
		return zero
	}

	max := items[0]
	for _, item := range items[1:] {
		if less(max, item) {
			max = item
		}
	}
	return max
}

// Function with multiple return values
func divide(a, b float64) (float64, error) {
	if b == 0 {
		return 0, errors.New("division by zero")
	}
	return a / b, nil
}

// Function with named return values
func swap(x, y string) (first, second string) {
	first = y
	second = x
	return // naked return
}

// Variadic function
func sum(numbers ...int) int {
	total := 0
	for _, num := range numbers {
		total += num
	}
	return total
}

// Function with context
func fetchUserData(ctx context.Context, userID UserID) (*Person, error) {
	// Simulate API call with timeout
	select {
	case <-time.After(100 * time.Millisecond):
		return &Person{
			ID:      userID,
			Name:    "John Doe",
			Age:     30,
			Status:  StatusActive,
			Created: time.Now(),
			Tags:    []string{"developer", "golang"},
			Metadata: map[string]interface{}{
				"last_login": time.Now().Unix(),
				"ip_address": "192.168.1.1",
			},
		}, nil
	case <-ctx.Done():
		return nil, ctx.Err()
	}
}

// Function with defer
func processFile(filename string) error {
	fmt.Printf("Processing file: %s\n", filename)

	// Simulate file operations
	defer func() {
		fmt.Printf("Finished processing: %s\n", filename)
	}()

	defer func() {
		if r := recover(); r != nil {
			fmt.Printf("Recovered from panic: %v\n", r)
		}
	}()

	// Simulate some work
	time.Sleep(10 * time.Millisecond)
	return nil
}

// Goroutine worker function
func worker(id int, jobs <-chan int, results chan<- int) {
	for job := range jobs {
		fmt.Printf("Worker %d processing job %d\n", id, job)
		time.Sleep(time.Millisecond)
		results <- job * 2
	}
}

// Function demonstrating channels
func demonstrateChannels() {
	jobs := make(chan int, 100)
	results := make(chan int, 100)

	// Start workers
	for w := 1; w <= 3; w++ {
		go worker(w, jobs, results)
	}

	// Send jobs
	for j := 1; j <= 9; j++ {
		jobs <- j
	}
	close(jobs)

	// Collect results
	for r := 1; r <= 9; r++ {
		<-results
	}
}

// Function with select statement
func selectExample() {
	ch1 := make(chan string)
	ch2 := make(chan string)

	go func() {
		time.Sleep(100 * time.Millisecond)
		ch1 <- "message from ch1"
	}()

	go func() {
		time.Sleep(200 * time.Millisecond)
		ch2 <- "message from ch2"
	}()

	for i := 0; i < 2; i++ {
		select {
		case msg1 := <-ch1:
			fmt.Println("Received:", msg1)
		case msg2 := <-ch2:
			fmt.Println("Received:", msg2)
		case <-time.After(300 * time.Millisecond):
			fmt.Println("Timeout")
		}
	}
}

// Main function
func main() {
	// Basic types
	var intVar int = 42
	var floatVar float64 = 3.14159
	var boolVar bool = true
	var stringVar string = "Hello, World!"
	var runeVar rune = '🚀'
	var byteVar byte = 255

	// Short variable declarations
	shortInt := 100
	shortString := "Short declaration"

	// Slice operations
	numbers := []int{1, 2, 3, 4, 5}
	doubled := make([]int, len(numbers))

	for i, num := range numbers {
		doubled[i] = num * 2
	}

	// Slice with append
	numbers = append(numbers, 6, 7, 8)

	// Map operations
	scores := make(map[string]int)
	scores["Alice"] = 95
	scores["Bob"] = 87
	scores["Charlie"] = 92

	// Map literal
	ages := map[string]int{
		"Alice":   30,
		"Bob":     25,
		"Charlie": 35,
	}

	// Control structures
	for i := 0; i < 10; i++ {
		if i%2 == 0 {
			fmt.Printf("Even number: %d\n", i)
		} else {
			fmt.Printf("Odd number: %d\n", i)
		}
	}

	// Range over map
	for name, age := range ages {
		fmt.Printf("%s is %d years old\n", name, age)
	}

	// Switch statement
	switch day := time.Now().Weekday(); day {
	case time.Saturday, time.Sunday:
		fmt.Println("It's weekend!")
	default:
		fmt.Println("It's a weekday")
	}

	// Type switch
	var i interface{} = 42
	switch v := i.(type) {
	case int:
		fmt.Printf("Integer: %d\n", v)
	case string:
		fmt.Printf("String: %s\n", v)
	case bool:
		fmt.Printf("Boolean: %t\n", v)
	default:
		fmt.Printf("Unknown type: %T\n", v)
	}

	// Struct usage
	person := Person{
		ID:      UserID(1),
		Name:    "Alice",
		Age:     30,
		Status:  StatusActive,
		Created: time.Now(),
		Tags:    []string{"developer", "golang"},
		Metadata: map[string]interface{}{
			"department": "engineering",
			"level":      "senior",
		},
	}

	// Method calls
	fmt.Println(person.Greet())
	fmt.Println("Is adult:", person.IsAdult())
	person.SetEmail("alice@example.com")

	// Pointer operations
	personPtr := &person
	fmt.Println("Person pointer:", personPtr)

	// JSON marshaling
	jsonData, err := json.MarshalIndent(person, "", "  ")
	if err != nil {
		log.Printf("JSON marshal error: %v", err)
	} else {
		fmt.Printf("JSON: %s\n", jsonData)
	}

	// Error handling
	result, err := divide(10.0, 2.0)
	if err != nil {
		log.Printf("Division error: %v", err)
	} else {
		fmt.Printf("Division result: %.2f\n", result)
	}

	// Multiple assignment
	first, second := swap("hello", "world")
	fmt.Printf("Swapped: %s, %s\n", first, second)

	// Variadic function call
	total := sum(1, 2, 3, 4, 5)
	fmt.Printf("Sum: %d\n", total)

	// Slice unpacking
	moreNumbers := []int{6, 7, 8, 9, 10}
	totalWithSlice := sum(moreNumbers...)
	fmt.Printf("Sum with slice: %d\n", totalWithSlice)

	// Anonymous function
	multiply := func(a, b int) int {
		return a * b
	}
	fmt.Printf("Multiply: %d\n", multiply(5, 3))

	// Closure
	counter := 0
	increment := func() int {
		counter++
		return counter
	}

	fmt.Printf("Counter: %d\n", increment())
	fmt.Printf("Counter: %d\n", increment())

	// String operations
	text := "Hello, World!"
	fmt.Printf("Length: %d\n", len(text))
	fmt.Printf("Upper: %s\n", strings.ToUpper(text))
	fmt.Printf("Contains 'World': %t\n", strings.Contains(text, "World"))

	// String conversion
	numberStr := "123"
	if num, err := strconv.Atoi(numberStr); err == nil {
		fmt.Printf("Parsed number: %d\n", num)
	}

	// Sort operations
	sort.Ints(numbers)
	fmt.Printf("Sorted numbers: %v\n", numbers)

	// Sort with custom function
	people := []Person{
		{Name: "Alice", Age: 30},
		{Name: "Bob", Age: 25},
		{Name: "Charlie", Age: 35},
	}

	sort.Slice(people, func(i, j int) bool {
		return people[i].Age < people[j].Age
	})

	fmt.Println("Sorted people by age:")
	for _, p := range people {
		fmt.Printf("  %s (%d)\n", p.Name, p.Age)
	}

	// Context usage
	ctx, cancel := context.WithTimeout(context.Background(), 5*time.Second)
	defer cancel()

	userData, err := fetchUserData(ctx, UserID(1))
	if err != nil {
		log.Printf("Fetch error: %v", err)
	} else {
		fmt.Printf("User data: %+v\n", userData)
	}

	// Goroutines and channels
	fmt.Println("Demonstrating channels:")
	demonstrateChannels()

	// Select statement
	fmt.Println("Demonstrating select:")
	selectExample()

	// Defer usage
	if err := processFile("test.txt"); err != nil {
		log.Printf("Process file error: %v", err)
	}

	// Generic function usage (Go 1.18+)
	maxInt := FindMax([]int{1, 5, 3, 9, 2}, func(a, b int) bool { return a < b })
	fmt.Printf("Max integer: %d\n", maxInt)

	// Interface usage
	var greeter Greeter = &person
	fmt.Println("Interface greeting:", greeter.Greet())

	// Type assertion
	if p, ok := greeter.(*Person); ok {
		fmt.Printf("Type assertion successful: %s\n", p.Name)
	}

	// Empty interface
	var empty interface{}
	empty = 42
	fmt.Printf("Empty interface value: %v\n", empty)

	// Embedded struct
	employee := Employee{
		Person: Person{
			ID:     UserID(2),
			Name:   "Bob",
			Age:    28,
			Status: StatusActive,
		},
		Department: "Engineering",
		Salary:     75000.0,
	}

	fmt.Println(employee.GetFullInfo())
	fmt.Println("Employee greeting:", employee.Greet()) // Inherited method

	fmt.Println("Program completed successfully!")
}

// init function
func init() {
	fmt.Println("Package initialized")
}
