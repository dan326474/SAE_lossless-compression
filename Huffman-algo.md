HUFFMAN CODING

Take the word BANANA

B   0100 0010
A   0100 0001
N   0100 1110
A   0100 0001
N   0100 1110
A   0100 0001

In total, this word would take up 48 bits.

We have:
- 3 A
- 1 B
- 2 N

'A' appears so many times, and yet we have to use full 8-bit (i.e. 24 bits in total) to represent them.

Let's change the representation of every letter:

A: 0    B: 10    N: 11

BANANA becomes

B   10
A   0
N   11
A   0
N   11
A   0

Now the whole word becomes 9 bits instead of 48 bits. This is far more efficient than RLE already (81.25% compression rate).

10 0 11 0 11 0
B  A N  A N  A

HOW DO WE DECIDE WHICH LETTER GETS WHICH NUMBER?

1. Start with the twoo least occuring letters: Bx1, Nx2.
2. Put them under one node in a binary tree.
3. node = SUM_OF_WEIGHTS(B, N) = 1 + 2 = 3
4. Now we have two nodes: Ax3, (B+N)x3
5. Join them under a new node. Let X = B + N
6. new_node = SUM_OF_WEIGHTS(A, X) = 3 + 3 = 6

    6
  /   \
 3     3
 |    / \
 A   B   N