#include <project.h>

/* Defines for DMA_1 */
#define DMA_1_BYTES_PER_BURST 1
#define DMA_1_REQUEST_PER_BURST 1
#define DMA_1_SRC_BASE (CYDEV_PERIPH_BASE)
#define DMA_1_DST_BASE (CYDEV_PERIPH_BASE)


/* Defines for DMA_2 */
#define DMA_2_BYTES_PER_BURST 1
#define DMA_2_REQUEST_PER_BURST 1
#define DMA_2_SRC_BASE (CYDEV_PERIPH_BASE)
#define DMA_2_DST_BASE (CYDEV_PERIPH_BASE) 

int main()
{
   
/* Variable declarations for DMA_1 and DMA_2*/

uint8 DMA_1_Chan;
uint8 DMA_1_TD[1];
uint8 DMA_2_Chan;
uint8 DMA_2_TD[1];

/* DMA Configuration for DMA_1 */
DMA_1_Chan = DMA_1_DmaInitialize(DMA_1_BYTES_PER_BURST, DMA_1_REQUEST_PER_BURST, 
                                HI16(DMA_1_SRC_BASE), HI16(DMA_1_DST_BASE));
DMA_1_TD[0] = CyDmaTdAllocate();
CyDmaTdSetConfiguration(DMA_1_TD[0], 1, DMA_1_TD[0], 0);
CyDmaTdSetAddress(DMA_1_TD[0], LO16((uint32)ADC_SAR_1_SAR_WRK0_PTR), LO16((uint32)Filter_1_STAGEA_PTR));
CyDmaChSetInitialTd(DMA_1_Chan, DMA_1_TD[0]);
CyDmaChEnable(DMA_1_Chan, 1);

/* Variable declarations for DMA_2 */
/* Move these variable declarations to the top of the function */

/* DMA Configuration for DMA_2 */
DMA_2_Chan = DMA_2_DmaInitialize(DMA_2_BYTES_PER_BURST, DMA_2_REQUEST_PER_BURST, 
                                HI16(DMA_2_SRC_BASE), HI16(DMA_2_DST_BASE));
DMA_2_TD[0] = CyDmaTdAllocate();
CyDmaTdSetConfiguration(DMA_2_TD[0], 1, DMA_2_TD[0], 0);
CyDmaTdSetAddress(DMA_2_TD[0], LO16((uint32)Filter_1_HOLDA_PTR), LO16((uint32)VDAC8_1_Data_PTR));
CyDmaChSetInitialTd(DMA_2_Chan, DMA_2_TD[0]);
CyDmaChEnable(DMA_2_Chan, 1);
   
 /* Start the components */
Clock_1_Start();
VDAC8_1_Start();
Filter_1_Start();
ADC_SAR_1_Start();
Filter_1_SetCoherency(Filter_1_CHANNEL_A, Filter_1_KEY_LOW);

//sine lookup table
int sineTable[1025];

int i, j, k;
  const int magic[33] = {
    0x691864, 0x622299, 0x2CB61A, 0x461622,
    0x62165A, 0x85965A, 0x0D3459, 0x65B10C,
    0x50B2D2, 0x4622D9, 0x88C45B, 0x461828,
    0x6616CC, 0x6CC2DA, 0x512543, 0x65B69A,
    0x6D98CC, 0x4DB50B, 0x86350C, 0x7136A2,
    0x6A974B, 0x6D531B, 0x70D514, 0x4EA714,
    0x5156A4, 0x393A9D, 0x714A6C, 0x755555,
    0x5246EB, 0x916556, 0x7245CD, 0xB4F3CE,
    0x6DBC7A
  };
  k = 0;
  for (i = 0; i < 33; i++) {
    for (j = 0; j < 24; j += 3) {
      sineTable[k++] = ((magic[i] >> j) & 7) - 4;
    }
  }
  sineTable[1] = 51472;

//for loop which estimates the value of the output value
  for (i = 3; i > 0; i--) {
    for (j = i; j <= 256; j++) {
      k = sineTable[j - 1];
      sineTable[j] = k + sineTable[j];
      sineTable[513-j] = k;
      sineTable[511+j] = -k;
      sineTable[1025-j] = -k;
    }
  }
  sineTable[768] = -0x800000;
//Writes values to output
for (i = 0; i < 1025; i++) {
Pin_2_Write(sineTable[i]);
   }
}



















