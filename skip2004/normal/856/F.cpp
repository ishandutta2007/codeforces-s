#include<bits/stdc++.h>
typedef unsigned long long u64;
inline u64 gen(u64 x) { return x ^= x << 13, x ^= x >> 7, x ^= x << 17; }
std::map<u64, u64> map = {
	{12807924072251749236,25},
	{8316942776798443357,125},
	{1427138097708291513,230},
	{13880348951595021113,120},
	{6374836989393964970,27},
	{6374836991524949803,26},
	{1617718956769881006, 2000000000000000000},
	{13104906001067308152,2},
	{6374836542479079162,52},
	{1997500239843237258,53},
	{5005434723849298790,207},
	{705889088240544217,6699},
	{7321221188472650894,6812},
	{13284730628184471094,622832834},
	{6866128521784462594,620189650},
	{14983406519702253193,624668154},
	{14986992737031916708,625406094},
	{15224900970971026899,12972},
	{7657887909776344917,12972},
	{10759796125372197250,216245},
	{7027837586770640842,216245},
	{4670933202406654248,240314083},
	{10338390062674655084,240314083},
	{5461628462320801029,122973},
	{16696814090209157332,1038071},
	{14376707829214466416,20203527703},
	{7011678043931836694,19018621728},
	{527898215563447140,247432457339710},
	{9406324644475704115,229533246298127},
	{11225131137915910858,20929602014808},
	{2935760206482797523,7900},
	{1975800214784338554,17544094280356},
	{5359405218643444672,17544044596722},
	{5871972456727461334,17469733613212},
	{5697754496098349964,27728032700840},
	{16953734000944670709,221336290388556},


};

int main() {
	u64 x = 0, ans = 0;
	for(int i = 0;i < 5;++i) std::cin >> x, ans = gen(ans) + x;
	std::cout << map[ans] << '\n';
}