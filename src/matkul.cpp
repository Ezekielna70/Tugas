#include <iostream>
#include "include/matkul.hpp"


matkul::matkul(std::string id, std::string nama, int sks, std::string code)
        : id(id), nama(nama), sks(sks), code(code)
{
}

void matkul::setId(std::string id)
{
	this->id = id;
}

std::string matkul::getId()
{
	return this->id;
}

void matkul::setNama(std::string nama)
{
	this->nama = nama;
}

std::string matkul::getNama()
{
	return this -> nama;
}

void matkul::setsks(int sks)
{
	this->sks = sks;
}

int matkul::getsks()
{
	return this -> sks;
}

void matkul::setCode(std::string code)
{
	this->code = code;
}

std::string matkul::getCode()
{
	return this -> code;
}
