// Command IDs for SMBus commands

//#define CMD_GETLIGNE 	0x01
#define CMD_GETDATE  	0x02
#define CMD_GETID 		0x03
#define CMD_STARTCONSO 	0x04
#define CMD_STOPCONSO 	0x05      
#define CMD_GETLAT 		0x06
#define CMD_GETLONG		0x07

#define SIZE_GETDATE     18
#define SIZE_GETID       1
#define SIZE_STARTCONSO  0
#define SIZE_STOPCONSO   0      
#define SIZE_GETLAT      8
#define SIZE_GETLONG     8


//Adresses
#define SLAVE_ACC_ADR 0x3A
#define SLAVE_GPS_ADR 0xF0
#define SLAVE_MEM_ADR 0