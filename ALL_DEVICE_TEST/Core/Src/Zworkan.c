#include "Zworkman.h"


uint32_t count3=0;
float DACoutput[200]={0.0,157.05379539064145,313.95259764656686,470.54156659257154,626.6661678215213,782.1723252011543,936.906572928623,1090.7162069827127,1243.449435824274,1394.9555301961464,1545.084971874737,1693.689601226457,1840.6227634233896,1985.739453173903,2128.896457825363,2269.952498697734,2408.7683705085765,2545.2070787518564,2679.133974894983,2810.416889260653,2938.926261462366,3064.5352682648822,3187.1199487434483,3306.559326618259,3422.735529643443,3535.533905932738,3644.843137107058,3750.5553481522975,3852.566213878946,3950.775061878452,4045.0849718747368,4135.402871372809,4221.639627510075,4303.710135019718,4381.5334002193185,4455.032620941839,4524.135262330098,4588.773128419905,4648.882429441257,4704.403844771127,4755.282581475768,4801.468428384715,4842.915805643155,4879.583809693737,4911.436253643443,4938.441702975689,4960.573506572388,4977.8098230154,4990.133642141358,4997.532801828658,5000.0,4997.532801828658,4990.133642141358,4977.8098230154,4960.573506572389,4938.441702975689,4911.436253643444,4879.583809693737,4842.915805643155,4801.4684283847155,4755.282581475768,4704.403844771127,4648.882429441257,4588.773128419905,4524.135262330097,4455.03262094184,4381.533400219318,4303.710135019718,4221.639627510075,4135.4028713728085,4045.084971874737,3950.7750618784517,3852.566213878946,3750.555348152298,3644.8431371070574,3535.533905932738,3422.7355296434444,3306.559326618259,3187.119948743449,3064.535268264882,2938.9262614623663,2810.416889260654,2679.133974894985,2545.2070787518555,2408.768370508576,2269.9524986977344,2128.8964578253645,1985.7394531739053,1840.6227634233908,1693.6896012264565,1545.0849718747374,1394.9555301961477,1243.4494358242762,1090.7162069827139,936.9065729286228,782.1723252011549,626.6661678215227,470.54156659257177,313.95259764656794,157.05379539064117,6.123233995736766e-13,-157.05379539063998,-313.95259764656674,-470.5415665925705,-626.6661678215214,-782.1723252011536,-936.9065729286239,-1090.7162069827125,-1243.4494358242728,-1394.9555301961445,-1545.0849718747363,-1693.6896012264574,-1840.6227634233896,-1985.739453173902,-2128.8964578253613,-2269.9524986977353,-2408.768370508577,-2545.207078751856,-2679.133974894982,-2810.4168892606513,-2938.9262614623635,-3064.535268264883,-3187.1199487434483,-3306.5593266182586,-3422.735529643442,-3535.5339059327357,-3644.843137107058,-3750.5553481522975,-3852.5662138789467,-3950.775061878452,-4045.0849718747368,-4135.4028713728085,-4221.639627510077,-4303.710135019719,-4381.533400219318,-4455.032620941839,-4524.135262330099,-4588.773128419906,-4648.882429441257,-4704.403844771127,-4755.282581475768,-4801.468428384715,-4842.915805643156,-4879.583809693737,-4911.436253643444,-4938.441702975689,-4960.573506572388,-4977.8098230154,-4990.133642141358,-4997.532801828658,-5000.0,-4997.532801828658,-4990.133642141358,-4977.8098230154,-4960.573506572389,-4938.441702975689,-4911.436253643444,-4879.583809693738,-4842.915805643155,-4801.4684283847155,-4755.282581475768,-4704.403844771128,-4648.882429441258,-4588.773128419907,-4524.1352623301,-4455.032620941842,-4381.533400219317,-4303.710135019717,-4221.639627510075,-4135.402871372809,-4045.0849718747377,-3950.775061878453,-3852.566213878948,-3750.5553481523,-3644.8431371070606,-3535.5339059327416,-3422.735529643445,-3306.559326618258,-3187.1199487434483,-3064.5352682648822,-2938.9262614623667,-2810.4168892606544,-2679.1339748949854,-2545.20707875186,-2408.7683705085806,-2269.952498697735,-2128.896457825365,-1985.7394531739017,-1840.6227634233894,-1693.6896012264572,-1545.0849718747384,-1394.9555301961484,-1243.4494358242769,-1090.7162069827166,-936.9065729286234,-782.1723252011554,-626.6661678215232,-470.54156659257455,-313.9525976465663,-157.0537953906418};

void storage_float(uint32_t place,float num)
{
//	uint32_t storagenum;
//	uint32_t i;

//	for(i=0;i<32,i++)
//	{
//		storagenum = (uint32_t)(num | 0);
//	}
	uint32_t storagenum=(int)num;


	W25QXX_Write(&storagenum,place,4);
}

float read_float(uint32_t place)
{
	int storagenum;
	float num;
	W25QXX_Read(&storagenum,place,4);

	//num = (float *)&storagenum;
	num = *(float*)&storagenum;

	return num;
}

void init_start()
{
	uint8_t buf1[4]={0x11,0x22,0x33,0x44};
	uint8_t buf2[4]={0};
	uint16_t ads_data[4];
	float num,storagenum = -222.3334;

	W25QXX_Init();
	ADS8688_Init(&ads, &hspi3, SPI3_CS_GPIO_Port, SPI3_CS_Pin);
	Init_AD9959();
	DAC8563_Init();

	//W25QXX_Write(&storagenum, 4000000, 4);
	//W25QXX_Read (&num       , 4000000, 4);

}


void while_do()
{
	HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);
	HAL_GPIO_TogglePin(LED2_GPIO_Port,LED2_Pin);
}
