/*
   +----------------------------------------------------------------------+
   | PHP Version 5                                                        |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Authors: Stanislav Malyshev <stas@zend.com>                          |
   +----------------------------------------------------------------------+
 */

#ifndef MSG_FORMAT_DATA_H
#define MSG_FORMAT_DATA_H

#include <php.h>

#include <unicode/umsg.h>

#include "intl_error.h"

typedef struct {
	// error hangling
	intl_error      error;

	// formatter handling
	UMessageFormat* umsgf;
	char*			orig_format;
	ulong			orig_format_len;
	HashTable*		arg_types;
	int				tz_set; /* if we've already the time zone in sub-formats */
} msgformat_data;

msgformat_data* msgformat_data_create( TSRMLS_D );
void msgformat_data_init( msgformat_data* mf_data TSRMLS_DC );
void msgformat_data_free( msgformat_data* mf_data TSRMLS_DC );
int msgformat_fix_quotes(UChar **spattern, uint32_t *spattern_len, UErrorCode *ec);

#endif // MSG_FORMAT_DATA_H
