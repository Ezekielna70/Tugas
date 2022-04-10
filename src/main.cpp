#include <iostream>
#include <vector>
#include <sstream>//untuk mengubah int jadi string
#include <string>
#include <conio.h>//untuk getch(system password)

#include "include/person.hpp"
#include "include/mahasiswa.hpp"
#include "include/dosen.hpp"
#include "include/tendik.hpp"


void UsernamePassword();//function void
void EditPassword();//function void
using namespace std;

string check="password";//declare password awal
string check2= "admin" ;//declare username awal

int main()
{
	vector<mahasiswa> recMhs;
	vector<dosen> recDosen;
	vector<tendik> recTendik;

	int menu_terpilih;
	
	cout<<"===================================================================="<<endl;//memperindah menu awal
	cout << "Selamat datang di Universitas Komedi Malam\n";
	cout<<"===================================================================="<<endl;

	cout << "Hint\n Username: admin\n Password: password"<<endl;
	UsernamePassword();// memanggil fungsi password


	while(1) {
		cout<<"===================================================================="<<endl;//memperindah menu awal
		cout << "Selamat datang di Universitas Komedi Malam\n";
		cout<<"===================================================================="<<endl;
		cout << "Data statistik:" << endl;
		cout << "  1. Jumlah Mahasiswa             : " << recMhs.size() << " mahasiswa" << endl;
		cout << "  2. Jumlah Dosen                 : " << recDosen.size() << " dosen" << endl;
		cout << "  3. Jumlah Tenaga Kependidikan   : " << recTendik.size() << " tenaga kependidikan" << endl;
		cout << endl;
		cout << "Menu: " << endl;
		cout << "  1. \tTambah Mahasiswa" << endl;
		cout << "  2. \tTambah Dosen" << endl;
		cout << "  3. \tTambah Tenaga Kependidikan" << endl;
		cout << "  4. \tTampilkan semua Mahasiswa" << endl;
		cout << "  5. \tTampilkan semua Dosen" << endl;
		cout << "  6. \tTampilkan semua Tenaga Kependidikan" << endl;
		cout << "  7. \tUpdate Data" << endl;//opsi edit data
		cout << "  8. \tEdit Username dan Password" << endl;//opsi edit password yang sudah ada
		cout << "  9. \tLog Out" << endl;//opsi log out
		cout << "  10.\tKeluar Program"<< endl;
		cout << "-> Silahkan memilih salah satu: ";
		cin >> menu_terpilih;
		cin.ignore();

		switch (menu_terpilih) {
			case 1:
			{
				int dd, mm, yy, tahunmasuk, semesterke, skslulus;
				string id, nama, nrp, departemen;

				stringstream ss;//declare ss
				ss << 1 + recMhs.size();//komputer secara otomatis membuat id orang itu ke ss
				id = ss.str();// data di ss dipindah ke id

				cout << "Nama: ";//output "nama"
				getline(cin, nama);// pakai getline karena mengambil lebih dari 1 kata

				cout << "Tanggal Lahir: ";
				cin >> dd;

				cout << "Bulan Lahir: ";
				cin >> mm;

				cout << "Tahun Lahir: ";
				cin >> yy;

				cout << "NRP: ";
				cin >> nrp;

				cout << "Departemen: ";
				cin.ignore();
				getline(cin, departemen);

				cout << "Semester: ";
				cin >> semesterke;

				cout << "SKS yang telah lulus: ";
				cin >> skslulus;

				vector<float> ipstemp;//declare
				float tempfile;
				for(int p=1; p<semesterke; p++)//loop sebanyak semester-1
				{
					cout << "IPS Semester "<< p<<": ";
					cin >> tempfile;
					ipstemp.push_back(tempfile);
				}	

				cout << "Tahun Masuk Kuliah: ";
				cin >> tahunmasuk;

				mahasiswa mhs(id, nama, dd, mm, yy, nrp, departemen, tahunmasuk, semesterke, skslulus);//pakai class

				for(unsigned u=1; u<=ipstemp.size(); u++)//memasukan semua IPS ke class 
				{
					mhs.setIPS(u,ipstemp[u-1]);
				}

				mhs.hitungIPK();
				recMhs.push_back(mhs);
				
				system("cls");
				
			}
				break;
				//haloooooo
			case 2:
			{
				int dd, mm, yy;
				string id, nama, npp, departemen, pendidikan;

				stringstream ss;//sama seperti di case 1
				ss << 1 + recDosen.size();
				id = ss.str();

				cout << "Nama: ";
				getline(cin, nama);

				cout << "Tanggal Lahir: ";
				cin >> dd;

				cout << "Bulan Lahir: ";
				cin >> mm;

				cout << "Tahun Lahir: ";
				cin >> yy;

				cout << "NPP: ";
				cin >> npp;

				cout << "Departemen: ";
				cin.ignore();
				getline(cin, departemen);

				cout << "Pendidikan: ";
				cin.ignore();
				getline(cin, pendidikan);

				dosen dsn(id, nama, dd, mm, yy, npp, departemen, pendidikan);

				recDosen.push_back(dsn);
				system ("cls");
			}
				break;
			case 3:
			{
				int dd, mm, yy ;
				string id, nama, npp, unit;

				stringstream ss;//sama seperti di case 1
				ss << 1 + recTendik.size();
				id = ss.str();

				cout << "Nama: ";
				getline(cin, nama);

				cout << "Tanggal Lahir: ";
				cin >> dd;

				cout << "Bulan Lahir: ";
				cin >> mm;

				cout << "Tahun Lahir: ";
				cin >> yy;

				cout << "NPP: ";
				cin >> npp;

				cout << "Unit: ";
				cin.ignore();
				getline(cin, unit);

				tendik tendik(id, nama, dd, mm, yy, npp, unit);

				recTendik.push_back(tendik);
				system ("cls");

			}
				break;
			case 4:
			{
				cout << endl;
				for(unsigned long i=0; i< recMhs.size(); i++)// loop untuk mengeluarkan semua data mahasiswa
				{
					cout<<"===================================================================="<<endl;
					cout << "ID: ";
					string simple=recMhs[i].getId();
					stringstream id_int(simple);
					int count = 0;
					id_int >> count;
					int hitung = 6;
					int x=0;
					while (true)//loop untuk memberi angka 0 didepan id agar rapi
					{
						int hasil = count / 10;

						if(hasil==0)
							break;
						x++;
					}

					for(int j=0; j<hitung-x; j++)
					{
						cout << "0";
					}
		
					cout << recMhs[i].getId()<< endl;
					cout << "Nama Mahasiswa: " << recMhs[i].getNama() << endl;//mengeprint isi
					cout << "Tanggal Lahir: ";
					if(recMhs[i].getTglLahir()<10){//memberi angka 0 pada angka dibawah 10
						cout<<"0";
					}
					cout << recMhs[i].getTglLahir()<<"/";
					if(recMhs[i].getBulanLahir()<10){
						cout<<"0";
					}
					cout << recMhs[i].getBulanLahir()<<"/"<<recMhs[i].getTahunLahir()<<endl;
					cout << "NRP: "<< recMhs[i].getNRP() << endl;
					cout << "Departemen: "<< recMhs[i].getDepartemen() << endl;
					cout << "Semester ke-"<<recMhs[i].getSemester() << endl;
					cout << "SKS Lulus: "<<recMhs[i].getSKSLulus() << endl;
					cout << "IPK: " <<recMhs[i].getIPK()<<endl;
					cout << "Tahun Masuk: "<< recMhs[i].getThnMsk() << endl;
					cout << endl;
					cout<<"===================================================================="<<endl;
				}
			}
				break;
			case 5:
			{	//sama seperti case 4
				cout << endl;
				for(unsigned long i=0; i< recDosen.size(); i++)
				{
					cout<<"===================================================================="<<endl;
					cout << "ID: ";
					string simple=recDosen[i].getId();
					stringstream id_int(simple);
					int count = 0;
					id_int >> count;
					int hitung = 6;
					int x=0;
					while (true)
					{
						int hasil = count / 10;

						if(hasil==0)
							break;
						x++;
					}

					for(int j=0; j<hitung-x; j++)
					{
						cout << "0";
					}
					cout << recDosen[i].getId()<< endl;

					cout << "Nama Dosen: " << recDosen[i].getNama() << endl;
					cout << "Tanggal Lahir: ";
					if(recDosen[i].getTglLahir()<10){
						cout<<"0";
					}
					cout << recDosen[i].getTglLahir()<<"/";
					if(recDosen[i].getBulanLahir()<10){
						cout<<"0";
					}
					cout << recDosen[i].getBulanLahir()<<"/"<<recDosen[i].getTahunLahir()<<endl;
					cout << "NPP: "<< recDosen[i].getnpp() << endl;
					cout << "Departemen: "<< recDosen[i].getDepartemen() << endl;
					cout << "Pendidikan: "<< recDosen[i].getPendidikan() << " Tahun" << endl;
					cout << endl;
					cout<<"===================================================================="<<endl;
				}
			}
				break;
			case 6:
			{	// sama seperti case 4
				cout << endl;
				for(unsigned long i=0; i< recTendik.size(); i++)
				{
					cout<<"===================================================================="<<endl;
					cout << "ID: ";
					string simple=recTendik[i].getId();
					stringstream id_int(simple);
					int count = 0;
					id_int >> count;
					int hitung = 6;
					int x=0;
					while (true)
					{
						int hasil = count / 10;

						if(hasil==0)
							break;
						x++;
					}

					for(int j=0; j<hitung-x; j++)
					{
						cout << "0";
					}
					cout << recTendik[i].getId()<< endl;

					cout << "Nama Tenaga Kependidikan: " << recTendik[i].getNama() << endl;
					cout << "Tanggal Lahir: ";
					if(recTendik[i].getTglLahir()<10){
						cout<<"0";
					}
					cout << recTendik[i].getTglLahir() << "/";
					if(recTendik[i].getTglLahir()<10){
						cout<<"0";
					}
					cout << recTendik[i].getBulanLahir()<<"/"<<recTendik[i].getTahunLahir()<<endl;
					cout << "NPP: "<< recTendik[i].getNPP() << endl;
					cout << "Unit: "<< recTendik[i].getUnit() << endl;
					cout << endl;
					cout<<"===================================================================="<<endl;
				}
			}
				break;
			case 7:
			{
				system("cls");
				cout << "  1. Update Data Mahasiswa" << endl;//memberi opsi data yang mau diubah
				cout << "  2. Update Data Dosen" << endl;
				cout << "  3. Update Data Tenaga Kependidikan" << endl;
				cout << "  Pilihan: ";
				int bukalapak;
				cin >> bukalapak;

				switch (bukalapak)
				{
					case 1:
					{
						system("cls");
						for(unsigned long i=0; i< recMhs.size(); i++)//loop mengeluarkan semua mahasiswa yang ada beserta ID nya
						{
							cout<<"===================================================================="<<endl;
							cout << "ID: ";
							string simple=recMhs[i].getId();
							stringstream id_int(simple);
							int count = 0;
							id_int >> count;
							int hitung = 6;
							int x=0;
							while (true)
							{
								int hasil = count / 10;

								if(hasil==0)
									break;
								x++;
							}

							for(int j=0; j<hitung-x; j++)
							{
								cout << "0";
							}
							cout << recMhs[i].getId()<< endl;
							cout << "Nama Mahasiswa: " << recMhs[i].getNama() << endl;
							cout<<"===================================================================="<<endl;
						}

						long zz;
						cout << "ID mahasiswa yang mau diperbaharui: ";//memasukan data mahasiswa yang mau diubah
						cin >> zz;
						zz --;
						
						int day, month, year, sems, sksfinal, thnmsk;
						string dept, nrp1, nama1;

						cout << "Nama: ";
						cin.ignore();
						getline(cin, nama1);
						recMhs[zz].setNama(nama1);//mengubah data

						cout << "Tanggal Lahir: ";
						cin >> day;

						cout << "Bulan Lahir: ";
						cin >> month;

						cout << "Tahun Lahir: ";
						cin >> year;
						recMhs[zz].setTglLahir(day, month, year);

						cout << "NRP: ";
						cin >> nrp1;
						recMhs[zz].setNRP(nrp1);

						cout << "Departemen: ";
						cin.ignore();
						getline(cin, dept);
						recMhs[zz].setDepartemen(dept);

						cout << "Semester: ";
						cin >> sems;
						recMhs[zz].setSemester(sems);

						cout << "SKS yang telah lulus: ";
						cin >> sksfinal;
						recMhs[zz].setSKSLulus(sksfinal);

						vector<float> ipstemp;
						float tempfile;
						for(int p=1; p<sems; p++)//memasukan IPS satu persatu ke data sementara
						{
							cout << "IPS Semester "<< p<<": ";
							cin >> tempfile;
							ipstemp.push_back(tempfile);
						}	
						for(unsigned u=1; u<=ipstemp.size(); u++)//memasukan semua data sementara ke class
						{
							recMhs[zz].setIPS(u,ipstemp[u-1]);
						}

						cout << "Tahun Masuk Kuliah: ";
						cin >> thnmsk;
						recMhs[zz].setThnMsk(thnmsk);

						system("cls");

					}
						break;
					case 2:
					{	// sama seperti case 1
						system("cls");
						for(unsigned long i=0; i< recDosen.size(); i++)
						{
							cout<<"===================================================================="<<endl;
							cout << "ID: ";
							string simple=recDosen[i].getId();
							stringstream id_int(simple);
							int count = 0;
							id_int >> count;
							int hitung = 6;
							int x=0;
							while (true)
							{
								int hasil = count / 10;

								if(hasil==0)
									break;
								x++;
							}

							for(int j=0; j<hitung-x; j++)
							{
								cout << "0";
							}
							cout << recDosen[i].getId()<< endl;
							cout << "Nama Dosen: " << recDosen[i].getNama() << endl;
							cout<<"===================================================================="<<endl;
						}

						long zz;
						cout << "ID Dosen yang mau diperbaharui: ";
						cin >> zz;
						zz --;
						
						int day, month, year;
						string dept, npp1, nama2, pendik;

						cout << "Nama: ";
						cin.ignore();
						getline(cin, nama2);
						recDosen[zz].setNama(nama2);

						cout << "Tanggal Lahir: ";
						cin >> day;

						cout << "Bulan Lahir: ";
						cin >> month;

						cout << "Tahun Lahir: ";
						cin >> year;
						recDosen[zz].setTglLahir(day, month, year);

						cout << "NPP: ";
						cin >> npp1;
						recDosen[zz].setnpp(npp1);

						cout << "Departemen: ";
						cin.ignore();
						getline(cin, dept);
						recDosen[zz].setDepartemen(dept);

						cout << "Pendidikan: ";
						cin.ignore();
						getline(cin,pendik);
						recDosen[zz].setPendidikan(pendik);
						system("cls");
					}
						break;
					case 3:
					{	//sama seperti case 1
						system("cls");
						for(unsigned long i=0; i< recTendik.size(); i++)
						{
							cout<<"===================================================================="<<endl;
							cout << "ID: ";
							string simple=recTendik[i].getId();
							stringstream id_int(simple);
							int count = 0;
							id_int >> count;
							int hitung = 6;
							int x=0;
							while (true)
							{
								int hasil = count / 10;

								if(hasil==0)
									break;
								x++;
							}

							for(int j=0; j<hitung-x; j++)
							{
								cout << "0";
							}
							cout << recTendik[i].getId()<< endl;
							cout << "Nama Tenaga Kependidikan: " << recTendik[i].getNama() << endl;
							cout<<"===================================================================="<<endl;
						}

						long zz;
						cout << "ID Tendik yang mau diperbaharui: ";
						cin >> zz;
						zz --;
						
						int day, month, year;
						string npp2, nama3, unit;

						cout << "Nama: ";
						cin.ignore();
						getline(cin, nama3);
						recTendik[zz].setNama(nama3);

						cout << "Tanggal Lahir: ";
						cin >> day;

						cout << "Bulan Lahir: ";
						cin >> month;

						cout << "Tahun Lahir: ";
						cin >> year;
						recTendik[zz].setTglLahir(day, month, year);

						cout << "NPP: ";
						cin >> npp2;
						recTendik[zz].setNPP(npp2);

						cout << "Unit: ";
						cin.ignore();
						getline(cin,unit);
						recTendik[zz].setUnit(unit);

						system("cls");

					}
				}
			}
				break;
			case 8:
			{
				system("cls");
				cout << "Enter Old Username and Password" << endl;
				UsernamePassword();//memanggil fungsi untuk memastikan kembali dengan dicek ulang
				EditPassword();//memanggil fungsi untuk mengubah username dan password

			}
				break;
			case 9:
			{
				system("cls");
				cout<<"===================================================================="<<endl;
				cout << "Selamat datang di Universitas Komedi Malam\n";
				cout<<"===================================================================="<<endl;
				UsernamePassword();//memulai kode dari awal lagi

			}
				break;
			case 10:
			{
				return 0;//keluar dari program
			}

		}
	}	
	return 0;
	
}


void UsernamePassword(){
	
	while(true)//looping terus sampai inputan benar
	{
		string username;
		
		cout<< endl << "Enter Username\t: ";
		cin >> username;
		//cout << username<<endl;
		//cout << check << endl;
		if(username != check2){//cek apakah input username sudah benar atau tidak
			cout << "Wrong Username\nPlease Press Enter To Start Again" << flush;
			cin.ignore();
			cin.ignore();
			continue;
		}
		break;
	}
	while(true)// looping sampai inputan password benar
	{	
		
		//system("cls");
		cout<<"Enter Password\t: ";
		char pass[1000];
		int i = 0;
		char a;
		while(true)
		{
			a=getch();//agar inputan tidak terlihat
			if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))//mengganti inputan dengan *
			{
				pass[i]=a;
				++i;
				cout<<"*";
			}
			if(a=='\b'&&i>=1)	// agar bisa backspace
			{
				cout<<"\b \b";
				--i;
			}
			if(a=='\r')//agar bisa tekan enter
			{
				pass[i]='\0';
				break;
			}
		}
		//cout<< endl << "You entered : "<<pass;
		
		if(i<=7)// memberi minimum digit password
		{
			cout<< endl <<"Minimum 8 digits needed.\nPlease PressEnter To Start Again" << flush;
			cin.ignore();
			cin.ignore();
			continue;
		}
		if(pass==check){//cek apakah inputan password sudah sama atau belum

			system("cls");
			break;
		}
		else{
			cout<< endl << "Wrong Password.\nPlease Press Enter To Start Again" << flush;
			cin.ignore();
			cin.ignore();
			continue;
		}
		break;
	}
}


void EditPassword(){
	
	while(true)
	{
		string username;
		
		cout<< endl << "Enter New Username\t: ";
		cin >> username;
		if(username == check2){
			cout << "Same Username Detected, Are You Sure?(y/n)\n";//meyakinkan user agar tidak salah memasukan username
			string enter;
			cin >> enter;
			if(enter=="y"){
				system("cls");
				check2 = username;
				break;
				
			}
		}
		else
		{
			check2 = username;//memasukan username baru ke data
			system("cls");
			break;
		}
		continue;
	}
	while(true)
	{	
		cout<<"Enter New Password\t: ";
		char pass[1000];
		int i = 0;
		char a;
		while(true)
		{
			a=getch();
			if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
			{
				pass[i]=a;
				++i;
				cout<<"*";
			}
			if(a=='\b'&&i>=1)
			{
				cout<<"\b \b";
				--i;
			}
			if(a=='\r')
			{
				pass[i]='\0';
				break;
			}
		}
		//cout<< endl << "You entered : "<<pass;
		if(pass==check){
			cout << "\nSame Password Detected, Are You Sure ?(y/n)\n";//memastikan agar user tidak salah memasukan password
			string enter;
			cin >> enter;
			if(enter=="y"){
				check = pass;
				break;
				system("cls");
			}
		}
		else
		{
			check = pass;
			system("cls");
			break;
		}
		
		if(i<=7)
		{
			cout<< endl <<"Minimum 8 digits needed.\nPlease Press Enter To Start Again" << flush;
			cin.ignore();
			cin.ignore();
			continue;
		}
		break;
	}
}