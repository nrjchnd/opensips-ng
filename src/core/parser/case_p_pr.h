/* 
 * Copyright (C) 2006 Juha Heinanen
 *
 * This file is part of opensips, a free SIP server.
 *
 * opensips is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * opensips is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef CASE_P_PR_H
#define CASE_P_PR_H


#define TITY_CASE                         \
        if (LOWER_DWORD(val) == _tity_) { \
	        hdr->type = HDR_PPI_T;     \
		p += 4;                       \
		goto dc_end;                  \
	}                                     \


#define IDEN_CASE                         \
        if (LOWER_DWORD(val) == _iden_) { \
	        p += 4;                   \
                val = READ(p);            \
                TITY_CASE;                 \
		goto other;               \
	}


#define RED__CASE                         \
        if (LOWER_DWORD(val) == _red__) { \
	        p += 4;                   \
                val = READ(p);            \
                IDEN_CASE;                 \
		goto other;               \
	}
	             

#define EFER_CASE                          \
        if (LOWER_DWORD(val) == _efer_) {  \
                p += 4;                    \
	        val = READ(p);             \
	        RED__CASE;                 \
                goto other;                \
        }


#define p_pr_CASE      \
     p += 4;           \
     val = READ(p);    \
     EFER_CASE;        \
     goto other;


#endif /* CASE_P_PR_H */
