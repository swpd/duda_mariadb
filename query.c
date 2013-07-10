/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*  Duda I/O
 *  --------
 *  Copyright (C) 2013, Zeying Xie <swpdtz at gmail dot com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include "common.h"
#include "query.h"

int mariadb_query_abort(mariadb_query_t *query)
{
    return MARIADB_OK;
}

void mariadb_query_free(mariadb_query_t *query)
{
    mk_list_del(query->_head);
    unsigned int i;
    for (i = 0; i < query->n_fields; ++i) {
        FREE(query->fields[i]);
    }
    FREE(query->fields);
    FREE(query->query_str);
    FREE(query->privdata);
    FREE(query);
}
