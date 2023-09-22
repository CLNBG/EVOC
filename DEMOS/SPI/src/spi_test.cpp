#include "spi.h"
#include <memory>
#include <cstdio>

int main()
{
    uint8_t MID;
    uint16_t DID;

    std::unique_ptr<nmros::SPI> tmp = std::make_unique<nmros::SPI>();

	tmp->SPI_Start();
    tmp->SPI_RW_Byte(nmros::SPIMode::MODE0,0x90);
    tmp->SPI_RW_Byte(nmros::SPIMode::MODE0,0x00);
    tmp->SPI_RW_Byte(nmros::SPIMode::MODE0,0x00);
    tmp->SPI_RW_Byte(nmros::SPIMode::MODE0,0x00);

    DID |= tmp->SPI_RW_Byte(nmros::SPIMode::MODE0,0xFF) << 8;
    DID |= tmp->SPI_RW_Byte(nmros::SPIMode::MODE0,0xFF);

    tmp->SPI_Stop();

	printf("MID MODE0: %X\n", MID);
    printf("DID MODE0: %X\n", DID);

	return 0;
}

