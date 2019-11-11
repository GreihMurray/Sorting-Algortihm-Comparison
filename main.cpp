/*COMPARES RUN TIMES OF BUBBLE SELECTION AND INSERTION SORTING ALGORITHIMS. GREIH MURRAY APRIL 2018*/

#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <string>
#include <iomanip>
#include "LinkedList.h"
using namespace std;

double bubble(int sz, int nums[]);
double selection(int sz, int nums[]);
double insertion(int sz, int a[]);

int main(){

    clock_t start;

    int sz = 0;
    double randBub;
    double reverBub;
    double nearBub;
    double randSel;
    double reverSel;
    double nearSel;
    double randIn;
    double reverIn;
    double nearIn;
    double randInA;
    double reverInA;
    double nearInA;

    ifstream rand;
    rand.open("random.txt");

    if(!rand.is_open()){
        cout << "Cannot open file random.txt";
        return 73;
    }

    while(!rand.eof()){
        int nah;
        rand >> nah;
        sz++;
    }

    rand.close();

    rand.open("random.txt");
    int nums[sz];
    int nums2[sz];
    int nums3[sz];
    int nums4[sz];
    int nums5[sz];

    for(int i = 0; i < sz; i++){
        rand >> nums[i];
    }



    start = clock();
    bubble(sz, nums);
    randBub = (clock() - start)/(double) CLOCKS_PER_SEC;

    rand.close();

    rand.open("random.txt");

    for(int i = 0; i < sz; i++){
        rand >> nums2[i];
    }

    start = clock();
    selection(sz, nums2);
    randSel = (clock() - start) / (double) CLOCKS_PER_SEC;

    rand.close();

    rand.open("random.txt");


    start = clock();
    LinkedList list;
        while(!rand.eof()){
            //read in the line
            string line;
            rand >> line;
            //add name to the list
            list.add(line);
        }
    randIn = (clock() - start) / (double) CLOCKS_PER_SEC;

    rand.close();

    rand.open("random.txt");

    for(int i = 0; i < sz; i++){
        rand >> nums4[i];
    }

    start = clock();
    insertion(sz, nums4);
    randInA = (clock() - start) / (double) CLOCKS_PER_SEC;

    rand.close();

    ifstream near;
    near.open("nearly.txt");

    if(!near.is_open()){
        cout << "cannot open nearly.txt";
        return 73;
    }

    for(int i = 0; i < sz; i++){
        near >> nums[i];
    }

    start = clock();
    bubble(sz, nums);
    nearBub = (clock() - start) / (double) CLOCKS_PER_SEC;

    near.close();

    near.open("nearly.txt");

    for(int i = 0; i < sz; i++){
        near >> nums2[i];
    }

    start = clock();
    selection(sz, nums2);
    nearSel = (clock() - start) / (double) CLOCKS_PER_SEC;

    near.close();

    near.open("nearly.txt");

    start = clock();
    while(!near.eof()){
        //read in the line
        string line;
        near >> line;
        //add name to the list
        list.add(line);
    }
    nearIn = (clock() - start) / (double) CLOCKS_PER_SEC;

    near.close();

    near.open("nearly.txt");

    for(int i = 0; i < sz; i++){
        near >> nums4[i];
    }

    start = clock();
    insertion(sz, nums4);
    nearInA = (clock() - start) / (double) CLOCKS_PER_SEC;

    near.close();

    ifstream rever;
    rever.open("reversed.txt");

    if(!rever.is_open()){
        cout << "Cannot open reversed.txt";
        return 73;
    }

    for(int i = 0; i < sz; i++){
        rever >> nums3[i];
    }

    start = clock();
    bubble(sz, nums3);
    reverBub = (clock() - start) / (double) CLOCKS_PER_SEC;

    rever.close();

    rever.open("reversed.txt");

    for(int i = 0; i < sz; i++){
        rever >> nums2[i];
    }

    start = clock();
    selection(sz, nums2);
    reverSel = (clock() - start) / (double) CLOCKS_PER_SEC;

    rever.close();

    rever.open("reversed.txt");

    start = clock();
    while(!rever.eof()){
            //read in the line
            string line;
            rever >> line;
            //add name to the list
            list.add(line);
        }
    reverIn = (clock() - (start)) / (double) CLOCKS_PER_SEC;

    rever.close();

    rever.open("reversed.txt");

    rever.open("reversed.txt");

    for(int i = 0; i < sz; i++){
        rever >> nums5[i];
    }
    start = clock();
    insertion(sz, nums5);
    reverInA = (clock() - start) / (double) CLOCKS_PER_SEC;

    rever.close();

    cout << setw(15) << right << "Bubble" << setw(12) << right << "Selection" << setw(12) << right << "Insertion" << setw(20) << right << "Insertion (Array)" << endl;

    cout << setw(9) << left << "Random" << setw(6) << internal << randBub << setw(10) << right << randSel << setw(12) << right << randIn << setw(12) << right << randInA << endl;

    cout << setw(9) << left << "Nearly" << setw(6) << internal << nearBub << setw(10) << right << nearSel << setw(12) << right << nearIn << setw(12) << right << nearInA << endl;

    cout << setw(9) << left << "Reversed" << setw(6) << internal << reverBub << setw(10) << right << reverSel << setw(12) << right << reverIn << setw(12) << right << reverInA << endl;
}

double bubble(int sz, int nums[]){
    bool sorted = false;
    while(!sorted){
        for(int i = 0; i < sz-1; i++){
            if(nums[i] > nums[i+1]){
                int hold = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = hold;
            }
        }
        sorted = true;
        for(int i = 0; i < sz-1; i++){
            if(nums[i] > nums[i+1]){
                sorted = false;
                break;
            }
        }
    }
}
double selection(int sz, int nums[]){
    for(int i = 0; i < sz; i++){
        int min = nums[i];
        int loc = i;
        for(int j = 0; j < sz; j++){
            if(nums[j]  < min){
                min = nums[j];
                loc = j;
            }
        }
        int hold = nums[loc];
        nums[loc] = nums[i];
        nums[i] = hold;
    }
}
double insertion(int sz, int a[]){
     int i, key, j;
   for (i = 1; i < sz; i++)
   {
       key = a[i];
       j = i-1;

       while (j >= 0 && a[j] > key)
       {
           a[j+1] = a[j];
           j = j-1;
       }
       a[j+1] = key;
   }
}

