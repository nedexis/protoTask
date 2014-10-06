/***************************************************************************//**
 * @file		
 * @author  	dejan
 * @brief       Interface of protoTask.
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
#ifndef PROTOTASK_H_
#define PROTOTASK_H_
/*_________________________________________________________  Include Files  __*/
#include <stdint.h>
/*_______________________________________________________________  Defines  __*/
#define NUM_OF_TASKS	10
/*_______________________________________________________________  Macro's  __*/
/*------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif
/*_____________________________________________________________  Data Types  __*/
/**@brief Task function type
*/
typedef void (taskFn_T)(void);
/**@brief Task opaque type
*/
typedef struct task task_T;
/*_______________________________________________________  Global Variables  __*/
/*____________________________________________________  Function Prototypes  __*/
/**@brief Create a new task
* @param fn pointer to task function
* @return Opaque pointer to task structure.
*/
task_T * taskCreate(taskFn_T * fn);
/**@brief Destroy a task
* @param Opaque pointer to task structure.
*/
void taskDestroy(task_T * task);
/**@brief Execute the tasks.
* @note This function must be continiosly invoked.
*/
void taskDispatcher(void);
/** @} *//**********************************************************************/
#ifdef __cplusplus
}
#endif
/*---------------------------------------------------------  C++ extern end  --*/
#endif /* PROTOTASK_H_ */
