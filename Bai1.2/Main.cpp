#include <iostream>
using namespace std;
bool KiemTra2BitLienTiep(int *arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] == 0 && arr[i + 1] == 0)
			return true;
	}
	return false;
}
bool KiemTra11(int *arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] == 1 && arr[i + 1] == 1)
			return true;
	}
	return false;
}
void LietKeChuoiBit(int *KQ, int n, int temp)
{
	if (!KiemTra2BitLienTiep(KQ, n))
	{
		for (int i = 0; i < n; i++)
			cout << KQ[i];
		cout << endl;
	}
	for (temp; temp < n; temp++)
	{
		KQ[temp] = 1;
		LietKeChuoiBit(KQ, n, temp + 1);
		KQ[temp] = 0;
	}
}
void XuatBit11(int *KQ, int n, int temp)
{
	if (KiemTra11(KQ, n))
	{
		for (int i = 0; i < n; i++)
			cout << KQ[i];
		cout << endl;
	}
	for (temp; temp < n; temp++)
	{
		KQ[temp] = 1;
		XuatBit11(KQ, n, temp + 1);
		KQ[temp] = 0;
	}
}
void main()
{
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = 0;
	cout << "Khong chua 2 bit 0 lien tiep\n";
	LietKeChuoiBit(a, n, 0);
	cout << "Chua 2 bit 1 lien tiep\n";
	XuatBit11(a, n, 0);
	delete[] a;
	cin.get();
	cin.get();
}