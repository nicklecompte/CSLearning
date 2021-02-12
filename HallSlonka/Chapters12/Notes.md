# Hall/Slonka - Chapters 1 and 2

Bundling these chapters together since they're pretty lightweight.

## Data representation

| Number System | Base | Digits             |
| :------------ | :--- | :----------------- |
| Binary        | 2    | 0 1                |
| Octal         | 8    | 0 1 2 3 4 5 6 7    |
| Decimal       | 10   | 0 .. 9             |
| Hexadecimal   | 16   | 0 .. 9 A B C D E F |

## Integer storage sizes [I still get confused sometimes since I don't have a lot of C experience]

|  Bits  |  Bytes  |  Term / C term              |  Unsigned rng  |  Signed rng      |
| :----- | :------ | :-------------------------- | :------------: | :--------------- |
| 8      | 1       | byte / byte                 | 0 - 2^8 - 1    | -2^7 - 2^7 - 1   |
| 16     | 2       | word / short int            | 0 - 2^16 - 1   | -2^15 - 2^15 - 1 |
| 32     | 4       | doubleword / int            | 0 - 2^32 - 1   | -2^31 - 2^31 - 1 |
| 64     | 8       | quadword / long             | 0 - 2^64 - 1   | -2^63 - 2^63 - 1 |
| 80     | 10      | tenbyte / NA                | 0 - 2^80 - 1   | -2^79 - 2^79 - 1 |
| 128    | 16      | double quadword / long long | 0 - 2^128 - 1  | -2^127-2^127 - 1 |

## Signed integer storage

There are many ways to sign integers in a system. In the three methods discussed, the most significant bit is used to indicate positive (0) or negative (1). We have

- Sign notation, where the MSB indicates sign but the numbers are otherwise identical
- Ones' complement, where the bits are all flipped
- Twos' complement, where the bits are all flipped, and then one is added to the result

Sign notation and ones' complement both have the "negative zero" problem: in 8 bits signed integers, the bytes 10000000 and 00000000 are both zero, but the first is negative. Ones' complement also has the oddity that the sum of a number with its negative is actually -1, not zero. Although this and the negaive zero problem can be avoided with careful programming, twos' complement avoids these problems architecturally.

Since I am not totally experienced in this arithmetic we will go through some exercises for converting decimal/binary/hex numbers to/from their twos complement negative:

23 in base 10 -> 00010111 in binary
11101000 is 23 with the bits flipped
11101001 is 23 flipped, adding 1 -> this is -23

00010111 is 17 in hex
11101000 is E0 in hex

6839 in base 10 -> 1AB7 in hex.
To take the twos complement of the hex, take F - each hex digit and add 1
F - 1 = E
F - A = 5
F - B = 4
F - 7 = 8
Then add one, so -6839 in base 10 -> E549 in hex


## Processor and system architectures
