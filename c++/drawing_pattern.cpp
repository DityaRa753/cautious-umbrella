#include <cstdlib>
#include <iostream>
using namespace std;

// add literal string in constant c++ TODO!

enum {WIDTH_1 = 3, WIDTH_2 = 9, HEIGHT = 3};
const char *SYMBOL = "*";
const char *EMPTINESS = " ";

void sym_loop(const int spc)
{
    for (int i = 1; i <= spc; i++) 
        cout << EMPTINESS;
}

void print_next(const int count, const int spc)
{
    sym_loop(spc);
    for (int tmp = 0; tmp < count; tmp++)
        cout << SYMBOL;
}
void potholes(const int count, const int modulo, const int result)
{
    for (int tmp = 1; tmp <= count; tmp++) {
        if (tmp % modulo == result) {
            cout << SYMBOL;
        } else 
            cout << EMPTINESS;
    }
}

void pattern1(const int width, const int modulo, const int resultCalc,
    const int space, const int count)
{
    for(int i = 1; i <= HEIGHT; i++) {
        for(int spc = 0; spc < space; spc++)
            cout << EMPTINESS;
        for(int j = 1; j <= width; j++) {
            if(i == 2) {
                cout << SYMBOL;
                
                    for (int tmp = 0; tmp < count-1; tmp++) {
                        if (resultCalc == 0 && j == width) {
                            print_next(WIDTH_1, 5);
                        }
                        if (resultCalc == 2 && j == width) {
                            print_next(8, 0);
                        }
                    }
                
            } else {
                if (j % modulo == resultCalc) {
                    cout << SYMBOL;
                    
                        for (int tmp = 0; tmp < count-1; tmp++) {
                            if (resultCalc == 0 && j == width - 1)
                                print_next(1, 7);
                            if (resultCalc == 2 && j == width - 1)
                                potholes(8, 3, 2);
                        }
                    
                } else {
                    cout << EMPTINESS;
                }
            }
        }
        cout << endl;
    }
}

void full_pattern(int size, int space)
{
    for (int i = 1; i <= WIDTH_1; i++) {
        if (i == 2)
            pattern1(WIDTH_2, 3, 2, space, size); //there spaces
        else
            pattern1(WIDTH_1, 2, 0, space+3, size);
    }
}

void full_img(int size)
{
    int space = 4*(size-1);
    full_pattern(1, space);
    full_pattern(size, 0);
    full_pattern(1, space);
    //paint_other(size);
    //full_pattern(size);
}

int main(int argc, char **argv)
{
    if (argc < 1)
        return 0;
    int size = atoi(argv[1]);
    if (size < 1 || size > 5) {
        cerr << "The number must greater than zero and no greater than five" << endl;
        exit(1);
    }
    //multiply by nine, because the width of the pattern is nine
    full_img(size);
    return 0;
}