# Wordament Solver in C using Trie Data Structure

This repository contains a program written in C language that solves the popular Wordament puzzle game using the trie data structure to check words and the backtracking algorithm to find all possible words. The program takes in a grid of letters as input and outputs all possible words that can be formed from the letters.

## Table of Contents

- [Algorithm](#algorithm)
- [Contributing](#contributing)
- [License](#license)

## Algorithm

The algorithm used in this program is a combination of the trie data structure and the recursive backtracking algorithm. The program starts by building a trie data structure from a dictionary of valid words. The trie allows the program to efficiently check if a given string is a valid word.

The program then iterates over every cell in the grid and calls a recursive function that tries to form words starting from that cell. The function checks if the current cell is a valid starting point for a word (i.e., it hasn't been visited before), and if it is, it adds the letter in the cell to the current word and continues recursively to the neighboring cells.

At each step, the program checks if the current word is a prefix of any valid word in the trie. If it is not, the function backtracks and tries a different path. If it is a prefix of a valid word, the program continues recursively to the neighboring cells.

When the program reaches a cell that has no valid neighbors (i.e., all possible paths have been exhausted), it checks if the current word is a valid word in the trie. If it is, it adds the word to a list of found words. If the current word is not a valid word, the function backtracks and tries a different path.

Once the program has finished iterating over all possible starting cells, it outputs the list of found words.

## Contributing

If you'd like to contribute to this program, feel free to fork the repository and submit a pull request with your changes. 

## License

This program is licensed under the [MIT License](./LICENSE). Feel free to use, modify, and distribute the code as you see fit.
