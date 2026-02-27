#include <iostream>
#include <vector>
#include <cstdint>
#include <iomanip>

using namespace std;
// code for Berlekamp-Massey attack on lfsr
class Bm{
    uint32_t current_poly = 1;
    uint32_t previous_poly = 1;
    int current_length = 0;
    int position = 0;
    vector<int> bitstream;

    public:
        Bm(vector<int> a){
            bitstream = a;
        }

        uint32_t run(){
            
            for (int i =0 ; i<bitstream.size() ;i++){
                int prediction = 0;
                int actual = bitstream[i];
                for(int j =0 ; j<= current_length; j++){
                    if((current_poly >> j) & 1){
                    // prediction = prediction XOR bitstream[i - j]
                    prediction = prediction ^ bitstream[i - j];
                }
            }
                // discrepancy = actual XOR prediction
                int discrepency = actual ^ prediction;
                    if (discrepency == 1){
                        int temp = current_poly;
                        current_poly = current_poly ^ (previous_poly << position);
                        
                        if ((i + 1 - current_length) > current_length){
                            previous_poly = temp;
                            current_length = i + 1 - current_length;
                            position = 1;
                        }
                        else{
                            position = position + 1;
                    }
                }
            }
            return current_poly;
        }


};
