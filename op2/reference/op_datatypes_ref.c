/*
  Open source copyright declaration based on BSD open source template:
  http://www.opensource.org/licenses/bsd-license.php

* Copyright (c) 2009, Mike Giles
* Copyright (c) 2011, Florian Rathgeber
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*     * The name of Mike Giles may not be used to endorse or promote products
*       derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY Mike Giles ''AS IS'' AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL Mike Giles BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <op2/common/op_datatypes.h>

void op_decl_set ( op_set * set, int size, char const * name )
{
  initialise_set ( set, size, name );
}

void op_decl_map ( op_map * mapping, op_set * from, op_set * to, int dim, int * map, char const * name )
{
  initialise_map ( mapping, from, to, dim, map, name );
}

void op_decl_gbl ( op_dat * data, int dim, int type_size, void * dat, char const * name )
{
  initialise_dat( data,
                  0,
                  NULL,
                  NULL,
                  dim,
                  type_size,
                  dat,
                  name );
}

void op_decl_vec ( op_dat * data, op_set * set, int dim, int type_size, void * dat, char const * name )
{
  initialise_dat( data,
                  1,
                  set,
                  NULL,
                  dim,
                  type_size,
                  dat,
                  name );
}

void op_decl_const ( void * dat, int dim, int type_size ) {}
