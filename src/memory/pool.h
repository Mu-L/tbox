/*!The Treasure Box Library
 * 
 * TBox is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 * 
 * TBox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with TBox; 
 * If not, see <a href="http://www.gnu.org/licenses/"> http://www.gnu.org/licenses/</a>
 * 
 * Copyright (C) 2009 - 2015, ruki All rights reserved.
 *
 * @author      ruki
 * @file        pool.h
 * @ingroup     memory
 *
 */
#ifndef TB_MEMORY_POOL_H
#define TB_MEMORY_POOL_H

/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */
#include "prefix.h"

/* //////////////////////////////////////////////////////////////////////////////////////
 * extern
 */
__tb_extern_c_enter__

/* //////////////////////////////////////////////////////////////////////////////////////
 * macros
 */
#define tb_pool_malloc(handle, size)                  tb_pool_malloc_(handle, size __tb_debug_vals__)
#define tb_pool_malloc0(handle, size)                 tb_pool_malloc0_(handle, size __tb_debug_vals__)

#define tb_pool_nalloc(handle, item, size)            tb_pool_nalloc_(handle, item, size __tb_debug_vals__)
#define tb_pool_nalloc0(handle, item, size)           tb_pool_nalloc0_(handle, item, size __tb_debug_vals__)

#define tb_pool_strdup(handle, data)                  tb_pool_strdup_(handle, data __tb_debug_vals__)
#define tb_pool_strndup(handle, data, size)           tb_pool_strndup_(handle, data, size __tb_debug_vals__)

#define tb_pool_ralloc(handle, data, size)            tb_pool_ralloc_(handle, data, size __tb_debug_vals__)
#define tb_pool_free(handle, data)                    tb_pool_free_(handle, data __tb_debug_vals__)

#define TB_POOL_GROW_MICRO                            (8096)
#define TB_POOL_GROW_SMALL                            (65536)
#define TB_POOL_GROW_LARGE                            (256 * 1024)

/* //////////////////////////////////////////////////////////////////////////////////////
 * types
 */

/// the pool ref type
typedef struct{}*   tb_pool_ref_t;

/* //////////////////////////////////////////////////////////////////////////////////////
 * interfaces
 */

/*! init the pool
 * 
 * @param grow      the pool grow size, using the default grow
 * @param align     the pool bytes align, using the cpu-aligned if be zero
 *
 * @return          the pool 
 */
tb_pool_ref_t       tb_pool_init(tb_size_t grow, tb_size_t align);

/*! exit the pool
 *
 * @param pool      the pool 
 */
tb_void_t           tb_pool_exit(tb_pool_ref_t pool);

/*! clear the pool
 *
 * @param pool      the pool 
 */
tb_void_t           tb_pool_clear(tb_pool_ref_t pool);

/*! malloc the memory
 *
 * @param pool      the pool 
 * @param size      the size
 *
 * @return          the data address
 */
tb_pointer_t        tb_pool_malloc_(tb_pool_ref_t pool, tb_size_t size __tb_debug_decl__);

/*! malloc the memory and fill zero 
 *
 * @param pool      the pool 
 * @param size      the size
 *
 * @return          the data address
 */
tb_pointer_t        tb_pool_malloc0_(tb_pool_ref_t pool, tb_size_t size __tb_debug_decl__);

/*! malloc the memory with the item count
 *
 * @param pool      the pool 
 * @param item      the item count
 * @param size      the item size
 *
 * @return          the data address
 */
tb_pointer_t        tb_pool_nalloc_(tb_pool_ref_t pool, tb_size_t item, tb_size_t size __tb_debug_decl__);

/*! malloc the memory with the item count and fill zero
 *
 * @param pool      the pool 
 * @param item      the item count
 * @param size      the item size
 *
 * @return          the data address
 */
tb_pointer_t        tb_pool_nalloc0_(tb_pool_ref_t pool, tb_size_t item, tb_size_t size __tb_debug_decl__);

/*! realloc the memory
 *
 * @param pool      the pool 
 * @param data      the data address
 * @param size      the data size
 *
 * @return          the new data address
 */
tb_pointer_t        tb_pool_ralloc_(tb_pool_ref_t pool, tb_pointer_t data, tb_size_t size __tb_debug_decl__);

/*! duplicate the string memory
 *
 * @param pool      the pool 
 * @param data      the string data address
 *
 * @return          the new string address
 */
tb_char_t*          tb_pool_strdup_(tb_pool_ref_t pool, tb_char_t const* data __tb_debug_decl__);

/*! duplicate the string memory with the given size
 *
 * @param pool      the pool 
 * @param data      the string data address
 * @param size      the string size
 *
 * @return          the new string address
 */
tb_char_t*          tb_pool_strndup_(tb_pool_ref_t pool, tb_char_t const* data, tb_size_t size __tb_debug_decl__);

/*! free the memory
 *
 * @param pool      the pool 
 * @param data      the data address
 *
 * @return          tb_true or tb_false
 */
tb_bool_t           tb_pool_free_(tb_pool_ref_t pool, tb_pointer_t data __tb_debug_decl__);

#ifdef __tb_debug__
/*! dump the pool
 *
 * @param pool      the pool 
 * @param prefix    the trace prefix
 */
tb_void_t           tb_pool_dump(tb_pool_ref_t pool, tb_char_t const* prefix);
#endif

/* //////////////////////////////////////////////////////////////////////////////////////
 * extern
 */
__tb_extern_c_leave__

#endif