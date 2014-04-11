/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2012 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id: header 321634 2012-01-01 13:15:04Z felipe $ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_grit.h"

/* If you declare any globals in php_grit.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(grit)
*/

/* True global resources - no need for thread safety here */
static int le_grit;

/* add by Lay li */
PHP_FUNCTION(grit_hello)
{
        char *name;
        int name_len;
        if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &name, &name_len) == FAILURE)
        {
                return;
        }
        php_printf("hello %s!", name);
        RETURN_TRUE;
}
ZEND_BEGIN_ARG_INFO(arginfo_grit_hello, 0)
ZEND_END_ARG_INFO()

/* {{{ grit_functions[]
 *
 * Every user visible function must have an entry in grit_functions[].
 */
const zend_function_entry grit_functions[] = {
	PHP_FE(grit_hello, arginfo_grit_hello)
	PHP_FE(confirm_grit_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE_END	/* Must be the last line in grit_functions[] */
};
/* }}} */

/* {{{ grit_module_entry
 */
zend_module_entry grit_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"grit",
	grit_functions,
	PHP_MINIT(grit),
	PHP_MSHUTDOWN(grit),
	PHP_RINIT(grit),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(grit),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(grit),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_GRIT
ZEND_GET_MODULE(grit)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("grit.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_grit_globals, grit_globals)
    STD_PHP_INI_ENTRY("grit.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_grit_globals, grit_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_grit_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_grit_init_globals(zend_grit_globals *grit_globals)
{
	grit_globals->global_value = 0;
	grit_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(grit)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(grit)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(grit)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(grit)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(grit)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "grit support", "enabled");
	php_info_print_table_row(2, "author", "Lay Li");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


/* Remove the following function when you have succesfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_grit_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_grit_compiled)
{
	char *arg = NULL;
	int arg_len, len;
	char *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	len = spprintf(&strg, 0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "grit", arg);
	RETURN_STRINGL(strg, len, 0);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
