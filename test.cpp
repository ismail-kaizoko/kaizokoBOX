#include <iostream>

void display(int * ptr);

int main() {
    int *tab = new int[3];

    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;

    int *tab2 = new int[3];


    display(tab2);

    delete[] tab;
    delete[] tab2;
    return 0;
}

void display(int * ptr){
    for(int i =0; i<20; i++){

        int val;
        val = ptr[i];
        std::cout << val ;

    

    }
}