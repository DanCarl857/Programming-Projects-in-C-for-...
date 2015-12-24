/* by: Daniel Carlson
 * on: Wed 03:20 am */

#ifndef H_ARRAY_H
#define H_ARRAY_H
#include "xmalloc.h"

#define make_vector(v, n) ((v) = xmalloc((n) * sizeof *(v)))
#define free_vector(v) do { free(v); v = NULL; } while(0)

#define make_matrix(a, m, n) do {		\
	size_t make_matrix_loop_counter;	\
	make_vector(a, (m) + 1);			\
	for (make_matrix_loop_counter = 0;	\
			make_matrix_loop_counter < (m);	\
			make_matrix_loop_counter++)		\
		make_vector((a)[make_matrix_loop_counter], (n));	\
	(a)[m] = NULL;											\
} while(0)

#define free_matrix(a) do {									\
	if (a != NULL) {										\
		size_t make_matrix_loop_counter;					\
		for (make_matrix_loop_counter = 0;					\
				(a)[make_matrix_loop_counter] != NULL;			\
				make_matrix_loop_counter++)						\
			free_vector((a)[make_matrix_loop_counter]);			\
		free_vector(a);											\
		a = NULL;												\
	}															\
} while(0)

#define print_vector(fmt, v, n) do {						\
	size_t print_vector_loop_counter;						\
	for(print_vector_loop_counter = 0;						\
			print_vector_loop_counter < (n);				\
			print_vector_loop_counter++)					\
		printf(fmt, (v)[print_vector_loop_counter]);		\
	putchar('\n');											\
} while(0)

/* TODO: to test this particular function :-) */
#define print_matrix(fmt, m, r, c) do {						\
	size_t row, column;										\
	for(row = 0; row < r; row++)							\
		print_vector(fmt, row, c);							\
}while(0)

#endif
