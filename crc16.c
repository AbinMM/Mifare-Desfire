#include <stdio.h>
#include <string.h>

unsigned short crc_16(unsigned char *data, unsigned int len);
unsigned short update_crc16(unsigned short crc, unsigned char c);

unsigned short crc_16(unsigned char *data, unsigned int len)
{
        unsigned int i;
        unsigned short crc= 0x6363;

        for(i= 0; i < len ; ++i)
                crc=  update_crc16(crc, data[i]);
        return crc;
}

unsigned short update_crc16(unsigned short crc, unsigned char c)   
{
        unsigned short i, v, tcrc = 0;

        v = (crc ^ c) & 0xff;
        for (i = 0; i < 8; i++) 
                {
                tcrc = ( (tcrc ^ v) & 1 ) ? ( tcrc >> 1 ) ^ 0x8408 : tcrc >> 1;
                v >>= 1;
                }
        return ((crc >> 8) ^ tcrc) & 0xffff;
}

int main(void)
{
	unsigned char x[]= {0x68,0x74,0x74,0x70, 0x73, 0x3a, 0x2f, 0x2f ,0x6d, 0x61 , 0x69, 0x6c, 0x2e, 0x67, 0x6f, 0x6f, 0x67, 0x6c, 0x65, 0x2e , 0x63, 0x6f, 0x6d ,0x2f ,0x6d ,0x61 ,0x69 ,0x6c ,0x2f ,0x75 ,0x2f ,0x30 ,0x2f ,0x23 ,0x69 ,0x6e ,0x62 ,0x6f ,0x78,0x65, 0x2e , 0x63, 0x6f, 0x6d ,0x2f ,0x6d ,0x61 ,0x69 ,0x6c ,0x2f ,0x75 ,0x2f ,0x30 ,0x2f ,0x23 ,0x69 ,0x6e ,0x62 ,0x6f ,0x78};

	printf("%02X\n",(unsigned char)crc_16(x,60));
	printf("%02X\n",crc_16(x,60) >> 8);
}
