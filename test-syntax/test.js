// Single line comment
/* Multi-line comment
   with multiple lines */

/**
 * JSDoc documentation comment
 * @param {string} name - The person's name
 * @param {number} age - The person's age
 * @returns {Person} A new Person instance
 */

// Import statements (ES6 modules)
import { EventEmitter } from 'events';
import fs from 'fs/promises';
import path from 'path';
import { promisify } from 'util';

// Export statements
export { Person, Employee };
export default class Application {};

// Constants
const API_URL = 'https://api.example.com';
const MAX_RETRIES = 3;
const PI = 3.14159;

// Let and var declarations
let globalCounter = 0;
var legacyVariable = 'legacy';

// Regular expressions
const emailRegex = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;
const phoneRegex = /^\+?[\d\s\-\(\)]+$/g;

// Template literals and tagged templates
function highlight(strings, ...values) {
    return strings.reduce((result, string, i) => {
        return result + string + (values[i] ? `<mark>${values[i]}</mark>` : '');
    }, '');
}

// Symbol and BigInt
const uniqueSymbol = Symbol('unique');
const bigNumber = 123456789012345678901234567890n;

// Class definitions
class Person {
    // Private fields (ES2022)
    #privateField = 'secret';

    // Public fields
    static instanceCount = 0;

    constructor(name, age, email = null) {
        this.name = name;
        this.age = age;
        this.email = email;
        this.id = ++Person.instanceCount;
        this.createdAt = new Date();
    }

    // Getter
    get fullInfo() {
        return `${this.name} (${this.age} years old)`;
    }

    // Setter
    set age(value) {
        if (value < 0) {
            throw new Error('Age cannot be negative');
        }
        this._age = value;
    }

    get age() {
        return this._age;
    }

    // Methods
    greet() {
        return `Hello, my name is ${this.name}`;
    }

    // Async method
    async fetchAdditionalInfo() {
        try {
            const response = await fetch(`${API_URL}/users/${this.id}`);
            const data = await response.json();
            return data;
        } catch (error) {
            console.error('Failed to fetch user info:', error);
            throw error;
        }
    }

    // Static method
    static createFromString(personString) {
        const [name, age] = personString.split(',');
        return new Person(name.trim(), parseInt(age.trim()));
    }

    // Private method
    #validateEmail(email) {
        return emailRegex.test(email);
    }

    // Generator method
    *getTags() {
        yield 'person';
        yield 'user';
        yield `age-${this.age}`;
    }
}

// Inheritance
class Employee extends Person {
    constructor(name, age, employeeId, department, salary) {
        super(name, age);
        this.employeeId = employeeId;
        this.department = department;
        this.salary = salary;
        this.benefits = new Set(['health', 'dental']);
    }

    // Method override
    greet() {
        return `${super.greet()}, I work in ${this.department}`;
    }

    // Method with default parameters
    giveRaise(percentage = 5) {
        this.salary *= (1 + percentage / 100);
        return this.salary;
    }

    // Rest parameters
    addBenefits(...newBenefits) {
        newBenefits.forEach(benefit => this.benefits.add(benefit));
    }
}

// Function declarations
function regularFunction(param1, param2) {
    return param1 + param2;
}

// Function expression
const functionExpression = function(x, y) {
    return x * y;
};

// Arrow functions
const arrowFunction = (x, y) => x + y;
const singleParamArrow = x => x * 2;
const multiLineArrow = (a, b) => {
    const sum = a + b;
    return sum * 2;
};

// Immediately Invoked Function Expression (IIFE)
(function() {
    console.log('IIFE executed');
})();

// Higher-order functions
function createMultiplier(factor) {
    return function(number) {
        return number * factor;
    };
}

const double = createMultiplier(2);
const triple = createMultiplier(3);

// Async functions
async function fetchUserData(userId) {
    try {
        const response = await fetch(`${API_URL}/users/${userId}`);

        if (!response.ok) {
            throw new Error(`HTTP error! status: ${response.status}`);
        }

        const userData = await response.json();
        return userData;
    } catch (error) {
        console.error('Error fetching user data:', error);
        throw error;
    }
}

// Generator functions
function* numberGenerator(start, end) {
    for (let i = start; i <= end; i++) {
        yield i;
    }
}

function* fibonacciGenerator() {
    let a = 0, b = 1;
    while (true) {
        yield a;
        [a, b] = [b, a + b];
    }
}

// Promises
function createPromise(shouldResolve = true) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            if (shouldResolve) {
                resolve('Promise resolved successfully');
            } else {
                reject(new Error('Promise rejected'));
            }
        }, 1000);
    });
}

// Promise chaining
createPromise()
    .then(result => {
        console.log('Success:', result);
        return 'Modified result';
    })
    .then(modifiedResult => {
        console.log('Modified:', modifiedResult);
    })
    .catch(error => {
        console.error('Error:', error);
    })
    .finally(() => {
        console.log('Promise chain completed');
    });

// Async/await with Promise.all
async function fetchMultipleUsers(userIds) {
    try {
        const promises = userIds.map(id => fetchUserData(id));
        const users = await Promise.all(promises);
        return users;
    } catch (error) {
        console.error('Error fetching multiple users:', error);
        throw error;
    }
}

// Object literals and methods
const calculator = {
    // Property
    name: 'Advanced Calculator',

    // Method shorthand
    add(a, b) {
        return a + b;
    },

    // Computed property names
    [Symbol.toStringTag]: 'Calculator',

    // Getter
    get version() {
        return '1.0.0';
    },

    // Setter
    set precision(value) {
        this._precision = Math.max(0, Math.min(10, value));
    }
};

// Destructuring
const person = { name: 'Alice', age: 30, city: 'New York' };
const { name, age, city = 'Unknown' } = person;
const { name: personName, ...otherProps } = person;

// Array destructuring
const colors = ['red', 'green', 'blue', 'yellow'];
const [primary, secondary, ...otherColors] = colors;
const [, , third] = colors; // Skip first two elements

// Nested destructuring
const user = {
    id: 1,
    profile: {
        name: 'John',
        contacts: {
            email: 'john@example.com',
            phone: '123-456-7890'
        }
    }
};

const {
    profile: {
        name: userName,
        contacts: { email, phone }
    }
} = user;

// Spread operator
const numbers = [1, 2, 3];
const moreNumbers = [...numbers, 4, 5, 6];
const evenMoreNumbers = [0, ...numbers, ...moreNumbers];

// Object spread
const baseConfig = { timeout: 5000, retries: 3 };
const config = { ...baseConfig, debug: true, timeout: 10000 };

// Maps and Sets
const userMap = new Map();
userMap.set('user1', { name: 'Alice', role: 'admin' });
userMap.set('user2', { name: 'Bob', role: 'user' });

const uniqueItems = new Set([1, 2, 3, 3, 4, 4, 5]);

// WeakMap and WeakSet
const weakMap = new WeakMap();
const weakSet = new WeakSet();

// Proxy
const target = { name: 'Original' };
const proxy = new Proxy(target, {
    get(obj, prop) {
        console.log(`Getting ${prop}`);
        return obj[prop];
    },
    set(obj, prop, value) {
        console.log(`Setting ${prop} to ${value}`);
        obj[prop] = value;
        return true;
    }
});

// Symbols
const METHOD_NAME = Symbol('methodName');
const PRIVATE_PROPERTY = Symbol.for('private');

// Main function with comprehensive examples
function main() {
    // Basic data types
    const stringVar = "Hello, World!";
    const numberVar = 42;
    const booleanVar = true;
    const nullVar = null;
    const undefinedVar = undefined;

    // Template literals
    const greeting = `Hello, ${name}! You are ${age} years old.`;
    const multilineString = `
        This is a multiline
        template literal
        with ${greeting}
    `;

    // Tagged template
    const highlighted = highlight`Welcome ${name}, you have ${5} new messages!`;

    // Arrays
    const fruits = ['apple', 'banana', 'orange'];
    const mixedArray = [1, 'string', true, null, { key: 'value' }];

    // Array methods
    const doubled = numbers.map(x => x * 2);
    const evens = numbers.filter(x => x % 2 === 0);
    const sum = numbers.reduce((acc, curr) => acc + curr, 0);

    // Array iteration
    fruits.forEach((fruit, index) => {
        console.log(`${index}: ${fruit}`);
    });

    // for...of loop
    for (const fruit of fruits) {
        console.log(`Fruit: ${fruit}`);
    }

    // for...in loop
    for (const key in person) {
        console.log(`${key}: ${person[key]}`);
    }

    // Control structures
    for (let i = 0; i < 10; i++) {
        if (i % 2 === 0) {
            console.log(`Even number: ${i}`);
        } else if (i % 3 === 0) {
            console.log(`Divisible by 3: ${i}`);
        } else {
            console.log(`Odd number: ${i}`);
        }
    }

    // Switch statement
    const day = new Date().getDay();
    switch (day) {
        case 0:
        case 6:
            console.log("It's weekend!");
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            console.log("It's a weekday");
            break;
        default:
            console.log("Invalid day");
    }

    // Try-catch-finally
    try {
        const result = JSON.parse('{"name": "John"}');
        console.log('Parsed JSON:', result);

        // Throwing custom error
        if (!result.age) {
            throw new Error('Age property is missing');
        }
    } catch (error) {
        if (error instanceof SyntaxError) {
            console.error('JSON syntax error:', error.message);
        } else if (error instanceof Error) {
            console.error('Custom error:', error.message);
        } else {
            console.error('Unknown error:', error);
        }
    } finally {
        console.log('JSON parsing attempt completed');
    }

    // Object creation and manipulation
    const employee = new Employee('Alice', 30, 'EMP001', 'Engineering', 75000);
    console.log(employee.greet());

    employee.addBenefits('vision', '401k', 'stock options');
    console.log('Benefits:', Array.from(employee.benefits));

    // Object property access
    console.log('Department:', employee['department']);
    console.log('Dynamic property:', employee[METHOD_NAME]);

    // this binding
    const boundMethod = employee.greet.bind(employee);
    const arrowMethod = () => employee.greet();

    // Call and apply
    const greeting1 = employee.greet.call(employee);
    const greeting2 = employee.greet.apply(employee, []);

    // Object.keys, Object.values, Object.entries
    const keys = Object.keys(employee);
    const values = Object.values(employee);
    const entries = Object.entries(employee);

    // JSON operations
    const jsonString = JSON.stringify(employee, null, 2);
    const parsedEmployee = JSON.parse(jsonString);

    // Regular expressions
    const text = "Contact us at support@example.com or call 1-800-123-4567";
    const emails = text.match(emailRegex);
    const phones = text.match(phoneRegex);

    // String methods
    const message = "  Hello, JavaScript World!  ";
    console.log('Original:', `"${message}"`);
    console.log('Trimmed:', `"${message.trim()}"`);
    console.log('Uppercase:', message.toUpperCase());
    console.log('Substring:', message.substring(2, 7));
    console.log('Split:', message.split(','));
    console.log('Replace:', message.replace('JavaScript', 'JS'));
    console.log('Includes:', message.includes('JavaScript'));

    // Number methods
    const num = 123.456789;
    console.log('Fixed:', num.toFixed(2));
    console.log('Precision:', num.toPrecision(5));
    console.log('Exponential:', num.toExponential(2));
    console.log('Is integer:', Number.isInteger(num));
    console.log('Is finite:', Number.isFinite(num));

    // Math operations
    console.log('Random:', Math.random());
    console.log('Floor:', Math.floor(num));
    console.log('Ceiling:', Math.ceil(num));
    console.log('Round:', Math.round(num));
    console.log('Max:', Math.max(1, 5, 3, 9, 2));
    console.log('Min:', Math.min(1, 5, 3, 9, 2));

    // Date operations
    const now = new Date();
    const specificDate = new Date('2023-12-25');
    const timestamp = Date.now();

    console.log('Current date:', now.toISOString());
    console.log('Formatted date:', now.toLocaleDateString());
    console.log('Formatted time:', now.toLocaleTimeString());

    // Generator usage
    const gen = numberGenerator(1, 5);
    for (const num of gen) {
        console.log('Generated number:', num);
    }

    // Fibonacci generator
    const fibGen = fibonacciGenerator();
    const firstTenFibs = Array.from({ length: 10 }, () => fibGen.next().value);
    console.log('First 10 Fibonacci numbers:', firstTenFibs);

    // Map operations
    userMap.set('user3', { name: 'Charlie', role: 'moderator' });
    console.log('User map size:', userMap.size);

    for (const [key, value] of userMap) {
        console.log(`${key}:`, value);
    }

    // Set operations
    console.log('Unique items:', Array.from(uniqueItems));
    uniqueItems.add(6);
    console.log('Has 3:', uniqueItems.has(3));
    uniqueItems.delete(1);

    // Closure example
    function createCounter() {
        let count = 0;
        return {
            increment: () => ++count,
            decrement: () => --count,
            get value() { return count; }
        };
    }

    const counter = createCounter();
    console.log('Counter:', counter.increment(), counter.increment(), counter.value);

    // Module pattern
    const module = (function() {
        let privateVar = 'I am private';

        return {
            publicMethod() {
                return `Public method accessing: ${privateVar}`;
            },

            setPrivateVar(value) {
                privateVar = value;
            }
        };
    })();

    console.log(module.publicMethod());

    // Event simulation (browser environment)
    if (typeof document !== 'undefined') {
        document.addEventListener('DOMContentLoaded', () => {
            console.log('DOM is ready');
        });

        // Event delegation
        document.addEventListener('click', (event) => {
            if (event.target.matches('.button')) {
                console.log('Button clicked:', event.target.textContent);
            }
        });
    }

    // Optional chaining (ES2020)
    const optionalResult = user?.profile?.contacts?.email;
    console.log('Optional chaining result:', optionalResult);

    // Nullish coalescing (ES2020)
    const defaultValue = null ?? undefined ?? 0 ?? 'default';
    console.log('Nullish coalescing result:', defaultValue);

    // Dynamic imports (would work in module environment)
    // import('./dynamic-module.js').then(module => {
    //     module.default();
    // });

    console.log('Main function execution completed!');
}

// Async main wrapper
async function asyncMain() {
    try {
        console.log('Starting async operations...');

        // Parallel async operations
        const results = await Promise.allSettled([
            fetchUserData(1),
            fetchUserData(2),
            createPromise(true)
        ]);

        results.forEach((result, index) => {
            if (result.status === 'fulfilled') {
                console.log(`Result ${index}:`, result.value);
            } else {
                console.error(`Error ${index}:`, result.reason);
            }
        });

        // Sequential async operations
        const userData = await fetchUserData(1);
        const additionalInfo = await fetchMultipleUsers([1, 2, 3]);

        console.log('Async operations completed');
    } catch (error) {
        console.error('Async error:', error);
    }
}

// Error classes
class CustomError extends Error {
    constructor(message, code) {
        super(message);
        this.name = 'CustomError';
        this.code = code;
    }
}

class ValidationError extends CustomError {
    constructor(field, value) {
        super(`Validation failed for field: ${field} with value: ${value}`, 'VALIDATION_ERROR');
        this.field = field;
        this.value = value;
    }
}

// Entry point
if (typeof window !== 'undefined') {
    // Browser environment
    window.addEventListener('load', () => {
        console.log('Page loaded, running main function...');
        main();
        asyncMain();
    });
} else {
    // Node.js environment
    console.log('Running in Node.js environment...');
    main();
    asyncMain();
}

// Export for module systems
export { main, asyncMain, Person, Employee, calculator };

// Default export
export default {
    main,
    asyncMain,
    version: '1.0.0'
};
