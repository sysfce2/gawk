#
# Makefile.am --- automake input file for gawk
#
# Copyright (C) 2000-2016, 2018, 2019, 2021, 2022, 2023
# the Free Software Foundation, Inc.
#
# This file is part of GAWK, the GNU implementation of the
# AWK Programming Language.
#
# GAWK is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# GAWK is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
#

## process this file with automake to produce Makefile.in

AM_CFLAGS  = @CFLAGS@
AM_LDFLAGS = @LDFLAGS@

AR = @AR@

# Stuff to include in the dist that doesn't need it's own
# Makefile.am files
EXTRA_DIST = \
        ChangeLog.0 \
	Makefile.am \
	Makefile.in \
	pma.h \
	pma.c \
	regcomp.c \
	regex_internal.c \
	regex_internal.h \
	regexec.c \
	malloc/dynarray-skeleton.c

# what to make and install
noinst_LIBRARIES = libsupport.a
libsupport_a_SOURCES = \
	attribute.h \
	cdefs.h \
	dfa.c \
	dfa.h \
	dynarray.h \
	flexmember.h \
	getopt.c \
	getopt.h \
	getopt1.c \
	getopt_int.h \
	ialloc.c \
	idx.h \
	intprops.h \
	intprops-internal.h \
	libc-config.h \
	localeinfo.c \
	localeinfo.h \
	random.c \
	random.h \
	regex.c \
	regex.h \
	verify.h \
	xalloc.h \
	xalloc-die.c \
	xmalloc.c \
	malloc/dynarray.h \
	malloc/dynarray_at_failure.c \
	malloc/dynarray_emplace_enlarge.c  \
	malloc/dynarray_finalize.c \
	malloc/dynarray_resize.c \
	malloc/dynarray_resize_clear.c

if USE_PERSISTENT_MALLOC
libsupport_a_SOURCES += pma.c pma.h
CFLAGS += -DNDEBUG
AM_CFLAGS += -DNDEBUG
endif

# For some make's, e.g. OpenBSD, that don't define this
RM = rm -f

# For debugging
DEBUG = -gdwarf-4 -g3

DEFS = -DGAWK -DHAVE_CONFIG_H -I"$(srcdir)/.."

distclean-local:
	rm -fr .deps

BUILT_SOURCES =
MOSTLYCLEANFILES =

# The following is taken from gnulib/modules/gen-header.

# In 'sed', replace the pattern space with a "DO NOT EDIT" comment.
SED_HEADER_NOEDIT = s,.*,/* DO NOT EDIT! GENERATED AUTOMATICALLY! */,

# '$(SED_HEADER_STDOUT) -e "..."' runs 'sed' but first outputs "DO NOT EDIT".
SED_HEADER_STDOUT = sed -e 1h -e '1$(SED_HEADER_NOEDIT)' -e 1G

# '$(SED_HEADER_TO_AT_t) FILE' copies FILE to $@-t, prepending a leading
# "DO_NOT_EDIT".  Although this could be done more simply via:
#	SED_HEADER_TO_AT_t = $(SED_HEADER_STDOUT) > $@-t
# the -n and 'w' avoid a fork+exec, at least when GNU Make is used.
SED_HEADER_TO_AT_t = $(SED_HEADER_STDOUT) -n -e 'w $@-t'


# The following is taken from gnulib/modules/absolute-header:
# Use this preprocessor expression to decide whether #include_next works.
# Do not rely on a 'configure'-time test for this, since the expression
# might appear in an installed header, which is used by some other compiler.
HAVE_INCLUDE_NEXT = (__GNUC__ || __clang__ || 60000000 <= __DECC_VER)


# The following is adapted from gnulib/modules/gen-header, under the assumption
# that @NMD@ is always empty.
#
# Use $(gl_V_at) instead of $(AM_V_GEN) or $(AM_V_at) on a line that
# is its recipe's first line if and only if @NMD@ lines are absent.
gl_V_at = $(AM_V_at)


# The following is adapted from gnulib/modules/assert-h with @NMD@ removed.
BUILT_SOURCES += $(ASSERT_H)

# We need the following in order to create <assert.h> when the system
# doesn't have one that works with the given compiler.
if GL_GENERATE_ASSERT_H
assert.h: assert.in.h verify.h $(top_builddir)/config.status
	$(AM_V_GEN)$(MKDIR_P) '%reldir%'
	$(gl_V_at){ $(SED_HEADER_STDOUT) \
	      -e 's|@''INCLUDE_NEXT''@|$(INCLUDE_NEXT)|g' \
	      -e 's|@''PRAGMA_SYSTEM_HEADER''@|@PRAGMA_SYSTEM_HEADER@|g' \
	      -e 's|@''PRAGMA_COLUMNS''@|@PRAGMA_COLUMNS@|g' \
	      -e 's|@''NEXT_ASSERT_H''@|$(NEXT_ASSERT_H)|g' \
	      < $(srcdir)/assert.in.h && \
	  sed -e '/@assert.h omit start@/,/@assert.h omit end@/d' \
	      -e 's|_gl_verify|_gl_static_assert|g' \
	      -e 's|_GL_VERIFY|_GL_STATIC_ASSERT|g' \
	      -e 's|_GL\(_STATIC_ASSERT_H\)|_${gl_include_guard_prefix}\1|g' \
	      < $(srcdir)/verify.h; \
	} > $@-t
	$(AM_V_at)mv $@-t $@
else
assert.h: $(top_builddir)/config.status
	rm -f $@
endif
MOSTLYCLEANFILES += assert.h assert.h-t


# The following is adapted from gnulib/modules/limits-h with @NMD@ removed.
BUILT_SOURCES += $(LIMITS_H)

# We need the following in order to create <limits.h> when the system
# doesn't have one that is compatible with GNU.
if GL_GENERATE_LIMITS_H
limits.h: limits.in.h $(top_builddir)/config.status
	$(AM_V_GEN)$(MKDIR_P) '%reldir%'
	$(gl_V_at)$(SED_HEADER_STDOUT) \
	      -e 's|@''GUARD_PREFIX''@|${gl_include_guard_prefix}|g' \
	      -e 's|@''INCLUDE_NEXT''@|$(INCLUDE_NEXT)|g' \
	      -e 's|@''PRAGMA_SYSTEM_HEADER''@|@PRAGMA_SYSTEM_HEADER@|g' \
	      -e 's|@''PRAGMA_COLUMNS''@|@PRAGMA_COLUMNS@|g' \
	      -e 's|@''NEXT_LIMITS_H''@|$(NEXT_LIMITS_H)|g' \
	      $(srcdir)/limits.in.h > $@-t
	$(AM_V_at)mv $@-t $@
else
limits.h: $(top_builddir)/config.status
	rm -f $@
endif
MOSTLYCLEANFILES += limits.h limits.h-t


# The following is adapted from gnulib/modules/stdckdint with @NMD@ removed.

BUILT_SOURCES += $(STDCKDINT_H)

# We need the following in order to create <stdckdint.h> when the system
# doesn't have one that works with the given compiler.
if GL_GENERATE_STDCKDINT_H
stdckdint.h: stdckdint.in.h $(top_builddir)/config.status
	$(AM_V_GEN)$(MKDIR_P) '%reldir%'
	$(gl_V_at)$(SED_HEADER_STDOUT) \
	  $(srcdir)/stdckdint.in.h > $@-t
	$(AM_V_at)mv $@-t $@
else
stdckdint.h: $(top_builddir)/config.status
	rm -f $@
endif
MOSTLYCLEANFILES += stdckdint.h stdckdint.h-t
