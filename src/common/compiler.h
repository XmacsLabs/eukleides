/*
 *  Eukleides version 1.5.0
 *  Copyright (c) Christian Obrecht 2004-2010
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

void add_instr(void (*f)(), _param p);

int get_addr(void);

void store_mark(void);

int pop_mark(void);

void back_patch(void);

void set_type(_symbol *symbol, int type);

void lift_type(_symbol *symbol, int type);

#define PSH_(arg)	add_instr(push_param, (_param)(arg))
#define INC(ptr)	add_instr(increment, (_param)(void *)ptr)
#define GTO(addr)	add_instr(goto_addr, (_param)(addr))
#define GSB(addr)	add_instr(gosub_addr, (_param)(addr))
#define JPZ(addr)	add_instr(jump_if_zero, (_param)(addr))
#define RTN		add_instr(go_back, (_param)NULL)
#define STP		add_instr(stop, (_param)NULL)
#define XEQ_(fct)	add_instr((fct), (_param)NULL)
#define XEQ(fct,ptr)    add_instr((fct), (_param)(void *)ptr)
#define SET_(fct,lbl)   add_instr((fct), (_param)(lbl))
