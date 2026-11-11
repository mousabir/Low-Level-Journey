*This project has been created as part of the 1337 (42 Network) curriculum by mousabir.*

## Description

BSQ finds the **largest possible square** on a map that contains obstacles, then prints the map with that square filled in.

The map is made of three characters:
- an **empty** character (free cells)
- an **obstacle** character (cells the square cannot cover)
- a **full** character (used to draw the biggest square)

If several squares have the same size, the program picks the one that is **closest to the top**, and then the one **closest to the left**.

## Map format

The first line gives the number of lines and the three characters, for example:

```
9.ox
...........................
....o......................
............o..............
...........................
....o......................
...............o...........
...........................
......o..............o.....
..o.......o................
```

- `9` is the number of lines of the map
- `.` is the empty character
- `o` is the obstacle character
- `x` is the full character

All lines must have the same length, and the map must end with a newline. If the map is invalid, the program prints `map error`.

## Instructions

### Compile

```
make
```

### Run

```
./bsq map1.txt map2.txt
```

or read the map from standard input:

```
cat map1.txt | ./bsq
```

### Clean

```
make clean    # remove object files
make fclean   # remove object files and the executable
make re       # recompile everything
```

## Example output

```
.....xxxxxxx...............
....oxxxxxxx...............
.....xxxxxxxo..............
.....xxxxxxx...............
....o......................
...............o...........
```

## Algorithm

The solution uses dynamic programming. For each cell, the program stores the size of the biggest square that ends at that cell. The largest value found gives the size and the position of the answer. This way the map is only walked through once, so it stays fast even on big maps.

## Resources

- Subject of the BSQ project (1337 / 42 intranet)
- Dynamic programming: "maximal square" problem

## Author

**mousabir**.
