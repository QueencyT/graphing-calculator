# Graphing Calculator

<img width="1745" height="1223" alt="Image" src="https://github.com/user-attachments/assets/df167d8b-8230-4fe8-ad36-01f2c54552fb" />

An interactive graphing calculator built from scratch in C++ using SFML, featuring custom mathematical expression parsing and evaluation with the Shunting Yard algorithm and Reverse Polish Notation (RPN), interactive graph navigation, and persistent equation history.

## Features

- **Interactive Graphing:** Visualizes mathematical functions on a Cartesian coordinate system using SFML.
- **Mathematical Expression Evaluation:** Parses and evaluates expressions using a custom token-based expression engine.
- **Zooming and Panning:** Supports keyboard-controlled zooming and horizontal navigation.
- **Equation History:** Saves previously entered equations and allows users to select and revisit past graphs.
- **Custom Data Structures:** Implements dynamic vectors, linked lists, stacks, and queues from scratch.
- **Graphical User Interface:** Features an equation input field, interactive buttons, graph history sidebar, and help controls.

## Technologies Used

- **Programming Language:** C++
- **Graphics Library:** SFML
- **Testing Framework:** Google Test
- **Core Concepts:** Object-Oriented Programming, Data Structures, Expression Parsing, Stack-Based Evaluation, Coordinate Transformation

## How It Works

The calculator processes mathematical expressions through four main stages:

### 1. Tokenization

User-entered expressions are parsed into tokens representing numbers, variables, mathematical operators, parentheses, and functions.

For example:

```text
Expression: x^2+3*x
Tokens:     [x] [^] [2] [+] [3] [*] [x]
```

### 2. Shunting Yard Algorithm

The **Shunting Yard algorithm** converts infix mathematical expressions into postfix notation using an operator stack and precedence rules.

```text
Infix:   x^2+3*x
Postfix: x 2 ^ 3 x * +
```

### 3. Reverse Polish Notation (RPN)

The postfix expression is evaluated using a custom stack.

For each value of `x`, the evaluator processes the mathematical operations and calculates the corresponding `y` coordinate.

For example:

```text
Expression: x^2 + 3*x
x = 2
y = 2^2 + 3(2) = 10
```

### 4. Graph Rendering

The calculator evaluates mathematical expressions across a specified domain to generate coordinate points.

These points are converted into screen coordinates using:

```cpp
screenX = originX + x * scale;
screenY = originY - y * scale;
```

SFML renders the resulting points on a Cartesian coordinate system. Graph coordinates are recalculated when users submit equations, zoom, or pan.

## Mathematical Operations

The expression engine implements the following mathematical operations:

| Category | Operations |
|---|---|
| Arithmetic | `+`, `-`, `*`, `/` |
| Exponentiation | `^` |
| Trigonometry | `sin`, `cos`, `tan` |
| Reciprocal Trigonometry | `csc`, `sec`, `cot` |
| Logarithms | `log` |
| Variables | `x` |
| Grouping | Parentheses |

## Controls

| Input | Action |
|---|---|
| Up Arrow | Zoom in |
| Down Arrow | Zoom out |
| Left Arrow | Pan left |
| Right Arrow | Pan right |
| Enter | Submit equation |
| Backspace | Delete character |
| Escape | Close application |
| Mouse | Select equation input and graph history entries |

## Project Architecture

The application follows a modular, object-oriented architecture that separates mathematical expression processing, graph computation, visualization, and user interaction.

| Component | Responsibility |
|---|---|
| `User_Input` | Converts mathematical expressions into tokens |
| `ShuntingYard` | Converts infix expressions into postfix notation |
| `RPN` | Evaluates postfix expressions using stack-based computation |
| `Plot` | Generates mathematical coordinate points |
| `Coordinate_Translator` | Transforms Cartesian coordinates into screen coordinates |
| `Graph` | Renders coordinate axes, tick marks, labels, and plotted points |
| `System` | Manages graph updates, zooming, and panning |
| `Graph_History` | Stores and retrieves previously entered equations |
| `animate` | Handles SFML window creation, events, updates, and rendering |
| `Vector`, `Stack`, `Queue` | Custom data structures supporting the application |

## Custom Data Structures

The project includes custom implementations of fundamental data structures rather than relying exclusively on the C++ Standard Template Library.

### Dynamic Vector

- Dynamic memory allocation and resizing
- Element insertion and deletion
- Copy constructors and assignment operators
- Index-based element access

### Linked List

- Node insertion and deletion
- Traversal and searching
- Deep copying and memory cleanup

### Stack and Queue

- Linked-list-based implementations
- Push and pop operations
- Iterator support
- Used in the Shunting Yard algorithm and RPN evaluation

## Testing

The project includes Google Test files for plotting, coordinate translation, and SFML application initialization.

## Technical Highlights

- **Algorithm Design:** Implements the Shunting Yard algorithm for converting mathematical expressions into postfix notation.
- **Expression Evaluation:** Uses Reverse Polish Notation and stack-based computation to evaluate mathematical functions.
- **Custom Data Structures:** Implements fundamental containers and linked-list operations using C++ templates and dynamic memory management.
- **Object-Oriented Design:** Separates mathematical processing, graph visualization, and user interaction into reusable components.
- **Computer Graphics:** Uses SFML to implement graphical rendering, coordinate transformations, and event-driven interaction.
- **File I/O:** Uses file-based storage to preserve equation history between application sessions.

## Project Information

**Language:** C++  
**Graphics Library:** SFML  
**Data Structures:** Dynamic Arrays, Vectors, Linked Lists, Stacks, Queues  
**Algorithms:** Shunting Yard Algorithm, Reverse Polish Notation (RPN)  
**Testing:** Google Test  
**Core Concepts:** Mathematical Expression Parsing, Operator Precedence, Stack-Based Evaluation, Object-Oriented Programming, Templates, Dynamic Memory Management, Coordinate Transformation, and Event-Driven Programming

**Developer:** Queency Tan
