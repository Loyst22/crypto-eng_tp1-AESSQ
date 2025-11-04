
## Q.3

*Keyed function*: function output depends on secret key

take a block cipher and turn it into a crypto function.

1. k = k1 || k2 -> 256 bits in total
2. encrypt x twice. once with k1 then with k2
3. x = x1 xor x2

If we do F(k, k, x) = E(k, x) xor E(k, x)
then both E will be the same, so the result is 0
