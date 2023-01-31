# DES Algorithm [Code Flow Explained]
### Pre-requisite [DES Algorithm Slide 15 - 31](https://docs.google.com/presentation/d/1nxHkbSJD9Lk_LG6YCpDqsPLU1B8foWFxee9JuXJ1WTA/edit#slide=id.p15)
### Functions Description

##### passFromTable(vector<vector<int>>,string)

This one is a utility function that takes a table(vector <vector<int>>) and a binary string and returns a matched binary string. It uses a nested loop to pass through every row and then every value in a row.

##### toBinary(string) 

This one is again a utility function, it takes a Hexadecimal Message as a string and returns binary of this string

##### toHexa(string)

This function has been just used once in the entire script, and it is quite the opposite of toBinary. It takes a binaryString and returns a Hexadecimal String

##### matchSBox(vector<vector<int>>,string)

Passing from a SBox is different from other tables thats why we need another function to do that for us. It is very simple, it takes a 6 digit binary string and uses first and last digit to know the row location and middle 4 to know the column location and then return binary of the matching number.

##### getAllKeys(string,string,vector<vector<int>>)

It is one of the most important function. It does all the processing for a key and generates 16 keys.
For every key, it first shifts it cyclically left and for the positions mentioned in the shifts array.
then it combines the Li and Ri and pass them from PC2

##### getR16(vector <vector<vector<int>>>&,vector<vector<int>>,vector<string>,vector<<vector<int>>,string,string)

This is the most important function and it does all the encryption for a message. It generates 16 messages and for each one of them, it flows like this.
1. It passes the Rn-1(Ri) from expansion table and call it ERi
2. It takes XOR with the Key[i] (i stand for current message index) and call the resulting string KERi
3. Then it passes all its substrings, of size 6 each, from the relative SBox and combine them and call the result PS
4. Now it passes PS from PTable and call the result as finalStr
5. Now it takes XOR of Ln-1(Li) with finalStr
6. Stores Rn-1(Ri) into Ln(Li) and stores the resulting XOR into Rn(Ri)

Before returing, it reverses the Li and Ri and returns (Ri + Li, instead of Li + Ri)

##### main function

main function primarily does nothing instead of just calling other functions and passing values.

1. It takes a key and converts it into binary and call it as K
2. Passes K from PC1 and call it KPlus
3. Divide Kplus to C0 and D0
4. get a vector<string> allKeys from getAllKeys function
5. Now takes message and converts it into binary and call it M
6. Passes M from IP table
7. Divide M into L0 and R0
8. Takes all the SBoxes and Expansion Table  and P Tabel to call getR16 function 
9. Calls R16 and gets a binary string calls it R16L16
10. Passes it from Inverse IP table and calls the result as finalString
11. calls ToHexa function to get encrypted message

prints the encrypted message!!!!
