#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<string> S(64);
  S[0] = "0000000000000000000000000010101111110100000000000000000000000000";
  S[1] = "0000000000000000000000101110101010010111110000000000000000000000";
  S[2] = "0000000000000000000011101000100011010000100100000000000000000000";
  S[3] = "0000000000000000011110101011111000011110101110100000000000000000";
  S[4] = "0000000000000000110000001010000011110000101010110000000000000000";
  S[5] = "0000000000000010011011111011101110100101100010010100000000000000";
  S[6] = "0000000000000111001001000000101000111100110110110110000000000000";
  S[7] = "0000000000011111101101101110111011100001100100100011100000000000";
  S[8] = "0000000000111111111111000010000010001011001101101001110000000000";
  S[9] = "0000000001111111111111111111101111111001111001111111111000000000";
  S[10] = "0000000011111111111111111111111111111111111111111111111100000000";
  S[11] = "0000000111111111111111111111111111111111111111111111111110000000";
  S[12] = "0000000111111111111111111111111111111111111111111111111110000000";
  S[13] = "0000001111111111111111111111111111111111111111111111111111000000";
  S[14] = "0000011111111111111111111111111111111111111111111111111111100000";
  S[15] = "0000011111111111111111111111111111111111111111111111111111100000";
  S[16] = "0000111111111111111111111111111111111111111111111111111111110000";
  S[17] = "0001111111111111111111111111111111111111111111111111111111111000";
  S[18] = "0000011111111111111111111111111111111111111111111111111111111000";
  S[19] = "0000000111111111111000100111111111111110001010111111111111100000";
  S[20] = "0011000001111111110010001111111111111110100000001111111100000000";
  S[21] = "0011110000011111000110100011111111111111101101100101100000001100";
  S[22] = "0111111100000100011100111001111111111101001000110000000001111110";
  S[23] = "0111111111000001001001101100011111111101101111100100001111111110";
  S[24] = "0111111111111011011100000111001111111000100100001110111111111110";
  S[25] = "0111111111000001000111011100011111111010111110100010010111111110";
  S[26] = "1111111111110111010010010001001111110010010000110111000111111111";
  S[27] = "1111111111100010010110111011101111010111011110011100010111111111";
  S[28] = "1111111111101111110111100001001010000101001011110001110111111111";
  S[29] = "1111111111100000100100111011100010101101101001000100100111111111";
  S[30] = "1111111111110110111101101110001011100000111101011111101111111111";
  S[31] = "1111111111100011100100100011101001110111100101110001000111111111";
  S[32] = "1111111111111000001101110110111011000001001101100100010111111111";
  S[33] = "1111111111111101101000010100001010010101101000110110111111111111";
  S[34] = "1111111111110000111101010101011110110100101110011100011111111111";
  S[35] = "1111111111111010010001110001111000100110000100110001111111111111";
  S[36] = "1111111111111111000111000101101101101100101110100100111111111111";
  S[37] = "1111111111111111110001011111100000111111100010001111111111111111";
  S[38] = "0111111111111111100100001111101011111111111000100111111111111110";
  S[39] = "0111111111111111111111111111111000011111111111111111111111111110";
  S[40] = "0111111111111111111111111111010010111111111111111111111111111110";
  S[41] = "0111111111111111111111111101000111111111111111111111111111111110";
  S[42] = "0011111111111111111111111100010001111111111111111111111111111100";
  S[43] = "0011111110011111111111111111110111111111111111111111111111111100";
  S[44] = "0001111111010111111111111111100011111111111111111111101111111000";
  S[45] = "0001111111000100011111111111001011111111111011111010000111111000";
  S[46] = "0001111111010101001010001101011001010010110001100000101111111000";
  S[47] = "0000111111110001100000100000001100011000000101001110111111110000";
  S[48] = "0000011111110100111101111011100111000011101111101011111111100000";
  S[49] = "0000011111111110100100100010111101110110100000100011111111100000";
  S[50] = "0000001111111100001101101000010001010000111010001111111111000000";
  S[51] = "0000000111111111011000111110110101000101100011111111111110000000";
  S[52] = "0000000111111111001110010100011100010111001000111111111110000000";
  S[53] = "0000000011111111100011110001110110111101111011111111111100000000";
  S[54] = "0000000001111111110110000101000000100001011111111111111000000000";
  S[55] = "0000000000111111111111010111101101101011001111111111110000000000";
  S[56] = "0000000000011111111111110000111100001000011111111111100000000000";
  S[57] = "0000000000000111111111111111111110111111111111111110000000000000";
  S[58] = "0000000000000011111111111111111111111111111111111100000000000000";
  S[59] = "0000000000000000111111111111111111111111111111110000000000000000";
  S[60] = "0000000000000000011111111111111111111111111111100000000000000000";
  S[61] = "0000000000000000000011111111111111111111111100000000000000000000";
  S[62] = "0000000000000000000000111111111111111111110000000000000000000000";
  S[63] = "0000000000000000000000000011111111111100000000000000000000000000";
  int row, col;
  cin >> row >> col;
  if (S[row][col] == '1'){
    cout << "IN" << endl;
  } else {
    cout << "OUT" << endl;
  }
}