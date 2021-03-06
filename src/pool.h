#ifndef	_pool_h
# define _pool_h

# include <sys/types.h>

typedef	struct	pool_chain_s	{
	size_t			used;	/* Number of objects in segment	 */
	struct pool_chain_s *	next;	/* Next segment in chain	 */
	char			data[];	/* Table of data		 */
} pool_chain_t;

typedef	struct	pool_s	{
	struct pool_chain_s *	head;	/* Link to start of chain	 */
	struct pool_chain_s *	chain;	/* Link to next pool clump	 */
	size_t			size;	/* Size of each object		 */
	size_t			qty;	/* Number of objects per link	 */
	int			(*ctor)(void *); /* Called after alloc	 */
	void			(*dtor)(void *); /* Called before free	 */
} pool_t;

typedef	struct	pool_iter_s	{
	pool_t *	pool;		/* Pool we are traversing	 */
	pool_chain_t *	chain;		/* Where we are in the chain	 */
	size_t		pos;		/* Index of element to return	 */
} pool_iter_t;

pool_t *	pool_new( size_t, int(*)(void *), void (*)(void *) );
void		pool_free( pool_t * * );
void *		pool_alloc( pool_t * );

pool_iter_t *	pool_iter_new( pool_t * );
void		pool_iter_free( pool_iter_t * * );
void *		pool_iter_next( pool_iter_t * );
pool_iter_t *	pool_iter_dup( pool_iter_t * );
int		pool_foreach( pool_t *, int (*)(pool_iter_t *, void *,void *), void * );

#endif	/* _pool_h */
