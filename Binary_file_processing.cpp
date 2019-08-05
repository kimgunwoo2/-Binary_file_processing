#include <iostream>
#include <fstream>
using namespace std;
class Data
{
public:
	// 생성자 : "point.dat" 파일이 존재하지 않는다면 파일을 만들고, 읽기&쓰기용으로 다시 연다.    
	Data()
	{
		fio.open("point.dat", ios_base::in | ios_base::out | ios_base::binary);
		if (!fio)       // 없다면
		{
			cout << "파일이 존재하지 않음. 새로 만듦!" << endl;
			fio.open("point.dat", ios_base::out | ios_base::binary);
			fio.close();  // 파일 생성 후 바로 닫기

			fio.open("point.dat", ios_base::in | ios_base::out | ios_base::binary);
		}
	}
	~Data() { fio.close(); }
	void Run()
	{
		int mode;
		int data;
		while (1) {
			cout << "메뉴 선택<1-수정, 2-추가, 3-화면출력, 0-종료> : ";
			cin >> mode;
			switch (mode) {
				case 1:
					int n;
					fio.seekp(0, ios_base::end);
					cout << "수정할 정수의 index와 값 입력 : ";
					scanf_s("%d %d", &n, &data);
			while (0 >= n || n >= (fio.tellp() / sizeof(int))) {
				cout << "index에 값이 없습니다. 다시 수정할 정수의 index와 값 입력 : ";
						scanf_s("%d %d", &n, &data);
					}
					fio.seekp(n * sizeof(int), ios_base::beg);
					fio.write((char*)&data, sizeof(int));
					break;
				case 2:
					cout<<"추가할 정수 값을 입력하세요 : ";
					scanf_s("%d", &data);
					fio.write((char*)&data, sizeof(int));
					break;
				case 3:
					fio.seekg(0, ios_base::beg);
					while (fio.read((char*)&data, sizeof(int)))
						cout << data << "  ";
					cout << endl;
					fio.clear();
					break;
				case 0:

					return;
			}
		}
	}
private:
	fstream fio;
};

int main()
{
	Data data;
	data.Run();

	return 0;
}


