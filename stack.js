class ExpressionStack {
  constructor() {
    this.data = [];
  }

  push(data) {
    this.data.push(data);
  }

  pop() {
    return this.data.pop();
  }

  display() {
    console.log("Hey " + this.data);
  }

  isOperator(operator) {
    if (
      operator === "+" ||
      operator === "-" ||
      operator === "*" ||
      operator === "/"
    )
      return true;
    return false;
  }

  performOperation(operator, operand1, operand2) {
    switch (operator) {
      case "+":
        return operand1 + operand2;
      case "-":
        return operand1 - operand2;
      case "*":
        return operand1 * operand2;
      case "/":
        return operand1 / operand2;
    }
  }

  generateNumber(lower, upper) {
    return (Math.floor(Math.random() * 10) % (upper - lower + 1)) + lower;
  }

  isEmpty() {
    return this.data.length === 0;
  }

  evaluateExpression(expression) {
    let value = 0,
      operand1,
      operand2;
    for (let i = 0; i < expression.length; i++) {
      if (this.isOperator(expression[i])) {
        if (!this.isEmpty()) {
          operand1 = this.pop();
        } else {
          console.log("Invalid expression");
        }
        if (!this.isEmpty()) {
          operand2 = this.pop();
        } else {
          console.log("Invalid expression");
        }
        this.push(this.performOperation(expression[i], operand1, operand2));
      } else {
        if (expression[i] === "a") value = a;
        else if (expression[i] === "b") value = b;
        else if (expression[i] === "c") value = c;
        else if (expression[i] === "d") value = d;
        this.push(value);
      }
    }
  }
}

let stack = new ExpressionStack();

let a = stack.generateNumber(0, 6);
let b = stack.generateNumber(a + 1, 7);
let c = stack.generateNumber(b + 1, 8);
let d = stack.generateNumber(c + 1, 9);

console.log(`a==> ${a} b==> ${b} c==> ${c} d==> ${d}`);

stack.evaluateExpression("abc+-");

stack.display();
