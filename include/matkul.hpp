#ifndef __MATKUL_HPP__
#define __MATKUL_HPP__

#include <iostream>

class matkul{
private:
    std::string id; 
    std::string nama;
    int sks;
    std::string code;
public:
	matkul(std::string id, std::string nama, int sks, std::string code);

	void setsks(int sks);
	int getsks();

	void setId(std::string id);
	std::string getId();

	void setNama(std::string nama);
	std::string getNama();

    void setCode(std::string code);
    std::string getCode();
};

#endif 
