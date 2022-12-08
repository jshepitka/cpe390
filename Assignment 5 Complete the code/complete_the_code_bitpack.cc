#include <iostream>
#include <iomanip>

using namespace std;

void compress(const uint32_t a[], uint32_t len, uint32_t out[]) {
	int out_index = 0;
	for (uint32_t i = 0; i < len; i += 16) { // do 16 at a time
		uint32_t sum = 0; // this gets stored in a register. Compute 32 bits

		for (uint32_t j = i; j < 16 + i; j++) { // how many do we do? 00/00 00/00 00/00 00/00 00/00 00/00 00/00 00/00
			// move the existing sum to the left, then OR in the new value
			sum = (sum << 2) | a[j];																			
			//sum = (sum << 2) + a[j]; // + works the same since the two new bits are to the right
		}
		out[out_index++] = sum;
	}
}

void compress2(uint32_t b[], uint32_t len, uint32_t out[]) {
  uint32_t out_i = 0;
  for (uint32_t x = 0; x < len; x++) {			//checking to see if numbers are within range
    if(b[x] > 7) {
      cout << "An Element in the Array is too large for this compression: (" << b[x] << ") The number will be limited to 3 bits."<< '\n';
      uint32_t temp = b[x] & 0x7;
      b[x] = temp;
	}
  }
  uint32_t r = 2; //number of bits to take off end of number and add to next
  uint32_t sum = 0;
  uint32_t j = 0;
													                    //    1  /  2 /  3 / 4 / 5 /  6  / 7  / 8  / 9 / 10 / 	 11	 /12 / 13/  14 / 15 /16  / 17/ 18 / 19  / 20/ 21/    22   / 23 / 24 / 25/ 26 / 27  /28 /29 / 30  / 31 /32   /   33 /34  / 35  / 36/    
	for (uint32_t i = 0; i < len; i += 10) {		//   000/0|00/00  0/000|000/0  00/00|0/000  000/000/00		0/000|000/0  00/00|0/000  000/0|00/00  0/000|000/0  	00/00|0/000  000/0|00/00  0/000|000/0  00/00|0/000		000/0|00/00  0/000|000/0  00/00|0/000  000/000/00
									//		1			2				3			1				2			3				1			2				3			1			2				3				1			2			3				1
   	for(j = i; j < 10 + i; j++) {
     		sum = (sum << 3) | b[j];
	  	if(j == len - 1) {
        out[out_i] = sum;
        return;
		  }
    }
    uint32_t g = i + 10;
		uint32_t hang = b[g];
    if(r == 0) {
      out[out_i++] = sum;
      //dont increment i or add to end
      r = 2;
      sum = 0;
    }
    else {
      uint32_t end = hang >> (3 - r); 
      sum = sum << r | end;
      uint32_t start = hang & 0x3;
      if(r == 2)
        start = start & 1;  
      out[out_i++] = sum;
      if (out_i == 4)
        return;
      sum = start;
      r--;
      i++;
    }
  }
}

/*
  Even when you successfully complete the above code, it has flaws.
  What would happen if a value in the array is NOT in the range 0 to 3?
  Write a second version of the code above that corrects this problem,
	and also handle a list which is not a length that is a multiple of 16 long

*/

void dump(const uint32_t x[], uint32_t len) {
	cout << hex;
	for (uint32_t i = 0; i < len; i++)
		cout << x[i] << " ";
	cout << '\n';
}

int main() {
	// given an array a of integers ranging from 0 to 3, pack each number into two bits
	// store into array b. This is a compression factor of 16.

	uint32_t a[] = {
		3, 2, 1, 3, 2, 1, 0, 0,
		1, 3, 2, 1, 2, 3, 1, 2,
		3, 1, 2, 3, 3, 3, 1, 3,
		2, 1, 2, 2, 2, 1, 1, 0
	};

	uint32_t out1[2];
	// read in every element of a and write into b
	compress(a, 32, out1);
  dump(out1, 2);

	uint32_t b[] = {
		3, 2, 1, 3, 2, 1, 0, 0,
		1, 3, 2, 1, 2, 3, 1, 2,
		3, 1, 2, 5, 1, 3, 1, 7, // note the 5 and 7 on this line
		2, 1, 2, 2, 2, 1, 1, 0,
		2, 1, 1, 0
	};

	uint32_t out2[4];
	compress2(b, 36, out2);
	dump(out2, 4);

}
//			3, 2, 1, 3, 2, 1, 0, 0, 1, 3, 	      	2, 			1, 2, 3, 1, 2, 3, 1, 2, 5, 1, 	        3, 		    1, 7, 2, 1, 2, 2, 2, 1, 1, 0,             2, 1, 1, 0
//					68b4402d										                            14ca6552										            cf452448                                    448
//011/010/00 1/011/010/0 01/000/000 001/011/01 		0/001/010/0 11/001/010 011/001/01 0/101/001/0		11/001/111 010/001/01 0/010/010/0 01/001/000  
// 1   2   3   4   5   6   7   8   9   10    11   	  12  13  14