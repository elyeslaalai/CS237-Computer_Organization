/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2020 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */


/*
 * is_zero - returns 1 if x == 0, and 0 otherwise
 *   Examples: is_zero(5) = 0, is_zero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int is_zero(int x) {
  // number of operations used = 1

  // compares the input to zero. If it's then it return 1 (true)
  // If not zero, then returns 0 (false)
  return !x;

}


/*
 * get_bitwise_xor - x^y using only ~ and &
 *   Example: get_bitwise_xor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int get_bitwise_xor(int x, int y) {
  // number of operations used = 7

  // for every bit, we only return 1 if the values are different
  return ( ~(x & y) ) & ( ~(~x & ~y) );

}

/*
 * is_implication - return x -> y in propositional logic - 0 for false, 1
 * for true
 *   Example: is_implication(1,1) = 1
 *            is_implication(1,0) = 0
 *   Legal ops: ! ~ ^ |
 *   Max ops: 5
 *   Rating: 2
 */
int is_implication(int x, int y) {
  // number of operations used = 2

  // If x is not 1 (false), returns 1. Else if x is 0 (false), returns 0.
  return  (!x) | y;

}

/*
 * is_any_odd_bit_set - return 1 if any odd-numbered bit in word set to 1
 *   Examples is_any_odd_bit_set(0x5) = 0, is_any_odd_bit_set(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int is_any_odd_bit_set(int x) {

  // number of operations used = 9

  // the constant byte oxAA has its 1's set only for odd bits (e.g 1010)
  // we compare it to all bytes in x to see if its 1s match with any in x
  return !! ( ( x | (x >> 8) | (x >> 16) | (x >> 24) ) & 0xAA );

}

/*
 * replace_byte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replace_byte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replace_byte(int x, int n, int c) {

  // number of operations used = 6

  // first we create a variable that will allow us to shift to the
  // byte replacement location since we are working on byte, then our
  // shifts should be by multiples of 2pow(3) = 8
  int shift = n << 3;

  // we create and position the mask in the byte replacement location
  // the byte at the replacement location will be all 0s, and the rest all 1s
  int xWithZerosInReplacementLocation = ~(0xFF << shift);

  // we position the byte c correctly on a 32-bit format (surround it by 0s)
  c = c << shift;

  // We changes the byte we are replacing in x to all 0s and leave the
  // others unchanged
  x = x & xWithZerosInReplacementLocation;

  // x contains 1 changed byte to all zeros and the rest is as it was
  // initially c contains 1s in the replacement position and 0s
  // elsewhere the bits not changing will be the same as in x the bits
  // changing will depend on the content of c since in x they contain 0s
  return x | c;

}

/*
 * get_bitwise_count - returns count of number of 1's in word
 *   Examples: get_bitwise_count(5) = 2, get_bitwise_count(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int get_bitwise_count(int x) {
	//$ Want to indent consisently
	// the count of number of 1's in word
	int countOfOnes = 0;
	int counterOfSumsPerFourBits, sumsPerFourBits;

	// first we build up the mask that will count the number of ones in x
	// the mask should be represented by 8 hexadecimal 1s: 1010 1010 .. 1010
	counterOfSumsPerFourBits = 0x11; 
	counterOfSumsPerFourBits = (counterOfSumsPerFourBits << 8) | 0x11;
	counterOfSumsPerFourBits = (counterOfSumsPerFourBits << 8) | 0x11;
	counterOfSumsPerFourBits = (counterOfSumsPerFourBits << 8) | 0x11;

	sumsPerFourBits = (x & counterOfSumsPerFourBits) +
  ((x >> 1) & counterOfSumsPerFourBits) +
  ((x >> 2) & counterOfSumsPerFourBits) +
  ((x >> 3) & counterOfSumsPerFourBits);

	// now we add the every sum in the sumsPerFourBits to our final count of ones
	// we add the number of 1s in the least significant byte
	countOfOnes += ( (sumsPerFourBits & 0xF)  +
  ( (sumsPerFourBits >> 4) & 0xF ) );

	// then, we add the number of 1s in the second least signicant byte
	countOfOnes += ( ( (sumsPerFourBits >> 8) & 0xF)  +
  ( (sumsPerFourBits >> 12) & 0xF ) );

	// then, we add the number of 1s in the third least signicant byte
	countOfOnes += ( ( (sumsPerFourBits >> 16) & 0xF)  +
  ( (sumsPerFourBits >> 20) & 0xF ) );

	// then, we add the number of 1s in the most signicant byte
	countOfOnes += ( ( (sumsPerFourBits >> 24) & 0xF)  +
  ( (sumsPerFourBits >> 28) & 0xF ) );

	// we return our counter that contains the needed result
	return countOfOnes;
}
