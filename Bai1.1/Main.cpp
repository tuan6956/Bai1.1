#include <iostream>
using namespace std;
long GiaiThua(int n);
long HoanVi(int n);
long ChinhHop(int n, int r);
long ToHop(int n, int r);
long ChinhHopLap(int n, int r);
long ToHopLap(int n, int r);

void main()
{
	cout<<ToHopLap(6,3);
	system("pause");
}

long HoanVi(int n)
{
	return GiaiThua(n);
}
long GiaiThua(int n)
{
	if (n == 1 || n == 0)
		return 1;
	else
		return n*GiaiThua(n - 1);
}
long ChinhHop(int n, int r)
{
	return GiaiThua(n) / (GiaiThua(n - r));
}
long ToHop(int n, int r)
{
	return ChinhHop(n, r) / GiaiThua(r);
}
long ChinhHopLap(int n, int r)
{
	return pow(n, r);
}
long ToHopLap(int n, int r)
{
	return ToHop(n + r - 1, r);
}
