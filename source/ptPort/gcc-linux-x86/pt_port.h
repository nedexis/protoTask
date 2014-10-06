/***************************************************************************//**
 * @file		
 * @author  	dejan
 * @brief       Interface of pt_port.
 * @details     detalis
 * 
 * Template version: 1.0.1 (26.07.2014)
 *
 * Copyright (C) 2013, 2014 Dejan Ristic
 *
 * protoTask is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * protoTask is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *//************************************************************************//**
 * @addtogroup  group 
 *********************************************************************//** @{ */
#ifndef PT_PORT_H_
#define PT_PORT_H_
/*_________________________________________________________  Include Files  __*/
#include <stdint.h>
#include <stddef.h>
/*_______________________________________________________________  Defines  __*/
/*_______________________________________________________________  Macro's  __*/
/*------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif
/*_____________________________________________________________  Data Types  __*/
typedef uint32_t native_T;
/*_______________________________________________________  Global Variables  __*/
/*____________________________________________________  Function Prototypes  __*/
static inline void ptIsrLock(native_T * ctx) {
	(void)ctx;
}
/*.............................................................................*/
static inline void ptIsrUnlock(native_T * ctx) {
	(void)ctx;
}

/** @} *//**********************************************************************/
#ifdef __cplusplus
}
#endif
/*---------------------------------------------------------  C++ extern end  --*/
#endif /* PT_PORT_H_ */
