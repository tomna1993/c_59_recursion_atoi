# c_59_recursion_atoi

## DESCRIPTION

### BACKGROUND

Image that you travel back in time to the 1970’s, when the C programming language was first created. You are hired as a programmer to come up with a way to convert `string`s to `int`s. (You may have used a function just like this, called atoi). You want to be thorough in your development process and plan to try several approaches before deciding on the most efficient.

In this problem, you will start with a simple implementation of `atoi` that handles positive `int`s using loops. You want to rework this into an implementation that uses recursion. Recusive functions can be memory intensive and are not always the best solution, but there are some problems in which using recursion can provide a simpler and more elegant solution.

### Implementation Details

In the recursive version of `convert`, start with the last `char` and convert it into an integer value. Then shorten the `string`, removing the last `char`, and then recursively call convert using the shortened `string` as input, where the next `char` will be processed.
