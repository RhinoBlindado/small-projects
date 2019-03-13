# Kinship
### Description
This program, as of now, allows the construction of family trees with the included functionality of calculating the kinship 
between two family members. For now, it's set to output in Spanish. Yes, for now it's a pretty basic program.
### Status
_Very_ Work-In-Progress
### To-Do
+ Make any sort of validations with strings.
+ Easier installation usage.
+ Finish implementing the basic libraries and perhaps add any other useful method.
+ Implement functionality regarding other misc (date of birth, death, age as of now, etc ) information about each member of the tree.
+ Develop an interface to easily access and create the family members, the tree and any other functionality.
+ Softcode the "Family Matrix" so it can be used with other languagues (Mainly English for now).
+ ... [Probably more to come]

### Installation
_I don't personally recommend this right now, it is very much **not** user friendly_
1. Download this whole repo as a `.zip` or make a `git clone`.
2. Setup an input file.
    1. Any file extension works for now, I use `.in` for clarity
    2. The formatting of the input file is as follows:
   ```
      N
      ID_1 S_1 fN_1 lN_2 DD_1 MM_1 YYYY_1
      ID_2 S_2 fN_2 lN_2 DD_2 MM_2 YYYY_2
      ...
      ID_N S_3 fN_N lN_N DD_N MM_N YYYY_N
      M
      ID_1_1 FTHR/MTHR ID_1_2
      ID_2_1 FTHR/MTHR ID_2_2
      ...
      ID_1_M FTHR/MTHR ID_2_M
      ```  
    `N`: Number of family members to evaluate.    
    `ID_i`: Integer to identify the person, it can be any integer, without order but it cannot repeat.   
    `S_i`: Sex of person  
    `fN_i`: Fist name of the person, doesn't accept names with spaces.    
    `lN_i`: Last name, ditto.   
    `DD_i,MM_i,YYYY_i`: Birth date.   
    `M`: Number of relationships
    `ID_1_i`: Ascendant, i.e. Father/Mother of `ID_2_i`.    
    `FTHR/MTHR`: String to determine if `ID_1_i` is father or mother.   
    `ID_2_i`: Descendant.   
3. Open `parentesco.cpp` and change `std::cout<<familia.getRelation(ID_1,ID_2)<<std::endl;` with the IDs of two members to determine their kinship.
4. In the terminal, type `make`
5. Followed by `./parentesco.out < input.in`
6. Cry
