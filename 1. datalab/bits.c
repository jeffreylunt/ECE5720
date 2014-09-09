/* 
 * CS:APP Data Lab 
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

#include "btest.h"
#include <limits.h>

/*
 * Instructions to Students:
 *
 * STEP 1: Fill in the following struct with your identifying info.
 */
team_struct team =
{
   /* Team name: Replace with either:
      Your login ID if working as a one person team
      or, ID1+ID2 where ID1 is the login ID of the first team member
      and ID2 is the login ID of the second team member */
    "A00957898+A01205668", 
   /* Student name 1: Replace with the full name of first team member */
   "Jeffrey W Lunt",
   /* Login ID 1: Replace with the login ID of first team member */
   "A00957898",

   /* The following should only be changed if there are two team members */
   /* Student name 2: Full name of the second team member */
   "Tyler J Wilson",
   /* Login ID 2: Login ID of the second team member */
   "A01205668"
};

#if 0
/*
 * STEP 2: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

CODING RULES:
 
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


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
#endif

/*
 * STEP 3: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest test harness to check that your solutions produce 
 *      the correct answers. Watch out for corner cases around Tmin and Tmax.
 */
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {

  return ((~x) & (~y)); //not both the x and the y to get the zero bits changed to ones. we then AND the zero (now 1's) to get a bitNor return.

}

/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 2
 */
int bitXor(int x, int y) {

  int r1 = (~x) & y;	//result 1 - not x AND y
  int r2 = (~y) & x;	//result 2 - not y AND x

  return ~((~r1) & (~r2));
}
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
  
  return (0x1 & (!(x^y))); //do an exclusive OR. If the two values are the same then the result is 0x0. We do a logical NOT to return true.
				//AND that result with 0x1 to return either 0x1 for true and 0x0 for false.
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  n = n << 3; //shift n bitwise 3 times to get multiples of two (0, 8, 16, 24)
  x = x >> n; //right bitwise shift n times to get the wanted byte as the LSB
 
  return (x & 0x000000FF); //Ignore the 3 MSB
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
 
  return ((x << 31) >> 31); //shift left 31 times to remove all bits but the LSB. Shift right 31 times to copy it to all bit holders
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 1 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  //we need to shift by n but mask the new bits that were shifted in (x>>n)

  return ( x >> n & ( 0xFFFFFFFF << ( 32 + ( ~n + 1 ) ) ) );
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {

	//with each level, two neighboring bits are joined together and shifted. The end result is the number of bits represented in binary
	int level1 = ( x & 0x55555555 ) + ( ( x >> 1 ) & 0x55555555 );
	int level2 = ( x & 0x33333333 ) + ( ( x >> 2 ) & 0x33333333 );
	int level3 = ( x & 0x0f0f0f0f ) + ( ( x >> 4 ) & 0x0f0f0f0f );
 	int level4 = ( x & 0x00ff00ff ) + ( ( x >> 8 ) & 0x00ff00ff );
	int level5 = ( x & 0x0000FFFF ) + ( ( x >> 16 ) & 0x0000FFFF );

	return level1 + level2 + level3 + level4 + level5;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {

	int negativeX = ~x + 1; //this is the two's compliment

	//if the number is not zero, there will be a 1 in the most significant bit of either the normal x or the negative x (depending on if the original is negative or positive)
	//so, we need to look at the most significant bit and return the OR of it.

	return ( ( x >> 32 ) & 0x1 ) | ( ( negativeX >> 32 ) & 0x1 );
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 4 
 */
int leastBitPos(int x) {
  return 2;
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
  
  int max = 0x80000000;		//0x80000000 will give us the max two's complement integer
	
  return ~max;			//NOT this value to return the largest two's complement integer
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {

  return !((x&80000000)>>31);
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {

	//save off the sign bits
	int signBitX = x >> 31;
	int signBitY = y >> 31;

	//there are four cases:
	//1: signBitX = 0, signBitY = 0 (both positive)
	//2: signBitX = 0, signBitY = 1 (x positive, y negative)
	//3: signBitX = 1, signBitY = 0 (x negative, y positive)
	//4: signBitX = 1, signBitY = 1 (both negative)

	//if the signs aren't equal, then this value is 1 if x < y
	int signsNotEqualandXltY = !signBitY & signBitX;

	//if the sign bits are equal, then you can determine which number is larger by adding the inverse of one and looking at the sign bit
	//x > y means that sign of ( x + ~y ) is 0
	//x < y means that sign of ( x + ~ y ) is 1
	int signBitofDifference = ( x + ~y ) >> 31;
	int signsEqualandXltY = ( signBitX ^ signBitY ) & signBitofDifference;

	return !( signsEqualandXltY | signsNotEqualandXltY );
	
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {

	//any negative number is off by one...
	int signBit = x >> 31;
	
	//the ( 0x1 << n ) + ~0 ) give a mask of the lower n bits, takes into account the case of the number being zero
	//one is added only if the number is negative
	return ( x + ( signBit & ( ( 0x1 << n ) + ~0 ) ) ) >> n;
}
/* 
 * abs - absolute value of x (except returns TMin for TMin)
 *   Example: abs(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int abs(int x) {

	//this all has to do with the sign bit and the two's compliment
	//we need to take the two's compliment if negative and do nothing if positive
	int signBit = x >> 31;
	int compliment = ~x + 1;
	
	//if negative, this addition will result in overflow in such a way that we are left with the absolute value. If positive, the 1 + ~signBit will be zero and we will be left with our original number
	return 1 + ~signBit + ( x ^ signBit );
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
  
//The sign of the sum of x + y must remain the same as the sign on x and y. If not, then overflow has occured
  int signofsum = (((x + y)>>31) & 0x1);
  int signofx = ((x>>31) & 0x1);
  int signofy = ((y>>31) & 0x1);

	return !(~(signofx ^ signofy) & (signofx ^ signofsum));
}
