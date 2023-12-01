# The Enigma Machine

### A Practical Implementation of the Infamous Enigma Machine in C++

1. Clone the repository:

```
git clone https://github.com/shashankp28/enigma-machine.git
```

2. To build `The Enigma Machine` run the following command:

```
make
```

3. You can modify the `PlugBoard` pairing from `enigma.conf` file

4. You can modify the rotors used (select distinct 3 of 5) in `enigma.conf` file

5. You can modify the initial position of the rotors in `enigma.conf` file

6. You can modify the Reflection rotor in `enigma.conf` file

7. To Encrypt using `The Enigma Machine` run the following command:

```
./bin/enigma enigma.conf input.txt output.txt
```

8. To Decrypt using `The Enigma Machine` switch the input and output files:

```
./bin/enigma enigma.conf output.txt input.txt
```

9. Encryption/Decryption Rate: `~ 7.7 MB/s`
