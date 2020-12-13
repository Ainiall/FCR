#include <iostream>

using namespace std;

extern "C" bool IsValidAssembly(int a, int b, int c);


void invalidAccess() {
	exit(1);
}
void checkPassword() {
	const unsigned int maxCad = 7;
	char contrasena[maxCad];
	cout << "Contraseña: ";
	cin.getline(contrasena, maxCad);
	cout << endl;
	char aux[] = "fGCtl9";
	bool is = false;
	for (int i = 0; i < 6; i++)
	{
		if (contrasena[i] != aux[i]) {
			is = true;
		}
	}
	if (is == true) {
		invalidAccess();
	}
}
void checkBits() {
	int num1, num2;
	cout << "Dame el primer numero: ";
	cin >> num1;
	cout << endl;
	cout << "Dame el segundo numero: ";
	cin >> num2;
	cout << endl;
	int mascM = (num1 &  0x00100000) >> 20;
	int masc28 = (num1 & 0x10000000) >> 28;
	int masc7= (num2 & 0x00000080) >> 7;
	int masc17M= (num1 & 0xffff8000);
	int mascMe= (num2 &  0x00007ffff) ;
	int mascSumada = masc17M | mascMe;

	if (mascM != 1) {
		num1 = num1 & 0xfffffffe;
		invalidAccess();
	}
	if (masc28 != masc7) {
		invalidAccess();
	}
	if (mascSumada < 9285) {
		invalidAccess();
	}
}
void checkAssembly() {
	int a, b, c, resultado;;
	cout << "Dame valor a: ";
	cin >> a;
	cout << endl;
	cout << "Dame valor b: ";
	cin >> b;
	cout<<endl;
	cout << "Dame valor c: ";
	cin >> c;
	cout << endl;
	bool result=IsValidAssembly(a, b, c);

	if (result == false) {
		invalidAccess();
	}

}

void checkInlineAssembly() {
	int num;
	cout << "Dame numero: ";
	cin >> num;
	cout << endl;
	__asm {
		mov eax, 00000040h
		and eax, num
		mov ebx, 00004000h
		and ebx, num
		shr eax, 6
		shr ebx,14
		cmp eax, ebx
		je consecuente
		mov num, 0
		jmp siguiente
		consecuente :
		mov num, 1
			siguiente :

	}
	if (num == 0) {
		invalidAccess();
	}
	else {
		cout << "Valid access" << endl;
	}
}
int main()
{
	/*setlocale(LC_ALL, "spanish");
	checkPassword();
	checkBits();
	checkAssembly();*/
	checkInlineAssembly();

	system("PAUSE()");

	return 0;
}
