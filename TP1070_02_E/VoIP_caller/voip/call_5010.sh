#!/bin/sh

killall pjsua

amixer sset Playback 85%,85%
amixer sset Capture 15
amixer sset 'MIC GAIN' 20dB

pjsua \
--ec-tail=0 \
--no-vad \
--clock-rate=8000 \
--dis-codec=speex \
--id sip:5020 \
--registrar sip:192.168.5.170 \
--realm=\* \
--username=5020 \
--password=passwd_5020 \
--log-file=sip-smily-call.log \
--no-cli-console \
sip:5010@192.168.5.170 </dev/tty2 &

