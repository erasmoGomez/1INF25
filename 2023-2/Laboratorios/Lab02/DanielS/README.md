## Build

Tested in Mac OS X ARM (64-bit)

To compile:
```
$ clang++ -std=c++17 -stdlib=libc++ -g -fsanitize=address ./main.cpp -o ./main
```

To check memory leaks:
```shell
$ leaks -atExit --list -- ./main > ./leaks.txt
```

Alternatively, run `make` or `make leaks`.

