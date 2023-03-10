// Dynamixel SDK platform dependent header
#ifndef _DYNAMIXEL_HAL_HEADER
#define _DYNAMIXEL_HAL_HEADER


#ifdef __cplusplus
extern "C" {
#endif

#include "MxMotor.h"

int dxl_hal_open( int devIndex, int baudrate );
void dxl_hal_close(void);
void dxl_hal_clear(void);
int dxl_hal_tx( unsigned char *pPacket, int numPacket );
int dxl_hal_rx( unsigned char *pPacket, int numPacket );
void dxl_hal_set_timeout( int NumRcvByte );
int dxl_hal_timeout(void);



#ifdef __cplusplus
}
#endif

#endif
