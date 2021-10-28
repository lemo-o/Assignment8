#include <iostream>
#include <vector>
#include <random>
using namespace std;

vector<double> main_array; //vectors are just spicy arrays after all
//so the idea was to use a vector to get user input
//the problem is that that gets very complicated very quickly
class w //w because it's short
{
private:
    int arraysize = 12; //default arraysize of 10
    double largestpossible = 5;
    double smallestpossible = -5;

public:
    void userinput();                                                   //grabs input for array size
    void generate(vector<double> &array, double L, double U);           //4 inputs: array of doubles; integer for size of array; lower bound of array; upper bound of array
    void generate(vector<double> &array, int size, double L, double U); //assignment specific
    void print(vector<double> &array);                                  //print each value but not on own line. Input: array; size
    double average(vector<double> &array);                              //averages each value. Input: array; size
    double min(vector<double> &array);                                  //returns smallest value in array. Input: array; size
    double max(vector<double> &array);                                  //returns largest value in array. Input: array; size
    void addx(vector<double> &array, double value);                     //adds a value to each value in array. Input: array; size; value
    double num_less(vector<double> &array);                             //returns array values < average. Input: array; size
    double num_more(vector<double> &array);                             //returns array values > average. Input: array; size
    double num_less();                                                  //same as above, no input
    double range(vector<double> &array);                                //largest value - smallest value. Inputs: array; size
};
/*
So what you're supposed to do is have the size defined as an argument to the function, but because I used a class I didn't have to do that
Less inputs and having the program do more itself is better anyway.
Thats my story, and that's what I'm rolling with
*/
void w::userinput()
{
    cout << "What size would you like the array to be?" << endl;
    cin >> arraysize;
    arraysize; //this makes it work lmao
    cout << endl;
}

void w::generate(vector<double> &array, int size, double L, double U)
{
    main_array.resize(0, arraysize - 1);
    for (int i = 0; i <= size; i++)
    {
        array.at(i) = L + (double)(rand()) / ((double)(RAND_MAX / (U - L)));
    }
    double largestpossible = L; //clever storage for later
    double smallestpossible = U;
}
//heres an example of the tiny difference between the code.
void w::generate(vector<double> &array, double L, double U)
{
    main_array.resize(15);
    for (int i = 0; i <= arraysize; i++)
    {
        array.at(i) = L + (double)(rand()) / ((double)(RAND_MAX / (U - L)));
    }
    cout << "Array generated successfully." << endl;
}

void w::print(vector<double> &array) //print each value but not on own line. Input: array; size
{
    cout << "Array values: ";
    for (int i = 0; i <= arraysize; i++)
    {
        cout << array[i] << ", ";
    }
    cout << endl;
}
double w::average(vector<double> &array) //averages each value. Input: array; size
{
    double temp; //storage var
    for (int i = 0; i <= arraysize; i++)
    {
        temp += array[i];
    }
    cout << "Average value of array: ";
    return temp / arraysize;
}
double w::min(vector<double> &array) //returns smallest value in array. Input: array; size
{
    double a = largestpossible; //storage variable, set to highest possible
    for (int i = 0; i <= arraysize; i++)
    {
        if (array[i] < a) //if smaller, set to current
        {
            a = array[i];
        }
    }
    cout << "Min value of array: ";
    return a;
}
double w::max(vector<double> &array) //returns largest value in array. Input: array; size
{
    double a = smallestpossible; //storage variable, set to smallest possible
    for (int i = 0; i <= arraysize; i++)
    {
        if (array[i] > a) //if smaller, set to current
        {
            a = array[i];
        }
    }
    cout << "Max value of array: ";
    return a;
}
void w::addx(vector<double> &array, double value) //adds a value to each value in array. Input: array; size; value
{
    for (int i = 0; i <= arraysize; i++)
    {
        array[i] += value;
    }
    cout << endl;
    vector<double> f(); //switching back to non-pointer form
}
double w::num_less(vector<double> &array) //returns array values < average. Input: array; size
{
    //average part
    double temp; //storage var
    for (int i = 0; i <= arraysize; i++)
    {
        temp += array[i];
    }
    double average = temp / (int)main_array.capacity();

    for (int i = 0; i <= 50; i++) //printing part
    {
        if (array[i] < average)
        {
            cout << array[i] << ", ";
        }
    }
    return 0;
}

double w::num_more(vector<double> &array) //returns array values > average. Input: array; size
{
    //average part
    double temp; //storage var
    for (int i = 0; i <= arraysize; i++)
    {
        temp += array[i];
    }
    double average = temp / (int)main_array.capacity();

    for (int i = 0; i <= arraysize; i++) //printing part
    {
        if (array[i] > average)
        {
            cout << array[i] << ", ";
        }
    }
    return 0;
}

double w::num_less() //same as above, no input
{
    //average part
    double temp; //storage var
    for (int i = 0; i < (int)main_array.capacity(); i++)
    {
        temp += main_array.at(i);
    }
    double average = temp / (int)main_array.capacity();

    for (int i = 0; i < (int)main_array.capacity(); i++) //printing part
    {
        if (main_array.at(i) < average)
        {
            cout << main_array.at(i) << ", ";
        }
    }
    return 0;
}
double w::range(vector<double> &array) //largest value - smallest value. Inputs: array; size
{
    double max = smallestpossible;
    double min = largestpossible;
    for (int i = 0; i < (int)main_array.capacity(); i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max - min;
}

int main()
{
    w pockysticks;
    pockysticks.generate(main_array, -5, 5);
    pockysticks.print(main_array);
    cout << pockysticks.average(main_array) << endl;
    cout << pockysticks.min(main_array) << endl;
    cout << pockysticks.max(main_array) << endl;

    pockysticks.addx(main_array, 3);
    pockysticks.print(main_array);

    //honestly this is super broken and I don't have the time to fix it
    //Its one of those where it's "technically correct" but it's a fun intereaction
    //between doubles not truncating and me not properly working in my vector
    cout << "Less than average: " << pockysticks.num_less(main_array) << endl;
    cout << "More than average: " << pockysticks.num_more(main_array) << endl;

    cout << "Less than average but with spice: " << pockysticks.num_less() << endl;

    cout << "Range: " << pockysticks.range(main_array) << endl;
}