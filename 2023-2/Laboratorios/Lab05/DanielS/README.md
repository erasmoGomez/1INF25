## Build

Tested in Mac OS X ARM (64-bit)

To compile:
```
$ clang++ -std=c++11 -stdlib=libc++ -g -fsanitize=address ./main.cpp -o ./main
```

To run:
```
$ ./main
```
