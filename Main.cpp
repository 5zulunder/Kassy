#include <iostream>
using namespace std;

void main() {

	setlocale(LC_ALL, "ru");
	double total_cash = 0; //����� � �����
	int next = 1;
	while (next == 1) {

		double cash_check = 0; //����� ����
		int price_arr[]{ 0,48,65,35,98,250 };//�����,����,�������,���,������,�������
		const int as = sizeof(price_arr) / sizeof(price_arr[0]); //���������� �������� ������� �������(���-�� ��������� � ��������)
		int toal_price_prod_arr[as]{}; //������ ���� ������� �������� � ����
		int count_arr[as]{}; //������ �������� ���������� ������� ��������
		string name_arr[]{ "empty","Bread","Chocolate","Juice","Milk","Toy" }; // empty �� ������������(���� ����������)


		cout << "\t\t\t\t\t\t****************" <<
			endl << "\t\t\t\t\t\t*Programm KASSY*" <<
			endl << "\t\t\t\t\t\t****************" << endl;
		cout << "\t\t\t\t\t\t Total cash = " << total_cash << "���." << endl;


		while (true) {
			cout << "������� ���, ������� - 0 " << endl
				<< "1 - Bread " << price_arr[1] << " ���.\n"
				<< "2 - Chocolate " << price_arr[2] << " ���.\n"
				<< "3 - Juice " << price_arr[3] << " ���.\n"
				<< "4 - Milk " << price_arr[4] << " ���.\n"
				<< "5 - Toy " << price_arr[5] << " ���.\n"
				<< "��� ������ ��������� ������� ��� ����� - ";


			int vol = 0, count = 0; //vol - ��������� ������ ���������� ��������, count - ���������� ��������

			cin >> vol;
			if (vol == 0) {
				cout << endl;
				break;
			}
			else if (vol < 0 || vol > as-1) {
				cout << "\n������, �� ����� �� ������ �����\n\n";
				continue;
			}

			cout << "������� ���������� - ";
			cin >> count;
			//int buff = count;//����� ��� �������� ��������� �������� count
			count_arr[vol] += count; // ��������� ���������� � ������ (��������?) ���� ������� ������
			toal_price_prod_arr[vol] = count_arr[vol] * price_arr[vol];//������ � ������, ���� �������� � ������ ���-��
			cout << "\t\t\t\t\t\t\t\t" << name_arr[vol] << " - " << count << "��. - " << "���� �� ��. - "
				<< price_arr[vol] << " ���." << " - ����� - " << price_arr[vol] * count
				<< "���." << endl;


		}

		cout << "���:\n";
		for (int k = 1; k < as; k++) {
			if (count_arr[k] != 0) {
				cout << name_arr[k] << " - " << count_arr[k] << "��. = " << toal_price_prod_arr[k] << "���." << endl;
				cash_check += toal_price_prod_arr[k];
			}

		}
		if (cash_check > 500) {
			cash_check *= 0.95;// ������ 5% ��� ������� ����� 500���
			cout << "����� ������� = " << cash_check << "���. ���� ������ 5%\n ";
		}
		else {
			cout << "����� ������� = " << cash_check << "���.\n";
		}
		total_cash += cash_check;

		cout << "��������� ���������� - ������� 1 ��� 0 ��� ������ ";
		cin >> next;
		if (next == 1) {
			system("cls");
				
		}
	}
	

}