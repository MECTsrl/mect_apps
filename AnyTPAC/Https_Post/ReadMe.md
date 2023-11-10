# Project **Https_Get**
***
## Purpose of this Project: Show how to use **openssl executable** on target to perform a *simple https post*
***
The *openssl* executable is called in the callback function of the "pushButton" button with the title "HTTPS POST" on the page page100.
The *s_client* parameter is used to implement a generic SSL/TLS client and establish a transparent connection to a remote server with SSL/TLS, in addition to the *-quiet* and *-connect* parameters
For this example we used the server https://httpbin.org/ 
The openssl executable is called using Qt's QProcess Class
The Server host address is taken from the content of theHostLineEdit and concatenated with the destination port (in the example 443) to the -connect parameter
The parameters for the POST call are taken from the contents of thePathLineEdit and passed as stdin to the executable after its activation.
The results of the connection (in this case a JSon structure) are taken from the standard output of QProcess (process.readAll) and made available to the calling application in a QString for subsequent processing