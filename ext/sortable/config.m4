dnl config.m4 for extension sortable

PHP_ARG_ENABLE(sortable, whether to enable sortable support,
Make sure that the comment is aligned:
[  --enable-sortable                Enable scalar-objects support])

if test "$PHP_SORTABLE" != "no"; then
  PHP_NEW_EXTENSION(sortable, sortable.c, $ext_shared)
fi