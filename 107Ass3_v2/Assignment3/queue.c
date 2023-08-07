/*
 *	Implementation for Queue using linked-list
 *	Authors: 
 *      - Minh Thong Dang 	- 551642 -	70% 	(square_state.c, game_state.c, game_tree.c)
 *      - Md Ashikur Rahman - 543704 -	30%		(queue.c, stack.c, t_node.c)
 *	Version: October 2020
 *
 *	This file holds the definition of the Queue ADT.
 *
 *	YOU NEED TO MAKE CHANGES TO THIS FILE!
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "queue.h"
#include "assig_three220.h"


struct queue_int {
	node first;		// first node in the linked list
};


/*
 *	init_queue
 *	initialiser function.
 *	Pre-condition: none
 *	Post-condition: create a new queue variable with a NULL first
 *					field and the address of it assigned to the
 *					parameter (qp)
 *	Informally: creates an empty queue
 *
 *	Param qp the address to create the queue within
 */
void init_queue(queue *qp)
{
	trace("init_queue: init_queue begins");

	*qp = (queue)malloc(sizeof(struct queue_int));
	(*qp)->first = NULL;

	trace("init_queue: init_queue ends");
}


/*
 *	is_empty_queue
 *	Emptiness test.
 *	Pre-condition: the queue variable is defined and valid
 *	Post-condition: true is returned if the queue variable is
 *					empty, false is returned otherwise
 *	Informally: indicate if the queue contains no nodes
 *
 *	return boolean whether or not the queue is empty
 */
bool is_empty_queue(queue q)
{
	trace("is_empty_queue: is_empty_queue begins and ends");

	return (q->first == NULL);
}

/*
 *	front
 *	Find value at front of queue.
 *	Pre-condition: the queue variable is defined and valid
 *	Post-condition: the value at the front of queue is returned
 *	Informally: find the value at the front of queue
 *
 *	return (void *) the value on front of the queue
 */
void *front(queue q)
{
	trace("front: front begins");

	if(is_empty_queue(q))
	{
  		fprintf(stderr, "Queue empty");
   		exit(1);
	}
	else
	{
   		return get_data_node(q->first);
	}
}

/*
 *	rear
 *	Remove head of the queue
 *	Pre-condition: the queue variable is defined and valid
 *	Post-condition: the value at the front of queue is deleted updating
 *					the "first" field accordingly
 *	Informally: delete the head of the queue
 */
void rear(queue q)
{
	trace("rear: rear begins");

	if(is_empty_queue(q))
	{
   		fprintf(stderr, "Queue empty");
   		exit(1);
	}
	else
	{
		q->first = get_next_node(q->first);
	}

	trace("rear: rear ends");
}

/*
 *	add
 *	Add item to back of queue
 *	Pre-condition: the queue variable is defined and valid
 *	Post-condition: a new node is created containing the parameter
 *					value (o) in the data field and NULL in the
 *					next field and this is inserted at the rear
 *					of the linked list
 *
 *	Param o value to be added to back of queue
 */
void add(queue q, void *o)
{
	node n, current;

	trace("add: add begins");

	init_node(&n, o);
	if(is_empty_queue(q))
	{
   		q->first = n;
	}
	else
	{
   		current = q->first;
   		while(get_next_node(current) != NULL)
   		{
      		current = get_next_node(current);
   		} 
   		set_next_node(current, n);
	}

	trace("add: add ends");
}

/*
 *	to_string_queue
 *	String conversion for queue
 *	Pre-condition: none
 *	Post-condition: a string variable is returned consisting of the
 *				string representation of all items in the queue,
 *				from left to right, separated by " " and contained
 *				within "<" and ">"
 *	Informally: produce a string representation of the queue
 *
 *	return (char *) printable contents of queue
 */
char *to_string_queue(queue q, char *f)
{
	node c;
	char *fmt = (char *)malloc(10 * sizeof(char));
	char *s=(char *)malloc(100*10*sizeof(char));
	
	if (is_empty_queue(q))	// empty queue so return nothing
	{
		s = "<>";
	}
	else 
	{
		// fill string with values from the linked list
		s[0] = '\0';
		sprintf(fmt, "%%s%s", f);
		c = q->first;
		while (c != NULL)
		{
			sprintf(s, fmt, s,*(int *)(get_data_node(c)));
			if (get_next_node(c) != NULL)
			{
				sprintf(s, "%s, ", s);
			}
			c = get_next_node(c);
		}
	}

	return s;
}
