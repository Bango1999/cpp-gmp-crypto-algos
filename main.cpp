/* 
 * File:   main.cpp
 * Author: joseph
 *
 * Created on July 11, 2014, 6:35 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>

using namespace std;

//This is an implementation of quickSort that I found on the internet.
void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
 
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}


int kasiskiMethod(string encrypted){
    int keyLength = 0;
   // int size = (encrypted.length() / 6 );
    int numTrigrams = 0;
    string found[50];//make an array to hold each trigram that is found
    //The size of this array is set to the length of the encrypted message divided by 6.
    int difference[50];
    int places[50][2];
    int factors[1000];
    int numFactors = 0;
    
    for(int i = 0; i < 1000; i++){
        factors[i] = 0;
    }
    
    string trigram ( encrypted, 0 , 3 );
    string temp = "";
    //int location = 0;
    
    
    
    for(int i = 0; i <20; i++){
        difference[i] = 0;
        places[i][0] = 0;
        places[i][1] = 0;
    }
    
    for(int location = 0; location < encrypted.length(); location++){ 
        trigram = encrypted.substr(location,3);
        for(int i = location + 1; i < encrypted.length(); i++){
            temp = encrypted.substr(i,3);
            if( trigram.compare(temp) == 0 ){
                found[numTrigrams] = trigram;
                places[numTrigrams][0] = i;
                places[numTrigrams][1] = location;
                difference[numTrigrams] = i - location;
                
                cout << trigram << "\t | \t" << location << " and " << i << "\t | \t" << i - location << " has the factors :  ";
                 //The cout statement above prints out a table similar to Table 4.2 on page 206, but it is not in alphabetical order.
                for(int j = 1; j < difference[numTrigrams]; j++){
                    
                    if( difference[numTrigrams] % j == 0 ){
                        factors[numFactors] = difference[numTrigrams] / j; 
                        cout << factors[numFactors++] << ", ";
                    }
                }
                cout << endl;
                numTrigrams++;
            }

                
        }
    
    
    }
    
//    for( int i = 0; i < numFactors;i++){
//        cout << factors[i] << endl;
//    }
    
    cout << endl << endl;
    
    quickSort(factors, 0, numFactors-1);
    
//    for( int i = 0; i < numFactors;i++){
//        cout << factors[i] << endl;
//    }
    
    int keyOccurence = 0;
    int n = 0;
    int i = 0;
    int num = 0;
    while( i < numFactors ){
        num = 1;
        n = factors[i];
        while( n == factors[i] && i < numFactors ){
            i++;
            num++;
        }
        if( num > keyOccurence ){
            keyOccurence = num;
            keyLength = n;
        }
        cout << n << " occurs " << num << " times." << endl;
    }
    
    cout << "The key length is " << keyLength << endl;
    
    return keyLength;
}

double IndCo(string s){
    int len = s.length();
    int n = 0;
    int F[26];
    double index = 0.0;
    //initializing F to all zeros
    for( int i = 0; i < 26; i++){
        F[i] = 0;
    }
    
    for( int i = 0; i < 26; i++){
        for( int j = 0; j < len; j++){
            if( ( s[j] == 'a' + i ) ||  ( s[j] == 'A' + i ) ){
                F[i] = F[i] + 1;
                n++;
            }
        }
    }
    
//    for( int i = 0; i < 26; i++){
//        cout << "F[" << i << "] = " << F[i] << endl;
//    }
    
    
    
    for( int i = 0; i < 26; i++){
        index = index + (F[i] * ( F[i] - 1 ) );
    }
    
    //cout << "n = " << n << endl;
    //cout << temp << " / (" << n << " * " << n -1 << ") = "; 
    
    index = index / (n * (n -1) );
    
    //cout << "temp = " << temp << endl;
    
    
    return index;
}

double MutIndCo(string s, string t){
    int lenS = s.length();
    int lenT = t.length();
    int m = 0;
    int n = 0;
    
    int Fs[26];
    int Ft[26];
    double index = 0.0;
    //initializing F to all zeros
    for( int i = 0; i < 26; i++){
        Fs[i] = 0;
        Ft[i] = 0;
    }
    
    for( int i = 0; i < 26; i++){
        for( int j = 0; j < lenS; j++){
            if( ( s[j] == 'a' + i ) ||  ( s[j] == 'A' + i ) ){
                Fs[i] = Fs[i] + 1;
                n++;
            }
        }
    }
    
    
    for( int i = 0; i < 26; i++){
        for( int j = 0; j < lenT; j++){
            if( ( t[j] == 'a' + i ) ||  ( t[j] == 'A' + i ) ){
                Ft[i] = Ft[i] + 1;
                m++;
            }
        }
    }
    
//    for( int i = 0; i < 26; i++){
//        cout << "F[" << i << "] = " << F[i] << endl;
//    }
    
    
    
    for( int i = 0; i < 26; i++){
        index = index + (Fs[i] *  Ft[i] );
    }
    
    //cout << "n = " << n << endl;
    //cout << temp << " / (" << n << " * " << n -1 << ") = "; 
    
    index = index / (n * m );
    
    //cout << "temp = " << temp << endl;
    
    
    return index;
}


int indexOfCoincidence(string s){
    int numIndex = 0;
    int keylength = 2;
    double realAverage = 0.0;
    double avg = 0.0;
    string temp = "";
    int start = 0;
    double eachIndex = 0.0;
    int tempKey = 0;
    double tempAvg = 0.0;
    
    cout << "Key Length | Individual Indices of Coincidence \t\t |  Avg Index\n";
    
   // while( realAverage < 0.06 && keylength < 10 ){
     while( keylength < 10 ){
        keylength++;
       
            temp="";
            start = 0;
            numIndex = 0;
            avg = 0.0;
            cout << keylength << "\t | ";
            while(start < keylength){
                temp="";
                for(int j = start; j < s.length(); j+=keylength){
                    temp += s[j];
                }
                numIndex++;
                //cout << "avg = " << avg << endl;
                eachIndex = IndCo(temp);
                cout  << eachIndex << ", ";
                avg += eachIndex;
             //  cout << "temp = " << temp << endl;
              //  cout << "eachIndex = " << eachIndex << endl;
                //cout << "After calling IndCo, avg = " << avg << endl;
                start++;
            }
            realAverage = avg / numIndex;
            cout << "\t\t\t | " << realAverage << endl;
            if( realAverage > tempAvg ){
                tempAvg = realAverage;
                tempKey = keylength;
            }
            //cout << "**********************************************************\n";
            //cout << "With a keylength of " << keylength << " the realAverage is : " << realAverage << endl;
    }
    
    
    //cout << "With a keylength of " << keylength << " the realAverage is : " << realAverage << endl;
    
   return tempKey; 
}

void mutualIndices(string str, const int keylength){
    vector<string> s;
    string sj = "";
    
    string temp="";
    int start = 0;
     while(start < keylength){
                temp="";
                for(int j = start; j < str.length(); j+=keylength){
                    temp += str[j];
                }
             //push_back temp into s...
                s.push_back(temp);
                start++;
            }
    
    
//    for(int i = 0; i < s.size(); i++){
//        cout << "s[" << i << "] = " << s[i] << endl;
//    }
    cout << "Blocks  | \t\t Shift Amount\n";
    cout << "i | j | ";
    for(int i = 0; i < 26; i++){
        cout << "     " << i << "     ";
    }
    cout << endl;
    for(int i = 0; i < keylength - 1; i++ ){
        for(int j = i + 1; j < keylength; j++ ){
            sj = s[j];
            cout << i+1 << " | " << j+1 << " | ";
            //call MutIndCo(s[i], sj )  because sigma == 0 
            for(int sigma = 0; sigma < 26; sigma++){
                if( sigma == 0 ){
                    cout << MutIndCo(s[i],sj) << "  ";
                }
                else{
                    for(int k = 0; k < sj.length(); k++){
                        if( sj[k] == 'z'){
                            sj[k] = 'a';
                        }
                        else{
                            sj[k] = sj[k] + 1;
                        }
                    }//for(int k = 0; k < sj.length(); k++){
                    cout << MutIndCo(s[i],sj) << "  ";
                }
            }//for(int sigma = 0; sigma < 26; sigma++){
            cout << endl;
        }//for(int j = i + 1; j <= keylength; j++ ){
    }//for(int i = 0; i < keylength; i++ ){
    
    
    return;
}

// I found this at snipplr.com.
int gauss(
        int N, // number of unknowns
        float A [20] [21], // coefficients and constants
        float r[20]
)
{
//    printMatrix(N, A);
    float multiplier, divider;
    bool fin = false;
 
    // forward substitution
    for (int m=0; m<=N; m++)
    {
        for (int i=m+1; i<=N; i++)
        {
            multiplier = A[i][m]; // current row - root
            divider = A[m][m]; // first row - root
 
            if (divider == 0)
            {
                return 1;
            }
 
            for (int j=m; j<=N; j++)
            {
                if (i == N) 
                {
                    break;
                    fin = true;
                }
 
                A[i][j] = (A[m][j] * multiplier / divider) - A[i][j];
//                cout << "A[" << i << "][" << j << "]  = (A[" << m << "][" << j << "] * " << multiplier << " / " << divider << ") - A[" << i << "][" << j << "]" << endl;
//                cout << "Current cell " << i << j << endl;
//                cout << "Current set " << m << m << endl;
//                printMatrix(N, A);
            }
 
            for (int j=m; j<=N; j++)
            {
                A[i-1][j] = A[i-1][j] / divider;
            }
 
            if (fin)
                break;
        }
    }
 
//    printMatrix(N, A);
 
    // back substitution
    float s = 0;
    r[N-1] = A[N-1][N];
    int y = 0;
    for (int i = N-2; i >= 0; i--)
    {
        s = 0;
        y++;
        for (int x = 0; x < N; x++)
        {
            s = s + (A[i][N-1-x] * r[N-(x+1)]);
//            cout << "A[" << i << "][" << N-1-x << "] = " << A[i][N-1-x] << " ";
//            cout << " r[" << N-(x+1) << "] = " << r[N-(x+1)] << " " << endl;
//            cout << "s = " << s << endl;
 
            if (y == x+1) break;
        }
        r[i] = A[i][N] - s;
//        cout << "r[" << i << "] = A[" << i << "][" << N << "] - " << s << " = " << r[i] << endl;
    }
 
//    for (int i = 0; i < N; i++)
//    {
//        cout << r[i] << endl;
//    }
 
 
}


void shiftRelations(string str, const int keylength){
    vector<string> s;
    string sj = "";
    // The following array "b" is an idea that I have for solving the Bi - Bj = sigma equations.
    int b[15][3];// j = i - sigma
    //b[i][0] will contain B_j
    //b[i][1] will contain b_i
    //b[i][2] will contain - sigma ( negative sigma )
    for(int i = 0; i < 15; i++){
        b[i][0] = 0;
        b[i][1] = 0;
        b[i][2] = 0;
    }
    int bCount = 0;
    
    
    string temp="";
    int start = 0;
    
    double index = 0.0;
    
    //this builds the S_i ' s
     while(start < keylength){
                temp="";
                for(int j = start; j < str.length(); j+=keylength){
                    temp += str[j];
                }
             //push_back temp into s...
                s.push_back(temp);
                start++;
     }
    
   
    
   
    cout << "i | j | Shift | MutIndCo | Shift Relation " << endl;
    for(int i = 0; i < keylength - 1; i++ ){
        for(int j = i + 1; j < keylength; j++ ){
            sj = s[j];
            //cout << i+1 << " | " << j+1 << " | ";
            //call MutIndCo(s[i], sj )  because sigma == 0 
            for(int sigma = 0; sigma < 26; sigma++){
                if( sigma == 0 ){
                    index = MutIndCo(s[i],sj);
                }
                else{
                    for(int k = 0; k < sj.length(); k++){
                        if( sj[k] == 'z'){
                            sj[k] = 'a';
                        }
                        else{
                            sj[k] = sj[k] + 1;
                        }
                    }//for(int k = 0; k < sj.length(); k++){
                    index = MutIndCo(s[i],sj);
                }
                if( index > 0.064 ){
                    cout << i+1 << " | " << j+1 << " |  " << sigma  << "   | " << index  << " | " << "B_" << i+1 << " - B_" << j+1 << " = " << sigma << endl;;
                    b[bCount][0] = j+1;
                    b[bCount][1] = i+1;
                    b[bCount][2] = ((sigma * - 1) % 26) ;
                    if( b[bCount][2]  < 0 )
                        b[bCount][2] += 26;
                    if( bCount > 14 ){
                        cout << "\nMore equations have been made then the array can hold.  Terminating.\n";
                        exit(1);
                    }
                    else{
                        bCount++;
                    }
                }
            }//for(int sigma = 0; sigma < 26; sigma++){
            //cout << endl;
        }//for(int j = i + 1; j <= keylength; j++ ){
    }//for(int i = 0; i < keylength; i++ ){
    
    //displaying the shift relation equations
    
    for(int i = 0; i < bCount; i++){
       cout << b[i][0] << " = " <<  
        b[i][1] << " + " << 
        b[i][2] << endl;
    }
    
    
    
    return;
}

void getKey(int shifts[], int keylength){
    vector<string> keys;
    string temp = "a";
    for(int h = 0; h < 26; h++){
        for(int i = 1; i < keylength; i++){
            temp += "a"; 
        }
        keys.push_back(temp);
        temp = "a";
    }
    
    for(int i = 0; i < keylength; i++){
        keys[0][i] = keys[0][i] + shifts[i];
        
    }

    cout << "First possible key : " << keys[0] << endl;
    
    for( int i = 1; i < 26; i++){
        for(int j = 0; j < keylength; j++){
            
            keys[i][j] = keys[i-1][j] + 1;
            
            if(keys[i][j] > 'z'){
                keys[i][j] -= 26;
            }
            
        }
        cout << "The " << i << "th possible key is : " << keys[i] << endl;
    }
    return;
}

void decrypt(string s, string key){
    string temp = "";
    
    
    
    for(int i = 0; i < s.length(); i+=key.length() ){
        for(int j = 0; j < key.length(); j++){
            
        }
    }
    
}




string BrethrenDostThouEvenDecrypt(string crypt, string key, int kl) {

  string msg = "";
  for (int i = 0; i < crypt.length(); i++) {
    msg += "-";
  }


  int index = 0;
  int keyIndex = 0;

  char charHalf[26];
  int intHalf[26];
  charHalf[0] = 'a';
  intHalf[0] = 0;

  for (int i = 1; i < 26; i++) {
    charHalf[i] = charHalf[i-1] + 1;
	//cout << "charhalf[i-1] = " << charHalf[i-1] << endl;
    intHalf[i] = intHalf[i-1] + 1;
  }
//for (int i = 0; i < 26; i++) cout << "charhalf["<<i<<"] = " << charHalf[i] << " and intHalf[" << i << "] = " << intHalf[i] << endl;
//return 0;

  while (index < crypt.length()) {

    int match = 0;

    while (key[keyIndex] != charHalf[match] && match < 26) {
      match++;
    }
	cout << "match is " << match << endl;
    msg[index] = crypt[keyIndex] - intHalf[match];
    
    if (msg[index] > 'z') {
      msg[index] = msg[index] + 26;
    }
    index++;
    keyIndex++;
    if (keyIndex >= kl) keyIndex = 0;
  }

  cout << "Decrypted Message As:\n" << msg << endl;

return msg;
}

/*
 * 
 */
int main(int argc, char** argv) {

     cout << setprecision(4) << fixed;
    
    string test = "zpgdlrjlajkpylxzpyyglrjgdlrzhzqyjzqrepvmswrzyrigzhzvregkwivssaoltnliuwoldieaqewfiiykhbjowrhdogcqhkwajyaggemisrzqoqhoavlkbjofrylvpsrtgiuavmswlzgmsevwpcdmjsvjqbrnklpcfiowhvkxjbjpmfkrqthtkozrgqihbmqsbivdardymqmpbunivxmtzwqvgefjhucborvwpcdxuwftqmoowjipdsfluqmoeavljgqealrktiwvextvkrrgxani";
   // cout << "length = " << test.length() << endl;
    
    
    int keyWordLength = kasiskiMethod(test);
    
    
    string s = "A bird in hand is worth two in the bush.";
    
    double test2 = IndCo(s);
    
    keyWordLength = indexOfCoincidence(test);
    
    cout << endl << keyWordLength << endl;
    
    string t = "A stitch in time saves nine.";
    
    test2 = MutIndCo(s,t);
    
    cout << "MutIndCo(s,t) = " << test2 << endl;
    
    
    mutualIndices(test, 7);
    cout << endl;
    shiftRelations(test, 7);
    
//    
//    //testing gauss function
//    float A[20][21];
//    float X[20];
//    
//    for(int i = 0; i < 20; i++){
//        for(int j = 0; j < 21; j++){
//            A[i][j] = 0;
//        }
//    }
//    //B1 - B3 = 1
//    A[0][0] = 1;  
//    A[0][2] = -1; 
//    A[0][7] = 1;
//    
//    //B1-B4 = 19
//    A[1][0] = 1;  
//    A[1][3] = -1; 
//    A[1][7] = 19;
//    
//    //B1-B6 = 16
//    A[2][0] = 1;  
//    A[2][5] = -1; 
//    A[2][7] = 16;
//    
//    //B2 - B3 = 6
//    A[3][1] = 1;  
//    A[3][2] = -1; 
//    A[3][7] = 6;
//    
//    
////    //B2 - B4 = 24
////    A[4][1] = 1;  
////    A[4][3] = -1; 
////    A[4][11] = 24;
////    
//    
////    //B3 - B4 = 18
////    A[5][2] = 1;  
////    A[5][3] = -1; 
////    A[5][11] = 18;
//    
//    
//    //B3 - B5 = 24
//    A[4][2] = 1;  
//    A[4][4] = -1; 
//    A[4][7] = 24;
//    
//    
////    //B3 - B6 = 15
////    A[7][2] = 1;  
////    A[7][5] = -1; 
////    A[7][11] = 15;
//    
//    
//    //B3 - B7 = 10
//    A[5][2] = 1;  
//    A[5][6] = -1; 
//    A[5][7] = 10;
//    
//    
//    // B_4 - B_6 = 23
//
//    A[6][3] = 1;  
//    A[6][5] = -1; 
//    A[6][7] = 23;
//    
////    
////    //  B_4 - B_7 = 18
////    A[10][3] = 1;  
////    A[10][6] = -1; 
////    A[10][11] = 18;
////    
////    
////    // B_6 - B_7 = 21
////    A[11][5] = 1;  
////    A[11][6] = -1; 
////    A[11][11] = 21;
////    
//    gauss(7, A, X);
//    
//     for (int i=0; i<7; i++) cout << X[i] << "  ";
    
    int offsets[7];
    offsets[0] = 0;
    offsets[1] = 5;
    offsets[2] = 25;
    offsets[3] = 7;
    offsets[4] = 1;
    offsets[5] = 10;
    offsets[6] = 15;
    
    getKey(offsets, 7);
    
    
    BrethrenDostThouEvenDecrypt(s, "dickens", 7);
    
    
    return 0;
}


