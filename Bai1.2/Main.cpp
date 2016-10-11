#include <iostream>
#include <vector>
using namespace std;
//int iN, k, a[10];
int a[1000];
int DanhDau[1000];
int dem = 0;
bool check = false;
void XuatVecto(vector<int> vecto);
long TongGiaiThua(int n);
void Chinhhoplap(int n, int k);
void display(int k);
void QuayLuiToHop(int i, int k, int n);
void QuayLuiChinhHop(int i, int k, int n);

void Hoanvi(int n);
void ChinhHop(int k, int n);
void ChinhHopLap(int k, int n);
void ToHop(int k, int n);
//void ToHopLap(int k, int n);
void ToHopLap(int **arr, int n, int *KQHoanVi, int r, int index, int temp, int &dem);
void main()
{

	//int a[100];
	int k = 5;
	int n = 3;
	//Chinh hop lap chập k của n phần tử(k,n)
	//ChinhHopLap(5, 3);

	//Tổ hợp
	//ToHop(3, 5);

	//Chỉnh Hơp
	//ChinhHop(3, 5);



	//Tổ hợp lặp(k,n)
	/*int **ab = new int*[n];
	for (int i = 0; i < n; i++)
		ab[i] = new int[2];
	int *b = new int[n];
	for (int i = 0; i < n; i++)
	{
		ab[i][0] = i + 1;
		ab[i][1] = 0;
	}
	int dem = 1;
	ToHopLap(ab, n, b, k, 0, 0, dem);*/
	system("pause");
}

void ChinhHopLap(int k, int n)
{
	for (int i = 1; i <= k; i++)
	{
		a[i] = 1;
	}
	while (!check) {
		display(k);
		Chinhhoplap(n, k);
	}
}
void display(int k)
{
	cout << ++dem << " : ";
	for (int i = 1; i <= k; i++)
	{
		cout << a[i];
	}
	cout << endl;
}
void Chinhhoplap(int n, int k)
{
	int i = k;
	while (a[i] == n &&i > 0)
	{
		i--;
	}
	if (i == 0) check = true;
	else
	{
		a[i]++;
		for (int j = i + 1; j <= k; j++)
		{
			a[j] = 1;
		}

	}
}

void ToHopLap(int **arr, int n, int *KQHoanVi, int r, int index, int temp, int &dem)
{
	if (index >= r)
	{
		cout <<  dem << " : ";
		for (int i = 0; i < r; i++)
		{
			cout << KQHoanVi[i] << ",";
		}
		cout << endl;
		dem++;
		return;
	}
	for (temp; temp < n; temp++)
	{
		KQHoanVi[index] = arr[temp][0];
		ToHopLap(arr, n, KQHoanVi, r, index + 1, temp, dem);
	}
}

void XuatVecto(vector<int> vecto)
{
	for (int i = 0; i < vecto.size(); i++)
	{
		cout << vecto[i];
	}
	cout << endl;
}
long GiaiThua(int n)
{
	if (n == 1 || n == 0)
		return 1;
	else
		return n*GiaiThua(n - 1);
}
long TongGiaiThua(int n)
{
	long temp = 0;
	for (int i = 1; i <= n; i++)
	{
		temp += GiaiThua(i);
	}
	return temp;
}
void Hoanvi(int n)
{
	//n = GiaiThua(n);
	int iCounter = 1;
	int vitri = 0;
	int value = 1;
	int iThutu = 1;
	vector<int>  hoanvi[1000];
	hoanvi[vitri].push_back(iCounter);
	++vitri;
	//iCounter = 2;

	value = iCounter;
	for (int i = 0; i < iCounter; i++)
	{
		if (hoanvi[i].size() == value)
		{
			for (int j = 0; j < value + 1; j++)
			{
				hoanvi[vitri] = hoanvi[i];
				if (j == value)
				{
					hoanvi[vitri].push_back(value + 1);
					vitri++;
				}
				else
				{
					vector<int>::iterator it;
					it = hoanvi[vitri].begin() + j;
					hoanvi[vitri].insert(it, value + 1);
					vitri++;
				}
			}
		}
		iCounter++;
		int dem = 0;
		for (int count = 0; count < vitri; count++)
		{
			if (hoanvi[count].size() == value + 1)
			{
				dem++;
			}
		}
		if (dem == GiaiThua(value + 1))
		{
			value++;
		}
		if (vitri == TongGiaiThua(n))
		{
			break;
		}
	}
	for (int i = 0; i < vitri; i++)
	{
		if (hoanvi[i].size() == n)
		{
			cout << iThutu++ << " : ";
			XuatVecto(hoanvi[i]);
		}
	}
}
//void ChinhHop(int n, int k)
//{
//	vector<int> chinhhop[1000];
//	//chinhhop[0].push_back(1);
//	int iCounter = 0;
//	for (int i = 0; i < n; i++)
//	{
//		
//		
//	}
//}
void ToHop(int k, int n)
{
	a[0] = 0;
	QuayLuiToHop(1, k, n);
}
void ChinhHop(int k, int n)
{
	a[0] = 0;
	QuayLuiChinhHop(0, k, n);
}
void QuayLuiToHop(int i, int k, int n)
{
	for (int j = a[i - 1] + 1; j <= n - k + i; j++)
	{
		a[i] = j;
		if (i == k) {

			display(k);
		}
		else 
		{
			QuayLuiToHop(i + 1, k, n);
		}

	}
}
void QuayLuiChinhHop(int i, int k, int n)
{
	if (i == k)
		display(k);
	else
	{
		for (int j = 0; j < n; j++)
			if (DanhDau[j] == 0) //neu dinh j chua duoc chon
			{
				DanhDau[j] = 1; //chon dinh j
				a[i] = j; //luu lai gia tri j
				QuayLuiChinhHop(i + 1, k, n); //tim phan tu tiep theo
				DanhDau[j] = 0; //phuc hoi dinh j
			}
	}
}
