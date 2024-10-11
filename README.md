# COMP 2710: Project 2

## Goals
- To learn “while” and “do-while” statements
- To learn how to define functions
- To write a test driver
- To learn how to use assert()
- To use random numbers

## Description
In the land of Puzzlevania, Aaron, Bob, and Charlie had an argument over which one of
them was the greatest puzzle-solver of all time. To end the argument once and for all,
they agreed on a duel to the death (this makes sense?). Aaron was a poor shooter and
only hit this target with a probability of 1/3. Bob was a bit better and hit his target with
a probability of 1/2. Charlie was an expert marksman and never missed. A hit means a
kill and the person hit drops out of the duel.

To compensate for the inequities in their marksmanship skills, the three decided that
they would fire in turns, starting with Aaron, followed by Bob, and then by Charlie. The
cycle would repeat until there was one man standing. That man would be remembered
for all time as the Greatest Puzzle-Solver of All Time.

### Strategy 1
An obvious and reasonable strategy is for each man to shoot at the most
accurate shooter still alive, on the grounds that this shooter is the deadliest and has the
best chance of hitting back.

Write a program to simulate the duel using this strategy. Your program should use
random numbers and the probabilities given in the problem to determine whether a
shooter hits his target. You will likely want to create multiple functions to complete the
problem. My solution had only one function to simulate the duels and it passed in the
odds and the three guys as pass-by-reference parameters. Once you can simulate a duel,
add a loop to your program that simulates 10,000 duels. Count the number of times that
each contestant wins and print the probability of winning for each contestant (e.g., for
Aaron your might output "Aaron won 3612/10000 duels or 36.12%).

### Strategy 2
An alternative strategy for Aaron is to intentionally miss on his first shot,
while the rest of duel is as same as that in **Strategy 1**. Write a function to simulate
Strategy 2. Your program will determine which strategy is better for Aaron.

### Note
**Probabilities** might be slightly different for different runs due to the random number, but strategy 2 should be always better than strategy 1.
