#include <iostream>
using namespace std;

void main() {

	setlocale(LC_ALL, "ru");
	double total_cash = 0; //сумма в кассе
	int next = 1;
	while (next == 1) {

		double cash_check = 0; //сумма чека
		int price_arr[]{ 0,48,65,35,98,250 };//пусто,хлеб,шоколад,сок,молоко,игрушка
		const int as = sizeof(price_arr) / sizeof(price_arr[0]); //переменная хранения размера массива(кол-во продуктов в магазине)
		int toal_price_prod_arr[as]{}; //массив сумм каждого продукта в чеке
		int count_arr[as]{}; //массив хранения количества каждого продукта
		string name_arr[]{ "empty","Bread","Chocolate","Juice","Milk","Toy" }; // empty не используется(надо избавиться)


		cout << "\t\t\t\t\t\t****************" <<
			endl << "\t\t\t\t\t\t*Programm KASSY*" <<
			endl << "\t\t\t\t\t\t****************" << endl;
		cout << "\t\t\t\t\t\t Total cash = " << total_cash << "руб." << endl;


		while (true) {
			cout << "Закрыть чек, введите - 0 " << endl
				<< "1 - Bread " << price_arr[1] << " Руб.\n"
				<< "2 - Chocolate " << price_arr[2] << " Руб.\n"
				<< "3 - Juice " << price_arr[3] << " Руб.\n"
				<< "4 - Milk " << price_arr[4] << " Руб.\n"
				<< "5 - Toy " << price_arr[5] << " Руб.\n"
				<< "Для выбора прордукта введите его номер - ";


			int vol = 0, count = 0; //vol - пременная номера выбранного продукта, count - количества продукта

			cin >> vol;
			if (vol == 0) {
				cout << endl;
				break;
			}
			else if (vol < 0 || vol > as-1) {
				cout << "\nОшибка, вы ввели не верное число\n\n";
				continue;
			}

			cout << "Введите количество - ";
			cin >> count;
			//int buff = count;//буфер для хранения истинного значения count
			count_arr[vol] += count; // Добаление количества в массив (проблема?) пока добавил буффер
			toal_price_prod_arr[vol] = count_arr[vol] * price_arr[vol];//запись в массив, цены продукта с учетом кол-ва
			cout << "\t\t\t\t\t\t\t\t" << name_arr[vol] << " - " << count << "шт. - " << "Цена за шт. - "
				<< price_arr[vol] << " руб." << " - всего - " << price_arr[vol] * count
				<< "руб." << endl;


		}

		cout << "Чек:\n";
		for (int k = 1; k < as; k++) {
			if (count_arr[k] != 0) {
				cout << name_arr[k] << " - " << count_arr[k] << "шт. = " << toal_price_prod_arr[k] << "руб." << endl;
				cash_check += toal_price_prod_arr[k];
			}

		}
		if (cash_check > 500) {
			cash_check *= 0.95;// скидка 5% при покупке более 500руб
			cout << "Сумма покупки = " << cash_check << "руб. Ваша скидка 5%\n ";
		}
		else {
			cout << "Сумма покупки = " << cash_check << "руб.\n";
		}
		total_cash += cash_check;

		cout << "Следующий покупатель - введите 1 или 0 для выхода ";
		cin >> next;
		if (next == 1) {
			system("cls");
				
		}
	}
	

}