let greeting = "   Hello, World!   ";

console.log(greeting.toUpperCase());
console.log(greeting.toLowerCase());

let cleanedGreeting = greeting.trim();
console.log(cleanedGreeting);

let string = "The quick brown fox jumps over the lazy dog.";

console.log(string.includes("fox"));

console.log(string.startsWith("The"));
console.log(string.endsWith("cat."));

let animal = string.slice(16, 19);
console.log(animal);

console.log(string.charAt(4));