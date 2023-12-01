# The Enigma Machine

### A Practical Implementation of the Infamous Enigma Machine in C++

1. Clone the repository:

```
cloning
```

2. To build `The Enigma Machine` run the following command:

```
make
```

3. You can modify the `PlugBoard` pairing from `my.conf` file

4. You can modify the rotors used (select distinct 3 of 5) in `my.conf` file

5. You can modify the initial position of the rotors in `my.conf` file

6. You can modify the Reflection rotor in `enigma.conf` file

**NOTE:** `MAKE SURE THAT PROMPT FILE ENDS WITH --exit-- IN A NEW LINE`

7. To Encrypt using `The Enigma Machine` run the following command:

```
./bin/enigma ./enigma.conf ./my.conf < ./input.txt > ./output.txt
```

8. To Decrypt using `The Enigma Machine` switch the input and output files:

```
./bin/enigma ./enigma.conf ./my.conf < ./output.txt > ./input.txt
```

9. Encryption/Decryption Rate: `~ 3.94 MB/s`
