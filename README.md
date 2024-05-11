I don't know how to write C! But I want to!

This program converts your 5e Dungeons and Dragons character's wealth into the highest denominations possible, like a magical CoinStar machine. I made a similar program in Python a few years ago, but I want to learn C, and this seemed like a good test program.

This program uses the denominations from 5th Edition D&D, as well as two table rules that my game's DM allows:
1) Converting between denominations is freely allowed, but the player has to keep track of their wealth themselves; and
2) electrum is stupid

Here's an example output from the program:

```
How much copper do you have?    > 112
How much silver do you have?    > 67
How much electrum do you have?  > 1
How much gold do you have?      > 266
How much platinum do you have?  > 13


PURSE VALUES:
CU: 112
AG: 67
EL: 1
AU: 266
PT: 13

Converting coins to wealth...

0 CU + 112 CU
=112 CU

112 CU + 67 AG
=782 CU

782 CU + 1 EL
=832 CU

832 CU + 266 AU
=27432 CU

27432 CU + 13 PT
=40432 CU



Converting wealth to coins...

STARTING WEALTH:
Total Wealth in Copper: 40432


40432 CU -> 40 PT (432 CU rem.) - Adding to purse...
432 CU -> 4 AU (32 CU rem.) - Adding to purse...
Skipping electrum...
32 CU -> 3 AG (2 CU rem.) - Adding to purse...
2 CU remaining - Adding to purse...
Converting coins to wealth...

0 CU + 2 CU
=2 CU

2 CU + 3 AG
=32 CU

32 CU + 0 EL
=32 CU

32 CU + 4 AU
=432 CU

432 CU + 40 PT
=40432 CU



Total Wealth in Copper: 40432


PURSE VALUES:
CU: 2
AG: 3
EL: 0
AU: 4
PT: 40
```
