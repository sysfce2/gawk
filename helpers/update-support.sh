#! /bin/bash

# This script is only useful for the maintainer ...
#
# It updates all the support/* files from current GNULIB.
# We don't bother to print any messages about what we copied,
# as Git will tell us what, if anything, changed.

(cd /usr/local/src/Gnu/gnulib && git pull)

GL=/usr/local/src/Gnu/gnulib/lib

FILE_LIST="assert.in.h
cdefs.h
dfa.c
dfa.h
dynarray.h
flexmember.h
ialloc.c
ialloc.h
idx.h
intprops.h
libc-config.h
limits.in.h
localeinfo.c
localeinfo.h
minmax.h
regcomp.c
regex.c
regexec.c
regex.h
regex_internal.c
regex_internal.h
stdckdint.in.h
verify.h
xmalloc.c
malloc/dynarray_at_failure.c
malloc/dynarray_emplace_enlarge.c
malloc/dynarray_finalize.c
malloc/dynarray.h
malloc/dynarray_resize.c
malloc/dynarray_resize_clear.c
malloc/dynarray-skeleton.c"

for i in $FILE_LIST
do
	if [ -f $GL/$i ] && [ -f support/$i ]
	then
		cp $GL/$i support/$i
	fi
done

MISSING_FILE_LIST="mktime.c
mktime-internal.h
reallocarray.c"

for i in $MISSING_FILE_LIST
do
	if [ -f $GL/$i ] && [ -f missing_d/$i ]
	then
		cp $GL/$i missing_d/$i
	fi
done

# gnulib-common.m4 could be in this list.
# However, it is currently omitted to make Awk's copy smaller.
M4_FILE_LIST="absolute-header.m4
assert_h.m4
flexmember.m4
include_next.m4
limits-h.m4
xalloc.m4"

for i in $M4_FILE_LIST
do
	if [ -f $GL/../m4/$i ] && [ -f m4/$i ]
	then
		cp $GL/$i m4/$i
	fi
done

cd support
rm -f pma.c pma.h
wget http://web.eecs.umich.edu/~tpkelly/pma/latest/pma.h
wget http://web.eecs.umich.edu/~tpkelly/pma/latest/pma.c
