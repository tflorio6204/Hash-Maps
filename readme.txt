Collision Ratios:

Total keys: 2417	Hash Table size: 3467
Collisions per key using hash 1: 1.76955, and collision handling 1: 1.64088

Total keys: 2417	Hash Table size: 3467
Collisions using hash 2: 1.76955, and collision handling 1: 57.3926

Total keys: 2417	Hash Table size: 3467
Collisions using hash 1: 1.76955, and collision handling 2: 1.48366

Total keys: 2417	Hash Table size: 3467
Collisions using hash 2: 1.76955, and collision handling 2: 18.1216

Hash Function 1 Description: My hash function 1 iterates through each character of the string
(string length) after calculating the string length and calculates the hash by multiplying by
a prime number of the last calculated value of hash (hashval2 * 7) and then adds it by the
characters ASCII value and mods it by map size. Overall, it uses all n characters of the string
as an n-digit, base b number. I implemented this because since I was using Dr. Seuss, I expected
shorter calculations since the words are suited for a children's book. Looking at calcHash1's
performance, it performed to my expectations. In fact, it was right around that threshold in
Seussout_example.txt of 1.03. It gave a consistent result of 1.77 (rounded) which isn't too bad.
However, I am confused as to why it matches hash function 2's time given I ran the debugger
,and it uses each function accordingly. Regardless, my hash function was quick and efficient based
on my data and wasn't too hard to implement.

Hash Function 2 Description: My hash function 2 calculates the length of the given string and
takes a cumulative sum of all the ASCII values that make up the word in the string (its
characters). It then sets the hash value by modding this sum by the map size and returns it.
I implemented this because it was quick and easy and I wanted to see that since it would be
quick and easy to implement if it would have the same capabilities of a harder implementation
of being efficient such as calcHash1. To my surprise, it had the same values of collision ratios
as calcHash1. However, it seemed to yield worse collision values as the hashes seemed to cluster
in the list. Furthermore, based on this relationship, I am able to make the conclusion that my
hash function 1 was more efficient regardless of the repeated values (1.77).

Collision Function 1 Description: My collision function 1 looked to emulate linear probing.
It used a while loop that kept hashing a new index until it found a valid position by checking
if the spot was equal to null and didn't match the keyword (open space). It calculated this
position by setting the hash equal to the original hash index passed in plus the initial number
of collisions modded by the map size. In the while loop, i was incremented to ensure a valid
hash index would be met eventually. Additionally, the if statement inside that while loop would
break if the conditions weren't met. I implemented linear probing because I knew about the issue
of clustering and wanted to see for myself just how bad it was. Additionally, it seemed fairly
simple to implement. As evidenced by the collision handling numbers of coll function 1 being
higher than that of collision function 2, collision function 1 was much more inefficient.
I was not surprised at all as this was predicted. However, it is cool to actually see this
come to fruition.

Collision Function 2 Description: My collision function 2 looked to emulate quadratic probing.
It used a while loop that kept hashing a new index until it found a valid position by checking
if the spot was equal to null and didn't match the keyword (open space). It calculated this
position by setting the hash equal to the initial number of collisions times the initial number
of collisions + the previous hash index. In the while loop, i was incremented to ensure a valid
hash index would be met eventually. Additionally, the if statement inside that while loop would
break if the conditions weren't met. I implemented quadratic probing because I knew of its
advantage of squaring the numbers would lead to better spacing, and hence a better function.
Furthermore, As evidenced by the collision handling numbers of coll function 2 being lower than
that of collision function 1, collision function 2 was much more efficient. I was not surprised
at all as this was predicted. However, it is cool to actually see this come to fruition.

Funny Quotes:
Output File 1 -->
"For Yertle, the beaches And your mother is Christmas!"
"And he grinned, "are the cat. 'take a loud whack! From there to have to find the smog, without care."
Output File 2 -->
"With your mother is waiting. NO! That's hard. I do as you do?' and sally and he sounds as before!"
"They'd do to be here. So I do! I am the hook. and there."
Output File 3 -->
"I do not a house. I will eat them here when they don't know what to grow."
"He happily lived, eating Truffula Trees! Mile after year."
Output File 4 -->
"And in the king! I'd do! you so big. They shook."
"I biggered my shoulders and the best on doing no one was starting to toss in this big mess! and ham."