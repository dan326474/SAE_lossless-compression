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

A: 0    B: 11    N: 10

BANANA becomes

B   11
A   0
N   10
A   0
N   10
A   0

Now the whole word becomes 9 bits instead of 48 bits. This is far more efficient than RLE already (81.25% compression rate).

11 0 10 0 10 0
B  A N  A N  A

HOW DO WE DECIDE WHICH LETTER GETS WHICH NUMBER (ENCODING)?

1. Start with the two least occuring letters: Bx1, Nx2.
2. Put them under one node in a binary tree.
3. node = SUM_OF_WEIGHTS(B, N) = 1 + 2 = 3
4. Now we have two nodes: Ax3, (B+N)x3
5. Join them under a new node. Let X = B + N
6. new_node = SUM_OF_WEIGHTS(A, X) = 3 + 3 = 6

    6
 0/   \1
 3     3
 |   0/ \1
 A   2   1
     |   |
     N   B

7. All left branches = 0; All right branches = 1
8. Navigate the tree using prefix notation. Every turn taken defines the encoded form of the character at the leaf.
9. Thus we have
  A: 0    B: 11   N: 10

HOW TO UNZIP?

1. Take compressed form: 110100100
2. First bit = 1, a.k.a. right turn. 1 doesn't mean anything => read next = 1.
3. 11 = B
4. Next = 0 = A
5. Next = 1 (means nothing) => read next = 0
6. 10 = N
7. Next = 0 = A
8. Next = 1 => read next = 0
9. 10 = N
10. Next = 0 = A

NOTE: One code can never be the start of another code
e.g. If F = 110 => 1100 = NULL

The pair choices are based on frequency:

1. Put every distinct letter in a priority queue, ordered by its count.

  (A:3  N:2  B:1)

2. Remove the two nodes with the smallest counts (B, N) and join them under a new parent. The parent’s count is their sum.
3. Put that parent back in the queue.

  (A:3  BN:3)

4. Repeat until only one node remains.

  (ABN:6)