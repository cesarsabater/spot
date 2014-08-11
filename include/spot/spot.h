
   /*--------------------------------------------------------------------+
    |                              Spot                                  |
    |--------------------------------------------------------------------|
    |                             spot.h                                 |
    |--------------------------------------------------------------------|
    |                    First version: 28/05/2014                       |
    +--------------------------------------------------------------------+

 +--------------------------------------------------------------------------+
 |  / __)/ __)( ___)( ___)(  _ \                                            |
 | ( (__ \__ \ )__)  )__)  )(_) )      Chunky High-Level Compiler Seed      |
 |  \___)(___/(____)(____)(____/                                            |
 +--------------------------------------------------------------------------+
 | Copyright (C) 2014 University of Strasbourg                              |
 |                                                                          |
 | This library is free software; you can redistribute it and/or modify it  |
 | under the terms of the GNU Lesser General Public License as published by |
 | the Free Software Foundation; either version 2.1 of the License, or      |
 | (at your option) any later version.                                      |
 |                                                                          |
 | This library is distributed in the hope that it will be useful but       |
 | WITHOUT ANY WARRANTY; without even the implied warranty of               |
 | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser  |
 | General Public License for more details.                                 |
 |                                                                          |
 | You should have received a copy of the GNU Lesser General Public License |
 | along with this software; if not, write to the Free Software Foundation, |
 | Inc., 51 Franklin Street, Fifth Floor,                                   |
 | Boston, MA  02110-1301  USA                                              |
 |                                                                          |
 | Spot, the Chunky High-Level Compiler Seed                                |
 | Written by Cedric Bastoul, Cedric.Bastoul@unistra.fr                     |
 +--------------------------------------------------------------------------*/


#ifndef SPOT_H
# define SPOT_H

# include <stdlib.h>
# include <spot/macros.h>
# include <osl/osl.h>
# include <isl/set.h>
# include <isl/ctx.h>

osl_scop_p          spot_scop_read_from_c(FILE* input, char* input_name);
void                spot_scop_print_to_c(FILE* output, osl_scop_p scop);
osl_names_p         get_scop_names(osl_scop_p scop);
__isl_give isl_set* spot_get_isl_stmt_domain(__isl_keep isl_ctx* ctx,
                                             osl_scop_p scop,
                                             osl_statement_p stm);
osl_relation_p      spot_isl_to_osl_dom(isl_ctx* ctx, isl_set* set);
void                spot_add_statement(osl_scop_p scop, isl_ctx* ctx,
                                       osl_spot_p spot);
void                spot_compute_statements(osl_scop_p scop, osl_spot_p spot);
void                spot_compute_scops(osl_scop_p scop);

#endif /* define SPOT_H */
