# Algorithms and Data Structures
--------------------------------
I'm interested to learn more about the fundamentals of computer science, and get some practice writing C code while I'm at it.  I get a lot of bittersweet joy out of writing C code- it just runs so darn fast, that when it works it's like the greatest feeling in the world.  So it certainly can't help to be sharp at the language.  It's great, in my opinion, to get so close to the metal and harden up after all of those nice, fun handholding languages I write with so much frequency like PHP and Python have turned my brain into mush :D

So far it's not too impressive - an implementation of a linked list, and the skeleton for a binary tree.  I intend to implement most of the infamous sorting algorithms on the linked list, partially just to say that I have done so, and then move on to greener pastures such as hash tables or (<i>gasp!</i>) a binary search tree reverse.

I'm very keen on taking a whack at the [Traveling Salesman](http://en.wikipedia.org/wiki/Travelling_salesman_problem) or [K-Armed Bandit](http://en.wikipedia.org/wiki/Multi-armed_bandit) problem as well.

## Compiling

To compile the linked list:

```
gcc linked_list.c -o linked_list
```

Running:

```
linked_list 1 2 3 4 5
```

will create and print (dump) a linked list with all of those numbers.  Soon I will add some validation or else people will do nasty things like

```
linked_list 1 2 foo bar 4
```

and make my program segfault.

You can give that program `--sort` parameter which eventually will allow you to choose the algorithm you want to sort with:

```
linked_list --sort quick 5 4 3 2 1
```

Currently unlicensed at the moment, but I don't think anyone's dying to include my linked list code in their app just yet.
