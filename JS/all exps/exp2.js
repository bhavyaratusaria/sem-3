let alpha = ['A', 'B', 'C'];

alpha.push('D');
console.log(alpha);

let lastAlpha = alpha.pop();
console.log(lastAlpha);

alpha.unshift('N');
console.log(alpha);

let firstAlpha = alpha.shift();
console.log(firstAlpha);

alpha.splice(1, 1, 'Bee');
console.log(alpha);

let numbers = [10, 20, 30, 40, 20];
console.log(numbers.indexOf(20));

console.log(numbers.includes(30));

let subArray = numbers.slice(1, 4);
console.log(subArray);
console.log(numbers);