/*
   +----------------------------------------------------------------------+
   | PHP Version 7                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2015 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: Grégory Planchat <gregory@luni.fr>                           |
   +----------------------------------------------------------------------+
 */

/* $Id$ */

#ifndef PHP_SORTABLE_H
#define PHP_SORTABLE_H

#include "zend.h"

extern zend_module_entry sortable_module_entry;
#define phpext_sortable_ptr &sortable_module_entry

#ifdef PHP_WIN32
#	if defined(SORTABLE_EXPORTS) || (!defined(COMPILE_DL_SORTABLE))
#		define SORTABLE_API __declspec(dllexport)
#	elif defined(COMPILE_DL_SORTABLE)
#		define SORTABLE_API __declspec(dllimport)
#	else
#		define SORTABLE_API /* nothing special */
#	endif
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define SORTABLE_API __attribute__ ((visibility("default")))
#else
#	define SORTABLE_API /* nothing special */
#endif

#ifdef ZTS
# include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(sortable);
PHP_MSHUTDOWN_FUNCTION(sortable);
ZEND_MINFO_FUNCTION(scalar_objects);

#ifdef ZTS
# define SORTABLEG(v) TSRMG(sortable_globals_id, zend_sortable_globals *, v)
#else
# define SORTABLEG(v) (sortable_globals.v)
#endif

#endif	/* PHP_SORTABLE_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
