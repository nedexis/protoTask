/***************************************************************************//**
 * @file		
 * @author      dejan 
 * @brief       Implementation of protoTask.
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
#include "proto_task.h"
#include "pt_port.h"
#include "assert.h"
/*_________________________________________________________  Local Defines  __*/
/*_________________________________________________________  Local Macro's  __*/
/*______________________________________________________  Local Data Types  __*/
struct task {
	task_T * 	next;
	task_T * 	prev;
	taskFn_T *	fn;
};
/*_______________________________________________________  Local Variables  __*/
static task_T gTasks[NUM_OF_TASKS];

static task_T sentinel = {
	(task_T *)&sentinel,
	(task_T *)&sentinel,
	NULL
};
/*______________________________________________________  Global Variables  __*/
/*_____________________________________________  Local Function Prototypes  __*/
/*____________________________________________  Local Function Definitions  __*/
/*___________________________________________  Global Function Definitions  __*/
task_T * taskCreate(taskFn_T * fn) {
	task_T * newTask = NULL;
	task_T * currTask;
	native_T i;
	native_T isrCtx = 0;

	assert(fn != NULL);

	ptIsrLock(&isrCtx);

	for (i = 0; i < NUM_OF_TASKS; i++) {
		if (gTasks[i].next == NULL) {
			newTask = &gTasks[i];
			break;
		}
	}
	assert(newTask != NULL);

	currTask = sentinel.prev;
	newTask->next = &sentinel;
	newTask->prev = currTask;
	sentinel.prev = newTask;
	currTask->next = newTask;
	newTask->fn = fn;

	ptIsrUnlock(&isrCtx);

	return newTask;
}
/*.............................................................................*/
void taskDestroy(task_T * task) {
	native_T isrCtx = 0;

	assert(task != NULL);

	ptIsrLock(&isrCtx);

	task->prev->next = task->next;
	task->next->prev = task->prev;
	task->next = NULL;

	ptIsrUnlock(&isrCtx);
}
/*.............................................................................*/
void taskDispatcher(void) {
	task_T * currTask;
	task_T * tmpTask;
	native_T isrCtx = 0;

	ptIsrLock(&isrCtx);

	currTask = sentinel.next;
	while (currTask != &sentinel) {
		tmpTask = currTask->next;
		currTask->fn();
		currTask = tmpTask;
	}

	ptIsrUnlock(&isrCtx);
}
/** @} *//*********************************************************************/
