
			}
		}
		GoTo(26, 6);
		cin >> mk;
		GoTo(30, 7);
		cin >> lmk;
		if (mk != lmk)
		{
			//	system("cls");
			GoTo(11, 8);
			cout << "Vui long dang ky lai theo dung yeu cau" << endl;
		}
	}
	GoTo(11, 8);
	cout << "                                           ";
	GoTo(11, 8);
	SetColor(0, 2);
	cout << "Dang ky thanh cong" << endl;
	SetColor(0, 7);
	fflush(stdin);
	GoTo(11, 9);
	cout << "Nhap ho ten cua ban: ";
	getline(cin, st);
	fstream fout;
	fout.open("data.csv", ios::out | ios::app);
	hocsinh tam;
	fout << tk << "," << mk << "," << st << ",0;" << endl;
	fout.close();
	tam.setUserName(tk);
	tam.setPassword(mk);
	tam.hoten = st;
	tam.borrow = "0;";
	hs.push_back(tam);
	sohs++;
	user(hs, sohs, sach, sosach, sohs);
}

int tim(string st)
{
	for (int i = 0; i <= sohs; i++)
	{
		if ((st == hs[i].getUserName()) && (st == "admin"))
		{
			kkt = true;
			return i;
		}
		if (st == hs[i].getUserName())
			return i;
	}
	return -1;
}
void check(int h)
{
	if (h == -1)
	{
		//system("cls");
		SetColor(0, 4);
		GoTo(11, 7);
		cout << "Khong co tai khoan hop le, nhap lai " << (char)30;
		SetColor(0, 7);
		GoTo(27, 5);
		cout << "                    ";
		GoTo(26, 6);
		cout << "                    ";
		GoTo(27, 5);
		cin >> tk;
		GoTo(26, 6);
		cin >> mk;
		check(tim(tk));
	}
	else
	{
		//system("cls");

		if (hs[h].getPassword() == mk)
		{
			if (kkt == true)
			{
				admin(hs, sohs, sach, sosach);
				kkt = false;
			}
			else
				user(hs, sohs, sach, sosach, h);
		}
		else
		{
			GoTo(11, 7);
			cout << "                                     ";
			SetColor(0, 4);
			GoTo(11, 7);
			cout << (char)19 << " Mat khau sai";
			kkt = false;
			SetColor(0, 7);
			GoTo(26, 6);
			cout << "                    ";
			GoTo(26, 6);
			cin >> mk;
			check(tim(tk));
		}
	};
}

void dangnhap()
{

	//SetConsoleOutputCP(65001);
	system("cls");
	draw(9, 2, 47, 8);
	SetColor(0, 2);
	GoTo(14, 4);
	cout << "DANG NHAP";
	SetColor(0, 7);
	GoTo(11, 5);
	cout << "Nhap tai khoan: ";
	GoTo(11, 6);
	cout << "Nhap mat khau: ";
	GoTo(27, 5);
	cin >> tk;
	GoTo(11, 6);
	cout << "Nhap mat khau: ";
	cin >> mk;
	check(tim(tk));
};
int main()
{
	system("title Quan ly thu vien - Gr6 - 20KTMT1");

	docfile(hs, sohs, sach, sosach);
	//cout << hs[7].hoten;
	drawbook();
	SetColor(0, 4);
	GoTo(10, 2);
	cout << "QUAN LY THU VIEN";

	GoTo(75, 25);
	cout << "San pham cua nhom 6 - 20KTMT1:";
	GoTo(78, 26);
	cout << (char)175 << " Ton That Hai";
	GoTo(78, 27);
	cout << (char)175 << " Ngo Xuan Sy";
	GoTo(78, 28);
	cout << (char)175 << " Le Pham Cong";
	SetColor(0, 7);
	SetColor(0, 9);
	//SetConsoleOutputCP(65001);
	GoTo(11, 5);
	cout << "1. Dang nhap " << endl;
	GoTo(11, 6);
	cout << "2. Dang ky " << endl;
	SetColor(0, 7);
	GoTo(11, 7);
	int ma;
	cout << "Nhap lua chon cua ban: ";
	cin >> ma;
	switch (ma)
	{
	case 1:
		dangnhap();
		break;
	case 2:
		dangky();
	}

	return 0;
}
