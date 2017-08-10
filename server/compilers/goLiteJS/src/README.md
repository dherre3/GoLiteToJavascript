# Left to do implementation:
- Scanner raw strings
- Adding code to transform escape sequences in rune to single character ones.
- Deleting code from pretty printer inside code file that might not be good anymore such as the type stuff.
# Completed
- blank ids
- slice append issue
- binary increment/decrement
- Need to check rune exp in print statements
- Checking array bounds
- Binary Expressions
- Unary Expressions
- if statements
- for statements
- switch statements
- Predeclarations
- Variable declarations
- Initializations
- Block Statements
- Function declarations
- All assingment statements
- Short declarations
- Return statements
- Casting in javascript
- Passing structs and arrays by value using utility functions
- All expressions but binary and unary expressions.

# Testing
- NONE, however, I have been using test.go in the ./src/test folder. To check results see ./src/test.js.
NOTES: I took a rather lazy approach with assignments, declarations and short statements that involve an expression, although they work as expected, we could be writing less if we check the type of expression we have at hand, if you wanna make it more efficient, go for it. 
