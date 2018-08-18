Wordsearch generator
====================

This is a Wordsearch generator written in C largely as an exercise in remembering how to use C having originally implemented it in Java (see https://github.com/fooflington/wordsearch-c).

Compiling
---------

Generally you'll probably want the *Release* version which has Optimisation enabled:

```bash
cd Release && make
```

This will drop a `wordsearch` executable

Running
-------

```
Usage: wordsearch <height> <width> [ words ... ]
```

For example:

```
$ ./wordsearch 15 15 gaping panicky lock purple geese massive judge hateful
```

For an existing list of words, the following form can be useful:

```
$ cat file.txt | xargs ./wordsearch 15 15
```

There are some example wordlists included in `tests`.
