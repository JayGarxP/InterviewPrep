Pattern Matching: Find all indices of substring, Geeks for Geeks
http://www.geeksforgeeks.org/searching-for-patterns-set-1-naive-pattern-searching/

Brute Force:
Start at index 0, when find the first char of substring, start new loop and compare each char for equal - if entire substring worked then print the starting index, then back up to the index where you started the new loop +1 and repeat until you hit the end of the string or NULL.

Possible to use  KMP (Knuth-Morris-Pratt) Algorithm ?
And not waste the information gathered from the inner loops?

Missing a better exit condition?


verschlimmbessern
Making something worse with an honest attempt to fix/improve it
