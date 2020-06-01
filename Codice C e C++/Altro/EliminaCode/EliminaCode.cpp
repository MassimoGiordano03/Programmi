#include <iostream>
using namespace std;

int Enable = 1;

int main() {

	int nextA = 0;
	int nextB = 0;

	int m1_a = 0;
	int m1_b = 0;
	int m2_a = 0;
	int m2_b = 0;
	int m3_a = 0;
	int m3_b = 0;
	int Monitor1 = 0;
	int Monitor2 = 0;
	int Monitor3 = 0;
	int Srv_A = 0;
	int Srv_B = 0;

	while(Enable) 
	{
		cout << "Mittente: ";
		int mitt;
		cin >> mitt;

		if(mitt <= 3 && mitt >= 0) 
		{
			cout << "Servizio: ";
			int srv_ctr;
			cin >> srv_ctr;

				if(mitt == 0) 
				{
					if(srv_ctr == 1) 
					{
						Srv_A += 1;
						cout << "Servizio A  ";
						cout << Srv_A;
						cout << " persone" << endl << endl;
					}
					else if(srv_ctr == 2) 
					{
						cout << "Servizio B  ";
						Srv_B += 1;
						cout << Srv_B;
						cout << " persone" << endl << endl;
					} 
					else 
					{
						cout << "Perfavore, reinserisci il servizio desiderato" << endl;
					}
				}
				else if(mitt == 1) 
				{
					if(srv_ctr == 1) 
					{
						nextA += 1;
						cout << "Serviamo il numero: " << nextA << endl;
						cout << "Potete andare al monitor 1 per il servizio A" << endl << endl;
						Srv_A += 1;
						Monitor1 += 1;
						m1_a += 1;
					}
					else if(srv_ctr == 2) 
					{
						nextB += 1;
						cout << "Serviamo il numero: " << nextB << endl;
						cout << "Potete andare al Monitor 1 per il servizio B" << endl << endl;
						Srv_B += 1;
						Monitor1 += 1;
						m1_b += 1;
					} 
					else 
					{
						cout << "Perfavore, reinserisci il servizio desiderato" << endl;
					}
				}
				else if(mitt == 2) 
				{
					if(srv_ctr == 1) 
					{
						nextA += 1;
						cout << "Serviamo il numero: " << nextA << endl;
						cout << "Potete andare al monitor 2 per il servizio A" << endl << endl;
						Srv_A += 1;
						Monitor2 += 1;
						m2_a += 1;
					}
					else if(srv_ctr == 2) 
					{
						nextB += 1;
						cout << "Serviamo il numero: " << nextB << endl;
						cout << "Potete andare al Monitor 2 per il servizio B" << endl << endl;
						Srv_B += 1;
						Monitor2 += 1;
						m2_b += 1;
					} 
					else 
					{
						cout << "Perfavore, reinserisci il servizio desiderato" << endl;
					}
				}
				else if(mitt == 3) 
				{
					if(srv_ctr == 1) 
					{
						nextA += 1;
						cout << "Serviamo il numero: " << nextA << endl;
						cout << "Potete andare al monitor 3 per il servizio A" << endl << endl;
						Srv_A += 1;
						Monitor3 += 1;
						m3_a += 1;
					}
					else if(srv_ctr == 2) 
					{
						nextB += 1;
						cout << "Serviamo il numero: " << nextB << endl;
						cout << "Potete andare al Monitor 3 per il servizio B" << endl << endl;
						Srv_B += 1;
						Monitor3 += 1;
						m3_b += 1;
					} 
					else 
					{
						cout << "Perfavore, reinserisci il servizio desiderato" << endl;
					}
				}
			}
			else if(mitt == 999) 
			{
				cout << "Spegnimento Programma";
				Enable = 0;
			} 
			else 
			{
				cout << "Questo mittente non esiste";
			}
		}
	cout << endl;
	cout << "Le persone al monitor 1 del servizio A sono: " << m1_a << endl << endl;
	cout << "Le persone al monitor 1 del servizio B sono: " << m1_b << endl << endl;
	cout << "Le persone al monitor 2 del servizio A sono: " << m2_a << endl << endl;
	cout << "Le persone al monitor 2 del servizio B sono: " << m2_b << endl << endl;
	cout << "Le persone al monitor 3 del servizio A sono: " << m3_a << endl << endl;
	cout << "Le persone al monitor 3 del servizio B sono: " << m3_b << endl << endl;
	int personeTotaliServizi = Monitor1 + Monitor2 + Monitor3;
	cout << "Le persone totali che hanno usufruito dei servizi sono: " << personeTotaliServizi << endl << endl;
	int personeTotali = Srv_A + Srv_B;
	cout << "Le persone che oggi hanno richiesto un servizio sono: " << personeTotali << endl << endl;
	return 0;
}
