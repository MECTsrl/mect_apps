#!/bin/sh

echo "Content-Type: text; charset=UTF-8"
echo ""

echo "${QUERY_STRING}"
echo "${QUERY_STRING}" > /tmp/do_write.query

exit 0
