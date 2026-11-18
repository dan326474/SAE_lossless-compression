RLE (Run-length encoding) is a lossless data compression method that replaces repeating sequences of identical values with a single value.


HOW COMPRESSION IT WORKS

Instead of storing every instance of an item, RLE counts the no. of occurences (i.e.  the "run") of a value in a row and stores that number alongside that value.

Consider the following examples:

Original string: AAAABBBCCDAA

RLE compressed: 4A3B2C1D2A (or A4B3C2D1A2)

Compression rate: 16.7%

Here's an example with pixel data (e.g. a b/w image):

Original sequence: WWWWBBBBBBW (W: White, B: Black)

RLE compressed: 4W6B1W

Compression rate: 45.5%


HOW DECOMPRESSION WORKS

The decoder reads each count and value pair and repeats the character or pixel that many times in a row.

RLE is used in:
- Simple images and icons (e.g. icons, images with large solid blocks of the same colour)
- .bmp, .tga, .tiff file formats and database storage layers (e.g. Parquet)
- Fax machines: Used to compress long rows of black or white space in faxes.


LIMITATIONS

If patterns are random and hardly ever repeat, RLE has diminishing returns and could even case "negative compression", i.e. it makes the file larger.