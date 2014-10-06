/***************************************************************************//**
 * @file		
 * @author      dejan 
 * @brief       Implementation of basicTest.
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
 
/*_________________________________________________________  Include Files  __*/
#include "basic_test.h"
#include "proto_task.h"
/*_________________________________________________________  Local Defines  __*/
/*_________________________________________________________  Local Macro's  __*/
/*______________________________________________________  Local Data Types  __*/
/*_______________________________________________________  Local Variables  __*/
static task_T * task1;
static task_T * task2;
/*______________________________________________________  Global Variables  __*/
/*_____________________________________________  Local Function Prototypes  __*/
static void task1fn(void);
static void task2fn(void);
/*____________________________________________  Local Function Definitions  __*/
static void task1fn(void) {
	/*taskDestroy(task1);*/
}
/*............................................................................*/
static void task2fn(void) {
	taskDestroy(task1);
}
/*___________________________________________  Global Function Definitions  __*/
void basicTest(void) {
	task1 = taskCreate(task1fn);
	task2 = taskCreate(task2fn);

	while (1) {
		taskDispatcher();
	}

	taskDestroy(task2);
}
/** @} *//*********************************************************************/
