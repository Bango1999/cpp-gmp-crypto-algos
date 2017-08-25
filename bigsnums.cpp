#include <cstdlib>
#include <iostream>
#include <cmath>
#include <set>
#include <climits>
#include <gmp.h>

using namespace std;

    int oneDotTwelve(int a, int b, int& u , int& v ){
        
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
       // cout << "U : " << u << "  V : " << v << endl;
        
        while ( u < 0 ){
            u = u + (b/g);
            v = v - (a/g);
         //   cout << "U : " << u << "  V : " << v << endl;
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
    
    //solves x == a mod b, x == c mod d, x == e mod f
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
    
    // returns x = g^A (mod N)
    long longSquareAndMultiply(int N, int g, int A){
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
        
        int y = a[1] - a[0];
        int inverse;
        int x;
        int runningClock = m[0];
        int v; //v is a throw away variable for the oneDotTwelvePositiveU function

        //displaying the work being done:
        cout << "x = " << a[0] << " + " << m[0] << " * y " << endl;
        cout << m[0] << " * y == " <<  y << " mod " << m[1] << endl;
        v = oneDotTwelvePositiveU(m[0], m[1], inverse, v);        
        cout << "Then multiply both sides by " << inverse << ", which is the inverse of " << m[0] << " mod " << m[1] << endl;
        y = (y * inverse) % m[1];
        
        if( y <0 )
            y += m[1];//this makes sure that y is a positive number
        
        cout << "So, y = " << y << endl;
        x = y*m[0] + a[0];
        cout << "And, x = " << x << endl;
        for(int i = 1; i < n-1; i++){  
            y = ( a[ i + 1 ] - ( x % m[ i + 1 ] )  ) ;
            
            if( y < 0 )
                    y += m[ i + 1 ];//makes sure that y is a positive number
        
            //cout << "y = " << y << endl;
            runningClock = runningClock * m[i];
            cout << "So the general solution for the first " << i+1<< " congruences is x = " << x << " + z * " << runningClock << endl;
            v = oneDotTwelvePositiveU(runningClock % m[i+1], m[i+1], inverse, v);
            y = (y * inverse) % m[i+1];
            cout << "Simplifying and multiplying both sides by the inverse of z's coefficient gives : ";
            cout << "z = " << y << endl; 
            x = y*runningClock + x;
            cout << "Substituting this value in for z, gives us x = " << x << endl;
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
            if( !check3mod4( p[i] ) ){
                cout << "\n\n\n P IS NOT EQUAL TO 3 MOD 4 AND P = " << p[i] << endl << endl << endl;
                a[i] = a[0] % p[i];
                int j = 1;
                do{
                    j++;
                    b[i] = squareAndMultiply(p[i], j, 2);
                    
                    cout << "\n j = " << j << "  , b[i] = " << b[i] << " , a[i] = " << a[i] << endl;
                }while( b[i] != a[i]);
                b[i] = j;
            }
            else{
            a[i] = a[0] % p[i];
            cout << " a[i] Just got built " << a[i] << endl;
            cout << " a[i] = " << a[i] << endl;
            cout << " p[i] = " << p[i] << endl;
            //cout << " p[i]+1/4 = " << (float)((( p[i])+1)/4) << endl;
           
            b[i] = squareAndMultiply(p[i], a[i], (    ( ( p[i] ) + 1 )  / 4 )    );
            cout << " b[i] = " << b[i] << endl;
            }
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
        cout << " One root is x = " << xCongruences << endl;
        cout << " Another root is x = " << xCongruences + p[0] << endl;
        
        for(int i = 0; i < n-1; i+=2){
            tempArray[i] = -1 * tempArray[i];
//            cout << " b[i] = " << tempArray[i] << endl;
            
        }
        
        xCongruences = solveNCongruences(tempArray, tempArray2, n-1);
        cout << " One root is x = " << xCongruences << endl;
        cout << " Another root is x = " << xCongruences + p[0] << endl;
        
        
        for(int i = 0; i < n-1; i++){
            tempArray[i] = -1 * tempArray[i];
//            cout << " b[i] = " << tempArray[i] << endl;
            
        }
        
        xCongruences = solveNCongruences(tempArray, tempArray2, n-1);
        cout << " One root is x = " << xCongruences << endl;
        cout << " Another root is x = " << (xCongruences + p[0]) << endl;
        
        
        for(int i = 0; i < n-1; i+=2){
            tempArray[i] = -1 * tempArray[i];
//            cout << " b[i] = " << tempArray[i] << endl;
            
        }
        
        xCongruences = solveNCongruences(tempArray, tempArray2, n-1);
        cout << " One root is x = " << xCongruences << endl;
        cout << " Another root is x = " << xCongruences + p[0] << endl;
        
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

    
    int compose(int a, int p, int arr[][2]) {
        int arrayCount = 1;
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
                if (arrayCount >= 100) {break;}
                if (i * j == p) {
                    arr[arrayCount][0] = i;
                    arr[arrayCount][1] = j;
                    arrayCount++;
                }
            }
        }
        arr[0][0] = arrayCount;
        arr[0][1] = arrayCount;
        cout << "exiting compose function\n";
    return 1;
    }
    
    
    
    
    
    int composeEvens(int a, int p, int arr[][2]) {
        int arrayCount = 1;
        for (int i = 2; i < p; i++) {
            for (int j = 2; j < p; j++) {
                if (arrayCount >= 100) {break;}
                if (i * j == p) {
                    arr[arrayCount][0] = i;
                    arr[arrayCount][1] = j;
                    arrayCount++;
                }
            }
        }
        arr[0][0] = arrayCount;
        arr[0][1] = arrayCount;
        cout << "exiting compose function\n";
    return 1;
    }
    
    void printComposites(int arr[][2]) {
        for (int i = 0; i < 100; i++) {
            if (arr[i][0] == 0) {break;}
            cout << arr[i][0] << " " << arr[i][1] << endl;
        }
    }
    
    int rootOfAModP(int a, int p){
        int factorsOfP[p/2][2]; 
        int clockedArguments[p/2];
        int n;
        int one = composeEvens(1, p, factorsOfP);
        clockedArguments[0] = a;
        n = factorsOfP[0][0];
        factorsOfP[0][0] = p;
        printComposites( factorsOfP );
        cout << "\n n = " << n << endl;
        int tempArray[p/2];
        for(int i = 0; i < n; i++){
            tempArray[i] = factorsOfP[i][0];
            
        }
        int returnNumber = findRootsModP(clockedArguments, tempArray, n);
        
        return returnNumber;
        
    }
    
    
    //returns x from the equation x^e == c (mod N)
    int threeDotOne(int e, int c, int N){
        
        int g;
        int factorsOfN[N/2][2]; 
        int d, V;
        int one = composeEvens(1, N, factorsOfN);
        printComposites(factorsOfN);
        int p = factorsOfN[0][1];
        cout << "(the count of elements in this array is ) p = " << p << endl;
        if( p == 1 ){
            p = N-1;
        }
        else
        {
            g = oneDotTwelvePositiveU((factorsOfN[1][0] - 1 ),(factorsOfN[1][1] - 1 ) , d, V);
            p = (factorsOfN[1][0] - 1 ) * (factorsOfN[1][1] - 1 ) / g;
        
        }
        
       
        cout << "p = " << p << endl;
        one = oneDotTwelvePositiveU(e, p, d, V);
        cout << "d = " << d << endl;
        cout << "c = " << c << endl;
        cout << "N = " << N << endl;
        int x = squareAndMultiply(N, c, d);
        
        cout << "\n x = " << x << endl;
        
        
        
        return x;
        
    }
    
    int totient(int N){
        int count=0;
        int U, V;
        int gcd;
        for(int i = 1;i <= N; i++ ){
            gcd = oneDotTwelve(i, N, U, V);
            if(gcd == 1){
                count++;
            }
        }
        return count;
    }
    
    
    
    //returns x from the equation x^e == c (mod N)
    long threeDotFive(int e, int c, int N){
        
        int g;
        int factorsOfN[N/2][2]; 
        int d, V;
	cout << "got here" << endl;
        g = oneDotTwelvePositiveU(e,totient(N) , d, V);
        
        //the following line uses The Extended Euclidean Algorithm to compute the inverse of e mod p
        //one = oneDotTwelvePositiveU(e, p, d, V);
        cout << "d = " << d << endl;
        cout << "c = " << c << endl;
        cout << "N = " << N << endl;
        long x = longSquareAndMultiply(N, c, d);
        
        cout << "\n x = " << x << endl;
        
        
        
        return x;
        
    }
    
    //returns x from the equation g^x = a mod p
    int pohligHellman(int g, int h, int p){
        int returnNum = 0;
        int orderOfg = cycleLength(g, p);
        cout << "The order of g is : " << orderOfg << endl;
        
        int factorsOfN[p/2][2]; 
       
        int one = compose(1, orderOfg, factorsOfN);
        printComposites(factorsOfN);
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

    
    
   
    
    void threeDotEight(mpz_t N, mpz_t p1q1, mpz_t p, mpz_t q){
        mpz_t pPlusQ;
	mpz_init( pPlusQ );
	mpz_add_ui(pPlusQ,N,1);
	mpz_sub(pPlusQ,pPlusQ,p1q1);

	//mpz_set(p, quadraticFormula(1, pPlusQ, p1q1, q));
        cout << "pPlusQ = ";
	mpz_out_str(stdout,10,pPlusQ);
	cout << endl;

       mpz_t fourac;
       mpz_init( fourac );
       mpz_mul_ui( fourac, N, 4);
	       

	cout << "fourac = ";
	mpz_out_str(stdout,10,fourac);
	cout << endl;
       mpz_t radical;
       mpz_init( radical );
       mpz_mul( radical, pPlusQ, pPlusQ );
       
       mpz_sub( radical, radical, fourac );
       cout << "radical before sqrt = ";
	mpz_out_str(stdout,10,radical);
	cout << endl;
       mpz_sqrt( radical, radical );
	cout << "radical after sqrt = ";
	mpz_out_str(stdout,10,radical);
	cout << endl;

	mpz_mod(radical,radical,N);

	cout << "radical after sqrt and modded = ";
	mpz_out_str(stdout,10,radical);
	cout << endl;
       
       // p = 
        //x = ((-1 * b) + radical) / ( 2 * a);
        mpz_mul_si(p, pPlusQ, -1);
        mpz_add(p,p,radical);
        mpz_div_ui(p,p,2);
        
        // q = 
        //otherX = ((-1 * b) - radical) / ( 2 * a);
        mpz_mul_si(q, pPlusQ, -1);
        mpz_sub(q,q,radical);
        mpz_div_ui(q,q,2);

	

        cout << "p = ";
	mpz_out_str(stdout,10,p);
	cout << " q = ";
	mpz_out_str(stdout,10,q);
	cout << endl;
        
        return;
    }
    
    // functions for hw5
    
    
//    
//    //start of mpz code that was most recently commented out
//     // a = some number, b = the number of the mod or the "clock", u = aInverse, v = bInverse
//    mpz_t extendedEuclideanPositiveU(mpz_t a, mpz_t b, mpz_t& u , mpz_t& v){
//        
//        if( b == 0 ){
//            u = 1;
//            v = 0;
//            return a;
//        }
//        if( a == 0 ){
//            u = 0;
//            v = 1;
//            return b;
//        } 
//        
//        mpz_t g = a;
//        u = 1;
//        mpz_t x = 0;
//        mpz_t y = b;
//        mpz_t s = 0;
//        mpz_t q = 0;
//        mpz_t t = 0;
//        
//        while( y != 0 ){
//            q = g / y;
//            t = g % y;
//            s = u - q*x;
//            u = x;
//            g = y;
//            x = s;
//            y = t;
//        }
//        if ( y ==0 )
//            v = (g-a*u)/b;
//        cout << "U : " << u << "  V : " << v << endl;
//        
//        while ( u < 0 ){
//            u = u + (b/g);
//            v = v - (a/g);
//            cout << "U : " << u << "  V : " << v << endl;
//        }
//        
//      //  cout << "U : " << u << "  V : " << v << endl;
//        return g;
//    }
//    
   void threeDotTwelve(){
         
//        N = 1889570071
//e1 = 1021763679
//e2 = 519424709
//
//c1 = 1244183534
//c2 = 732959706
      cout << "Problem 3.12)" << endl;
       mpz_t N;
       mpz_init_set_str(N, "1889570071", 10);
       mpz_t e1;
       mpz_init_set_str(e1, "1021763679", 10);
       mpz_t e2;
       mpz_init_set_str(e2, "519424709", 10);
       mpz_t c1;
       mpz_init_set_str(c1, "1244183534", 10);
       mpz_t c2;
       mpz_init_set_str(c2, "732959706", 10);
       
       mpz_t g;
       mpz_init(g);
       mpz_t u;
       mpz_init(u);
       mpz_t v;
       mpz_init(v);
       mpz_t res1;
       mpz_init(res1);
       mpz_t res2;
       mpz_init(res2);
       mpz_t m;
       mpz_init(m);
       
       mpz_gcdext(g,u,v,e1,e2);
       mpz_powm(res1, c1, u, N);
       mpz_powm(res2, c2, v, N);
       mpz_mul(m, res1, res2);
       
       
       cout << "\n m = ";
       mpz_out_str(stdout, 10, m);
       cout << endl;
//      
       
       return;
   }
//    
//    mpz_t gcd(mpz_t a, mpz_t b){
//        mpz_t aInverse, bInverse;
//        mpz_init(aInverse);
//        mpz_init(bInverse);
//        return extendedEuclideanPositiveU(a,b,aInverse,bInverse);
//    }
//    
//    // returns x = g^A (mod N)
//    mpz_t mpSquareAndMultiply(mpz_t N, mpz_t g, mpz_t A){
//        mpz_t a = g;
//        mpz_t b = 1;
//        while(A>0){
//            if( 1 == A % 2)
//                b = b * a % N;
//            a = a * a;
//            a = a % N;
//            A = A/2;
//        }
//        return b;
//        
//    }
//    
//    
//    void setValueAndCout(mpz_t testNumber, int input){
//        mpz_set_si(testNumber, input);
//        
//        
//        
//        return;
//    }
//    
//    void getKandQ(mpz_t n, mpz_t& k, mpz_t &q){
//        mpz_t nMinusOne;
//        mpz_init(nMinusOne);
//        mpz_init(k);
//        mpz_init(q);
//        mpz_sub_ui(nMinusOne, n, 1);
//        
//        //unsigned long int mpz_mod_ui (mpz t r, const mpz t n, unsigned long int d)
//        //mpz_mod_ui(q, nMinusOne, 2);
//        
//        do{
//            mpz_mod_ui(q, nMinusOne, 2);
//            //if( mpz_cmp_ui(q, 0 ) != 0 )
//                mpz_add_ui( k, k, 1 );
//        
//        }while( mpz_cmp_ui(q, 0 ) != 0 );
//        
//        
//        return;
//        
//    }
//    
////    //none working backup
////    bool millerRabin(mpz_t numberInQuestion, mpz_t possibleWitness){
//////        mpz_t returnNumber;
//////        mpz_init (returnNumber);
////        
//////        bool composite = true;
//////        if numberInQuestion is even or 1 < gcd(possibleWitness, numberInQuestion) < numberInQuestion, return true //true = composite
//////                solve numberInQuestion - 1 = ( 2^k ) * q // q must be odd
//////                possibleWitness = possibleWitness^q mod numberInQuestion
//////                if possibleWitness  is congruent to 1 mod numberInQuestion 
//////                 composite = true
//////                        return !composite //false
//////                        for(int i =0, i < k; i++){
//////                            if possibleWitness is congruent to -1 mod numberInQuestion
//////                                return !composite;
//////                                possibleWitness = possibleWitness^2 mod numberInQuestion; // 
//////                        }
//////                        
//////        return true; // composite = true
////                        
////        //bool isComposite = 1; //true
////        bool composite = true;
////        mpz_t g;
////        mpz_init (g);
////        mpz_gcd(g, possibleWitness, numberInQuestion);
////        //if numberInQuestion is even or 1 < gcd(possibleWitness, numberInQuestion) < numberInQuestion, return true //true = composite
////        if( (mpz_divisible_p(numberInQuestion, 2) != 0  ) || ((mpz_cmp_si( g, 1) > 0) && (mpz_cmp(g , numberInQuestion) < 0)))
////                return composite; // composite = true
////        //solve numberInQuestion - 1 = ( 2^k ) * q // q must be odd
////        mpz_t nMinusOne;
////        mpz_init( nMinusOne );
////        mpz_sub_ui( nMinusOne, numberInQuestion, 1);
////        unsigned long b = 1;
////        while( mpz_divisble_2exp_p(nMinsOne,b) > 0 ){
////            b++;
////        }
////        b--;
////        mpz_z d;
////        mpz_init( d );
////        mpz_z q;
////        mpz_init( q );
////        mpz_powm(d, 2, b , numberInQuestion);
////        mpz_divexact(q, nMinusOne, d );
////        
////        //possibleWitness = possibleWitness^q mod numberInQuestion
////        mpz_powm(possibleWitness, possibleWitness, q, numberInQuestion);
////        
////        
//////        if possibleWitness  is congruent to 1 mod numberInQuestion 
//////                 composite = true
//////                        return !composite //false
//////        
////        
////        if ( mpz_congruent_ui_p(possibleWitness, 1, numberInQuestion  ) > 0 )
////            return !composite; // return false because composite = true
////        mpz_t negOne;
////        mpz_init_set_str(negOne, "-1", 10);
////        
////        unsigned long i = 0;
////        //for(int i =0, i < k; i++){
////        while( i < b ){
////                //if possibleWitness is congruent to -1 mod numberInQuestion
////            if( mpz_congruent_p(possibleWitness, negOne, numberInQuestion  ) > 0 )
////                        return !composite;
////            //possibleWitness = possibleWitness^2 mod numberInQuestion; // 
////            mpz_powm_ui(possibleWitness, possibleWitness, 2, numberInQuestion);
////        }
////                        
////        return true; // composite = true
//////  
////    }
//    
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

    // end of mpz code that was most recently commented out


//
//int main(int argc, char** argv) {
//	mpz_t testNumber;
//	mpz_init(testNumber);
//	mpz_set_si(testNumber, 9995);
//
//cout << "\nDone\n";
//
//
//
//	mpz_t n;
//	mpz_init_set_str(n, "1105" ,10);
//	mpz_t a;
//	mpz_init_set_str(a, "5", 10);
//	bool composite = millerRabin(n,a);
//	if( composite ) 
//	cout << "\n5 divides 1105\n";
//	else
//	cout << "\n5 does not  divide 1105\n";
//	
//
//
//return 0;
//}

    
    void pollards(mpz_t d, mpz_t N) {
     mpz_t a;
     mpz_init_set_str(a,"2",10);
     mpz_t j;
     mpz_init_set_str(j,"2",10);
     mpz_t sqrtN;
     mpz_sqrt(sqrtN,N);
     

       mpz_t aMinusOne;
       mpz_init(aMinusOne);
     
     
     while (mpz_cmp(j,sqrtN)<0) {
      
       mpz_powm(a,a,j,N);
       
       mpz_sub_ui(aMinusOne, a, 1);
       mpz_gcd(d,aMinusOne,N);
       
       if ( ( mpz_cmp_ui(d,1) > 0 ) && ( mpz_cmp(d,N) < 0 ) ) {
	 mpz_out_str(stdout,10,d);
	 cout << " = p and ";
 	 mpz_div(d,N,d);
	 mpz_out_str(stdout,10,d);
	 cout << " = q as factors of ";
	 mpz_out_str(stdout,10,N);
	 cout << endl;
	 return;
       }

       mpz_add_ui(j,j,1);
       
     }
     return;
    }
    
    
    
    void threeDotSeventeen(int x){
     int count = 4;
     int countOneModFour = 1;
     int countThreeModFour = 2;
     bool isComposite = false;
     int list[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
     mpz_t check;
     mpz_init( check );
     mpz_t a;
     mpz_init( a );
     mpz_t modResult;
     mpz_init( modResult );
     int j = 2;
     
    // int primes[x];
     
    // for(int i = 0; i < x; i++){
    //     primes[i] = 0;
    // }
    // primes[0] = 2;
    // primes[1] = 3;
    // primes[2] = 5;
    // primes[3] = 7;
     
     
     
     for(int i = 11; i < x+1; i+=2){
         //millerRabin(numberInQuestion, possibleWitness)
         mpz_set_si( check, i );
         
         mpz_set_si( a, j );
                isComposite = millerRabin(check, a);
                j++;
                if( isComposite )
                    j = x;

		if(i%1000 == 1 )
		    cout << "On the number " << i << endl;
         
         while(( j < i ) && (j < x)){
                mpz_set_si( a, j );
                isComposite = millerRabin(check, a);
                j++;
                if( isComposite )
                    j = x;
         }
         j=2;
//         
//         while(( list[j] < i ) && (j < 10)){
//                mpz_set_si( a, list[j] );
//                isComposite = millerRabin(check, a);
//                j++;
//                if( isComposite )
//                    j = 10;
//         }
//         j=0;
         if( !isComposite ){
    //         primes[count] = i;
             count++;
             mpz_mod_ui( modResult, check, 4 );
             if( mpz_cmp_ui(modResult, 1) == 0 )
                 countOneModFour++;
             if( mpz_cmp_ui(modResult, 3) == 0 )
                 countThreeModFour++;
             
        }
     }
    // cout << "The primes that were found are : ";
    // for(int m = 0; m<count; m++){
    //     cout << primes[m] << ", ";
    // }
    // cout << endl;
     cout << " There are " << count << " total primes less than " << x << endl;
     cout << " There are " << countOneModFour << " total primes equal to 1 mod 4 that are less than " << x << endl;
     cout << " There are " << countThreeModFour << " total primes equal to 3 mod 4 that are less than " << x << endl;
      cout << "The ratio of pi_3 / pi_1 = " << countThreeModFour / countOneModFour << endl;
     return;
 }
 
 void threeDotFourteen(mpz_t n){
cout << "\n problem 3.14 \n";        
        mpz_t a;
int list[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
mpz_init_set_str(a, "2", 10);
cout << "\n before miller-rabin \n";
bool composite = millerRabin(n,a);
cout  << "\n after miller-rabin \n";

        if( composite ) {
                 mpz_out_str(stdout, 10, a) ;
cout << " is a witness for the compositeness of ";
                 mpz_out_str(stdout, 10, n);
                 cout << endl;
        }
else
        {
                mpz_out_str(stdout, 10, a) ;
cout << " is NOT a witness for the compositeness of ";
                 mpz_out_str(stdout, 10, n);
                 cout << endl;
        }
        int i = 0;
cout << "\n before while loop \n";

        while(( i < 9 ) && (composite == false)){
cout << "\n during while loop \n";

            i++;
mpz_set_si(a, list[i]);
            //mpz_add_ui(a, a, 1);
        composite = millerRabin(n,a);
if( composite ) {
                 mpz_out_str(stdout, 10, a) ;
cout << " is a witness for the compositeness of ";
                 mpz_out_str(stdout, 10, n);
                 cout << endl;
        }
else
        {
                mpz_out_str(stdout, 10, a) ;
cout << " does not divide ";
                 mpz_out_str(stdout, 10, n);
                 cout << endl;
        }
        }
cout << "\n after while loop \n";

        return;
    }

 
 
 
 long threeDotSix(int e, int N, int arr[][2], int m) {
        //if (decompose2Primes(e,N,arr,true)) {
            int p = arr[1][0];
            int q = arr[1][1];
            cout << "keys published: e = " << e << ", p = " << p << ", q = " << q << endl;
            cout << "sender chooses message = " << m << endl;
            long c = longSquareAndMultiply(N,m,e);
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

            long message = longSquareAndMultiply(N,c,d);
            cout << "decrypted message as " << message << endl;

            c = 317730;

            message = longSquareAndMultiply(N,c,d);
            cout << "decrypted message as " << message << endl;

            return message;


       // } else {
      //      cout << "Could not factor prime composites on threeDotSix" << endl;
      //      return -1;
       // }

    }

    long threeDotSeven(int e, int N, int arr[][2], int c) {
        int temp = compose(e,N,arr);
            int p = arr[1][0];
            int q = arr[1][1];
	    printComposites(arr);
            //cout << "keys published: e = " << e << ", p = " << p << ", q = " << q << endl;
            long p1q1 = (p-1) * (q-1);
            int d = 0;
            temp = oneDotTwelvePositiveU(e,p1q1,d,temp);
            //d = getModX(1,N,e);
            cout << "d = " << d << endl;

            long message = longSquareAndMultiply(N,c,d);
            cout << "decrypted message as " << message << endl;

            return message;

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

   // int A, B , G, U, V;
        
//        A = 2024;
//        B = 748;
//        
//        G = oneDotTwelve(A,B,U,V);
//        
//        cout << "The gcd of " << A << " and " << B << " is : " << G << endl;
//        cout << "U : " << U << "  V : " << V << endl ;
//    
//        
//        A = 2024;
//        B = 0;
//        
//        G = oneDotTwelve(A,B,U,V);
//        
//        cout << "The gcd of " << A << " and " << B << " is : " << G << endl;
//        cout << "U : " << U << "  V : " << V << endl;
//    
//        
//        A = 527;
//        B = 1258;
//        
//        G = oneDotTwelvePositiveU(A,B,U,V);
//        
//        cout << "The gcd of " << A << " and " << B << " is : " << G << endl;
//        cout << "U : " << U << "  V : " << V << endl;
//    
//        
//        A = 228;
//        B = 1056;
//        
//        G = oneDotTwelvePositiveU(A,B,U,V);
//        
//        cout << "The gcd of " << A << " and " << B << " is : " << G << endl;
//        cout << "U : " << U << "  V : " << V << endl;
//    
//        
//        A = 163961;
//        B = 167181;
//        
//        G = oneDotTwelve(A,B,U,V);
//        
//        cout << "The gcd of " << A << " and " << B << " is : " << G << endl;
//        cout << "U : " << U << "  V : " << V << endl;
//    
//        A = 3892394;
//        B = 239847;
//        
//        G = oneDotTwelve(A,B,U,V);
//        
//        cout << "The gcd of " << A << " and " << B << " is : " << G << endl;
//        cout << "U : " << U << "  V : " << V << endl;
//    
//        
//        //testing solveCongruences
//        //for problem 1.23
//        A = 3;
//        B = 7;
//        int C = 4;
//        int D = 9;
//        int x = solveCongruences(A,B,C,D);
//        
//        cout << A << " (mod " << B << " ) = " << x << " = " << C << " (mod " << D << " )" << endl;
//        
//        
//        A = 13;
//        B = 71;
//         C = 41;
//         D = 97;
//         x = solveCongruences(A,B,C,D);
//        
//        cout << A << " (mod " << B << " ) = " << x << " = " << C << " (mod " << D << " )" << endl;
//        
//        A = 3;
//        B = 7;
//         C = 4;
//         D = 9;
//         int E = 0;
//         int F = 11;
//         x = solve3CongruencesLatest(A,B,C,D,E, F);
//        
//        cout << A << " (mod " << B << " ) = " << x << " = " << C << " (mod " << D << " )" << endl;
//        
//        A = 4;
//        B = 7;
//         C = 5;
//         D = 8;
//         E = 11;
//         F = 15;
//         x = solve3CongruencesLatest(A,B,C,D,E, F);
//        
//        cout << A << " (mod " << B << " ) = " << x << " = " << C << " (mod " << D << " )" << endl;
//        
//        int N = 256;
//        int g = 17;
//        A = 183;
//        int b = squareAndMultiply(N,g, A);
//        
//        cout << "b is : " << b << endl;
//        
//        N = 1000;
//        g = 2;
//        A = 477;
//        b = squareAndMultiply(N,g, A);
//        
//        cout << "b is : " << b << endl;
//        
//        N = 1237;
//        g = 11;
//        A = 507;
//        b = squareAndMultiply(N,g, A);
//        
//        cout << "b is : " << b << endl;
//        
//        
//        
//        int a = 11;
//        int p = 47;
//        int aInverse = oneDotThirtyFermat(a,p);
//        
//        cout << "aInverse = " << aInverse << endl;
//        
//        
//        A = 11;
//        B = 47;
//        U= 0;
//        V= 0;
//        
//        int gcdOfOne = oneDotTwelvePositiveU(A,B,U,V);
//        
//        while( gcdOfOne != 1){
//            gcdOfOne = oneDotTwelvePositiveU(A,B,U,V);
//        }
//       
//        cout << "U = " << U << " = A-1 when A = " << A << endl;
//        
//        
//        a=A=345;
//        p=B=587;
//        U= 0;
//        V= 0;
//        
//        aInverse = oneDotThirtyFermat(a,p);
//        
//        cout << "aInverse = " << aInverse << endl;
//        
//        
//        gcdOfOne = oneDotTwelve(A,B,U,V);
//        
//        while( gcdOfOne != 1){
//            gcdOfOne = oneDotTwelve(A,B,U,V);
//        }
//       
//        cout << "U = " << U << " = A-1 when A = " << A << endl;
//        
//        a=A=78467;
//        p=B=104801;
//        U= 0;
//        V= 0;
//        
//        aInverse = oneDotThirtyFermat(a,p);
//        
//        cout << "aInverse = " << aInverse << endl;
//        
//        
//        gcdOfOne = oneDotTwelve(A,B,U,V);
//        
//        while( gcdOfOne != 1){
//            gcdOfOne = oneDotTwelve(A,B,U,V);
//        }
//       
//        cout << "U = " << U << " = A-1 when A = " << A << endl;
//        
//        
//        
//        int modP = 7;
////
//        set<int> generators = primitiveRoots(modP);
//        
//        
//         modP = 13;
//
//         generators = primitiveRoots(modP);
//        
//         modP = 19;
//
//         generators = primitiveRoots(modP);
//        
//        modP = 23;
//
//         generators = primitiveRoots(modP);
//        
//         modP = 5;
//
//         generators = primitiveRoots(modP);
//        
//         modP = 11;
//
//         generators = primitiveRoots(modP);
//        
//         modP = 17;
//
//         generators = primitiveRoots(modP);
//        
//         modP = 29;
//
//         generators = primitiveRoots(modP);
//        
//         modP = 41;
//
//         generators = primitiveRoots(modP);
//        
//         modP = 43;
//
//         generators = primitiveRoots(modP);
//        
//         modP = 11;
//
//         generators = primitiveRoots(modP);
//         
//         modP = 229;
//
//         generators = primitiveRoots(modP);
//         
//    cout << "\n\n2.4 : \n";
//         int base = 2;
//         int argument = 13;
//         int prime = 23;
//         int exponent = twoDotFour(base, prime, argument);
//        
//         
//         base = 10;
//          argument = 22;
//          prime = 47;
//          exponent = twoDotFour(base, prime, argument);
//         
//          base = 627;
//          argument = 608;
//          prime = 941;
//          exponent = twoDotFour(base, prime, argument);
//    cout << "\n\n2.6 : \n";    
//          twoDotSix();
//          cout << "\n\n2.8 : \n";
//          twoDotEight();
//          cout << "\n\n2.10 : \n";
//          twoDotTen();
          //2.6
          
         
//        int * generators = new int[modP];
//        generators = primitiveRoots(modP);
//        for (int i = 0; i < modP; i++) {
//            
//            cout << "generators[i] = " << generators[i] << endl;
//            
//        }
//        int numGenerators = (generators[0]);
//        cout << "numGenerators = " << numGenerators << endl;
//        int xx;
//        cin >> xx;
        
//        cout << "Primitive roots of mod " << modP << endl;
//        for(int i = 1; i < numGenerators; i++){
//            //cout << "*generators[0] " << *generators[0] << endl;
//            cout << "generators[0] " << (generators[0]) << endl;
//            
//            cout << "numGenerators " << numGenerators << endl;
//            cout << "i = " << i << endl;
//            cout << "generators[i] " << (generators[i]) << endl;
//        }
        
         
//         int start1 = 3;
//         int clock1 = 5;
//         int start2 = 7;
//         int clock2 = 10;
//         int soln = solveCongruences(start1, clock1, start2, clock2);
//         
//         cout << soln << endl;
//         
//         int result =  shanks(71, 11, 21);
//          cout << "21 ( mod 71 ) = 11^" << result <<endl;
//          
//         result =  shanks(593, 156, 116);
//         cout << "116 ( mod 593 ) = 156^" << result <<endl;
//         
//         result =  shanks(3571, 650, 2213);
//         cout << "2213 ( mod 3571 ) = 650^" << result <<endl;
//         
//         
//         int xInverse, VV;
//        int gcd;
//      
//        gcd = oneDotTwelvePositiveU(3, 8, xInverse, VV);
//      
//        cout << " eInverse = " << xInverse  << endl;
        
/*    
    start of HW3
   problem 2.18
    
    part a
	cout << "Problem 2.18)" << endl;
     cout << endl << " part a " << endl;
        int n = 2;
        int a[3] = {3, 4, 0};
        int m[3] = {7, 9, 0};
        int congruence = solveNCongruences(a,m,n);
        cout << "x = " << congruence <<endl;
        cout << "x + 437 = " << congruence+437 <<endl;
    
        part b
         cout << endl << " part b " << endl;
         n = 2;
         a[0] = 137;
         a[1] = 87;
         m[0] = 423;
         m[1] = 191;
         congruence = solveNCongruences(a,m,n);
        cout << "x = " << congruence <<endl;
        
        
        part c - no solution because 451 and 697 are not relatively prime.  GCD = 41
         cout << endl << " part c " << endl;
        n = 2;
         a[0] = 133;
         a[1] = 237;
         m[0] = 451;
         m[1] = 697;
         congruence = solveNCongruences(a,m,n);
        cout << "x = " << congruence <<endl;
        
        int U, V;
        int gcd = oneDotTwelvePositiveU(m[0], m[1], U, V);
        cout << "gcd = " << gcd <<endl;


        part d
        cout << endl << " part d " << endl;
         n = 3;
         a[0] = 5;
         a[1] = 6;
         a[2] = 7;
         m[0] = 9;
         m[1] = 10;
         m[2] = 11;
         congruence = solveNCongruences(a,m,n);
        cout << "x = " << congruence <<endl;


 part e
        cout << endl << " part e " << endl;
         n = 3;
         a[0] = 37;
         a[1] = 22;
         a[2] =18;
         m[0] = 43;
         m[1] = 49;
         m[2] = 71;
         congruence = solveNCongruences(a,m,n);
        cout << "x = " << congruence <<endl;

   end of problem 2.18     
        
        example 2.26
        
        
        cout << endl << " example 2.26 " << endl;
         n = 3;
         a[0] = 2;
         a[1] = 3;
         a[2] = 4;
         m[0] = 3;
         m[1] = 7;
         m[2] = 16;
        cout << "m[0] = " << m[0] << endl;
       cout << "a[0] = " << a[0] << endl;
       
         congruence = solveNCongruences(a,m,n);
        cout << "x = " << congruence <<endl;

        
    problem 2.23
    
    part a
    cout << "Problem 2.23)" << endl;
    cout << "a)" << endl;
    cout << " calling  rootOfAModP(340, 437)" << endl;
    int x = rootOfAModP(340, 437);
        
    
    part b
    cout << "b)" << endl;
    cout << " calling  rootOfAModP(253, 3143)" << endl;
     x = rootOfAModP(253, 3143);
     
    part c
    cout << "c)" << endl;
    cout << " calling  rootOfAModP(253, 3143)" << endl;
     x = rootOfAModP(2833, 4189);
    
     pard d
     cout << "d)"<<endl;
     n = 4;
     int arg[4];
     arg[0] = 813;
     int tempArray[4] = {868,2,7,31};
     x = findRootsModP(arg,tempArray,n);
     cout << " calling  rootOfAModP(197, 437)" << endl;
     x = rootOfAModP(813, 868);
     
     
     cout << "pollard example" << endl;
     mpz_t gcd1;
     mpz_init(gcd1);
     mpz_t N1;
     mpz_init_set_str(N1,"13927189",10);
     //pollards(gcd1,N1);
     cout << "Problem 3.21" << endl;
     cout << "a)" << endl;
     mpz_set_str(N1,"1739",10);
     pollards(gcd1,N1);
     
     cout << "b)" << endl;
     mpz_set_str(N1,"220459",10);
     pollards(gcd1,N1);
     
     cout << "c)" << endl;
     mpz_set_str(N1,"48356747",10);
     pollards(gcd1,N1);

     cout <<"end" << endl;
    
   congruence = solveCongruences(8,19,6,23);
       cout << "x = " << congruence <<endl;
       
    
    
    problem 2.28
    
    pohligHellman(5448, 6909, 11251);
    
   problem 3.1
   
   cout << "\n example 3.3 \n ";
   x = threeDotOne(1583, 4714, 7919);
   
   
   cout << "\n problem 3.1.a \n ";
   x = threeDotOne(19, 36, 97);
   
   
   cout << "\n problem 3.1.b \n ";
   x = threeDotOne(137, 428, 541);
   
   
   cout << "\n problem 3.1.c \n ";
   x = threeDotOne(73, 614, 1159);
   
   
   cout << "\n problem 3.1.d \n ";
   x = threeDotOne(751, 677, 8023);*/
   
   
   //cout << "\n problem 3.1.e \n ";
  // x = threeDotOne(38993, 328047, 401227);
//    //cout << endl << squareAndMultiply(401227, x, 38993) + 401227;
//    
//    
//    cout << "\n example 3.6 \n ";
//   int x = threeDotOne(17389, 43927, 64349);
////    
//    cout << "\n example 3.6 \n ";
//    x = threeDotFive(17389, 43927, 64349);
////  
    
//    cout << "\n problem 3.5.b.i \n ";
//    long x2 = threeDotFive(577, 60, 1463);
//    
//    cout << "\n problem 3.5.b.ii \n ";
//   x2 = threeDotFive(959, 1583, 1625);
//   
//   
//   cout << "problem 3.5.b.iii causes segfault, omitted" << endl;
//   //x2 = threeDotFive(139957,224689,2134440);
//  
  //3.12
    threeDotTwelve();
    
    
    //3.14
    mpz_t n;
    mpz_init_set_str(n, "1105" ,10);
    cout << "a) \n";
    threeDotFourteen(n);

    mpz_set_str(n, "294409",10);
    cout << "b) \n";
    threeDotFourteen(n);

    mpz_set_str(n, "294409",10);
    cout << "c) \n";
    threeDotFourteen(n);

    mpz_set_str(n, "118901509",10);
    cout << "d) \n";
    threeDotFourteen(n);

    mpz_set_str(n, "118901521",10);
    cout << "e) \n";
    threeDotFourteen(n);

    mpz_set_str(n, "118901527",10);
    cout << "f) \n";
    threeDotFourteen(n);

    mpz_set_str(n, "118915387",10);
    cout << "g) \n";
    threeDotFourteen(n);

     
     //3.17
     cout << "3.17" << endl;
     threeDotSeventeen(10);
     threeDotSeventeen(25);
     threeDotSeventeen(100);
     
     
     
         
    
    //3.21
    mpz_t gcd1;
     mpz_init(gcd1);
     mpz_t N1;
     mpz_init_set_str(N1,"13927189",10);

     cout << "Problem 3.21" << endl;
     cout << "a)" << endl;
     mpz_set_str(N1,"1739",10);
     pollards(gcd1,N1);
     
     cout << "b)" << endl;
     mpz_set_str(N1,"220459",10);
     pollards(gcd1,N1);
     
     cout << "c)" << endl;
     mpz_set_str(N1,"48356747",10);
     pollards(gcd1,N1);

     cout <<"end" << endl;
     
/*     
      cout << "\n problem 3.6 \n ";
      
    int N = 2038667;
    int e = 103;
    int m = 892383;
    int arrlen = 100;
    int arr[arrlen][2];
    clearArray(arr,arrlen);
    long x = threeDotSix(e,N,arr,m);

    cout << "\n problem 3.7 \n ";
    N = 12191;
    e = 37;
    int c = 587;
    clearArray(arr,arrlen);
    x = threeDotSeven(e,N,arr,c);
     */
  
  return 0;
  /*
 
   //cout << "\n problemaaaaz 3.5.b.iii \n ";
   cout << "gt here";
   x2 = threeDotFive(133957, 224689, 2134440);
      return 0;
 
//    
//   // cout << "\n totient(999) == " << totient(999) << endl;
//    
//    
//    cout << "\n problem 3.8 \n ";
//    int p, q;
    

mpz_t p;
mpz_init(p);
mpz_t q;
mpz_init(q);
//mpz_set_str(p);

cout << "\n\nProblem 3.8)\n\n";
cout << "\ta)" << endl;
mpz_t N;
mpz_init_set_str(N,"352717",10);
mpz_t p1q1;
mpz_init_set_str(p1q1,"351520",10);
threeDotEight(N, p1q1, p, q);

cout << "\tb)" << endl;
mpz_set_str(N,"77083921",10);
mpz_set_str(p1q1,"77066212",10);
threeDotEight(N, p1q1, p, q);

cout << "\tc)" << endl;
mpz_set_str(N,"109404161",10);
mpz_set_str(p1q1,"109380612",10);
threeDotEight(N, p1q1, p, q);

cout << "\td)" << endl;
mpz_set_str(N,"172205490419",10);
mpz_set_str(p1q1,"172204660344",10);
threeDotEight(N, p1q1, p, q);
//    */
//    
    return 0;
}


