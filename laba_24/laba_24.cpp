#include <iostream>
#include <windows.h>
using namespace std;
HANDLE mutex;
HANDLE g_hEvent[2];
HANDLE g_hEventtwo;

DWORD WINAPI Scout(PVOID pvParam) {
	int sms;
	WaitForSingleObject(mutex, INFINITE);
	if (WaitForSingleObject(g_hEventtwo, 20) == WAIT_TIMEOUT) 
	{
		cout << "Введите специальное событие - 1 или 2: \n";
		cin >> sms;
		cout << "Выбранное событие: " << sms << "\n";
		if (sms != 1 && sms != 2) 
		{
			cout << "Данные введены некорректно!\n";
		}

	}
	else {
		ReleaseMutex(mutex);
		return 1;
	}

}

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, ".1251");
	int numb = 0;

	cout << "Введите число скаутов: ";
	cin >> numb;

	for (int i = 0; i < 4; i++) 
	{
		g_hEvent[i] = CreateEventA(0, 0, 0, 0);
	}
	g_hEventtwo = CreateEventA(0, 1, 0, 0);
	mutex = CreateMutexA(0, 1, 0);

	HANDLE* hThreads = new HANDLE[numb];
	for (int i = 0; i < numb; i++) 
	{
		hThreads[i] = CreateThread(0, 0, Scout, 0, 0, 0);
	}
	ReleaseMutex(mutex);
	for (int i = 0; i < 2; i++) 
	{
		WaitForMultipleObjects(2, g_hEvent, 0, INFINITE);
		cout << "Сообщение доставлено\n" << i + 1 << endl;

	}
	cout << "Работа завершена";
	CloseHandle(hThreads);
	WaitForSingleObject(mutex, INFINITE);
	
}
