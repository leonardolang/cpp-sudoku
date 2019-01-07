# cpp-sudoku

This is a compile-time implementation of Sudoku where only correct Sudoku solutions are well-typed, relying only on features from C++ 98.

A Sudoku `table` can be declared using a series of nine `row` declarations as template parameters. See the end of the file for a few examples.

For fully evaluating the types (and therefore performing the validation), either type `t` from the table have to be `typedef`'ed or an object has to be instantiated.

## Why?

It was inspired by [this post](https://www.reddit.com/r/ProgrammerHumor/comments/acbv9r/sudoku_validity_is_a_total_function/) on **r/ProgrammerHumor**, titled "Sudoku validity is a Total function":

![Sudoku at compile time](https://i.redd.it/fllc6t7ioa821.png)
