#include <iostream>
#include <fstream>
using namespace std;
class Data
{
public:
	// ������ : "point.dat" ������ �������� �ʴ´ٸ� ������ �����, �б�&��������� �ٽ� ����.    
	Data()
	{
		fio.open("point.dat", ios_base::in | ios_base::out | ios_base::binary);
		if (!fio)       // ���ٸ�
		{
			cout << "������ �������� ����. ���� ����!" << endl;
			fio.open("point.dat", ios_base::out | ios_base::binary);
			fio.close();  // ���� ���� �� �ٷ� �ݱ�

			fio.open("point.dat", ios_base::in | ios_base::out | ios_base::binary);
		}
	}
	~Data() { fio.close(); }
	void Run()
	{
		int mode;
		int data;
		while (1) {
			cout << "�޴� ����<1-����, 2-�߰�, 3-ȭ�����, 0-����> : ";
			cin >> mode;
			switch (mode) {
				case 1:
					int n;
					fio.seekp(0, ios_base::end);
					cout << "������ ������ index�� �� �Է� : ";
					scanf_s("%d %d", &n, &data);
			while (0 >= n || n >= (fio.tellp() / sizeof(int))) {
				cout << "index�� ���� �����ϴ�. �ٽ� ������ ������ index�� �� �Է� : ";
						scanf_s("%d %d", &n, &data);
					}
					fio.seekp(n * sizeof(int), ios_base::beg);
					fio.write((char*)&data, sizeof(int));
					break;
				case 2:
					cout<<"�߰��� ���� ���� �Է��ϼ��� : ";
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


