## Build

Tested in Mac OS X ARM (64-bit)

To compile and run:
```
$ clang++ -std=c++11 -stdlib=libc++ -Wall -fsanitize=address -g ./main.cpp -o ./main
$ ./main
```

To check memory leaks:
```shell
$ clang++ -std=c++11 -stdlib=libc++ -Wall -fsanitize=address -g ./main.cpp -o ./main-leaks
$ leaks -atExit --list -- ./main-leaks > ./leaks.txt
```

