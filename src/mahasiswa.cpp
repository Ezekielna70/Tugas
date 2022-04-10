#include <iostream>
#include <vector>
#include "include/mahasiswa.hpp"

using namespace std;


mahasiswa::mahasiswa(string id, string nama, int dd, int mm, int yy, 
				string nrp, string departemen, int tahunmasuk, int semesterke, int skslulus)
		: person(id, nama, dd, mm, yy), nrp(nrp), departemen(departemen), tahunmasuk(tahunmasuk), semesterke(semesterke), skslulus(skslulus)
{
	this->ipk = 0.0;

	this->ips = vector<float>(14,0);
}

void mahasiswa::setDepartemen(string departemen)
{
	this->departemen = departemen;
}

string mahasiswa::getDepartemen()
{
	return this->departemen;
}

void mahasiswa::setThnMsk(int tahunmasuk)
{
	this->tahunmasuk = tahunmasuk;
}

int mahasiswa::getThnMsk()
{
	return this->tahunmasuk;
}

void mahasiswa::setNRP(string nrp)
{
	this->nrp = nrp;
}

string mahasiswa::getNRP()
{
	return this->nrp;
}

void mahasiswa::setSemester(int semesterke)
{
	this->semesterke = semesterke;
}

int mahasiswa::getSemester()
{
	return this->semesterke;
}

void mahasiswa::setSKSLulus(int skslulus)
{
	this->skslulus = skslulus;
}

int mahasiswa::getSKSLulus()
{
	return this->skslulus;
}

void mahasiswa::hitungIPK()
{
	// int i = 0;
	// float temp = 0;
	// for (; ips[i] != (float)0; i++)
	// {
	// 	cout << "||||" << ips[i] << endl;
	// 	temp += ips[i];
	// }

	// cout << "temp: " << temp << "|";
	
	int i = 0;
	float temp = 0;
	for (; ips[i] != (float)0; i++)
	{
		temp += ips[i];
	}

	this->ipk = temp/i;

	

}

float mahasiswa::getIPK()
{
	return this->ipk;
}

void mahasiswa::setIPS(int semester, float ips)
{
	// semester mulai dari 1
	if (semester < 15) {
		this->ips[semester-1] = ips;
		this->hitungIPK();
	}
}

float mahasiswa::getIPS(int semester)
{
	if (semester < 15)
		return this->ips[semester-1];

	return -1.0;
}

vector<float> mahasiswa::getAllIPS()
{
	return this->ips;
}



