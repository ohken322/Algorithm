# README

The implementation of van Emde Boas(vEB) tree following a book *Introduction to Algorithms* 3rd Edition.

You can play with the vEB tree as much as you want ;)

## van Emde Boas tree
vEB tree is a data structure which can be considered as a multi-branch tree, defined and implemented in a recursive way.

It can deal with any subset of {0,1,2,...,u-1} for any fixed power u of 2.

vEB tree has its strength on its small computation complexity for various fundamental operations:
it can execute each of the operation in the list below in O(log log u) time.

## How to use
By running main.cpp linking with vEB.cpp, you can create a van Emde Boas tree by entering the size of the tree (maximum size of the set).

Execute `Insert x` to insert an integer x into the vEB tree you've created.
The command you can use are the following:
- `Insert` (one element at a time, sorry)
- `Delete` (same as above)
- `Member` (boolean, true if x is contained in the set)
- `Successor`/`Succ` (the smallest value in the set among those larger than x)
- `Predecessor`/`Pred` (the largest value in the set among those smaller than x)
- `Minimum`/`Min`
- `Maximum`/`Max`

Enter `show summary(/set/all)` to see the current summary, set, or both, respectively, the tree holds. 

If there is no appropriate element in the set (for example, `Min` for an empty tree), then it returns -1.

If you want to quit playing with the vEB tree, enter `exit`.

Please have fun!
