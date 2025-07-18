# Single line comment
"""
Multi-line comment
or module docstring
This demonstrates various Python syntax elements
for testing theme highlighting
"""

import json
import re
import asyncio
import threading
from typing import List, Dict, Optional, Union, Tuple, Any, Callable, Generic, TypeVar
from dataclasses import dataclass, field
from enum import Enum, IntEnum, auto
from collections import defaultdict, namedtuple
from contextlib import contextmanager
from functools import wraps, lru_cache
from pathlib import Path
import datetime as dt

# Constants
MAX_SIZE = 100
PI = 3.14159
API_URL = "https://api.example.com"

# Type variables
T = TypeVar('T')
U = TypeVar('U', bound='BaseClass')

# Enum definitions
class Status(Enum):
    ACTIVE = "active"
    INACTIVE = "inactive"
    PENDING = "pending"

class Priority(IntEnum):
    LOW = 1
    MEDIUM = 2
    HIGH = 3
    CRITICAL = auto()

# Dataclass with type hints
@dataclass
class Person:
    """A person with basic information."""
    name: str
    age: int
    email: Optional[str] = None
    tags: List[str] = field(default_factory=list)
    metadata: Dict[str, Any] = field(default_factory=dict)

    def __post_init__(self):
        """Post-initialization validation."""
        if self.age < 0:
            raise ValueError("Age cannot be negative")

    def greet(self) -> str:
        """Return a greeting message."""
        return f"Hello, my name is {self.name} and I'm {self.age} years old"

    def is_adult(self) -> bool:
        """Check if person is an adult."""
        return self.age >= 18

    @classmethod
    def from_dict(cls, data: Dict[str, Any]) -> 'Person':
        """Create Person from dictionary."""
        return cls(**data)

    @staticmethod
    def validate_email(email: str) -> bool:
        """Validate email format."""
        pattern = r'^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$'
        return re.match(pattern, email) is not None

# Regular class with inheritance
class Employee(Person):
    """Employee class inheriting from Person."""

    def __init__(self, name: str, age: int, employee_id: str,
                 department: str, salary: float, **kwargs):
        super().__init__(name, age, **kwargs)
        self.employee_id = employee_id
        self.department = department
        self._salary = salary  # Private attribute
        self.__secret = "confidential"  # Name mangled

    @property
    def salary(self) -> float:
        """Get salary (property getter)."""
        return self._salary

    @salary.setter
    def salary(self, value: float) -> None:
        """Set salary with validation (property setter)."""
        if value < 0:
            raise ValueError("Salary cannot be negative")
        self._salary = value

    def get_full_info(self) -> str:
        """Get complete employee information."""
        return f"{self.name} (ID: {self.employee_id}) works in {self.department}"

    def __str__(self) -> str:
        """String representation."""
        return f"Employee({self.name}, {self.department})"

    def __repr__(self) -> str:
        """Developer representation."""
        return f"Employee(name='{self.name}', department='{self.department}')"

# Generic class
class Container(Generic[T]):
    """Generic container class."""

    def __init__(self):
        self._items: List[T] = []

    def add(self, item: T) -> None:
        """Add item to container."""
        self._items.append(item)

    def get_all(self) -> List[T]:
        """Get all items."""
        return self._items.copy()

    def __len__(self) -> int:
        return len(self._items)

    def __iter__(self):
        return iter(self._items)

# Decorator functions
def timing_decorator(func: Callable) -> Callable:
    """Decorator to measure function execution time."""
    @wraps(func)
    def wrapper(*args, **kwargs):
        start_time = dt.datetime.now()
        result = func(*args, **kwargs)
        end_time = dt.datetime.now()
        duration = end_time - start_time
        print(f"{func.__name__} took {duration.total_seconds():.4f} seconds")
        return result
    return wrapper

def retry(max_attempts: int = 3):
    """Decorator with parameters for retry logic."""
    def decorator(func: Callable) -> Callable:
        @wraps(func)
        def wrapper(*args, **kwargs):
            for attempt in range(max_attempts):
                try:
                    return func(*args, **kwargs)
                except Exception as e:
                    if attempt == max_attempts - 1:
                        raise
                    print(f"Attempt {attempt + 1} failed: {e}")
            return None
        return wrapper
    return decorator

# Context manager
@contextmanager
def temporary_value(obj, attr: str, temp_value):
    """Context manager to temporarily change an attribute."""
    original_value = getattr(obj, attr)
    setattr(obj, attr, temp_value)
    try:
        yield obj
    finally:
        setattr(obj, attr, original_value)

# Regular functions
def fibonacci(n: int) -> int:
    """Calculate fibonacci number recursively."""
    if n <= 1:
        return n
    return fibonacci(n - 1) + fibonacci(n - 2)

@lru_cache(maxsize=128)
def fibonacci_cached(n: int) -> int:
    """Cached fibonacci calculation."""
    if n <= 1:
        return n
    return fibonacci_cached(n - 1) + fibonacci_cached(n - 2)

def find_max(*args: Union[int, float]) -> Union[int, float]:
    """Find maximum value from variable arguments."""
    if not args:
        raise ValueError("At least one argument required")
    return max(args)

def process_data(data: List[Dict[str, Any]],
                filter_func: Optional[Callable[[Dict], bool]] = None) -> List[Dict[str, Any]]:
    """Process data with optional filtering."""
    if filter_func is None:
        filter_func = lambda x: True

    return [item for item in data if filter_func(item)]

# Async functions
async def fetch_data(url: str, timeout: float = 5.0) -> Dict[str, Any]:
    """Simulate async data fetching."""
    await asyncio.sleep(0.1)  # Simulate network delay
    return {"url": url, "data": "sample data", "timestamp": dt.datetime.now().isoformat()}

async def gather_data(urls: List[str]) -> List[Dict[str, Any]]:
    """Gather data from multiple URLs concurrently."""
    tasks = [fetch_data(url) for url in urls]
    return await asyncio.gather(*tasks)

# Generator functions
def number_generator(start: int, end: int, step: int = 1):
    """Generate numbers in range."""
    current = start
    while current < end:
        yield current
        current += step

def fibonacci_generator():
    """Generate fibonacci sequence."""
    a, b = 0, 1
    while True:
        yield a
        a, b = b, a + b

# Main function with comprehensive examples
def main():
    """Main function demonstrating various Python features."""
    # Basic types and variables
    integer_var = 42
    float_var = 3.14159
    boolean_var = True
    string_var = "Hello, World!"
    bytes_var = b"Hello bytes"
    none_var = None

    # Raw strings and f-strings
    raw_string = r"Raw string with \n no escaping"
    f_string = f"F-string with variable: {integer_var}"
    multiline_string = """
    This is a multiline string
    with multiple lines
    """

    # Collections
    list_var = [1, 2, 3, 4, 5]
    tuple_var = (1, 2, 3)
    dict_var = {"key1": "value1", "key2": "value2"}
    set_var = {1, 2, 3, 4, 5}

    # List comprehensions
    squares = [x**2 for x in range(10)]
    even_squares = [x**2 for x in range(10) if x % 2 == 0]

    # Dictionary comprehensions
    square_dict = {x: x**2 for x in range(5)}
    filtered_dict = {k: v for k, v in dict_var.items() if "1" in k}

    # Set comprehensions
    even_set = {x for x in range(10) if x % 2 == 0}

    # Generator expressions
    sum_of_squares = sum(x**2 for x in range(100))

    # Control flow structures
    for i in range(10):
        if i % 2 == 0:
            print(f"Even number: {i}")
        elif i % 3 == 0:
            print(f"Divisible by 3: {i}")
        else:
            print(f"Odd number: {i}")

    # While loop
    count = 0
    while count < 5:
        print(f"Count: {count}")
        count += 1

    # Match-case statement (Python 3.10+)
    def process_value(value):
        match value:
            case int() if value > 0:
                return f"Positive integer: {value}"
            case int() if value < 0:
                return f"Negative integer: {value}"
            case 0:
                return "Zero"
            case str() if len(value) > 10:
                return f"Long string: {value[:10]}..."
            case str():
                return f"Short string: {value}"
            case list() | tuple():
                return f"Sequence with {len(value)} elements"
            case _:
                return f"Unknown type: {type(value)}"

    # Exception handling
    try:
        result = 10 / 0
    except ZeroDivisionError as e:
        print(f"Division by zero error: {e}")
    except ValueError as e:
        print(f"Value error: {e}")
    except Exception as e:
        print(f"Unexpected error: {e}")
    else:
        print("No exception occurred")
    finally:
        print("This always executes")

    # Context managers
    with open(__file__, 'r') as file:
        content = file.read(100)  # Read first 100 characters

    # Class instantiation and usage
    person = Person("Alice", 30, email="alice@example.com")
    person.tags.extend(["developer", "python"])

    employee = Employee("Bob", 28, "EMP001", "Engineering", 75000.0)
    employee.salary = 80000.0  # Using property setter

    print(person.greet())
    print(employee.get_full_info())
    print(f"Is adult: {person.is_adult()}")
    print(f"Email valid: {Person.validate_email('test@example.com')}")

    # Container usage
    int_container: Container[int] = Container()
    int_container.add(1)
    int_container.add(2)
    int_container.add(3)

    # Iterator usage
    for item in int_container:
        print(f"Container item: {item}")

    # Lambda functions
    square = lambda x: x**2
    add = lambda a, b: a + b

    # Higher-order functions
    numbers = [1, 2, 3, 4, 5]
    squared_numbers = list(map(square, numbers))
    even_numbers = list(filter(lambda x: x % 2 == 0, numbers))

    # Reduce example
    from functools import reduce
    product = reduce(lambda a, b: a * b, numbers, 1)

    # Decorators usage
    @timing_decorator
    @retry(max_attempts=3)
    def risky_function():
        """Function that might fail."""
        import random
        if random.random() < 0.7:
            raise RuntimeError("Random failure")
        return "Success!"

    try:
        result = risky_function()
        print(f"Function result: {result}")
    except Exception as e:
        print(f"Function failed: {e}")

    # Generator usage
    fib_gen = fibonacci_generator()
    first_10_fibs = [next(fib_gen) for _ in range(10)]
    print(f"First 10 Fibonacci numbers: {first_10_fibs}")

    # Named tuple
    Point = namedtuple('Point', ['x', 'y'])
    point = Point(10, 20)
    print(f"Point: x={point.x}, y={point.y}")

    # Default dict
    word_count = defaultdict(int)
    text = "hello world hello python"
    for word in text.split():
        word_count[word] += 1

    # Enum usage
    current_status = Status.ACTIVE
    priority = Priority.HIGH

    print(f"Status: {current_status.value}")
    print(f"Priority: {priority.name} ({priority.value})")

    # Regular expressions
    pattern = r'\b\w+@\w+\.\w+\b'
    text = "Contact us at support@example.com or sales@company.org"
    emails = re.findall(pattern, text)
    print(f"Found emails: {emails}")

    # JSON operations
    data = {"name": "John", "age": 30, "city": "New York"}
    json_string = json.dumps(data, indent=2)
    parsed_data = json.loads(json_string)

    # Path operations
    current_file = Path(__file__)
    print(f"Current file: {current_file.name}")
    print(f"Parent directory: {current_file.parent}")

    # String operations
    text = "  Hello, World!  "
    print(f"Original: '{text}'")
    print(f"Stripped: '{text.strip()}'")
    print(f"Upper: '{text.upper()}'")
    print(f"Split: {text.split(',')}")
    print(f"Replace: '{text.replace('World', 'Python')}'")

    # Type checking
    def check_type(value: Any) -> str:
        if isinstance(value, int):
            return "integer"
        elif isinstance(value, str):
            return "string"
        elif isinstance(value, (list, tuple)):
            return "sequence"
        else:
            return "other"

    # Multiple assignment
    a, b, c = 1, 2, 3
    x, *middle, z = [1, 2, 3, 4, 5]

    # Dictionary unpacking
    defaults = {"timeout": 30, "retries": 3}
    config = {"url": "example.com", **defaults, "debug": True}

    # Set operations
    set1 = {1, 2, 3, 4}
    set2 = {3, 4, 5, 6}
    union = set1 | set2
    intersection = set1 & set2
    difference = set1 - set2

    print(f"Set union: {union}")
    print(f"Set intersection: {intersection}")
    print(f"Set difference: {difference}")

    # Walrus operator (Python 3.8+)
    data_list = [1, 2, 3, 4, 5]
    if (n := len(data_list)) > 3:
        print(f"List has {n} elements, which is more than 3")

    # Type hints with Union and Optional
    def process_input(value: Union[str, int, None]) -> Optional[str]:
        if value is None:
            return None
        return str(value).upper()

    # Async example (would need asyncio.run() to execute)
    async def async_example():
        urls = ["url1", "url2", "url3"]
        results = await gather_data(urls)
        return results

    print("Main function execution completed!")

# Module-level code
if __name__ == "__main__":
    # This runs when the script is executed directly
    print("Starting Python syntax test...")
    main()
    print("Python syntax test completed!")

# Global variables with type hints
global_counter: int = 0
global_data: Dict[str, Any] = {}

# Module constants
__version__ = "1.0.0"
__author__ = "Python Developer"
__all__ = ["Person", "Employee", "Container", "main"]
