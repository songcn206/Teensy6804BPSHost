/*
 Linear Technology DC2100A Demonstration Board.
 PIC18 Driver File for SPI port.
 All datasheet references in this file refer to Microchip Technology Inc. document 39964B.pdf.

 @verbatim
 This code provides an interface to the SPI port on the PIC18 used to communicate with the LTC6804-2.
 DMA is used so that the other software modules can perform other tasks (such as CRC calculation) as
 bytes as sent to and received from the SPI bus.  The SPI driver can be configured to different baud
 rates, so that communication for each IC can occur at its maximum rate.
 @endverbatim

 http://www.linear.com/solutions/5126

 REVISION HISTORY
 $Revision: 640 $
 $Date: 2014-08-26 16:31:44 -0400 (Tue, 26 Aug 2014) $

 Copyright (c) 2013, Linear Technology Corp.(LTC)
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
    list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 The views and conclusions contained in the software and documentation are those
 of the authors and should not be interpreted as representing official policies,
 either expressed or implied, of Linear Technology Corp.

*/

#ifndef __PIC_18FXXJ_SPI_H__
#define __PIC_18FXXJ_SPI_H__

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Includes
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
#include "Typedefs.h"

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Definitions
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

// See Register 20-1 and 20-2 in datasheet for description of these bits
typedef struct {
    int SMP : 1;
    int CKP : 1;
    int CKE : 1;
} PIC18FXXJ_SPI_MODE_TYPE;

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Global Data
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Global Prototypes
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
void PIC18FXXJ_SPI_Init(int16 baud_khz, PIC18FXXJ_SPI_MODE_TYPE mode);
void PIC18FXXJ_SPI_Set_Baud(int16 baud_khz);
inline BOOLEAN PIC18FXXJ_SPI_Buffer_Done(void);
inline void PIC18FXXJ_SPI_Buffer_Receive_Start(int8* read_buffer, int8 num_bytes);
inline void PIC18FXXJ_SPI_Buffer_Send_Start(int8* write_buffer, int8 num_bytes);
inline int8 PIC18FXXJ_SPI_Buffer_Receive_Bytes_Available(int8* write_buffer_ptr);

#endif
