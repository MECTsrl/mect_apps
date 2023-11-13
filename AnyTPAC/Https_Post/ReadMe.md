# Project **Https_Post**

***
## Purpose of this Project: Show how to use **openssl executable** on target to perform a *simple https post*
***

For this example, the https://httpbin.org/ server was used, widely used by REST API developers in debugging, which returns the feedback of the parameters received in http messages.

The *openssl* executable is called in __two ways__, either by **preparing the call parameters and the POST query dynamically by reading the values from the user interface**, or simply by **calling an external bash script *testPost.sh*** which must already be present in the program folder hmi executable (/local/root/)  

In both cases the call generates the **postResult.txt** file in the program folder hmi executable, which can be read by the calling program to manage the return parameters of the POST call  

In the **first case**, the *openssl* executable is called in the callback function of the "pushButtonQProcess" button with the title "openssl Call" on the page page100.  

The *s_client* parameter is used to implement a generic SSL/TLS client and establish a transparent connection to a remote server with SSL/TLS, in addition to the *-quiet* and *-connect* parameters

The openssl executable is called using Qt's **QProcess** Class as a *bash command*.  The Server *host address* is taken from the content of *theHostLineEdit* and concatenated with the *destination port* (in the example **443**) to the -connect parameter  

The path on the Server, (the Header of Post) and also two header parameters query string *qs1 and qs2*, are taken from the contents of *thePathLineEdit*  

The *body parameters for the POST call par1 and par2*  are taken from the contents of *theParamsLineEdit* 

The http requests message is prepared in a QString *stdInput* and passed as stdin to the shell command wit a QProcess.write() after its activation and a fixed delay to allow connection to http server. 

The write channel of the bash command is subsequently closed through a QProcess.closeWriteChannel() to close the openssl connection with the Server at the end of its execution.  

The result of the query (in this case the connection results and a JSon structure)  is redirected to the *postResult.txt* file through a tee pipe, and will be read when the called Process closes and copied to theResultLabel object.

In the **second case** the *testPost.sh* example script (included in the project and copied into the hmi program folder) is executed in the callback function of the "pushButtonShell" button with the title "script Call" on the page page100.  
The bash script is called via a QProcess.start() and at the end its output,  captured  via a tee to the postResult.txt file, is read and copied to *theResultLabel* object

In **both cases**, in order for the QProcess object used for the openssl call to correctly handle input and output, it is necessary to call the *QProcess.setProcessChannelMode(QProcess::ForwardedChannels)* method before QProcess activation.

Preparing a bash script can be faster in its execution because there are no delays for connection management, as necessary for calling openssl directly via QProcess  

