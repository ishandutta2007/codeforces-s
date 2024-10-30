#include<bits/stdc++.h>
using namespace std;
 
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ST first
#define ND second
 
ostream& operator<<(ostream &out, string str) {
	for(char c : str) out << c;
	return out;
}
 
template<class L, class R> ostream& operator<<(ostream &out, pair<L, R> p) {
	return out << "(" << p.ST << ", " << p.ND << ")";
}

template<class T> auto operator<<(ostream &out, T &&x) -> decltype(x.begin(), out) {
	out << '{';
	for(auto &e : x)
        	out << e << (&e == &*--x.end() ? "" : ", ");
	return out << '}';
}

template<class... Args> void dump(Args&&... args) {
	((cerr << args << ";  "), ...);
}
 
#ifdef DEBUG
#  define debug(x...) cerr << "[" #x "]: ", dump(x), cerr << "\n"
#else
#  define debug(...) false
#endif
 
template<class T> int size(T && a) { return (int) a.size(); }
 
using LL = long long;
using PII = pair<int, int>;

LL ans[151][10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

ans[1][0] = 1;
ans[2][0] = 2;
ans[3][0] = 3;
ans[4][0] = 4;
ans[5][0] = 5;
ans[6][0] = 6;
ans[7][0] = 7;
ans[8][0] = 8;
ans[9][0] = 9;
ans[10][0] = 19;
ans[11][0] = 29;
ans[12][0] = 39;
ans[13][0] = 49;
ans[14][0] = 59;
ans[15][0] = 69;
ans[16][0] = 79;
ans[17][0] = 89;
ans[18][0] = 99;
ans[19][0] = 199;
ans[20][0] = 299;
ans[21][0] = 399;
ans[22][0] = 499;
ans[23][0] = 599;
ans[24][0] = 699;
ans[25][0] = 799;
ans[26][0] = 899;
ans[27][0] = 999;
ans[28][0] = 1999;
ans[29][0] = 2999;
ans[30][0] = 3999;
ans[31][0] = 4999;
ans[32][0] = 5999;
ans[33][0] = 6999;
ans[34][0] = 7999;
ans[35][0] = 8999;
ans[36][0] = 9999;
ans[37][0] = 19999;
ans[38][0] = 29999;
ans[39][0] = 39999;
ans[40][0] = 49999;
ans[41][0] = 59999;
ans[42][0] = 69999;
ans[43][0] = 79999;
ans[44][0] = 89999;
ans[45][0] = 99999;
ans[46][0] = 199999;
ans[47][0] = 299999;
ans[48][0] = 399999;
ans[49][0] = 499999;
ans[50][0] = 599999;
ans[51][0] = 699999;
ans[52][0] = 799999;
ans[53][0] = 899999;
ans[54][0] = 999999;
ans[55][0] = 1999999;
ans[56][0] = 2999999;
ans[57][0] = 3999999;
ans[58][0] = 4999999;
ans[59][0] = 5999999;
ans[60][0] = 6999999;
ans[61][0] = 7999999;
ans[62][0] = 8999999;
ans[63][0] = 9999999;
ans[64][0] = 19999999;
ans[65][0] = 29999999;
ans[66][0] = 39999999;
ans[67][0] = 49999999;
ans[68][0] = 59999999;
ans[69][0] = 69999999;
ans[70][0] = 79999999;
ans[71][0] = 89999999;
ans[72][0] = 99999999;
ans[73][0] = 199999999;
ans[74][0] = 299999999;
ans[75][0] = 399999999;
ans[76][0] = 499999999;
ans[77][0] = 599999999;
ans[78][0] = 699999999;
ans[79][0] = 799999999;
ans[80][0] = 899999999;
ans[81][0] = 999999999;
ans[82][0] = 1999999999;
ans[83][0] = 2999999999;
ans[84][0] = 3999999999;
ans[85][0] = 4999999999;
ans[86][0] = 5999999999;
ans[87][0] = 6999999999;
ans[88][0] = 7999999999;
ans[89][0] = 8999999999;
ans[90][0] = 9999999999;
ans[91][0] = 19999999999;
ans[92][0] = 29999999999;
ans[93][0] = 39999999999;
ans[94][0] = 49999999999;
ans[95][0] = 59999999999;
ans[96][0] = 69999999999;
ans[97][0] = 79999999999;
ans[98][0] = 89999999999;
ans[99][0] = 99999999999;
ans[100][0] = 199999999999;
ans[101][0] = 299999999999;
ans[102][0] = 399999999999;
ans[103][0] = 499999999999;
ans[104][0] = 599999999999;
ans[105][0] = 699999999999;
ans[106][0] = 799999999999;
ans[107][0] = 899999999999;
ans[108][0] = 999999999999;
ans[109][0] = 1999999999999;
ans[110][0] = 2999999999999;
ans[111][0] = 3999999999999;
ans[112][0] = 4999999999999;
ans[113][0] = 5999999999999;
ans[114][0] = 6999999999999;
ans[115][0] = 7999999999999;
ans[116][0] = 8999999999999;
ans[117][0] = 9999999999999;
ans[118][0] = 19999999999999;
ans[119][0] = 29999999999999;
ans[120][0] = 39999999999999;
ans[121][0] = 49999999999999;
ans[122][0] = 59999999999999;
ans[123][0] = 69999999999999;
ans[124][0] = 79999999999999;
ans[125][0] = 89999999999999;
ans[126][0] = 99999999999999;
ans[127][0] = 199999999999999;
ans[128][0] = 299999999999999;
ans[129][0] = 399999999999999;
ans[130][0] = 499999999999999;
ans[131][0] = 599999999999999;
ans[132][0] = 699999999999999;
ans[133][0] = 799999999999999;
ans[134][0] = 899999999999999;
ans[135][0] = 999999999999999;
ans[136][0] = 1999999999999999;
ans[137][0] = 2999999999999999;
ans[138][0] = 3999999999999999;
ans[139][0] = 4999999999999999;
ans[140][0] = 5999999999999999;
ans[141][0] = 6999999999999999;
ans[142][0] = 7999999999999999;
ans[143][0] = 8999999999999999;
ans[144][0] = 9999999999999999;
ans[145][0] = 19999999999999999;
ans[146][0] = 29999999999999999;
ans[147][0] = 39999999999999999;
ans[148][0] = 49999999999999999;
ans[149][0] = 59999999999999999;
ans[150][0] = 69999999999999999;
ans[1][1] = 0;
ans[2][1] = -1;
ans[3][1] = 1;
ans[4][1] = -1;
ans[5][1] = 2;
ans[6][1] = -1;
ans[7][1] = 3;
ans[8][1] = -1;
ans[9][1] = 4;
ans[10][1] = 9;
ans[11][1] = 5;
ans[12][1] = 19;
ans[13][1] = 6;
ans[14][1] = 29;
ans[15][1] = 7;
ans[16][1] = 39;
ans[17][1] = 8;
ans[18][1] = 49;
ans[19][1] = 18;
ans[20][1] = 59;
ans[21][1] = 28;
ans[22][1] = 69;
ans[23][1] = 38;
ans[24][1] = 79;
ans[25][1] = 48;
ans[26][1] = 89;
ans[27][1] = 58;
ans[28][1] = 189;
ans[29][1] = 68;
ans[30][1] = 289;
ans[31][1] = 78;
ans[32][1] = 389;
ans[33][1] = 88;
ans[34][1] = 489;
ans[35][1] = 98;
ans[36][1] = 589;
ans[37][1] = 198;
ans[38][1] = 689;
ans[39][1] = 298;
ans[40][1] = 789;
ans[41][1] = 398;
ans[42][1] = 889;
ans[43][1] = 498;
ans[44][1] = 989;
ans[45][1] = 598;
ans[46][1] = 1989;
ans[47][1] = 698;
ans[48][1] = 2989;
ans[49][1] = 798;
ans[50][1] = 3989;
ans[51][1] = 898;
ans[52][1] = 4989;
ans[53][1] = 998;
ans[54][1] = 5989;
ans[55][1] = 1998;
ans[56][1] = 6989;
ans[57][1] = 2998;
ans[58][1] = 7989;
ans[59][1] = 3998;
ans[60][1] = 8989;
ans[61][1] = 4998;
ans[62][1] = 9989;
ans[63][1] = 5998;
ans[64][1] = 19989;
ans[65][1] = 6998;
ans[66][1] = 29989;
ans[67][1] = 7998;
ans[68][1] = 39989;
ans[69][1] = 8998;
ans[70][1] = 49989;
ans[71][1] = 9998;
ans[72][1] = 59989;
ans[73][1] = 19998;
ans[74][1] = 69989;
ans[75][1] = 29998;
ans[76][1] = 79989;
ans[77][1] = 39998;
ans[78][1] = 89989;
ans[79][1] = 49998;
ans[80][1] = 99989;
ans[81][1] = 59998;
ans[82][1] = 199989;
ans[83][1] = 69998;
ans[84][1] = 299989;
ans[85][1] = 79998;
ans[86][1] = 399989;
ans[87][1] = 89998;
ans[88][1] = 499989;
ans[89][1] = 99998;
ans[90][1] = 599989;
ans[91][1] = 199998;
ans[92][1] = 699989;
ans[93][1] = 299998;
ans[94][1] = 799989;
ans[95][1] = 399998;
ans[96][1] = 899989;
ans[97][1] = 499998;
ans[98][1] = 999989;
ans[99][1] = 599998;
ans[100][1] = 1999989;
ans[101][1] = 699998;
ans[102][1] = 2999989;
ans[103][1] = 799998;
ans[104][1] = 3999989;
ans[105][1] = 899998;
ans[106][1] = 4999989;
ans[107][1] = 999998;
ans[108][1] = 5999989;
ans[109][1] = 1999998;
ans[110][1] = 6999989;
ans[111][1] = 2999998;
ans[112][1] = 7999989;
ans[113][1] = 3999998;
ans[114][1] = 8999989;
ans[115][1] = 4999998;
ans[116][1] = 9999989;
ans[117][1] = 5999998;
ans[118][1] = 19999989;
ans[119][1] = 6999998;
ans[120][1] = 29999989;
ans[121][1] = 7999998;
ans[122][1] = 39999989;
ans[123][1] = 8999998;
ans[124][1] = 49999989;
ans[125][1] = 9999998;
ans[126][1] = 59999989;
ans[127][1] = 19999998;
ans[128][1] = 69999989;
ans[129][1] = 29999998;
ans[130][1] = 79999989;
ans[131][1] = 39999998;
ans[132][1] = 89999989;
ans[133][1] = 49999998;
ans[134][1] = 99999989;
ans[135][1] = 59999998;
ans[136][1] = 199999989;
ans[137][1] = 69999998;
ans[138][1] = 299999989;
ans[139][1] = 79999998;
ans[140][1] = 399999989;
ans[141][1] = 89999998;
ans[142][1] = 499999989;
ans[143][1] = 99999998;
ans[144][1] = 599999989;
ans[145][1] = 199999998;
ans[146][1] = 699999989;
ans[147][1] = 299999998;
ans[148][1] = 799999989;
ans[149][1] = 399999998;
ans[150][1] = 899999989;
ans[1][2] = -1;
ans[2][2] = -1;
ans[3][2] = 0;
ans[4][2] = -1;
ans[5][2] = -1;
ans[6][2] = 1;
ans[7][2] = -1;
ans[8][2] = -1;
ans[9][2] = 2;
ans[10][2] = -1;
ans[11][2] = -1;
ans[12][2] = 3;
ans[13][2] = -1;
ans[14][2] = -1;
ans[15][2] = 4;
ans[16][2] = -1;
ans[17][2] = -1;
ans[18][2] = 5;
ans[19][2] = -1;
ans[20][2] = -1;
ans[21][2] = 6;
ans[22][2] = -1;
ans[23][2] = -1;
ans[24][2] = 7;
ans[25][2] = -1;
ans[26][2] = -1;
ans[27][2] = 17;
ans[28][2] = -1;
ans[29][2] = -1;
ans[30][2] = 27;
ans[31][2] = -1;
ans[32][2] = -1;
ans[33][2] = 37;
ans[34][2] = -1;
ans[35][2] = -1;
ans[36][2] = 47;
ans[37][2] = -1;
ans[38][2] = -1;
ans[39][2] = 57;
ans[40][2] = -1;
ans[41][2] = -1;
ans[42][2] = 67;
ans[43][2] = -1;
ans[44][2] = -1;
ans[45][2] = 77;
ans[46][2] = -1;
ans[47][2] = -1;
ans[48][2] = 87;
ans[49][2] = -1;
ans[50][2] = -1;
ans[51][2] = 97;
ans[52][2] = -1;
ans[53][2] = -1;
ans[54][2] = 197;
ans[55][2] = -1;
ans[56][2] = -1;
ans[57][2] = 297;
ans[58][2] = -1;
ans[59][2] = -1;
ans[60][2] = 397;
ans[61][2] = -1;
ans[62][2] = -1;
ans[63][2] = 497;
ans[64][2] = -1;
ans[65][2] = -1;
ans[66][2] = 597;
ans[67][2] = -1;
ans[68][2] = -1;
ans[69][2] = 697;
ans[70][2] = -1;
ans[71][2] = -1;
ans[72][2] = 797;
ans[73][2] = -1;
ans[74][2] = -1;
ans[75][2] = 897;
ans[76][2] = -1;
ans[77][2] = -1;
ans[78][2] = 997;
ans[79][2] = -1;
ans[80][2] = -1;
ans[81][2] = 1997;
ans[82][2] = -1;
ans[83][2] = -1;
ans[84][2] = 2997;
ans[85][2] = -1;
ans[86][2] = -1;
ans[87][2] = 3997;
ans[88][2] = -1;
ans[89][2] = -1;
ans[90][2] = 4997;
ans[91][2] = -1;
ans[92][2] = -1;
ans[93][2] = 5997;
ans[94][2] = -1;
ans[95][2] = -1;
ans[96][2] = 6997;
ans[97][2] = -1;
ans[98][2] = -1;
ans[99][2] = 7997;
ans[100][2] = -1;
ans[101][2] = -1;
ans[102][2] = 8997;
ans[103][2] = -1;
ans[104][2] = -1;
ans[105][2] = 9997;
ans[106][2] = -1;
ans[107][2] = -1;
ans[108][2] = 19997;
ans[109][2] = -1;
ans[110][2] = -1;
ans[111][2] = 29997;
ans[112][2] = -1;
ans[113][2] = -1;
ans[114][2] = 39997;
ans[115][2] = -1;
ans[116][2] = -1;
ans[117][2] = 49997;
ans[118][2] = -1;
ans[119][2] = -1;
ans[120][2] = 59997;
ans[121][2] = -1;
ans[122][2] = -1;
ans[123][2] = 69997;
ans[124][2] = -1;
ans[125][2] = -1;
ans[126][2] = 79997;
ans[127][2] = -1;
ans[128][2] = -1;
ans[129][2] = 89997;
ans[130][2] = -1;
ans[131][2] = -1;
ans[132][2] = 99997;
ans[133][2] = -1;
ans[134][2] = -1;
ans[135][2] = 199997;
ans[136][2] = -1;
ans[137][2] = -1;
ans[138][2] = 299997;
ans[139][2] = -1;
ans[140][2] = -1;
ans[141][2] = 399997;
ans[142][2] = -1;
ans[143][2] = -1;
ans[144][2] = 499997;
ans[145][2] = -1;
ans[146][2] = -1;
ans[147][2] = 599997;
ans[148][2] = -1;
ans[149][2] = -1;
ans[150][2] = 699997;
ans[1][3] = -1;
ans[2][3] = -1;
ans[3][3] = -1;
ans[4][3] = -1;
ans[5][3] = -1;
ans[6][3] = 0;
ans[7][3] = -1;
ans[8][3] = -1;
ans[9][3] = -1;
ans[10][3] = 1;
ans[11][3] = -1;
ans[12][3] = -1;
ans[13][3] = -1;
ans[14][3] = 2;
ans[15][3] = 9;
ans[16][3] = -1;
ans[17][3] = -1;
ans[18][3] = 3;
ans[19][3] = 19;
ans[20][3] = 8;
ans[21][3] = -1;
ans[22][3] = 4;
ans[23][3] = 29;
ans[24][3] = 18;
ans[25][3] = 7;
ans[26][3] = 5;
ans[27][3] = 39;
ans[28][3] = 28;
ans[29][3] = 17;
ans[30][3] = 6;
ans[31][3] = 49;
ans[32][3] = 38;
ans[33][3] = 27;
ans[34][3] = 16;
ans[35][3] = 59;
ans[36][3] = 48;
ans[37][3] = 37;
ans[38][3] = 26;
ans[39][3] = 69;
ans[40][3] = 58;
ans[41][3] = 47;
ans[42][3] = 36;
ans[43][3] = 79;
ans[44][3] = 68;
ans[45][3] = 57;
ans[46][3] = 46;
ans[47][3] = 89;
ans[48][3] = 78;
ans[49][3] = 67;
ans[50][3] = 56;
ans[51][3] = 189;
ans[52][3] = 88;
ans[53][3] = 77;
ans[54][3] = 66;
ans[55][3] = 289;
ans[56][3] = 188;
ans[57][3] = 87;
ans[58][3] = 76;
ans[59][3] = 389;
ans[60][3] = 288;
ans[61][3] = 187;
ans[62][3] = 86;
ans[63][3] = 489;
ans[64][3] = 388;
ans[65][3] = 287;
ans[66][3] = 96;
ans[67][3] = 589;
ans[68][3] = 488;
ans[69][3] = 387;
ans[70][3] = 196;
ans[71][3] = 689;
ans[72][3] = 588;
ans[73][3] = 487;
ans[74][3] = 296;
ans[75][3] = 789;
ans[76][3] = 688;
ans[77][3] = 587;
ans[78][3] = 396;
ans[79][3] = 889;
ans[80][3] = 788;
ans[81][3] = 687;
ans[82][3] = 496;
ans[83][3] = 989;
ans[84][3] = 888;
ans[85][3] = 787;
ans[86][3] = 596;
ans[87][3] = 1989;
ans[88][3] = 988;
ans[89][3] = 887;
ans[90][3] = 696;
ans[91][3] = 2989;
ans[92][3] = 1988;
ans[93][3] = 987;
ans[94][3] = 796;
ans[95][3] = 3989;
ans[96][3] = 2988;
ans[97][3] = 1987;
ans[98][3] = 896;
ans[99][3] = 4989;
ans[100][3] = 3988;
ans[101][3] = 2987;
ans[102][3] = 996;
ans[103][3] = 5989;
ans[104][3] = 4988;
ans[105][3] = 3987;
ans[106][3] = 1996;
ans[107][3] = 6989;
ans[108][3] = 5988;
ans[109][3] = 4987;
ans[110][3] = 2996;
ans[111][3] = 7989;
ans[112][3] = 6988;
ans[113][3] = 5987;
ans[114][3] = 3996;
ans[115][3] = 8989;
ans[116][3] = 7988;
ans[117][3] = 6987;
ans[118][3] = 4996;
ans[119][3] = 9989;
ans[120][3] = 8988;
ans[121][3] = 7987;
ans[122][3] = 5996;
ans[123][3] = 19989;
ans[124][3] = 9988;
ans[125][3] = 8987;
ans[126][3] = 6996;
ans[127][3] = 29989;
ans[128][3] = 19988;
ans[129][3] = 9987;
ans[130][3] = 7996;
ans[131][3] = 39989;
ans[132][3] = 29988;
ans[133][3] = 19987;
ans[134][3] = 8996;
ans[135][3] = 49989;
ans[136][3] = 39988;
ans[137][3] = 29987;
ans[138][3] = 9996;
ans[139][3] = 59989;
ans[140][3] = 49988;
ans[141][3] = 39987;
ans[142][3] = 19996;
ans[143][3] = 69989;
ans[144][3] = 59988;
ans[145][3] = 49987;
ans[146][3] = 29996;
ans[147][3] = 79989;
ans[148][3] = 69988;
ans[149][3] = 59987;
ans[150][3] = 39996;
ans[1][4] = -1;
ans[2][4] = -1;
ans[3][4] = -1;
ans[4][4] = -1;
ans[5][4] = -1;
ans[6][4] = -1;
ans[7][4] = -1;
ans[8][4] = -1;
ans[9][4] = -1;
ans[10][4] = 0;
ans[11][4] = -1;
ans[12][4] = -1;
ans[13][4] = -1;
ans[14][4] = -1;
ans[15][4] = 1;
ans[16][4] = -1;
ans[17][4] = -1;
ans[18][4] = -1;
ans[19][4] = 9;
ans[20][4] = 2;
ans[21][4] = -1;
ans[22][4] = -1;
ans[23][4] = 8;
ans[24][4] = 19;
ans[25][4] = 3;
ans[26][4] = -1;
ans[27][4] = 7;
ans[28][4] = 18;
ans[29][4] = 29;
ans[30][4] = 4;
ans[31][4] = 6;
ans[32][4] = 17;
ans[33][4] = 28;
ans[34][4] = 39;
ans[35][4] = 5;
ans[36][4] = 16;
ans[37][4] = 27;
ans[38][4] = 38;
ans[39][4] = 49;
ans[40][4] = 15;
ans[41][4] = 26;
ans[42][4] = 37;
ans[43][4] = 48;
ans[44][4] = 59;
ans[45][4] = 25;
ans[46][4] = 36;
ans[47][4] = 47;
ans[48][4] = 58;
ans[49][4] = 69;
ans[50][4] = 35;
ans[51][4] = 46;
ans[52][4] = 57;
ans[53][4] = 68;
ans[54][4] = 79;
ans[55][4] = 45;
ans[56][4] = 56;
ans[57][4] = 67;
ans[58][4] = 78;
ans[59][4] = 89;
ans[60][4] = 55;
ans[61][4] = 66;
ans[62][4] = 77;
ans[63][4] = 88;
ans[64][4] = 189;
ans[65][4] = 65;
ans[66][4] = 76;
ans[67][4] = 87;
ans[68][4] = 188;
ans[69][4] = 289;
ans[70][4] = 75;
ans[71][4] = 86;
ans[72][4] = 187;
ans[73][4] = 288;
ans[74][4] = 389;
ans[75][4] = 85;
ans[76][4] = 186;
ans[77][4] = 287;
ans[78][4] = 388;
ans[79][4] = 489;
ans[80][4] = 95;
ans[81][4] = 286;
ans[82][4] = 387;
ans[83][4] = 488;
ans[84][4] = 589;
ans[85][4] = 195;
ans[86][4] = 386;
ans[87][4] = 487;
ans[88][4] = 588;
ans[89][4] = 689;
ans[90][4] = 295;
ans[91][4] = 486;
ans[92][4] = 587;
ans[93][4] = 688;
ans[94][4] = 789;
ans[95][4] = 395;
ans[96][4] = 586;
ans[97][4] = 687;
ans[98][4] = 788;
ans[99][4] = 889;
ans[100][4] = 495;
ans[101][4] = 686;
ans[102][4] = 787;
ans[103][4] = 888;
ans[104][4] = 989;
ans[105][4] = 595;
ans[106][4] = 786;
ans[107][4] = 887;
ans[108][4] = 988;
ans[109][4] = 1989;
ans[110][4] = 695;
ans[111][4] = 886;
ans[112][4] = 987;
ans[113][4] = 1988;
ans[114][4] = 2989;
ans[115][4] = 795;
ans[116][4] = 986;
ans[117][4] = 1987;
ans[118][4] = 2988;
ans[119][4] = 3989;
ans[120][4] = 895;
ans[121][4] = 1986;
ans[122][4] = 2987;
ans[123][4] = 3988;
ans[124][4] = 4989;
ans[125][4] = 995;
ans[126][4] = 2986;
ans[127][4] = 3987;
ans[128][4] = 4988;
ans[129][4] = 5989;
ans[130][4] = 1995;
ans[131][4] = 3986;
ans[132][4] = 4987;
ans[133][4] = 5988;
ans[134][4] = 6989;
ans[135][4] = 2995;
ans[136][4] = 4986;
ans[137][4] = 5987;
ans[138][4] = 6988;
ans[139][4] = 7989;
ans[140][4] = 3995;
ans[141][4] = 5986;
ans[142][4] = 6987;
ans[143][4] = 7988;
ans[144][4] = 8989;
ans[145][4] = 4995;
ans[146][4] = 6986;
ans[147][4] = 7987;
ans[148][4] = 8988;
ans[149][4] = 9989;
ans[150][4] = 5995;
ans[1][5] = -1;
ans[2][5] = -1;
ans[3][5] = -1;
ans[4][5] = -1;
ans[5][5] = -1;
ans[6][5] = -1;
ans[7][5] = -1;
ans[8][5] = -1;
ans[9][5] = -1;
ans[10][5] = -1;
ans[11][5] = -1;
ans[12][5] = -1;
ans[13][5] = -1;
ans[14][5] = -1;
ans[15][5] = 0;
ans[16][5] = -1;
ans[17][5] = -1;
ans[18][5] = -1;
ans[19][5] = -1;
ans[20][5] = -1;
ans[21][5] = 1;
ans[22][5] = -1;
ans[23][5] = -1;
ans[24][5] = 9;
ans[25][5] = -1;
ans[26][5] = -1;
ans[27][5] = 2;
ans[28][5] = -1;
ans[29][5] = -1;
ans[30][5] = 7;
ans[31][5] = -1;
ans[32][5] = -1;
ans[33][5] = 3;
ans[34][5] = -1;
ans[35][5] = -1;
ans[36][5] = 5;
ans[37][5] = -1;
ans[38][5] = -1;
ans[39][5] = 4;
ans[40][5] = -1;
ans[41][5] = -1;
ans[42][5] = 15;
ans[43][5] = -1;
ans[44][5] = -1;
ans[45][5] = 14;
ans[46][5] = -1;
ans[47][5] = -1;
ans[48][5] = 25;
ans[49][5] = -1;
ans[50][5] = -1;
ans[51][5] = 24;
ans[52][5] = -1;
ans[53][5] = -1;
ans[54][5] = 35;
ans[55][5] = -1;
ans[56][5] = -1;
ans[57][5] = 34;
ans[58][5] = -1;
ans[59][5] = -1;
ans[60][5] = 45;
ans[61][5] = -1;
ans[62][5] = -1;
ans[63][5] = 44;
ans[64][5] = -1;
ans[65][5] = -1;
ans[66][5] = 55;
ans[67][5] = -1;
ans[68][5] = -1;
ans[69][5] = 54;
ans[70][5] = -1;
ans[71][5] = -1;
ans[72][5] = 65;
ans[73][5] = -1;
ans[74][5] = -1;
ans[75][5] = 64;
ans[76][5] = -1;
ans[77][5] = -1;
ans[78][5] = 75;
ans[79][5] = -1;
ans[80][5] = -1;
ans[81][5] = 74;
ans[82][5] = -1;
ans[83][5] = -1;
ans[84][5] = 85;
ans[85][5] = -1;
ans[86][5] = -1;
ans[87][5] = 84;
ans[88][5] = -1;
ans[89][5] = -1;
ans[90][5] = 185;
ans[91][5] = -1;
ans[92][5] = -1;
ans[93][5] = 94;
ans[94][5] = -1;
ans[95][5] = -1;
ans[96][5] = 285;
ans[97][5] = -1;
ans[98][5] = -1;
ans[99][5] = 194;
ans[100][5] = -1;
ans[101][5] = -1;
ans[102][5] = 385;
ans[103][5] = -1;
ans[104][5] = -1;
ans[105][5] = 294;
ans[106][5] = -1;
ans[107][5] = -1;
ans[108][5] = 485;
ans[109][5] = -1;
ans[110][5] = -1;
ans[111][5] = 394;
ans[112][5] = -1;
ans[113][5] = -1;
ans[114][5] = 585;
ans[115][5] = -1;
ans[116][5] = -1;
ans[117][5] = 494;
ans[118][5] = -1;
ans[119][5] = -1;
ans[120][5] = 685;
ans[121][5] = -1;
ans[122][5] = -1;
ans[123][5] = 594;
ans[124][5] = -1;
ans[125][5] = -1;
ans[126][5] = 785;
ans[127][5] = -1;
ans[128][5] = -1;
ans[129][5] = 694;
ans[130][5] = -1;
ans[131][5] = -1;
ans[132][5] = 885;
ans[133][5] = -1;
ans[134][5] = -1;
ans[135][5] = 794;
ans[136][5] = -1;
ans[137][5] = -1;
ans[138][5] = 985;
ans[139][5] = -1;
ans[140][5] = -1;
ans[141][5] = 894;
ans[142][5] = -1;
ans[143][5] = -1;
ans[144][5] = 1985;
ans[145][5] = -1;
ans[146][5] = -1;
ans[147][5] = 994;
ans[148][5] = -1;
ans[149][5] = -1;
ans[150][5] = 2985;
ans[1][6] = -1;
ans[2][6] = -1;
ans[3][6] = -1;
ans[4][6] = -1;
ans[5][6] = -1;
ans[6][6] = -1;
ans[7][6] = -1;
ans[8][6] = -1;
ans[9][6] = -1;
ans[10][6] = -1;
ans[11][6] = -1;
ans[12][6] = -1;
ans[13][6] = -1;
ans[14][6] = -1;
ans[15][6] = -1;
ans[16][6] = -1;
ans[17][6] = -1;
ans[18][6] = -1;
ans[19][6] = -1;
ans[20][6] = -1;
ans[21][6] = 0;
ans[22][6] = -1;
ans[23][6] = -1;
ans[24][6] = -1;
ans[25][6] = -1;
ans[26][6] = -1;
ans[27][6] = -1;
ans[28][6] = 1;
ans[29][6] = -1;
ans[30][6] = 9;
ans[31][6] = -1;
ans[32][6] = 8;
ans[33][6] = -1;
ans[34][6] = 7;
ans[35][6] = 2;
ans[36][6] = 6;
ans[37][6] = 19;
ans[38][6] = 5;
ans[39][6] = 18;
ans[40][6] = 4;
ans[41][6] = 17;
ans[42][6] = 3;
ans[43][6] = 16;
ans[44][6] = 29;
ans[45][6] = 15;
ans[46][6] = 28;
ans[47][6] = 14;
ans[48][6] = 27;
ans[49][6] = 13;
ans[50][6] = 26;
ans[51][6] = 39;
ans[52][6] = 25;
ans[53][6] = 38;
ans[54][6] = 24;
ans[55][6] = 37;
ans[56][6] = 23;
ans[57][6] = 36;
ans[58][6] = 49;
ans[59][6] = 35;
ans[60][6] = 48;
ans[61][6] = 34;
ans[62][6] = 47;
ans[63][6] = 33;
ans[64][6] = 46;
ans[65][6] = 59;
ans[66][6] = 45;
ans[67][6] = 58;
ans[68][6] = 44;
ans[69][6] = 57;
ans[70][6] = 43;
ans[71][6] = 56;
ans[72][6] = 69;
ans[73][6] = 55;
ans[74][6] = 68;
ans[75][6] = 54;
ans[76][6] = 67;
ans[77][6] = 53;
ans[78][6] = 66;
ans[79][6] = 79;
ans[80][6] = 65;
ans[81][6] = 78;
ans[82][6] = 64;
ans[83][6] = 77;
ans[84][6] = 63;
ans[85][6] = 76;
ans[86][6] = 89;
ans[87][6] = 75;
ans[88][6] = 88;
ans[89][6] = 74;
ans[90][6] = 87;
ans[91][6] = 73;
ans[92][6] = 86;
ans[93][6] = 189;
ans[94][6] = 85;
ans[95][6] = 188;
ans[96][6] = 84;
ans[97][6] = 187;
ans[98][6] = 83;
ans[99][6] = 186;
ans[100][6] = 289;
ans[101][6] = 185;
ans[102][6] = 288;
ans[103][6] = 184;
ans[104][6] = 287;
ans[105][6] = 93;
ans[106][6] = 286;
ans[107][6] = 389;
ans[108][6] = 285;
ans[109][6] = 388;
ans[110][6] = 284;
ans[111][6] = 387;
ans[112][6] = 193;
ans[113][6] = 386;
ans[114][6] = 489;
ans[115][6] = 385;
ans[116][6] = 488;
ans[117][6] = 384;
ans[118][6] = 487;
ans[119][6] = 293;
ans[120][6] = 486;
ans[121][6] = 589;
ans[122][6] = 485;
ans[123][6] = 588;
ans[124][6] = 484;
ans[125][6] = 587;
ans[126][6] = 393;
ans[127][6] = 586;
ans[128][6] = 689;
ans[129][6] = 585;
ans[130][6] = 688;
ans[131][6] = 584;
ans[132][6] = 687;
ans[133][6] = 493;
ans[134][6] = 686;
ans[135][6] = 789;
ans[136][6] = 685;
ans[137][6] = 788;
ans[138][6] = 684;
ans[139][6] = 787;
ans[140][6] = 593;
ans[141][6] = 786;
ans[142][6] = 889;
ans[143][6] = 785;
ans[144][6] = 888;
ans[145][6] = 784;
ans[146][6] = 887;
ans[147][6] = 693;
ans[148][6] = 886;
ans[149][6] = 989;
ans[150][6] = 885;
ans[1][7] = -1;
ans[2][7] = -1;
ans[3][7] = -1;
ans[4][7] = -1;
ans[5][7] = -1;
ans[6][7] = -1;
ans[7][7] = -1;
ans[8][7] = -1;
ans[9][7] = -1;
ans[10][7] = -1;
ans[11][7] = -1;
ans[12][7] = -1;
ans[13][7] = -1;
ans[14][7] = -1;
ans[15][7] = -1;
ans[16][7] = -1;
ans[17][7] = -1;
ans[18][7] = -1;
ans[19][7] = -1;
ans[20][7] = -1;
ans[21][7] = -1;
ans[22][7] = -1;
ans[23][7] = -1;
ans[24][7] = -1;
ans[25][7] = -1;
ans[26][7] = -1;
ans[27][7] = -1;
ans[28][7] = 0;
ans[29][7] = -1;
ans[30][7] = -1;
ans[31][7] = -1;
ans[32][7] = -1;
ans[33][7] = -1;
ans[34][7] = -1;
ans[35][7] = -1;
ans[36][7] = 1;
ans[37][7] = 9;
ans[38][7] = 8;
ans[39][7] = 7;
ans[40][7] = 6;
ans[41][7] = 5;
ans[42][7] = 4;
ans[43][7] = 3;
ans[44][7] = 2;
ans[45][7] = 19;
ans[46][7] = 18;
ans[47][7] = 17;
ans[48][7] = 16;
ans[49][7] = 15;
ans[50][7] = 14;
ans[51][7] = 13;
ans[52][7] = 12;
ans[53][7] = 29;
ans[54][7] = 28;
ans[55][7] = 27;
ans[56][7] = 26;
ans[57][7] = 25;
ans[58][7] = 24;
ans[59][7] = 23;
ans[60][7] = 22;
ans[61][7] = 39;
ans[62][7] = 38;
ans[63][7] = 37;
ans[64][7] = 36;
ans[65][7] = 35;
ans[66][7] = 34;
ans[67][7] = 33;
ans[68][7] = 32;
ans[69][7] = 49;
ans[70][7] = 48;
ans[71][7] = 47;
ans[72][7] = 46;
ans[73][7] = 45;
ans[74][7] = 44;
ans[75][7] = 43;
ans[76][7] = 42;
ans[77][7] = 59;
ans[78][7] = 58;
ans[79][7] = 57;
ans[80][7] = 56;
ans[81][7] = 55;
ans[82][7] = 54;
ans[83][7] = 53;
ans[84][7] = 52;
ans[85][7] = 69;
ans[86][7] = 68;
ans[87][7] = 67;
ans[88][7] = 66;
ans[89][7] = 65;
ans[90][7] = 64;
ans[91][7] = 63;
ans[92][7] = 62;
ans[93][7] = 79;
ans[94][7] = 78;
ans[95][7] = 77;
ans[96][7] = 76;
ans[97][7] = 75;
ans[98][7] = 74;
ans[99][7] = 73;
ans[100][7] = 72;
ans[101][7] = 89;
ans[102][7] = 88;
ans[103][7] = 87;
ans[104][7] = 86;
ans[105][7] = 85;
ans[106][7] = 84;
ans[107][7] = 83;
ans[108][7] = 82;
ans[109][7] = 189;
ans[110][7] = 188;
ans[111][7] = 187;
ans[112][7] = 186;
ans[113][7] = 185;
ans[114][7] = 184;
ans[115][7] = 183;
ans[116][7] = 92;
ans[117][7] = 289;
ans[118][7] = 288;
ans[119][7] = 287;
ans[120][7] = 286;
ans[121][7] = 285;
ans[122][7] = 284;
ans[123][7] = 283;
ans[124][7] = 192;
ans[125][7] = 389;
ans[126][7] = 388;
ans[127][7] = 387;
ans[128][7] = 386;
ans[129][7] = 385;
ans[130][7] = 384;
ans[131][7] = 383;
ans[132][7] = 292;
ans[133][7] = 489;
ans[134][7] = 488;
ans[135][7] = 487;
ans[136][7] = 486;
ans[137][7] = 485;
ans[138][7] = 484;
ans[139][7] = 483;
ans[140][7] = 392;
ans[141][7] = 589;
ans[142][7] = 588;
ans[143][7] = 587;
ans[144][7] = 586;
ans[145][7] = 585;
ans[146][7] = 584;
ans[147][7] = 583;
ans[148][7] = 492;
ans[149][7] = 689;
ans[150][7] = 688;
ans[1][8] = -1;
ans[2][8] = -1;
ans[3][8] = -1;
ans[4][8] = -1;
ans[5][8] = -1;
ans[6][8] = -1;
ans[7][8] = -1;
ans[8][8] = -1;
ans[9][8] = -1;
ans[10][8] = -1;
ans[11][8] = -1;
ans[12][8] = -1;
ans[13][8] = -1;
ans[14][8] = -1;
ans[15][8] = -1;
ans[16][8] = -1;
ans[17][8] = -1;
ans[18][8] = -1;
ans[19][8] = -1;
ans[20][8] = -1;
ans[21][8] = -1;
ans[22][8] = -1;
ans[23][8] = -1;
ans[24][8] = -1;
ans[25][8] = -1;
ans[26][8] = -1;
ans[27][8] = -1;
ans[28][8] = -1;
ans[29][8] = -1;
ans[30][8] = -1;
ans[31][8] = -1;
ans[32][8] = -1;
ans[33][8] = -1;
ans[34][8] = -1;
ans[35][8] = -1;
ans[36][8] = 0;
ans[37][8] = -1;
ans[38][8] = -1;
ans[39][8] = -1;
ans[40][8] = -1;
ans[41][8] = -1;
ans[42][8] = -1;
ans[43][8] = -1;
ans[44][8] = -1;
ans[45][8] = 1;
ans[46][8] = -1;
ans[47][8] = -1;
ans[48][8] = -1;
ans[49][8] = -1;
ans[50][8] = -1;
ans[51][8] = -1;
ans[52][8] = -1;
ans[53][8] = -1;
ans[54][8] = 11;
ans[55][8] = -1;
ans[56][8] = -1;
ans[57][8] = -1;
ans[58][8] = -1;
ans[59][8] = -1;
ans[60][8] = -1;
ans[61][8] = -1;
ans[62][8] = -1;
ans[63][8] = 21;
ans[64][8] = -1;
ans[65][8] = -1;
ans[66][8] = -1;
ans[67][8] = -1;
ans[68][8] = -1;
ans[69][8] = -1;
ans[70][8] = -1;
ans[71][8] = -1;
ans[72][8] = 31;
ans[73][8] = -1;
ans[74][8] = -1;
ans[75][8] = -1;
ans[76][8] = -1;
ans[77][8] = -1;
ans[78][8] = -1;
ans[79][8] = -1;
ans[80][8] = -1;
ans[81][8] = 41;
ans[82][8] = -1;
ans[83][8] = -1;
ans[84][8] = -1;
ans[85][8] = -1;
ans[86][8] = -1;
ans[87][8] = -1;
ans[88][8] = -1;
ans[89][8] = -1;
ans[90][8] = 51;
ans[91][8] = -1;
ans[92][8] = -1;
ans[93][8] = -1;
ans[94][8] = -1;
ans[95][8] = -1;
ans[96][8] = -1;
ans[97][8] = -1;
ans[98][8] = -1;
ans[99][8] = 61;
ans[100][8] = -1;
ans[101][8] = -1;
ans[102][8] = -1;
ans[103][8] = -1;
ans[104][8] = -1;
ans[105][8] = -1;
ans[106][8] = -1;
ans[107][8] = -1;
ans[108][8] = 71;
ans[109][8] = -1;
ans[110][8] = -1;
ans[111][8] = -1;
ans[112][8] = -1;
ans[113][8] = -1;
ans[114][8] = -1;
ans[115][8] = -1;
ans[116][8] = -1;
ans[117][8] = 81;
ans[118][8] = -1;
ans[119][8] = -1;
ans[120][8] = -1;
ans[121][8] = -1;
ans[122][8] = -1;
ans[123][8] = -1;
ans[124][8] = -1;
ans[125][8] = -1;
ans[126][8] = 91;
ans[127][8] = -1;
ans[128][8] = -1;
ans[129][8] = -1;
ans[130][8] = -1;
ans[131][8] = -1;
ans[132][8] = -1;
ans[133][8] = -1;
ans[134][8] = -1;
ans[135][8] = 191;
ans[136][8] = -1;
ans[137][8] = -1;
ans[138][8] = -1;
ans[139][8] = -1;
ans[140][8] = -1;
ans[141][8] = -1;
ans[142][8] = -1;
ans[143][8] = -1;
ans[144][8] = 291;
ans[145][8] = -1;
ans[146][8] = -1;
ans[147][8] = -1;
ans[148][8] = -1;
ans[149][8] = -1;
ans[150][8] = -1;
ans[1][9] = -1;
ans[2][9] = -1;
ans[3][9] = -1;
ans[4][9] = -1;
ans[5][9] = -1;
ans[6][9] = -1;
ans[7][9] = -1;
ans[8][9] = -1;
ans[9][9] = -1;
ans[10][9] = -1;
ans[11][9] = -1;
ans[12][9] = -1;
ans[13][9] = -1;
ans[14][9] = -1;
ans[15][9] = -1;
ans[16][9] = -1;
ans[17][9] = -1;
ans[18][9] = -1;
ans[19][9] = -1;
ans[20][9] = -1;
ans[21][9] = -1;
ans[22][9] = -1;
ans[23][9] = -1;
ans[24][9] = -1;
ans[25][9] = -1;
ans[26][9] = -1;
ans[27][9] = -1;
ans[28][9] = -1;
ans[29][9] = -1;
ans[30][9] = -1;
ans[31][9] = -1;
ans[32][9] = -1;
ans[33][9] = -1;
ans[34][9] = -1;
ans[35][9] = -1;
ans[36][9] = -1;
ans[37][9] = -1;
ans[38][9] = -1;
ans[39][9] = -1;
ans[40][9] = -1;
ans[41][9] = -1;
ans[42][9] = -1;
ans[43][9] = -1;
ans[44][9] = -1;
ans[45][9] = 0;
ans[46][9] = 1;
ans[47][9] = 2;
ans[48][9] = 3;
ans[49][9] = 4;
ans[50][9] = 5;
ans[51][9] = 6;
ans[52][9] = 7;
ans[53][9] = 8;
ans[54][9] = 9;
ans[55][9] = 10;
ans[56][9] = 11;
ans[57][9] = 12;
ans[58][9] = 13;
ans[59][9] = 14;
ans[60][9] = 15;
ans[61][9] = 16;
ans[62][9] = 17;
ans[63][9] = 18;
ans[64][9] = 19;
ans[65][9] = 20;
ans[66][9] = 21;
ans[67][9] = 22;
ans[68][9] = 23;
ans[69][9] = 24;
ans[70][9] = 25;
ans[71][9] = 26;
ans[72][9] = 27;
ans[73][9] = 28;
ans[74][9] = 29;
ans[75][9] = 30;
ans[76][9] = 31;
ans[77][9] = 32;
ans[78][9] = 33;
ans[79][9] = 34;
ans[80][9] = 35;
ans[81][9] = 36;
ans[82][9] = 37;
ans[83][9] = 38;
ans[84][9] = 39;
ans[85][9] = 40;
ans[86][9] = 41;
ans[87][9] = 42;
ans[88][9] = 43;
ans[89][9] = 44;
ans[90][9] = 45;
ans[91][9] = 46;
ans[92][9] = 47;
ans[93][9] = 48;
ans[94][9] = 49;
ans[95][9] = 50;
ans[96][9] = 51;
ans[97][9] = 52;
ans[98][9] = 53;
ans[99][9] = 54;
ans[100][9] = 55;
ans[101][9] = 56;
ans[102][9] = 57;
ans[103][9] = 58;
ans[104][9] = 59;
ans[105][9] = 60;
ans[106][9] = 61;
ans[107][9] = 62;
ans[108][9] = 63;
ans[109][9] = 64;
ans[110][9] = 65;
ans[111][9] = 66;
ans[112][9] = 67;
ans[113][9] = 68;
ans[114][9] = 69;
ans[115][9] = 70;
ans[116][9] = 71;
ans[117][9] = 72;
ans[118][9] = 73;
ans[119][9] = 74;
ans[120][9] = 75;
ans[121][9] = 76;
ans[122][9] = 77;
ans[123][9] = 78;
ans[124][9] = 79;
ans[125][9] = 80;
ans[126][9] = 81;
ans[127][9] = 82;
ans[128][9] = 83;
ans[129][9] = 84;
ans[130][9] = 85;
ans[131][9] = 86;
ans[132][9] = 87;
ans[133][9] = 88;
ans[134][9] = 89;
ans[135][9] = 90;
ans[136][9] = 181;
ans[137][9] = 182;
ans[138][9] = 183;
ans[139][9] = 184;
ans[140][9] = 185;
ans[141][9] = 186;
ans[142][9] = 187;
ans[143][9] = 188;
ans[144][9] = 189;
ans[145][9] = 190;
ans[146][9] = 281;
ans[147][9] = 282;
ans[148][9] = 283;
ans[149][9] = 284;
ans[150][9] = 285;

	int t;
	cin >> t;
	REP(i, t) {
		int n, k;
		cin >> n >> k;
		cout << ans[n][k] << "\n";
	}
}