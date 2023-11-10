#!/bin/sh
connectToHost="postman-echo.com" ; \
command="/post?qs1=wave&qs2=sound"; \
dataToPost='{par1=value1&par2=value2}'; \
dataLen=$(expr length "${dataToPost}" ) ; \
( printf "POST %s HTTP/1.1\n" "${command}"; \
  printf "Host: %s\n" "${connectToHost}"; \
  printf "Content-Length: %d\n" "$((dataLen+1))" ; \
  printf "Content-Type: application/json\r\n\r\n" ; \
  printf "%s\n" "${dataToPost}" ; \
sleep 2 ) | openssl s_client -quiet -no_ign_eof -connect ${connectToHost}:443 2>&1 | tee postResult.txt
