#include <iostream>
#include <math.h>

using namespace std;

class PerusahaanMobilNS{
	public: 
		virtual double getQuality()=0; //polimorfisme
};

int angka (double &a)
{
	if (a<0 || a>100)
	{
		cout<<"-------------------------------------------------------------------------------"<<endl;
		throw "Error !! Parameter nilai harus diantara 0-100 !!";
	}
	
	return a;
}

int mentotal (double &tot)
{
	if (tot<=2)
	{
		cout<<"-------------------------------------------------------------------------------"<<endl;
		throw "\t\t\tMobil telah lolos quality control";
	}

	else
	{
		cout<<"-------------------------------------------------------------------------------"<<endl;
		throw "\t\t\tMobil tidak lolos quality control";
	}
	return tot;
}

class Interior : public PerusahaanMobilNS {
	private:
	double jokdepan, jokbelakang, sabukpengaman, kacafilm, headunit, daskboard, karpetbawah;
	
	public:
		
	kompInterior (double a, double b, double c, double d, double e, double f, double g)
	{
		jokdepan=a;
		jokbelakang=b;
		sabukpengaman=c;
		kacafilm=d;
		headunit=e;
		daskboard=f; 
		karpetbawah=g;
	}
	
	double getJokDepan()
	{return jokdepan;}
	
	double getJokBelakang()
	{return jokbelakang;}

	double getSabuk()
	{return sabukpengaman;}

	double getKacaFilm()
	{return kacafilm;}	
	
	double getHeadUnit()
	{return headunit;}
	
	double getDaskboard()
	{return headunit;}
	
	double getKarpet()
	{return karpetbawah;}
	
	double getQuality()
	{return (jokdepan+jokbelakang+sabukpengaman+kacafilm+headunit+daskboard+karpetbawah)/7;}
};

class Mesin : public PerusahaanMobilNS {
	private:
	double radiator, olimesin, oligearbox;
	double minyakrem;
	double aki;
	double absi;
	double pendingin;
	
	public:
	kompMesin(double h, double i, double u, double j, double k, double l, double m){
		
		radiator = h;
		olimesin = i;
		oligearbox = u;
		minyakrem = j;
		aki = k;
		absi = l;
		pendingin = m; 
	}

	double getRadiator()
	{return radiator;}
		
	double getOliMesin()
	{return olimesin;}

	double getOliGearbox()
	{return oligearbox;}
	
	double getMinyakRem()
	{return minyakrem;}
	
	double getPasangAki()
	{return aki;}
	
	double getABS()
	{return absi;}
	
	double getSistemPendingin()
	{return pendingin;}	
	
	double getQuality()
	{return (radiator+olimesin+oligearbox+minyakrem+aki+absi+pendingin)/7;}
};

class Exterior : public PerusahaanMobilNS {
	private:
	double lampuutama;
	double lampusein;
	double lampubelakang;
	double pintudepan;
	double pintubelakang;
	double roda;
	double kapdepan;
	
	public:
	kompExterior(double n, double o, double p, double q, double r, double s, double t){
		lampuutama = n;
		lampusein = o;
		lampubelakang = p;
		roda = q;
		kapdepan = r;
		pintudepan = s;
		pintubelakang = t;
	}
	
	double getLampuUtama()
	{return lampuutama;}	
	
	double getLampuSein()
	{return lampusein;}	

	double getLampuBelakang()
	{return lampubelakang;}	
	
	double getRoda()
	{return roda;}	
	
	double getKapDepan()
	{return kapdepan;}
	
	double getPintuDepan()
	{return pintudepan;}
	
	double getPintuBelakangn()
	{return pintubelakang;}
	
	double getQuality()
	{return (lampuutama+lampusein+lampubelakang+pintudepan+pintubelakang+roda+kapdepan)/7;}
	
};

void parameter ()
{
		cout<<endl;
		cout<<"Parameter nilai: "<<endl;
		cout<<"0-25\t: Sangat Buruk\t-> Komponen tidak bisa dipakai"<<endl;
		cout<<"26-50\t: Buruk\t\t-> Tidak bisa dipakai namun dapat didaur ulang/diperbaiki "<<endl;
		cout<<"51-76\t: Baik\t\t-> Terdapat cacat minor namun masih layak dipakai"<<endl;
		cout<<"76-100\t: Sangat Baik\t-> Sempurna"<<endl;
		cout<<endl;
}

int main()
{
	Interior x;
	Exterior y;
	Mesin z;
	
	int menu, errori, tota;
	double jokdepan, jokbelakang, sabukpengaman, kacafilm, headunit, daskboard, karpetbawah;
	double lampuutama, lampusein, lampubelakang, pintudepan, pintubelakang, roda, kapdepan;
	double radiator, olimesin, oligearbox, minyakrem, aki, absi, pendingin;

do{
		cout<<"-------------------------------------------------------------------------------"<<endl;
		cout << "\t\t\t PEMERIKSAAN QUALITY CONTROL \t\n";
		cout<<"-------------------------------------------------------------------------------"<<endl;
		cout << "(1) Interior\n";
		cout << "(2) Eksterior\n";
		cout << "(3) Mesin\n";
		cout << "(4) Total\n";
		cout << "(5) Keluar\n";
		cout << "Pilih : ";
		cin >> menu;	
			
		switch (menu)
		{
			case 1:
				cout<<"-------------------------------------------------------------------------------"<<endl;
				parameter();
				cout<<"-------------------------------------------------------------------------------"<<endl;
				try{
				cout<<"Masukkan parameter kualitas komponen jok depan:\t\t";
				cin>>jokdepan;
				errori = angka(jokdepan);
				cout<<"Masukkan parameter kualitas komponen jok belakang:\t";
				cin>>jokbelakang;
				errori = angka(jokbelakang);
				cout<<"Masukkan parameter kualitas komponen sabuk pengaman:\t";
				cin>>sabukpengaman;
				errori = angka(sabukpengaman);
				cout<<"Masukkan parameter kualitas komponen kaca film:\t\t";
				cin>>kacafilm;
				errori = angka(kacafilm);
				cout<<"Masukkan parameter kualitas komponen head unit:\t\t";
				cin>>headunit;
				errori = angka(headunit);
				cout<<"Masukkan parameter kualitas komponen daskboard:\t\t";
				cin>>daskboard;
				errori = angka(daskboard);
				cout<<"Masukkan parameter kualitas komponen karpet bawah:\t";
				cin>>karpetbawah;
				errori = angka(karpetbawah);
				x.kompInterior(jokdepan, jokbelakang, sabukpengaman, kacafilm, headunit, daskboard, karpetbawah);
				cout<<"-------------------------------------------------------------------------------"<<endl;
				cout<<"Rata-rata kualitas komponen interior:\t\t\t"<<x.getQuality()<<endl;
				cout << "Total toleransi kepresisisian dan kesalahan interior:\t" << abs (x.getQuality()-100) << "%"<< endl;
				}catch (const char *e)
				{cout<<e<<endl;}
				break;
			case 2:
				cout<<"-------------------------------------------------------------------------------"<<endl;
				parameter();
				cout<<"-------------------------------------------------------------------------------"<<endl;
				try{
				cout<<"Masukkan parameter kualitas komponen lampu utama:\t";
				cin>>lampuutama;
				errori = angka(lampuutama);
				cout<<"Masukkan parameter kualitas komponen lampu sein:\t";
				cin>>lampusein;
				errori = angka(lampusein);
				cout<<"Masukkan parameter kualitas komponen lampu belakang:\t";
				cin>>lampubelakang;
				errori = angka(lampubelakang);
				cout<<"Masukkan parameter kualitas komponen pintu depan:\t";
				cin>>pintudepan;
				errori = angka(pintudepan);
				cout<<"Masukkan parameter kualitas komponen pintu belakang:\t";
				cin>>pintubelakang;
				errori = angka(pintubelakang);
				cout<<"Masukkan parameter kualitas komponen roda:\t\t";
				cin>>roda;
				errori = angka(roda);
				cout<<"Masukkan parameter kualitas komponen kap depan:\t\t";
				cin>>kapdepan;
				errori = angka(kapdepan);
				y.kompExterior(lampuutama, lampusein, lampubelakang, pintudepan, pintubelakang, roda, kapdepan);
				cout<<"-------------------------------------------------------------------------------"<<endl;
				cout<<"Rata-rata kualitas komponen eksterior:\t\t\t"<<y.getQuality()<<endl;
				cout << "Total toleransi kepresisisian dan kesalahan eksterior:\t" << abs (y.getQuality()-100) << "%"<< endl;
				}catch (const char *e)
				{cout<<e<<endl;}
				break;
			case 3:
				cout<<"-------------------------------------------------------------------------------"<<endl;
				parameter();
				cout<<"-------------------------------------------------------------------------------"<<endl;
				try{
				cout<<"Masukkan parameter kualitas komponen radiator:\t\t";
				cin>>radiator;
				errori = angka(radiator);
				cout<<"Masukkan parameter kualitas komponen oli mesin:\t\t";
				cin>>olimesin;
				errori = angka(olimesin);
				cout<<"Masukkan parameter kualitas komponen oli gearbox:\t";
				cin>>oligearbox;
				errori = angka(oligearbox);
				cout<<"Masukkan parameter kualitas komponen minyak rem:\t";
				cin>>minyakrem;
				errori = angka(minyakrem);
				cout<<"Masukkan parameter kualitas komponen aki:\t\t";
				cin>>aki;
				errori = angka(aki);
				cout<<"Masukkan parameter kualitas komponen ABS:\t\t";
				cin>>absi;
				errori = angka(absi);
				cout<<"Masukkan parameter kualitas komponen pendingin:\t\t";
				cin>>pendingin;
				errori = angka(pendingin);
				z.kompMesin(radiator, olimesin, oligearbox, minyakrem, aki, absi, pendingin);
				cout<<"-------------------------------------------------------------------------------"<<endl;
				cout<<"Rata-rata kualitas komponen mesin:\t\t\t"<<z.getQuality()<<endl;
				cout << "Total toleransi kepresisisian dan kesalahan mesin:\t" << abs (z.getQuality()-100) << "%"<< endl;
				}catch (const char *e)
				{cout<<e<<endl;}
				break;
			case 4: 
			try{
				double total = abs ((x.getQuality()+y.getQuality()+z.getQuality())/3-100);
				cout<<"-------------------------------------------------------------------------------"<<endl;
				cout << "Total toleransi kepresisisian dan kesalahan mobil: " << total << "%"<< endl;
				tota = mentotal(total);
				cout<<endl;
				cout<<"-------------------------------------------------------------------------------"<<endl;
				}catch (const char *e)
				{cout<<e<<endl;}

			break;
	}
}

	while (menu!=5);
	{
		cout<<"-------------------------------------------------------------------------------"<<endl;
		cout<<"\nTerima kasih telah menginput data !"<<endl;
	}
	
	return 0;
}
