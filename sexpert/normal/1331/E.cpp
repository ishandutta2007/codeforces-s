#include <bits/stdc++.h>
using namespace std;

string clown = "0000000000000000000000000010101111110100000000000000000000000000000000000000000000000010111010101001011111000000000000000000000000000000000000000000111010001000110100001001000000000000000000000000000000000000011110101011111000011110101110100000000000000000000000000000000011000000101000001111000010101011000000000000000000000000000000100110111110111011101001011000100101000000000000000000000000000111001001000000101000111100110110110110000000000000000000000001111110110110111011101110000110010010001110000000000000000000001111111111110000100000100010110011011010011100000000000000000001111111111111111111101111111001111001111111111000000000000000001111111111111111111111111111111111111111111111110000000000000001111111111111111111111111111111111111111111111111100000000000000111111111111111111111111111111111111111111111111110000000000000111111111111111111111111111111111111111111111111111100000000000111111111111111111111111111111111111111111111111111111000000000011111111111111111111111111111111111111111111111111111100000000011111111111111111111111111111111111111111111111111111111000000011111111111111111111111111111111111111111111111111111111110000000011111111111111111111111111111111111111111111111111111111000000000011111111111100010011111111111111000101011111111111110000000110000011111111100100011111111111111101000000011111111000000000011110000011111000110100011111111111111101101100101100000001100011111110000010001110011100111111111110100100011000000000111111001111111110000010010011011000111111111011011111001000011111111100111111111111011011100000111001111111000100100001110111111111110011111111100000100011101110001111111101011111010001001011111111011111111111101110100100100010011111100100100001101110001111111111111111111100010010110111011101111010111011110011100010111111111111111111110111111011110000100101000010100101111000111011111111111111111111000001001001110111000101011011010010001001001111111111111111111110110111101101110001011100000111101011111101111111111111111111110001110010010001110100111011110010111000100011111111111111111111110000011011101101110110000010011011001000101111111111111111111111101101000010100001010010101101000110110111111111111111111111111000011110101010101111011010010111001110001111111111111111111111110100100011100011110001001100001001100011111111111111111111111111111000111000101101101101100101110100100111111111111111111111111111111000101111110000011111110001000111111111111111101111111111111111001000011111010111111111110001001111111111111100111111111111111111111111111111000011111111111111111111111111110011111111111111111111111111101001011111111111111111111111111111001111111111111111111111111010001111111111111111111111111111111100011111111111111111111111100010001111111111111111111111111111100001111111001111111111111111111011111111111111111111111111111110000011111110101111111111111111000111111111111111111111011111110000001111111000100011111111111001011111111111011111010000111111000000111111101010100101000110101100101001011000110000010111111100000001111111100011000001000000011000110000001010011101111111100000000011111110100111101111011100111000011101111101011111111100000000001111111111010010010001011110111011010000010001111111110000000000011111111000011011010000100010100001110100011111111110000000000000111111111011000111110110101000101100011111111111110000000000000011111111100111001010001110001011100100011111111111000000000000000111111111000111100011101101111011110111111111111000000000000000001111111110110000101000000100001011111111111111000000000000000000011111111111101011110110110101100111111111111000000000000000000000111111111111100001111000010000111111111111000000000000000000000000111111111111111111110111111111111111110000000000000000000000000001111111111111111111111111111111111110000000000000000000000000000001111111111111111111111111111111100000000000000000000000000000000011111111111111111111111111111100000000000000000000000000000000000001111111111111111111111110000000000000000000000000000000000000000001111111111111111111100000000000000000000000000000000000000000000000011111111111100000000000000000000000000";

int main() {
    int x, y;
    cin >> x >> y;
    cout << ((clown[64*x + y] == '1') ? "IN" : "OUT") << '\n';
}