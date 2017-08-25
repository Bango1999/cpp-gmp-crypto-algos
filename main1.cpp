/*
 * File:   main.cpp
 * Author: bango & joe f
 *
 * Created on June 1, 2014, 9:01 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <set>
#include <climits>
#include <gmp.h>

using namespace std;

    int oneDotTwelve(int a, int b, int& u , int& v){

        if( b == 0 ){
            u = 1;
            v = 0;
            return a;
        }
        if( a == 0 ){
            u = 0;
            v = 1;
            return b;
        }

        int g = a;
        u = 1;
        int x = 0;
        int y = b;
        int s = 0;
        int q = 0;
        int t = 0;

        while( y != 0 ){
            q = g / y;
            t = g % y;
            s = u - q*x;
            u = x;
            g = y;
            x = s;
            y = t;
        }
        if ( y ==0 )
            v = (g-a*u)/b;

     //   cout << "U : " << u << "  V : " << v << endl;
        return g;
    }

    // a = some number, b = the number of the mod or the "clock", u = aInverse, v = bInverse
    int oneDotTwelvePositiveU(int a, int b, int& u , int& v){

        if( b == 0 ){
            u = 1;
            v = 0;
            return a;
        }
        if( a == 0 ){
            u = 0;
            v = 1;
            return b;
        }

        int g = a;
        u = 1;
        int x = 0;
        int y = b;
        int s = 0;
        int q = 0;
        int t = 0;

        while( y != 0 ){
            q = g / y;
            t = g % y;
            s = u - q*x;
            u = x;
            g = y;
            x = s;
            y = t;
        }
        if ( y ==0 )
            v = (g-a*u)/b;
        cout << "U : " << u << "  V : " << v << endl;

        while ( u < 0 ){
            u = u + (b/g);
            v = v - (a/g);
            cout << "U : " << u << "  V : " << v << endl;
        }

      //  cout << "U : " << u << "  V : " << v << endl;
        return g;
    }


    int solveCongruences(int a, int b, int c, int d){
        int count = 0;
        int x = a;
        int y = c;
        set<int> possibleSolutions;
        pair<set<int>::iterator, bool> result;
        result =  possibleSolutions.insert(x);
            if(result.second != false)
                result = possibleSolutions.insert(y);
            else {
                cout << "count = " << count << endl;
                return x;

            }
       // cout << "x = " << x << " ; y = " << y << endl;
        while(result.second != false){
            x += b;
            count++;
            y += d;
         //   cout << "x = " << x << " ; y = " << y << endl;
            result = possibleSolutions.insert(x);
            if(result.second != false)
                result = possibleSolutions.insert(y);
            else {
                cout << "count = " << count << endl;
                return x;
            }
        }
        return y;



    }

    int solve3CongruencesLatest(int a, int b, int c, int d, int e, int f){

        int x = a;
        int y = c;
        int z = e;
        bool done = false;
        set<int> possibleSolutions;
        pair<set<int>::iterator, bool> result;

        do{
        result =  possibleSolutions.insert(x);
            if(result.second != false) {
                result = possibleSolutions.insert(y);
                       if(result.second != false) {
                                result = possibleSolutions.insert(z);
                                if(result.second == false) {
                                     if( c == z % d){
                                            if ( a == z % b )
                                                return z;
                                        }
                                }
                        }
                       else {
                           //condition of y failing to insert because the value already exists
                           if( a == y % b){
                                   if ( e == y % f )
                                        return y;
                           }
                       }
            }
            else {
                //code to check that x contains a value that satisfies y and z as well
                // variable containing the value that failed to insert: x
                if( c == x % d){
                    if ( e == x % f )
                        return x;
                }
            }
       // cout << "x = " << x << " ; y = " << y << endl;

            x += b;
            y += d;
            z += f;
            cout << "x = " << x << " ; y = " << y <<  " ; z = " << z <<endl;

        }while(done == false);
        return -1;
    }



//    int solveThreeCongruences(int a, int b, int c, int d, int e, int f){
//
//        int x = a;
//        int y = c;
//        int z = e;
//
//        //array[3] with values representing x, y, and its common denominator
//        //array[3] with values representing y, z, and its common denominator
//        //array[3] with values representing z, a, and its common denominator
//
//        //the first match between all 3 of them is the solution
//
//        int xyMatch[3], yzMatch[3], zaMatch[3];
//        bool matchFound = false;
//        while (!matchFound) {
//
//            if (x)
//
//
//            if (y)
//            if (z)
//            x += b;
//            if (x >= b) {
//             x -= b;
//            }
//            y += d;
//            if (y >= d) {
//                y -= b;
//            }
//            z += f;
//            if (z > f) {
//                z -= f;
//            }
//
//            //for (int i = 0; i < )
//            matchFound = true;
//        }
//
//
//
////        set<int> possibleSolutions;
////        pair<set<int>::iterator, bool> result;
////        result =  possibleSolutions.insert(x);
////        do {
////            if(result.second != false)
////                result = possibleSolutions.insert(y);
////            else
////                return x;
////            if(result.second != false)
////                result = possibleSolutions.insert(z);
////            else
////                return x;
////    } while(result.second != false);
////        return y;
//
//    }

    // returns x = g^A (mod N)
    int squareAndMultiply(int N, int g, int A){
        int a = g;
        int b = 1;
        while(A>0){
            if( 1 == A % 2)
                b = b * a % N;
            a = a * a;
            a = a % N;
            A = A/2;
        }
        return b;

    }

    long squareAndMultiplyLong(int N, int g, int A){
        long a = g;
        long b = 1;
        while(A>0){
            if( 1 == A % 2)
                b = b * a % N;
            a = a * a;
            a = a % N;
            A = A/2;
        }
        return b;

    }

    //check the return type first
    //number may be too large
    int oneDotThirtyFermat(int a, int p){
        return squareAndMultiply(p, a, p-2);
    }

    int cycleLength(int start, int clock){
        int result = start;
        int counter = 1;
        //
        //cout << result;
        while((result != 1) && (counter < clock)) {
            counter++;
          //  cout << ", ";
            result = (result * start ) % clock;
          //  cout << result;
            //cout << "clock:" << clock << " counter : " << counter << " result: " << result << " start : " << start <<endl;
        }
        //cout << "clock:" << clock << " counter : " << counter << " result: " << result <<endl;
        //cout << endl;
        return counter;
    }

    set<int> primitiveRoots(int clock){
        int cycleCount = 0;
        int rootsCount = 0;
        set<int> roots;
        for(int i = 2; i < clock; i++){
            cycleCount = cycleLength(i, clock);
            //cout << "cycleCount = " << cycleCount << "  i = " << i << endl;
            if( cycleCount == clock-1) {
                roots.insert(i);
                rootsCount++;
                cout << i << ",";
                //cout << i << " is a primitive root of mod(" << clock << endl;
            }
        }
        cout << endl;
        cout << rootsCount << "rootsCount\n";
        return roots;
    }

    // returns x from the equation g^x = arg (mod p)
    int twoDotFour(int g , int P, int arg){

        int x = INT_MAX;
        int ans = 1;
        int  i = 1;
        int temp;
        while( i < x ){
            ans = ans * g;
            temp = ans/P;
            ans = ans - (temp*P);

            if(ans == arg)
                x = i;

            i++;

        }

        cout << arg << " ( mod " << P << " ) = " << g<< "^" << x <<endl;

        return x;
    }

    void twoDotSix(){

        cout << " a = " << twoDotFour(2, 1373, 974 ) << endl;
        cout << " sharedSecret = " << squareAndMultiply(1373, 974, 871) << endl;

        cout << " B = " << squareAndMultiply(1373, 2, 871) << endl;

    }

    void twoDotEight(){
        int AtotheK = squareAndMultiply(1373, 177, 877);
        int A = squareAndMultiply(1373, 2, 947);
        cout << " A = " << A << endl;
        cout << " c1 = " << squareAndMultiply(1373, 2, 877) << endl;
        //cout << " A^k = " << AtotheK << endl;
        cout << " c2 = " << squareAndMultiply(1373, AtotheK * 583 , 1) << endl;
        //part c
        int x = squareAndMultiply(1373, 661, 299);
        cout << " x = " << x << endl;
        int xInverse, V;
        int gcd;
        //while(gcd != 1){
        gcd = oneDotTwelvePositiveU(x, 1373, xInverse, V);
        //}
        int m = squareAndMultiply(1373, 1325*xInverse, 1);
        cout << "m = " << m << endl;



        //part d
        int b = twoDotFour(2, 1373, 893);
        cout << "b = " << b << endl;
        x = squareAndMultiply(1373, 693, b);
        gcd = oneDotTwelvePositiveU(x, 1373, xInverse, V);
        m = squareAndMultiply(1373, 793*xInverse, 1);
        cout << "m = " << m << endl;
    }


    void twoDotTen(){
        int p = 32611;
        //Alice
        int m = 11111;
        int a = 3589;
        int u = squareAndMultiply(p, m, a);
        //Bob
        int b = 4037;
        int v = squareAndMultiply(p, u, b);
        //Alice
        int x = twoDotFour(u, p, v);
        cout << " x = b = " << x  << endl;
        //next line luckily produces 27257, but I think this is not the right way to do it.
        int w = squareAndMultiply(p, m, b);
        cout << " w = " << w  << endl;
        //Bob
        int y = twoDotFour(w, p, v);
        cout << " y = a = " << y  << endl;

        int xInverse, V;
        int gcd;

        gcd = oneDotTwelvePositiveU(b, p-1, xInverse, V);

        cout << " bInverse = " << xInverse  << endl;


        gcd = oneDotTwelvePositiveU(a, p-1, xInverse, V);

        cout << " aInverse = " << xInverse  << endl;


    }

    //originally found an implementation of Quick Sort at : http://www.algolist.net/Algorithms/Sorting/Quicksort
//and then modified it to move the associated original index stored in the list[n][1] position, as well
void quickSort(int arr[][2], int left, int right) {
      int i = left, j = right;
      int tmp, tmpIndex;
      int pivot = arr[(left + right) / 2][0];

      /* partition */
      while (i <= j) {
            while (arr[i][0] < pivot)
                  i++;
            while (arr[j][0] > pivot)
                  j--;
            if (i <= j) {

                  tmp = arr[i][0];
                  tmpIndex = arr[i][1];
                  arr[i][0]= arr[j][0];
                  arr[i][1]= arr[j][1];

                  arr[j][0] = tmp;
                  arr[j][1] = tmpIndex;

                  i++;
                  j--;

            }

      }
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}


    //2.17 Shank's baby step, giant step algorithm
    //returns x from the equation g^x = h mod G
    //solves the discrete log problem
    int shanks(int G, int g, int h) {

        //most recent change for g == h case
//        if( g == h )
//            return 1;

    int N = cycleLength(g,G);
    cout << "N = " << N << endl;
    int limit = 10;
    int n = 1 + floor(sqrt(N));
    int list1[n][2], list2[n][2];
    cout << "n = " << n << endl;

    int gInverse, V;
    int gcd = oneDotTwelvePositiveU(g,G,gInverse,V);
    int u = squareAndMultiply(G,gInverse,n);
    //cout << "u = " << u << endl;
    int neg = 0;
    for (int i = 0; i < n+1; i++) {
        if (i == 0) {
            list1[i][0] = 1;
            list2[i][0] = h % G;
            list1[i][1] = i;
            list2[i][1] = i;
        } else {
            neg = n - (2*n);
            int putMeIn = g;
            //cout << "putmein = " << putMeIn << endl;
            //for (int j = 0; j < i-1;j++) {
              //  putMeIn = putMeIn * g;
                //cout << "loop round " << j << " putmein = " << putMeIn << endl;
           //}
           putMeIn = squareAndMultiply(G,g,i);
            list1[i][0] = putMeIn % G;
            //cout << "putMeIn % G = " << list1[i] << endl;
            list2[i][0] = (h * squareAndMultiply(G,u,i)) % G;
          //  if (list1[i] == 14567) {
           //     cout << "list2[" << i << "] = 1159";
          //     return 0;
          //  }// else if (list2[i] == 1159) {
                //cout << "list1[" << i << "] = 1159" << endl;
               //return 0;
            list1[i][1] = i;
            list2[i][1] = i;


        }


    }

    quickSort(list1,0,n);
    quickSort(list2,0,n);

    int ii = 0;
    int jj = 0;
    while(list1[ii][0] != list2[jj][0]){
        while(list1[ii][0] < list2[jj][0]){
            ii++;
        }
        while(list1[ii][0] > list2[jj][0]){
            jj++;
        }


    }
    return (list1[ii][1]+list2[jj][1] *n);
    }
//
//   int shanks(int G, int g, int h){
//       int N = cycleLength(g,G);
//       cout << endl << "N = " << N << endl;
//       if(N < 2)
//           return 0;
//       int n = 1 + floor(sqrt(N));
//       cout << endl << "n = " << n << endl;
//
//
//
//
//
//       int gInverse, V;
//       int gcd = oneDotTwelvePositiveU(9704, 17389, gInverse, V);
//       cout << "g^-1 : " << gInverse << endl;
//       cout << "g^-n attempt : " << squareAndMultiply(17389, gInverse, 36) << endl;
//   }

//
//    int* primitiveRoots(int clock){
//        int cycleCount = 2;
//        int rootsCount = 5;
//        int roots[clock];
//        for(int i = 2; i < clock; i++){
//            //cycleCount = cycleLength(i, clock);
//            int ans = 0;
//            cycleCount = 2;
//            while (cycleCount < clock+2 && ans != 1) {
//
//                ans = (pow(i,cycleCount));
//                ans = ans % clock;
//                cout << ans << endl;
//                cycleCount++;
//            }
//            cout << "cycleCount = " << cycleCount-1 << endl;
//            if( cycleCount-1 == clock) {
//                roots[rootsCount++] = i;
//                cout << i << " is a primitive root of mod(" << clock << endl;
//            }
//        }
//
//        roots[0] = rootsCount;
//        cout << rootsCount << "rootsCount\n";
//        cout << roots[0] << "roots[0]\n";
//
//        int * ret = roots;
//        return ret;
//
//    }


    //pass in two arrays and the number of congruences ( n ) to solve
    // returns x = a[i] mod m[i] for n congruences
    int solveNCongruences(int a[], int m[], int n){
        int y;
        int inverse;
        int x;
        int runningClock = m[0];
        int v; //v is a throw away variable for the oneDotTwelvePositiveU function
        //I should update that function to just be aInverseModP and not use V


        //look here
        y = a[1] - a[0]; // should this line be mod-ed so that if we get a negative number for the argument, then we can loop it back around the clock to a positive value?
        //possible fuck up on the line above^^^



        v = oneDotTwelvePositiveU(m[0], m[1], inverse, v);

        // check here too
        y = (y * inverse) % m[1];//if y is negative then the mod operator will return complete bullshit answers that will need to be modified by +/- 1
        // need to check for negative values in all variables

        if( y <0 )
            y += m[1];//testing this fix


        cout << "y = " << y << endl;


        x = y*m[0] + a[0];
        cout << "x = " << x << endl;
        for(int i = 1; i < n-1; i++){
            x = x % m[i+1];
            y = a[i+1] - (x % m[i+1]);
            runningClock = runningClock * m[i];
             v = oneDotTwelvePositiveU(runningClock % m[i+1], m[i+1], inverse, v);
             y = (y * inverse) % m[i+1];
             cout << "y = " << y << endl;
             x = y*runningClock + x;
             cout << "x = " << x << endl;
        }

        return x;
    }

    bool check3mod4(int p){
        int check = p % 4;
        return check == 3;
    }

//    int clockDown(int a, int p){
//        return a % p;
//    }

    int findRootsModP(int a[], int p[],int n){

        //int bTemp;// = squareAndMultiply(p, a, (p+1/4));
        int b[n];
        for(int i = 1; i < n; i++){
            if( !check3mod4( p[i] ) )
                cout << "\n\n\n P IS NOT EQUAL TO 3 MOD 4 AND P = " << p[i] << endl << endl << endl;

            a[i] = a[0] % p[i];
            cout << " a[i] Just got built " << a[i] << endl;
            cout << " a[i] = " << a[i] << endl;
            cout << " p[i] = " << p[i] << endl;
            //cout << " p[i]+1/4 = " << (float)((( p[i])+1)/4) << endl;

            b[i] = squareAndMultiply(p[i], a[i], (    ( ( p[i] ) + 1 )  / 4 )    );
            cout << " b[i] = " << b[i] << endl;
        }

        cout << "\n\n\n";
        int tempArray[n-1];
        for(int i = 0; i < n-1; i++){
            tempArray[i] = b[i+1];
            cout << " b[i] = " << tempArray[i] << endl;

        }


        int tempArray2[n-1];
        for(int i = 0; i < n-1; i++){
            tempArray2[i] = p[i+1];
            cout << " p[i] = " << tempArray2[i] << endl;
        }

        int xCongruences = solveNCongruences(tempArray, tempArray2, n-1);

        //if ( xCongruences )


//        int test = squareAndMultiply(p[0], xCongruences, 2);
//        cout << " test = " << test << endl;
//        while(  a[0] != test ){
//            test += p[0];
//        }
//        for(int i = 0; i < 20 ; i++){
//                cout << endl << xCongruences << "is a root of " << a[0] << " mod " << p[0] << endl;
//                xCongruences += p[0];
//        }
        return xCongruences;

    }

	bool sieve(int arr[][2], int passedArr[2], int p) {
            //arr[0][0] holds arrayCount
                bool badFlag = false;
                for (int l = 3; l < (int)sqrt(p); l++) {
                    if (passedArr[0] != l && passedArr[0]%l == 0) {
                        //cout << passedArr[0] <<" is not prime in " << passedArr[0] << "," << passedArr[1] << endl;
                        //cout << "because " << passedArr[0] << " % " << l << " = " << passedArr[0]%l << endl;
                        badFlag=true;
                        break;
                    }
                    if (passedArr[1] != l && passedArr[1]%l == 0) {
                        cout << passedArr[1] <<" is not prime in " << passedArr[0] << "," << passedArr[1] << endl;
                        cout << "because " << passedArr[1] << " % " << l << " = " << passedArr[1]%l << endl;
                        badFlag=true;
                        break;
                    }
                }
                if (!badFlag) {
                    arr[1][0] = passedArr[0];
                    arr[1][1] = passedArr[1];
                    return true;
                }

        return false;
}

    bool decompose2Primes(int a, int p, int arr[][2], bool verbose) {
        int arrayCount = 2;
        bool tf,ft,sf,d = false;
        cout << "Please wait while exhaustive prime check is completed" << endl;
        for (int i = 3; i < p; i=i+2) {
            //cout << (float)i/p << endl;
            if (arrayCount >= 500) {break;}
            for (int j = 3; ((j < p) && (i+j < p/2)); j=j+2) {
                if (i * j == p) {
                    arr[arrayCount][0] = i;
                    arr[arrayCount][1] = j;
                    arrayCount++;

					int passMe[2] = {i,j};
                    if (sieve(arr, passMe, p)) {
						//cout << "matched " << i << "*" << j << " -- Adding to array at arr[" << arrayCount << "][0 & 1] respectively" << endl;
						arr[1][0] = i;
						arr[1][1] = j;

						//uncomment if you are ONLY interested in a single pair of prime composites (arr[1][0] & arr[1][1])
						//return true;
                    }
                }
            }
            if (verbose) {
                if ((float)i/p > 0.999 && !d) {
                    cout << "Done..." << endl;
                    d = true;
                } else if ((float)i/p > 0.25 && !sf) {
                    cout << "75% complete..." << endl;
                    sf = true;
                } else if ((float)i/p > 0.15 && !ft) {
                    cout << "50% complete..." << endl;
                    ft = true;
                } else if ((float)i/p > 0.08 && !tf) {
                    cout << "25% complete..." << endl;
                    tf = true;
                }
            }
        }

        arr[0][0] = arrayCount;
        arr[0][1] = arrayCount;


        if (arr[1][0] == 0 && arr[1][1] == 0) {
            return false;
        } else {
            return true;
        }
    }



    void printComposites(int arr[][2], bool has2Primes) {
        if (arr[0][0] == 0) {return;}
        int count = arr[0][0];
        if (!has2Primes) {
            count--;
        }
        for (int i = 0; i < arr[0][0]; i++) {
            //if (arr[i][0] == 2) {break;}
            if (i == 0) {
                cout << "This array has " << count << " values..." << endl;
            } else if (i == 1 && has2Primes) {
                cout << "Dual Composite Primes are " << arr[1][0] << " and " << arr[1][1] << endl;
            } else if (i != 1) {
                cout << arr[i][0] << " " << arr[i][1] << endl;
            }
        }
        return;
    }


    int rootOfAModP(int a, int p){
        int factorsOfP[p/2][2];
        int clockedArguments[p/2];
        int n;
        printComposites(factorsOfP,decompose2Primes(1, p, factorsOfP, false));
        clockedArguments[0] = a;
        n = factorsOfP[0][0];
        factorsOfP[0][0] = p;
        cout << "\n n = " << n << endl;
        int tempArray[p/2];
        for(int i = 0; i < n; i++){
            tempArray[i] = factorsOfP[i][0];

        }
        int returnNumber = findRootsModP(clockedArguments, tempArray, n);

        return returnNumber;

    }

    //returns x from the equation g^x = a mod p
    int pohligHellman(int g, int h, int p){
        int returnNum = 0;
        int orderOfg = cycleLength(g, p);
        cout << "The order of g is : " << orderOfg << endl;

        int factorsOfN[p/2][2];

        printComposites(factorsOfN,decompose2Primes(1, orderOfg, factorsOfN, false));
        int tempArray[p/2];
        int n = factorsOfN[0][0];
        int arrayOfg[n];
        int arrayOfh[n];
        int arrayOfY[n];
        for(int i = 0; i < n; i++){
            tempArray[i] = factorsOfN[i+1][0];
            arrayOfg[i] = squareAndMultiply(p, g, ( orderOfg / tempArray[i] ) );
            arrayOfh[i] = squareAndMultiply(p, h, ( orderOfg / tempArray[i] ) );
           // arrayOfY[i] = shanks(p, arrayOfg[i], arrayOfh[i] );
            cout << "g_" << i << " = " << arrayOfg[i] << endl;
            cout << "y_" << i << " = " << arrayOfY[i] << endl;
            cout << "h_" << i << " = " << arrayOfh[i] << endl;
        }
       // int x = solveNCongruences(arrayOfY, tempArray, n);

        //cout << "\n x = " << x << endl;

        return returnNum;
    }

     int threeDotOne(int e, int c, int N){
        cout << "\tn= " << N << endl;
        int x;
        int g;
        int factorsOfN[(int)N/2][2];
        int d, V;
        bool verbose = false;
        //initialize all elements to 0
        for (int i = 0; i < N/2; i++) {
            for (int j = 0; j < 2; j++) {
                factorsOfN[i][j] = 0;
            }
        }
        //if N is very big, show the completion rate when performing exhaustive prime checks
        if (N > 200000) {
            verbose = true;
        }
        cout << "\tn= " << N << endl;
        decompose2Primes(1, N, factorsOfN, verbose);
        int p = factorsOfN[0][1];
        cout << "(the count of elements in this array is ) p = " << p << endl;
        if( factorsOfN[1][0] == 0 ){
            p = N-1;
        }
        else
        {
            g = oneDotTwelvePositiveU((factorsOfN[1][0] - 1 ),(factorsOfN[1][1] - 1 ) , d, V);
            p = (factorsOfN[1][0] - 1 ) * (factorsOfN[1][1] - 1 ) / g;

        }


        cout << "p = " << p << endl;
        int temp = oneDotTwelvePositiveU(e, p, d, V);
        cout << "d = " << d << endl;
        cout << "c = " << c << endl;
        cout << "N = " << N << endl;
        long xx = squareAndMultiplyLong(N, c, d);

        cout << "\n x = " << xx << endl;



        return xx;

    }

    int getModX(int x, int mod, int e) {
        int base = 0;
        for (int i = 0; i < mod; i++) {
            if ((long)(i*e)%mod == x) {
                return i;
            }

        }
        return -1;
    }

    long threeDotSix(int e, int N, int arr[][2], int m) {
        //if (decompose2Primes(e,N,arr,true)) {
            int p = arr[1][0];
            int q = arr[1][1];
            cout << "keys published: e = " << e << ", p = " << p << ", q = " << q << endl;
            cout << "sender chooses message = " << m << endl;
            long c = squareAndMultiplyLong(N,m,e);
            cout << "encoded message = " << c << endl;

            //find d
            int d = 0;
            int other = 0;
            p = 1301;
            q = N / p;
            cout << "p = " << p << ", q = " << q << endl;
            long p1q1 = (p-1) * (q-1);
            int temp;
            temp = oneDotTwelvePositiveU(e,p1q1,d,temp);
            //d = getModX(1,N,e);
            cout << "d = " << d << endl;

            long message = squareAndMultiplyLong(N,c,d);
            cout << "decrypted message as " << message << endl;

            c = 317730;

            message = squareAndMultiplyLong(N,c,d);
            cout << "decrypted message as " << message << endl;

            return message;


       // } else {
      //      cout << "Could not factor prime composites on threeDotSix" << endl;
      //      return -1;
       // }

    }

    long threeDotSeven(int e, int N, int arr[][2], int c) {
        if (decompose2Primes(e,N,arr,false)) {
            int p = arr[1][0];
            int q = arr[1][1];
            cout << "keys published: e = " << e << ", p = " << p << ", q = " << q << endl;
            long p1q1 = (p-1) * (q-1);
            int temp;
            int d = 0;
            temp = oneDotTwelvePositiveU(e,p1q1,d,temp);
            //d = getModX(1,N,e);
            cout << "d = " << d << endl;

            long message = squareAndMultiplyLong(N,c,d);
            cout << "decrypted message as " << message << endl;

            return message;


        } else {
            cout << "Could not factor prime composites on threeDotSix" << endl;
            return -1;
        }

    }

    void clearArray(int arr[][2],int arrlen) {
        for (int i = 0; i < arrlen; i++) {
            arr[i][0] = arr[i][1] = 0;
        }
        return;
    }
    void printArray(int arr[][2], int arrlen) {
        for (int i = 0; i < arrlen; i++) {
            cout << arr[i][0] << " - " << arr[i][1] << endl;
        }
        return;
    }


/*
 *
 */
int main(int argc, char** argv) {


	int x, y = 1147;
	int arrlen = 500;
	int arr[arrlen][2];
	clearArray(arr,arrlen);

	//signed long int lngInt = 17;
	//mpz_t integ;
	//mpz_init(integ);

	//mpz_set_si(integ,lngInt);
//	cout << integ << endl;



    mpz_t a,b,p;
    mpz_inits(a,b,p,NULL);

    mpz_set_str(a, "1234", 10);
    mpz_set_str(b,"-5678", 10); //Decimal base

    mpz_add(p,a,b);

    cout<<"\nThe exact result is:";
    mpz_out_str(stdout, 10, p); //Stream, numerical base, var
    cout<<endl;

    mpz_abs(p, p);
    cout<<"The absolute value result is:";
    mpz_out_str(stdout, 10, p);
    cout<<endl;

    cin.get();
	return 0;

    //if you want to print the array you got, run printComposites.  If you just want the array quietly, call decompose2Primes
//    printComposites(arr,decompose2Primes(x,y,arr,false));

    //example
    //if (decompose2Primes(x,y,arr,false)) {
    //   cout << "Calling decompose" << endl;
    //}

    //problem 2.28

    //pohligHellman(5448, 6909, 11251);

    //problem 3.1

    cout << "\n example 3.3 \n ";
    x = threeDotOne(1583, 4714, 7919);


    cout << "\n problem 3.1.a \n ";
    x = threeDotOne(19, 36, 97);


    cout << "\n problem 3.1.b \n ";
    x = threeDotOne(137, 428, 541);


    cout << "\n problem 3.1.c \n ";
    x = threeDotOne(73, 614, 1159);


    cout << "\n problem 3.1.d \n ";
    x = threeDotOne(751, 677, 8023);


    cout << "\n problem 3.1.e \n ";
   //x = threeDotOne(38993, 328047, 401227);
    //cout << endl << squareAndMultiply(401227, x, 38993) + 401227 << endl;

    cout << "\n problem 3.6 \n ";
    int N = 2038667;
    int e = 103;
    int m = 1337;
    clearArray(arr,arrlen);
    x = threeDotSix(e,N,arr,m);

    cout << "\n problem 3.7 \n ";
    N = 12191;
    e = 37;
    int c = 587;
    clearArray(arr,arrlen);
    x = threeDotSeven(e,N,arr,c);

    cout << "\n problem 3.8 \n ";
    //long mods[8] = {352717,351520,77083921,77066212,109404161,109380612,172205490419,172204660344};
    //threeDotEight(arr,mods);


    return 0;
}
