#include <iostream>

#include <gmp.h>

#include <math.h>


using namespace std;





void threeDotTwentyfive(int a[], int length, mpz_t n){

     mpz_t c;

     mpz_init( c );

     mpz_t bSquared;

     mpz_init( bSquared );

     mpz_t b;

     mpz_init( b );

     mpz_t aMinusB;

     mpz_init( aMinusB );

     mpz_t d;

     mpz_init( d );

     mpz_t q;

     mpz_init( q );

     mpz_t aProduct;

     mpz_init( aProduct );

     mpz_t remainder;

     mpz_init( remainder );

     

     

     mpz_set_si(c, a[0]);

     mpz_set(aProduct, c);
	cout <<"\n";
	mpz_out_str(stdout,10,aProduct);
	cout << endl << endl;
    // mpz_mul(bSquared, c, c);

     mpz_powm_ui(bSquared, c, 2, n);

     for(int i = 1; i < length; i++){

         mpz_set_si(c, a[i]);

         mpz_mul(aProduct, aProduct, c);

         mpz_powm_ui(c, c, 2, n);

         mpz_mul(bSquared, bSquared, c);

     }

     

cout << "b^2 = ";

mpz_out_str(stdout, 10, bSquared);

cout << endl;     



     //mpz_mod(bSquared, bSquared, n);

     mpz_mod(aProduct, aProduct, n);


     

     mpz_sqrtrem(b, remainder, bSquared);

mpz_mod(b, b, n);	

cout << "b = ";

mpz_out_str(stdout, 10, b);

cout << endl;     

if( mpz_cmp_si(remainder, 0 ) != 0)

         cout << " bSquared is NOT a perfect square \n";

     

     mpz_sub(aMinusB, aProduct, b);

     mpz_abs(aMinusB, aMinusB);

     cout << "a - b = ";

mpz_out_str(stdout, 10, aMinusB);

cout << endl;

     mpz_gcd(d, n, aMinusB);

     

     cout << endl;

             mpz_out_str(stdout, 10, d);

             cout << " = d" << endl;

     

     if( mpz_divisible_p(n,d) > 0 ){

             mpz_divexact(q, n, d);

             cout << endl;

             mpz_out_str(stdout, 10, q);

             cout << " = q" << endl;

     }

     else{

         cout << "d does not perfectly divide n\n";

     }

     

     

     return;

 }



bool millerRabin(mpz_t numberInQuestion, mpz_t a){

mpz_t possibleWitness;

mpz_init( possibleWitness );

mpz_set( possibleWitness, a );

//        if numberInQuestion is even or 1 < gcd(possibleWitness, numberInQuestion) < numberInQuestion, return true //true = composite

//                solve numberInQuestion - 1 = ( 2^k ) * q // q must be odd

//                possibleWitness = possibleWitness^q mod numberInQuestion

//                if possibleWitness  is congruent to 1 mod numberInQuestion 

//                 composite = true

//                        return !composite //false

//                        for(int i =0, i < k; i++){

//                            if possibleWitness is congruent to -1 mod numberInQuestion

//                                return !composite;

//                                possibleWitness = possibleWitness^2 mod numberInQuestion; // 

//                        }

//                        

//        return true; // composite = true

                        

        //bool isComposite = 1; //true

        bool composite = true;

        mpz_t g;

        mpz_init (g);

        mpz_gcd(g, possibleWitness, numberInQuestion);

        //if numberInQuestion is even or 1 < gcd(possibleWitness, numberInQuestion) < numberInQuestion, return true //true = composite

      

  if( (mpz_divisible_ui_p(numberInQuestion, 2) != 0  ) || ((mpz_cmp_si( g, 1) > 0) && (mpz_cmp(g , numberInQuestion) < 0))){

                return composite; // composite = true

}

        //solve numberInQuestion - 1 = ( 2^k ) * q // q must be odd

        mpz_t nMinusOne;

        mpz_init( nMinusOne );

        mpz_sub_ui( nMinusOne, numberInQuestion, 1);

        unsigned long b = 1;

        while( mpz_divisible_2exp_p(nMinusOne,b) > 0 ){

            b++;

        }

        b--;

        mpz_t d;

        mpz_init( d );

        mpz_t q;

        mpz_init( q );

        mpz_ui_pow_ui( d, 2, b );

        mpz_divexact(q, nMinusOne, d );

        

        //possibleWitness = possibleWitness^q mod numberInQuestion

        mpz_powm(possibleWitness, possibleWitness, q, numberInQuestion);

        

        

//        if possibleWitness  is congruent to 1 mod numberInQuestion 

//                 composite = true

//                        return !composite //false

//        

        mpz_t One;

        mpz_init_set_str(One, "1", 10);

        

        if ( mpz_congruent_p(possibleWitness, One, numberInQuestion  ) > 0 ){

                        return !composite;

}        mpz_t negOne;

        mpz_init_set_str(negOne, "-1", 10);

        

if( mpz_congruent_p(possibleWitness, negOne, numberInQuestion  ) > 0 ){

                        return !composite;

}


        unsigned long i = 0;

        //for(int i =0, i < k; i++){

        while( i < b ){

                //if possibleWitness is congruent to -1 mod numberInQuestion

            

            //possibleWitness = possibleWitness^2 mod numberInQuestion; // 

            mpz_powm_ui(possibleWitness, possibleWitness, 2, numberInQuestion);

if( mpz_congruent_p(possibleWitness, negOne, numberInQuestion  ) > 0 ){

                        return !composite;

}

i++;

        }

                        


        return true; // composite = true

//  

    }




    //returns the count of numbers <= x that are b-smooth.

    //A number is b-smooth if all of its prime factors are less than or equal to b.

    int sigh(int x, int b){

        int smoothCount = b-1;

        bool bSmooth = true;

        int count = 0;


        

//        for(int i = b + 1; i <= x; i++){

//            for(int j = 2; j <= b; j++){

//                if(i%j != 0){

//                    bSmooth = false;

//                    j = b+1;

//                }

//            }

//        }

        

        

        

     bool isComposite = false;

     

     mpz_t check;

     mpz_init( check );

     mpz_t a;

     mpz_init( a );

     mpz_t modResult;

     mpz_init( modResult );

     mpz_t remainder;

     mpz_init( remainder );

     

     int j = 2;

     

     int composite[x];

     

     for(int i = 0; i < x; i++){

         composite[i] = 0;

     }

     

     

     

     for(int i = b+1; i < x+1; i++){

         //millerRabin(numberInQuestion, possibleWitness)

         mpz_set_si( check, i );

 

         while(( j < i ) && (j < x)){

                mpz_set_si( a, j );

                isComposite = millerRabin(check, a);

                j++;

                if( isComposite ){

                        composite[count] = i;

                        count++;

                        j=i+1;

        }

         }

         j=2;

     }

     cout << "The composite numbers that were found are : ";

     for(int m = 0; m<count; m++){

         cout << composite[m] << ", ";

     }

     cout << endl;

     cout << " There are " << count << " total composites between b and x.  X = " << x << endl;


//     

//     for(int i = 0; i < count; i++){

//         mpz_set_si( check, composite[i] );

//         for(int j = 2; j <= b; j++){

//                if( mpz_divisible_ui_p(check, j) > 0 )

//                        mpz_divexact_ui(remainder, check, j);

//         }

//         

//     }

        



     for(int i = 0; i < count; i++){

         mpz_set_si( check, composite[i] );

         for(int j = 2; j <= b; j++){

                if( mpz_divisible_ui_p(check, j) > 0 ){

                        mpz_divexact_ui(check, check, j);

                        j=2;

                }

         }

         if( ( mpz_cmp_ui(check, b) == 0 ) || ( mpz_cmp_ui(check, b) < 0 )){

             smoothCount++;

             cout << "This number was determined to be B-smooth : "  << composite[i] << endl;

             

         }

         

     }

        

     cout << "The total number of B-smooth numbers less than X is : " << smoothCount << endl;

     cout << "For b = " << b << " and x = " << x << endl;

     

        

        return count;

    }

    

    

   void threeDotTwentyeight(int n){

        double logN = n* log(2);

        double logLogN = log(logN);

        double underTheRadical = logN * logLogN;

        double squareRoot = sqrt(underTheRadical);

        double lOfN = exp(squareRoot);

        double seconds = lOfN / 1000000000;

        double hours = seconds / 3600;

        double days = hours / 24;

        double years = days / 365.25;

        

        

        cout << "The number of seconds for 2^" << n << " operations is " << seconds << endl;

        cout << "The number of hours for 2^" << n << " operations is " << hours << endl;

        cout << "The number of days for 2^" << n << " operations is " << days << endl;

        cout << "The number of years for 2^" << n << " operations is " << years << endl;

        

        

        

        return;

    }    



void threeDotThirtythree(int N, int B, int fStart, int fStop){

        int count = fStop - fStart + 1;

        int fValues[count];

        int divisors[10] = {2,3,2,5,7,2,3,11,13,2};

        int mods[10]     = {2,3,4,5,7,8,9,11,13,16};

        

        for( int i = 0; i < count; i++){

            fValues[i] = ((fStart + i)*(fStart + i) ) - N;

            cout << endl << fValues[i] << endl;

        }


    int index = 0;

    //if array starts with an even, skip the first one so we can know where to start dividing out 2

    if (fValues[index] % 2 == 1){

      index = 1;

    }


    //divide out 2

    while(index < count){


        fValues[index] /= 2;

        cout << endl << fValues[index] << endl;

        index += 2;


    }

       int step = 1;

       int p = mods[step];

        bool solved = false;


        while( mods[step] <= B ){

           p = mods[step];


            for (int t = 0; t < mods[step]; t++) {

          if ((t*t) % p == N % p) {

        solved = true;

        break;

          }

        }


        if (solved) {

      cout << "Solution exists for " << N % p << " mod " << p << endl;


          for (int T = fStart; T <= fStop; T++) {

        if (((T*T) % p) == (N % p)) {

          index = T - fStart;

        cout << "The T value that satisfies T^2 % p == N % p is : " << T << endl;  

while (index <= fStop) {


            fValues[index] /= divisors[step];

            index = index+p;

          }//while (index <= fStop)

        }// if ((T*T) % p == N % p)

          }//  for (int T = fStart; T <= fStop; T++)

        }//  if (solved)


      solved = false;

      step++;

        }


for( int i = 0; i < count; i++){

         //   fValues[i] = ((fStart + i)*(fStart + i) ) - N;

            cout << endl << "fValue[" << i << "] = " << fValues[i] << endl;

        }        

        

        return;

    }


void NoneWorkingthreeDotThirtythree(int N, int B, int fStart, int fStop){

        int count = fStop - fStart + 1;

        int fValues[count];

        int divisors[10] = {2,3,2,5,7,2,3,11,13,2};

        int mods[10] = {2,3,4,5,7,8,9,11,13,16};

        

        for( int i = 0; i < count; i++){

            fValues[i] = ((fStart + i)*(fStart + i) ) - N;

            cout << endl << fValues[i] << endl;

        }

        

//divide every other entry by 2:

        if( fValues[0] % 2 == 0 ){

            for( int i = 0; i < count; i+=2){

                fValues[i] /= 2;

                cout << endl << fValues[i] << endl;

            }

        }

        else{

            for( int i = 1; i < count; i+=2){

                fValues[i] /= 2;

                cout << endl << fValues[i] << endl;

            }

        }

            

        

        

        

        return;

    }


    void threeDotThirtyeight(mpz_t a, mpz_t p){

        mpz_t b;

        mpz_init( b );

        mpz_t pPlus1Div4;

        mpz_init( pPlus1Div4 );

        mpz_add_ui( pPlus1Div4, p, 1 );

        mpz_div_ui( pPlus1Div4, pPlus1Div4, 4 );

        mpz_powm( b, a, pPlus1Div4, p );

        

        cout << " b = ";

        mpz_out_str(stdout, 10, b);

        cout << " satisfies b^2 = ";

        mpz_out_str(stdout, 10, a);

        cout << " mod ";

        mpz_out_str(stdout, 10, p);

        cout << endl;

        return;

    }



int main(int argc, char** argv) {


     //threeDotTwentyfive
	cout << "\n\n\nSTART 3.25\n\n)" << endl;

     int arrayLength = 3;
	cout << "\n\neXample)\n\n";
int a[5] = {1869, 1909, 3387,0 ,0 };

mpz_t n;

mpz_init( n );

mpz_set_str(n, "914387", 10);

threeDotTwentyfive( a, arrayLength, n );

cout << "\n\nA)\n\n";

arrayLength = 2;

a[0] = 1882;

a[1] = 1898;

mpz_set_str(n, "61063", 10);

threeDotTwentyfive( a, arrayLength, n );

cout << "\n\nB)\n\n";

arrayLength = 2;

a[0] = 773;

a[1] = 763;

a[2] = 773;

a[3] = 976;

mpz_set_str(n, "52907", 10);

threeDotTwentyfive( a, arrayLength, n );


cout << "\n\nC)\n\n";

arrayLength = 3;

a[0] = 1605;

a[1] = 2378;

a[2] = 2815;

a[3] = 2815;

mpz_set_str(n, "198103", 10);

threeDotTwentyfive( a, arrayLength, n );

cout << "\n\nD)\n\n";


arrayLength = 5;

a[0] = 1591;

a[1] = 3182;

a[2] = 4773;

a[3] = 5275;

a[4] = 5401;

mpz_set_str(n, "2525891", 10);

threeDotTwentyfive( a, arrayLength, n );

cout << "\n\n\n3.26)\n\n" << endl;

cout << "\n\nA)\n\n";
sigh(25,3);

cout << "\n\nB\n\n";
sigh(35,5);

cout << "\n\nC)\n\n";
sigh(50,7);

cout << "\n\nD)\n\n";
sigh(100,5);

cout << "\n\nE)\n\n";
sigh(100,7);

cout << "\n\n\n3.28)\n\n\n";

cout << "\n\nA)\n\n";
threeDotTwentyeight(100);

cout << "\n\nB\n\n";
threeDotTwentyeight(250);

cout << "\n\nC)\n\n";
threeDotTwentyeight(350);

cout << "\n\nD)\n\n";
threeDotTwentyeight(500);

cout << "\n\nE)\n\n";
threeDotTwentyeight(750);

cout << "\n\nF)\n\n";
threeDotTwentyeight(1000);

cout << "\n\nG)\n\n";
threeDotTwentyeight(2000);

//return 0;

//cout << "\nTesting 3.33\n";


//threeDotThirtythree(221, 7, 15, 30);

//cout << "\nDone Testing 3.33\n";


mpz_t arg;

mpz_init( arg );

mpz_t modP;

mpz_init( modP );


mpz_set_str(arg, "116", 10);


mpz_set_str(modP, "587", 10);


threeDotThirtyeight(arg, modP);




mpz_set_str(arg, "3217", 10);


mpz_set_str(modP, "8627", 10);


threeDotThirtyeight(arg, modP);



mpz_set_str(arg, "9109", 10);


mpz_set_str(modP, "10663", 10);


threeDotThirtyeight(arg, modP);


return 0;

}
