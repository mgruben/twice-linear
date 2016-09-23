# twice-linear
Find the nth term of a set, beginning with 1, which increases in two linear directions.

Specifically, for every entry in the set, (2*entry + 1) and (3*entry + 1) must also be in the set.

For example:
```
(1) -> (1, 3, 4)
(1, 3, 4) -> (1, 3, 4, 7, 9, 10, 13)
(1, 3, 4, 7, 9, 10, 13) -> (1, 3, 4, 7, 9, 10, 13, 15, 19, 21, 22, ...)

22 is the 10th term of the set
57 is the 20th term of the set
91 is the 30th term of the set
175 is the 50th term of the set
```
This implementation uses priority queues to maintain a tally of invariants.

This project was completed for [CodeWars - Integers: Twice Linear](https://www.codewars.com/kata/twice-linear/).

I recommend that this code should only be viewed _after_ you've completed your own implementation.  
If you're super stuck, take a break, take a walk, and it will come to you; good luck.
