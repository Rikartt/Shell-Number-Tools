# Shell Number Tools
Some experimenting with making shell runnable programs using C, that can be used to play with numbers.

## formatnum
Formats numbers according to a splitter, syntax is like this,
`snt-formatnum [E|S|other splitter] [numbers separated by spaces]`
Where `snt-formatnum` can be replaced with whatever filename the compiled program has currently and `E`, `S` mean Engineering vs Scientific notation respectively, other splitter can be any char to split the number, like `*10^` for example.

## veginere
Decrypts and encrypts a ciphertext or ciphertext when provided with the key. Syntax is as follows:
`snt-veginere [mode: e(ncrypt)|d(ecrypt)] [key] [plaintext / ciphertext]`