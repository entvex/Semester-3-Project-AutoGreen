
#include <iostream>


using namespace std;

struct plant
{
	int temp;
	int water;
	int light;

};

struct Sensordata
{
	int temp;
	int hum;
	int light;
	int ground[6];

};


class Regulator
{
public:
	Regulator(UART * uart_, Indstillinger * settings_)																															)
	{
		uart = uart_;
		settings = settings_;
		//* pointer til DATALOG + UART
		tempHigh = false;
		tempLow = false;
		humidityHigh = false;
		humidityLow = false;
		plante1water = false;
		plante2water = false;
		plante3water = false;
		plante4water = false;
		plante5water = false;
		plante6water = false;


	}
	~Regulator()
	{

	}

	void run()
	{
		//run is running at all times

		//load data into plants from Settings (indstillinger)
		loadData(plant1);
		loadData(plant2);
		loadData(plant3);
		loadData(plant4);
		loadData(plant5);
		loadData(plant6);




		//linux
		//usleep(6000000);
	}

	void ControlData(plant control_plant, Sensordata drivhus_data)
	{

		/*lets make some control checks*/
		
		/*Get newestSensorData*/
		double temp_drivhus = 0;// settings->get_temp;

		/* Compare average temperature for plants to Actual temps*/
		double avg_temp_drivhus = (plant1.temp + plant2.temp + plant3.temp + plant4.temp + plant5.temp + plant6.temp) / 6;


		/* check waterstatus for plant 1-6*/



	}

	void loadData(plant loadplant)
	{
		// go to indstillinger
		loadplant.light = 0;
		loadplant.temp = 0;
		loadplant.water = 0;
		


	}

private:

	bool tempHigh;
	bool tempLow;
	bool humidityHigh;
	bool humidityLow;
	bool plante1water;
	bool plante2water;
	bool plante3water;
	bool plante4water;
	bool plante5water;
	bool plante6water;

	plant plant1;
	plant plant2;
	plant plant3;
	plant plant4;
	plant plant5;
	plant plant6;

	UART * uart;
	Indstillinger * settings;

};
